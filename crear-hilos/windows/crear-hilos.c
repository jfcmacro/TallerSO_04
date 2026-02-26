#include <windows.h>
#include <stdio.h>
#include <tchar.h>
#include <stdlib.h>

DWORD WINAPI
funcion_hilo(LPVOID lpParameter) {

  int valor = *((int*) lpParameter);
  DWORD dwResultado = valor * 100;

  fprintf(stdout, "Valor recibido: %d\r\n", valor);

  return dwResultado;
}

void
_tmain(int argc, TCHAR *argv[]) {

  int i = 10;
  DWORD threadId;
  HANDLE hThread;

  hThread = CreateThread(NULL,
			 0,
			 funcion_hilo,
			 (LPVOID) &i,
			 0,
			 &threadId);

  if (hThread == NULL) {
    fprintf(stderr, "No se pudo crear el hilo: %d\r\n", GetLastError());
    ExitProcess(EXIT_FAILURE);
  }

  WaitForSingleObject(hThread, INFINITE);
  DWORD dwReturnValue;
  GetExitCodeThread(hThread, &dwReturnValue);

  fprintf(stdout, "Valor retornado %d\r\n", dwReturnValue);

  ExitProcess(EXIT_SUCCESS);
}
