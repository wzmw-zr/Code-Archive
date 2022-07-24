/*************************************************************************
	> File Name: 5.LeetCode6126.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年07月24日 星期日 10时40分35秒
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

struct Node {
  int rate;
  string name;

  Node() = default;
  Node(int rate, string name) : rate(rate), name(name) {}

  bool operator<(const struct Node &that) const {
    return this->rate == that.rate ? this->name > that.name : this->rate < that.rate;
  }

  bool operator==(const struct Node &that) const {
    return this->rate == that.rate && this->name == that.name;
  }
};

class FoodRatings {
public:
  unordered_map<string, string> food_to_cuisine;
  unordered_map<string, int> food_to_rating;
  unordered_map<string, set<Node>> cuisine_to_foods;

  FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
    int n = foods.size();
    for (int i = 0; i < n; i++) {
      food_to_cuisine[foods[i]] = cuisines[i];
      food_to_rating[foods[i]] = ratings[i];
      if (!cuisine_to_foods.count(cuisines[i])) 
        cuisine_to_foods[cuisines[i]] = set<Node>();
      cuisine_to_foods[cuisines[i]].insert(Node(ratings[i], foods[i]));
    }
  }

  void changeRating(string food, int newRating) {
    string cuisine = food_to_cuisine[food];
    int old_rating = food_to_rating[food];
    cuisine_to_foods[cuisine].erase(Node(old_rating, food));
    food_to_rating[food] = newRating;
    cuisine_to_foods[cuisine].insert(Node(newRating, food));
  }

  string highestRated(string cuisine) {
    return cuisine_to_foods[cuisine].rbegin()->name;
  }
};


int main() {
  return 0;
}
