#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
<<<<<<< HEAD
int N,M;
vector<int> v1,v2;
int main()
{
    cin >> N >> M;
    for(int i=0;i<N;i++)
    {
        int a;cin >> a; v1.push_back(a);
    }
    for(int i=0;i<M;i++)
    {
        int a; cin >> a; v2.push_back(a);
    }
    
=======
int want,N,M,A_arr[1001],B_arr[1001],cnt;
vector<int> A_plus,B_plus;
void get_sum(int *arr, int size, vector<int> &v)
{
    queue<int> q;
    int total=0;
    for(int i=0;i<size;i++) total += arr[i];
    for(int i=0;i<size;i++) // 시작번호
    {
        for(int j=0;i+j<size;j++) // 몇조각?
        {
            if(j) v.push_back(v.back()+arr[i+j]);
            else v.push_back(arr[i]);
            if(v.back() == want) cnt++;
            if(i && i+j!=size-1) q.push(total - v.back());
        }
    }
    while(!q.empty())
    {
        v.push_back(q.front()); q.pop();
        if(v.back()==want) cnt++;
    }
    sort(v.begin(),v.end());
}
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    cin >> want >> N >> M;
    for(int i=0;i<N;i++) cin >> A_arr[i];
    for(int i=0;i<M;i++) cin >> B_arr[i];
    get_sum(A_arr,N,A_plus); get_sum(B_arr,M,B_plus);
    for(int i=0;i<A_plus.size();i++)
    {
        int new_want = want - A_plus[i];
        cnt += upper_bound(B_plus.begin(),B_plus.end(),new_want) - lower_bound(B_plus.begin(),B_plus.end(),new_want);
    }
    cout << cnt;
>>>>>>> c970bb23ae158ddb0c279d0af13d5172eedb711b
}