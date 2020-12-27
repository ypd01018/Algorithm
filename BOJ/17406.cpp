#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
int N,M,K,mat[55][55],cpy[55][55],visited[8],arr[8],mn=INT_MAX;
struct cmd
{
    int y_start,y_end,x_start,x_end;
};
cmd rcs[8];
void print_test()
{
    for(int i=0;i<K;i++)
    cout << arr[i] << ' ';
    cout << endl;

    cout << "------------------------start----------------------------"<<endl;
    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=M;j++)
        {
            cout << mat[i][j] << ' ';
        }
        cout << endl;
    }
    cout << "------------------------e n d----------------------------"<<endl;
}
void rotate(int a)
{
    int y_s=rcs[a].y_start, y_e=rcs[a].y_end,x_s=rcs[a].x_start,x_e=rcs[a].x_end;
    deque<int> dq;
    while(y_s != y_e)
    {
        //cout << y_s << ',' << x_s << "  " << y_e << ',' << x_e << endl;
        for(int i=x_s;i<=x_e;i++) dq.push_back(mat[y_s][i]);
        for(int i=y_s+1;i<=y_e;i++) dq.push_back(mat[i][x_e]);
        for(int i=x_e-1;i>=x_s;i--) dq.push_back(mat[y_e][i]);
        for(int i=y_e-1;i>y_s;i--) dq.push_back(mat[i][x_s]);

        int tmp = dq.back(); dq.push_front(tmp); dq.pop_back();
        
        for(int i=x_s;i<=x_e;i++) {mat[y_s][i]=dq.front(); dq.pop_front();}
        for(int i=y_s+1;i<=y_e;i++) {mat[i][x_e]=dq.front(); dq.pop_front();}
        for(int i=x_e-1;i>=x_s;i--) {mat[y_e][i]=dq.front(); dq.pop_front();}
        for(int i=y_e-1;i>y_s;i--) {mat[i][x_s]=dq.front(); dq.pop_front();}

        y_s++; y_e--;
        x_s++; x_e--;
    }
}
void DFS(int a)
{
    if(a==K)
    {
        for(int i=0;i<K;i++)
        {
            int target = arr[i];
            rotate(target);
            //print_test();
        }
        int mn_row=INT_MAX;

        for(int i=1;i<=N;i++)
        {
            int hap=0;
            for(int j=1;j<=M;j++)
            {
                hap += mat[i][j];
            }
            mn_row = min(mn_row,hap);
        }
        mn = min(mn_row,mn);
        memcpy(mat,cpy,sizeof(cpy));

        return;
    }

    for(int i=0;i<K;i++)
    {
        if(visited[i]) continue;
        visited[i]=1;
        arr[a]=i;
        DFS(a+1);
        visited[i]=0;
    }
}
int main()
{
    cin >> N >> M >> K;
    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=M;j++)
        {
            cin >> mat[i][j];
        }
    }
    for(int i=0;i<K;i++)
    {
        int r,c,s;
        cin >> r >> c >> s;
        rcs[i].y_start = r-s; rcs[i].x_start=c-s;
        rcs[i].y_end=r+s, rcs[i].x_end=c+s;
    }
    memcpy(cpy,mat,sizeof(mat));
    DFS(0);
    cout << mn;



}