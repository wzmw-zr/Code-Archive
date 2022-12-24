/*************************************************************************
	> File Name: 4.LeetCode6274.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年12月24日 星期六 22时44分44秒
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

using PII = pair<int, int>;

vector<int> topStudents(vector<string>& positive_feedback, vector<string>& negative_feedback, vector<string>& report, vector<int>& student_id, int k) {
  unordered_set<string> pos(positive_feedback.begin(), positive_feedback.end());
  unordered_set<string> neg(negative_feedback.begin(), negative_feedback.end());
  int n = student_id.size();
  vector<int> vals(n, 0);
  vector<PII> nums;
  for (int i = 0; i < n; i++) {
    string &s = report[i];
    int ind = 0;
    while (s[ind]) {
      string word = "";
      while (s[ind] && s[ind] == ' ')
        ind++;
      if (!s[ind])
        break;
      while (s[ind] && s[ind] != ' ')
        word += s[ind++];
      if (pos.count(word))
        vals[i] += 3;
      if (neg.count(word))
        vals[i] -= 1;
    }
    nums.push_back(PII(vals[i], student_id[i]));
  }
  sort(nums.begin(), nums.end(), [](PII &a, PII &b){
    return a.first == b.first ? a.second > b.second : a.first < b.first;
  });
  vector<int> ans;
  for (int i = 0; i < k; i++)
    ans.push_back(nums[n - i - 1].second);
  return ans;
}

int main() {
  return 0;
}
