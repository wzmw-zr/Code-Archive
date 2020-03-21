/*************************************************************************
	> File Name: 3.ls.c
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年03月16日 星期一 16时59分10秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<dirent.h>
#include<string.h>
#include<unistd.h>
#include<sys/ioctl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<pwd.h>
#include<grp.h>
#include<time.h>
#include<math.h>

#define swap(a, b) {\
    __typeof(a) __temp = a;\
    a = b; b = __temp;\
}

typedef struct File_Info {
    char *File_Name;
    char *File_Path;
    ino_t ino;
    mode_t mode;
    nlink_t link;
    uid_t uid;
    gid_t gid;
    off_t size;
    char *username;
    char *groupname;
    struct timespec atime;
    struct timespec mtime;
    struct timespec ctime;
} File_Info;

typedef struct File_Set {
    File_Info **file;
    int size, cnt;
} File_Set;

File_Info *NewFileInfo (char *filename, char *whole_path, ino_t inode, mode_t mode, nlink_t nlink, uid_t uid, gid_t gid, char *uname, char *gname, struct timespec atime, struct timespec mtime, struct timespec ctime, off_t size) {
    File_Info *p = (File_Info *) calloc(sizeof(File_Info), 1);
    p->File_Name = filename;
    p->File_Path = whole_path;
    p->ino = inode;
    p->mode = mode;
    p->link = nlink;
    p->uid = uid;
    p->gid = gid;
    p->username = strdup(uname);
    p->groupname = strdup(gname);
    p->atime = atime;
    p->mtime = mtime;
    p->ctime = ctime;
    p->size = size;
    return p;
}

File_Set *NewFileSet(int size) {
    File_Set *p = (File_Set *) calloc(sizeof(File_Set), 1);
    p->file = (File_Info **) calloc(sizeof(File_Info *), size + 5);
    p->size = size;
    p->cnt = 0;
    return p;
}

void Upper(char *str) {
    for (int i = 0; str[i]; i++) {
        if (str[i] >= 'a' && str[i] <= 'z') str[i] -= 32;
    }
}

int cmp(File_Info *a, File_Info *b) {
    if (!strcmp(a->File_Name, ".")) return 1;
    if (!strcmp(b->File_Name, ".")) return 0;
    if (!strcmp(a->File_Name, "..")) return 1;
    if (!strcmp(b->File_Name, "..")) return 0;
    char *str_a, *str_b;
    if (a->File_Name[0] == '.' && a->File_Name[1] != '.') str_a = strdup(a->File_Name + 1);
    else if (a->File_Name[0] == '.' && a->File_Name[1] == '.') str_a = strdup(a->File_Name + 2);
    else str_a = strdup(a->File_Name);
    if (b->File_Name[0] == '.' && b->File_Name[1] != '.') str_b = strdup(b->File_Name + 1);
    else if (b->File_Name[0] == '.' && b->File_Name[1] == '.') str_b = strdup(b->File_Name + 2);
    else str_b = strdup(b->File_Name);
    Upper(str_a);
    Upper(str_b);
    if (strcmp(str_a, str_b) <= 0) {
        free(str_a);
        free(str_b);
        return 1;
    }
    free(str_a);
    free(str_b);
    return 0;
}

void q_sort(File_Set *fs, int l, int r) {
    if (l >= r) return ;
    int offset = rand() % (r - l + 1);
    swap(fs->file[l], fs->file[l + offset]);
    File_Info *p = fs->file[l];
    int x = l, y = r;
    while (x < y) {
        while (x < y && cmp(p, fs->file[y])) y--; 
        if (x < y) {
            swap(fs->file[x], fs->file[y]); 
            x++;
        }
        while (x < y && !cmp(p, fs->file[x])) x++;
        if (x < y) {
            swap(fs->file[x], fs->file[y]); 
            y--;
        }
    }
    fs->file[x] = p;
    q_sort(fs, l, x - 1);
    q_sort(fs, x + 1, r);
}


void AddFileToSet(File_Set *fs, char *filename, char *whole_path, ino_t inode, mode_t mode, nlink_t nlink, uid_t uid, gid_t gid, char *uname, char *gname, struct timespec atime, struct timespec mtime, struct timespec ctime,  off_t size) {
    if (fs->cnt > fs->size) return ;
    fs->file[fs->cnt++] = NewFileInfo(filename, whole_path, inode, mode, nlink, uid, gid, uname, gname, atime, mtime, ctime, size);
}

void clearFileInfo(File_Info *p) {
    if (!p) return ;
    free(p->File_Name);
    free(p->File_Path);
    free(p->username);
    free(p->groupname);
    free(p);
}

void clearFileSet(File_Set *p) {
    if (!p) return ;
    for (int i = 0; i <= p->cnt; i++) {
        if (!p->file[i]) continue;
        clearFileInfo(p->file[i]);
    }
    free(p->file);
    free(p);
}

// above are the definitions of data struture

// get the number of directory entry
int GetDirEntryNum(DIR *dirp) {
    int ret = 0;
    while (readdir(dirp)) ret++;
    return ret;
}

// get the absolute path of a file
char *GetWholePath(char *pathname, char *filename) {
    int path_len = strlen(pathname), filename_len = strlen(filename);
    char *whole_path = (char *) calloc(sizeof(char), path_len + filename_len + 5); 
    memcpy(whole_path, pathname, path_len);
    if (whole_path[path_len - 1] != '/') whole_path[path_len] = '/';
    strcat(whole_path, filename);
    return whole_path;
}

// get type of a file
char GetFileType(mode_t mode) {
    switch (mode & S_IFMT) {
        case S_IFBLK : return 'b';
        case S_IFCHR : return 'c';
        case S_IFDIR : return 'd';
        case S_IFIFO : return 'p';
        case S_IFLNK : return 'l';
        case S_IFREG : return '-';
        case S_IFSOCK : return 's';
    }
    return (char) 0;
}

char p[11];
// get previlege of a file
char *GetPrevilege(mode_t mode) {
    for (int i = 0; i < 9; i++) p[i] = '-';
    if (mode & S_IRUSR) p[0] = 'r';
    if (mode & S_IWUSR) p[1] = 'w';
    if (mode & S_IXUSR) p[2] = 'x';
    if ((mode & S_ISUID) && (mode & S_IXUSR)) p[2] = 's';
    if ((mode & S_ISUID) && !(mode & S_IXUSR)) p[2] = 'S';
    if (mode & S_IRGRP) p[3] = 'r';
    if (mode & S_IWGRP) p[4] = 'w';
    if (mode & S_IXGRP) p[5] = 'x';
    if ((mode & S_ISGID) && (mode & S_IXGRP)) p[5] = 's';
    if ((mode & S_ISGID) && !(mode & S_IXGRP)) p[5] = 'S';
    if (mode & S_IROTH) p[6] = 'r';
    if (mode & S_IWOTH) p[7] = 'w';
    if (mode & S_IXOTH) p[8] = 'x';
    if ((mode & S_ISVTX) && (mode & S_IXOTH)) p[8] = 't';
    if ((mode & S_ISVTX) && !(mode & S_IXOTH)) p[8] = 'T';
    return p;
}


// get max size of file
int GetMaxSize(File_Set *fs) {
    int ret = 0, size;
    for (int i = 0; i < fs->cnt; i++) {
        size = fs->file[i]->size;
        ret = ret > size ? ret : size;
    }
    return ret;
}

// get max number of link
int GetMaxLink(File_Set *fs) {
    int ret = 0, num;
    for (int i = 0; i < fs->cnt; i++) {
        num = fs->file[i]->link;
        ret = ret > num ? ret : num;
    }
    return ret;
}

// get digits of number
int digit(int num) {
    int ret = 0;
    do {
        num /= 10, ret++;
    } while (num);
    return ret;
}


void ColorPrint(mode_t mode, char *filename) {
    if (S_ISDIR(mode)) printf("\033[34m%s\033[0m", filename);
    else if (mode & S_IXUSR || mode & S_IXGRP || mode & S_IXOTH) 
    printf("\033[32m%s\033[0m", filename);
    else if (S_ISLNK(mode)) printf("\033[1;32m%s\033[0m", filename);
    else if (S_ISCHR(mode) || S_ISBLK(mode)) printf("\033[1;33m%s\033[0m", filename);
    else printf("%s", filename);
}

// printf attributes of a file
void detail_print(File_Info *p, int max_l, int max_s) {
    if (!p) return ;
    time_t time = (time_t) (p->mtime).tv_sec;
    char *chtime = ctime(&time);
    chtime[strlen(chtime) - 9] = '\0'; 
    printf("%c%s ", GetFileType(p->mode), GetPrevilege(p->mode));
    for (int i = 0; i < digit(max_l) - digit(p->link); i++) printf(" ");
    printf("%d %s %s ", p->link, p->username, p->groupname);
    for (int i = 0; i < digit(max_s) - digit(p->size); i++) printf(" ");
    printf("%d %s ", p->size, chtime);
    ColorPrint(p->mode, p->File_Name);
    S_ISDIR(p->mode) && printf("/");
    printf("\n");
}

int GetAbritaryFile(File_Set *fs) {
    int ret = 0;
    for (int i = 0; i < fs->cnt; i++) {
        fs->file[i]->File_Name[0] != '.' && ++ret;
    }
    return ret;
}

// judge if "part" columns can contain
int CanDo(char **name, int cnt, int part) {
    int ColumnCnt = (int) ceil((cnt * 1.0) / (part * 1.0));
    if (cnt / ColumnCnt < part - 1) return 1;
    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
    int ColumnSize = w.ws_col;
    int total_width = 0;
    for (int i = 0, j = 0; i < part && i * ColumnCnt + j < cnt; i++, j = 0) {
        int max_width = 0;
        for (; j < ColumnCnt && i * ColumnCnt + j < cnt; j++) {
            int width = strlen(name[i * ColumnCnt + j]);
            max_width = max_width > width ? max_width : width;
        }
        total_width += max_width + (i ? 2 : 0);
    }
    if (total_width <= ColumnSize) return part;
    return 0;
}

// get each column max width
void GetColumnWidth(char **name, int cnt, int part, int *max_w) {
    int ColumnCnt = (int) ceil((cnt * 1.0) / (part * 1.0));
    for (int i = 0, j = 0; i < part; i++, j = 0) {
        int max_width = 0;
        for (; j < ColumnCnt && i * ColumnCnt + j < cnt; j++) {
            int width = strlen(name[i * ColumnCnt + j]);
            max_width = max_width > width ? max_width : width;
        }
        max_w[i] = max_width;
    }
}

// just print simple name
void simple_print(File_Set *fs, char **name, int cnt, int offset) {
    int i, s, r;
    for (i = 2, s = 1, r = 1; i <= cnt && (r = CanDo(name, cnt, i)); i++) {
        r > 1 && (s = r);
    }
    int ColumnCnt = (int) ceil((cnt * 1.0) / (s * 1.0));
    int max_w[s + 5];
    GetColumnWidth(name, cnt, s, max_w);
    for (int j = 0; j < ColumnCnt; j++) {
        for (int k = 0; k < s && k * ColumnCnt + j < cnt; k++) {
            ColorPrint(fs->file[k * ColumnCnt + j + offset]->mode, name[k * ColumnCnt + j]);
            //printf("%s", name[k * ColumnCnt + j]);
            for (int x = 0; x < max_w[k] + 2 - strlen(name[k *ColumnCnt + j]); x++) printf(" ");
        } 
        printf("\n");
    }
}

void name_print(File_Set *fs) {
    int AbitaryFileCnt = GetAbritaryFile(fs);
    char *name[AbitaryFileCnt + 5];
    for (int i = 0, j = 0; i < fs->cnt; i++) {
        if (fs->file[i]->File_Name[0] != '.') name[j++] = fs->file[i]->File_Name; 
    }
    simple_print(fs, name, AbitaryFileCnt, 2);
}

void all_file_print(File_Set *fs) {
    char *name[fs->cnt + 5];
    for (int i = 0; i < fs->cnt; i++) name[i] = fs->file[i]->File_Name;
    simple_print(fs, name, fs->cnt, 0);
}
void attributes_print(File_Set *fs) {
    int max_s = GetMaxSize(fs), max_l = GetMaxLink(fs);
    for (int i = 0; i < fs->cnt; i++) {
        if (fs->file[i]->File_Name[0] != '.') detail_print(fs->file[i], max_l, max_s);
    }
}
void all_file_attributes_print(File_Set *fs) {
    int max_s = GetMaxSize(fs), max_l = GetMaxLink(fs);
    for (int i = 0; i < fs->cnt; i++) {
        detail_print(fs->file[i], max_l, max_s);
    }
}


// if the path is not the path of directory , then do this:
void HandleNDir(struct stat statbuf, int flag, char *filename) {
    uid_t uid = statbuf.st_uid;
    gid_t gid = statbuf.st_gid;
    struct passwd *pw = getpwuid(uid);
    struct group *gr= getgrgid(gid);
    time_t time = (statbuf.st_mtim).tv_sec;
    char *chtime = ctime(&time);
    chtime[strlen(chtime) - 9] = '\0'; 
    switch (flag) {
        case 0 :
        case 1 : printf("%s\n", filename); break;  
        case 2 :
        case 3 : {
            printf("%c%s %d %s %s %d %s ", GetFileType(statbuf.st_mode), GetPrevilege(statbuf.st_mode), statbuf.st_nlink, pw->pw_name, gr->gr_name, statbuf.st_size, chtime); 
            ColorPrint(statbuf.st_mode, filename);
            printf("\n");
            break;
        }
    }
}

void ls(char *pathname, int flag) {
    struct stat statbuf;
    char *truepath = (char *) calloc(sizeof(char), strlen(pathname) + 5);
    if (pathname[0] != '/') truepath[0] = '.', truepath[1] = '/';
    strcat(truepath, pathname);
    if (stat(truepath, &statbuf)) {
        perror("stat");
        return ;
    } 
    // if pathname is not the path or name of a directory 
    if (!S_ISDIR(statbuf.st_mode)) {
        HandleNDir(statbuf, flag, pathname);
        return ;
    }
    printf("%s:\n", pathname);
    DIR *dirp = opendir(pathname);
    // handle invalid pathname
    if (!dirp) {
        perror("opendir");
        return ;
    }
    // get directory entry number
    int dirent_num = GetDirEntryNum(dirp);
    // get dirp again
    dirp = opendir(pathname);
    // directory entry information
    struct dirent *dr_info;
    // get directory info
    File_Set *fs = NewFileSet(dirent_num);
    while ((dr_info = readdir(dirp))) {
        // get entrie file path
        char *whole_path = GetWholePath(pathname, dr_info->d_name);
        char *filename = strdup(dr_info->d_name);
        // define struct stat statbuf to get file information
        if (stat(whole_path, &statbuf)) {
            perror("stat");
            return ;
        }
        uid_t uid = statbuf.st_uid;
        gid_t gid = statbuf.st_gid;
        struct passwd *pw = getpwuid(uid);
        struct group *gr= getgrgid(gid);
        AddFileToSet(fs, filename, whole_path, statbuf.st_ino, statbuf.st_mode, statbuf.st_nlink, statbuf.st_uid, statbuf.st_gid, pw->pw_name, gr->gr_name, statbuf.st_atim, statbuf.st_mtim, statbuf.st_ctim, statbuf.st_size);
    }
    q_sort(fs, 0, fs->cnt - 1);
    switch (flag) {
        case 0 : name_print(fs); break;
        case 1 : all_file_print(fs); break;
        case 2 : attributes_print(fs); break;
        case 3 : all_file_attributes_print(fs); break;
        default : break;
    }
    closedir(dirp);
    clearFileSet(fs);
    return ;
}

int main(int argc, char **argv) {
    srand(time(0));
    int opt, flags = 0, argcnt = 0, temp = argc;
    char **argv_temp = argv;
    while ((opt = getopt(argc, argv, "al")) != -1) {
        switch (opt) {
            case 'a': flags |= 1;  break; 
            case 'l': flags |= 2;  break;
            default : return 0;
        }
    }
    if (argc == 1) ls(".", flags);
    else {
        while (--temp) {
            if ((*++argv)[0] == '-') argcnt++;
        }
        if (argc - argcnt == 1) ls(".", flags);
        else while (--argc) {
            // ignore options
            if ((*++argv_temp)[0] != '-') {
                ls(*argv_temp, flags);
                argc > 1 && printf("\n");
            }
        } 
    }
    return 0;
}
