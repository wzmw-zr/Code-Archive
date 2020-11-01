/*************************************************************************
	> File Name: 3.LeetCode804.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年11月01日 星期日 20时34分50秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<unordered_map>
#include<unordered_set>
#include<map>
#include<set>
#include<algorithm>
using namespace std;

string mos[] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};

int uniqueMorseRepresentations(vector<string>& words) {
    unordered_map<char, string> mp;
    unordered_set<string> st;
    for (int i = 0; i < 26; i++) mp['a' + i] = mos[i];
    for (int i = 0; i < words.size(); i++) {
        string temp = "";
        for (int j = 0; words[i][j]; j++) temp += mp[words[i][j]];
        st.insert(temp);
    }
    return st.size();
}

int main() {
    return 0;
}
