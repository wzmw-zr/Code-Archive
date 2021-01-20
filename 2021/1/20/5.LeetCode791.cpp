/*************************************************************************
	> File Name: 5.LeetCode791.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年01月20日 星期三 21时59分43秒
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
#include<functional>
using namespace std;

string customSortString(string S, string T) {
    vector<int> ch(26, 26);
    for (int i = 0; S[i]; i++) ch[S[i] - 'a'] = i;
    auto cmp = [&](char a, char b){
        return ch[a - 'a'] < ch[b - 'a'];
    };
    sort(T.begin(), T.end(), cmp);
    return T;
}

int main() {
    return 0;
}
