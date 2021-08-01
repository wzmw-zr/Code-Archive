/*************************************************************************
	> File Name: 3.LeetCode5187.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年08月01日 星期日 11时18分33秒
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

long long minimumPerimeter(long long neededApples) {
    long long l = 1, r = 1e6;
    while (l < r) {
        long long mid = (l + r) / 2;
        long long t = static_cast<long long>(2 * mid) * static_cast<long long>(mid + 1) * static_cast<long long>(2 * mid + 1);
        if (t < neededApples) l = mid + 1;
        else r = mid;
    }
    return 8 * l;
}

int main() {
    return 0;
}
