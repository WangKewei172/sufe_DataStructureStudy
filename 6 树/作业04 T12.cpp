#if 0
#include<iostream>
using namespace std;

struct node {	//������
	char data;	//ֵ
	int ltag = 0, rtag = 0; //��ltag = 0ʱ��lchildָ���������ӽ�㣻��ltag = 1ʱ��lchildָ������Ӧ˳�򣨱������򣩵�ǰһ��ֵ�Ľ��
	node* lchild, * rchild;	
};

//������������ǰ��ʽ���
void prePrint(node* head) {
	while(head != NULL){
		cout << head->data << " ";
		if (head->ltag == 0 && head->lchild) {	//һֱ�����ܣ��ܵ��ס���������ӽ������Ҳ�Ϊ�գ�
			head = head->lchild;
			continue;
		}

		if (head->ltag == 1 || head->lchild == NULL) {
			while (head->rchild != NULL && head->rtag != 0)	//�����ء��ܣ��ܵ����ҽ��ĵط�
				head = head->rchild;
			head = head->rchild;	//���ŵ�����ҽ������
		}
	}
}

//void prePrint(node* head) {
//	while (head != NULL) {
//		cout << head->data << " ";
//		if (head->ltag == 1 || head->lchild == NULL) {
//			head = head->lchild;
//			continue;
//		}
//		else {
//			head = head->lchild;
//			while (head->rtag == 0)
//				head = head->rchild;
//		}
//	}
//}


//����������ظ���ֵ���ܻ��ж�����������������������û���ظ���ֵ
//ǰ��ĵ�һ��Ϊ���ڵ㣬����ĸ��ڵ����ҷ��ֱ����������������Կ���������һ��ݹ�
node* makeTreeByPreIno(char pre[], char ino[], int n) {	//��������������ֱ�Ϊ��ǰ���������鳤��
	if (n == 0) {	//�����鳤��Ϊ0ʱ������NULL
		return NULL;
	}

	// 1.����ȡǰ����׸���Ϊ���ڵ��ֵ
	node* head = new node;
	head->data = pre[0];

	// 2.���������������ҵ����ֵ
	char* p = ino;	//��ΪѰ�Ҹ�ֵ��ָ��
	for (; p < ino + n; p++) {
		if (*p == pre[0])	//�ҵ����ڵ��λ�ã�ֵ���ظ���
			break;
	}

	int leftNum = p - ino;	//�������Ĵ�С���������������ҵ��ĸ��ڵ��λ�ü�ȥ��ͷ��λ��

	// 3.�ҵ����������򣩵����Ϊ���������ұ�Ϊ����������ʼ�ݹ�

	// ��������������pre[0]�Ѿ��Ǹ��ڵ��ˣ�������Ҫ�����ơ�һλ
	// ����ġ�������Χ����leftNum����������С�����ƣ������൱��ino��leftNumһ�𡰽�ȡ���˸�����
	head->lchild = makeTreeByPreIno(pre + 1, ino, leftNum);

	// ��������������������ʼλ�õ��������������Ĵ�С��
	// �������������Ϊp+1������Ϊ�ܳ���ȥ�����������ҵ��ĸ��ڵ����Ĳ��֣�
	// ��������Ϊʣ��һ���ֵĳ��ȣ�����ĳ��ȼ�һ����Ϊǰ��ĵ�һ���Ѿ��Ǹ��ڵ��ˣ������ܳ��ȼ�һ����ȥ����������
	head->rchild = makeTreeByPreIno(pre + 1 + leftNum, p + 1, n - leftNum - 1);

	return head;
}

//��������������������
//preָ��ǰһ�����
void createTree(node* head, node* &pre) {
	if (head) {
		createTree(head->lchild, pre);

		if (!head->lchild) {	//�������Ϊ��
			head->ltag = 1;	//���Ϊ��û������
			head->lchild = pre;	//���Ӹ�ֵΪǰ��
		}

		if (pre != NULL && !pre->rchild) {	//����Һ���Ϊ��
			pre->rtag = 1;	//���Ϊ��û���Һ���
			pre->rchild = head;	//ָ����
		}

		pre = head;
		createTree(head->rchild, pre);
	}
}

int main() {
	char a[] = "ABDGCEF";	//ǰ��
	char b[] = "GDBAECF";	//����
	node *head = makeTreeByPreIno(a, b, 9), *pre = NULL;


	createTree(head, pre);
	head->rchild->rchild->rchild = NULL;
	//pre = NULL;	//�����һ�����������


	//if (!pre) cout << "��\n";
	prePrint(head);
	return 0;
}
#endif