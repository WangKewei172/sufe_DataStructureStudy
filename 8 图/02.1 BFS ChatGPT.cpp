#if 0
/**

@file bfs.cpp
@brief ������������㷨
@author ·Զ
*/
#include <iostream>

using namespace std;

//! �������ֵ
#define MAXN 50

//! ����ṹ��
struct L_node {
int ver; //! ����
L_node *link; //! ָ����һ������ָ��
};

//! ����ṹ������
L_node *head[MAXN];

//! ������չ���
struct E_node {
int ver1, ver2; //! ����1�Ͷ���2
};

//! ������չ�������
E_node e[MAXN];

//! �������
int n, m, u;

//! �����������
struct qtype {
int qa, qe; //! ���п�ʼ�Ͷ��н�����λ��
int item[MAXN]; //! �����е���
};

//! ���������������㷨
void bfs(int u)
{
//! �������
qtype queue;
//! ���嶥�����
int v, w;
//! ����ָ�����ָ��
L_node *t;

Copy code
//! �������
cout << u;
//! ���ʶ���
visit[u] = 1;
//! ��ʼ������
queue.qa = 0;
queue.qe = 0;
//! ��һ����������
queue.item[0] = u;
//! �����л�����δ����
while (queue.qa <= queue.qe)
{
    //! ȡ�������е�һ����
    v = queue.item[queue.qa++];
    //! ָ����һ�����
    t = head[v];
    //! ����ǰ����ÿ����չ���
    while (t != NULL)
        
}

#endif