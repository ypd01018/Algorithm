#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
int N,k,temp,mx;
string a;
vector<int> v;
void DFS(int a,int learn,int alp)
{
    int cnt=0;
    if(a==k-5) //학습 가능한 갯수의 알파벳을 배웠으면
    {
        for(int i=0;i<v.size();i++)
        {   
            if((learn&(v[i]))==v[i]) cnt++;
        }
        mx = max(cnt,mx);
        return;
    }
    for(int i=alp;i<26;i++)
    {
        if(learn&(1<<i)) continue;
        DFS(a+1,learn|(1 << i),i+1); 
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> k;
    for(int i=0;i<N;i++)
    {
        cin >> a;
        int tmp=0;
        for(int j=0;j<a.size();j++)
        {
            tmp |= (1<<(a[j]-'a'));
        }
        v.push_back(tmp); // 각 단어를 어떤 철자를 쓰는지 비트로 체크
    }
    temp |= (1 << ('a' - 'a'));temp |= (1 << ('n' - 'a'));temp |= (1 << ('t' - 'a'));temp |= (1 << ('i' - 'a'));temp |= (1 << ('c' - 'a')); //필수로 필요한 a,n,t,i,c 체크
    
    DFS(0,temp,0);
    cout << mx;
}