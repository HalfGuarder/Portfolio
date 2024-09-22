#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <stack>
#include <queue>

using namespace std;

void MergeResult(vector<int>& v, int left, int mid, int right)
{
	// ó�� ������ ���� ���� �۰� �ɰ��� �ִ� ����
	int leftIndex = left;
	int rightIndex = mid + 1;
	int i = 0;

	vector<int> temp;

	while (true)
	{
		if (leftIndex > mid || rightIndex > right) break;

		if (v[leftIndex] <= v[rightIndex])
		{
			temp.push_back(v[leftIndex]);
			leftIndex++;
		}
		else
		{
			temp.push_back(v[rightIndex]);
			rightIndex++;
		}
	}

	// ���� ���Ұ� ��� temp�� ����.
	// �����ʿ� ���Ұ� ���� �ִ�.
	if (leftIndex > mid)
	{
		while (rightIndex <= right)
		{
			temp.push_back(v[rightIndex]);
			rightIndex++;
		}
	}
	
	// ������ ���Ұ� ��� temp�� ����.
	// ���ʿ� ���Ұ� ���� �ִ�.
	else
	{
		while (leftIndex <= mid)
		{
			temp.push_back(v[leftIndex]);
			leftIndex++;
		}
	}

	for (int i = 0; i < temp.size(); i++)
	{
		v[left + i] = temp[i];
	}


	/*while (leftIndex <= mid && rightIndex <= right)
	{
		if (v[leftIndex] <= v[rightIndex])
		{
			temp.push_back(v[leftIndex]);
			leftIndex++;
		}
		else if (v[leftIndex] > v[rightIndex])
		{
			temp.push_back(v[rightIndex]);
			rightIndex++;
		}
	}

	if (leftIndex > mid)
	{
		while (rightIndex <= right)
		{
			temp.push_back(v[rightIndex]);
			rightIndex++;
		}
	}
	else if (rightIndex > right)
	{
		while (leftIndex <= mid)
		{
			temp.push_back(v[leftIndex]);
			leftIndex++;
		}
	}*/
	
}

void MergeSort(vector<int>& v, int left, int right)
{
	if (left >= right) return;

	int mid = (left + right) / 2;

	// Divede
	MergeSort(v, left, mid);
	MergeSort(v, mid + 1, right);

	// Conquer
	MergeResult(v, left, mid, right);
}

int main()
{
	vector<int> v = { 55, 30, 15, 100, 1, 5, 70, 30 };

	// MergeSort(v, 0, v.size() - 1);
	
	// N * logN
	// std::sort(v.begin(), v.end());
	// std::partial_sort(v.begin(), v.begin() + 3, v.end());
	// std::stable_sort(v.begin(), v.end());
	
	std::partial_sort(v.begin(), v.begin() + 3, v.end());

	return 0;
}