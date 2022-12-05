#if 0
#include  <iostream>
using namespace std;
#define MAXN 100
char pos_e[MAXN];
int v[26] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26 };

//���ظ��������ջ�е����ȼ�
int icp(char c)
{
    switch (c)
    {
    case '^':
        return(4);
    case '*':
    case '/':
        return(2);  //������case���������ִ�������һ���ģ���ô�����ֻ����дһ��
    case '+':
    case '-':
        return(1);
    }
}


//���ظ�������ڽ�ջǰ�����ȼ�
int isp(char c)
{
    switch (c)
    {
    case '^':
        return(3);
    case '*':
    case '/':
        return(2);
    case '+':
    case '-':
        return(1);
    case '(':
        return(0);
    case '$':
        return(-1);
    }
}
/*
* ��׺ת��׺����
* mid_e: ��׺���ʽ
* pos_e: ��׺���ʽ
* 
* ת������
* �Ǳ������������
* ����������ţ�ֱ����ջ
* ����������ţ���ջ��ֱ��������һ��������
* ����� ^, +, -, *, /���Ƚ�ջ�е����ȼ�����С�ڵ���ջ�е����ȼ������ջ�������ջ
* ����� \0 ��ȫ����ջ
*/

int mid_to_pos(char  mid_e[], char  pos_e[])
{
    char stack[MAXN], c;    
    int top, i, j;
    stack[0] = '$';
    top = 0;    // ��ʾջ����λ��
    j = 0;  // ��׺���ʽ�ĵ�j��
    i = 0;  // ������
    c = mid_e[0];   // ������ʽ�ĵ�i��
    while (c != '\0')
    {
        if (islower(c)) // ���������ջ
            pos_e[j++] = c;
        else
            switch (c){
                case '+':
                case '-':
                case '*':
                case '/':
                case '^':
                    while (icp(c) <= isp(stack[top])) //�Ƚ�ջ�е����ȼ�����С�ڵ���ջ�е����ȼ������ջ
                        pos_e[j++] = stack[top--];
                    stack[++top] = c;
                    break;
                case '(':   //����� ( ����ջ
                    stack[++top] = c;
                    break;
                case  ')':  //����� ) �����ջ��ֱ�� ( Ϊֹ
                    while (stack[top] != '(')
                        pos_e[j++] = stack[top--];  //��ջ�ľ������׺���ʽ
                    top--;  // ��ʱ��stack[top]Ϊ( ��������Ҫֱ�ӵ�������top--
                    break;
                default:
                    return(1);
            }
        c = mid_e[++i];
    }
    while (top > 0) //ʣ�µ�ֱ�ӵ���
        pos_e[j++] = stack[top--];
    pos_e[j] = '\0';
    return(0);
}

//�����׺���ʽ
int  evaluate(char  pos_e[], int& p_y)
{
    int stack[MAXN];    // ��Ϊջ�������׺���ʽ
    int top, i, x;  // x���ڴ���ջ��Ԫ�ز�������
    char c; // ������ʽ�ĵ�i��
    top = -1;   // ��¼ջ����λ��ֵ
    i = 0;  // ���ʽ�ĵڼ���
    c = pos_e[0];
    while (c != '\0')
    {
        if (islower(c)) // �������ĸ������ջ��Ӧ������
            stack[++top] = v[c - 'a'];
        else
            // ���������������ڼӼ��˳����ȱ���ջ��Ԫ�ص�ֵ��Ȼ��ջ������Ԫ�ؽ��ж�Ӧ������
            // �൱�ڰ�ջ��������Ԫ�ؾ�����Ӧ�����ںϳ�һ��Ԫ��
            switch (c)
            {
            case '+':
                x = stack[top--];
                stack[top] += x;
                break;
            case '-':
                x = stack[top--];
                stack[top] -= x;
                break;
            case '*':
                x = stack[top--];
                stack[top] *= x;
                break;
            case '/':
                x = stack[top--];
                stack[top] /= x;
                break;
            case '^':
                int j, k, y, z;
                x = stack[top--];
                y = stack[top];
                if (y == 0)  return(1); // �����Ϊ0����Ϊ���Ǵ���ı��ʽ
                if (x == 0) stack[top] = 1; // �����Ϊ�㣬���ֱ��Ϊ1
                else {
                    if (x > 0) j = x;
                    else  j = -x;   // ȡ�ݵľ���ֵ

                    for (z = 1, k = 1; k <= j; k++) // ��������
                        z *= y;

                    if (x < 0) z = 1 / z;   // �����С��0����ô�ͱ��1/n

                    stack[top] = z;
                }
                break;
            default: return(1);
            }
        c = pos_e[++i];
    }
    if (top > 0) return(1);
    p_y = stack[top];
    return(0);
}

int main()
{
    char mid_e[MAXN], pos_e[MAXN];   // ������ʽ���൱��string
    cout << "Please input a mid express?\n";
    cin >> mid_e;
    mid_to_pos(mid_e, pos_e);

    for (char ch : pos_e) { //������ɵĺ�׺���ʽ
        cout << ch;
        if (ch == '\0') break;  //��Ȼ�������
    }
    cout << endl;
    int y; evaluate(pos_e, y);
    cout << "the result is: " << y << endl;
    
    return 0;
    
}
#endif