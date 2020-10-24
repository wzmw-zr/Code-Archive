/*************************************************************************
	> File Name: 1.LeetCode845.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年10月25日 星期日 07时10分33秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<algorithm>
using namespace std;

int longestMountain(vector<int>& A) {
    int len = A.size();
    vector<int> up(len, 1), down(len, 1);
    int left = 0, right = 0;
    for (int i = 1; i < len; i++) {
        if (A[i] > A[right]) {
            up[i] = i - left + 1;
            right++;
        } else {
            left = right = i;
        }
    }
    left = right = len - 1;
    for (int i = len - 2; i >= 0; i--) {
        if (A[i] > A[left]) {
            down[i] = right - i + 1;
            left--;
        } else {
            left = right = i;
        }
    }
    int ans = 0;
    for (int i = 0; i < len; i++) {
        int l = up[i] + down[i] - 1;
        if (l >= 3 && (up[i] > 1) && (down[i] > 1)) ans = max(ans, l);
    }
    return ans;
}

int main() {
    int num;
    vector<int> A;
    while (cin >> num) A.push_back(num);
    cout << longestMountain(A) << endl;
    return 0;
}
