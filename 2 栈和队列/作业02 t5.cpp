//#include <iostream>
//using namespace  std;
//#define MAX 50
//struct stack
//{
//    //x��y��
//    int x, y, d;    //d�����ã���direction����ʾ�����ŷ����ߵģ����ڻ��˺���ű�������
//};
//
//struct Move //���ĸ�������
//{
//    int a, b;   //a�У�b��
//};
//int maze[MAX][MAX]; //�����Թ�
//int mark[MAX][MAX]; //����Ǵ����߹���·���߹��ͼ�Ϊ1
//Move mv[4]; //�ߵ�4������
//stack s[MAX * MAX]; //ջ������·��
//int top;    //ջ��λ��
//
//void setmove()  //���ú÷���ֻ����4��
//{
//    mv[0].a = -1;    mv[0].b = 0;   //��
//    mv[1].a = 0;    mv[1].b = -1;   //��
//    mv[2].a = 0;    mv[2].b = 1;    //��
//    mv[3].a = 1;    mv[3].b = 0;    //��
//
//}
//
////�����Զ�����Թ�
//void inputmaze(int m, int n)
//{
//    int i, j;
//    cout << "Input maze : \n";
//    for (i = 0; i <= m + 1; i++)
//        for (j = 0; j <= n + 1; j++)
//            maze[i][j] = 1; //��ʼ����ȫ��Ϊ1
//    for (i = 1; i <= m; i++)
//    {
//        for (j = 1; j <= n; j++)
//            cin >> maze[i][j];  //�߽籣��Ϊ1���м������
//    }
//}
//
////����Թ��������߽���Զ����
//void outputmaze(int m, int n)
//{
//    int  i, j;
//    cout << "Output maze: \n";
//    for (i = 0; i <= m + 1; i++)
//    {
//        for (j = 0; j <= n + 1; j++)    
//            cout << maze[i][j];
//        cout << endl;
//    }
//}
//
////�ѵ��Ǽ�¼�켣�õģ�������û�б����ʣ�
//void setmark(int m, int n)
//{
//    int i, j;
//    for (i = 0; i <= m + 1; i++)
//        for (j = 0; j <= n + 1; j++)
//            mark[i][j] = 0;
//}
//
//int getmazepath(int m, int n)
//{
//    int  i, j, k, g, h, t;  
//    if (maze[1][n] != 0 || maze[m][1] != 0) //����յ㲻�ܵ��ֱ�ӽ������˴���mn�����˱߽磬�ʲ���Ҫ-1
//        return (1);
//    s[0].x = 1;
//    s[0].y = n; //���������ջ
//    s[0].d = -1;
//    top = 1;    //ջ��
//    mark[1][n] = 1;
//    while (top > 0)	//�����һ���������ߵ�·�����߹�ȥ
//    {
//        i = s[--top].x;
//        j = s[top].y;
//        k = s[top].d;
//        while (k < 3)
//        {
//            g = i + mv[++k].a;
//            h = j + mv[k].b;
//            if (g == m && h == 1)   //�����յ�����·��
//            {
//                cout << "path in maze:\n";
//                for (t = 0; t < top; t++)
//                    cout << s[t].x << "  " << s[t].y << endl;
//                cout << i << "  " << j << endl;	//���ڵ���λ��
//                cout << m << "  " << 1 << endl;	//�����ܽ��������ʾ��һ�������յ���
//                return(0);
//            }
//            if (maze[g][h] == 0 && mark[g][h] == 0) //����ط������ߣ�����û�߹�
//            {
//                mark[g][h] = 1;
//                s[top].x = i;
//                s[top].y = j;	
//                s[top++].d = k;	
//                i = g;
//                j = h;
//                k = -1;
//            }
//        }  /* while k  */
//    } /*while  top  */
//    return (1);
//}
//
//int main(){
//    int m, n;
//    cout << "input m n\n";
//    cin >> m >> n;
//    setmove();
//    inputmaze(m, n);
//    outputmaze(m, n);
//    setmark(m, n);
//    if (getmazepath(m, n)) cout << "Error! No path!\n";
//    return 1;
//}
