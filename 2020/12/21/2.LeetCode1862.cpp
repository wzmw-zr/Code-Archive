/*************************************************************************
	> File Name: 2.LeetCode1862.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年12月21日 星期一 08时14分35秒
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

class WordsFrequency {
public:
    unordered_map<string, int> mp;
    WordsFrequency(vector<string>& book) {
        for (string &s : book) mp[s]++;
    }

    int get(string word) {
        if (mp.count(word)) return mp[word];
        return 0;
    }
};

int main() {
    return 0;
}
