/*************************************************************************
	> File Name: 5.sort_template.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年08月10日 星期一 14时29分02秒
 ************************************************************************/

#include<iostream>
#include<cstdlib>
#include<cstring>
#include<ctime>
using namespace std;

template<typename ValueType>
void merge(ValueType *arr, int left, int right) {
    int mid = (left + right) / 2;
    ValueType *temp = new ValueType[right - left + 1];
    int x = left, y = mid + 1, ind = 0;
    while ((x <= mid) || (y <= right)) {
        if ((x <= mid) && ((y > right) || arr[x] < arr[y])) temp[ind++] = arr[x++];
        else temp[ind++] = arr[y++];
    }
    memcpy(arr + left, temp, sizeof(ValueType) * (right - left + 1));
    delete[] temp;
}

template<typename ValueType>
void merge_sort(ValueType *arr, int left, int right) {
    if (left == right) return ;
    int mid = (left + right) / 2;
    merge_sort(arr, left, mid);
    merge_sort(arr, mid + 1, right);
    merge(arr, left, right);
}

template<typename ValueType>
void quick_sort(ValueType *arr, int left, int right) {
    if (left >= right) return ;
    int offset = rand() % (right - left + 1);
    ValueType temp = arr[left + offset];
    arr[left + offset] = arr[left];
    arr[left] = temp;
    int x = left, y = right;
    while (x < y) {
        while ((x < y) && (arr[y] > temp)) y--;
        if (x < y) arr[x++] = arr[y];
        while ((x < y) && (arr[x] <= temp)) x++;
        if (x < y) arr[y--] = arr[x];
    }
    arr[x] = temp;
    quick_sort(arr, left, x);
    quick_sort(arr, x + 1, right);
}


int main() {
    srand(time(0));
    int arr[20];
    for (int i = 0; i < 20; i++) arr[i] = rand() % 1000;
    for (int i = 0; i < 20; i++) cout << arr[i] << " ";
    cout << endl;
    merge_sort(arr, 0, 19);
    for (int i = 0; i < 20; i++) cout << arr[i] << " ";
    cout << endl;
    return 0;
}
