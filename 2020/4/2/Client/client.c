/*************************************************************************
	> File Name: client.c
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年04月01日 星期三 14时10分03秒
 ************************************************************************/

#include "1.include/head.h"
#include "1.include/tcp_client.h"
char *path = "./client.conf";

void *work(void *arg) {
	int sockfd = *(int *) arg;
	Message msg;
	while (1) {
		memset(&msg, 0, sizeof(msg));
		if (recv(sockfd, (void *) &msg, sizeof(msg), 0) <= 0) {
			perror("recv");
			continue;
		}
		HandleMessage(sockfd, &(msg));
	}
	return NULL;
}

int main() {
	char *ip = get_value(path, "SERVER");
	char *port = get_value(path, "PORT");
	char *name = get_value(path, "USERNAME");
	int sockfd = socket(AF_INET, SOCK_STREAM, 0);
	struct sockaddr_in address = GetAddress(ip, port);
	ConnectServer(sockfd, address);
	Login(name, sockfd);
	Message msg;
	if (recv(sockfd, &msg, sizeof(msg), 0) <= 0) {
		close(sockfd);
		return 0;
	}
	pid_t pid;
	pthread_t tid;
	pthread_attr_t attr;
	pthread_attr_init(&attr);
	pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);
	// 子线程用于处理服务端发来的信息
	pthread_create(&tid, &attr, work, (void *) &sockfd);
	// 父线程用来处理用户的输入，给服务端发送信息
	while (1) {
		printf("Input information:\n");
		char line[1024];
		scanf("%[^\n]s", line);
		getchar();
		// 解析用户的输入
		memset(&msg, 0, sizeof(msg));
		Message msg = ParseLine(line, name);
		if (send(sockfd, (void *) &msg, sizeof(msg), 0) <= 0) {
			perror("send");
			continue;
		}
	}
	close(sockfd);
	return 0;
}