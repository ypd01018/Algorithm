#include<iostream>
#define endl "\n"
#include<string>
using namespace std;

int main()
{
    int a[3],b=1,c[10]={0};
    for(int i=0;i<3;i++) cin>>a[i];
    for (auto i : a) b=b*i;

    while(b!=0)
    {
        c[b%10]++;
        b=b/10;
    }
    
    for(auto i : c) cout<<i<<endl;

}