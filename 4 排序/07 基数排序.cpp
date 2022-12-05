#if 0
#include<iostream>
constexpr auto N = 10;	//��10��Ͱ��0~9;
constexpr auto DIG = 4;	//���λ��Ϊ4;
using namespace std;


struct node { 
    int data;
    node* link;
};

//���ã���ȡa�ĵ�����n + 1λ����
int getNNum(int a, int n) {
    while (n--)
        a = a / N;  //�����N������10��Ϊ��ʹ����ͳһ
    return a % N;
}

void radixSort(node* arr) {
    if (arr == NULL) return;

    node* p = arr;
    for (int i = 0; i < DIG; i++) { //��4��
        node* head[N] = { NULL };  //ʮ��Ͱ��ͷ��� һ��Ҫ�������棬�൱�ڳ�ʼ����
        node* tail[N] = { NULL };  //ʮ��Ͱ��β���

        p = arr;    //�ӿ�ͷ��ʼ
        while (p != NULL) { //��Ͱ����һ���Ƿǳ�����Ĵ����½��Ȼ��ӵ�����ĩβ�Ĳ���
            int temp = getNNum(p->data, i); //��ȡ���ִζ�Ӧ��λ����ֵ
            if (head[temp] == NULL) {   //���ͷ���Ϊ��
                head[temp] = new node;  //����ͷ���
                head[temp]->data = p->data; //��ֵ
                head[temp]->link = NULL;    //��ֵ
                tail[temp] = head[temp];    //����β���
            }
            else {
                node* q = new node; //����һ���½��
                q->data = p->data;  //���½�㸳ֵ
                q->link = NULL;     //ͬ��
                tail[temp]->link = q;   //����β���
                tail[temp] = q; //����β���
            }
            p = p->link;    //ָ����һ����
        }

        //��Ͱ
        p = arr;
        for (int j = 0; j < N; j++) {   //j����Ͱ��Ӧ����   
            node* tmp = head[j];
            while (tmp != NULL && p != NULL) {
                p->data = tmp->data;    //����ʽ���
                p = p->link;
                tmp = tmp->link;
            }
        }
    }
}

//�����������
node* createRandLink()
{
    srand((unsigned int)time(NULL));
    node* head = NULL, * p, * q;
    int n = rand() % 15;   //nΪ������������

    if (N == 0) return NULL;

    head = new node;
    p = head;
    p->data = n;
    p->link = NULL;

    for (int i = 1; i < N; i++) {
        q = new node;
        q->data = rand() % 9999;  //�����
        q->link = NULL;
        p->link = q;
        p = q;
    }
    return head;
}

void printLink(node* head) {
    node* p = head;
    while (p != NULL) {
        cout << p->data << " -> ";
        p = p->link;
    }
    cout << "\n";
}

int main() {
    node* arr = createRandLink();
    printLink(arr);

    radixSort(arr);
    printLink(arr);
    return 0;
}
#endif