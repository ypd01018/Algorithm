#include<iostream>
#define endl "\n"
#include<algorithm>
using namespace std;
int L,C,k=0,issued[20],par=0,child=0;
char input[20],arr[20];
void pw(int a);
//모음 a,e,i,o,u
int main()
{
    char tmp;
    cin >> L >> C;

    for(int i = 0 ; i < C ; i++)
    {
        cin >> tmp;
        input[i] = tmp;
    }

    sort(input,input+C);

    pw(0);
    
}

void pw(int a)
{
    if(k==L && par > 0 && child > 1)
    {
        for(int i = 0 ; i < L; i++)
        {
            cout << arr[i];
        }
        cout << endl;
        return;
    }

    for(int i = a ; i < C; i++)
    {
        arr[k] = input[i];
        k++;
        bool par_true=false;
        if(input[i] == 'i' || input[i] == 'a' || input[i] == 'e' || input[i] == 'o' || input[i] == 'u')
        {
            par++;
            par_true = true;
        }
        else child++;

        pw(i+1);

        k--;

        if(par_true) par--;
        else child--;
        
    }
}