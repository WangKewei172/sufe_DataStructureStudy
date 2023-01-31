#if 0
#include<iostream>
using namespace std;
const int N = 8;

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

	for (int tem = 0; tem <= N; tem++) cout << a[tem] << " ";
	cout << "\n";

	quickSort(a, low, j - 1);	//����߽�����ͬ����
	quickSort(a, j + 1, high);	//���ұ߽�����ͬ����
}

//void quick(int  a[], int low, int up)
//{
//	int i, j;
//	int t;
//	
//	if (low < up)
//	{
//		i = low;
//		j = up;
//		t = a[low];
//		while (i != j)
//		{
//			while (i<j && a[j]>t)   j--;
//			if (i < j)  a[i++] = a[j];
//			while (i < j && a[i] <= t)   i++;
//			if (i < j)  a[j--] = a[i];
//		}
//		a[i] = t;
//		for (int tem = 0; tem <= 9; tem++) cout << a[tem] << " ";
//		cout << "\n";
//		quick(a, low, i - 1);
//		quick(a, i + 1, up);
//	}
//}
void quick(int a[], int low, int up)
{
	int i, j;
	int t;
	// ��� low < up��˵����ǰ����Ԫ��û������
	if (low < up) {
		i = low;
		j = up;
		t = a[low];
		// �� t ���뵽���ʵ�λ��
		while (i != j) {
			// �Ӻ���ǰ�ҵ���һ��С�� t ����
			while (i < j && a[j] > t) {
				j--;
			}
			if (i < j) {
				// ��������ŵ� t �����
				a[i++] = a[j];
			}
			for (int tem = 0; tem <= N; tem++) {
				cout << a[tem] << " ";
			}
			cout << "\n";

			// ��ǰ�����ҵ���һ������ t ����
			while (i < j && a[i] <= t) {
				i++;
			}
			if (i < j) {
				// ��������ŵ� t ���ұ�
				a[j--] = a[i];
			}
			for (int tem = 0; tem <= N; tem++) {
				cout << a[tem] << " ";
			}
			cout << "\n";
		}
		// ��� t �ŵ����ʵ�λ��
		a[i] = t;
		// ���ÿ������Ľ��

		cout << "\n";
		// �������򣬽� t ����ߺ��ұ߷ֱ�����
		quick(a, low, i - 1);
		quick(a, i + 1, up);
	}
}



int main() {
	int a[] = { 46,26,22,68,48,42,36,84,66 };
	
	//quickSort(a, 0, N);
	//cout << "\n";
	int b[] = { 46,26,22,68,48,42,36,84,66 };
	quick(b, 0, N);
}

#endif