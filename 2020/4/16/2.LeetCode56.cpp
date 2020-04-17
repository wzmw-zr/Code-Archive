/*************************************************************************
	> File Name: 2.LeetCode56.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年04月16日 星期四 22时06分34秒
 ************************************************************************/

#include<iostream>
#include<cstdlib>
#include<string>
#include<string>
#include<vector>
using namespace std;

int cmp(vector<int> a, vector<int> b) {
    if (a[0] < b[0]) return 1;
    if (a[0] > b[0]) return 0;
    return a[0] <= b[0];
}

void merge_vector(vector<vector<int>> &intervals, int left, int right) {
    if (left == right) return ;
    int mid = (left + right) >> 1;
    vector<vector<int>> tmp;
    int x = left, y = mid + 1;
    while (x <= mid || y <= right) {
        if (x <= mid && (y > right || cmp(intervals[x], intervals[y]))) tmp.push_back(intervals[x++]);
        else tmp.push_back(intervals[y++]);
    }
    for (int i = 0; i < right - left + 1; i++) {
        intervals[left + i] = tmp[i];
    }
}

/*void merge_vector(vector<vector<int>> &intervals, int left, int right) {
    if (left == right) return ;
    int mid = (left + right) >> 1;
    vector<vector<int>> tmp;
    int x = left, y = mid + 1;
    while (x <= mid || y <= right) {
        if (x <= mid && (y > right || intervals[x][0] < intervals[y][0])) tmp.push_back(intervals[x++]);
        else tmp.push_back(intervals[y++]);
    }
    for (int i = 0; i < right - left + 1; i++) {
        intervals[left + i] = tmp[i];
    }
}
*/

void merge_sort(vector<vector<int>> &intervals, int left, int right) {
    if (left == right) return ;
    int mid = (left + right) >> 1;
    merge_sort(intervals, left, mid);
    merge_sort(intervals, mid + 1, right);
    merge_vector(intervals, left, right);
}

vector<vector<int>> T_merge(vector<vector<int>> &intervals) {
    vector<vector<int>> ret;
    for (int i = 0; i < intervals.size(); i++) {
        if (!i) {
            ret.push_back(intervals[i]);
            continue;
        }
        vector<int> tmp = ret[ret.size() - 1];
        if (tmp[1] >= intervals[i][0]) {
            ret.pop_back();
            tmp[1] = intervals[i][1];
            ret.push_back(tmp);
            continue;
        } 
        ret.push_back(intervals[i]);
    }
    return ret;
}

vector<vector<int>> merge(vector<vector<int>> &intervals) {
    merge_sort(intervals, 0, intervals.size() - 1);
    return T_merge(intervals);
}

int main() {
    vector<vector<int>> data, ret;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a, b;
        vector<int> tmp;
        cin >> a >> b;
        tmp.push_back(a);
        tmp.push_back(b);
        data.push_back(tmp);
    }
    for (int i = 0; i < data.size(); i++) {
        cout << "[" << data[i][0] << " " << data[i][1] << "]" << endl;
    }
    ret = merge(data);
    for (int i = 0; i < ret.size(); i++) {
        cout << "[" << ret[i][0] << " " << ret[i][1] << "]" << endl;
    }
    return 0;
}
