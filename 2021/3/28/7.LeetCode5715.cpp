/*************************************************************************
	> File Name: 7.LeetCode5715.cpp
	> Author: 
	> Mail: 
	> Created Time: 2021年03月28日 星期日 10时46分05秒
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

int reinitializePermutation(int n) {
    vector<int> orig(n);
    for (int i = 0; i < n; i++) orig[i] = i;
    vector<int> perm = orig;
    int step = 0;
    while (1) {
        step++;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) arr[i] = perm[i / 2];
            else arr[i] = perm[n / 2 + (i - 1) / 2];
        }
        if (arr == orig) break;
        perm = arr;
    }
    return step;
}

int main() {
    int n;
    cin >> n;
    cout << reinitializePermutation(n) << endl;
    return 0;
}
