/*************************************************************************
	> File Name: 1.LeetCode1690.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年07月09日 星期四 00时10分36秒
 ************************************************************************/

#include<iostream>
#include<cstdlib>
#include<cstring>
#include<string>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<unordered_map>
#include<algorithm>
using namespace std;

int respace(vector<string>& dictionary, string sentence) {
    int s_len = sentence.size();
    int ret = 0;

    unordered_map<string, int> mp;
    vector<int> dp(s_len + 5, 0);

    for (auto x : dictionary) mp[x] = 1;

    for (int i = 1; i <= s_len; i++) {
        int tmp = 0;
        for (int j = i; j > 0; j--) {
            #if 0
            cout << j - 1 << " " << i - 1 << endl;
            cout << sentence.substr(j - 1, i - j + 1) << endl;
            #endif
            if (!mp[sentence.substr(j - 1, i - j + 1)]) continue;
            #if 0
            cout << sentence.substr(j - 1, i - j + 1) << endl;
            #endif
            tmp = i - j + 1;
        }
        //tmp &&  cout << tmp << endl;
        dp[i] = tmp;
    }

    for (int i = s_len; i > 0; ) {
        if (dp[i]) {
            i -= dp[i];
            #if 0
            cout << i << " ";
            cout << sentence.substr(i - dp[i], dp[i]) << endl;
            cout << i << endl; 
            #endif
        }
        else ret++, i--; 
    }

    return ret;
}

int main() {
    string sentence;
    cin >> sentence;
    cout << sentence << endl;
    int n;
    cin >> n;
    vector<string> dictionary;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        cout << s << endl;
        dictionary.push_back(s);
    }
    cout << endl;
    cout << respace(dictionary, sentence) << endl;
    return 0;
}
