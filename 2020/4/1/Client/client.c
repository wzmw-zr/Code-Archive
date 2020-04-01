/*************************************************************************
	> File Name: client.c
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年04月01日 星期三 14时10分03秒
 ************************************************************************/

#include "1.include/head.h"
#include "1.include/tcp_client.h"
char *path = "./client.conf";

int main() {
	char *ip = get_value(path, "SERVER");
	char *port = get_value(path, "PORT");
	char *name = get_value(path, "USERNAME");
	int sockfd = socket(AF_INET, SOCK_STREAM, 0);
	struct sockaddr_in address = GetAddress(ip, port);
	ConnectServer(sockfd, address);
	Login(name, sockfd);
	close(sockfd);
	return 0;
}