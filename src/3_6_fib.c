/*************************
 * Author:    TKONIY
 * Date:      2020/10/11
 * Platform:  WSL-ubuntu18.04
 * Compiler:  gcc7.5.0
 ************************/

#include <sched.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <wait.h>

void fib(int n) {
  long dp[2] = {0, 1};
  if (n == 0) return;
  printf("%ld ", dp[0]);
  if (n == 1) return;
  printf("%ld ", dp[1]);

  for (int i = 2, p = 0; i < n; ++i, p = (p + 1) % 2) {
    dp[p] = dp[0] + dp[1];
    printf("%ld ", dp[p]);
  }
}

int main(int argc, char** argv) {
  int n;
  if (argc == 1 || (n = atoi(argv[1])) < 0) {
    fprintf(stderr, "please input an non-negitive number.\n");
    return -1;
  }
  pid_t pid = fork();
  if (pid < 0) {
    fprintf(stderr, "Fork Faild");
    exit(-1);
  } else if (pid == 0) {
    fib(n);
  } else {
    wait(NULL);
  }
  return 0;
}
