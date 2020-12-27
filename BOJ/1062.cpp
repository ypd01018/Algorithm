#include<iostream>
#include<vector>
#include<string>
#define endl "\n"
using namespace std;
int N,K,mx,need,need_n;
vector<int> v;
void go(int n,int alp,int a)
{
    if(n==K-5 || n>=need_n-5)
    {
        int n_word=0;
        for(int i=0;i<v.size();i++)
        {
            if((v[i]&alp)==v[i]) n_word++; 
        }
        mx= max(mx,n_word);
        if(mx == N) {cout << N; exit(0);}
        return;
    }
    for(int i=a;i<26;i++)
    {        
        if((1<<i & alp)||!(need&1<<i)) continue;
        go(n+1,alp|1<<i,i+1);
    }

}
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    cin >> N >> K;
    for(int i=0;i<N;i++)
    {
        string a; cin >> a; int word=0;
        for(int j=0;j<a.size();j++) 
        {
            if(!(need&1<<a[j]-'a')) need_n++;
            word |= 1<<a[j]-'a';
            need |= 1<<a[j]-'a';
        }
        v.push_back(word);
    }
    if(K<5)
    {
        cout << 0; return 0;
    }
    int alp=0;
    alp |=1<<('a'-'a');
    alp |=1<<('n'-'a');
    alp |=1<<('t'-'a');
    alp |=1<<('i'-'a');
    alp |=1<<('c'-'a');
    go(0,alp,0);
    cout << mx;
}