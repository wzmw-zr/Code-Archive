/*************************************************************************
	> File Name: shell.c
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年04月12日 星期日 18时54分34秒
 ************************************************************************/

#include "../head/common.h"
#include "../head/shell.h"

int main() {
    while (1) {
        PrintLinePre(); 
        char command[256] = {0};
        scanf("%[^\n]s", command);
        getchar();
        pid_t pid;
        if ((pid = fork()) < 0) {
            perror("fork");
            exit(1);
        } else if (pid == 0) {
            HandleCommand(command);
            exit(0);
        } else {
            wait(NULL); 
        }
        //sleep(2);
    }
    return 0;
}
