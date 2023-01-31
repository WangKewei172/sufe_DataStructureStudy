#if 0
#include  <iostream>
using namespace  std;
struct  node {
	int  data;
	node* link;
};
node* create_link()
{
	int  n;
	node* head = NULL, * p, * q;
	p = head;

	cin >> n;
	while (n != -9999)
	{
		if (head == NULL) {
			head = new node;
			head->data = n;
			head->link = NULL;
			p = head;   //pֻ��Ҫָ��head����
			cin >> n;   //������Ҫһ��cin����Ȼ��һ���ͻᴴ������
		}
		else {
			q = new node;   //��q������Ȼ��p��ָ
			q->data = n;
			q->link = NULL;
			p->link = q;
			p = q;
			cin >> n;
		}
		p->link = NULL;
	}

	return(head);
}

void out_link(node* head)
{
	while (head != NULL)
	{
		cout << head->data << "-->";
		head = head->link;
	}
	cout << endl;
}

node* reverse_link(node* head) {
	if (head == NULL || head->link == NULL) return head; //�ձ����ֻ��һ������൱�ڲ���Ҫ��ת
	node* p = head->link;
	node* q = p->link;
	head->link = NULL;
	while (q != NULL) {
		p->link = head; //�����м䡱���ָ����һ�����
		head = p;   //���������൱�ڰ�������ָ����������ƶ�һ��
		p = q;
		q = p->link;    //p->link����q->link��һ������p->linkΪ�˷������
	}
	p->link = head; //���һ����㻹û�����������ڶ�������
	return p;
}

int main()
{
	node* head;
	head = create_link();
	cout << "ԭ����\n";
	out_link(head);
	cout << "\n";

	head = reverse_link(head);
	cout << "��ת��\n";
	out_link(head);

	return 1;
}

#endif