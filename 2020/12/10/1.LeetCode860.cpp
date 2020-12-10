/*************************************************************************
	> File Name: 1.LeetCode860.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年12月10日 星期四 08时25分09秒
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

bool lemonadeChange(vector<int>& bills) {
    int five = 0, ten = 0, twenty = 0;
    for (int &x : bills) {
        switch (x) {
            case 5 : {
                five++;
            } break;
            case 10 : {
                if (!five) return false;
                five--, ten++;
            } break;
            case 20 : {
                if (!ten && five < 3) return false;
                if (!ten) {
                    five -= 3;
                    twenty++;
                } else {
                    if (!five) return false;
                    five--, ten--, twenty++;
                }
            } break;
        }
    }
    return true;
}

int main() {
    int n;
    vector<int> bills;
    while (cin >> n) bills.push_back(n);
    cout << (lemonadeChange(bills) ? "Yes" : "No") << endl;
    return 0;
}
