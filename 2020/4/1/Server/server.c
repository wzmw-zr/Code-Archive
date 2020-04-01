/*************************************************************************
	> File Name: server.c
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年04月01日 星期三 13时25分41秒
 ************************************************************************/

#include "1.include/head.h"
#include "1.include/message.h"
#include "1.include/tcp_server.h"

char *path = "./server.conf";

void *work(void *arg) {
	int fd = *(int *) arg;
	char name[100];
	if (recv(fd, name, sizeof(name), 0) <= 0) {
		perror("recv");
		close(fd);
		return NULL;
	}
	printf("%s\n", name);
	close(fd);
	return NULL;
}

int main() {
	char *port = get_value(path, "PORT");
	int sockfd = GetSocket(port);
	BindAndListen(sockfd, atoi(port));
	while (1) {
		int fd;
		pthread_t tid;
		if ((fd = accept(sockfd, NULL, NULL)) <= 0) {
			perror("accept");
			continue;
		}
		pthread_create(&tid, NULL, work, (void *) &fd);
	}
	return 0;
}
