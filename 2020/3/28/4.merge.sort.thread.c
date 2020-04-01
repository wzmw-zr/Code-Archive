/*************************************************************************
	> File Name: 3.merge.sort.thread.c
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年03月28日 星期六 10时00分13秒
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

#define NUM 1000

int number[NUM];
int temp[NUM];

typedef struct Info {
    int left, right;
} Info;

/*void merge(int left, int right) {
    int mid = (left + right) >> 1, x = left, y = mid + 1, ind = 0;
    int tmp[right - left + 1];
    while (x <= mid || y <= right) {
        if (x <= mid && (y > right || number[x] <= number[y])) tmp[ind++] = number[x++];
        else tmp[ind++] = number[y++];
    }
    memcpy(number + left, tmp, sizeof(tmp));
}

void merge_sort(int left, int right) {
    if (left == right) return ;
    int mid = (left + right) >> 1;
    merge_sort(left, mid);
    merge_sort(mid + 1, right);
    merge(left, right);
}*/

void thread_merge(int left, int right) {
    int mid = (left + right) >> 1, x = left, y = mid + 1, ind = 0;
    int tmp[right - left + 1];
    while (x <= mid || y <= right) {
        if (x <= mid && (y > right || temp[x] <= temp[y])) tmp[ind++] = temp[x++];
        else tmp[ind++] = temp[y++];
    }
    memcpy(temp + left, tmp, sizeof(tmp));
}

void *thread_merge_sort(void *arg) {
    Info *info = (Info *) arg;
    if (info->left == info->right) return NULL;
    int mid = (info->left + info->right) >> 1;
    Info tmp[2];
    pthread_t tid[2];
    void *status[2];
    tmp[0].left = info->left;
    tmp[0].right = mid;
    tmp[1].left = mid + 1;
    tmp[1].right = info->right;
    pthread_create(&tid[0], NULL, thread_merge_sort, (void *) &(tmp[0]));
    pthread_create(&tid[1], NULL, thread_merge_sort, (void *) &(tmp[1]));
    pthread_join(tid[0], &(status[0]));
    pthread_join(tid[1], &(status[1]));
    thread_merge(info->left, info->right);
    return NULL;
}

int main(int argc, char **argv) {
    srand(time(0));
    for (int i = 0; i < NUM; i++) temp[i] = rand() % 10000;
    /*memcpy(temp, number, sizeof(number));
    for (int i = 0; i < 20; i++) printf("%d ", number[i]);
    printf("\n");
    merge_sort(0, 19);
    */
    for (int i = 0; i < NUM; i++) printf("%d ", temp[i]);
    printf("\n");
    pthread_t tid;
    Info info = {0, NUM - 1};
    pthread_create(&tid, NULL, thread_merge_sort, (void *) &info);
    void *status;
    pthread_join(tid, &status);
    for (int i = 0; i < NUM; i++) printf("%d ", temp[i]);
    printf("\n");
    return 0;
}
