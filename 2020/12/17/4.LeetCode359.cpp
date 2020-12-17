/*************************************************************************
	> File Name: 4.LeetCode359.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年12月17日 星期四 13时30分43秒
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

class Logger {
public:
    unordered_map<string, int> mp;
    Logger() {}

    bool shouldPrintMessage(int timestamp, string message) {
        if (!mp.count(message)) {
            mp[message] = timestamp;
            return true;
        }
        if (timestamp - mp[message] < 10) return false;
        mp[message] = timestamp;
        return true;
    }
};

int main() {
    return 0;
}
