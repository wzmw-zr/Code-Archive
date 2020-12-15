/*************************************************************************
	> File Name: 1.LeetCode738.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年12月15日 星期二 07时49分33秒
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

int monotoneIncreasingDigits(int N) {
    string str = to_string(N);
    int n = str.size();
    for (int i = 0; i < n; i++) str[i] -= '0';
    for (int i = 0; i < n - 1; i++) {
        if (str[i + 1] >= str[i]) continue;
        while (i && str[i] == str[i - 1]) i--;
        str[i] -= 1;
        for (int j = i + 1; j < n; j++) str[j] = 9;
        break;
    }
    for (int i = n - 1; i > 0; i--) {
        if (str[i] >= 0) continue;
        str[i] += 10;
        str[i - 1] -= 1;
    }
    while (str.size() && str[0] == 0) str.erase(str.begin());
    int ans = 0, ten_pow = 1;
    for (int i = str.size() - 1; i >= 0; i--) {
        ans += str[i] * ten_pow;
        ten_pow *= 10;
    }
    return ans;
}

int main() {
    int N;
    cin >> N;
    cout << monotoneIncreasingDigits(N) << endl;
    return 0;
}
