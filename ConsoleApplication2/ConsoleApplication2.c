#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>

typedef struct {
    char fio[80];
    char nomer[7];
    int otGIBDD;
} vladelec ;

typedef struct {
    char name[80];
    char capital[80];
    int population;
    int square;
} country;

typedef struct {
    char fio[80];
    struct {
        int day;
        int month;
        int year;
    };
    char gender;
} human;

//void main()
//{
//    system("chcp 1251");
//    vladelec *vl;
//    int size;
//    char c = 'R';
//    int num = 715;
//
//    puts("Введите кол-во владельцев");
//    scanf("%d",&size);
//
//    vl = (vladelec*)malloc(size * sizeof(vladelec));
//
//    for (int i = 0; i < size; i++) {
//        printf("Владелец №%d\n", i+1);
//
//        puts("Введите ФИО владельца");
//        getchar();
//        gets(vl[i].fio);
//
//        puts("Введите номер авто");
//        gets(vl[i].nomer);
//
//        puts("Введите отделение ГИБДД");
//        scanf("%d", &vl[i].otGIBDD);
//
//        puts("");
//    }
//
//    for (int i = 0; i < size; i++) {
//
//        if (vl[i].otGIBDD == num && vl[i].nomer[strlen(vl[i].nomer) - 1] == c) {
//            puts(vl[i].fio);
//        }
//    }
//      free(vl);
//}

//void main() {
//    system("chcp 1251");
//
//    country* countries;
//    int size, N, M;
//
//    puts("Введите кол-во стран");
//    scanf("%d", &size);
//
//    puts("Введите численность население");
//    scanf("%d", &N);
//
//    puts("Введите площадь");
//    scanf("%d", &M);
//
//    countries = (country*)malloc(size * sizeof(country));
//
//    for (int i = 0; i < size; i++) {
//        printf("Страна №%d\n", i+1);
//        
//        puts("Введите название страны");
//        getchar();
//        gets(countries[i].name);
//        
//        puts("Введите название столицы");
//        gets(countries[i].capital);
//        
//        puts("Введите численность население");
//        scanf("%d", &countries[i].population);
//
//        puts("Введите площадь");
//        scanf("%d", &countries[i].square);
//        
//        puts("");
//    }
//
//    for (int i = 0; i < size; i++) {
//        if (countries[i].population >= N && countries[i].square <= M) {
//            puts(countries[i].name);
//        }
//    }
//    free(countries);
//}


//void main() {
//    system("chcp 1251");
//
//    human* people;
//    int size, avg_age = 0, age ,year = 2022, month = 6, day = 5;
//
//    puts("Введите кол-во людей");
//    scanf("%d", &size);
//
//    people = (human*)malloc(size * sizeof(human));
//
//    for (int i = 0; i < size; i++) {
//
//        printf("Человек №%d\n", i + 1);
//        
//        puts("Введите ФИО");
//        getchar();
//        gets(people[i].fio);
//        
//        puts("Введите число рождения");
//        scanf("%d", &people[i].day);
//
//        puts("Введите месяц рождения");
//        scanf("%d", &people[i].month);
//
//        puts("Введите год рождения");
//        scanf("%d", &people[i].year);
//        
//        puts("Введите пол человека \"f\" или \"m\"");
//        getchar();
//        scanf("%c", &people[i].gender);
//        //people[i].gender = getchar();
//        //getch(people[i].gender);
//        
//
//        age = year - people[i].year;
//        if (people[i].month < month && people[i].day < day) {
//            age -= 1;
//        }
//
//        avg_age += age;
//
//        puts("");
//    }
//    avg_age /= size;
//
//    for (int i = 0; i < size; i++) {
//
//        age = year - people[i].year;
//        if (people[i].month < month && people[i].day < day) {
//            age -= 1;
//        }
//        if (age > avg_age && people[i].gender == 'm')
//            puts(people[i].fio);
//    }
//    free(people);
//}