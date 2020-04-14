/*************************************************************************
	> File Name: 1.popen.c
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年04月14日 星期二 18时27分11秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<sys/wait.h>
#include<errno.h>

static pid_t *childpid = NULL;
static int max;

FILE *my_popen(const char *command, const char *type) {
    FILE *fp;
    int pipefd[2];
    pid_t pid;
    if ((type[0] != 'r' && type[0] != 'w') || type[1] != '\0') {
        errno = EINVAL;
        return NULL;
    }
    if (!childpid) { 
        max = sysconf(_SC_OPEN_MAX);
        if ((childpid = (pid_t *) calloc(sizeof(pid_t), max)) == NULL) {
            perror("calloc");
            exit(1);
        }
    }
    if (pipe(pipefd) < 0) {
        return NULL;
    }
    if (pipefd[0] >= max || pipefd[1] >= max) {
        close(pipefd[0]);
        close(pipefd[1]);
        return NULL;
    }
    if ((pid = fork()) < 0) {
        return NULL;
    }
    if (pid == 0) {
        if (type[0] == 'r') {
            close(pipefd[0]);
            if (pipefd[1] != STDOUT_FILENO) {
                dup2(pipefd[1], STDOUT_FILENO);
                close(pipefd[1]);
            } 
        } else {
            close(pipefd[1]);
            if (pipefd[0] != STDIN_FILENO) {
                dup2(pipefd[0], 0);
                close(pipefd[0]);
            }
        }
        for (int i = 0; i <= max; i++) {
            if (childpid[i] > 0) {
                close(i);
            }
        }
        execl("/bin/bash", "bash", "-c", command, NULL);
        exit(0);
    }

    if (type[0] == 'r') {
        close(pipefd[1]);
        if ((fp = fdopen(pipefd[0], type)) == NULL) return NULL;
    } else {
        close(pipefd[0]);
        if ((fp = fdopen(pipefd[1], type)) == NULL) return NULL;
    }
    childpid[fileno(fp)] = pid;
    return fp;
}

int my_pclose(FILE *fp) {
    int status, fd = fileno(fp);
    pid_t pid;
    if (childpid == NULL) {
        errno = EINVAL;
        return -1;
    }
    if (fd >= max) {
        errno = EINVAL;
        return -1;
    }
    pid = childpid[fd];
    if (pid == 0) {
        errno = EINVAL;
        return -1;
    }
    childpid[fd] = 0;
    close(fd);
    waitpid(pid, &status, 0);
    return status;
}

int main() {
    FILE *fp;
    char buffer[1024] = {0};
    if ((fp = my_popen("ls -al /etc", "r")) == NULL) {
        perror("my_popen");
        exit(1);
    }
    while (fgets(buffer, sizeof(buffer), fp)) {
        printf("%s", buffer);
        memset(buffer, 0, sizeof(buffer));
    }
    int status = my_pclose(fp);
    printf("%d\n", status);
    return 0;
}
