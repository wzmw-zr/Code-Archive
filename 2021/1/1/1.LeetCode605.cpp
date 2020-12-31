/*************************************************************************
	> File Name: 1.LeetCode605.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年01月01日 星期五 00时05分33秒
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

bool canPlaceFlowers(vector<int>& flowerbed, int n) {
    if (!n) return true;
    int len = flowerbed.size();
    int cnt = 0;
    if (len == 1) {
        if (flowerbed[0] || n > 1) return false;
        return true;
    }
    if (!flowerbed[0] && !flowerbed[1]) {
        flowerbed[0] = 1;
        n--;
    }
    for (int i = 1; i < len - 1; i++) {
        if (flowerbed[i - 1] || flowerbed[i] || flowerbed[i + 1]) continue;
        flowerbed[i] = 1;
        n--;
    }
    if (!flowerbed[len - 1] && !flowerbed[len - 2]) {
        flowerbed[len - 1] = 1;
        n--;
    }
    return n <= 0;
}

int main() {
    return 0;
}
