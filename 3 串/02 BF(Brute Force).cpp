#if 0
#include<iostream>
using namespace std;

int bruteForce(string main, string sub) {
	int len_m = main.length();
	int len_s = sub.length();	//���Ȼ�ȡ�����ַ����ĳ���
	if (len_m < len_s) return -1;	//ƥ�䴮��������ֱ�ӷ���

	for (int i = 0; i < len_m; i++) {	//����main�ַ�����ÿһ���ַ�
		if (main[i] == sub[0]) {	//�Ƚ�����ĸ�����ƥ��ͱȽϺ����
			int tem = i + 1;	//�������λ�ã�
			int j = 1;	//j: ����sub��ʣ���ַ�
			for (; j < len_s && tem < len_m; j++, tem++) {	//����һ����ͷ���˳�
				if (main[tem] != sub[j])	//����в�ƥ��ģ�ֱ���˳�
					break;
			}
			if (j == len_s) return i;	//�����j�˳������ظ�λ�á�ע���ʱ��j����Ϊ����len_s���˳���
		}
	}
	return -1;	//�Ҳ���ƥ��ľͷ���-1
}


int main() {
	string str1, str2;
	str1 = "wangkewei";
	str2 = "wei";
	cout << bruteForce(str1, str2);
}
#endif