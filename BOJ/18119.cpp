#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
int N,M,n_word[10010],word_alp[10010][30];
string arr[10010];
set<char> s[10010];
set<char> st;
int n_memorize_word()
{
    int ret = 0;
    for(int i=0;i<N;i++)
    {
        // cout << arr[i] << ':' << s[i].size() << endl;
        // for(auto j=s[i].begin();j!=s[i].end();j++) cout << *j << ' '; cout << endl;
        if(s[i].size() == n_word[i]) ret++;
    }
    return ret;
}
int query_memorize(char a)
{
    for(int i=0;i<N;i++)
    {
        if(word_alp[i][a-'a']) s[i].insert(a);
    }
    return n_memorize_word();
}
int query_forget(char a)
{
    for(int i=0;i<N;i++)
    {
        if(s[i].count(a))s[i].erase(a);
    }
    return n_memorize_word();
}
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    cin >> N >> M;
    for(int i=0;i<N;i++)
    {
        string a; cin >> a;
        arr[i] = a;
        for(int j=0;j<a.size();j++)
        {
            if(s[i].count(a[j])) continue;
            word_alp[i][a[j]-'a']=1;
            s[i].insert(a[j]);
        }
        n_word[i]=s[i].size();
    }
    for(int i=0;i<M;i++)
    {
        int cmd; char a; 
        cin >> cmd >> a;
        if(cmd==1) cout << query_forget(a) << endl;
        else cout << query_memorize(a) << endl;
    }
}