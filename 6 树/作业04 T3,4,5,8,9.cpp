#if 0
#include<iostream>
using namespace std;

struct node {
	int data;
	node* leftChild;	//���ӽ��
	node* rightChild;	//���ӽ��
};

//���õݹ鹹����ȫ��������nΪ����
void makeBinaryTree(node* &head,int n) {

	if (n <= 0) {	//���׸�null
		head = NULL;
	}
	else {
		head = new node;
		head->data = rand() % 10;	//�����ֵ
		makeBinaryTree(head->leftChild, n - 1);	//��
		makeBinaryTree(head->rightChild, n - 1);	//��
	}
	
}

//����ջ�����ݹ飩ʵ�ֺ������
//����
void printBinaryTree(node* head) {
	if (head == NULL) {	//ĳ���Ϊ�գ�����
		return;
	}

	//��T�ĺ����ӦT'������
	printBinaryTree(head->leftChild);	
	cout << head->data << " ";
	printBinaryTree(head->rightChild);
}

//�������
void swapBinaryTree(node* &head) {
	if (head == NULL) return;
	swap(head->leftChild, head->rightChild);	//�Ȼ�����ģ������Ƶ�������Ҳ����
	swapBinaryTree(head->leftChild);
	swapBinaryTree(head->rightChild);
}

//����Ҷ�ӽ�������
//����Ҷ�ӽ������Ϊת���ɶ������������Ϊ�յ�����
void coutChild(node* head) {
	
	if (head == NULL) return;
	if (head->leftChild == NULL)	//����Ϊ�վͼ�һ
		cout << head->data << " ";
	coutChild(head->leftChild);	//������Ҷ�ӽ�����������������������ĺ�
	coutChild(head->rightChild);
	return;
}

//���㵱ǰ��������������ӽ��
int countConRight(node* head) {
	int sum = 1;
	if (head->rightChild != NULL)
		sum += countConRight(head->rightChild);
	else
		return sum;

}

//�������Ĵ���
//���Ĵ������Ƕ����������ӵ������Һ��ӣ������Լ��������ֵ
int countTimes(node* head) {
	if (head == NULL) return 0;
	int num = countConRight(head);

	//���㵱ǰ�����������ֵ
	//�����Һ��ӵıȽ�,ȡ���ֵ
	num = max(max(countTimes(head->rightChild),countTimes(head->leftChild)),num);
	return num;
}

//�ж��ǲ�����ȫ������
bool isCompleteBT(node* head) {
	if (head->leftChild == NULL && head->rightChild == NULL) {	//����������Ϊ�գ�˵����Ҷ�ӽ�㣬������
		return true;
	}
	else if (head->leftChild != NULL && head->rightChild != NULL) {
		return isCompleteBT(head->leftChild) && isCompleteBT(head->rightChild);	//���������������Ϊ�գ��ݹ���ȥ
	}
	else
		return false;	//һ��Ϊ�գ�һ����Ϊ�գ�������ȫ������
}

//�ж������Ƿ�����
bool isSimilarTree(node* tree1, node* tree2) {
	if (tree1 == NULL && tree2 == NULL)
		return true;
	else if (tree1 != NULL && tree2 != NULL)
		return isSimilarTree(tree1->leftChild, tree2->leftChild)
		&& isSimilarTree(tree1->rightChild, tree2->rightChild);	//���������Ƿ�ֱ�����
	else
		return false;
}

int main() {
	srand((unsigned int)time(NULL));
	node* head = NULL, * head2 = NULL;
	
	// �����������
	makeBinaryTree(head, 8);
	head->rightChild = NULL;
	head->leftChild->leftChild = NULL;
	head->leftChild->rightChild->rightChild->leftChild = NULL;
	head->leftChild->rightChild->rightChild->rightChild = NULL;
	head->leftChild->rightChild->leftChild->leftChild = NULL;
	head->leftChild->rightChild->leftChild->rightChild->leftChild = NULL;
	head->leftChild->rightChild->leftChild->rightChild->rightChild->leftChild = NULL;

	printBinaryTree(head);
	cout << "\n";
	cout << countTimes(head);
}

///*char pre[] = "abdgcef";
//char ino[] = "gdbaecf";
//makeBinaryTree(head,3);
//makeBinaryTree(head2, 3);*/
////cout << isSimilarTree(head, head2) << endl;
////printBinaryTree(head);
////makeBinaryTree(head, 4);
///*printBinaryTree(head);
//cout << "\n";
//
//head->rightChild = NULL;
//head->leftChild->rightChild = NULL;
//
//printBinaryTree(head);
//cout << "\n";
//coutChild(head);*/
//
////cout << countTimes(head);
//
////swapBinaryTree(head);
////printBinaryTree(head);


#endif