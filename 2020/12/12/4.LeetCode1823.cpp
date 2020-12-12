/*************************************************************************
	> File Name: 4.LeetCode1823.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年12月12日 星期六 10时22分13秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
using namespace std;

int convertInteger(int A, int B) {
    int ans = 0;
    for (int i = 0; i < 32; i++) {
        int t_1 = A & 1, t_2 = B & 1;
        if (t_1 != t_2) ans++;
        A >>= 1, B >>= 1;
    }
    return ans;
}

int main() {
    int A, B;
    cin >> A >> B;
    cout << convertInteger(A, B) << endl;
    return 0;
}
