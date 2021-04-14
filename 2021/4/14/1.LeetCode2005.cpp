/*************************************************************************
	> File Name: 1.LeetCode2005.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年04月14日 星期三 22时09分42秒
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

int b_s_left_near_max(vector<int> &b, int num) {
    int l = 0, r = b.size() - 1;
    while (l < r) {
        int mid = (l + r + 1) / 2;
        if (b[mid] <= num) l = mid;
        else r = mid - 1;
    }
    return l;
}

int b_s_right_near_min(vector<int> &b, int num) {
    int l = 0, r = b.size() - 1;
    while (l < r) {
        int mid = (l + r) / 2;
        if (b[mid] >= num) r = mid;
        else l = mid + 1;
    }
    return l;
}


int smallestDifference(vector<int>& a, vector<int>& b) {
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int len_a = a.size(), len_b = b.size();
    long ans = INT64_MAX;
    for (int i = 0; i < len_a; i++) {
        int left_near_max = b_s_left_near_max(b, a[i]);
        int right_near_min = b_s_right_near_min(b, a[i]);
        long left_max = b[left_near_max];
        long right_min = b[right_near_min];
        long num = a[i];
        ans = min(ans, min(abs(num - left_max), abs(num - right_min)));
    }
    for (int i = 0; i < len_b; i++) {
        int left_near_max = b_s_left_near_max(a, b[i]);
        int right_near_min = b_s_right_near_min(a, b[i]);
        long left_max = a[left_near_max];
        long right_min = a[right_near_min];
        long num = b[i];
        ans = min(ans, min(abs(num - left_max), abs(num - right_min)));
    }
    return ans;
}

int main() {
    return 0;
}
