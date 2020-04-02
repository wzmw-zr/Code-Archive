/*************************************************************************
	> File Name: tcp_client.h
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年04月01日 星期三 14时20分42秒
 ************************************************************************/

#ifndef _TCP_CLIENT_H
#define _TCP_CLIENT_H
#include "message.h"
// ok
char *get_value(char *path, char *key);
//ok
int GetSocket();
//ok
struct sockaddr_in GetAddress(char *ip, char *port);
// ok
void ConnectServer(int sockfd, struct sockaddr_in address);

// 解析用户的输入，ok
Message ParseLine(char *line, char *name);

// 发送信息，ok
void SendMessage(int sockfd, Message *msg);

// 处理服务端发来的信息，ok
void HandleMessage(int sockfd, Message *msg);

//ok
void Login(char *name, int sockfd);
void Logout(User *user);
#endif
