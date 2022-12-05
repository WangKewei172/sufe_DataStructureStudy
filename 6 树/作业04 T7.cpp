#if 0
#include<iostream>
using namespace std;

struct node {
	char data;
	node* leftChild;	//���ӽ��
	node* rightChild;	//���ӽ��
};


void printBinaryTree(node* head) {
	if (head == NULL) {	//ĳ���Ϊ�գ�����
		return;
	}

	//��T�ĺ����ӦT'������
	printBinaryTree(head->leftChild);
	cout << head->data << " ";
	printBinaryTree(head->rightChild);
}



//t7�����ö�������ǰ�����������
// https://weibaohang.blog.csdn.net/article/details/110233951?spm=1001.2101.3001.6661.1&utm_medium=distribute.pc_relevant_t0.none-task-blog-2%7Edefault%7ECTRLIST%7ERate-1-110233951-blog-105255475.pc_relevant_default&depth_1-utm_source=distribute.pc_relevant_t0.none-task-blog-2%7Edefault%7ECTRLIST%7ERate-1-110233951-blog-105255475.pc_relevant_default&utm_relevant_index=1
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
	head->leftChild = makeTreeByPreIno(pre + 1, ino, leftNum);	

	// ��������������������ʼλ�õ��������������Ĵ�С��
	// �������������Ϊp+1������Ϊ�ܳ���ȥ�����������ҵ��ĸ��ڵ����Ĳ��֣�
	// ��������Ϊʣ��һ���ֵĳ��ȣ�����ĳ��ȼ�һ����Ϊǰ��ĵ�һ���Ѿ��Ǹ��ڵ��ˣ������ܳ��ȼ�һ����ȥ����������
	head->rightChild = makeTreeByPreIno(pre + 1 + leftNum, p + 1, n - leftNum - 1);	

	return head;
}

bool isCompleteBT(node* head) {
	if (head->leftChild == NULL && 
		head->rightChild == NULL) {	//����������Ϊ�գ�˵����Ҷ�ӽ�㣬������
		return true;
	}
	else if (head->leftChild != NULL && head->rightChild != NULL) {	//���������������Ϊ�գ��ݹ���ȥ
		return isCompleteBT(head->leftChild) && isCompleteBT(head->rightChild);	
	}
	else
		return false;	//һ��Ϊ�գ�һ����Ϊ�գ�������ȫ������
}


int main() {
	node* head = NULL;

	char pre[] = "abdgcef";
	char ino[] = "gdbaecf";

	head = makeTreeByPreIno(pre, ino, 7);

	cout << endl << isCompleteBT(head) << endl;
	printBinaryTree(head);	//���������gdbaecf
}
#endif