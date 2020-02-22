/*************************************************************************
	> File Name: 2.c
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年02月04日 星期二 20时27分50秒
 ************************************************************************/

#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>

int *number;

void *adding(void *arg){
  int *arg_ = (int *) arg;
  for(int i = 0; i < 5000000; i++){
    (*arg_)++;
  }
  return NULL;
}
void *adding(void *arg);
int main(){
  number = malloc(sizeof(int));
  pthread_t p[2];
  pthread_create(&p[0], 0, adding, number);
  pthread_create(&p[1], 0, adding, number);
  pthread_join(p[0], (void**)NULL);
  pthread_join(p[1], (void**)NULL);
  printf("%d\n", *number);
  return 0;
}
