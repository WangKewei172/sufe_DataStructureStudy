#if 0
# include <iostream>
# include <stack>
using namespace std;
#define MAXN 100
struct node {
	char data;
	node* lchild;	//ָ�����ӽ��
	node* rchild;	//ָ�����ӽ��
};
struct lrnode {
	char data;
	char ltag, rtag;	//ֵΪ0˵���ж�Ӧ�Ľ�㣬Ϊ1˵��û��
};
node* transfer(lrnode  tree[], int n)
{
	node* stack[MAXN], * root, * p, * q;
	int top, i;
	if (n == 0) return(NULL);
	root = new  node;
	p = root;
	top = 0;
	for (i = 0; i < n - 1; i ++)
	{
		p->data = tree[i].data;

		if (tree[i].rtag == '0')
			stack[top++] = p;	//��ջ
		else 
			p->rchild = NULL;

		q = new node;

		if (tree[i].ltag == '0')
			p->lchild = q;
		else {
			p->lchild = NULL;
			p = stack[--top];	//��ջ
			p->rchild = q;
		}

		p = q;
	}
	p->data = tree[n - i].data;
	p->lchild = NULL;
	p->rchild = NULL;
	return(root);
}

// �ҵ����ڵ㡣
// ����ͨ��ջ��ģ�����������ת�����Ӷ��ó����ڵ�
lrnode* findFatherNode(lrnode tree[], char a, int length) {	//����ı���Ϊ������2����־λ������������a��ֵ�����Ľ����
	stack<lrnode*> treeStk;
	if (tree == NULL || tree[0].data == a) {
		cerr << "�Ҳ������ڵ㣡\n";
		return NULL;	//����������ڻ���û�и��ڵ㣬���ؿգ�
	}

	int i = 0;
	for (; i < length; i++) {	///ģ�⽨��
		if (tree[i].data == a) break;	//�ҵ���
		if (tree[i].rtag == '0') 
			treeStk.push(&tree[i]);	//������������ӽ�㣬����ջ

		if (tree[i].ltag == '1')	//���������û�����ӽ�㣬˵����һ��������ĳ���������ӽ��
			treeStk.pop();
	}

	if (i == length || i == 0) {	//û���ҵ�ֵΪa�Ľ��
		cerr << "û���ҵ�ֵΪa�Ľ���Ϊ����㣡\n";
		return NULL;
	}
	else {
		if (tree[i - 1].ltag == '0') //˵�����������ϸ������ӽ��
			return &tree[i - 1];
		else if (!treeStk.empty())	//���ջ���գ���������д�
			return treeStk.top();	//�����һ�����û�����ӽ�㣬˵��������ĸ��ڵ���ջ��
		else
			return NULL;
	}
}

//�������鴴�����������ң�
//�������Ľ�������������飬���־λ���飬�ұ�־λ����
void makeTree(lrnode tree[], int n, char dataA[], char ltagA[], char rtagA[]) {
	for (int i = 0; i < n; i++) {
		tree[i].data = dataA[i];
		tree[i].ltag = ltagA[i];
		tree[i].rtag = rtagA[i];
	}
}
int main() {
	lrnode tree[MAXN];
	char dataA[] = "ABDFCEGH";
	char ltagA[] = "01010011";
	char rtagA[] = "00111101";

	char a = 'G';

	makeTree(tree, 8, dataA, ltagA, rtagA);
	lrnode *tem = findFatherNode(tree, a, 8);
	if (tem != NULL) {	// ������ֵΪ�գ�˵���д�
		cout << "���ڵ�ĵ�ַ��" << tem << endl;
		cout << "���ڵ��ֵ��" << tem->data << endl;
	}
	else
	{
		cerr << "�д����޸ģ�\n";
	}
}
#endif