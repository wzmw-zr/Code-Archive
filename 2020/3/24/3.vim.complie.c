/*************************************************************************
	> File Name: 4.vim.complie.c
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年03月24日 星期二 21时13分45秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<stdarg.h>
#include<unistd.h>
#include<fcntl.h>
#include<wait.h>
#include<regex.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>

void CheckArg(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage : %s [c source file / c++ source file]\n", argv[0]);
        exit(1);
    }
}

void CheckExit() {
    int status;
    if (wait(&status) == -1) {
        perror("wait");
        exit(1);
    }
}

int match(char *filename, char *regex) {
    regex_t preg;
    if (regcomp(&preg, regex, REG_EXTENDED)) {
        perror("regcomp");
        exit(1);
    }
    if (regexec(&preg, filename, 0, NULL, 0)) return 0;
    return 1;
}

int GetFileType(char *filename) {
    int ret = 0;
    if (match(filename, ".*\\.c$")) ret = 1;
    if (match(filename, ".*\\.cpp$")) ret = 2;
    return ret;
}

void edit_create(char *filename) {
    pid_t pid;
    if ((pid = fork()) == -1) {
        perror("fork");
        exit(1);
    } else if (pid == 0) {
        if (execlp("vim", "vim", filename, NULL) == -1) {
            perror("fork");
            exit(1);
        }
    } else CheckExit();
}

void do_compile(char *filename, char *method) {
    if (execlp(method, method, filename, "-o", "case", NULL) == -1) {
        perror("execlp");
        exit(1);
    }
}

void compile(char *filename) {
    pid_t pid;
    int type = GetFileType(filename);
    if (type == 0) {
        fprintf(stderr, "Invaild filename!\n");
        exit(1);
    }
    if ((pid = fork()) == -1) {
        perror("fork");
        exit(1);
    } else if (pid == 0) {
        if (type == 1) {
            do_compile(filename, "gcc");
        } else {
            do_compile(filename, "g++"); 
        }
    } else CheckExit();
}

void run(char *filename) {
    pid_t pid;
    if ((pid = fork()) == -1) {
        perror("fork");
        exit(1); 
    } else if (pid == 0) {
        if (execl("./case", "case", NULL) == -1) {
            perror("execl");
            exit(1);
        }
    } else CheckExit();
}

int main(int argc, char **argv) {
    CheckArg(argc, argv);
    edit_create(argv[1]);
    compile(argv[1]);
    run(argv[1]);
    return 0;
}
