/*************************************************************************
	> File Name: 3.LeetCode5681.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年03月06日 星期六 22时36分37秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
using namespace std;

bool minus_max_pow_of_three(int &n, vector<int> &powsOfThree, vector<int> &check) {
    for (int i = 19; i >= 0; i--) {
        if (n < powsOfThree[i]) continue;
        if (check[i]) return false;
        check[i]++;
        n -= powsOfThree[i];
        break;
    }
    return true;
}

bool checkPowersOfThree(int n) {
    vector<int> powsOfThree(20, 1);
    vector<int> check(20, 0);
    powsOfThree[0] = 1;
    for (int i = 1; i < 20; i++) powsOfThree[i] = 3 * powsOfThree[i - 1];
    while (n) {
      if (!minus_max_pow_of_three(n, powsOfThree, check)) 
        return false;
    };
    for (int i = 0; i < 20; i++) {
        if (check[i] > 1) return false;
    }
    return true;
}

int main() {
    return 0;
}
