#include <iostream>
#include <vector>

using namespace std;

void SwapVal(vector<int>& array, int i, int j)
{
	int temp = array[i];
	array[i] = array[j];
	array[j] = temp;
	return;
}
// 快速排序算法   分治算法
void QuickSort(vector<int>& array, int left, int right)
{
	if (left >= right)
	{
		return;
	}
	int i = left;
	int val = array[left];
	for (int j = i+1; j <= right; j++) {
		if (array[j] <= val) {
			SwapVal(array, i, j);
			i++;
		}
	}
	QuickSort(array, left, i-1);
	QuickSort(array, i+1, right);
}