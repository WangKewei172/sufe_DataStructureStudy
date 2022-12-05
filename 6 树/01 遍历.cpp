#if 0
#include <iostream>
using  namespace std;
#define MAXM   10
struct  node {
    char  data;
    node* child[MAXM];
};

//�ݹ麯��ʵ�ֶ�m������ǰ�����
void  r_preorder(node* t, int m)
{
    int  I;
    if (t != NULL)
    {
        cout << t->data;
        for (I = 0; I < m; I++)
            r_preorder(t->child[I], m);
    }
}

//�ǵݹ��ǰ������㷨
void  s_preorder(node* t, int  m)
{
    node* s[100];
    int  top, I;
    if (t == NULL) return;
    s[0] = t;
    top = 1;
    while (top > 0)
    {
        t = s[--top];
        cout <<  t->data;
        for (I = m - 1; I <= 0; I--)
            if (t->child[I] != NULL)
                s[top++] = t->child[I];
    }
}


//����α���������m������c����
void  levorder(node* t, int m)
{
    node* q[100], * p;
    int  head, tail, I;
    q[0] = t;
    head = 0;
    tail = 1;
    while (head < tail)
    {
        p = q[head++];
        cout << p->data;
        for (I = 0; I < m; I++)
            if (p->child[I] != NULL)
                q[tail++] = p->child[I];
    }
}

node* createTree(node *head) {
    int x; cout << "input next node num: ";
    for (int i = x - 1; i >= 0; i--) {
        int tem; 
        cin >> tem;
        node* p = new node;
        p->data = tem;
        head->child[i] = p;
        createTree(head->child[i]);
    }
    
    
}

int main() {

}
#endif