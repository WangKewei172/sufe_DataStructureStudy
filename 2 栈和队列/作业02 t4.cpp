//#include<iostream>
//#include<cctype>
//constexpr int MAXN = 100;
//using namespace std;
//
//int getPrior(char c) {
//    switch (c) {
//    case'>':
//        return 1;
//    case'+':
//    case'-':
//        return 2;
//    case'*':
//    case'/':
//        return 3;
//    case'^':
//        return 4;
//    case'(':
//        return 0;
//    }
//}
//
////���ݴ���Ĳ��������������������㣬����������
//int getResult(char op, int a, int b) {
//    int sum = 1;
//    switch (op) {
//    case '+':
//        return a + b;
//    case '-':
//        return a - b;
//    case '*':
//        return a * b;
//    case '/':
//        if (b == 0) {   //����Ϊ0���˳�
//            cerr << "��������Ϊ0��\n";
//            exit(1);
//        }
//        return a / b;
//    case '%':
//        return a % b;
//    case '^':
//        for (int i = 0; i < b; i++) sum *= a;
//        return sum;
//    case '>':
//        return a > b;
//    default:
//        cerr << "���ڲ����Ϲ�����������\n";
//        exit(2);
//    }
//    return 0;
//}
//
//void countSum(char exp[], int& sum) {
//    int nstack[MAXN];char ostack[MAXN];
//    int ntop = -1, otop = -1;
//    int i = 0;  //����exp[]
//
//    while (exp[i] != '\0') {
//        if (isalpha(tolower(exp[i]))) { //����ĸ
//            // cout << "exp[" << i << "]= " << exp[i] << endl; //����
//            ntop++;
//            nstack[ntop] = int(exp[i]) - 'a' + 1;   //ת�������֣�ѹ��ջ��
//        }
//        else {       
//            switch (exp[i]) {
//            case '+':
//            case '-':
//            case '*':
//            case '/':
//            case '^':
//            case '%':
//                if (otop == -1) {   //���������ջΪ�գ�ֱ��ѹ��ջ
//                    otop++;
//                    ostack[otop] = exp[i];
//                }
//                else {
//                    if (getPrior(exp[i]) <= getPrior(ostack[otop])) {   //���ȼ��;ͼ���ջ��
//                        if (ntop <= 0||otop == -1) {    //���ʽ����
//                            cerr << "���ʽ����\n";
//                            exit(1);
//                        }
//                        //����ջ��
//                        int tem = nstack[ntop];
//                        ntop--;
//                        nstack[ntop] = getResult(ostack[otop], nstack[ntop], tem);
//                        otop--; //��������ջ
//                    }
//                    otop++; //��ջ
//                    ostack[otop] = exp[i]; // ��ֹ���ϵ��Ƴ�������������ջ��;����ch���ȼ�����
//                }
//                break;
//            case '(':   //��ջ
//                otop++;
//                ostack[otop] = '(';
//                break;
//            case')':
//                while (ostack[otop] != '(') {
//                    if (ntop <= 0 || otop <= 0) {    //���ʽ����
//                        cerr << "���ʽ����\n";
//                        exit(1);
//                    }
//                    int tem = nstack[ntop];
//                    ntop--; //ȡ��������
//                    nstack[ntop] = getResult(ostack[otop], nstack[ntop], tem);  //��������ѹ��ջ
//                    otop--; //��������ջ
//                }
//                otop--; //�� ( ����
//                break;
//            }
//        }
//        i++;
//    }
//    while (otop > -1) {
//        if (ntop <= 0) {    //���ʽ����
//            cerr << "���ʽ����\n";
//            exit(1);
//        }
//        int tem = nstack[ntop--];
//        nstack[ntop] = getResult(ostack[otop], nstack[ntop], tem);
//        otop--; //��������ջ
//    }
//    if (ntop == 0) sum = nstack[ntop];
//    else {
//        cerr << "wrong��\n";
//        exit(1);
//    }
//}
//
//int main() {
//    char exp[MAXN];
//    int sum;
//
//    cout << "��������ʽ��26����ĸ�ֱ��Ӧ1~26����ʹ��Сд��:\n";
//    cin >> exp;
//    
//    countSum(exp, sum);
//    cout << sum << endl;
//}
