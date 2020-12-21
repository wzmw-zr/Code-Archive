/*************************************************************************
	> File Name: 5.LeetCode705.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年12月21日 星期一 14时12分34秒
 ************************************************************************/

#include<iostream>
#include<cstring>
#include<cstdlib>
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

class MyHashSet {
public:
    bool st[1000001];
    MyHashSet() {
        memset(st, 0, sizeof(st));
    }
    
    void add(int key) {
        st[key] = true;
    }
    
    void remove(int key) {
        st[key] = false;
    }
    
    bool contains(int key) {
        return st[key];
    }
};
int main() {
    return 0;
}
