#if 0
#include <iostream>
using namespace  std;
#define MAX 50
struct stack
{
	int x, y, d;    //d�����ã�
};

struct Move //���ĸ�������
{
	int a, b;
};
int maze[MAX][MAX];
int mark[MAX][MAX];
Move mv[8];
stack s[MAX * MAX];
int top;

void setmove()  //���ú÷���
{
	mv[0].a = -1;    mv[0].b = 0;
	mv[1].a = -1;    mv[1].b = 1;
	mv[2].a = 0;    mv[2].b = 1;
	mv[3].a = 1;    mv[3].b = 1;
	mv[4].a = 1;    mv[4].b = 0;
	mv[5].a = 1;    mv[5].b = -1;
	mv[6].a = 0;    mv[6].b = -1;
	mv[7].a = -1;    mv[7].b = -1;
}

//�����Զ�����Թ�
void inputmaze(int m, int n)
{
	int i, j;
	cout << "Input maze : \n";
	for (i = 0; i <= m + 1; i++)
		for (j = 0; j <= n + 1; j++)
			maze[i][j] = 1; //��ʼ����ȫ��Ϊ1
	for (i = 1; i <= m; i++)
	{
		for (j = 1; j <= n; j++)
			cin >> maze[i][j];  //�߿���Ϊ1���м������
	}
}

//����Թ��������߽���Զ����
void outputmaze(int m, int n)
{
	int  i, j;
	cout << "Output maze: \n";
	for (i = 0; i <= m + 1; i++)
	{
		for (j = 0; j <= n + 1; j++)
			cout << maze[i][j];
		cout << endl;
	}
}

//�ѵ��Ǽ�¼�켣�õģ�������û�б����ʣ�
void setmark(int m, int n)
{
	int i, j;
	for (i = 0; i <= m + 1; i++)
		for (j = 0; j <= n + 1; j++)
			mark[i][j] = 0;
}

int getmazepath(int m, int n)
{
	int  i, j, k, g, h, t;
	if (maze[1][1] != 0 || maze[m][n] != 0)
		return (1);
	s[0].x = 1;
	s[0].y = 1;
	s[0].d = 1; //���1,1
	top = 1;
	mark[1][1] = 1;
	while (top > 0)
	{
		i = s[--top].x; //����Ҳ�����top--�����ؿ���
		j = s[top].y;
		k = s[top].d;   //�̳���һ��ǰ���ķ��򣬽���������������Ϊ���������Ǵ�0~7��
		while (k < 7)   //������Ҿ�һֱ����ȥ
		{
			g = i + mv[++k].a;
			h = j + mv[k].b;//i,j�������ڵ�λ�ã�g,h������һ����λ�ã�

			//�ҵ��յ�
			if (g == m && h == n)
			{
				cout << "path in maze:\n";
				for (t = 0; t < top; t++)
					cout << s[t].x << "  " << s[t].y << endl;
				cout << i << "  " << j << endl;
				cout << m << "  " << n << endl;
				return(0);
			}
			//��һ��������
			if (maze[g][h] == 0 && mark[g][h] == 0)
			{
				mark[g][h] = 1;
				s[top].x = i;
				s[top].y = j;
				s[top++].d = k;
				i = g;
				j = h;
				k = -1; //ˢ��k������һ����ʱ�ӵ�һ������ʼ��
			}
		}  /* while k  */
	} /*while  top  */
	return (1);
}

int main() {
	int m, n;
	cout << "input m n\n";
	cin >> m >> n;
	setmove();
	inputmaze(m, n);
	outputmaze(m, n);
	setmark(m, n);
	if (getmazepath(m, n)) cout << "Error! No path!\n";
	return 1;
}
#endif