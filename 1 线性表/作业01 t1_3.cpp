#if 0
#include<iostream>
using namespace std;;

void createRandMatrix(int a[][4]) {
	srand((unsigned int)time(NULL));
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			a[i][j] = rand() % 20 - 10;	//��Χ��-10~9
		}
	}
}

void printMatrix(const int a[][4]) {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			cout << a[i][j] << "\t";
		}
		cout << "\n";
	}
}

int main() {
	int a[4][4];
	createRandMatrix(a);
	cout << "����\n";
	printMatrix(a);
	cout << "���Խ��ߺ͵Ľ����" << a[0][0] + a[1][1] + a[2][2] + a[3][3] << endl;
}
#endif