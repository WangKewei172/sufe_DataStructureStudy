#if 0
#include<iostream>
#include<ctime>
#include<Windows.h>
constexpr auto MAXSIZE = 10;;
using namespace std;



//˵������������Ϊ����ʽ�Ĵ���������ÿһ������Ϊ�����ϵ����
//����a[0] ��ʾ ϵ��Ϊa[0]������Ϊ0 ����

//�����������ʽ
int* createRandPoly() {
	int* a = new int[MAXSIZE];
	srand((unsigned)time(NULL));
	for (int i = 0; i < MAXSIZE; i++) {	//iΪ����
		a[i] = rand() % 20 - 10;	//ϵ����Χ��-10~9
	}
	return a;
}

//�ֶ�����ϵ��
int* createPoly(int ap[]) {
	if(ap != NULL) 	delete[] ap;
	int coef, exp;
	int* a = new int[MAXSIZE];
	for (int i = 0; i < MAXSIZE; i++) {	//���ȳ�ʼ����ȫ������Ϊ0����ֹ��û��������
		a[i] = 0;
	}
	cout << "������ϵ����Ϊ-9999ʱֹͣ���Ǹ���ʽ���룩��";
	cin >> coef;
	while (coef != -9999) {
		cout << "�����������";
		cin >> exp;
		while (exp >= MAXSIZE) {
			cout << "����Ĵ�����ΧΪ��0~" << MAXSIZE - 1 << "�����������룡\n";
			cout << "�����������";
			cin >> exp;
		}
		a[exp] = coef;
		cout << "������ϵ����Ϊ-9999ʱֹͣ����";
		cin >> coef;
	}
	return a;
}

//���
int* addPoly(int a[], int b[]) {
	int* c = new int[MAXSIZE];
	for (int i = 0; i < MAXSIZE; i++) {
		c[i] = a[i] + b[i];
	}
	return c;
}

//���
int* subPoly(int a[], int b[]) {
	int* c = new int[MAXSIZE];
	for (int i = 0; i < MAXSIZE; i++) {
		c[i] = a[i] - b[i];
	}
	return c;
}

//�������ʽ
void outputPoly(int a[]) {
    bool isFirst = true;
    for (int i = MAXSIZE - 1; i > 0; i--) {
        if (a[i] == 0) continue;
        else if (a[i] > 0) {
            if (isFirst) {	//����Ƕ���ʽ�ĵ�һ��
                cout << a[i] << "x^" << i;
                isFirst = false;
            }
            else {
                cout << " + " << a[i] << "x^" << i;
            }
        }
        else {
			if (isFirst) {	//����Ƕ���ʽ�ĵ�һ��
				cout << "-"<< -a[i] << "x^" << i;	//���ڸ��ź�������һ�𲻱��ڹ۲죬�������ͳһ��ʽ
				isFirst = false;
			}
			else {
				cout << " - " << -a[i] << "x^" << i;
			}
        }
    }
	
	if (a[0] > 0) {
		cout << " + " << a[0];
	}
	else if (a[0] < 0) {
		cout << " - " << -a[0];
	}
	cout << "\n\n";
}



int main() {
	int* a_poly = NULL, * b_poly = NULL;
	int* c_poly = NULL;

	int a, b;
	cout << "���ڶ���ʽa����ѡ��\n";
	cout << "1. �ֶ�����\n";
	cout << "2. �������(default)\n";
	cin >> a;

	if (a == 1) {
		cout << "���������ʽa����ߴ���Ϊ��" << MAXSIZE - 1 << "�Σ���\n";
		a_poly = createPoly(a_poly);
	}
	else {	//Ĭ�����
		a_poly = createRandPoly();	//�����������ʽ
	}
	
	cout << "\n����ʽa��\n";
	outputPoly(a_poly);

	Sleep(1000);	//ͣ��һ�룬��ֹ�����һ��

	cout << "���ڶ���ʽb����ѡ��\n";
	cout << "1. �ֶ�����\n";
	cout << "2. �������(default)\n";
	cin >> b;
	if (b == 1) {
		cout << "���������ʽb����ߴ���Ϊ��" << MAXSIZE - 1 << "�Σ���\n";
		b_poly = createPoly(b_poly);
	}
	else {
		b_poly = createRandPoly();	//�����������ʽ
	}
	
	cout << "\n����ʽb��\n";
	outputPoly(b_poly);

	cout << "\n��ӵĺ�Ϊ��\n";
	c_poly = addPoly(a_poly, b_poly);	//c_polyΪ��ӵĽ��
	outputPoly(c_poly);

	cout << "\n�����a - b���ĺ�Ϊ��\n";
	c_poly = subPoly(a_poly, b_poly);	//c_polyΪ����Ľ��
	outputPoly(c_poly);

	delete a_poly;
	delete b_poly;
	delete c_poly;
	return 0;
}
#endif