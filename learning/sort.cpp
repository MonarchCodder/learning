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
// ���������㷨   �����㷨
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

// ��������  

void InsertSort(vector<int>& array, int left, int right)
{
	return;
}

// �鲢����
void Merge(vector<int>& array, int left, int right, vector<int>& resArray);
void MergeSort(vector<int>& array, int left, int right, vector<int>& resArray);

void MergeSort(vector<int>& array, int left, int right, vector<int>& resArray)
{
	if (left < right)
	{
		int mid = (left + right) / 2;
		// �ֿ�
		MergeSort(array, left, mid, resArray);
		MergeSort(array, mid + 1, right, resArray);
		// �ϲ�
		Merge(array, left, right, resArray);
	}

	return;
}
// Merge�������ڹ鲢�Ĳ�
void Merge(vector<int>& array, int left, int right, vector<int>& resArray)
{

	// i �� j �ֱ���Ϊָ�룬ָ��������������ʼλ��
	int i = left;
	int j = (left + right)/2 +1;
	// tempָ�����ڲ����������
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
	// ���Ҫ������һ�������Ķ�����ݸ�ֱ�Ӹ��Ƹ�resArray   ���ﲻ��©

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
	// ע��Ҫˢ��ԭ�����ֵ
	for (int k = left; k <= right; k++)
	{
		array[k] = resArray[k];
	}
	return;
}
