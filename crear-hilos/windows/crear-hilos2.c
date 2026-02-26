#include <windows.h>
#include <stdio.h>
#include <tchar.h>
#include <stdlib.h>

DWORD WINAPI
funcion_hilo(LPVOID lpParameter) {

  int valor = *((int*) lpParameter);
  DWORD dwResultado = valor + 1;

  fprintf(stdout, "Hola mundo desde el hilo: %d\r\n", valor);

  Sleep(valor * 1000); // Esta expresion esta en milisegundos

  dwResultado *= 100;

  return dwResultado;
}

void
_tmain(int argc, TCHAR *argv[]) {
    int nHilos;
    DWORD dwResultado;
    int i;
    DWORD *tablaHilos;

    if (argc != 2) {
        fprintf(stderr, "Uso: %s nHilos\r\n", argv[0]);
        ExitProcess(EXIT_FAILURE);
    }

    nHilos = atoi(argv[1]);

    if (nHilos == 0) {
        fprintf(stderr, "Uso: %s nHilos\r\n", argv[0]);
        ExitProcess(EXIT_FAILURE);
    }

    tablaHilos = (LPDWORD) malloc(sizeof(LPDWORD) * nHilos);

    for (i = 0; i < nHilos; i++) {

        CreateThread(NULL,
                     0,
                     funcion_hilo,
                     (LPVOID) &i,
                     0,
                     (tablaHilos + i));
    }

    for (i = 0; i < nHilos; i++) {
        HANDLE hThread;

        hThread = OpenThread(THREAD_ALL_ACCESS,
                             FALSE,
                             *(tablaHilos + i));

        WaitForSingleObject(hThread, INFINITE);

        GetExitCodeThread(hThread, &dwResultado);

        fprintf(stdout, "El hilo: %d terminó: %d\r\n",
                *(tablaHilos + i),
                dwResultado);
    }

    ExitProcess(EXIT_SUCCESS);
}
