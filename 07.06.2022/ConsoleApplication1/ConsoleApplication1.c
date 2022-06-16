#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

typedef struct {
	char fio[80];
	char doljnost[80];
	int zp;
}sotrudnic ;

//void main()
//{
//	system("chcp 1251");
//	int size = 1;
//	sotrudnic* st;
//	FILE* fp;
//
//	fp = fopen("G:\\Project\\C\\C_works\\07.06.2022\\ConsoleApplication1\\file.txt", "rb");
//
//	if (fp == NULL) {
//		puts("File not found");
//		return;
//	}
//
//	st = (sotrudnic*)malloc(size * sizeof(sotrudnic));
//	char c;
//
//	while (!feof(fp)) {
//
//		fscanf(fp, "%c", &c);
//		if (c == '\n')
//			size++;		
//	}
//	st = (sotrudnic*)realloc(st, size * sizeof(sotrudnic));
//	fread(st, sizeof(sotrudnic), size, fp);
//
//
//	//printf("%d", size);
//}


void main() {
	system("chcp 1251");
	FILE* fp;
	int n, m;
	int* arr;

	fp = fopen("G:\\Project\\C\\C_works\\07.06.2022\\ConsoleApplication1\\file2.data", "rb");

	if (fp == NULL) {
		puts("File not found");
		return;
	}

	fscanf(fp, "%d", &n);
	fscanf(fp, "%d", &m);

	arr = (int*)malloc(n * m * sizeof(int));

	fread(arr, sizeof(int), n*m, fp);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			printf("%4d  ", arr[i * m + j]);
		}
		printf("\n");
	}

	int s,s1,flag;

	for (int i = 0; i < n; i++) {
		s = 0;
		flag = 0;
		for (int k = arr[i * m + 0]; k > 0; k /= 10)
			s++;

		for (int j = 0; j < m; j++) {
			s1 = 0;
			for (int k = arr[i * m  + j]; k > 0; k /= 10)
				s1++;
			if (s != s1)
				break;
			flag++;
		}

		if (flag == n - 1) {
			for (int j = 0; j < m; j++) {
				free(arr[i * m + j]);
			}
		}
	}
	printf("\n\n\n");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			printf("%4d  ", arr[i * m + j]);
		}
		printf("\n");
	}
		
}
