#if 0
#include<iostream>
using namespace std;

//int a[]Ϊ��������飬int nΪ���鳤��
void dirSelSort(int a[], int n) {
	int i = 0;	//i����ָ���ź����ĩβ
	int search = 1;	//���ڱ������������
	int min = 0;	//��Сֵλ��
	for (; i < n; i++) {
		search = i + 1;
		min = i;
		while (search < n) {//�ҵ���Сֵ���
			if (a[search] < a[min]) {
				min = search;
			}
			search++;
		}//�ҵ�����Сֵ��ţ���searchֵ�޹���

		//��ʼ�滻
		int tem = a[min];
		while (min > i) {
			a[min] = a[min - 1];	//ÿһ��������һλ
			min--;
		}
		a[i] = tem;
	}
}

int main() {
	int a[10] = { 1,5 ,6, 8, 9, 6, 45 ,5, 2, 1 };
	dirSelSort(a, 10);
	for (int i : a) cout << i << " ";
}
#endif