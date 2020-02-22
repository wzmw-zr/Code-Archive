/*************************************************************************
	> File Name: 1.heap.sort.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年02月17日 星期一 09时54分37秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

#define swap(a, b) {\
    __typeof(a) __temp = a;\
    a = b; b = __temp;\
}

void downUpdate(int *arr, int n, int ind) {
    while ((ind << 1) <= n) {
        int temp = ind, l = ind << 1, r = ind << 1 | 1;
        if (arr[temp] < arr[l]) temp = l;
        if (r <= n && arr[temp] < arr[r]) temp = r;
        if (temp == ind) break;
        swap(arr[ind], arr[temp]);
        ind = temp;
    }
    return ;
}

void heap_sort(int *arr, int n) {
    arr -= 1;
    for (int i = n >> 1; i >= 1; i--) {
        downUpdate(arr, n, i);
    }
    for (int i = n; i > 1; i--) {
        swap(arr[1], arr[i]);
        downUpdate(arr, i - 1, 1);
    }
    return ;
}

void output(int *arr, int n) {
    printf("arr(%d) = [", n);
    for (int i = 0; i < n; i++) {
        i && printf(" ");
        printf("%d", arr[i]);
    }
    printf("\n");
}


int main() {
    srand(time(0));
    #define max_op 20
    int *arr = (int *) malloc(sizeof(int) * max_op);
    for (int i =0; i < max_op; i++) {
        arr[i] = rand() % 100;
    }
    output(arr, max_op);
    heap_sort(arr, max_op);
    output(arr, max_op);
    free(arr);
    return 0;
}
