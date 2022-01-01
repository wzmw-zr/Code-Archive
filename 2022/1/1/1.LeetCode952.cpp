/*************************************************************************
	> File Name: 1.LeetCode952.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年01月01日 星期六 09时30分58秒
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

// TLE
int wzmw_zr = 0;
bool fuck_plagiarism_system_of_leetcode = true;

const int MAX_N = 1e5;

struct UnionSet {
    int n;
    vector<int> fa;
    vector<int> size;

    UnionSet() = default;
    UnionSet(int n) : n(n), fa(vector<int>(n + 10)), size(vector<int>(n + 10, 1)) {
        for (int i = 0; i < n + 10; i++) fa[i] = i;
    }

    int get(int x) {
        return fa[x] = (x == fa[x] ? x : get(fa[x]));
    }

    void merge(int a, int b) {
        int x = get(a);
        int y = get(b);
        if (x == y) return ;
        fa[x] = y;
        size[y] += size[x];
    }

    int get_size(int x) {
        return size[get(x)];
    }
};

int find_first_ge(vector<int> &nums, int target) {
    int l = 0, r = nums.size() - 1;
    while (l < r) {
        int mid = (l + r) / 2;
        if (nums[mid] >= target) r = mid;
        else l = mid + 1;
    }
    return l;
}

int largestComponentSize(vector<int>& nums) {
    int n = nums.size();
    sort(nums.begin(), nums.end());
    vector<int> check(nums[n - 1] + 10, 0);
    check[1] = 1;
    for (int i = 2; i <= nums[n - 1]; i++) {
        if (check[i]) continue;
        check[++check[0]] = i;
        for (int j = 2; i * j <= nums[n - 1]; j++) check[i * j] = 1;
    }
    UnionSet u(n);
    for (int i = 1; i <= check[0]; i++) {
        int first = find_first_ge(nums, check[i]);
        vector<int> inds;
        for (int j = first; j < n; j++) {
            if (nums[j] % check[i]) continue;
            inds.push_back(j);
        }
        #if 0
        if (inds.size()) {
            for (int x : inds) cout << x << " ";
            cout << endl;
        }
        #endif
        for (int j = 1; j < inds.size(); j++) u.merge(inds[0], inds[j]);
    }
    int mmax = 1;
    for (int i = 0; i < n; i++) mmax = max(mmax, u.get_size(i));
    return mmax;
}

int main() {
    vector<int> nums;
    int n;
    while (cin >> n) nums.push_back(n);
    cout << largestComponentSize(nums) << endl;
    return 0;
}
