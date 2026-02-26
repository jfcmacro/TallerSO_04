#include <stdio.h>
#include <tchar.h>
#include <windows.h>

void
_tmain(int argc, TCHAR *argv[]) {
  STARTUPINFOA si;
  PROCESS_INFORMATION pi;

  ZeroMemory(&si, sizeof(si));
  si.cb = sizeof(si);
  ZeroMemory(&pi, sizeof(pi));

  if (!CreateProcessA(NULL,
		      TEXT("nano -l -v ejecutar.c ejecutar2.c"),
		      NULL,
		      NULL,
		      FALSE,
		      0,
		      NULL,
		      NULL,
		      &si,
		      &pi)) {

    fprintf(stderr,
	    TEXT("Creación de proceso fallo (%d) \n"),
	    GetLastError());

    ExitProcess(EXIT_FAILURE);
  }

  WaitForSingleObject(pi.hProcess, INFINITE);

  DWORD exitCode;

  if (GetExitCodeProcess(pi.hProcess, &exitCode)) {

    fprintf(stdout, "Proceso salio con estado: %d\n", exitCode);
  }
  else {

    fprintf(stderr, "No se pudo obtener un codigo de retorno: %d\n",
	    GetLastError());
  }

  CloseHandle(pi.hProcess);
  CloseHandle(pi.hThread);

  ExitProcess(EXIT_SUCCESS);
}
