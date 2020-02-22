/*************************************************************************
	> File Name: 3.case.c
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年01月29日 星期三 23时03分36秒
 ************************************************************************/

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<string.h>

typedef struct ram_block {
    size_t size;
    void *next_block;
    void *prev_block;
    int is_free;
} ram_block;

typedef struct free_block_list {
    ram_block *head;
} free_block_list;

free_block_list new_free_list;

void *new_malloc(size_t sizes) {
    ram_block *new_block = (ram_block *) sbrk(sizeof(ram_block));
    new_block->size = sizes;
    new_block->next_block = NULL;
    new_block->prev_block = NULL;
    new_block->is_free = 0;
    void *ret = sbrk(sizes);
    return ret;
}

void new_free(void *p) {
    ram_block *block_start = (ram_block *) (p - sizeof(ram_block));
    block_start->is_free = 1;
    if (!new_free_list.head) {
        new_free_list.head = block_start;
        return ;
    }
    ram_block *current_block = new_free_list.head;
    while (current_block->next_block) current_block = current_block->next_block;
    current_block->next_block = block_start;
    block_start->prev_block = current_block;
}

void output(free_block_list *list) {
    ram_block *current_block = list->head;
    while (current_block) {
        printf("%d\n", current_block->size);
        current_block = current_block->next_block;
    }
}


int main() {
    new_free_list.head = NULL;
    int n = 20, m = 10;
    char *a = (char *) new_malloc(n);
    char *b = (char *) new_malloc(m);
    scanf("%s", a);
    scanf("%s", b);
    printf("%s\n", a);
    printf("%s\n", b);
    new_free(a);
    new_free(b);
    output(&new_free_list);
    return 0;
}
