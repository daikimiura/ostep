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
  int fd = open("./foo.txt", O_CREAT|O_WRONLY|O_TRUNC, S_IRWXU);
  char *s_main = "main process\n";
  write(fd, s_main, strlen(s_main));

  int rc = fork();
  if (rc < 0) {
    fprintf(stderr, "fork failed\n");
    exit(1);
  } else if (rc == 0) { // child process
    char *s_child = "child process\n";
    write(fd, s_child, strlen(s_child));
  } else { // parent process
    char *s_parent = "parent process\n";
    write(fd, s_parent, strlen(s_parent));
  }

  return 0;
}
