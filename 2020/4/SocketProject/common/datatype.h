/*************************************************************************
	> File Name: datatype.h
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年06月09日 星期二 18时13分12秒
 ************************************************************************/

#ifndef _DATATYPE_H
#define _DATATYPE_H
#define MAX_MSG 1024
struct LogRequest{
    char name[20];
    int team; //0 RED 1 BLUE
    char msg[512];
};

struct LogResponse{
    int type; //0 success 1 failed
    char msg[512];
};

struct Point{
    int x;
    int y;
};

struct User{
    int team;
    int fd;
    int online;
    char name[20];
    int flag; // 未响应次数
    struct sockaddr_in addr;
    struct Point loc;
};

struct Map {
    int width;
    int height;
    struct Point start;
    int gate_width;
    int gate_heigth;
};

struct Ctrl {
    int carry;
    int kick;
};

struct TransMsg{
    int dirx;
    int diry;
    struct Ctrl ctrl;
};


#define FT_TEST 0x01
#define FT_WALL 0x02
#define FT_MSG  0x04
#define FT_ACK  0x08
#define FT_FIN  0x10

struct FootBallMsg {
    int type;
    int size;
    int team;
    char name[20];
    char msg[MAX_MSG];
};
#endif
