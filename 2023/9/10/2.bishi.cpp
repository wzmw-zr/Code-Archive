#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
using namespace std;

void deleteMiddle(vector<double> &arr_a, vector<int> &arr_b) {
  multiset<double> left, right;
  int n = arr_a.size();
  vector<double> tmp = arr_a;
  sort(tmp.begin(), tmp.end());
  for (int i = 0; i < (n + 1) / 2; i++)
      left.insert(arr_a[i]);
  for (int i = (n + 1) / 2; i < n; i++)
      right.insert(arr_a[i]);
  if (n & 1) {
      cout << *left.rbegin();
  } else {
      cout << (*left.rbegin() + *right.begin()) / 2;
  }
  for (int x : arr_b) {
      double val = arr_a[x];
      if (left.count(val)) {
          left.erase(left.find(val));
          if (left.size() < right.size()) {
              left.insert(*right.begin());
              right.erase(right.begin());
          }
      } else {
          right.erase(right.find(val));
          if (left.size() - right.size() > 1) {
              right.insert(*left.rbegin());
              left.erase(prev(left.end()));
          }
      }
      n--;
      if (n & 1) {
          cout << " " << *left.rbegin();
      } else {
          cout << " " << (*left.rbegin() + *right.begin()) / 2;
      }
  }
  cout << endl;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<double> arr_a(n);
    for (int i = 0; i < n; i++)
      cin >> arr_a[i];
    vector<int> arr_b(n - 1);
    for (int i = 0; i < n - 1; i++) {
      cin >> arr_b[i];
      arr_b[i]--;
    }
    deleteMiddle(arr_a, arr_b);
  }
  return 0;
}
