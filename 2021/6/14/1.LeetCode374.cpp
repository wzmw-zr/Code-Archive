/*************************************************************************
	> File Name: 1.LeetCode374.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年06月14日 星期一 00时04分00秒
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int guess(int n) {
    return n;
}

int guessNumber(int n) {
    int l = 1, r = n;
    while (l < r) {
        int mid = l / 2 + r / 2;
        if ((l & 1) && (r & 1)) mid += 1;
        int t = guess(mid);
        if (t == 0) return mid;
        else if (t == -1) r = mid - 1;
        else l = mid + 1;
    }
    return l;
}

int main() {
    return 0;
}
