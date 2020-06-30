/*************************************************************************
	> File Name: 4.LeetCode546.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年06月30日 星期二 11时14分21秒
 ************************************************************************/

#include<iostream>
#include<cstdlib>
#include<cstring>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<unordered_map>
#include<algorithm>
#include<unistd.h>
using namespace std;

int removeBoxes(vector<int> &boxes) {
    int dp[105][105][105] = {0};
    for (int i = 0; i < boxes.size(); i++) {
        for (int k = 0; k < boxes.size(); k++) {
            dp[i][i][k] = (k + 1) * (k + 1);
        }
    }
    for (int l = 1; l < boxes.size(); l++) {
        for (int j = l; j < boxes.size(); j++) {
            int i = j - l;
            for (int k = 0; k <= i; k++) {
                int res = (1 + k) * (1 + k) + dp[i + 1][j][0];
                for (int m = i + 1; m <= j; m++) {
                    if (boxes[m] == boxes[j]) {
                        res = max(res, dp[i + 1][m - 1][0] + dp[m][j][k + 1]);
                    }
                }
                dp[i][j][k] = res;
            }
        }
    }
    return boxes.size() == 0 ? 0 : dp[0][boxes.size() - 1][0];
}

int main() {
    int n;
    cin >> n;
    vector<int> boxes;
    for (int i = 0; i < n; i++) {
        int m;
        cin >> m;
        boxes.push_back(m);
    }
    #if 0
    for (int i = 0; i < n; i++) cout << boxes[i] << " ";
    cout << endl;
    #endif
    cout << removeBoxes(boxes) << endl;
    return 0;
}


