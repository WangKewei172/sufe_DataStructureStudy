#if 0
#include<iostream>
using namespace std;

struct node {
	char  data;
	node* link;
};

node* create_link(char a[]) {
	if (a[0] == '\0') return NULL;

	node* head = new node;
	head->data = a[0]; head->link = NULL;
	node* p = head, * q;	//p:ָ��β��㣬q�������½��

	int i = 1;

	while (a[i] != '\0') {
		q = new node;
		q->data = a[i]; q->link = NULL;	//���½��
		p->link = q; p = q;	//����ɽ��
		i++;
	}
	return head;
}
void Out_link(node* head) {
	node* p = head;
	while (p != NULL) {
		cout << p->data << " -> ";
		p = p->link;
	}
	cout << "\n";
}

node* reverse_link(node* head)
{
	if (head->link == NULL) return head;
	node* left = head, * mid = head->link, * right = mid->link;	//���������ֱ��ʾ�����ҽ�㣨����NULL��
	head->link = NULL;
	while (right != NULL) {
		mid->link = left;	//��ת
		left = mid; mid = right; right = right->link;	//����ȥ
	}
	mid->link = left;
	return mid;
}

int main() {
	char s[] = "abcdefg";
	node* head = create_link(s);
	Out_link(head);
	head = reverse_link(head);
	Out_link(head);
	return 0;
}
#endif