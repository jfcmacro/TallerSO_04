#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

void*
funcion_hilo(void *arg) {
  
  int valor = *((int*) arg);

  fprintf(stdout, "Hola Mundo del hilo %d\n", valor);

  sleep(valor);

  int* retValue = malloc(sizeof(int));

  *retValue = valor * 10;

  return retValue;
}

void
main(int argc, char *argv[]) {

  int valor = 10;

  pthread_t threadId;
  int error;
  
  if ((error = pthread_create(&threadId, 
			      NULL, 
			      funcion_hilo,
			      &valor)) != 0) {
    fprintf(stderr, "Error: %d errno: %d\n", error, errno);
    _exit(EXIT_FAILURE);
  }
  

  int* retValue;
  pthread_join(threadId,
	       (void **) &retValue);
  fprintf(stdout, "Valor de retorno: %d del hilo: %ld\n",
	  *retValue, threadId);
  free(retValue);
  
  _exit(EXIT_SUCCESS);
}
		 
  
  
