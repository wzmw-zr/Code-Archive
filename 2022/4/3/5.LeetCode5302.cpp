/*************************************************************************
	> File Name: 5.LeetCode5302.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年04月03日 星期日 11时02分44秒
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

class Encrypter {
public:
  unordered_map<char, string> mp1;
  unordered_map<string, int> mp2;

  Encrypter(vector<char>& keys, vector<string>& values, vector<string>& dictionary) {
    int n = keys.size();
    for (int i = 0; i < n; i++) mp1[keys[i]] = values[i];
    for (string &s : dictionary) mp2[encrypt(s)]++;
  }

  string encrypt(string word1) {
    string ans = "";
    for (char c : word1) ans += mp1[c];
    return ans;
  }

  int decrypt(string word2) {
    return mp2.count(word2) ? mp2[word2] : 0;
  }
};


int main() {
  return 0;
}
