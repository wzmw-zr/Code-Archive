/*************************************************************************
	> File Name: 3.LeetCode2051.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年05月14日 星期五 00时58分13秒
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

int binary_search(vector<int> &arr, int num) {
    int l = 0, r = (int) arr.size() - 1;
    while (l < r) {
        int mid = (l + r) / 2;
        if (arr[mid] == num) return mid;
        if (arr[mid] < num) l = mid + 1;
        else r = mid - 1;
    }
    return l;
}

vector<int> findSwapValues(vector<int>& array1, vector<int>& array2) {
    int len_1 = array1.size();
    int len_2 = array2.size();
    sort(array1.begin(), array1.end());
    sort(array2.begin(), array2.end());
    int dis = 0;
    vector<int> ans;
    for (int x : array1) dis += x;
    for (int x : array2) dis -= x;
    if (dis & 1) return ans;
    dis /= 2;
    for (int i = 0; i < len_1; i++) {
        int ind = binary_search(array2, array1[i] - dis);
        if (array2[ind] != (array1[i] - dis)) continue;
        ans.push_back(array1[i]);
        ans.push_back(array2[ind]);
        break;
    }
    return ans;
}

int main() {
    return 0;
}
