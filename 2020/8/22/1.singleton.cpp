/*************************************************************************
	> File Name: 1.singleton.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年08月22日 星期六 16时09分14秒
 ************************************************************************/


#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
#include<mutex>
using namespace std;

class Singleton {
private : 
    static Singleton *instance;
    static std::mutex m_mutex;
    Singleton() = default;
    Singleton(const Singleton &) = default;
    ~Singleton() = default;
public :
    static Singleton *GetInstance() {
        if (instance == nullptr) {
            std::unique_lock<mutex> lock(m_mutex);
            if (instance == nullptr) {
                instance = new Singleton();
            }
        }
        return instance;
    }
};

// initialize the class member or function can be placed outside, whatever it is private or public
Singleton *Singleton::instance = nullptr;
std::mutex Singleton::m_mutex;

#if 0
In Singleton, we can not delete the single object outside, so the destructor must be placed in private
#endif

int main() {
    Singleton *p = Singleton::GetInstance();
    return 0;
}
