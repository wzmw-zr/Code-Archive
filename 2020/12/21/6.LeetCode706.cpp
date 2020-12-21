/*************************************************************************
	> File Name: 6.LeetCode706.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年12月21日 星期一 14时17分45秒
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

class MyHashMap {
public:
    int mp[1000001];
    MyHashMap() {
        for (int i = 0; i < 1000001; i++) mp[i] = -1;
    }

    void put(int key, int value) {
        mp[key] = value;
    }

    int get(int key) {
        return mp[key];
    }

    void remove(int key) {
        mp[key] = -1;
    }
};

int main() {
    return 0;
}
