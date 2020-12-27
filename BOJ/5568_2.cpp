#include<iostream>
#include<string>
#include<set>
#define endl "\n"
using namespace std;
set<string> st;
int N,K,arr[11],cnt,ans[11],visited[11];
void DFS()
{
    if(cnt==2)
    {
        string a="";
        for(int i=0;i<K;i++)
        {
            a=a+(to_string(ans[i]));
            cout << ans[i]<<' ';
        }cout << endl;
        st.insert(a);
        return;
    }
    for(int i=0;i<N;i++)
    {
        if(visited[i]) continue;
        ans[cnt] = arr[i];
        cnt++;
        visited[i]=1;
        DFS();
        cnt--;
        visited[i]=0;
    }
}
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    cin >> N >> K;
    for(int i=0;i<N;i++) cin >> arr[i];
    DFS();
    cout << st.size();
}