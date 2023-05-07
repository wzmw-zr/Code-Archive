/*************************************************************************
	> File Name: 2.LeetCode6417.cpp
	> Author: 
	> Mail: 
	> Created Time: 2023年05月07日 星期日 10时35分18秒
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

class FrequencyTracker {
public:
  unordered_map<int, int> num_freq;
  unordered_map<int, int> freq_cnt;

  FrequencyTracker() {}

  void add(int number) {
    if (num_freq.count(number)) {
      if (!(--freq_cnt[num_freq[number]]))
        freq_cnt.erase(num_freq[number]);
      num_freq[number]++;
      freq_cnt[num_freq[number]]++;
    } else {
      num_freq[number]++;
      freq_cnt[num_freq[number]]++;
    }
  }

  void deleteOne(int number) {
    if (!num_freq.count(number))
      return;
    if (!(--freq_cnt[num_freq[number]]))
      freq_cnt.erase(num_freq[number]);
    if (!(--num_freq[number])) {
      num_freq.erase(number);
    } else {
      freq_cnt[num_freq[number]]++;
    }
  }

  bool hasFrequency(int frequency) {
    return freq_cnt.count(frequency);
  }
};

int main() {
  return 0;
}
