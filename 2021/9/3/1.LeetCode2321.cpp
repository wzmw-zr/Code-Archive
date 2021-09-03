/*************************************************************************
	> File Name: 1.LeetCode2321.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年09月03日 星期五 08时27分34秒
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
using namespace std;

vector<int> smallestK(vector<int>& arr, int k) {
    vector<int> ans;
    sort(arr.begin(), arr.end());
    for (int i = 0; i < k; i++) ans.push_back(arr[i]);
    return ans;
}

int main() {
    return 0;
}
