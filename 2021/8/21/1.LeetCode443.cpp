/*************************************************************************
	> File Name: 1.LeetCode443.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年08月21日 星期六 09时41分58秒
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

int compress(vector<char>& chars) {
    int n = chars.size();
    int ind = 0;
    vector<char> ans;
    while (ind < n) {
        char t = chars[ind];
        int cnt = 0;
        while (ind < n && chars[ind] == t) cnt++, ind++;
        ans.push_back(t);
        if (cnt > 1) 
            for (char c : to_string(cnt)) ans.push_back(c);
    }
    chars = ans;
    return chars.size();
}

int main() {
    return 0;
}
