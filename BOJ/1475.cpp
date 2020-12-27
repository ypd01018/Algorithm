#include<iostream>
#define endl "\n"

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

    int a,b[10]={0};
    cin >> a;
    if(a==0) b[0]++;
    else
    while(a!=0)
    {
        b[a%10]++;
        a=a/10;
    }
    int temp=0,temp_2=0;
    for(int i=0;i<10;i++)
    {
        if(i!=6 && i!=9)
        {
            if(temp < b[i]) temp=b[i];
        }
        else temp_2=temp_2+b[i];
    } 
    if(temp_2%2==0) temp_2=temp_2/2;
    else temp_2=temp_2/2 + 1;

    if(temp>temp_2) cout << temp;
    else cout << temp_2;
}