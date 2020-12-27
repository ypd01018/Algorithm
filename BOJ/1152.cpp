#include<iostream>
#define endl "\n"
#include<string>
using namespace std;

int main()
{
    ios::sync_with_stdio(1);
    cin.tie(0);

    bool flag = false;
    int cnt;
    string a;
    getline(cin,a);
    if(a[0]==' ') cnt=0;
    else cnt =1;
    for(int i = 0 ; i < a.size() ; i++)
    {
        //cout << i;
        if(a[i] == ' ')
        { 
            cnt++;
            if( i !=0 && a[i-1]==' ') cnt--;
            flag = true;  
        } 
        else flag = false; 
    }
    if(a[a.size()-1] == ' ') cnt--;
    cout << cnt;
}