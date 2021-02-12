/*************************************************************************
	> File Name: 5.LeetCode1176.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年02月12日 星期五 09时15分57秒
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

int dietPlanPerformance(vector<int>& calories, int k, int lower, int upper) {
    int n = calories.size(), sum = 0, score = 0;
    for (int i = 0; i < k - 1; i++) sum += calories[i];
    for (int i = k - 1; i < n; i++) {
        sum += calories[i];
        if (sum < lower) score--;
        else if (sum > upper) score++;
        sum -= calories[i - k + 1];
    }
    return score;
}

int main() {
    return 0;
}
