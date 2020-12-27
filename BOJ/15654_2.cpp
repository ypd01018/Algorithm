#include<bits/stdc++.h>
#define endl "\n"

using namespace std;
int arr[10],issued[10];
int N,M;
vector<int> v;
void func(int k)
{
    if(k==M)
    {
        for(int i=0;i<M;i++)
        {
            cout << arr[i]<< " ";
        }
        cout << endl;
        return;
    }

    for(int i=0;i<N;i++)
    {
        if(/*issued[i] || */(k!=0 && arr[k-1]>v[i]) ) continue;
        issued[i]=1;
        arr[k]=v[i];
        func(k+1);
        issued[i]=0;
    }

}
int main()
{
    
    cin >> N >> M;
    for(int i=0;i<N;i++)
    {
        int tmp; cin >>tmp;
        v.push_back(tmp);
    }
    sort(v.begin(),v.end());
    func(0);
}