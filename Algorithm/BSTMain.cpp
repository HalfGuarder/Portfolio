#include <unordered_map>
#include <map>

#include "BinarySearchTree.h"

// �ؽ� ���̺� : �޸𸮸� �ְ� Ž�� �ð��� ���Ѵ�.
// Ž�� : ��� ... �ؽ� �浹�� ���� ü�̴׿� ���� �޶��� �� �ִ�.
// ���� : ���
// �浹, ü�̴�

// �ڰ� ���� ���� Ž�� Ʈ��
// Ž�� : logN
// ���� : logN

// �ؽ� ���̺� vs �ڰ� ���� ���� Ž�� Ʈ��
// �ؽ� �Լ� �� �浹�� ���� �Ͼ ��� ... �ڰ� ���� ���� Ž�� Ʈ�� ��
// �浹�� ���� ��� ... �ؽ� ���̺� ��

int main()
{
#pragma region BST
	BinarySearchTree bst;
	bst.Insert(50);
	bst.Insert(40);
	bst.Insert(70);
	bst.Insert(30);
	bst.Insert(45);

	bst.Insert(100);
	bst.Insert(60);
	bst.Insert(47);

	bst.PrintTree(bst._root);

	Node* tmp = bst.Search(bst._root, 100);
	if (tmp != nullptr)
	{
		cout << tmp->key << endl;
	}
	else
	{
		cout << "�ش� ��尡 �����ϴ�." << endl;
	}

	tmp = bst.Min(bst._root);
	cout << tmp->key << endl;

	tmp = bst.Max(bst._root);
	cout << tmp->key << endl;
#pragma endregion

	unordered_map<int, int> um;

	um[5] = 1;

	return 0;
}