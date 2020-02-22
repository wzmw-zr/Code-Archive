/*************************************************************************
	> File Name: 3.file_io.c
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年02月06日 星期四 11时18分46秒
 ************************************************************************/

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<stdlib.h>

int main() {
    int fd = open("new.txt", O_CREAT | O_RDWR, S_IRUSR | S_IWUSR);
    int old_fd = dup(fd);
    char sentence[100] = "hello world";
    dup2(1, fd);
    write(fd, sentence, strlen(sentence));
    write(old_fd, sentence, strlen(sentence));
    return 0;
}
