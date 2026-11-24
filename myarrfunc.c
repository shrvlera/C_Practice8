#include <stdio.h>
#include "myarrfunc.h"
// очистка буфера
void clear_buf(void) {
	int c;
	while ((c = getchar()) != '\n' && c != EOF) {
	}
}

// пунк b: заполнение массива
void fill_array(int *arrptr, int n) {
	int *p = arrptr;
	int *end = arrptr + n;
	int i = 0;
	int res;

	while (p < end) {
		printf("Введите элемент [%d]: ", i);
		res = scanf("%d" , p);
		if (res == EOF) {
			break;
		}
		if (res != 1) {
			printf("ошибка: ведите целое число.\n");
			clear_buf();
			continue;
		}
		clear_buf();
		p++;
		i++;
	}
}
// пункт c: вывод значений и адресов
void print_array(const int *arrptr, int n) {
	const int *p = arrptr;
	const int *end = arrptr + n;
	int i = 0;

	printf("\nИндекс | Значение | Адрес\n");
	while (p < end) {
		printf("%6d | %8d | %p\n", i, *p, p);
		p++;
		i++;
	}
	printf("\n");
}
// функция № 3: мин. значение в диапазоне k-m
int find_min_range(const int *arrptr, int n, int k, int m, int *res) {
	if (k < 0 || m >= n || k > m) {
		return ERR;
	}
	const int *p = arrptr + k;
	const int *end = arrptr + m;
	int min = *p;

	while (p <= end) {
		if (*p < min) {
			min = *p;
		}
		p++;
	}
	*res = min;
	return OK;
}

// функция 18: разница между макс. и мин. значениями в диапазоне k-m
int find_diff_range(const int *arrptr, int n, int k, int m, int *res) {
	if (k < 0 || m >= n || k > m) {
		return ERR;
	}
	const int *p = arrptr + k;
	const int *end = arrptr + m;
	int min = *p;
	int max = *p;

	while (p <= end) {
		if (*p < min) {
			min = *p;
		}
		if (*p > max) {
			max = *p;
		}
		p++;
	}
	*res = max - min;
	return OK;
}

// функция 23: индексы элементов, значение котрых ниже k
int find_below_k(const int *arrptr, int n, int k, int *idx_arr, int *count) {
	const int *p = arrptr;
	const int *end = arrptr + n;
	int *out = idx_arr;
	int cnt = 0;
	int i = 0;

	while (p < end) {
		if (*p < k) {
			*out = i;
			out++;
			cnt++;
		}
		p++;
		i++;
	}
	*count = cnt;
	if (cnt == 0) {
		return NOT_FOUND;
	}
	return OK;
}






































