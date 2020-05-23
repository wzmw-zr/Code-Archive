/*************************************************************************
	> File Name: 5.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年05月23日 星期六 16时30分54秒
 ************************************************************************/

#include <algorithm>
#include <iostream>
using namespace std;

/*int bs(int *num, int l, int r, int target) {
    if (l == r) return l + 1;
    int mid = (l + r + 1) >> 1;
    if (num[mid] < target) return bs(num, mid, r, target);
    return bs(num, l, mid - 1, target);
}
*/

int find_first_location(int *num, int len, int target) {
    int l = 0, r = len - 1;
    while (l < r) {
        int mid = (l + r + 1) >> 1;
        if (num[mid] < target) l = mid;
        else r = mid - 1;
    }
    if (l == 0 && num[l] >= target) return 0;
    return l + 1;
}
int main() {
	int num[100000];
	int n, m;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> num[i];
	}
	cin >> m;
	for (int i = 0; i < m; ++i) {
		int value;
		cin >> value;
		cout << find_first_location(num, n, value) << endl;
	}
	return 0;
}
