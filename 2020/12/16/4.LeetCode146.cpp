/*************************************************************************
	> File Name: 4.LeetCode146.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年12月16日 星期三 18时23分00秒
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

class LRUCache {
public:
    int rest;
    int stamp;
    unordered_map<int, int> exist;
    unordered_map<int, int> key_value;
    map<int, int> mp;

    LRUCache(int capacity) {
        rest = capacity;
        stamp = 0;
    }

    int get(int key) {
        if (!exist.count(key)) return -1;
        mp.erase(mp.find(exist[key]));
        exist[key] = ++stamp;
        mp[exist[key]] = key;
        return key_value[key];
    }

    void put(int key, int value) {
        if (exist.count(key)) {
            mp.erase(mp.find(exist[key]));
            exist[key] = ++stamp;
            mp[exist[key]] = key;
            key_value[key] = value;
        } else {
            if (rest) {
                rest--;
                exist[key] = ++stamp;
                mp[exist[key]] = key;
                key_value[key] = value;
            } else {
                exist.erase(exist.find(mp.begin()->second));
                key_value.erase(key_value.find(mp.begin()->second));
                mp.erase(mp.begin());
                exist[key] = ++stamp;
                mp[exist[key]] = key;
                key_value[key] = value;
            }
        }
    }
};

int main() {
    return 0;
}
