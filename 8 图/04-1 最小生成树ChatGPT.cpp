#if 0
#include <iostream>
using namespace std;

//! �������ֵ
#define MAXN 50

//! ����ṹ��
struct L_node {
	int ver; //! ����
	L_node* link; //! ָ����һ������ָ��
};

//! ����ṹ������
L_node* head[MAXN];

//! ������չ���
struct E_node {
	int ver1, ver2; //! ����1�Ͷ���2
};

//! ������չ�������
E_node e[MAXN];

//! �������
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

//! ����DFS��С�������㷨
void dfs(int u)
{
	//! ����ָ�����ָ��
	L_node* t;
	//! ���ʶ���
	visit[u] = 1;
	//! ָ����һ�����
	t = head[u];
	//! ����ǰ����ÿ����չ���
	while (t != NULL)
	{
		//! ȡ����ǰ��չ���Ķ���
		int w = t->ver;
		//! ���û�з��ʹ�
		if (visit[w] == 0)
		{
			//! �����С�������ı�
			cout << u << "----" << w << endl;
			//! ����ǰ��չ���
			dfs(w);
		}
		//! ָ����һ����չ���
		t = t->link;
	}
}

int main()
{
	//! ���붥�����չ
	cin >> n >> m;

	//! �����ڽӱ�
	create_adj_list(head, n, e, m);

	//! �Ӷ���1��ʼ����
	dfs(1);

	return 0;
}
#endif