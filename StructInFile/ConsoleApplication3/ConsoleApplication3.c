#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct {
    char last_name[50];
    char city[15];
    char nomer[10];
}buyer;

int main() {
    system("chcp 1251");
    FILE* fp = fopen("f1.txt", "w");
    buyer* st;
    int size;

    puts("Введите кол-во покупателей");
    scanf("%d", &size);
    getchar();

    st = (buyer*)malloc(size * sizeof(buyer));

    for (int i = 0; i < size; i++) {
        printf("%d-й покупатель\n", i + 1);
        puts("Введите фамилия покупателя");
        gets(st[i].last_name);
        //getchar();

        puts("Введите город покупателя");
        gets(st[i].city);

        //getchar();
        puts("Введите номер счета");
        gets(st[i].nomer);

        puts("");
    }

    for (int i = 0; i < size; i++) {
        if (strcmp(st[i].city, "Новосибирск") == 0 && st[i].nomer[strlen(st[i].nomer) - 1] == '0' && st[i].nomer[strlen(st[i].nomer) - 2] == '0') {
            fprintf(fp, "%s\t", st[i].last_name);
            fprintf(fp, "%s\t", st[i].city);
            fprintf(fp, "%s\n", st[i].nomer);
        }
    }
    fclose(fp);
    free(st);
}
