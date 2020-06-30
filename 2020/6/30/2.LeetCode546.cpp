/*************************************************************************
	> File Name: 2.LeetCode546.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年06月30日 星期二 09时05分52秒
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

int get_seq_len(int ind, vector<int> &boxes) {
    int len = 1;
    for (int i = ind + 1; i < boxes.size(); i++) {
        if (boxes[i] == boxes[ind]) len++;
        else break;
    }
    return len;
}

int removeBoxes(vector<int> &boxes) {
    if (boxes.size() == 0) return 0;
    int ans = 0;
    for (int i = 0; i < boxes.size(); ) {
        int seq_len = get_seq_len(i, boxes);

        vector<int> tmp = boxes;
        int res = seq_len * seq_len;

        tmp.erase(tmp.begin() + i, tmp.begin() + i + seq_len);

        res += removeBoxes(tmp);
        ans = max(ans, res);
        i += seq_len;
    }
    return ans;
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
