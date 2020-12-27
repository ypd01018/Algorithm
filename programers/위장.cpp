#include <string>
#include <vector>
#include<map>
using namespace std;
map<string,int> mp;
int solution(vector<vector<string>> clothes) 
{
    for(int i=0;i<clothes.size();i++) mp[clothes[i][1]]++;
    int tmp=1;
    for(map<string,int>::iterator iter=mp.begin();iter!=mp.end();iter++) tmp*=(1+iter->second);
    return tmp-1;
}

int main()
{
    vector<vector<string>> clothes;
    int N; cin >> N;
    clothes.resize(N);
    for(int i=0;i<N;i++)
    {
        string a,b;
        cin >> a >> b;
        clothes[i].push_back(a); clothes[i].push_back(b);
    }
    cout << solution(clothes);
}