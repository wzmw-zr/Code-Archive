/*************************************************************************
	> File Name: 1.merge.sort.thread.c
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年03月28日 星期六 09时00分28秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<unistd.h>
#include<fcntl.h>
#include<pthread.h>
#include<semaphore.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>

int number[20];

typedef struct Info {
    int left, right;
} Info;

void merge(Info info) {
    int mid = (info.left + info.right) >> 1;
    int temp[info.right - info.left + 1];
    int ind = 0, x = info.left, y = mid + 1;
    while (ind <= info.right - info.left) {
        if (x <= mid && (y >= info.right - info.left + 1 || number[x] <= number[y])) temp[ind++] = number[x++]; 
        else temp[ind++] = number[y++];
    }
    memcpy(number + info.left, temp, sizeof(temp));
}

void *merge_sort(void *arg) {
    Info *info = (Info *) arg;
    if (info->left == info->right) return NULL;
    int mid = (info->left + info->right) >> 1;
    Info tmp1 = {info->left, mid}, tmp2 = {mid + 1, info->right};
    pthread_t tid[2];
    void *status[2];
    pthread_create(&tid[0], NULL, merge_sort, (void *) &tmp1);
    pthread_create(&tid[1], NULL, merge_sort, (void *) &tmp2);
    pthread_join(tid[0], &status[0]);
    pthread_join(tid[1], &status[1]);
    merge(*info);
    return NULL;
}

void m_sort(int *number, int left, int right) {
    if (left == right) return ;
    int mid = (left + right) >> 1;
    m_sort(number, left, mid);
    m_sort(number, mid + 1, right);
    Info info = {left, right};
    merge(info);
}

int main(int argc, char **argv) {
    srand(time(0));
    for (int i = 0; i < 20; i++) number[i] = rand() % 100;
    for (int i = 0; i < 20; i++) printf("%d ", number[i]);
    printf("\n");
    int temp[20];
    memcpy(temp, number, sizeof(int) * 20);
    pthread_t tid;
    Info info = {0, 19};
    pthread_create(&tid, NULL, merge_sort, (void *) &info);
    void *status;
    pthread_join(tid, &status);
    for (int i = 0; i < 20; i++) printf("%d ", number[i]);
    printf("\n");
    m_sort(temp, 0, 19);
    for (int i = 0; i < 20; i++) printf("%d ", temp[i]);
    printf("\n");
    return 0;
}
