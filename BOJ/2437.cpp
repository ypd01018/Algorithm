#include<cstdio>
#include<algorithm>
int main()
{
    int N,mx=0,arr[1000],i=0;
    scanf("%d",&N);
    for(i;i<N;i++) scanf("%d",&arr[i]);
    std::sort(arr,arr+N);
    for(i=0;i<N && arr[i]<=mx+1;i++) mx += arr[i];
    printf("%d",mx+1);
}