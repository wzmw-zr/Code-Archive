/*************************************************************************
	> File Name: 5.NewCode.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年08月12日 星期三 20时49分45秒
 ************************************************************************/

#include<iostream>
#include<vector>
#include<functional>
#include<algorithm>
using namespace std;
#define MAX_N 100000

struct Area {
    int x, y;    
};

int n, l;

int main() {
    cin >> n >> l;
    vector<Area> area(n);
    for (int i = 0; i < n; i++) {
        cin >> area[i].x >> area[i].y;
    }
    auto cmp = [](Area &a, Area &b) -> bool {
        if (a.x - b.x) return a.x < b.x;
        return a.y < b.y;
    };
    sort(area.begin(), area.end(), cmp);
    for (int i = 0; i < n; i++) {
        cout << area[i].x << " " << area[i].y << endl;
    }
    int end_line = 0;
    int cnt = 0;
    for (int i = 0; i < n;) {
        int flag = 0;
        int tmp = end_line;
        while (area[i].x <= end_line) {
            flag = 1;
            tmp = max(tmp, area[i].y);
            i++;
        }
        if (!flag) {
            cout << -1 << endl;
            return 0;
        }
        end_line = max(end_line, tmp);
        cnt++;
        if (end_line >= l) break;
    }
    if (end_line < l) cout << -1 << endl;
    else cout << cnt << endl;
    return 0;
}
