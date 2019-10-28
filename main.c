#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main() {
   
    int sayi;
    while (1) {
        printf("Lutfen sayi giriniz: ");
        scanf("%d",&sayi);
        
        if (sayi > 1){
            collatz(sayi);
        } else {
            printf("Lütfen 1'den büyük bir değer giriniz!\n");
        }
    }
    return 0;
}

int collatz(int i){
    pid_t child_pid, wpid;
    int durum = 0;

    if ((child_pid = fork()) == 0){
        while (i != 1) {
            printf("%d\t", i);
            if (i % 2 == 0) {
                i /= 2;
            }
            else {
                i = 3 * i + 1;
            }
        }
        printf("1\n");
        exit(1);
    }
    while ((wpid = wait(&durum)) > 0){
        printf("Child bitti!\n");
    }
    return;
}