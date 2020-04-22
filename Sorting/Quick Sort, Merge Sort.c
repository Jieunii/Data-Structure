#include <stdio.h>
#define MAX_SIZE 8

void Swap(int arr[], int a, int b) 
{
	int temp = arr[a];
	arr[a] = arr[b];
	arr[b] = temp;
}
int Partition(int arr[], int left, int right)
{
	int pivot = arr[left];
	int low = left + 1;
	int high = right;

	while (low <= high)
	{
		while (pivot >= arr[low] && low <= right)
		{
			low++; 
		}
		while (pivot <= arr[high] && high >= (left + 1))
		{
			high--;
		}
		if (low <= high)
		{
			Swap(arr, low, high);
		}
	}
	Swap(arr, left, high);
	return high;
}
void QuickSort(int arr[], int left, int right)
{
	if (left <= right)
	{
		int pivot = Partition(arr, left, right);
		QuickSort(arr, left, pivot - 1); 
		QuickSort(arr, pivot + 1, right);
	}
	
}

int sorted[MAX_SIZE];
void Merge(int arr[], int left, int mid, int right) {
	int i, j, k, l;
	i = left;
	j = mid + 1;
	k = left;

	while (i <= mid && j <= right) {
		if (arr[i] <= arr[j])
			sorted[k++] = arr[i++];
		else
			sorted[k++] = arr[j++];
	}

	if (i > mid) {
		for (l = j; l <= right; l++)
			sorted[k++] = arr[l];
	}

	else {
		for (l = i; l <= mid; l++)
			sorted[k++] = arr[l];
	}

	for (l = left; l <= right; l++) {
		arr[l] = sorted[l];
	}
}

void MergeSort(int arr[], int left, int right) {
	int mid;

	if (left < right) {
		mid = (left + right) / 2;
			MergeSort(arr, left, mid);
		MergeSort(arr, mid + 1, right);
		Merge(arr, left, mid, right);
	}
}

int main()
{
	int arr[MAX_SIZE] = { 69, 10, 30, 2, 16, 8, 31, 22 };
	printf("정렬할 데이터: 69 10 30 2 16 8 31 22\n\n");

	printf("Quick sort를 수행한 결과: ");
	QuickSort(arr, 0, MAX_SIZE-1);
	for (int i = 0; i < MAX_SIZE; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	
	printf("Merge sort를 수행한 결과: ");
	MergeSort(arr, 0, MAX_SIZE - 1);
	for (int i = 0; i < MAX_SIZE; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	return 0;
}