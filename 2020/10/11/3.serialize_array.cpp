/*************************************************************************
	> File Name: 3.serialize_array.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年10月11日 星期日 08时27分05秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
#include<ctime>
using namespace std;

string serialize_array(vector<int> &nums) {
    string ans = "[";
    for (int i = 0; i < nums.size(); i++) {
        if (i) ans += ",";
        ans += to_string(nums[i]);
    }
    ans += "]";
    return ans;
}

int main() {
    srand(time(0));
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) arr[i] = rand() % 100000;
    string ans = serialize_array(arr);
    cout << ans << endl;
    return 0;
}
