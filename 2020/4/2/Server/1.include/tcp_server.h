/*************************************************************************
	> File Name: tcp_server.h
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年04月01日 星期三 13时51分11秒
 ************************************************************************/

#ifndef _TCP_SERVER_H
#define _TCP_SERVER_H
#include "head.h"
#include "message.h"

// 互斥量与用户链表的虚拟头节点。
#define LOCK pthread_mutex_lock(&mutex)
#define UNLOCK pthread_mutex_unlock(&mutex)

extern pthread_mutex_t mutex;

User *start;

// ok
char *get_value(char *path, char *key);
// ok
int GetSocket();
// ok
void BindAndListen(int sockfd, int port);

void UserLogin(char *name);
void UserLogout(char *name);
// 给所有用户发送信息
void SendAll(Message *msg);
// 给单个用户发送信息
void SendOne(Message *msg, User *user);


// 处理用户登录与登出， ok
User *UserExist(char *name);
// 0k
void AddUser(User *user);
// ok
void Deleteuser(char *name);

// 处理从用户收到的信息， ok
void HandleMessage(int fd, Message msg);
#endif
