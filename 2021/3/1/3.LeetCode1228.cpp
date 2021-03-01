/*************************************************************************
	> File Name: 3.LeetCode1228.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年03月01日 星期一 09时26分18秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
using namespace std;

int missingNumber(vector<int>& arr) {
    int n = arr.size();
    int dis = arr[1] - arr[0];
    for (int i = 2; i < n; i++) {
        int temp = arr[i] - arr[i - 1];
        if (dis == temp * 2) return arr[0] + temp;
        if (dis == temp) continue;
        if (dis * 2 == temp) return arr[i - 1] + dis;
    }
    return 0;
}

int main() {
    return 0;
}
