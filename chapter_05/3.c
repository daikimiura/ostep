//
// Created by Daiki Miura on 2020/09/08.
//

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
  int rc = fork();
  if (rc < 0) {
    fprintf(stderr, "fork failed\n");
    exit(1);
  } else if (rc == 0) { // child process
    printf("hello\n");
  } else { // parent process
    sleep(1);
    printf("goodbye\n");

  }

  return 0;
}
