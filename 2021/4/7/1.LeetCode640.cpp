/*************************************************************************
	> File Name: 1.LeetCode640.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年04月07日 星期三 22时27分31秒
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

void split(string &equation, string &left, string &right) {
    int i = 0;
    for (i = 0; equation[i] && equation[i] != '='; i++) left += equation[i];
    i++;
    for (; equation[i]; i++) right += equation[i];
}

void parse(string &str, int &x_cnt, int &num_sum) {
    int flag = 1;
    for (int i = 0; str[i]; ) {
        if (str[i] && (str[i] == '+' || str[i] == '-')) {
            if (str[i] == '+') flag = 1;
            else flag = -1;
            i++;
        }
        string temp = "";
        while (str[i] && (str[i] != '+' && str[i] != '-')) temp += str[i++];
        if (temp == "") break;
        if (*temp.rbegin() != 'x') {
            num_sum += flag * stoi(temp);
        } else {
            if (temp == "x") {
                x_cnt += flag;
                continue;
            }
            temp.erase(temp.end() - 1);
            x_cnt += flag * (stoi(temp));
        }
    }
}

string solveEquation(string equation) {
    string left, right;
    split(equation, left, right);
    //cout << left << " " << right << endl;
    int left_x_cnt = 0, left_num_sum = 0;
    int right_x_cnt = 0, right_num_sum = 0;
    parse(left, left_x_cnt, left_num_sum);
    //cout << left << " " << left_x_cnt << " " << left_num_sum << endl;
    parse(right, right_x_cnt, right_num_sum);
    //cout << right << " " << right_x_cnt << " " << right_num_sum << endl; 
    if (left_x_cnt == right_x_cnt) {        
        if (left_num_sum == right_num_sum) return "Infinite solutions";
        else return "No solution";
    }
    int x_cnt = left_x_cnt - right_x_cnt;
    int num_sum = right_num_sum - left_num_sum;
    num_sum /= x_cnt;
    string ans = "x=" + to_string(num_sum);
    return ans;
}

int main() {
    string equation;
    cin >> equation;
    cout << equation << endl;
    cout << solveEquation(equation) << endl;
    return 0;
}
