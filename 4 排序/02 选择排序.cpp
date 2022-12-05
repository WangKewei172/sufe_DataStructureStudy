#if 0
#include <iostream>
using namespace std;

struct node {
	int data;
	node* link;
};

//ѡ������
void selectionSort(node *head) {
	node* p = head;//p�����������ÿһ��Ԫ��
	node* q = head;	//q����ָ���ź����ĩβ�Ľ��ĺ�һ�����
	node* t = head;	//t����ָ����СԪ��

	p = q->link;
	while (q->link != NULL && p != NULL) {
		t = q;	//��q��ʼ
		while (p != NULL) {	//����������н��
			if (p->data < t->data) {	//����ҵ��˸�С��Ԫ��
				t = p;//tָ����СԪ��
			}
			p = p->link;//����������
		}//��ʱ�Ѿ��ҵ�����С��ֵ���ڵĽ�㣬��tָ��

		if (t != q) {//��Сֵ�ں���Ļ����ͽ�����������ֵ
			/*int tem = t->data;
			t->data = q->data;
			q->data = tem;*/
			swap(t->data, q->data);
		}
		q = q->link;//�ź���󣬸���ĩβ���
		p = q->link;//��Ϊtָ��q������p��q����һ����ʼ
	}
}

//�˺������ڴ������������
node* createRandLink()
{
	srand((unsigned int)time(NULL));
	node* head = NULL, * p, * q;
	int n = rand() % 20 - 10;   
	head = new node;
	p = head;
	p->data = n;
	p->link = NULL;

	for (int i = 1; i < 10; i++) {
		q = new node;
		q->data = rand() % 40 - 20;  //�����
		q->link = NULL;
		p->link = q;
		p = q;
	}
	return head;
}

//�˺��������������
void outPutLink(node *head) {
	node* p = head;
	while (p != NULL) {
		cout << p->data << " -> ";
		p = p->link;
	}
	cout << endl;
}

int main() {
	node* head = createRandLink();
	outPutLink(head);
	selectionSort(head);
	outPutLink(head);
}
#endif