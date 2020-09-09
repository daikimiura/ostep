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
  int pipefd[2];
  if(pipe(pipefd) < 0) {
    perror("pipe");
    exit(-1);
  }

  char *s = "hello via pipe";

  int rc1 = fork();
  if (rc1 < 0) {
    fprintf(stderr, "fork failed\n");
    exit(1);
  } else if (rc1 == 0) { // child process
    write(pipefd[1], s, strlen(s));
    close(pipefd[1]);
  } else { // parent process
    int rc2 = fork();
    if (rc2 < 0) {
      fprintf(stderr, "fork failed\n");
      exit(1);
    } else if (rc2 == 0) { // child process
      char buf[128];
      read(pipefd[0], buf, strlen(s));
      printf("buf = [%s]\n", buf);
      close(pipefd[0]);
    } else { // parent process
    }
  }

  return 0;
}
