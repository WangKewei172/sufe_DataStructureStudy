//#include  <iostream>
//using namespace std;
//#define MAXN 100
//
//int v[26] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26 };   //��Ӧ26����ĸ��ʾ����
//
///* 
//* ������evaluate(char pos_e[], int& p_y)
//* ���ã������׺���ʽ����ĸ����ĸ���е������������֣�������Сд��ĸ
//*/
//int  evaluate(char  pos_e[], int& p_y)
//{
//    int stack[MAXN];    // ��Ϊջ�������׺���ʽ
//    int top, i, x;  // x���ڴ���ջ��Ԫ�ز�������
//    char c; // ������ʽ�ĵ�i��
//    top = -1;   // ��¼ջ����λ��ֵ
//    i = 0;  // ���ʽ�ĵڼ���
//    c = pos_e[0];
//    while (c != '\0')
//    {
//        if (islower(c)) // �������ĸ������ջ��Ӧ������
//            stack[++top] = v[c - 'a'];
//        else
//            // ���������������ڼӼ��˳����ȱ���ջ��Ԫ�ص�ֵ��Ȼ��ջ������Ԫ�ؽ��ж�Ӧ������
//            // �൱�ڰ�ջ��������Ԫ�ؾ�����Ӧ�����ںϳ�һ��Ԫ��
//            switch (c)  
//            {
//            case '+':
//                x = stack[top--];
//                stack[top] += x;
//                break;
//            case '-':
//                x = stack[top--];
//                stack[top] -= x;
//                break;
//            case '*':
//                x = stack[top--];
//                stack[top] *= x;
//                break;
//            case '/':
//                x = stack[top--];
//                stack[top] /= x;
//                break;
//            case '^':
//                int j, k, y, z;
//                x = stack[top--];
//                y = stack[top];
//                if (y == 0)  return(1); // �����Ϊ0����Ϊ���Ǵ���ı��ʽ
//                if (x == 0) stack[top] = 1; // �����Ϊ�㣬���ֱ��Ϊ1
//                else{
//                    if (x > 0) j = x;
//                    else  j = -x;   // ȡ�ݵľ���ֵ
//                    
//                    for (z = 1, k = 1; k <= j; k++) // ��������
//                        z *= y; 
//
//                    if (x < 0) z = 1 / z;   // �����С��0����ô�ͱ��1/n
//
//                    stack[top] = z; 
//                }
//                break;
//            default: return(1);
//            }
//        c = pos_e[++i];
//    }
//    if (top > 0) return(1);
//    p_y = stack[top];
//    return(0);
//}
//int  main()
//{
//    int y;  //��float���ô�Ĵ��룬����ʹ��top--�����ˣ�����ֻ����������
//    char pos_e[MAXN];   // ������ʽ���൱��string
//    cout << "Please input a pos express?\n";
//    cin >> pos_e;
//    if (evaluate(pos_e, y))  cout << "Express is error!" << endl;
//    else cout << pos_e << "=" << y << endl;
//    return 0;
//}
