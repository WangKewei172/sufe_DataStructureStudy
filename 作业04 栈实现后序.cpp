#if 0
#include<iostream>
#include<stack>
using namespace std;

//node�Ľṹ
struct node {
	int data;
	node* leftChild;	//���ӽ��
	node* rightChild;	//���ӽ��
};

void stackPrintTree(node* head) {
	if (!head) return;
	stack<node*> bs;
	bs.push(head);	// ѹ������

	node* p = head;	// 

	while (!bs.empty()) {
		head = bs.top();

	}
}

int main() {

}
#endif