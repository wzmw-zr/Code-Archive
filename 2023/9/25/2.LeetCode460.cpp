/*************************************************************************
	> File Name: 2.LeetCode460.cpp
	> Author: 
	> Mail: 
	> Created Time: 2023年09月25日 星期一 10时42分46秒
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
#include <list>
using namespace std;

struct Node {
  int freq;
  list<int> values;

  Node() = default;
  Node(int freq) : freq(freq) {}
};

class LFUCache {
public:
  int capacity;
  unordered_map<int, int> key2value;
  unordered_map<int, int> key2freq;
  unordered_map<int, list<int>::iterator> key2iter;
  list<Node> freq_list;
  unordered_map<int, list<Node>::iterator> freq2iter;

  LFUCache(int capacity) : capacity(capacity) {}

  int get(int key) {
    if (!key2value.count(key))
      return -1;
    int freq = key2freq[key];
    auto freq_iter = freq2iter[freq];

    if (next(freq_iter) == freq_list.end() || next(freq_iter)->freq != freq + 1) {
      freq_list.insert(next(freq_iter), Node(freq + 1));
      freq2iter[freq + 1] = next(freq_iter);
    }
    (*freq_iter).values.erase(key2iter[key]);
    if ((*freq_iter).values.size() == 0) {
      freq_list.erase(freq_iter);
      freq2iter.erase(freq);
    }
    freq_iter = freq2iter[freq + 1];
    (*freq_iter).values.push_back(key);
    key2iter[key] = prev((*freq_iter).values.end());
    key2freq[key] = freq + 1;
    return key2value[key];
  }

  void put(int key, int value) {
    if (key2value.count(key)) {
      int freq = key2freq[key];
      auto freq_iter = freq2iter[freq];

      if (next(freq_iter) == freq_list.end() || next(freq_iter)->freq != freq + 1) {
        freq_list.insert(next(freq_iter), Node(freq + 1));
        freq2iter[freq + 1] = next(freq_iter);
      }
      (*freq_iter).values.erase(key2iter[key]);
      if ((*freq_iter).values.size() == 0) {
        freq_list.erase(freq_iter);
        freq2iter.erase(freq);
      }
      freq_iter = freq2iter[freq + 1];
      (*freq_iter).values.push_back(key);
      key2iter[key] = prev((*freq_iter).values.end());
      key2freq[key] = freq + 1;
      key2value[key] = value;
      return ;
    }
    if (key2value.size() == capacity) {
      auto freq_iter = freq_list.begin();
      int freq = (*freq_iter).freq;
      int del_key = (*freq_iter).values.front();
      key2value.erase(del_key);
      key2freq.erase(del_key);
      key2iter.erase(del_key);
      (*freq_iter).values.pop_front();
      if ((*freq_iter).values.size() == 0) {
        freq_list.erase(freq_iter);
        freq2iter.erase(freq);
      }
    }
    if (freq_list.size() == 0 || (*freq_list.begin()).freq != 1) {
      freq_list.insert(freq_list.begin(), Node(1));
      freq2iter[1] = freq_list.begin();
    }
    auto freq_iter = freq_list.begin();
    (*freq_iter).values.push_back(key);
    key2value[key] = value;
    key2freq[key] = 1;
    key2iter[key] = prev((*freq_iter).values.end());
  }
};

int main() {
  return 0;
}
