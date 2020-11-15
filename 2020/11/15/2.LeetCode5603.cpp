/*************************************************************************
	> File Name: 2.LeetCode5603.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年11月15日 星期日 10时45分03秒
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

bool closeStrings(string word1, string word2) {
    int len_1 = word1.size(), len_2 = word2.size();
    if (len_1 - len_2) return false;
    unordered_map<char, int> mp_1, mp_2;
    for (char c : word1) mp_1[c]++;
    for (char c : word2) mp_2[c]++;
    if (mp_1.size() - mp_2.size()) return false;
    for (auto x : mp_1) {
        if (!mp_2.count(x.first)) return false;
    }
    vector<int> num_1, num_2;
    for (auto x : mp_1)  num_1.push_back(x.second);
    for (auto x : mp_2)  num_2.push_back(x.second);
    sort(num_1.begin(), num_1.end());
    sort(num_2.begin(), num_2.end());
    return num_1 == num_2;
}

int main() {
    string word1, word2;
    cin >> word1 >> word2;
    cout << (closeStrings(word1, word2) ? "Yes" : "False") << endl;
    return 0;
}
