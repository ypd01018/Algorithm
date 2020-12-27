#include<bits/stdc++.h>
#define endl "\n"
#define mp make_pair
using namespace std;
int N,M,K;
int mat[42][42];
vector<vector<int>> sticker[101];
void print_test()
{
    cout << "----------------------------------\n";
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {
            cout << mat[i][j] << ' ';
        }cout << endl;
    }
}
void print_sticker(vector<vector<int>> output)
{
    cout << "----sticker------------------------\n";
    for(int i=0;i<output.size();i++)
    {
        for(int j=0;j<output[0].size();j++)
        {
            cout<<output[i][j]<<' ';
        }cout<<endl;
    }
}
vector<vector<int>> rotate_sticker(vector<vector<int>> want_sticker)
{
    queue<int> q;
    for(int i=0;i<want_sticker.size();i++)
    {
        for(int j=0;j<want_sticker[i].size();j++)
        {
            q.push(want_sticker[i][j]);
        }
    }
    
    vector<vector<int>> rotate;
    rotate.resize(want_sticker[0].size());
    for(int i=0;i<want_sticker[0].size();i++) rotate[i].resize(want_sticker.size());
    for(int i=rotate[0].size()-1;i>=0;i--)
    {
        for(int j=0;j<rotate.size();j++)
        {
            rotate[j][i]=q.front(); q.pop();
        }
    }
    return rotate;
}
bool check(vector<vector<int>> want_sticker, int y, int x)
{
    for(int i=0;i<want_sticker.size();i++)
    {
        for(int j=0;j<want_sticker[0].size();j++)
        {
            if(mat[y+i][x+j] && want_sticker[i][j]) return false;
        }
    }

    for(int i=0;i<want_sticker.size();i++)
    {
        for(int j=0;j<want_sticker[0].size();j++)
        {
            if(want_sticker[i][j]) mat[y+i][x+j]=1;
        }
    }
    return true;
}
bool stiky(vector<vector<int>> want_sticker)
{
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {
            int y_end = i + want_sticker.size()-1;
            int x_end = j + want_sticker[0].size()-1;
            if(y_end>=N || x_end >=M) continue;
            if(check(want_sticker,i,j)) 
            {
                // cout << i << ',' << j << endl;
                return true;
            }
        }
    }
    return false;
}
void go(vector<vector<int>> want_sticker)
{
    for(int i=0;i<4;i++)
    {
        // print_sticker(want_sticker);
        if(stiky(want_sticker)) 
        {
            // cout << "success\n";
            // print_test();
            return;
        }if(i<3)want_sticker = rotate_sticker(want_sticker);
    }
    // print_test();
}
int main()
{
    cin >> N >> M >> K;
    for(int i=0;i<K;i++)
    {
        int R,C; cin >> R >> C;
        for(int j=0;j<R;j++)
        {
            vector<int> new_v;
            for(int k=0;k<C;k++)
            {
                int a; cin >> a;
                new_v.push_back(a);
            }
            sticker[i].push_back(new_v);
        }
    }
    for(int i=0;i<K;i++)
    {
        go(sticker[i]);
    }
    int ans=0;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {
            ans += mat[i][j];
        }
    }
    cout << ans;

}