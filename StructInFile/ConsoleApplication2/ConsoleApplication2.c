#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct {
    char fio[50];
    char gender;
    struct {
        int day;
        int month;
        int year;
    };
    char clas[4];
}student;

int main()  {
    system("chcp 1251");
    FILE* fp = fopen("f1.txt", "w");
    student* st;
    int size, day = 14, month = 6, year = 2022, age;

    puts("Введите кол-во учеников");
    scanf("%d", &size);
    getchar();

    st = (student*)malloc(size * sizeof(student));

    for (int i = 0; i < size; i++) {
        printf("%d-й ученик\n", i+1);
        puts("Введите ФИО ученика");
        
        gets(st[i].fio);
        //getchar();
        puts("Введите пол ученика \"m\" или \"f\" ");
        scanf("%c",&st[i].gender);

        //getchar();
        puts("Введите число рождения ученика");
        scanf("%d", &st[i].day);

        puts("Введите месяц рождения ученика");
        scanf("%d", &st[i].month);

        puts("Введите год рождения ученика");
        scanf("%d", &st[i].year);
        getchar();

        puts("Введите класс ученика");
        gets(st[i].clas);

        puts("");
    }

    for (int i = 0; i < size; i++) {
        printf("%s\t", st[i].fio);
        printf("%c\t", st[i].gender);
        printf("%d\t", st[i].day);
        printf("%d\t", st[i].month);
        printf("%d\t", st[i].year);
        printf("%s\n", st[i].clas);
        age = year - st[i].year;
        if (st[i].month < month || (st[i].month == month && st[i].day < day)) {
            age--;
        }
        if (age == 13 && st[i].clas[strlen(st[i].clas) - 1] == 'A') {
            //fwrite(st+i,sizeof(student), 1, fp);
            fprintf(fp, "%s ", st[i].fio);
            fprintf(fp, "%c ", st[i].gender);
            fprintf(fp, "%d ", st[i].day);
            fprintf(fp, "%d ", st[i].month);
            fprintf(fp, "%d ", st[i].year);
            fprintf(fp, "%s ", st[i].clas);
        }
    }
    fclose(fp);
    free(st);
}

    
