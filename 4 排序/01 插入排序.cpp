#if 0

#include <iostream>
using namespace std;

//������鳤��
////int len = getLength(a);	//��ȡ���鳤��
//template<class T>
//int getLength(T a[]) {
//	int i = 0;
//	while(a[i] != '\0')
//		i++;
//	return i + 1;
//}

//����n�������뵽ǰ��n-1���ź����������
void insertionSort(int a[], int len) {
	for (int i = 1; i < len; i++) {	//���������ڶ������������
		for (int j = i; j > 0; j--) {	//�����ǰ��������Ƚ�
			if (a[j] < a[j - 1]) {	//����
				swap(a[j - 1], a[j]);	//�����ǰ�����������������൱�ڰ�������������ô�����������Ԫ�غ���һλ��������ȥ
			}
			else
				break;
		}
	}
}

int main() {
	int a[10] = { 1,5,3,6,2,45,51,6,33,0 };
	insertionSort(a, 10);
	for (int i : a)
		cout << i << " ";
	return 0;
}
#endif