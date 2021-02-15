/*************************************************************************
	> File Name: 3.LeetCode1758.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年02月15日 星期一 13时24分05秒
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

int minOperations(string s) {
    int cnt_1 = 0, cnt_2 = 0;
    for (int i = 0; s[i]; i++) {
        if (!(i & 1)) {
            if (s[i] - '0') cnt_1++;
            else cnt_2++;
        } else {
            if (s[i] - '0') cnt_2++;
            else cnt_1++;
        }
    }
    return min(cnt_1, cnt_2);
}

int main() {
    return 0;
}
