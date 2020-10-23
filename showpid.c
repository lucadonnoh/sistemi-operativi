#include <stdio.h>
#include <unistd.h>
int main(int argc, char const *argv[])
{
    char *newargv[] = {"argv[0] di showpid", NULL};
    printf("io sono testexecve %d\n", getpid());
    execve("./showpid", newargv, NULL);
    return 0;
}
