/*************************************************************************
	> File Name: 6.LeetCode373.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年11月17日 星期二 10时50分04秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<unordered_map>
#include<unordered_set>
#include<algorithm>
using namespace std;

vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
    vector<vector<int>> ans;
    vector<vector<int>> temp;
    int len_1 = nums1.size(), len_2 = nums2.size();
    for (int i = 0; i < min(len_1, k); i++) {
        for (int j = 0; j < min(len_2, k); j++) {
            temp.push_back({nums1[i], nums2[j]});
        }
    }
    sort(temp.begin(), temp.end(), [](vector<int> &a, vector<int> &b){ return (a[0] + a[1]) < (b[0] + b[1]); });
    for (int i = 0; i < k; i++) ans.push_back(temp[i]);
    return ans;
}

int main() {
    return 0;
}
