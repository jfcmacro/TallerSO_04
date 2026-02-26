#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int
main() {
  pid_t proceso_hijo = fork();

  if (proceso_hijo == 0) {
    // Hijo
    fprintf(stdout, "pid: %d ppid: %d\n", getpid(), getppid());
    sleep(5);
    _exit(10);
  }
  else {
    int status;
    waitpid(proceso_hijo, &status, 0);
    fprintf(stdout, "pid: %d proceso hijo: %d\n",
	    getpid(),
	    proceso_hijo);
    fprintf(stdout, "llamo a _exit=%d status=%d\n",
	    WIFEXITED(status),
	    WEXITSTATUS(status));
  }

  _exit(0);
}
