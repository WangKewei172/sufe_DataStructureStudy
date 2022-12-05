#if 0
#include<iostream>
using namespace std;

//a[]����������飬low��������ʼ�±꣬high����������±�
void quickSort(int a[], int low, int high) {
	if (high <= low) return;	//������ֻʣ��һ��ʱ����
	int i = low, j = high, key = a[low];	//i��jΪ�ڱ���keyΪ��׼ֵ

	while (true) {
		while (a[j] >= key) {	//�ȴ��������ұȻ�׼ֵС��
			j--;	//�Ӻ���ǰ��
			if (j == low) break;	//�����ڱ�������ֹͣ
		}
		while (a[i] <= key) {	//�ٴ��������ұȻ�׼ֵ���
			i++;	//��ǰ������
			if (i == high) break;	//�����ڱ�������ֹͣ
		}

		if (i >= j) break;	//�����ڱ�������ֹͣ����Ѱ������
		swap(a[i], a[j]);	//�����ڱ�jio�µ���
	}
	a[low] = a[j];	//������������������ֱ����swap����
	a[j] = key;		//swap(a[low], a[j]);

	//for (int tem = 0; tem <= 9; tem++) cout << a[tem] << " ";
	//cout << "\n";

	quickSort(a, low, j - 1);	//����߽�����ͬ����
	quickSort(a, j + 1, high);	//���ұ߽�����ͬ����
}

int main() {
	int a[10] = { 20,10,90,99,40,50,30,60,80,70 };
	quickSort(a, 0, 9);
	for (int i : a) cout << i << " ";
	cout << "\n";
}

#endif