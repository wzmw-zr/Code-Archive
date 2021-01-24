/*************************************************************************
	> File Name: 5.LeetCode5662.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年01月24日 星期日 10时54分22秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int minCharacters(string a, string b) {
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    vector<int> cnt_a(26, 0), cnt_b(26, 0);
    int cnt_1 = 0, cnt_2 = 0, cnt_3 = 0, cnt_4 = 0, cnt_5 = 0;
    int len_1 = a.size(), len_2 = b.size();
    for (int i = 0; a[i]; i++) {
        if (a[i] >= b[0]) cnt_1++;
        if (a[i] >= b[len_2 - 1]) cnt_4++;
        cnt_a[a[i] - 'a']++;
    }
    for (int i = 0; b[i]; i++) {
        if (b[i] >= a[0]) cnt_2++;
        if (b[i] >= a[len_1 - 1]) cnt_5++;
        cnt_b[b[i] - 'a']++;
    }
    int ans = min(min(cnt_1, cnt_2), min(len_1 - cnt_4, len_2 - cnt_5));
    int temp = 0;
    for (int i = 0; i < 26; i++) temp = max(temp, cnt_a[i] + cnt_b[i]);
    cnt_3 = a.size() + b.size() - temp;
    ans = min(ans, cnt_3);
    return ans;
}

int main() {
    return 0;
}
