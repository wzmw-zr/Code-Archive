/*************************************************************************
	> File Name: 2.map.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年07月21日 星期二 20时10分33秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<map>
#include<unordered_map>
using namespace std;

int main() {
    map<double, string> arr;
    arr[1.2] = "hello";
    arr[4.3] = "world";
    arr[-4.5] = "haizei";
    arr[89.7] = "world";

    double n;
    while (cin >> n) {
        // if use arr[n], the map will definitely add arr[n] even not exist
        #if 0
        if (arr[n] != "") {
            cout << "Find : " << arr[n] << endl;
        } else {
            cout << "Not found : " << n << endl;
        }
        #endif
        // arr.find() will not add new node if not exist
        if (arr.find(n) != arr.end()) {
            cout << "find : " << arr[n] << endl;
        } else {
            cout << " not found : " << n << endl;
        }
    }
    for (auto iter = arr.begin(); iter != arr.end(); iter++) {
        cout << iter->first << " " << iter->second << endl;
    } 
    return 0;
}
