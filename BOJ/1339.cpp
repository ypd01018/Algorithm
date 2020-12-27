#include<bits/stdc++.h>
#define endl "\n"

using namespace std;
long long N;
pair<long long,char> alp[30];
string input[12];
int num(char target)
{
    for(int i=25;i>-1;i--)
    {
        if(target == alp[i].second) return alp[i].first;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for(int i=0;i<28;i++)
    {
        alp[i].second = 65+i;
    }
    for(int i=0;i<N;i++)
    {
        cin >> input[i];
        int ten=1;
        for(int j=input[i].size()-1;j>-1;j--)
        {
            alp[input[i][j]-65].first += ten;
            ten *=10;
        }
    }
    sort(alp,alp+26);
    int val=9;
    for(int i=25;i>-1;i--)
    {
        if(!alp[i].first) break;
        alp[i].first = val--;
    }
    /*for(int i=25;i>-1;i--)
    {
        cout << alp[i].second << ": " << alp[i].first << endl;
    }*/
    int total=0;
    for(int i=0;i<N;i++)
    {
        int ten = 1;
        for(int j=input[i].size()-1;j>-1;j--)
        {
            total += num(input[i][j])*ten;
            //cout << "total:" << total << " num" << num(input[i][j])*ten << endl;
            ten *=10;
        }
    }
    cout << total;
}