#if 0
#include<iostream>
using namespace std;

struct node {
	int num;		//ֵ
	node* left;	//��ָ��
	node* right;	//��ָ��
};

/**
 * .�ݹ���ж��ǲ��Ƕ��������
 *
 * \param head ����ĸ����
 * \return
 */
bool isBST(node* head) {
	if (head->left == NULL && head->right == NULL) {	//ȫΪ��
		return true;
	}
	else if (head->left == NULL) {		//�Ҳ�Ϊ��
		return head->num < head->right->num&& isBST(head->right);	//������Ϊ�����������Ҵ�����
	}
	else if (head->right == NULL) {	//��Ϊ��
		return head->num > head->left->num && isBST(head->left);
	}
	else {	//���Ҷ�����
		return head->left->num < head->num&&		//��С����
			head->num < head->right->num&&	//��С����
			isBST(head->left) && isBST(head->right);	//���Ҷ���
	}
}

int main() {
	node* head = new node;
	node* l = new node; node* r = new node;
	head->left = l; head->right = r; head->num = 9;
	l->left = l->right = NULL; l->num = 8;
	r = NULL;
	//r->left = r->right = NULL; r->num = 10;

	cout << isBST(head);
}
#endif