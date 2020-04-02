/*************************************************************************
	> File Name: 1.parse.line.c
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年04月02日 星期四 11时04分30秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Message {
    char name[256], target[256], file_path[256];
    int type;
    char data[1024];
} Message;


Message ParseLine(char *line, char *name) {
    Message msg;
    memset((void *) &msg, 0,  sizeof(msg));
    // line[0] == '@'表明这是一个私发信息
    if (line[0] == '@') {
        char *np = strchr(line, ' ');
        // 私发对象的名字
        snprintf(msg.target, np - line, "%s", line + 1);
        msg.type = 2;
        strcpy(msg.name, name);
        // 私发的信息
        strcpy(msg.data, np + 1);
        return msg;
    } else if (line[0] == '#') {
        // #1表示获取当前所有在线用户名字
        if (line[1] == '1') {
            msg.type = 5;
            strcpy(msg.name, name);
            return msg;
        } else if (line[1] == '2') {
            // 表示公发信息
            // TO DO：
            printf("send file\n");
            msg.type = 4;
            strcpy(msg.name, name);
            return msg;
        }
    } else {
        // 公发信息
        msg.type = 1;
        strcpy(msg.name, name);
        strcpy(msg.data, line);
        printf("send to all: data = %s\n", msg.data);
        return msg;
    }
}

int main() {
    char name[256] = "zhaorui";
    while (1) {
        char line[1024];
        scanf("%[^\n]s", line);
        getchar();
        Message msg = ParseLine(line, name);
    }
    return 0;
}
