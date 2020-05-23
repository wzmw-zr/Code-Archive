/*************************************************************************
	> File Name: 4.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年05月23日 星期六 16时28分16秒
 ************************************************************************/

#include <iostream>
using namespace std;

int binary_search(int target, int *num, int len) {
    int l = 0, r = len - 1;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (num[mid] == target) return mid;
        if (num[mid] > target) r = mid -1;
        else l = mid + 1;
    }
    return -1;
}
int main() {
	int num[1000000];
	int n, m;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> num[i];
	}
	cin >> m;
	for (int i = 0; i < m; ++i) {
		int value;
		cin >> value;
		cout << binary_search(value, num, n) << endl;
	}
	return 0;
}
