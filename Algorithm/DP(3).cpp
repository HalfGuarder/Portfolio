#include <iostream>
#include <Windows.h>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

// Enchant
// N��ŭ ��ȭ
// +1, +2, +3

int N = 0; // 100000
// +1 +1 +1
// +1 +2
// +2 +1
// +3
// ... result = 4

vector<int> enchantV = { 1, 2, 3 };

vector<int> cache = vector<int>(100001, -1);

int Enchant1(int num) // 0 ��ȭ�� �� 1�� ����
{
	// ���� ����
	if (num == N) return 1;
	if (num > N) return 0;

	int& ref = cache[num];
	if (ref != -1) return ref;

	return ref = Enchant1(num + 1) + Enchant1(num + 2) + Enchant1(num + 3);
}


int Enchant3(int num) // 0 ��ȭ�� �� 1�� ����
{
	// ���� ����
	if (num == 0) return 1;
	if (num < 0) return 0;

	int& ref = cache[num];
	if (ref != -1) return ref;

	return ref = Enchant1(num - 1) + Enchant1(num - 2) + Enchant1(num - 3);
}


int Enchant2(int target)
{
	// ���� ����
	if (target == 0) return 0;
	if (target == 1) return 1;
	if (target == 2) return 2;
	if (target == 3) return 4;

	// �޸������̼�
	int& ref = cache[target];

	if (ref != -1) return ref;

	// ���ϱ�
	ref = Enchant2(target - 1) + Enchant2(target - 2) + Enchant2(target - 3);

	return ref;
}


int main()
{
	int result = Enchant2(0);
	
	// ���� ������
	// %c : character
	// %s : string
	// %d : ��ȣ �ִ� 10�� ���� decimal
	// %f : float
	int tmp = 1;
	printf("Hello World! %d \n .... tmp : %d", result, tmp);

	return 0;
}