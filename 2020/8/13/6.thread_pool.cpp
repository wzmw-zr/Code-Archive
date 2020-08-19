/*************************************************************************
	> File Name: 6.thread_pool.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年08月13日 星期四 16时08分50秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
#include<thread>
#include<functional>
#include<mutex>
#include<queue>
#include<condition_variable>
#include<map>
#include<ctime>
using namespace std;

namespace haizei {
class Task {
public :
    template<typename T, typename ...ARGS>
    Task(T func, ARGS... args) {
        this->func = std::bind(func, forward<ARGS>(args)...);
    }

    void operator()() {
        this->func();
    }

private :
    function<void()> func;
}; 

void thread_func1(int a, int b) {
    cout << a << " + " << b << " = " << a + b << endl;
}

void thread_func2(int &n) {
    n += 1;
}

class ThreadPool {
public :
    ThreadPool(int n = 5) 
    : max_threads_num(n) {} 

    void start() {
        for (int i = 0; i < max_threads_num; i++) {
            threads.push_back(new thread(&ThreadPool::worker, this));
        }
    }

    void stop() {
        for (int i = 0; i < this->max_threads_num; i++) {
            this->addOneTask(&ThreadPool::stop_task, this);
        }

        for (int i = 0; i < max_threads_num; i++) {
            threads[i]->join();
            delete threads[i];
        }
        threads.clear();
    }

    void worker() {
        std::thread::id id = std::this_thread::get_id();
        is_running[id] = true;
        while (is_running[id]) {
            Task *t = this->getOneTask();
            (*t)();
            delete t;
        }
    }

    template<typename T, typename ...ARGS>
    void addOneTask(T func, ARGS... args) {
        // forward<ARGS>(args)...
        unique_lock<mutex> lock(m_mutex);
        this->task_queue.push(new Task(func, forward<ARGS>(args)...));
        m_cond.notify_one();
        return ;
    }

    ~ThreadPool() {
        cout << "destructor" << endl;
        while (!task_queue.empty()) {
            Task *t = task_queue.front();
            task_queue.pop();
            delete t;
        }
    }


private :
    void stop_task() {
        std::thread::id id = std::this_thread::get_id();
        is_running[id] = false;
    }

    Task *getOneTask() {
        unique_lock<mutex> lock(m_mutex);
        while (task_queue.empty()) m_cond.wait(lock); // waiting until task enter the queue
        Task *t = task_queue.front();
        task_queue.pop();
        return t;
    }

    int max_threads_num;
    std::vector<thread *> threads;
    std::queue<Task *> task_queue;
    std::map<std::thread::id, bool> is_running;

    std::mutex m_mutex;
    std::condition_variable m_cond;
};

}

int prime_cnt = 0;

int is_prime(int x) {
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) return 0;
    }
    return 1;
}

void Prime_cnt(int left, int right) {
    for (int i = left; i <= right; i++) {
        if (is_prime(i)) __sync_fetch_and_add(&prime_cnt, 1);
    }
    return ;
}


void task_func(int x) {
    cout << "task func : " << x << endl;
}


int main() {
    haizei::ThreadPool tp(5);
    tp.start();
    tp.addOneTask(Prime_cnt, 2, 200000);
    tp.addOneTask(Prime_cnt, 200001, 400000);
    tp.addOneTask(Prime_cnt, 400001, 600000);
    tp.addOneTask(Prime_cnt, 600001, 800000);
    tp.addOneTask(Prime_cnt, 800001, 1000000);
    tp.stop();
    cout << prime_cnt << endl;
    return 0;
}
