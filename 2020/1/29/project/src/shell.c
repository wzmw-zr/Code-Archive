#include "shell.h"
/**
 * shell的入口
 */
void prefix() {
    char cwd[80];
    getcwd(cwd, sizeof(cwd));
    printf("%s$", cwd);
}

int execute(char* buffer) {
    if (buffer[0] == 'c' && buffer[1] == 'd') {
        char dir[80] = {0};
        // getcwd(dir, sizeof(dir));
        // int len = strlen(dir);
        // dir[len] = '/';
        for (int i = 3; i <= strlen(buffer) - 1; i++) dir[i - 3] = buffer[i];
        int len = strlen(dir);
        dir[len] = '/';
        if (chdir(dir)) printf("%s:No such file or directory\n", dir);
        log_push(&Log, buffer);
        return 1;
    } 
    
    else if (buffer[0] == 'e' && buffer[1] == 'x' && buffer[2] == 'i' && buffer[3] == 't') {
        log_push(&Log, buffer);
        return 0;
    } 
    
    else if (buffer[0] == '!' && buffer[1] == '#') {
        node* head = Log.head;
        while (head) {
            printf("%s\n", head->cmd);
            head = head->next;
        }
        return 1;
    } 
    
    else if (buffer[0] == '!' && buffer[1] != '#') {
        char prefix[strlen(buffer)];
        char *command;
        memset(prefix, 0, sizeof(prefix));
        for (int i = 1; i <= strlen(buffer) - 1; i++) prefix[i - 1] = buffer[i];
        command = log_search(&Log, prefix);
        if (command) {
            execute(command);
            return 1;
        }
        printf("No Match\n");
        return 1;
    } 
    
    else if (buffer[0] == 'l' && buffer[1] == 's') {
        system(buffer);
        log_push(&Log, buffer);
        return 1;
    } 
    
    else if (buffer[0] == 'a' && buffer[1] == 'r' && buffer[2] == 'g' && buffer[3] == 's'){
        int pid = fork();
        if (!pid) {
            char cwd[80] = {0};
            getcwd(cwd, sizeof(cwd));
            strcat(cwd, "arg");
            char* content[strlen(buffer)];
            char temp[strlen(buffer)];
            memset(content, 0, sizeof(content));
            memset(temp, 0, sizeof(temp));
            strcpy(temp, buffer);
            char *token = strtok(temp, " ");
            int index = 0;
            while (token) {
                char* tmp = (char *) malloc(sizeof(token) + 5);
                strcpy(tmp, token);
                content[index++] = tmp;
                token = strtok(NULL, " ");
            }
            execv(cwd, content);
            log_push(&Log, buffer);
            printf("6\n");
            return 1;
        } else {
            int status;
            wait(&status);
        }
        printf("6\n");
        return 1;
    } else {
        printf("%s: no such command\n", buffer);
        log_push(&Log, buffer);
        return 1;
    }
}
