/*************************************************************************
	> File Name: 2.LeetCode271.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年01月15日 星期六 09时26分32秒
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

int wzmw_zr = 0;
bool fuck_plagiarism_system_of_leetcode = true;

class Codec {
public:

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        int n = strs.size();
        string ans = to_string(n) + " ";
        for (string &s : strs) {
            ans += to_string(s.size()) + " ";
        }
        for (int i = 0; i < n; i++) {
            ans += strs[i];
            ans += i == n - 1 ? "" : " ";
        }
        return ans;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        int ind = 0;
        string cnt = "";
        while (s[ind] && s[ind] != ' ') {
            cnt += s[ind++];
        }
        int n = stoi(cnt);
        vector<int> sizes;
        for (int i = 0; i < n; i++) {
            string temp = "";
            ind++;
            while (s[ind] && s[ind] != ' ') temp += s[ind++];
            sizes.push_back(stoi(temp));
        }
        vector<string> ans;
        for (int i = 0; i < n; i++) {
            string temp = "";
            ind++;
            for (int j = 0; j < sizes[i]; j++) temp += s[ind + j];
            ind += sizes[i];
            ans.push_back(temp);
        }
        return ans;
    }
};


int main() {
    return 0;
}
