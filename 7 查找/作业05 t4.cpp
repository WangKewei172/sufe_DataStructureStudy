#if 1
#include<iostream>
using namespace std;

struct node {
	int num;		//ֵ
	node* left;	//��ָ��
	node* right;	//��ָ��
};

/**
 * . ��������
 * 
 * \param head Ҫ����Ķ������ĸ����
 * \param n ���Ĳ���
 */
void makeBinaryTree(node*& head, int n) {
	if (n <= 0) {	//���׸�null
		head = NULL;
	}
	else {
		head = new node;
		head->num = rand() % 10;	//�����ֵ
		makeBinaryTree(head->left, n - 1);	//��
		makeBinaryTree(head->right, n - 1);	//��
	}
}

/**
 * . ���õݹ�������ĸ߶ȡ���ǰ���ĸ߶� = �������߶� + 1
 * 
 * \param head	ͷ���
 * \return ���ص�ǰ���ĸ߶�
 */
int countHeight(node* head) {
	if (head->left == NULL && head->right == NULL) {		//���ΪҶ�ӽ��
		return 1;
	}
	else if (head->left == NULL) {
		return countHeight(head->right) + 1;
	}
	else if (head->right == NULL) {
		return countHeight(head->left) + 1;
	}
	else {
		return max(countHeight(head->left), countHeight(head->right)) + 1;	//����������� + 1
	}
}

int main() {
	node* head = NULL;
	makeBinaryTree(head,5);
	head->left->left = NULL;
	head->left->right = NULL;
	head->right->left = NULL;
	//head->right->right = NULL;

	cout << countHeight(head);
}

#endif