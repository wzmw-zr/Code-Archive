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
        char dir[strlen(buffer)];
        memset(dir, 0, sizeof(dir));
        for (int i = 2; i <= strlen(buffer) - 1; i++) dir[i - 2] = buffer[i];
        if (chdir(dir)) printf("%s:No such file or directory\n", dir);
        log_push(&Log, buffer);
        printf("1\n");
        return 1;
    } 
    
    else if (buffer[0] == 'e' && buffer[1] == 'x' && buffer[2] == 'i' && buffer[3] == 't') {
        log_push(&Log, buffer);
        printf("2\n");
        return 0;
    } 
    
    else if (buffer[0] == '!' && buffer[1] == '#') {
        node* head = Log.head;
        printf("%s\n", head->cmd);
        while (head) {
            printf("%s\n", head->cmd);
            head = head->next;
        }
        printf("3\n");
        return 1;
    } 
    
    else if (buffer[0] == '!' && buffer[1] != '#') {
        char prefix[strlen(buffer)];
        memset(prefix, 0, sizeof(prefix));
        for (int i = 1; i <= strlen(prefix) - 1; i++) prefix[i - 1] = buffer[i];
        if (log_search(&Log, prefix)) execute(prefix);
        log_push(&Log, prefix);
        printf("4\n");
        return "No Match\n";
    } 
    
    else if (buffer[0] == 'l' && buffer[1] == 's') {
        system(buffer);
        log_push(&Log, buffer);
        printf("%s\n", (Log.head)->cmd);
        //printf("%d\n", (Log.head == NULL));
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
