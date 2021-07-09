/*************************************************************************
	> File Name: 4.LeetCode89.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年07月09日 星期五 09时11分14秒
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> grayCode(int n) {
    int rest = 1 << n;
    vector<int> check(rest, 0);
    vector<int> ans(1, 0);
    check[0] = 1;
    rest--;
    int pre_num = 0;
    while (rest) {
        for (int i = 0; i < 31; i++) {
            if (pre_num & (1 << i)) {
                int temp = pre_num - (1 << i);
                if (check[temp]) continue;
                pre_num = temp;
                ans.push_back(pre_num);
                check[pre_num] = 1;
                break;
            } else {
                int temp = pre_num | (1 << i);
                if (check[temp]) continue;
                pre_num = temp;
                ans.push_back(pre_num);
                check[pre_num] = 1;
                break;
            }
        }
        rest--;
    }
    return ans;
}

int main() {
    return 0;
}
