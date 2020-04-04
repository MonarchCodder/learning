#include <iostream>
#include <vector>
#include <algorithm>
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

// 插入排序法  

void InsertSort(vector<int>& array, int left, int right)
{
	return;
}

// 归并排序
void Merge(vector<int>& array, int left, int right, vector<int>& resArray);
void MergeSort(vector<int>& array, int left, int right, vector<int>& resArray);

void MergeSort(vector<int>& array, int left, int right, vector<int>& resArray)
{
	if (left < right)
	{
		int mid = (left + right) / 2;
		// 分开
		MergeSort(array, left, mid, resArray);
		MergeSort(array, mid + 1, right, resArray);
		// 合并
		Merge(array, left, right, resArray);
	}

	return;
}
// Merge函数用于归并的并
void Merge(vector<int>& array, int left, int right, vector<int>& resArray)
{

	// i 和 j 分别作为指针，指向两个分区的起始位置
	int i = left;
	int j = (left + right)/2 +1;
	// temp指针用于不断填充数据
	int temp = left;
	while ((i <= (left + right)/2) && (j <= right) )
	{
		if (array[i] > array[j])
		{
			resArray[temp] = array[j];
			temp++;
			j++;
		}
		else
		{
			resArray[temp] = array[i];
			temp++;
			i++;
		}
	}
	// 最后还要将其中一个分区的多的数据给直接复制给resArray   这里不能漏

	while (i <= ((left + right)/2)) {
		resArray[temp] = array[i];
		temp++;
		i++;
	}
	while (j <= right) {
		resArray[temp] = array[j];
		temp++;
		j++;
	}
	// cout << "Mergr" << endl;
	// for_each(resArray.begin(), resArray.end(), [](int num) {cout << num << endl; });
	// 注意要刷新原数组的值
	for (int k = left; k <= right; k++)
	{
		array[k] = resArray[k];
	}
	return;
}
