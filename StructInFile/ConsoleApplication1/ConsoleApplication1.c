#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct {
	char fio[50];
	char doljnost[50];
	int zp;
} human;

int main()
{
    system("chcp 1251");

	int size = 0, avg_zp = 0;
	FILE* fp = fopen("f1.dat", "r");
	human* hm =	(human*)malloc(size * sizeof(human));
    
	if (fp == NULL) {
		printf("File not found");
		return 1;
	}

	while (!feof(fp)) {
		size++;
		hm = (human*)realloc(hm, size * sizeof(human));
		fgets(hm[size-1].fio, 50, fp);
		fgets(hm[size-1].doljnost, 50, fp);
		fscanf(fp,"%d\n", &hm[size-1].zp);
	}

	for (int i = 0; i < size; i++) {
		avg_zp += hm[i].zp;
	}

	avg_zp /= size;

	for (int i = 0; i < size; i++) {
		if (hm[i].zp < avg_zp)
			puts(hm[i].fio);
	}

	free(hm);
	fclose(fp);
}