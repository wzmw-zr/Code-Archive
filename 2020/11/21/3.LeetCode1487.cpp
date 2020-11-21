/*************************************************************************
	> File Name: 3.LeetCode1487.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年11月21日 星期六 07时57分08秒
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

vector<string> getFolderNames(vector<string>& names) {
    unordered_map<string, int> mp;
    vector<string> ans;
    for (string &x : names) {
        if (mp.count(x)) {
            while (1) {
                string temp = x + "(" + to_string(mp[x]++) + ")";
                if (mp.count(temp)) continue;
                mp[temp] = 1;
                ans.push_back(temp);
                break;
            }
        } else {
            mp[x] = 1;
            ans.push_back(x);
        }
    }
    return ans;
}

int main() {
    return 0;
}
