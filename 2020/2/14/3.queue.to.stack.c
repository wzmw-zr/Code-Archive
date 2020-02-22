/*************************************************************************
	> File Name: 3.queue.to.stack.c
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年02月14日 星期五 10时00分23秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>


typedef struct {
    int *data;
    int head, tail, size, count;
} MyStack;

/** Initialize your data structure here. */

MyStack* myStackCreate() {
    MyStack *s = (MyStack *) malloc(sizeof(MyStack)); 
    s->data = (int *) malloc(sizeof(int) * 1000);
    s->head = s->tail = s->count = 0;
    s->size = 1000;
    return s;
}

/** Push element x onto stack. */
void myStackPush(MyStack* obj, int x) {
    obj->data[obj->tail] = x;
    obj->tail = (obj->tail + 1) % obj->size;
    obj->count++;
}

/** Removes the element on top of the stack and returns that element. */
int myStackPop(MyStack* obj) {
    int ret = obj->data[obj->tail];
    if (obj->count == 1) {
        obj->tail = obj->head;    
        return ret;
    }
    int j = 0;
    while (j < obj->count - 1) {
        obj->data[(obj->tail + j + 1) % obj->size] = obj->data[(obj->head + j) % obj->size];
        j++;
    }
    obj->head = obj->tail;
    obj->tail = (obj->tail + (obj->count - 1)) % obj->size;
    obj->head = (obj->head + 1) % obj->size;
    obj->count--;
    return ret;
}

/** Get the top element. */
int myStackTop(MyStack* obj) {
    return obj->data[obj->tail]; 
}

/** Returns whether the stack is empty. */
int myStackEmpty(MyStack* obj) {
    return obj->count == 0; 
}

void myStackFree(MyStack* obj) {
    free(obj->data); 
    free(obj);
}

/**
 * Your MyStack struct will be instantiated and called as such:
 * MyStack* obj = myStackCreate();
 * myStackPush(obj, x);
 
 * int param_2 = myStackPop(obj);
 
 * int param_3 = myStackTop(obj);
 
 * bool param_4 = myStackEmpty(obj);
 
 * myStackFree(obj);
*/
