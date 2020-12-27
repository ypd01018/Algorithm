#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
int A,B,N,M,dy[4]={1,0,-1,0},dx[4]={0,1,0,-1};
int mat[102][102];
struct ro
{
    int y,x,d;
};
ro robot[102];
int direction(char d)
{
    if(d=='N') return 0;
    else if(d=='E') return 1;
    else if(d=='S') return 2;
    else return 3;
}
void print_test()
{
    cout << "print==================================================================="<<endl;
    for(int i=1;i<=N;i++)
    {
        cout << robot[i].y <<' '<< robot[i].x <<  ' ' <<robot[i].d << endl;
    }
    cout << endl;
    for(int i=B;i>0;i--)
    {
        for(int j=1;j<=A;j++)
        {
            cout << mat[i][j] << ' ';
        }
        cout << endl;
    }
    cout << endl;
    cout << "print==================================================================="<<endl;
}
void action(int num,char cmd)
{
    if(cmd=='L') robot[num].d = (robot[num].d+7)%4;
    else if(cmd=='R') robot[num].d= (robot[num].d+1)%4;
    else
    {
        int d = robot[num].d,y=robot[num].y,x=robot[num].x;
        int ny = robot[num].y+dy[d], nx = robot[num].x +dx[d];
        if(ny < 1 || nx <1 || ny > B|| nx > A)
        {
            cout << "Robot "<<num<< " crashes into the wall";
            exit(0);
        }

        if(mat[ny][nx])
        {
            cout << "Robot " << num <<" crashes into robot " << mat[ny][nx];
            exit(0);
        }

        mat[ny][nx]=num;
        mat[y][x]=0;
        robot[num].y=ny; robot[num].x=nx;
    }
    

}
int main()
{
    cin >> A >> B >> N >> M;
    for(int i=1;i<=N;i++)
    {
        int y,x; char d; cin >> x >> y >> d;
        robot[i].y=y; robot[i].x=x; robot[i].d=direction(d);
        mat[y][x]=i;
    }
    // print_test();
    for(int i=0;i<M;i++)
    {
        int num,repeat; char cmd; cin >> num >> cmd >> repeat;
        for(int i=0;i<repeat;i++)
        {
            action(num,cmd);
            // print_test();
        }
    }
    cout << "OK";
}