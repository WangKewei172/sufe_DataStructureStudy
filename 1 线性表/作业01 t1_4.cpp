#if 0
#include  <iostream>
using namespace  std;
constexpr auto N = 20;	//���鳤��

struct  node {
    int  data;
    node* link;
};
node* createSortedLink()
{
    srand((unsigned int)time(NULL));
    node* head = NULL, * p, * q;
    int n = rand() % 20 - 10;   //nΪ������������

    if (N == 0) return NULL;

    head = new node;
    p = head;
    p->data = n;
    p->link = NULL;

    for (int i = 1; i < N; i++) {
        q = new node;
        q->data = n + i * 1.5;  //Ҫ�е���
        q->link = NULL;
        p->link = q;
        p = q;
    }
    
    return head;
}

node* insertLink(node *head) {
    int num;
    cout << "����������������ֵ��= -9999ʱ�˳�����";
    cin >> num;
    if (num == -9999) return head;

    int max;    //��¼���ֵ
    node* m = head; //��Ϊ����Ѱ��β���
    while (m->link != NULL) {
        m = m->link;
    }
    max = m->data;  //���������õ�����˳��Ϊ���������ҵ����һ������ֵ����

    node* p = new node; //p���½��
    p->data = num;

    if (num < head->data) { //����ͷ��
        p->link = head;
        head = p;
    }
    else if (num >= max) {   //������ڵ������ֵ�����������
        p->link = NULL;
        m->link = p;
    }
    else {  //���м�
        m = head;   //��ʱβ����Ѿ�û�����ˣ��������´�����������
        while (m->link != NULL && m->link->data < p->data) { //�ҵ�Ҫ�����λ�ã���������£�������2�����
            m = m->link;
        }
        p->link = m->link;
        m->link = p;
    }

    return head;
}

void out_link(node* head)
{
    while (head != NULL)
    {
        cout << head->data << " --> ";
        head = head->link;
    }
    cout << endl;
}



int main()
{
    node* head;
    head = createSortedLink();
    out_link(head);
    head = insertLink(head);
    cout << "�����\n";
    out_link(head);
    return 0;
}
#endif