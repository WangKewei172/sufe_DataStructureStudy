#if 0
#include<iostream>
#define  MAXN  50
#define MAXM 100
using namespace std;

/**
 * @file   main.cpp
 * @author
 * @date
 * @brief
 */

#include<iostream>
using namespace std;

// ������������ͱ���
#define  MAXN  50
#define MAXM 100

// ��������������
struct  L_node {
    int ver;  // ���ı��
    L_node* link;  // ָ����һ������ָ��
};

// ����ͼ�бߵĽṹ��
struct  E_node {
    int ver1, ver2;  // �ߵ��������
};

// ��������ͷ����
L_node* head[MAXN];

// ���������
E_node  e[MAXM];

//������ʹ�������
int visit[MAXN];

// �������������������ʼ�����
int n, m, u;

// �������ڴ����ڽӱ�
// ���룺����ͷ���顢�������������顢����
/**
 * .
 * 
 * \param head ����ͷ����
 * \param n ������
 * \param e ������
 * \param m ����
 */
void create_adj_list(L_node* head[], int n, E_node e[], int m)
{
    // ������ʱ����
    int i, u, v;
    L_node* p;

    // ��ʼ������ͷ����
    for (i = 1; i <= n; i++)
        head[i] = NULL;

    // ����������
    for (i = 0; i < m; i++)
    {
        // ��ȡ�ߵ��������
        u = e[i].ver1;
        v = e[i].ver2;

        // �����½��
        p = new L_node;
        p->ver = v;  // ���ý����

        // ���½�����u��������
        p->link = head[u];
        head[u] = p;

        // �����½��
        p = new L_node;
        p->ver = u;  //
    }
}

// �������ڿ����������
// ���룺��ʼ�����u

void bfs(int u)
{
    // �������
    struct  qtype {
        int qa;  // ���еĶ�ͷָ��
        int qe;  // ���еĶ�βָ��
        int item[MAXN];  // ��������
    };

    // ������ʱ����
    int v, w;
    L_node* t;

    // �������
    qtype  queue;

    // �����ʼ���ı��
    cout << u;

    // ��ǽ��u�ѱ�����
    visit[u] = 1;

    // ��ʼ������
    queue.qa = 0;
    queue.qe = 0;
    queue.item[0] = u;

    // ѭ����������
    while (queue.qa <= queue.qe)
    {
        // ��ȡ��ͷ���ı��
        v = queue.item[queue.qa++];

        // ָ��ָ����v������ͷ���
        t = head[v];

        // ѭ���������v������
        while (t != NULL)
        {
            // ��ȡ���ı��
            w = t->ver;

            // ������wû�б����ʣ�����������
            if (visit[w] == 0)
            {
                // ��������
                cout << w;

                // ��ǽ��w�ѱ�����
                visit[w] = 1;

                // �����w�������
                queue.item[++queue.qe] = w;
            }

            // ָ��ָ����һ�����
            t = t->link;
        }
    }
}

int main() {
    create_adj_list(head, 3, e, 2);
}

#endif