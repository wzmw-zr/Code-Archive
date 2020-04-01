/*************************************************************************
	> File Name: tcp_server.h
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年04月01日 星期三 13时51分11秒
 ************************************************************************/

#ifndef _TCP_SERVER_H
#define _TCP_SERVER_H
#include "message.h"
// ok
char *get_value(char *path, char *key);
// ok
int GetSocket(char *port);
// ok
void BindAndListen(int sockfd, int port);

void UserLogin(char *name);
void UserLogout(char *name);
void SendAll(Message *msg);
void SendOne(Message *msg, User *user);

User *UserExist(char *name);
void AddUser(char *name);
void Deleteuser(char *name);
#endif
