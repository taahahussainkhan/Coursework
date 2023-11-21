#include <stdio.h>
#include <string.h>
#include <windows.h>

#define MAX_INPUT_SIZE 1024

void execute_command(char *command, int is_background) {
    STARTUPINFO si;
    PROCESS_INFORMATION pi;

    ZeroMemory(&si, sizeof(si));
    si.cb = sizeof(si);
    ZeroMemory(&pi, sizeof(pi));

    // Create process
    if (!CreateProcess(NULL, command, NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi)) {
        fprintf(stderr, "CreateProcess failed (%lu)\n", GetLastError());
        return;
    }

    // Wait for the process to finish unless it's a background process
    if (!is_background) {
        WaitForSingleObject(pi.hProcess, INFINITE);
    }

    // Close process and thread handles
    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);
}

int main() {
    char input[MAX_INPUT_SIZE];

    while (1) {
        printf("> ");
        fgets(input, sizeof(input), stdin);

        // Remove the newline character from the input
        size_t len = strlen(input);
        if (len > 0 && input[len - 1] == '\n') {
            input[len - 1] = '\0';
        }

        // Check if the command is a background process
        int is_background = 0;
        if (input[len - 1] == '&') {
            is_background = 1;
            input[len - 1] = '\0';
        }

        execute_command(input, is_background);
    }

    return 0;
}
