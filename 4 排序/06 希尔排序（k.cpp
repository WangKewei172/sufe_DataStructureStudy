#if 0
#include<iostream>
using namespace std;


/*template<typename T>
void shell_sort(T array[], int length) {
    int h = 1;
    while (h < length / 3) {
        h = 3 * h + 1;
    }
    while (h >= 1) {
        for (int i = h; i < length; i++) {
            for (int j = i; j >= h && array[j] < array[j - h]; j -= h) {
                swap(array[j], array[j - h]);
            }
        }
        h = h / 3;
    }
}*/


template<class T>
void shellSort(T a[], int length) {   // a[]:�����Ҫ���������, length:���鳤��
    //int length = sizeof(a) / sizeof(a[0]);  // �����鳤��

    // interval��Ϊ�����࣬ÿ���Գ���2�����϶�����1��0
    for (int interval = length / 2; interval; interval /= 2) {   

        // arrayNum��Ϊ������ͬʱҲ��Ϊ��ʼλ�á�����ÿ�飬����������
        for (int arrayNum = 0; arrayNum < interval; arrayNum++) { 
/*-��--��-��-��-��-��--��-��-��--��-�������ǲ�������-��--��-��-��--��-��-��--��-��-��-*/

            // numBeSort:��Ҫ����������ӵ�һ������ʼ
            // ���ǵ����������a[numBeSort] > a[numBeSort + interval]��������numBeSort + intrval < length
            // ÿ�μ�interval�����Ƿ�����
            for (int numBeSort = arrayNum; numBeSort + interval < length; numBeSort += interval) {

                // ����ǰ��Ĳ������򷽷�
                for(int i = numBeSort; i >= 0; i -= interval)  {
                    if (a[i + interval ] < a[i])    // ��С����ǰ��壬����
                        swap(a[i], a[i + interval]);
                }
            }
        }
    }
}

int main() {
    int a[] = { 778,5,3,8,94,0,2,3,15,8,1,74,5,4 };
    shellSort(a, 14);
    for (int i : a)
        cout << i << "  ";
    cout << endl;
}

#endif