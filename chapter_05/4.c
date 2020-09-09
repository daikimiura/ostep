//
// Created by Daiki Miura on 2020/09/08.
//

#include <stdio.h>
#include <stdlib.h>
#define _GNU_SOURCE
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
  int rc = fork();
  if (rc < 0) {
    fprintf(stderr, "fork failed\n");
    exit(1);
  } else if (rc == 0) { // child process
//    execl("/bin/ls", "ls", "/", NULL); // ok
//    execl("ls", "ls", "/", NULL); // ng

//    char *env[] = {"FOO=asdfasdf", NULL};
//    execle("/bin/sh", "sh", "-c", "echo $FOO", NULL, env);

//    execlp("ls",  "ls", "/", NULL); // ok

//    char *args[] = {"ls", "/", NULL};
//    execv("/bin/ls", args); // ok
//    execv("ls", args); // ng

//    execvp("ls", args);

//    The execvpe() function is a GNU extension. Mac OSX does not support it.
//    char *env[] = {"FOO=asdfasdf", NULL};
//    char *args[] = {"sh", "-c", "echo $FOO", NULL};
//    execvpe("/bin/sh", args, env);
    printf("Error: execve(%d) %s\n", errno, strerror(errno));
  } else { // parent process
    wait(NULL);
    printf("finished!\n");
  }

  return 0;
}
