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
    int wc = waitpid(-1, NULL, 0);
    printf("child: %d (wait: %d)\n", getpid(), wc);
  } else { // parent process
    int wp = waitpid(-1, NULL, 0);
    printf("parent: %d (wait: %d)\n", getpid(), wp);
    printf("finished!\n");
  }

  return 0;
}