/*************************************************************************
	> File Name: 1.server.c
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年06月11日 星期四 20时18分32秒
 ************************************************************************/

#include"../common/udp_server.h"
#include"../common/head.h"
#include "../common/heartbeat.h"
#include "../common/sub_reactor.h"
#include"../common/udp_epoll.h"
#include "../common/thread_pool.h"
#include"../game.h"

char *conf = "./server.conf";
struct User *rteam; //存放两个队的用户端
struct User *bteam;
int data_port;
int port = 0;
//struct Map court;

int repollfd, bepollfd;

int main(int argc, char **argv){
    int opt, listener, epoll_fd;
    pthread_t draw_t, red_t, blue_t, heart_t;
    while((opt = getopt(argc, argv, "p;")) != -1){
        switch(opt){
            case 'p':
                port = atoi(optarg);
                break;
            default :
                fprintf(stderr , "Usage: %s [-p port]\n", argv[0]);
                exit(1);
        }
    }
    argc -= (optind - 1);
    argv += (optind - 1);

    if(argc > 1){
        fprintf(stderr , "Usage: %s [-p port]\n", argv[0]);
        exit(1);
    }
    

    if(!port) port = atoi(get_value(conf, "PORT"));
    data_port = atoi(get_value(conf, "DATAPORT"));
    court.width = atoi(get_value(conf, "COLS"));
    court.height = atoi(get_value(conf, "LINES"));
    court.start.x = 1;
    court.start.y = 1;

    rteam = (struct User *)calloc(MAX, sizeof(struct User));
    bteam = (struct User *)calloc(MAX, sizeof(struct User));
    
    if((listener = socket_create_udp(port)) < 0){
        perror("socket_create_udp");
        exit(1);
    }

    DBG(GREEN"INFO"NONE" : Server start on Prt %d\n",port);

    epoll_fd = epoll_create(MAX * 2);
    repollfd = epoll_create(MAX);
    bepollfd = epoll_create(MAX);

    if(epoll_fd < 0 || repollfd < 0 || bepollfd < 0){
           perror("epoll_create");
           exit(1);
    }
    struct task_queue redQueue;
    struct task_queue blueQueue;

    task_queue_init(&redQueue, MAX, repollfd);
    task_queue_init(&blueQueue, MAX, bepollfd);

    pthread_create(&red_t, NULL, sub_reactor, (void *)&redQueue);
    pthread_create(&blue_t, NULL, sub_reactor, (void *)&blueQueue);
    pthread_create(&heart_t, NULL, heart_beat, NULL);


    struct epoll_event ev, events[MAX * 2];

    ev.events = EPOLLIN;
    ev.data.fd = listener;
   
    epoll_ctl(epoll_fd, EPOLL_CTL_ADD, listener, &ev);
    struct sockaddr_in client;
    socklen_t len = sizeof(client);
    
    while(1){
    
        DBG(YELLOW"Main Thread"NONE" : Before epoll_wait\n");
        int nfds = epoll_wait(epoll_fd, events, MAX * 2, -1);
        DBG(YELLOW"Main Thread"NONE" : After epoll_wait\n");

        for(int i = 0; i < nfds; i++){
            char buff[512] = {0};
            struct User user;
            DBG(YELLOW"EPOLL"NONE" : Doing with %dth fd\n", i);
            if(events[i].data.fd == listener){
               int new_fd =  udp_accept(epoll_fd, listener, &user);
                
                if (new_fd > 0) {
                    DBG(YELLOW "Main Thread" NONE
                               " : Add %s to %s sub_reactor.\n",
                        user.name, (user.team ? "BLUE" : "RED"));
                    add_to_sub_reactor(&user);
                }
            }else {
                recv(events[i].data.fd, buff, sizeof(buff), 0);
                printf(PINK "RECV" NONE " : %s\n", buff);
            }
        }
    }

    return 0;
}

