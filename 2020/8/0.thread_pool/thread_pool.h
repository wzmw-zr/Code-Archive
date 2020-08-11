/*************************************************************************
	> File Name: thread_pool.h
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年08月08日 星期六 19时36分33秒
 ************************************************************************/

#ifndef _THREAD_POOL_H
#define _THREAD_POOL_H
#include<iostream>
#include<functional>

namespace haizei {
class Task {
public:
    template<typename Func_T, typename ...ARGS>
    Task(Func_T f, ARGS... args) {
        this->func = std::bind(f, std::forward<ARGS>(args)...);
    }

    void run() {
        this->func();
    }

private:
    std::function<void()> func;

};
};

#endif
