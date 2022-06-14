#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
	FILE* fw = fopen("f2.txt", "w");
	int n, m, * arr, size, flag;

	fscanf(fp, "%d %d", &n, &m);
	printf("%d %d\n", n, m);

	arr = (int*)malloc(n * m * sizeof(int));

	for (int i = 0; i < n * m; i++) {
		fscanf(fp, "%d", &arr[i]);
		printf("%d  %d\n", arr[i], kolvoCifr(arr[i]));
	}

	for (int i = 0; i < n; i++) {
		flag = 1;
		size = kolvoCifr(arr[i*m]);
		for (int j = 0; j < m; j++) {
			if (size != kolvoCifr(arr[i * m + j])) {
				flag = 0;
			}
		}
		if (flag == 0) {
			for (int j = 0; j < m; j++) {
				fprintf(fw, "%d ", arr[i * m + j]);
			}
			fprintf(fw, "\n");
		}
	}
	free(arr);
	fclose(fp);
	fclose(fw);

}

