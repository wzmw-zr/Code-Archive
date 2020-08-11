/*************************************************************************
	> File Name: 1.auto.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年08月02日 星期日 18时41分03秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<unordered_map>
#include<algorithm>
using namespace std;

class A {
public:
    static const auto x = 123;
};

int main() {
    auto a = 123;
    cout << sizeof(a) << endl;
    map<int, int> mp;
    mp[789465] = 176523;
    mp[4657] = 712;
    mp[999] = 10000;
    for (auto iter = mp.begin(); iter != mp.end(); iter++) {
        cout << iter->first << " "  << iter->second << endl;
    }
    for (auto &x : mp) {
        cout << x.first << " " << x.second << endl;
    }
    return 0;
}
