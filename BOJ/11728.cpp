#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
int N,M;
int a[1'000'003],b[1'000'003];
void merge(int a_size, int b_size)
{
    int *merge_arr = new int[a_size+b_size];
    int idx_a=0,idx_b=0,idx_merge=0;
    while(idx_a < a_size && idx_b < b_size)
    {
        if(a[idx_a]<b[idx_b])
        {
            merge_arr[idx_merge++]=a[idx_a++];
        }
        else
        {
            merge_arr[idx_merge++]=b[idx_b++];
        }

    }

    while(idx_a < a_size) merge_arr[idx_merge++]=a[idx_a++];
    while(idx_b < b_size) merge_arr[idx_merge++]=b[idx_b++];

    for(int i=0;i<a_size + b_size;i++) cout << merge_arr[i] <<" ";
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N,M;
    cin >> N >> M;
    for(int i=0;i<N;i++) cin >> a[i];
    for(int i=0;i<M;i++) cin >> b[i];

    merge(N,M);
}