/*************************************************************************
	> File Name: 4.assignment.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年10月23日 星期五 17时27分22秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<unordered_map>
#include<map>
#include<set>
#include<algorithm>
using namespace std;
#define MAX_N 100000

int n;
struct Task {
    int r, p;
};
Task task[MAX_N + 10];
int start_t, end_t, done, ans;

void update() {
    int flag = 0;
    for (int i = done; i < n; i++) {
        if (task[i].r < start_t) {
            if (!flag) {
                if (!(--task[i].p)) {
                    ans += start_t;
                    cout << i << " " << start_t << endl;
                    done++;
                }
                flag = 1;
            }
            task[i].r = start_t;
        }
    }
    sort(task + done, task + n, [](Task &a, Task &b){ return a.r == b.r ? a.p < b.p : a.r < b.r; });
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> task[i].r >> task[i].p;
    //for (int i = 0; i < n; i++) cout << task[i].r << " " << task[i].p << endl;
    sort(task, task + n, [](Task &a, Task &b){ return a.r == b.r ? a.p < b.p : a.r < b.r; });
    start_t = task[0].r;
    while (done < n) {
        start_t++;
        update();
    }
    cout << ans << endl;
    return 0;
}
