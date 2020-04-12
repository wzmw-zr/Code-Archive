#include "../head/common.h"
#include "../head/shell.h"

void PrintLinePre() {
    char *user = strdup(getlogin());
    char *hostname = (char *) calloc(sizeof(char), 128);
    char *cwd = (char *) calloc(sizeof(char), 1024);
    if (gethostname(hostname, 128) == -1) {
        perror("gethostname");
        exit(1);
    }
    if ((cwd = getcwd(cwd, 1024)) == NULL) {
        perror("getwd");
        exit(1);
    }
    printf("[%s@%s %s]$", user, hostname, cwd);
    fflush(stdout);
    free(user);
    free(hostname);
    free(cwd);
}

/*char **ParseCommand(char *command) {
    char **ret = (char **) calloc(sizeof(char *), strlen(command));
    int ind = 0;
    ret[ind++] = strtok(command, " ");
    while ((ret[ind] = strtok(NULL, " "))) ind++;
    return ret;
}
*/

char **Split_Command(char *command, char *c) {
    char **ret = (char **) calloc(sizeof(char *), strlen(command));
    int ind = 0;
    ret[ind++] = strtok(command, c);
    while ((ret[ind] = strtok(NULL, c))) ind++;
    return ret;
}

void do_input(char *command)  {
    char **ret = Split_Command(command, "<");
    int pipefd[2];
    pipe(pipefd);
    pid_t pid;
    if ((pid = fork()) < 0) {
        perror("fork");
        return;
    } else if (pid == 0) {
        close(pipefd[0]); 
        dup2(pipefd[1], 1);
        execlp("cat", "cat", ret[1], NULL);
    } else {
        close(pipefd[1]);
        dup2(pipefd[0], 0);
        execlp(ret[0], ret[0], NULL);
        return ;
    }
    wait(NULL);
}

void do_output(char *command) {

}

void do_pipe(char *command) {
    char **ret = Split_Command(command, "|");
}

void HandleCommand(char *command) {
    if (strchr(command, '<')) {
        do_input(command);
        return;
    }
    if (strchr(command, '>')) {
        do_output(command);
        return;
    }
    if (strchr(command, '|')) {
        do_pipe(command);
        return;
    }
    char **result = Split_Command(command, " ");
    int para_num = 0;
    for (int i = 1; result[i]; i++) para_num++;
    if (!strcmp(result[0], "cd")) {
        // cd
        if (para_num > 1) {
            fprintf(stderr, "cd : too many parameters!\n");
            return ;
        }
        if (chdir(result[1]) == -1) {
            perror("chdir");
            return ;
        }
        return ;
    }
    if (!strcmp(result[0], "pwd")) {
        // pwd
        char *cwd = (char *) calloc(sizeof(char), 1024);
        if ((cwd = getcwd(cwd, 1024)) == NULL) {
            perror("getwd");
            return ;
        }
        printf("%s\n", cwd);
        free(cwd);
        return ;
    }
    execvp(result[0], result);
    free(result);
}
