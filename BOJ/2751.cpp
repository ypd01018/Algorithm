#include<iostream>
#define endl "\n"

using namespace std;
int cnt=0;
int arr[1000001],temp[1000001],tp;
void merge(int start, int end);
void sort(int start, int end);
int main()
{
    int n;
    cin >> n;
    for(int i=0 ;i < n ;i++)
    {
        cin >> tp;
        arr[i]=tp;
    }

    sort(0,n-1);


    for(int i=0 ;i < n ;i++)
    {
        cout << arr[i] << endl;
    }

    
}
void merge(int start, int end)
{
    int mid =(start + end)/2;
    int i =start, j = mid + 1 , k = 0;
    while( i <=mid && j <=end)
    {
        if(arr[i]>arr[j]) 
        {
            temp[k]=arr[j];
            j++;
            k++;
        }
        else
        {
            temp[k] = arr[i];
            i++;
            k++;
        }
    }
    while(i <= mid) 
    {
        temp[k]=arr[i];
        k++; i++;
    }
    while(j <= end)
    {
        temp[k] = arr[j];
        k++; j++;
    }

    for(int i = start ; i <= end; i++)
    {
        arr[i]=temp[i-start];
    }

}
void sort(int start, int end)
{
    if(start == end) return;
    int mid = (start+end)/2;

    sort(start, mid);
    sort(mid+1, end);
    merge(start,end);
}
