#include <stdio.h>

int left(int *pArr, int index, int height);
int right(int *pArr, int index, int height, int arr_size);

void main() {

	int arr[7] = {7, 4, 5, 9, 6, 7, 3};

	int max_area = 0;
	int total_left = 0;
	int total_right = 0;
	int sum_area = 0;
	int arr_length = sizeof(arr) / 4;
	for (int i = 0; i < arr_length; i++) {
		total_left = left(arr, i, arr[i]);
		total_right = right(arr, i, arr[i], sizeof(arr));
		sum_area = total_left + total_right - arr[i];

		if (max_area < sum_area)
			max_area = sum_area;

		printf("sum_area = %d \n", sum_area);
		printf("max_area = %d \n", max_area);
		printf("\n");
	}

	
}

int left(int *pArr, int index, int height) {

	if (index < 0)
		return NULL;

	int sum = 0;
	if (pArr[index] >= height) {
		index--;
		sum = left(pArr, index, height);
		index++;
		sum += height;
	}
	else
		return NULL;

	return sum;
}

int right(int *pArr, int index, int height, int arr_size) {

	if (index > arr_size)
		return NULL;

	int sum = 0;
	if(pArr[index] >= height) {
		index++;
		sum = right(pArr, index, height, arr_size);
		index--;
		sum += height;
	}
	else 
		return NULL;

	return sum;
}