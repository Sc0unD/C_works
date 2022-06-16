#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

int kolvoCifr(int a) {
	int size = 0;
	if (a == 0) {
		size = 1;
	}
	while (a > 0) {
		size++;
		a /= 10;
	}
	return size;
}


int main()
{
	system("chcp 1251");
	FILE* fp = fopen("f1.txt", "r");
	int n, m, * arr, size, new_n, f = 0;
	bool flag = false;

	fscanf(fp, "%d %d", &n, &m);
	printf("%d %d\n", n, m);
	new_n = n;

	arr = (int*)malloc(n * m * sizeof(int));

	for (int i = 0; i < n * m; i++) {
		fscanf(fp, "%d", &arr[i]);
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			printf("%4d\t", arr[i * m + j]);
		}
		printf("\n");
	}

	for (int i = 0; i < n; i++) {
		
		flag = false;
		size = kolvoCifr(arr[i * m]);
		for (int j = 0; j < m; j++) {
			//printf("%3d", kolvoCifr(arr[i * m + j]));
			if (kolvoCifr(arr[i * m + j]) != size) {
				flag = true;
			}
		}

		if (flag == false) {
			new_n--;
			
			for (int j = 0; j < m; j++) {
				for (int k = 0; k + i < n-1; k++) {
					arr[(i + k) * m + j] = arr[(i + k + 1) * m + j];
				}
			}
			i -= 2;
		}
	}
	

	arr = (int*)realloc(arr, m * new_n * sizeof(int));
	printf("\n");

	for (int i = 0; i < new_n; i++) {
		for (int j = 0; j < m; j++) {
			printf("%4d\t", arr[i * m + j]);
		}
		printf("\n");
	}

	free(arr);
	fclose(fp);

}
