/*************************************************************************
	> File Name: 1.file_io.c
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年02月06日 星期四 10时26分14秒
 ************************************************************************/

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>

int main() {
    int fd = open("case.txt", O_CREAT | O_RDWR, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH);
    printf("%d\n", fd);
    char sentence[100] = "hello world!";
    printf("length = %d\n", write(fd, sentence, strlen(sentence)));
    char output[100] = {0};
    if (read(fd, output, strlen(sentence)) != -1) printf("%s\n", output);
    printf("len = %d\n", strlen(output));
    return 0;
}
