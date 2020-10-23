/*************************************************************************
	> File Name: 1.LeetCode255.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年10月23日 星期五 08时17分01秒
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

bool dfs(vector<int> &preorder, int left, int right) {
    if (left >= right) return true;
    int l = left, r = right, num = preorder[left], flag = 0;
    for (int i = left; i <= right; i++) {
        if (preorder[i] <= num) l = i;
        else {
            if (!flag) {
                flag = 1;
                r = i;
            }
        }
    }
    cout << l << " " << r << endl;
    if (l > r) return false;
    return dfs(preorder, left + 1, l) && dfs(preorder, l + 1, right);
}

bool verifyPreorder(vector<int>& preorder) {
    return dfs(preorder, 0, preorder.size() - 1);
}

int main() {
    int n;
    vector<int> preorder;
    while (cin >> n) preorder.push_back(n);
    cout << (verifyPreorder(preorder) ? "True" : "False") << endl;
    return 0;
}
