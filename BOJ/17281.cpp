#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
int N,mat[52][11],turn[11],check[11],ru[4],score,mx=0;
void anta(int a)
{
    if(a==4)
    {
        int cnt=1;
        for(int i=1;i<=3;i++)
        {
            if(ru[i]>=1) cnt++;
            ru[i]=0;
            
        }
        score += cnt;
        return;
    }
    else if(a==1)
    {
        score += ru[3];
        ru[3]=ru[2];
        ru[2]=ru[1];
        ru[1]=1;
    }
    else if(a==2)
    {
        score += ru[3]+ru[2];
        ru[3]=ru[1];
        ru[2]=1;
        ru[1]=0;
    }
    else if(a==3)
    {
        score += ru[3]+ru[2]+ru[1];
        ru[3]=1;
        ru[2]=0;
        ru[1]=0;
    }
}
void game_start()
{
    // cout << endl;
    // for(int i=1;i<=9;i++)
    // cout << turn[i] <<' ';
    // cout << endl;
    score=0;
    int start=1;

    for(int ining=1;ining<=N;ining++)
    {
        memset(ru,0,sizeof(ru));
        int out=0;
        bool flag = false;
        while(out<3)
        {
            if(flag) start = 1;

            for(int i=start;i<=9;i++)
            {
                int num=turn[i];
                int action = mat[ining][num];
                switch (action)
                {
                    case 0:
                        out++;
                        break;
                    case 1:
                        anta(1);
                        break;
                    case 2:
                        anta(2);
                        break;
                    case 3:
                        anta(3);
                        break;
                    case 4:
                        anta(4);
                        break;
                    default:
                        break;
                }
                if(out==3)
                {
                    if(i==9) start = 1;
                    else start = i+1;
                    break;
                }
            }
            flag=true;
        }
    }
    mx = max(score,mx);
}
void set_turn(int n)
{

    if(n==10)
    {
        game_start();
        return;
    }

    if(n==4)
    {
        set_turn(n+1);
        return;    
    }

    for(int i=2;i<=9;i++)
    {
        if(check[i]==0)
        {
            turn[n]=i;
            check[i]=1;
            set_turn(n+1);
            check[i]=0;
        }
    }
}
int main()
{
    cin >> N;
    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=9;j++)
        {
            cin >> mat[i][j];
        }
    }
    turn[4]=1;
    check[1]=1;
    set_turn(1);
    cout << mx;

}