#if 0
#include<iostream>
constexpr int MAXN = 11;
using namespace std;

void getNext(const string& str, int* next) {
	int j = 0;	//jָ���׺
	next[0] = j;
	for (int i = 1; i < str.size(); i++) {	//i��1��ʼ�� iָ��ǰ׺
		while (j > 0 && str[i] != str[j]) {	//ǰ��׺��ͬ���˴���������if����Ϊ�����������˵�
			j = next[j - 1];	//��ǰ����
		}
		if (str[i] == str[j])	//�ҵ�����ͬ��ǰ��׺
			j++;
		next[i] = j;//��ǰ׺�ĳ��ȸ���next[i]
	}
}

//str��������p��ģʽ����next�ǻ����õ�����
int kmpSearch(string str, string p) {
	int next[MAXN];
	getNext(p, next);//����next����

	int i = 0, j = 0;
	while (i < str.length()) {
		if (str[i] == p[j]) {	//ƥ�䣬ָ�����
			i++; 
			j++;
		}
		else if (j > 0) {//��ƥ�䣬����next����
			j = next[j - 1];
		}
		else {	//��һ���Ͳ�ƥ��
			i++;
		}
		if (j == p.size())	//ƥ��ɹ�
			return i - j;
	}
	return -1;
}

int main() {
	string str1 = "wangkewangwawakekewei";
	string str2 = "wawakekew";
	int a[MAXN];
	getNext(str2, a);
	for (int i : a) cout << i << " ";
	cout << "\n";
	cout << kmpSearch(str1, str2);
}
#endif