//#include  <iostream>
//using namespace  std;
//struct  NODE {
//    int  data;
//    NODE* link;
//};
//NODE* create_link()
//{
//    int /*i,*/ n;
//    NODE* head = NULL, * p, * q;
//    p = head;
//    //if (n == 0) return(NULL);
//    cin >> n;
//    while (n != -9999)/*for (i = 1; i < n; i++)*/
//    {
//        if (head == NULL) {
//            head = new NODE;
//            head->data = n;
//            head->link = NULL;
//            p = head;   //pֻ��Ҫָ��head����
//            cin >> n;   //������Ҫһ��cin����Ȼ��һ���ͻᴴ������
//        }
//        else {
//            q = new NODE;   //��q������Ȼ��p��ָ
//            q->data = n;
//            q->link = NULL;
//            p->link = q;
//            p = q;
//            cin >> n;
//        }
//        p->link = NULL;
//    }
//    //cin >> p->data;
//
//    return(head);
//}
//
//void* insert_link(NODE*& head) {
//    int loc;
//    cout << "Where do you want to insert?\n";
//    cin >> loc;
//    loc -= 1;
//    NODE* pos = head;
//
//    //insert
//    int num;
//    cout << "please input the number\n";
//    cin >> num;
//    NODE* q = new NODE;
//    q->data = num;
//    if (loc == -1) {    
//        q->link = head;
//        head = q;   
//    }
//    else {
//        //find the position
//        while (pos->link != NULL && loc) {  
//            pos = pos->link;                        
//            loc--;
//        }
//        q->link = pos->link;
//        pos->link = q;
//    }
//    return head;
//}
//
//void out_link(NODE* head)
//{
//    while (head != NULL)
//    {
//        cout << head->data << "-->";
//        head = head->link;
//    }
//    cout << endl;
//}
//
//NODE* reverse_link(NODE* head) {
//    if (head == NULL || head->link == NULL) return head; //�ձ����ֻ��һ������൱�ڲ���Ҫ��ת
//    NODE* p = head->link;
//    NODE* q = p->link;
//    head->link = NULL;
//    while (q != NULL) { 
//        p->link = head; //�����м䡱���ָ����һ�����
//        head = p;   //���������൱�ڰ�������ָ����������ƶ�һ��
//        p = q;
//        q = p->link;    //p->link����q->link��һ������p->linkΪ�˷������
//    }
//    p->link = head; //���һ����㻹û�����������ڶ�������
//    return p;
//}
//
//
//NODE* delete_link(NODE* head, int a) {
//    if (head == NULL) { //����Ϊ��ʱ
//        cout << "����Ϊ�գ�\n";
//        return head;
//    }
//    NODE* q = head;
//    if (q->data == a) { //ɾ������ͷ���
//        head = q->link; //����ǰ���Ѿ�����head��㣬����ֱ�ӽ���ȥ����ɾ��
//        delete(q);
//        return head;
//    }
//    else {  //ɾ�������м���
//        NODE* p = head;    //���ã�ָ��Ҫɾ���Ľ��
//        while (q->data != a && q->link != NULL) {   //Ϊ���ҵ�ƥ��Ľ��
//            p = q;
//            q = q->link;
//        }
//        if (q->data == a) { //����Ϊ�ҵ��˲�ͣ������
//            p->link = q->link;  //����ȥ
//            delete(q);  //ɾ���ý��
//            return head;
//        }
//        else {  //����Ϊ��β�˲�ͣ������
//            cout << "δ�ҵ���Ӧ�Ľ�㣡\n";
//            return head;
//        }
//    }
//}
//
//
//int main()
//{
//    NODE* head;
//    head = create_link();
//    out_link(head);
//    head = reverse_link(head);
//    //head = delete_link(head, 3);
//    //insert_link(head);
//    out_link(head);
//    return 1;
//}
