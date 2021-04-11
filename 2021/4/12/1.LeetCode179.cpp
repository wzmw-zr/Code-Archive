/*************************************************************************
	> File Name: 1.LeetCode179.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年04月12日 星期一 00时03分03秒
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

// WA

static bool cmp(string a, string b) {
    if (a == b) return true;
    int len_a = a.size();
    int len_b = b.size();
    int min_len = min(len_a, len_b);
    string a_p = a.substr(0, min_len);
    string b_p = b.substr(0, min_len);
    if (a_p == b_p) {
        if (len_a < len_b) {
            string b_r = b.substr(min_len);
            return cmp(a, b_r);   
        } else {
            string a_r = a.substr(min_len);
            return cmp(a_r, b);
        }
    }
    return a_p < b_p;
}

string largestNumber(vector<int>& nums) {
    vector<string> strs;
    for (int x : nums) strs.push_back(to_string(x));
    sort(strs.begin(), strs.end(), cmp);
    string ans = "";
    int n = strs.size();
    for (int i = n - 1; i >= 0; i--) ans += strs[i];
    int ind = 0, len = ans.size();
    while (ind < len - 1 && ans[ind] == '0') ind++;
    ans = ans.substr(ind);
    return ans;
}

int main() {
    return 0;
}
