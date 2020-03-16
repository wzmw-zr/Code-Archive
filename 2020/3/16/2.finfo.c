/*************************************************************************
	> File Name: 2.finfo.c
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年03月16日 星期一 16时30分00秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<dirent.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<pwd.h>
#include<grp.h>

int main(int argc, char **argv) {
    char path[10] = "1.ls.c";
    struct stat f_info;
    if (stat(path, &f_info)) {
        perror("stat");
        return 0;
    }
    printf("get file suceesfully!\n");
    uid_t uid = f_info.st_uid;
    gid_t gid = f_info.st_gid;
    ino_t inode_n = f_info.st_ino;
    printf("uid = %lld, gid = %lld, inode = %lld\n", uid, gid, inode_n);
    struct passwd *u_info = getpwuid(uid);
    printf("username = %s\n", u_info->pw_name);
    struct group *g_info = getgrgid(gid);
    printf("groupname = %s\n", g_info->gr_name);
    return 0;
}
