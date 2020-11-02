/*************************************************************************
	> File Name: 2.LeetCode408.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年11月02日 星期一 08时23分06秒
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

int get_num(string &abbr, int &ind) {
    int num = 0;
    while (abbr[ind] && abbr[ind] >= '0' && abbr[ind] <= '9') {
        num = num * 10 + abbr[ind++] - '0';
    } 
    return num;
}

bool validWordAbbreviation(string word, string abbr) {
    int ind_1 = 0, ind_2 = 0;
    for ( ; ind_1 < word.size() && ind_2 < abbr.size(); ) {
        if (abbr[ind_2] >= '0' && abbr[ind_2] <= '9') {
            if (abbr[ind_2] == '0') {
                if ((ind_2 + 1 < abbr.size()) && abbr[ind_2 + 1] >= '0' && abbr[ind_2 + 1] <= '9')
                    return false;
            }
            int num = get_num(abbr, ind_2);
            ind_1 += num;
        } else {
            if (word[ind_1] == abbr[ind_2]) ind_1++, ind_2++;
            else return false;
        }
    } 
    if (ind_1 == word.size() && ind_2 == abbr.size()) return true;
    return false;
}

int main() {
    string word, abbr;
    cin >> word >> abbr;
    cout << (validWordAbbreviation(word, abbr) ? "True" : "False") << endl;
    return 0;
}
