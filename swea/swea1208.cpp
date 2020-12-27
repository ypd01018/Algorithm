#include<iostream>
#define endl "\n"
using namespace std;

int arr[100];
void sol();
int mx();
int mn();
int main()
{
    for(int i = 0 ; i<10 ; i++)
    {
        cout << "#"<< i+1 <<" ";
        sol();
        cout << endl;
    }
}

void sol()
{
    int n,temp,max,min;
    cin >> n;
    for(int i=0 ; i < 100 ; i++)
    {
        cin >> temp;
        arr[i] = temp;
    }

    for(int i = 0; i < n ; i++)
    {
        max = mx();
        min = mn();
        if(arr[max] - arr[min] == 0) break;
        arr[max]--;
        arr[min]++;
    }
    max = mx();
    min = mn();

    cout << arr[max] - arr[min];
}
int mx()
{
    int temp=0;
    for(int i=0; i < 100 ; i++)
    {
        if(arr[i] > arr[temp]) temp = i;
    }
    return temp;
}
int mn()
{
    int temp=0;
    for(int i=0; i < 100 ; i++)
    {
        if(arr[i] < arr[temp])
        {
            temp = i;
        }
    }
    return temp;
}