/*************************************************************************
	> File Name: 2.LeetCode1861.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年01月13日 星期三 00时09分50秒
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

vector<int> findClosedNumbers(int num) {
    vector<int> ones, zeros;
    for (int i = 0; i <= 30; i++) {
        if (num & (1 << i)) ones.push_back(i);
        else zeros.push_back(i);
    }
    if (zeros.size() == 0) return vector<int>({-1, -1});

    int len_1 = ones.size(), len_2 = zeros.size();
    int near_max = num, near_min = num;
    int flag = 0;

    for (int i = 0; i < len_2; i++) {
        if (zeros[i] < ones[0]) continue;
        flag = 1;
        for (int j = 0; j <= zeros[i]; j++) near_max |= (1 << j);
        for (int j = 1; j <= (i + 1); j++) near_max &= ~(1 << (zeros[i] - j));
        break;
    }
    if (flag == 0)  near_max = -1;

    flag = 0;
    for (int i = 0; i < len_1; i++) {
        if (ones[i] < zeros[0]) continue;
        flag = 1;
        for (int j = 0; j <= ones[i]; j++) near_min &= ~(1 << j);
        for (int j = 1; j <= (i + 1); j++) near_min |= (1 << (ones[i] - j));
        break;
    }
    if (flag == 0) near_min = -1;

    return vector<int>({near_max, near_min});
}

int main() {
    int num;
    cin >> num;
    auto ans = findClosedNumbers(num);
    cout << ans[0] << " " << ans[1] << endl;
    return 0;
}
