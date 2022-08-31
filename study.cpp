#include<stdio.h>

void mergeSort(int numList[], int left, int right);

void merge(int numList[], int left, int mid, int right);

void mergeSort(int numList[], int left, int right) {
	int mid = (left + right) / 2;

	if (left < right) {
		mergeSort(numList, left, mid);
		mergeSort(numList, mid + 1, right);
		merge(numList, left, mid, right);
	}
}

void merge(int numList[], int left, int mid, int right) {
	int left_count = left, right_count = mid + 1, numList_copy[100] = { 0, }, count = left;

	while (left_count <= mid && right_count <= right) {
		if (numList[left_count] <= numList[right_count]) numList_copy[count++] = numList[left_count++];
		else numList_copy[count++] = numList[right_count++];
	}

	if (left_count > mid) while (right_count <= right) numList_copy[count++] = numList[right_count++];
	else while (left_count <= mid) numList_copy[count++] = numList[left_count++];

	for (int i = left; i <= right; i++) numList[i] = numList_copy[i];
}

int BinarySearch(int Sorted_numList[],int left, int right, int searchNum) {
	int mid = (left + right) / 2;

	if (right % 2 == 1) {
		if (Sorted_numList[right] == searchNum) return right;
		
		right--;
	}

	while (Sorted_numList[mid] != searchNum && left < right) {
		mid = (left + right) / 2;

		if (searchNum < Sorted_numList[mid]) right = mid;
		else left = mid;
	}

	return mid + 1;
}

int main() {
	int input_numList[100] = { 0, }, inputCount = 0, input_searchNum = 0;

	printf("입력할 숫자의 개수: ");
	scanf_s("%d", &inputCount);

	printf("\n숫자 입력: ");
	for (int i = 0; i < inputCount; i++) scanf_s("%d", &input_numList[i]);

	mergeSort(input_numList, 0, inputCount - 1);

	//printf("\n-----------------<mergeSort_TEST>-----------------\n");
	//for (int i = 0; i < inputCount; i++)printf("%d ", input_numList[i]);
	//printf("\n--------------------------------------------------\n");

	printf("\n몇번째로 작은지 알아볼 숫자: ");
	scanf_s("%d", &input_searchNum);

	printf("찾으시는 숫자는 %d번째로 작은 숫자입니다.", BinarySearch(input_numList, 0, inputCount - 1, input_searchNum));

	return 0;
}