#include<iostream>
#include<algorithm>
#include<string>
#define endl "\n"
using namespace std;
struct Data
{
    int age, date;
    string name;
};
int N;
Data arr[100'002];
bool cmp(Data a, Data b)
{
    if(a.age < b.age) return true;
    else if(a.age > b.age) return false;
    else
    {
        if(a.date<b.date) return true;
        else return false;
    }
}
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    cin >> N;
    for(int i=0;i<N;i++)
    {
        Data a;
        cin >>a.age >> a.name;
        a.date = i;
        arr[i]=a;
    }
    sort(arr,arr+N,cmp);
    for(int i=0;i<N;i++) cout << arr[i].age << ' ' << arr[i].name << endl;
}
