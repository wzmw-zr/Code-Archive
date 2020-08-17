/*************************************************************************
	> File Name: 2.sort.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年08月17日 星期一 14时32分54秒
 ************************************************************************/

#include<iostream>
#include<algorithm>
#include<ctime>
#include<functional>
using namespace std;

int cmp(int a, int b) {
    return a > b;
}

struct CMP {
public:
    bool operator()(int a, int b) {
        return a > b;
    }
};

namespace haizei {
    template<typename T>
    class less {
    public:
        bool operator()(T a, T b) {
            return a < b;
        }

        bool operator()(T &&a, T &&b) {
            return a < b;
        }
    };

    template<typename T>
    class greater {
    public:
        bool operator()(T a, T b) {
            return a > b;
        }

        bool operator()(T &&a, T &&b) {
            return a > b;
        }
    };
};

int main() {
    srand(time(0));
    int arr[10];
    for (int i = 0; i < 10; i++) arr[i] = rand() % 100;
    function<int(int, int)> func(cmp);
    sort(arr, arr + 10, CMP());
    sort(arr, arr + 10, haizei::less<int>());
    sort(arr, arr + 10, haizei::greater<int>());
    //sort(arr, arr + 10, func);
    //sort(arr, arr + 10, [](int a, int b) { return a > b; });
    for (int i = 0; i < 10; i++) cout << arr[i] << " ";
    cout << endl;
    return 0;
}
