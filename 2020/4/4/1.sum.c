/*************************************************************************
	> File Name: 1.sum.c
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年04月04日 星期六 15时05分17秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<sys/socket.h>
#include<sys/file.h>
#include<sys/wait.h>

char num_file[] = "./.num";
char lock_file[] = "./lock";
int x;

typedef struct Num {
    int now;
    int sum;
} Num;

size_t get_num(Num *num) {
    size_t read;
    FILE *fp = fopen(num_file, "rb");
    if (!fp) {
        perror(num_file);
        return -1;
    }
    if ((read = fread(num, 1, sizeof(Num), fp)) < 0) {
        perror("fread");
        return -1;
    }
    fclose(fp);
    return read;
}

size_t set_num(Num *num) {
    FILE *fp = fopen(num_file, "wb"); 
    size_t write = fwrite(num, 1, sizeof(Num), fp);
    fclose(fp);
    printf("write %zu\n", write);
    return write;
}

void do_add(int max, int x) {
    Num num;
    while (1) {
        FILE *lock = fopen(lock_file, "w");
        flock(lock->_fileno, LOCK_EX);
        if (get_num(&num) < 0) {
            fclose(lock);
            continue;
        }
        printf("<%d> : %d %d\n", x, num.now, num.sum);
        if (num.now > max) break;
        num.sum += num.now;
        num.now++;
        set_num(&num);
        flock(lock->_fileno, LOCK_UN);
        fclose(lock);
    }
}

void getvalue(char *filename) {
    FILE *fp = fopen(filename, "w+");
    int fd = fp->_fileno;
    flock(fd, LOCK_EX);
    char *line = (char *) calloc(sizeof(char), 100);
    size_t size = 100; 
    getline(&line, &size, fp);
    line[strlen(line) - 1] = '\0';
    size = 100; 
    int num = atoi(line);
    getline(&line, &size, fp);
    line[strlen(line) - 1] = '\0';
    int sum = atoi(line);
    num++;
    sum += num; 
    printf("num = %d, sum = %d\n", num, sum);
    ftruncate(fd, 0);
    lseek(fd, 0, SEEK_SET);
    //fclose(fp);
    //fp = fopen(filename, "w");
    char s_num[256] = {0};
    char s_sum[256] = {0};
    sprintf(s_num, "%d\n", num);
    sprintf(s_sum, "%d\n", sum);
    fputs(s_num, fp);
    fputs(s_sum, fp);
}

int main(int argc, char **argv) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s max ins\n", argv[0]);
        exit(1);
    }
    int max = atoi(argv[1]);
    int ins = atoi(argv[2]);
    Num num;
    num.now = 0;
    num.sum = 0;
    set_num(&num);
    pid_t pid;
    for (int i = 1; i <= ins; i++) {
        if ((pid = fork()) < 0) {
            perror("fork");
            return 1;
        } else if (pid == 0) {
            x = i;
            break;
        }
    }
    if (pid == 0) {
        do_add(max, x);
        exit(0);
    }
    while (ins) {
        wait(NULL);
        ins--;
    }
    get_num(&num);
    printf("<ans = %d>\n", num.sum);
    return 0;
}
