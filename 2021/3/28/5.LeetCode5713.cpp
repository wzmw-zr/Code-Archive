/*************************************************************************
	> File Name: 5.LeetCode5713.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年03月28日 星期日 10时30分51秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<unordered_set>
using namespace std;

int numDifferentIntegers(string word) {
    int ind = 0;
    unordered_set<string> st;
    while (word[ind]) {
        while (word[ind] && word[ind] >= 'a' && word[ind] <= 'z') ind++;
        string s = "";
        while (word[ind] && word[ind] >= '0' && word[ind] <= '9') s += word[ind++];
        if (s.size() == 0) break;
        int l = 0;
        while (s[l + 1] && s[l] == '0') l++;
        s = s.substr(l);
        st.insert(s);
    }
    return st.size();
}

int main() {
    return 0;
}
