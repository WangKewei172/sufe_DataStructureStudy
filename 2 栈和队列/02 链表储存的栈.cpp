#if 0
#include  <iostream>
using namespace  std;
struct NODE {
	char data;
	NODE* link;
};
NODE* top = NULL;
void push_l(char x) //��ջ
{
	NODE* p;
	p = new(NODE);
	p->data = x;
	p->link = top;  //����һ���½�㣬��ֵ������
	top = p;    //����ջ��ָ��
}

int pop_l(char* p_y)    //��ջ
{
	NODE* p;
	if (top == NULL)  return(1);    //���ջ�վͲ��ܳ�ջ
	*p_y = top->data;
	p = top;    //����ջ����ָ��
	top = top->link;    //��ջ
	delete p;   //����ԭջ���ռ�
	return(0);
}
#endif