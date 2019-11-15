#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <wait.h>
#include <fcntl.h>

void sort(char *x, int size)
{
    char ans[size];
    int j;
    char tmp;
    for (int i = 0; i < size; i++) {
        ans[i] = x[i];
        if (i > 0) {
             j = i - 1;
             while ((ans[j + 1] < ans[j]) && (j >= 0)) {
                 tmp = ans[j + 1];
                 ans[j + 1] = ans[j];
                 ans[j] = tmp;
                 j--;
              }
        }
    }
    for (int i = 0; i < size; i++) {
        x[i] = ans[i];
    }
}

void forking(int i, char *x, char *res, int* piper)
{
    pid_t proc = fork();
    if (proc < 0) {
        printf("Error fork\n");
        exit(1);
    }
    if (proc == 0) {
        int wt;
        wait(&wt);
        read(piper[i], x, sizeof(x));
        exit(0);
    }
    if (proc > 0) {
        sort(x, 10);
        for (int j = 0; j < 10; j++) {
            res[i*10 + j] = x[j];
        }
    }
}

int main(int argc, char* argv[])
{
    char x[10], y[10], res[20], c;
    int piper[3];
    piper[0] = open(argv[1], O_RDONLY);
    piper[1] = open(argv[2], O_RDONLY);
    piper[2] = open(argv[3], O_WRONLY);
    if (pipe(piper)) {
        printf("Error: pipe\n");
        exit(1);
    }
    pid_t proc = fork();
    if (proc < 0) {
        printf("Error fork\n");
        exit(1);
    }
    if (proc == 0) {
        forking(0, x, res, piper);
        forking(1, x, res, piper);
        exit(0);
    }
    if (proc > 0) {
        int wt;
        wait(&wt);
        sort(res, 20);
        write(piper[2], res, sizeof(res));
    }
}
