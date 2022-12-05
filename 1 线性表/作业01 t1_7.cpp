#if 0
#include<iostream>
using namespace std;

struct node {
    int coef, exp;
    node* link;
};

node* createPoly(node *head, int num)
{
    if (head == NULL) {
        head = new node;
        head->coef = 0;
        head->exp = -1;
        head->link = head;
    }
    node* p = head, * q;   //pָ�����һ����㣬qָ���µĽ��
    int n;
    cout << "���������Ϊ��"<< num << "��ϵ��������-9999��ǰֹͣ����";
    cin >> n;
    while (n != -9999) {
        q = new node;
        q->coef = n;
        q->exp = num;
        q->link = head; //�����½��q�����丳ֵ      

        p->link = q;
        p = q;  //���½�����
        
        num--;  //����λ��������Ҫ
        if (num < 0) break;
        cout << "���������Ϊ��" << num << "��ϵ��������-9999��ǰֹͣ����";
        cin >> n;
    }
    return head;
}

void outputPoly(node* head) {   //�������ʽ
    bool isFirst = true;
    if(head->exp == -1) head = head->link;
    while(head->exp != -1) {  //ִ�����headΪҪ��������һ�����
        if (head->coef == 0) {
            head = head->link;
            continue;
        }
        else if (head->coef > 0 && head->exp != 0) {
            if (isFirst) {	//����Ƕ���ʽ�ĵ�һ��
                cout << head->coef << "x^" << head->exp;
                isFirst = false;
            }
            else {
                cout << " + " << head->coef << "x^" << head->exp;
            }
        }
        else if(head->coef < 0 && head->exp != 0) {
    		if (isFirst) {	//����Ƕ���ʽ�ĵ�һ��
    			cout << "-"<< -head->coef << "x^" << head->exp;	//���ڸ��ź�������һ�𲻱��ڹ۲죬�������ͳһ��ʽ
    			isFirst = false;
    		}
    		else {
    			cout << " - " << -head->coef << "x^" << head->exp;
    		}
        }
        else if (head->exp == 0) {  //Ӧ�ÿ���ֱ��else�������������������else if
            if (head->coef > 0) {
                if (isFirst) {
                    cout << head->coef;
                }
                else
                    cout << " + " << head->coef;
            }
            else if (head->coef < 0) {
                if(isFirst)
                    cout << -head->coef;
                else
                    cout << " - " << -head->coef;
            }
        }
        head = head->link;
    }
    cout << "\n\n";
}

void insertPoly(node*& c,int coef, int exp) {
    node* a = c;
    while (a->link->exp != -1) {
        a = a->link;
    }
    node* p = new node;
    p->coef = coef; p->exp = exp; p->link = c;
    a->link = p;
}

void addAndSubPoly(node*a, node*b, node*& c, node*& d) {    //ʹ��ָ������
    if (a->exp = -1) a = a->link;   //��ֹ������Ϊͷ��㣬Ȼ������ѭ��
    if (b->exp = -1) b = b->link;

    while (a->exp != -1 && b->exp != -1) {  //a��b
        if (a->exp == b->exp) { //����ƥ��
            insertPoly(c, a->coef + b->coef, a->exp);
            insertPoly(d, a->coef - b->coef, a->exp);

            a = a->link; b = b->link;   //����
        }
        else if (a->exp > b->exp) {
            insertPoly(c, a->coef, a->exp);
            insertPoly(d, a->coef, a->exp);
            b = b->link;
        }
        else {  //a->exp < b->exp
            insertPoly(c, b->coef, b->exp);
            insertPoly(d, b->coef, b->exp);
            a = a->link;   //����
        }
    }
    while (a->exp != -1)	//b���˵�
    {
        insertPoly(c, a->coef, a->exp);
        insertPoly(d, a->coef, a->exp);
        a = a->link;
    }
    while (b->exp != -1)	//a���˵�
    {
        insertPoly(c, b->coef, b->exp);
        insertPoly(d, b->coef, b->exp);
        b = b->link;
    }
}


int main() {
    node* ah = NULL, *bh = NULL;
    ah = createPoly(ah, 3);
    cout << "����ʽa��\n";
    outputPoly(ah);

    bh = createPoly(bh, 3);
    cout << "\n����ʽb��\n";
    outputPoly(bh);

    node* ch, * dh; //��������ʼ�������������
    ch = new node; dh = new node;
    ch->link = ch; dh->link = dh;
    ch->exp = -1; dh->exp = -1;
    ch->coef = dh->coef = 0;

    addAndSubPoly(ah, bh, ch, dh);
    cout << "\na + b��\n";
    outputPoly(ch);
    cout << "\na - b��\n";
    outputPoly(dh);
    
    return 0;
}
#endif