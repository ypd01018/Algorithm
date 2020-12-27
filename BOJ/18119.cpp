#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
int N,M;
int word[10010],forget_alp[27],memory_alp=0b11111111111111111111111111;
int n_know_word()
{
    int ret = 0;
    for(int i=0;i<N;i++)
    {
        if( (memory_alp&word[i]) == word[i]) ret++;
    }
    return ret;
}
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);

    for(int i=0;i<26;i++)
    {
        forget_alp[i] = memory_alp - (int)pow(2,i);
    }
    cin >> N >> M;
    for(int i=0;i<N;i++)
    {
        string a; cin >> a;
        for(int j=0;j<a.size();j++)
        {
            word[i] |= 1 << (a[j]-'a'); 
        }
    }
    for(int i=0;i<M;i++)
    {
        int cmd; char a;
        cin >> cmd >> a;
        if(cmd==1) memory_alp &= forget_alp[a-'a'];
        else memory_alp |= 1<<(a-'a');
        cout << n_know_word() << endl;
    }
}