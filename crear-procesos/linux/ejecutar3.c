#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int
main(int argc, char const* argv[], char *env[]) {
  pid_t proceso_hijo = fork();
  
  if (proceso_hijo == 0) {
      
    execlp("nano", "nano", "-l", "-v", "crear_proceso.c", "ejecutar.c", NULL);

    _exit(1);
  }
  else {
   int status;
   waitpid(proceso_hijo, &status, 0);
  }

  _exit(0);
}
