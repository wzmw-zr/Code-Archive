/*************************************************************************
	> File Name: 2.LeetCode1471.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年06月11日 星期五 22时56分29秒
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

vector<int> getStrongest(vector<int>& arr, int k) {
    sort(arr.begin(), arr.end());
    int n = arr.size();
    int mid = arr[(n - 1) / 2];
    sort(arr.begin(), arr.end(), [&](int x, int y){
        return (abs(x - mid) == abs(y - mid)) ? (x < y) : (abs(x - mid) < abs(y - mid));
    });
    vector<int> ans;
    for (int i = 0; i < k; i++) ans.push_back(arr[n - 1 - i]);
    return ans;
}

int main() {
    return 0;
}
