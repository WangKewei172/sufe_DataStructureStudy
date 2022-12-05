#if 0
#include  <iostream>
using namespace  std;
constexpr auto N = 20;  //���鳤��
struct  node {
    int  data;
    node* link;
};
node* createRandLink()
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
        q->data = rand()%40 - 20;  //�����
        //q->data = (rand() % 10 - 5) * 2;    //ȫ��ż��
        //q->data = (rand() % 10 - 5) * 2 + 1; //ȫ������
        q->link = NULL;
        p->link = q;
        p = q;
    }
    return head;
}

bool isOdd(int n) {
    return n % 2 == 1 || n % 2 == -1;
}

node* deleteOddNode(node* head) {
    if (head == NULL) { //����Ϊ��ʱ
        return head;
    }
    node* q = head;
    node* p = head;    //���ã�ָ��Ҫɾ���Ľ���ǰ��
    while (1) {
        if (isOdd(q->data)) { //ɾ������ͷ���
            if (q->link == NULL) {//ֻʣͷ��㣬��ͷ���Ϊ��
                delete q;
                return NULL;   
            }
            
            head = q->link; //����ǰ���Ѿ�����head��㣬����ֱ�ӽ���ȥ����ɾ��
            delete(q);
            q = head;   //�ٽ���ȥ
        }
        else {  //ɾ�������м��㣬��ʱͷ����Ѿ�Ϊż���������Ѿ���ɾ�겢�˳�
            while (!isOdd(q->data) && q->link != NULL) {   //Ϊ���ҵ���һ��ƥ��Ľ��
                p = q;
                q = q->link;
            }
            if (isOdd(q->data)) { //�ҵ�����
                p->link = q->link;  //����ȥ
                delete(q);  //ɾ���ý��
                q = p;
            }
            else {  //����Ϊ��β�˲�ͣ������
                return head;
            }
        }
    }
    
}

void out_link(node* head)
{
    if (head == NULL) cout << "����Ϊ��\n";
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
    head = createRandLink();
    cout << "ԭ����\n";
    out_link(head);

    head = deleteOddNode(head);
    cout << "ɾ���������\n";
    out_link(head);
    return 0;
}

#endif