#if 0
#include  <iostream>
using namespace  std;
/*��ͷ����˫��;����Ĳ���*/
struct node {
    int data;
    node* llink, * rlink;
};
node* head;
int insert_d_l(node* head, int x, int y)    //x:�����ĸ�����֮��y����ʲôֵ
{
    node* p, * q;
    p = head->rlink;
    while (p != head && p->data != x)
        p = p->rlink;
    if (p == head) return(1);
    q = new(node);
    q->data = y;
    q->rlink = p->rlink;
    p->rlink = q;
    q->rlink->llink = q;
    q->llink = p;
    return(0);
}

//Ϊʲô���ɾ������ֱ�Ӷ����ݲ�������֮ǰ�Ĵ�����Ҫ���ã�
int delete_d_l(node* head, int x) /*��ͷ����˫��;����Ĳ��*/
{
    node* p;
    p = head->rlink;
    while (p != head && p->data != x)
        p = p->rlink;
    if (p == head) return(1);
    p->llink->rlink = p->rlink;
    p->rlink->llink = p->llink;
    delete  p;
    return(0);
}

node* create_link() {
    node* head = new node;
    head->data = -9999; head->llink = head; head->rlink = head; //ͷ��㲻�������е�����

    int n;
    cout << "���������ݣ�-9999��������";
    cin >> n;
    if (n == -9999) {
        return head;
    }
    else if(head->llink == head) {
        node* q = new node;
        q->data = n;
        q->rlink = head; q->llink = head;
        head->llink = q; head->rlink = q;

        cout << "���������ݣ�-9999��������";
        cin >> n;
    }
    
    while (n != -9999) {    //��ͷ������߲����µĽ��
        node* q = new node, * p = head->llink;   //q���½�㣬p���ɵ�β���
        q->data = n;
        q->rlink = head; q->llink = p;  //q��������
        p->rlink = q; head->llink = q;  //��������q
        
        cout << "���������ݣ�-9999��������";
        cin >> n;
    }
    return head;
}

void output_link(node *head) {
    node* p = head->rlink;
    while (p->data != -9999) {
        cout << p->data << " --> ";

        p = p->rlink;
    }
    cout << "\n";
}

int main() {
    node* head;
    head = create_link();
    output_link(head);
    delete_d_l(head, 200);
    output_link(head);

}
#endif