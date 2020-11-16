#include "Header.h"

float bubbleSort(int a[], int n)
{
	clock_t start = clock();
	for (int i = 1; i < n; i++)
	{
		for (int j = n - 1; j > i; j--)
		{
			if (a[j] < a[j - 1])
				swap(a[j], a[j - 1]);
		}
	}
	clock_t end = clock();

	return (float)(end - start) / CLOCKS_PER_SEC;
}

int findMin(int a[], int start, int n)
{
	int Min = start;
	for (int i = start + 1; i < n; i++)
		if (a[i] < a[Min])
			Min = i;
	return Min;
}

float selectionSort(int a[], int n)
{
	clock_t start = clock();
	for (int i = 0; i < n - 1; i++)
	{
		int Min = findMin(a, i, n);
		swap(a[i], a[Min]);
	}
	clock_t end = clock();

	return (float)(end - start) / CLOCKS_PER_SEC;
}

float insertionSort(int a[], int n)
{
	clock_t start = clock();
	int k = 1;
	while (k < n) {
		int i = k - 1;
		int p = a[k];
		while (i > -1 && a[i] > p)
		{
			a[i + 1] = a[i];
			i--;
		}
		i++;
		a[i] = p;
		k++;
	}
	clock_t end = clock();

	return (float)(end - start) / CLOCKS_PER_SEC;
}

void sift(int a[], int left, int right)
{
	int i = left;
	int j = 2 * i + 1;
	int x = a[i];
	while (j <= right) {
		if ((a[j] > a[j + 1]) && j < right)
			j++;
		if (x <= a[j])
			break;
		a[i] = a[j];
		i = j;
		j = 2 * i + 1;
	}
	a[i] = x;
}

float heapSort(int a[], int n)
{
	int left = n / 2 - 1;
	while (left > -1) {
		sift(a, left, n);
		left--;
	}

	int right = n - 1;
	while (right > 0) {
		swap(a[0], a[right]);
		right--;
		sift(a, 0, right);
	}
}
