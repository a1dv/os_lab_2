#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <wait.h>
#include <fcntl.h>

/*void sort(char *x)
{
    char ans[10];
    int j;
    char tmp;
    for (int i = 0; i <= 9; i++) {
        ans[i] = x[i];
        if (i > 0) {
             j = i - 1;
             while ((ans[j+1] < ans[j]) && (j >= 0)) {
                 tmp = ans[j+1];
                 ans[j+1] = ans[j];
                 ans[j] = tmp;
                 j--;
              }
        }
    }
    for (int i = 0; i <= 9; i++) {
        x[i] = ans[i];
    }
}*/

int main(int argc, char* argv[])
{
/*    char x[10];
    int i = 0;
    x[0] = 'f';
    x[1] = 'e';
    x[2] = 'p';
    x[3] = 'q';
    x[4] = 'a';
    x[5] = 'c';
    x[6] = 'b';
    x[7] = 'u';
    x[8] = 'z';
    x[9] = 'y';
    sort(x);*/
    int ept = open(argv[1], O_WRONLY);
    write(ept, "a", 1);

}
