#if 0
#include  <iostream>
using namespace  std;
struct  NODE {
    int  data;
    NODE* link;
};
NODE* create_link(/*int n*/)
{
    int /*i,*/ n;
    NODE* head = NULL, * p, * q;
    p = head;
    //if (n == 0) return(NULL);
    cin >> n;
    while (n != -9999)/*for (i = 1; i < n; i++)*/
    {
        if (head == NULL) {
            head = new NODE;
            head->data = n;
            head->link = NULL;
            p = head;   //pֻ��Ҫָ��head����
            cin >> n;   //������Ҫһ��cin����Ȼ��һ���ͻᴴ������
        }
        else{
            q = new NODE;   //��q������Ȼ��p��ָ
            q->data = n;
            q->link = NULL;
            p->link = q;
            p = q;
            cin >> n;
        }
        p->link = NULL;
    }
    //cin >> p->data;
    
    return(head);
}

void insert_link(NODE *head) {
    int loc;
    cout << "Where do you want to insert?\n";
    cin >> loc;
    loc -= 1;
    NODE* pos = head;
    
    //about head
   /* if (loc == -1) {
        int num;
        cout << "please input the number\n";
        cin >> num;
        NODE* q = new NODE;
        q->data = num;
        q->link = head;
        head = q;
    }*/

    //insert
    int num;
    cout << "please input the number\n";
    cin >> num;
    NODE* q = new NODE;
    q->data = num;
    if (loc == -1) {    //problem: �޷�ͬ�������ݵĲ���ָ����
        q->link = head;
        head = q;   //Ϊʲô������ı䣿���ݵ���ָ�룬����Ҫ����ָ�룿
    }
    else {
        //find the position
        while (pos->link != NULL && loc) {  //Ϊʲô��������NULL����Ϊ��
            pos = pos->link;                         //������ֱ����pos++
            loc--;
        }
        q->link = pos->link;
        pos->link = q;
    }
    return;//head;
}

void out_link(NODE* head)
{
    while (head != NULL)
    {
        cout << head->data << "-->";
        head = head->link;
    }
    cout << endl;
}

NODE* delete_link(NODE* head, int a) {
    if (head == NULL) { //����Ϊ��ʱ
        cout << "����Ϊ�գ�\n";
        return head;
    }
    NODE* q = head;
    if (q->data == a) { //ɾ������ͷ���
        head = q->link; //����ǰ���Ѿ�����head��㣬����ֱ�ӽ���ȥ����ɾ��
        delete(q);
        return head;
    }
    else {  //ɾ�������м���
        NODE* p = head;    //���ã�ָ��Ҫɾ���Ľ���ǰ��
        while (q->data != a && q->link != NULL) {   //Ϊ���ҵ�ƥ��Ľ��
            p = q;
            q = q->link;
        }
        if (q->data == a) { //����Ϊ�ҵ��˲�ͣ������
            p->link = q->link;  //����ȥ
            delete(q);  //ɾ���ý��
            return head;
        }
        else {  //����Ϊ��β�˲�ͣ������
            cout << "δ�ҵ���Ӧ�Ľ�㣡\n";
            return head;
        }
    }
}



int main()
{
    NODE* head;
    head = create_link();
    out_link(head);
    insert_link(head);
    out_link(head);

    delete_link(head, 5);
    out_link(head);
    return 1;
}

#endif