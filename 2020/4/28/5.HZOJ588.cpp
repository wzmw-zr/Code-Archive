/*************************************************************************
	> File Name: 5.HZOJ588.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年04月28日 星期二 15时18分10秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
#include<unistd.h>
using namespace std;

int n;
vector<int> num1, num2;

void Push(vector<int> &num, int cnt, int data) {
    int ind = num.size();
    vector<int> tmp;
    while (cnt) {
        tmp.push_back(cnt % 10);
        cnt /= 10;
    }
    for (int i = tmp.size() - 1; i >= 0; i--) num.push_back(tmp[i]);
    num.push_back(data);
}

int main() {
    cin >> n;
    num1.push_back(1);
    for (int i = 2; i <= n; i++) {
        int ind = 0, len = num1.size();
        while (ind < len) {
            int cnt = 0, j, data = num1[ind];
            for (j = ind; j < len && num1[j] == data; j++) cnt++;
            Push(num2, cnt, data);
            ind = j;
        }
        num1 = num2;
        num2.clear();
    }
    for (int i = 0; i < num1.size(); i++) cout << num1[i];
    cout << endl;
    return 0;
}
