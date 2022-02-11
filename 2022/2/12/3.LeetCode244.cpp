/*************************************************************************
	> File Name: 3.LeetCode244.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年02月12日 星期六 00时33分05秒
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

class WordDistance {
public:
    unordered_map<string, vector<int>> mp;

    WordDistance(vector<string>& wordsDict) {
        int n = wordsDict.size();
        for (int i = 0; i < n; i++) {
            if (!mp.count(wordsDict[i])) {
                mp[wordsDict[i]] = vector<int>(0);
            }
            mp[wordsDict[i]].push_back(i);
        }
    }

    int find_max_le(vector<int> &inds, int ind) {
        int l = 0, r = static_cast<int>(inds.size()) - 1;
        while (l < r) {
            int mid = (l + r + 1) / 2;
            if (inds[mid] <= ind) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        return inds[l];
    }

    int find_min_ge(vector<int> &inds, int ind) {
        int l = 0, r = static_cast<int>(inds.size()) - 1;
        while (l < r) {
            int mid = (l + r) / 2;
            if (inds[mid] >= ind) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return inds[l];
    }


    int shortest(string word1, string word2) {
        vector<int> inds_1 = mp[word1];
        vector<int> inds_2 = mp[word2];
        int ans = INT32_MAX;
        for (int ind : inds_1) {
            int left = find_max_le(inds_2, ind);
            int right = find_min_ge(inds_2, ind);
            ans = min({ans, abs(ind - left), abs(ind - right)});
        }
        for (int ind : inds_2) {
            int left = find_max_le(inds_1, ind);
            int right = find_min_ge(inds_1, ind);
            ans = min({ans, abs(ind - left), abs(ind - right)});
        }
        return ans;
    }
};

int main() {
    return 0;
}
