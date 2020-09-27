/*************************************************************************
	> File Name: case.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年09月27日 星期日 12时28分31秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<set>
using namespace std;

set<int> mp;

int main() {
    for (auto it = mp.begin(); it != mp.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
    for (int i = 0; i < 10; i++) mp.insert(i);
    for (auto it = mp.begin(); it != mp.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
    return 0;
}
