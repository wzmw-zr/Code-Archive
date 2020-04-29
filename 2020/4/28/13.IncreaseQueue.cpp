/*************************************************************************
	> File Name: 13.IncreaseQueue.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年04月28日 星期二 23时14分15秒
 ************************************************************************/

#include<iostream>
using namespace std;
#define MAX_N 1000

struct MQueue {
    int num[MAX_N + 5], q[MAX_N + 5], head, tail, len;
    
    void Push(int ind) {
        if (ind - q[head] == len) head++;
        while (tail - head && num[q[tail - 1]] > num[ind]) tail--;
        q[tail++] = ind;
    }
};

int main() {
    return 0;
}
