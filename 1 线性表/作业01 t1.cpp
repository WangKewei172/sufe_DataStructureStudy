#if 0
#include<iostream>
using namespace std;

int MAX_NUM = 2;    //��̬����ĳ�ʼ������

struct student {
	int no;//ѧ��
	string  name; //����
	char  sex; //�Ա� M �����У�W����Ů
	int   age;// ����
};

void printMenu() {
	cout << "======���ܲ˵�======\n";
	cout << "  1---����ѧ����\n";
	cout << "  2---���һ��ѧ��\n";
	cout << "  3---����һ��ѧ��\n";
	cout << "  4---ɾ��һ��ѧ��\n";
	cout << "  5---��ʾȫ��ѧ��������\n";
	cout << "  6---��ѧ�Ų���ѧ������\n";
	cout << "  0---�˳�\n";
	cout << "��ѡ���ܣ�(1/2/3/4/5/6/0)\n";
}

//�����ж�������Ա��Ƿ����Ҫ��
bool sexIsRight(char c) {
	return c == 'M' || c == 'W' || c == 'm' || c == 'w';
}

//����ѧ���ҵ�ĳѧ����λ�ã�����λ������
int findStudentPos(student s[], const int sNUM, int no) {
	for (int i = 0; i < sNUM; i++) {
		if (s[i].no == no) {
			return i;
		}
	}
	return -1;  //�Ҳ����ͷ���-1
}

//5. ��ӡ����ѧ����Ϣ
void printStudentArray(const student s[], const int n) {
	for (int i = 0; i < n; i++) {
		cout << "ѧ�ţ�" << s[i].no << endl;
		cout << "������" << s[i].name << endl;
		cout << "�Ա�" << s[i].sex << endl;
		cout << "���䣺" << s[i].age << endl;
		cout << "----------------------------------------\n";
	}
}

//����ѧ����Ϣ�����������ѧ�Ų����ظ�
bool enterStudentInfo(student& t) {
	cout << "������ѧ�ţ� " << endl;
	cin >> t.no;
	if (t.no == -9999) {
		return false;
	}
	cout << "������������ " << endl;
	cin >> t.name;
	cout << "�������Ա�M �����У�W����Ů���� " << endl;
	cin >> t.sex;
	while (!sexIsRight(t.sex)) {    //���Ծ�һֱ����
		cout << "�����������Ա�M �����У�W����Ů������ " << endl;
		cin >> t.sex;
	}
	cout << "���������䣺 " << endl;
	cin >> t.age;
	cout << "\n";
	return true;
}

//��չ��̬����Ĵ�С
student* extendArray(student s[], const int n) {
	MAX_NUM = MAX_NUM * 1.5 + 2; //����ȫ�ֱ���
	student* sArr = new student[MAX_NUM];
	for (int i = 0; i < n; i++) {
		sArr[i].no = s[i].no;
		sArr[i].name = s[i].name;
		sArr[i].sex = s[i].sex;
		sArr[i].age = s[i].age;
	}
	delete[] s;
	return sArr;
}

//1. ����ѧ���б�
student* createStudentArray(student s[], int& sNum) {
	enterStudentInfo(s[sNum]);  //����һ��ѧ��
	sNum++; //ѧ��������һ
	while (enterStudentInfo(s[sNum])) {
		sNum++;
		if (sNum >= MAX_NUM) {
			s = extendArray(s, sNum);
		}
	}
	return s;
}

//2. ���һ��ѧ��
student* appendStudent(student s[], int& sNUM) {
	if (sNUM >= MAX_NUM) {
		extendArray(s, sNUM);
	}
	if (enterStudentInfo(s[sNUM])) {  //����ѧ����Ϣ
		sNUM++; //ѧ������+1
	}
	return s;
}

//3. ��ĳλ�ò���һ��ѧ��
student* insertStudent(student s[], int& sNUM) {
	int pos;
	cout << "��������ģ�\n";
	cin >> pos;
	//if (pos >= sNUM) {  //λ�ô��ڵ�������ʱ��ֱ���൱��append
	//    s = appendStudent(s, sNUM);
	//    return s;
	//}
	//else if (pos < 0) { //λ��С��0
	//    cout << "��λ����Ч��\n";
	//    return s;
	//}
	student tem_s;  //��ʱ����ѧ����Ϣ����ֹ����Ϊ-9999
	if (enterStudentInfo(tem_s)) {  //ȷʵҪ����
		sNUM++;
		if (sNUM >= MAX_NUM) {  //��ֹ�����Ѿ��ﵽ����
			extendArray(s, sNUM);
		}
		for (int i = sNUM - 1; i > pos; i--) { //Ҫô����=��Ҫô��������ֵ������ֱ��s[i] = s[i - 1]
			s[i].no = s[i - 1].no;
			s[i].name = s[i - 1].name;
			s[i].age = s[i - 1].age;
			s[i].sex = s[i - 1].sex;
		}
		s[pos].no = tem_s.no;
		s[pos].name = tem_s.name;
		s[pos].age = tem_s.age;
		s[pos].sex = tem_s.sex;
	}
	return s;
}

//4. ɾ��ѧ��
student* deleteStudent(student s[], int& sNUM) {
	int no, pos;
	cout << "������Ҫɾ����ѧ����ѧ�ţ�";
	cin >> no;
	pos = findStudentPos(s, sNUM, no);
	if (pos == -1)  //posΪ-1�Ļ����������溯��û���ҵ���Ӧ��ѧ��
		cout << "���޴���\n";
	else {
		for (int i = pos; i < sNUM; i++) {
			s[i].no = s[i + 1].no;
			s[i].name = s[i + 1].name;
			s[i].age = s[i + 1].age;
			s[i].sex = s[i + 1].sex;
		}
		sNUM--; //����-1
		cout << "ɾ���ɹ���\n";
	}
	return s;
}

//6. ����ѧ������ʾ������Ϣ
void findStudent(student s[], int& sNUM) {
	int no, pos;
	cout << "������Ҫ���ҵ�ѧ����ѧ�ţ�";
	cin >> no;
	pos = findStudentPos(s, sNUM, no);
	if (pos == -1) {    ////posΪ-1�Ļ����������溯��û���ҵ���Ӧ��ѧ��
		cout << "���޴���\n";
	}
	else {
		cout << "ѧ�ţ�" << s[pos].no << endl;
		cout << "������" << s[pos].name << endl;
		cout << "�Ա�" << s[pos].sex << endl;
		cout << "���䣺" << s[pos].age << endl;
		cout << "----------------------------------------\n";
	}
}

int main() {
	student* studentArr = new student[MAX_NUM]; //ʹ�ö�̬�����ڴ�
	int n;  //����ѡ�����
	int studentNumber = 0;
	while (true) {
		printMenu();
		cin >> n;
		switch (n) {
		case 1:
			studentArr = createStudentArray(studentArr, studentNumber); //�����Լ���ֵ�ͻᵼ�������
			system("pause");
			system("cls");
			break;  //break���ܵ�
		case 2:
			studentArr = appendStudent(studentArr, studentNumber);
			system("pause");
			system("cls");
			break;
		case 3:
			studentArr = insertStudent(studentArr, studentNumber);
			system("pause");
			system("cls");
			break;
		case 4:
			studentArr = deleteStudent(studentArr, studentNumber);
			system("pause");
			system("cls");
			break;
		case 5:
			printStudentArray(studentArr, studentNumber);
			system("pause");
			system("cls");
			break;
		case 6:
			findStudent(studentArr, studentNumber);
			system("pause");
			system("cls");
			break;
		case 0:
			cout << "Bye~\n";
			delete[] studentArr;
			return 0;
		default:
			break;
		}
	}
	if (studentArr != NULL)  //��ֹδɾ���ռ�
		delete[] studentArr;
	return 0;
}
#endif