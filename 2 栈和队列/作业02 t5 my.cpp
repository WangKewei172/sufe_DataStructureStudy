#if 0
#include<iostream>
#include<stack>
constexpr int MAX = 50;	//�����Թ����߳�
constexpr int DIR = 4;	//������
using namespace std;

struct Move {
	int a, b;	//a--�У������ߣ���b--�У������ߣ�
};

struct point {	//��ʾ�Թ��ĵ㣬�����������һ���ߵķ���
	int x, y, d;//x:�У�y:�У�d:����0~DIR - 1)
	point(int a, int b, int c) {	//���캯������������
		x = a; y = b; d = c;
	}
	void makePoint(int a, int b, int c) {	//��ֵ�õĺ�������������
		x = a; y = b; d = c;
	}
};

class Maze {
public:
	char board[MAX][MAX];	//�����Թ������ӣ�������Ҫ��·���*������������char
	int mark[MAX][MAX];	//���߹�����1��û�о���0����ʵboolҲ�У����ڲ����ܳ��֡�һ����ͨ��·��һ��ͨ��·��������һ�㡱�����Ա��1����1��
	int m = 0, n = 0;	//�Թ��Ĵ�С��m:��,n:�У���Ϊ�ı�
	Move mv[DIR];	//�ߵķ��򡪡��������ң�DIR�Ƿ�������������ܲ�ֹ����������
	stack<point> s;	//����Ѱ��·��ջ�����Ҫô��������·��ҪôΪ�ձ�ʾ�Ҳ���·��

	Maze(int a, int b);	//���캯������ʼ���߽���ڲ���С�������ƶ�����
	void refreshMaze();	//��������������ҵ������յ��·�󣬰�����·����*��
	void createMaze();	//�����Զ�����Թ�
	void outputMaze();	//����Թ��������߽磩
	int getPath(int beg_a, int beg_b, int end_a, int end_b);	//����·����ǰ������������㣬���������յ㡣���������Ӹ���������
};


//���캯������ʼ���߽���ڲ���С
Maze::Maze(int a, int b) {
	m = a; n = b;
	for (int i = 0; i < m + 2; i++) {
		for (int j = 0; j < n + 2; j++) {
			board[i][j] = '1';	//�����еİ����߽�ĸ��ӳ�ʼ��Ϊ1
			mark[i][j] = 0;	//���еĸ��Ӷ����Ϊδ�߹�
		}	
	}

	mv[0].a = 0; mv[0].b = -1;	//����
	mv[1].a = 1; mv[1].b = 0;	//����
	mv[2].a = -1; mv[2].b = 0;	//����
	mv[3].a = 0; mv[3].b = 1;	//����
}

//��·�߱��*
void Maze::refreshMaze() {
	while (!s.empty()) {
		int a = s.top().x; 
		int b = s.top().y;
		board[a][b] = '*';
		s.pop();
	}
}

//�����Թ��ڲ�
void Maze::createMaze(){
	cout << "input maze:\n";
	for (int x = 1; x <= m; x++)
		for (int y = 1; y <= n; y++)
			cin >> board[x][y];
}

//����Թ�
void Maze::outputMaze() {
	cout << "output maze:\n";
	for (int i = 0; i <= m + 1; i++) {
		for (int j = 0; j <= n + 1; j++) {
			cout << board[i][j] << " ";
		}
		cout << "\n";	
	}
	cout << "\n";
}

//�õ�·��,beg_a:��������������꣩��beg_b:��������������꣩
int Maze::getPath(int beg_a, int beg_b, int end_a, int end_b) {
	beg_a = 1; beg_b = n;	//��㣺���ϣ��յ㣺����
	end_a = m; end_b = 1;	//������Ŀ�������յ㶼�Ѿ�ȷ�������Ծ�������д���ˣ����۴�����ʲô������

	if (board[1][n] == '1' || board[m][1] == '1') return 1;	//�������յ��е����˵ģ�ֱ�ӷ���
	point tem_p(beg_a, beg_b, -1);	//��ʼ��
	s.push(tem_p);		//�Ƚ����ѹ��ջ
	mark[beg_a][beg_b] = 1;	//����߹���

	int nowRow, nowCol;	//���ڵ��к���
	int nextRow, nextCol; //��һ��������к���
	int dir;	//������

	tem_p.makePoint(0, 0, -1); s.push(tem_p);	//�ȼ�һ�����ȥ�����������whileѭ���жϣ�Ϊ�˴ճ�while��

	//�˴�ʹ��DFS
	while (1) { //ջ����
		s.pop();	//������������·�в�ͨ�����˻�ȥһ�񣬿�����û����������
		if (s.empty()) return 1;//���ջ���ˣ�ֱ�ӽ���
		nowRow = s.top().x;
		nowCol = s.top().y;	//������������Ϊ������һ��������
		dir = s.top().d;	//�����ϴεķ������������ȥ

		while (dir < DIR - 1) {	//����ÿһ����������dir�Ǵ�-1��ʼ��������++dir���ȼ��ٸ�ֵ�ģ�������DIRҪ-1
			nextRow = nowRow + mv[++dir].a;
			nextCol = nowCol + mv[dir].b;	//��һ���ߵ�������
			if (nextRow == end_a && nextCol == end_b) {	//�ҵ����յ�
				if (s.top().x == 0 && s.top().y == 0) s.pop();	//�����������ö�����һ�����ȥ
				tem_p.makePoint(nowRow, nowCol, dir); s.push(tem_p);
				tem_p.makePoint(nextRow, nextCol, dir); s.push(tem_p);	//���յ�Ҳ�ƽ�ȥ
				refreshMaze();	//��·���*
				outputMaze();	//��������Թ�
				return 0;	//�ǵ�ֱ�ӽ���
			}
			if (board[nextRow][nextCol] == '0' && mark[nextRow][nextCol] == 0) {	//���λ�ÿ����ߣ�����û�߹�
				mark[nextRow][nextCol] = 1;	//�����Ҫ����

				s.top().x = nowRow;
				s.top().y = nowCol;	//����ĸ�����һ�֡��ͺ��ԡ��������൱����ǰ�����¸���
				s.top().d = dir;	//���µ�ǰ��λ�ķ���
				
				tem_p.makePoint(0, 0, -1);	s.push(tem_p);//������ͺ���
				nowRow = nextRow; nowCol = nextCol;	//�ѵ�ǰ�������Ϊ��һ������
				dir = -1;	//�ѷ���Ҳ����һ��
			}
		}
	}
	return 1;
}

int main() {
	int m, n;
	cout << "input m n:\n";
	cin >> m >> n;

	Maze mz(m, n);
	mz.createMaze();
	mz.outputMaze();
	if (mz.getPath(1, n, m, 1)) {	//��Ϊ����ֵΪ1�Ļ����ͱ�ʾ�������ɣ���Ϊ����ģ�
		cout << "Error! No path!\n";
	}
	return 0;
}

#endif