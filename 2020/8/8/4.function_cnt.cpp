/*************************************************************************
	> File Name: 4.function_cnt.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年08月08日 星期六 16时38分39秒
 ************************************************************************/

#include<iostream>
#include<functional>
using namespace std;

template<typename T, typename ...ARGS> class FunctionCnt;
template<typename T, typename ...ARGS> 
class FunctionCnt<T(ARGS...)> {
public:
    FunctionCnt() : cnt(0) {}
    FunctionCnt(function<T(ARGS...)> g) : cnt(0), func(g) {}
    FunctionCnt(FunctionCnt<const T(ARGS...)> &g) : cnt(0), func(g.func) {}

    T operator()(ARGS... args) {
        this->cnt++;
        return func(args...);
    }

    void operator=(function<T(ARGS...)> g) {
        this->cnt = 0;
        this->func = g;
    }

    void operator=(FunctionCnt<T(ARGS...)> g) {
        this->cnt = 0;
        this->func = g.func;
    }

    int get_cnt() {
        return this->cnt;
    }
private:
    function<T(ARGS...)> func;
    int cnt;
};

int add(int a, int b, int c, int d) {
    return a + b + c + d;
}

int main() {
    FunctionCnt<int(int, int, int, int)> func1(add);
    FunctionCnt<int(int, int, int, int)> func2;
    func2 = add;
    cout << func1(100, 1000, 10000, 100000) << endl;
    cout << func2(100, 1000, 10000, 100000) << endl;
    return 0;
}
