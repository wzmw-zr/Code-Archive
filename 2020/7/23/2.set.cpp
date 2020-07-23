/*************************************************************************
	> File Name: 1.set.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年07月23日 星期四 18时14分34秒
 ************************************************************************/

#include<iostream>
#include<cstdlib>
#include<string>
#include<vector>
#include<map>
#include<set>
#include<algorithm>
using namespace std;

int main() {
    set<int> s;
    s.insert(345);
    s.insert(65);
    s.insert(9973);
    s.insert(9000);
    cout << s.size() << endl;
    s.insert(65);
    cout << s.size() << endl;
    cout << *(s.begin()) << endl;
    //cout << s.count(65) << endl;
    for (auto iter = s.begin(); iter != s.end(); iter++) {
        cout << *iter << endl;
    }
    s.erase(s.begin());
    cout << *s.begin() << endl;
    return 0;
}
