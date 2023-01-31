#if 0
#include<iostream>
constexpr int MAXN = 100;
using namespace std;

//��ǰ����ʽ��Ž�㸽�����־λ����ָ�룬�Խṹ���������ʽ������
struct node {
	char data;	// ����ֵ
	int ltag;	// ���������0��˵�������������������������1�����ʾ��û�����ӽ��
	int rchild;	// ���ӽ���λ�ã������Ϊ-1����˵����û���ҽڵ�
};

// ��׼��ʽ����Ķ�����
struct bnode {
public:
	char data;	//ֵ
	bnode* lbnode;	//����
	bnode* rbnode;	//�ҽ��
};

void createPreTree(node tree[]) {
	char ndata[] = "abdfghce";
	int nltag[] = { 0,0,1,0,1,1,1,1 };
	int nrchild[] = { 6,-1,3,5,-1,-1,7,-1 };
	for (int i = 0; i < 8; i++) {
		tree[i].data = ndata[i];
		tree[i].ltag = nltag[i];
		tree[i].rchild = nrchild[i];
	}
}

//������ֵ�����û���ٿռ�Ϳ���
void createBNode(bnode*& bhead, char c, bnode* l, bnode* r) {
	if (bhead == NULL)
		bhead = new bnode;
	bhead->data = c;
	bhead->lbnode = l;
	bhead->rbnode = r;
}

//�������־λ����ָ�� ת��Ϊ ��׼��ʽ����
bnode* convertPreToBin(int pos, node tree[]) {
	bnode* bhead = new bnode;
	bhead->data = tree[pos].data;	//�Ըý�㸳ֵ

	if (tree[pos].ltag && tree[pos].rchild == -1) {	//���Ҷ�Ϊ��
		bhead->lbnode = NULL;
		bhead->rbnode = NULL;
		return bhead;
	}
	if (!tree[pos].ltag) {	// ���ӽ�����
		bhead->lbnode = convertPreToBin(pos + 1, tree);	//����һ���������ӽ��
	}
	if (tree[pos].rchild != -1) {	//���ӽ�����
		bhead->rbnode = convertPreToBin(tree[pos].rchild, tree);	//�������ӽ���λ��
	}
	return bhead;
}

int main() {
	node tree[MAXN];
	createPreTree(tree);

	bnode* head = convertPreToBin(0, tree);
	cout << tree[0].data;
}
#endif