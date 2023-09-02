/*************************************************************************
	> File Name: 1.bishi.cpp
	> Author: 
	> Mail: 
	> Created Time: 2023年09月02日 星期六 16时23分03秒
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
#include <cstdint>
using namespace std;

int main() {
  double base_freq;
  cin >> base_freq;
  vector<double> freqs;
  vector<double> losses;
  string s;
  getline(cin, s);
  getline(cin, s);
  int ind = 0;
  while (s[ind]) {
    string freq;
    string loss;
    while (s[ind] && s[ind] != ':')
      freq += s[ind++];
    ind++;
    while (s[ind] && s[ind] != ',')
      loss += s[ind++];
    freqs.push_back(stoi(freq));
    losses.push_back(stoi(loss));
    if (s[ind])
      ind++;
  }
  double dist = INT32_MAX;
  for (double freq : freqs)
    dist = min(dist, abs(freq - base_freq));
  int n = freqs.size();
  double sum = 0;
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    if (abs(freqs[i] - base_freq) == dist) {
      sum += losses[i];
      cnt++;
    }
  }
  printf("%.1f\n", sum / cnt);
  return 0;
}
