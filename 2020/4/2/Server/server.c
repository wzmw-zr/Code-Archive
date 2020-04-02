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

void print() {
	User *head = start;
	while (head->next) {
		printf("%s\n", head->next->name);
		head = head->next;
	}
}

void *work(void *arg) {
	User *user = (User *) arg, tmp;
	int fd = user->sockfd;
	if (recv(fd, (void *) &tmp, sizeof(tmp), 0) <= 0) {
		perror("recv");
		close(fd);
		return NULL;
	}
	strcpy(user->name, tmp.name);
	printf("%s\n", user->name);
	// 判断用户是否存在
	LOCK;
	if (UserExist(user->name)) {
		UNLOCK;
		// 若用户存在，就组织并返回用户已经存在的信息
		Message msg;
		msg.type = -1;
		if (send(fd, (void *) &msg, sizeof(msg), 0) <= 0) {
			perror("send");
		}
		close(fd);
		return NULL;
	} else {
		AddUser(user);
		UNLOCK;
		// 给用户发送登录成功的信息。
		Message msg;
		msg.type = 0;
		if (send(fd, (void *) &msg, sizeof(msg), 0) <= 0) {
			perror("send");
			close(fd);
			return NULL;
		}
	}
	// 接收用户信息并进行转发处理
	while (1) {
		Message msg;
		if (recv(fd, (void *) &msg, sizeof(msg), 0) <= 0) {
			perror("recv");
			close(fd);
			return NULL;
		}
		LOCK;
		HandleMessage(fd, msg);
		UNLOCK;
	}
	// 打印当前的用户信息
	print();
	return NULL;
}

int main() {
	start = (User *) calloc(sizeof(User), 1);
	char *port = get_value(path, "PORT");
	int sockfd = GetSocket();
	BindAndListen(sockfd, atoi(port));
	while (1) {
		User *user = (User *) calloc(sizeof(User), 1);
		if ((user->sockfd = accept(sockfd, NULL, NULL)) <= 0) {
			perror("accept");
			continue;
		}
		pthread_attr_t attr;
		pthread_attr_init(&attr);
		pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);
		pthread_create(&(user->tid), &attr, work, (void *) user);
	}
	return 0;
}
