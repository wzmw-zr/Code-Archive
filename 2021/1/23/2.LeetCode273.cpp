/*************************************************************************
	> File Name: 2.LeetCode273.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年01月23日 星期六 09时50分33秒
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
#include<cmath>
using namespace std;

unordered_map<int, string> mp;

void init() {
    mp[0] = "Zero";
    mp[1] = "One";
    mp[2] = "Two";
    mp[3] = "Three";
    mp[4] = "Four";
    mp[5] = "Five";
    mp[6] = "Six";
    mp[7] = "Seven";
    mp[8] = "Eight";
    mp[9] = "Nine";
    mp[10] = "Ten";
    mp[11] = "Eleven";
    mp[12] = "Twelve";
    mp[13] = "Thirteen";
    mp[14] = "Fourteen";
    mp[15] = "Fifteen";
    mp[16] = "Sixteen";
    mp[17] = "Seventeen";
    mp[18] = "Eighteen";
    mp[19] = "Nineteen";
    mp[20] = "Twenty";
    mp[30] = "Thirty";
    mp[40] = "Forty";
    mp[50] = "Fifty";
    mp[60] = "Sixty";
    mp[70] = "Seventy";
    mp[80] = "Eighty";
    mp[90] = "Ninety";
    mp[100] = "Hundred";
    mp[1000] = "Thousand";
    mp[1000000] = "Million";
    mp[1000000000] = "Billion";
}

int get_len(int num) {
    int cnt = 0;
    do {
        num /= 10;
        cnt++;
    } while (num);
    return cnt;
}

string numberToString(int num) {
    int n = get_len(num);
    if (n == 1) return mp[num];
    if (n == 2) {
        if (num < 20) return mp[num];
        if (num % 10 == 0) return mp[num];
        return mp[num / 10 * 10] + " " + mp[num % 10];
    }
    if (n == 3) {
        string pre_part = numberToString(num / 100);
        string post_part = numberToString(num % 100);
        if (post_part != "Zero") return pre_part + " " + mp[100] + " " + post_part;
        return pre_part + " " + mp[100];
    }
    if (4 <= n && n <= 6) {
        string pre_part = numberToString(num / 1000);
        string post_part = numberToString(num % 1000);
        if (post_part != "Zero") return pre_part + " " + mp[1000] + " " + post_part;
        return pre_part + " " + mp[1000];
    }
    if (7 <= n && n <= 9) {
        string pre_part = numberToString(num / 1000000);
        string post_part = numberToString(num % 1000000);
        if (post_part != "Zero") return pre_part + " " + mp[1000000] + " " + post_part;
        return pre_part + " " + mp[1000000];
    }
    string pre_part = numberToString(num / 1000000000);
    string post_part = numberToString(num % 1000000000);
    if (post_part != "Zero") return pre_part + " " + mp[1000000000] + " " + post_part;
    return pre_part + " " + mp[1000000000];
}

string numberToWords(int num) {
    init();
    return numberToString(num);
}

int main() {
    int num;
    cin >> num;
    cout << numberToWords(num) << endl;
    return 0;
}
