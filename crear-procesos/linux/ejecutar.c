#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int
main(int argc, char const* argv[], char *env[]) {
  pid_t proceso_hijo = fork();

  if (proceso_hijo == 0) {
    char *const proceso_argv[] = {
      "nano",
      "-l",
      "-v",
      "crear_proceso.c",
      "ejecutar.c",
      NULL };
      
    execve("/usr/bin/nano", proceso_argv, env);

    _exit(1);
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
