#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
int N,M,H,mat[40][20],cnt;
bool visited[40][20];
void print_test()
{
    cout <<"------------------------------"<< endl;
    for(int i=1;i<=H;i++)
    {
        for(int j=1;j<=N;j++)
        {
            cout << mat[i][j] << ' ';
        }
        cout << endl;
    }
    cout <<"------------------------------"<< endl;
}
void go(int n)
{
    if(cnt == n)
    {
        //print_test();
        for(int i=1;i<=N;i++)
        {
            int x = mat[1][i];
            for(int j=2;j<=H;j++)
            {
                x = mat[j][x];
            }
            if(x != i)
            {
                return;
            } 
        }
        cout << n; exit(0);
        return;
    }

    for(int i=1;i<=H;i++)
    {
        for(int j=1;j<N;j++)
        {
            if(!visited[i][j] && !visited[i][j+1])
            {
                visited[i][j]=visited[i][j+1]=1;
                mat[i][j]=j+1;
                mat[i][j+1]=j;
                cnt++;

                go(n);

                visited[i][j]=visited[i][j+1]=0;
                mat[i][j]=j;
                mat[i][j+1]=j+1;
                cnt--;
            }
        }
    }

}
int main()
{
    cin >> N >> M >> H;
    if(M==0){cout << 0; exit(0);}

    for(int i=1;i<=H;i++)
    {
        for(int j=1;j<=N;j++)
        {
            mat[i][j] = j;
        }
    }

    //print_test();
    for(int i=0;i<M;i++)
    {
        int a,b;
        cin >> a >> b;
        mat[a][b]=b+1;
        mat[a][b+1]=b;
        visited[a][b] = visited[a][b+1]=1;
    }
    //print_test();
    for(int i=0;i<=3;i++) 
        go(i);

    cout << -1;


}