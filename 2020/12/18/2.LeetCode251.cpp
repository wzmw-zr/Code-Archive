/*************************************************************************
	> File Name: 2.LeetCode251.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年12月18日 星期五 08时22分37秒
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

class Vector2D {
public:
    int ind;
    vector<int> nums;
    Vector2D(vector<vector<int>>& v) : ind(0) {
        for (auto &x : v) {
            for (auto &y : x) nums.push_back(y);
        }
    }

    int next() {
        return nums[ind++];
    }

    bool hasNext() {
        if (ind < nums.size()) return true;
        return false;
    }
};

int main() {
    return 0;
}
