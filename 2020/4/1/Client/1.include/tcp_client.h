/*************************************************************************
	> File Name: tcp_client.h
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年04月01日 星期三 14时20分42秒
 ************************************************************************/

#ifndef _TCP_CLIENT_H
#define _TCP_CLIENT_H
#include "message.h"
char *get_value(char *path, char *key);

int GetSocket();
struct sockaddr_in GetAddress(char *ip, char *port);
void ConnectServer(int sockfd, struct sockaddr_in address);

void ParseLine(char *line, char *name);
void SendMessage(Message *msg);
void Login(char *name, int sockfd);
void Logout(User *user);
#endif
