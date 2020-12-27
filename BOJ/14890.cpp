#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
int N,L,mat[102][102],check[102],ans;
void print_test()
{
    cout << "----------------------------" <<endl;
    for(int i=0;i<N;i++)
    {
        cout << check[i] << ' ';
    }
    cout << endl<<"----------------------------" <<endl;
}
void print_test2()
{
    cout << "----------------------------" <<endl;
    for(int i=0;i<N;i++)
    {
        cout << check[i] <<endl;
    }
    cout << endl<<"----------------------------" <<endl;
}
bool same_cehck(int y, int x)
{
    if(x-L+1 < 0) return false;
    int val = mat[y][x];

    for(int i=x-L+1;i<=x;i++)
    {
        if(mat[y][i]!=val || check[i]) return false;
    }

    for(int i=x-L+1;i<=x;i++)
    {
        check[i]=1;
    }

    return true;
}
bool same_cehck2(int y, int x)
{
    if(x+L-1 >= N) return false;
    int val = mat[y][x];
    for(int i=x;i<=x+L-1;i++)
    {
        if(mat[y][i]!=val || check[i]) return false;
    }

    for(int i=x;i<=x+L-1;i++)
    {
        check[i]=1;
    }

    return true;
}
bool same_cehck3(int y, int x)
{
    if(y-L+1 < 0) return false;

    int val = mat[y][x];
    for(int i=y-L+1;i<=y;i++)
    {
        if(mat[i][x]!=val || check[i]) return false;
    }

    for(int i=y-L+1;i<=y;i++)
    {
        check[i]=1;
    }

    return true;
}
bool same_cehck4(int y, int x)
{
    if(y+L-1 >= N) return false;

    int val = mat[y][x];
    for(int i=y;i<=y+L-1;i++)
    {
        if(mat[i][x]!=val || check[i]) return false;
    }

    for(int i=y;i<=y+L-1;i++)
    {
        check[i]=1;
    }

    return true;
}

void row_check()
{
    //cout << "row_check"<<endl;
    for(int i=0;i<N;i++)
    {
        //cout << "row:" << i<<endl;
        memset(check,0,sizeof(check));
        bool flag=true;
        for(int j=0;j<N-1;j++)
        {
            if(mat[i][j]+1 == mat[i][j+1])
            {
                if(!same_cehck(i,j))
                { 
                    //cout << i <<',' << j << "  0 fail" << endl;  print_test();
                    flag=false;
                    break;
                }
            }
            else if(mat[i][j]-1 == mat[i][j+1])
            {
                if(!same_cehck2(i,j+1))
                {
                    //cout << i <<',' << j << "  0 fail" << endl;  print_test();
                    flag=false;
                    break;
                }
                j = j+L-1;
                continue;
            }
            else if(mat[i][j]!=mat[i][j+1])
            {
                //cout << i <<',' << j << "  0 fail" << endl;  print_test();
                flag = false;
                break;
            }

        }
        if(flag)
        {
            ans++;
            //cout << " ans+1"<<endl; print_test();
        }

    }
}


void col_check()
{
    //cout << "col_check"<<endl;
    for(int i=0;i<N;i++)
    {
        //cout << "col:" << i<<endl;
        memset(check,0,sizeof(check));
        bool flag=true;
        for(int j=0;j<N-1;j++)
        {
            if(mat[j][i]+1 == mat[j+1][i])
            {
                if(!same_cehck3(j,i))
                {
                    flag=false;
                    //cout << j <<',' << i << "  0 fail" << endl;  print_test2();
                    break;
                }
            }
            else if(mat[j][i]-1 == mat[j+1][i])
            {
                if(!same_cehck4(j+1,i))
                {
                    //cout << i <<',' << j << "  0 fail" << endl;  print_test();
                    flag=false;
                    break;
                }
                j = j+L-1;
                continue;
            }
            else if(mat[j][i]!=mat[j+1][i])
            {
                flag = false;
                    //cout << j <<',' << i << "  0 fail" << endl;  print_test2();
                break;
            }
        }
        if(flag)
        {
            ans++;
            //cout << " ans+1"<<endl; print_test2();
        }
    }
}
int main()
{
    cin >> N >> L;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            cin >> mat[i][j];
        }
    }
    row_check();
    col_check();
    cout << ans;

}