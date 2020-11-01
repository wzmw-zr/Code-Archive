/*************************************************************************
	> File Name: 5.quick_sort.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年10月07日 星期三 18时38分26秒
 ************************************************************************/

#include<iostream>
#include<ctime>
#include<vector>
using namespace std;

void quick_sort(vector<int> &nums, int left, int right) {
    if (left >= right) return ;
    int ind = left + rand() % (right - left + 1);
    swap(nums[left], nums[ind]);
    int x = left, y = right, num = nums[left];
    while (x < y) {
        while (x < y && nums[y] >= num) y--;
        if (x < y) nums[x++] = nums[y];
        while (x < y && nums[x] < num) x++;
        if (x < y) nums[y--] = nums[x];
    }
    nums[x] = num;
    quick_sort(nums, left, x - 1);
    quick_sort(nums, x + 1, right);
}

int main() {
    srand(time(0));
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];
    quick_sort(nums, 0, n - 1);
    for (int x : nums) cout << x << " ";
    cout << endl;
    return 0;
}
