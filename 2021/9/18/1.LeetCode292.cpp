/*************************************************************************
	> File Name: 1.LeetCode292.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年09月18日 星期六 09时00分01秒
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
using namespace std;

bool A_win(int n);
bool B_win(int n);

bool A_win(int n) {
    if (n <= 3) return true;
    return !(B_win(n - 1) & B_win(n - 2) & B_win(n - 3));
}

bool B_win(int n) {
    if (n <= 3) return true;
    return !(A_win(n - 1) & A_win(n - 2) & A_win(n - 3));
}

bool canWinNim(int n) {
    return A_win(n);
}

int main() {
    return 0;
}
