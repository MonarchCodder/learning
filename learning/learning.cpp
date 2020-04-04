﻿// learning.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
extern void SwapVal(vector<int>& array, int i, int j);
extern void QuickSort(vector<int>& array, int left, int right);
// 归并排序
extern void MergeSort(vector<int>& array, int left, int right, vector<int>& resArray);
// Merge函数用于归并的并
extern void Merge(vector<int>& array, int left, int right, vector<int>& resArray);

int main()
{
	vector<int> array = { 3,1,2,5,4 };
	// 快速排序
	QuickSort(array, 0, array.size() - 1);
	cout << "Quick Sort" << endl;
	for_each(array.begin(), array.end(), [](int num) {cout << num << ","; });
	cout << endl;
	// 归并排序
	array = { 3,1,2,5,4};
	cout << "Merge Sort Pre" << endl;
	for_each(array.begin(), array.end(), [](int num) {cout << num << ","; });
	vector<int> resArray(array.size(),0);
	MergeSort(array, 0, array.size() - 1, resArray);
	cout << endl << "Merge Sort After Temp" << endl;
	for_each(resArray.begin(), resArray.end(), [](int num) {cout << num << endl; });
	cout << endl << "Merge Sort After" << endl;
	for_each(array.begin(), array.end(), [](int num) {cout << num << endl; });
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
