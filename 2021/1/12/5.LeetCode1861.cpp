/*************************************************************************
	> File Name: 5.LeetCode1861.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年01月12日 星期二 23时27分41秒
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
    vector<int> ones;
    vector<int> zeros;
    for (int i = 0; i <= 30; i++) {
        if (num & (1 << i)) ones.push_back(i);
        else zeros.push_back(i);
    }
    int len_1 = ones.size(), len_2 = zeros.size();
    int near_max = num, near_min = num;
    int first_one = ones[0], first_zero = zeros[0];
    int flag = 0;
    for (int &x : zeros) {
        if (x < first_one) continue;
        flag = 1;
        near_max &= ~(1 << first_one);
        near_max |= (1 << x);
        break;
    }
    if (flag == 0) near_max = -1;

    flag = 0;
    for (int i = 0; i < len_1; i++) {
        if (ones[i] < first_zero) continue;
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
