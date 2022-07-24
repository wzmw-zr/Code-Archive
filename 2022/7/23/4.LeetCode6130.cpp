/*************************************************************************
	> File Name: 4.LeetCode6130.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年07月23日 星期六 22时41分56秒
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

class NumberContainers {
public:
  unordered_map<int, int> ind_to_num;
  unordered_map<int, set<int>> num_to_inds;

  NumberContainers() {}

  void change(int index, int number) {
    if (ind_to_num.count(index)) {
      num_to_inds[ind_to_num[index]].erase(index);
      if (num_to_inds[ind_to_num[index]].size() == 0) 
        num_to_inds.erase(ind_to_num[index]);
    }
    ind_to_num[index] = number;
    if (!num_to_inds.count(number)) 
      num_to_inds[number] = set<int>();
    num_to_inds[number].insert(index);
  }

  int find(int number) {
    if (!num_to_inds.count(number)) return -1;
    return *(num_to_inds[number].begin());
  }
};


int main() {
  return 0;
}
