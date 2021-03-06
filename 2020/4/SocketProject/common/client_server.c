#include "head.h"
#include "common.h"
#include "game.h"

extern int sockfd;

void * client_recv(void *arg) {
    while (1) {
        struct FootBallMsg msg;
        struct User user;
        bzero(&msg, sizeof(msg));
        recv(sockfd, (void *) &msg, sizeof(msg), 0);
        strcpy(user.name, msg.name);
        user.team = msg.team;
        if (msg.type & FT_TEST) {
            DBG(RED"HeartBeat from Server ❤️"NONE"\n");
            msg.type = FT_ACK;
            send(sockfd, (void *) &msg, sizeof(msg), 0);
        } else if (msg.type & FT_MSG) {
            DBG(GREEN "Server Msg : "NONE"%s\n", msg.msg);
            //Show_Message(, &user, msg.msg, 0);
        } else if (msg.type & FT_WALL) {
            //Show_Message(, NULL, msg.msg, 1);
        } else if (msg.type & FT_FIN) {
            DBG(GREEN"Server is going to stop.\n"NONE);
            endwin();
            exit(0);
        } else {
            DBG(GREEN "Server Msg : "NONE"Unsupport Message Type.\n");
        }
    }
}

/*while (1) {
    struct FootBallMsg msg;
    memset(msg.msg, 0, sizeof(msg.msg));
    ssize_t rsize = recv(sockfd, (void *) &msg, sizeof(msg), 0);
    if (msg.type & FT_TEST) {
        DBG(RED"HeartBeat from Server ❤️"NONE"\n");
        msg.type = FT_ACK;
        send(sockfd, (void *) &msg, sizeof(msg), 0);
    } else if (msg.type & (FT_MSG | FT_WALL)) {
        DBG(GREEN "Server Msg : "NONE"%s\n", msg.msg);
    } else if (msg.type & FT_FIN) {
        DBG(GREEN "Server Msg : "NONE"Unsupport Message Type.\n");
    }
}
*/
