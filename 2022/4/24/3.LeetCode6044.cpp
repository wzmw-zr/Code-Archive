/*************************************************************************
	> File Name: 3.LeetCode6044.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年04月24日 星期日 14时41分57秒
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

vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& persons) {
  int m = flowers.size(), n = persons.size();
  sort(flowers.begin(), flowers.end());
  vector<PII> people;
  for (int i = 0; i < n; i++) people.push_back(PII(persons[i], i));
  sort(people.begin(), people.end());
  auto cmp = [](PII &a, PII &b) -> bool {
    return a.second == b.second ? a.first > b.first : a.second > b.second;
  };
  priority_queue<PII, vector<PII>, decltype(cmp)> que(cmp);
  vector<int> ans(n);
  int ind = 0;
  for (auto &&[t, id] : people) {
    while (ind < m && flowers[ind][0] <= t) {
      que.push(PII(flowers[ind][0], flowers[ind][1]));
      ind++;
    }
    while (!que.empty() && que.top().second < t) que.pop();
    ans[id] = que.size();
  }
  return ans;
}

int main() {
  return 0;
}
