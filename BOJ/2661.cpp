#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
int N,arr[100];

bool arr_dif(int a,int b)//a가 큰거 b가 작은거
{
    int arr_1[100],arr_2[100];

    for(int i=0;i<(a-b);i++)
    {
        arr_1[i]=arr[a-i];
        arr_2[i]=arr[b-i];
    }
    for(int i=0;i<(a-b);i++)
    {
        if(arr_1[i]!=arr_2[i]) 
        {
            return true;
        }
    }
    return false;

}

bool test(int num)
{
    for(int j=1;j<100;j++)
    {   
        if(num-j<0) continue;
        if(!arr_dif(num,num-j)) return false;
    }
    return true;
}

void func(int num)
{
    if(num==N)
    {
        for(int i=0;i<N;i++) cout << arr[i] ;
        cout << endl;
        exit(0);
        return;
    }

    for(int i=0;i<3;i++)
    {
        arr[num]=i+1;
        if(num!=0 && arr[num-1]==arr[num]) continue; //연속은 패스
        if(num==0 || test(num)) func(num+1); 
    }
}

int main()
{
    cin >> N;
    arr[0]=1; arr[1]=2; arr[2]=3; arr[3]=1; arr[4]=2; arr[5]=3;
    if(arr_dif(0,3)) cout<<"false";
    func(0);
}   