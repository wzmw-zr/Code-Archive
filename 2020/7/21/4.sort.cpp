/*************************************************************************
	> File Name: 4.sort.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年07月21日 星期二 20时54分15秒
 ************************************************************************/

#include<iostream>
#include<algorithm>
using namespace std;

struct CMP_FUNC {
    bool operator()(int a, int b) {
        return a > b;
    }
};

int main() {
    int arr[1000], n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];
    nth_element(arr, arr + 1, arr + n);
    cout << arr[1] << endl;
    sort(arr, arr + n, CMP_FUNC());
    //sort(arr, arr + n, [](int a, int b) ->bool { return a > b;  });
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
    return 0;
}
