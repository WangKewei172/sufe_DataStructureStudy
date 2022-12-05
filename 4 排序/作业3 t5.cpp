#if 0
#include <algorithm>
#include <iostream>

using namespace std;

int getIndex(int* a, int* t, int n)
{
    // ��¼��ʼ��Ȼ�ź����������ε���ʼ�±꼰����
    int cnt = 0;
    t[cnt++] = 0;	// ��һ���±�Ϊ0
    for (int i = 0; i < n - 1; i++)
    {
        if (a[i + 1] < a[i])
            t[cnt++] = i + 1;
    }
    return cnt;
}

// �ϲ�a����������������鵽b��Ӧ��λ��
// l�ǵ�һ������������ε���ʼ�±�
// m�ǵ�һ������������ε�ĩβ�±�
// r�ǵڶ�������������ε�ĩβ�±�
void merge(int* a, int* b, int left, int mid, int right)
{
    int i = left;
    int j = mid + 1;	// jΪ�ڶ�������ʼ�±�
    int k = left;
    while (i <= mid && j <= right)	// �ϲ�����
    {
        if (a[i] <= a[j])	// ÿ��ȡ�����н�С��һ��
            b[k++] = a[i++];
        else
            b[k++] = a[j++];
    }
    // �ϲ������е�ʣ�ಿ��
    while (i <= mid) b[k++] = a[i++];
    while (j <= right)	b[k++] = a[j++];
}

void mergePass(int* a, int* b, int* t, int s, int n, int cnt)
{
    int i = 0;
    while (i <= cnt - 2 * s)	// ���Ӷ������������ѭ��
    {
        if (i + 2 * s < cnt)
            merge(a, b, t[i], t[i + s] - 1, t[i + 2 * s] - 1);
        else
            merge(a, b, t[i], t[i + s] - 1, n - 1);
        i = i + 2 * s;
    }
    // ʣ��δ�ϲ��Ĳ���s
    if (i + s < cnt)
        merge(a, b, t[i], t[i + s] - 1, n - 1);
    else if (i < cnt)
        for (int j = t[i]; j <= n - 1; j++)
            b[j] = a[j];
}

void mergeSort(int* a, int* t, int n, int cnt)
{
    // sָ����ÿ�κϲ����Ӷ�������˵����
    // s = 1ʱ���Ƕ��ڳ�ʼ�ֶ�1-1�ϲ�
    // s = 2ʱ��������ʼ�ֶ�2-2�ϲ���2��֮ǰ�ϲ��õ�1-1
    int b[100];
    int s = 1;
    while (s < cnt)
    {
        mergePass(a, b, t, s, n, cnt);	// �ϲ����鵽b
        s += s;
        mergePass(b, a, t, s, n, cnt);	// �ϲ������a
        s += s;
    }
}


int main()
{
    int n;
    int a[100], t[100];
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int cnt = getIndex(a, t, n);
    mergeSort(a, t, n, cnt);
    for (int i = 0; i < n; i++)
        cout << a[i] << ' ';

    return 0;
}
#endif