#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

void*
funcion_hilo(void *arg) {
  
  int valor = *((int*) arg);

  free(arg);
  fprintf(stdout, "Hola Mundo del hilo %d\n", valor);

  sleep(valor);

  int *retValue = malloc(sizeof(int));

  *retValue = valor * 100;
  return retValue;
}

int
main(int argc, char *argv[]) {

  int nHilos = 0;           
  int i;
  pthread_t *tablaDeHilos;  // Información de los hilos

  if (argc != 2) {
    fprintf(stderr, "Uso: %s nHilos\n", argv[0]);
    exit(1);
  }

  nHilos = atoi(argv[1]);

  if (nHilos == 0) {
    fprintf(stderr, "Uso: %s nHilos\n", argv[0]);
    exit(1);
  }

  // Solicito memoria dinámica para la tabla
  tablaDeHilos = (pthread_t *) malloc(sizeof(pthread_t) * nHilos);
  
  for (i = 0; i < nHilos; i++) {

    int error;
    int *value = malloc(sizeof(int));
    *value = i;
    if ((error = pthread_create((tablaDeHilos + i), 
				NULL, 
				funcion_hilo,
				value)) != 0){
	  fprintf(stderr, "Error: %d %d\n", error, errno);
	  _exit(EXIT_FAILURE);
	}
  }
  
  for (i = 0; i < nHilos; i++) {

    int* valorRetorno;
    pthread_join(*(tablaDeHilos +i),
		 (void **) valorRetorno);
    fprintf(stdout, "Valor de retorno: %d del hilo: %ld\n",
	    *valorRetorno, *(tablaDeHilos +i));
    free(valorRetorno);
  }

  exit(1);
}
		 
  
  
