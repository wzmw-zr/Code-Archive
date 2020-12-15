/*************************************************************************
	> File Name: 5.LeetCode379.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年12月15日 星期二 19时46分46秒
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

class PhoneDirectory {
public:
    /** Initialize your data structure here
        @param maxNumbers - The maximum numbers that can be stored in the phone directory. */
    set<int> st;
    unordered_map<int, bool> mp;

    PhoneDirectory(int maxNumbers) {
        for (int i = 0; i < maxNumbers; i++) {
            st.insert(i);
            mp[i] = true;
        }
    }

    /** Provide a number which is not assigned to anyone.
        @return - Return an available number. Return -1 if none is available. */
    int get() {
        if (!st.size()) return -1;
        int top = *st.begin();
        st.erase(st.begin());
        mp[top] = false;
        return top;
    }

    /** Check if a number is available or not. */
    bool check(int number) {
        return mp[number];
    }

    /** Recycle or release a number. */
    void release(int number) {
        st.insert(number);
        mp[number] = true;
    }
};

int main() {
    return 0;
}
