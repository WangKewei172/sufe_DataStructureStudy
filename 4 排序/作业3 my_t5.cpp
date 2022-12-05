#if 0
#include<iostream>
constexpr int N = 10;	//���鳤��
using namespace std;

//void printArr(int a[]) {
//	for(int i =0; i < N; i++)
//		cout << a[i] << " ";
//	cout << "\n";
//}


//����pos�����¼����Ϊa�����������ġ��ϵ��ĵط�����
//pos��¼�����������ʼλ�ã������Ҫ��һ����Ľ���λ�ã���һ����
//n��a �ĳ���
int getPos(int a[], int pos[]) {
	int tem = 1;	//posҪ��¼���±��1��ʼ
	pos[0] = 0;	//���ȿ�ͷ��¼Ϊ0����Ϊ��һ�������ʼλ��һ����0
	for (int i = 0; i < N - 1; i++) {//ע��˴��� n - 1 ����Ϊ��i+1����ֹԽ�磡
		if (a[i] > a[i + 1]) {	//������1 2 3 5 0 1 2 3 �У���5��0���Ǹ��ϵ㣬��ʱ5 > 0����¼��0��λ��
			pos[tem++] = i + 1;//��¼������Ĳ��֣������Ϳ��Էֳɶ��������飬ͨ��pos��¼�±�
		}
	}
	return tem;	//����pos��β��
}

//������a��beg��mid��mid+1��end������ͨ������b�ϲ���һ��
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
	//cout << "a= "; printArr(a); cout << "\n"; //debug
	//cout << "b= "; printArr(b); cout << "\n";	//debug
}

//a[]:ԭʼ���飬b[]����ʱ����
void mergeSort(int a[],int b[]) {
	int pos[N];	//����pos����
	int posLen = getPos(a, pos);	//����pos���鲢��ȡ�䳤��

	//�����merge����Ϊ��������posLen�� - 1��
	for (int i = 0; i < posLen - 2; i++) {	//����
		merge(a, b, pos[0], pos[i + 1] - 1, pos[i + 2] - 1);
		//cout << "a merge = "; printArr(a); cout << "\n"; //debug
	}//���������Ϻ󣬻���ʣ�����������

	merge(a, b, pos[0], pos[posLen - 1] - 1, N - 1);	//�ϲ�����2��
}


int main() {
	int a[N] = {1, 2, 3, 0, 1, 0 ,5 ,6, 5, 4};	//�ֳ�5��
	int b[N];
	mergeSort(a, b);
	for (int i : a) cout << i << " ";
}
#endif