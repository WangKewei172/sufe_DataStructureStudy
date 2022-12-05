#if 0
#include<iostream>
using namespace std;

//������a��beg��mid��mid+1��end������ͨ������b�ϲ���һ�𡣴�����������±꣬�����Ǹ�����
void merge(int* a, int* b, int beg, int mid, int end) {
	int i = beg,	//i �Ǳ���ǰ�벿�����飬������mid
		j = mid + 1, //j �ǵڶ���������ʼ���±꣬������end
		k = beg;	//k �Ǳ�������b��������end

	while (i <= mid && j <= end) {	//��ʼ�ϲ���i��j��¼�Ƚϵ������������������
		if (a[i] < a[j])	//�����������У��ĸ�ֵ��С�����a[i]��С�Ͱ�������b[k]����ȥ��
			b[k++] = a[i++];	//++ֱ�ӷ���[]����õ���д�������
		else
			b[k++] = a[j++];	//���a[j]��С�Ͱ�������b[k]����ȥ��
	}

	while (i <= mid) b[k++] = a[i++];	//���j�����ˣ�����벿��ȫ������ȥ�ˣ���ôǰ�벿��ֱ�Ӱ�˳�����뼴��
	while (j <= end) b[k++] = a[j++];	//ͬ��

	for (i = beg; i <= end; i++)
		a[i] = b[i];
}

void mergeSort(int a[], int b[], int begin, int end) {
	int mid;
	if (begin < end) {
		mid = begin + (end - begin) / 2;	//���֣�����м���±�
		mergeSort(a, b, begin, mid);	//��
		mergeSort(a, b, mid + 1, end);	//��
		merge(a, b, begin, mid, end);	//�ϲ�
	}
}



int main() {
	int a[10] = { 20,10,90,99,40,50,30,60,80,70 };
	int b[10];
	mergeSort(a, b, 0, 9);
	for (int i : a)
		cout << i << " ";
	cout << "\n";
	return 0;
}
#endif