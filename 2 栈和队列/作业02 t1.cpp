#if 0
#include  <iostream>
using namespace  std;
constexpr auto N = 10;  //�����С
struct  node_one {
	int  data;
	node_one* link;
};

struct node_two {
	int  data;
	node_two* Llink;
	node_two* Rlink;
};

node_one* createRandLink()
{
	srand((unsigned int)time(NULL));
	node_one* head = NULL, * p, * q;
	int n = rand() % 20 - 10;   //nΪ������������

	if (N == 0) return NULL;

	head = new node_one;
	p = head;
	p->data = n;
	p->link = NULL;

	for (int i = 1; i < N; i++) {   //���ɽ����ΪN������
		q = new node_one;
		q->data = rand() % 40 - 20;  //�����
		q->link = NULL;
		p->link = q;
		p = q;
	}
	return head;
}

node_two* oneToTwo(node_one* head) {
	node_one* p = head;
	node_two* tp = NULL, * tem = NULL, * thead = NULL;
	if (p != NULL) {
		thead = new node_two;   //����ͷ���
		thead->data = p->data;  //��ͷ��㸳ֵ
		thead->Llink = NULL;    //����link
		tp = thead; //βָ��ָ��ͷ
		p = p->link;
	}
	while (p != NULL) {
		tem = new node_two; //�½��
		tem->Llink = tp; tem->Rlink = NULL; tem->data = p->data;    //���½�㸳ֵ
		tp->Rlink = tem; tp = tem;   //�������½�㣬����˫������
		p = p->link;    //���µ�������
	}
	return thead;
}

void printTwoLink(node_two* head) {
	node_two* p = head;
	while (p->Rlink != NULL) p = p->Rlink;
	cout << "����\n";
	while (p != NULL) {
		cout << p->data << " <-> ";
		p = p->Llink;
	}
	cout << "\n";
}

void printOneLink(node_one* head) {
	node_one* p = head;
	while (p != NULL) {
		cout << p->data << " -> ";
		p = p->link;
	}
	cout << "\n";
}

int main() {
	node_one* ohead = createRandLink();
	printOneLink(ohead);
	node_two* thead = oneToTwo(ohead);
	printTwoLink(thead);
}
#endif