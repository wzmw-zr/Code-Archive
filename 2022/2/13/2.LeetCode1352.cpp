/*************************************************************************
	> File Name: 2.LeetCode1352.cpp
	> Author: 
	> Mail: 
	> Created Time: 2022年02月13日 星期日 00时06分58秒
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

// Misunderstanding condition, 0 can be add to class.
struct BIT {
    int n;
    vector<int> nums;

    BIT(int n) : n(n), nums(vector<int>(n, 1)) {}

    int lowbit(int x) {
        return x & -x;
    }

    void update(int ind, int num) {
        while (ind < n) {
            nums[ind] *= num;
            ind += lowbit(ind);
        }
    }

    int query(int ind) {
        int ans = 1;
        while (ind) {
            ans *= nums[ind];
            ind -= lowbit(ind);
        }
        return ans;
    }
};

class ProductOfNumbers {
public:
    BIT bit;
    int ind;

    ProductOfNumbers() : bit(BIT(40010)), ind(0) {
    }

    void add(int num) {
        ind++;
        bit.update(ind, num);
    }

    int getProduct(int k) {
        return bit.query(ind) / bit.query(ind - k);
    }
};

int main() {
    return 0;
}
