/*************************************************************************
	> File Name: 3.LeetCode5737.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年04月18日 星期日 14时08分04秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
using namespace std;

int getXORSum(vector<int>& arr1, vector<int>& arr2) {
    int a1 = 0, a2 = 0;
    for (int &x : arr1) a1 ^= x;
    for (int &x : arr2) a2 ^= x;
    return a1 & a2;
}

int main() {
    return 0;
}
