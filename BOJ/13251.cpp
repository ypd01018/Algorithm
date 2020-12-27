#include<bits/stdc++.h>
#define endl "\n"
#define MAX 2503
using namespace std;
long long M,K,n,n_M[MAX];
double mat[MAX][MAX];
void make()
{
    for(int i=0;i<MAX;i++)
    {
        mat[i][0]=1;
    }
    mat[0][1] = 1;

    for(int i=1;i<MAX;i++)
    {
        for(int j=1;j<i+2;j++)
        {   
            mat[i][j] = (mat[i-1][j] +mat[i-1][j-1]);
            if(mat[i][j]<0) cout << "this:" << mat[i][j] << endl; // 오버플로우 나서 0보다 작아지면 출력
        }
    }
}
int main()
{
    make();
    cin >> M;
    n=0;
    for(int i=0;i<M;i++)
    {
        int tmp;
        cin >> n_M[i];
        n += n_M[i];
    }
    cin >> K;
    for(int i=0;i<M;i++)
    {
        if(n_M[i]<K) n_M[i]=0;
        //cout <<"n_M[i]:" << n_M[i] << " K:" << K << endl;
    }
    double tot=0;
    for(int i=0;i<M;i++)
    {
        if(n_M[i]==0) continue;
        tot += (double)mat[n_M[i]-1][K]/(double)mat[n-1][K];
    }
    cout << fixed;
    cout.precision(18);

    cout << tot; 
}