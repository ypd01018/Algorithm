#include<iostream>
#define endl "\n"
#include<vector>
#include<algorithm>
using namespace std;
int n,temp,sel[30]={0};
vector<int> v;
int main()
{

    while(1)
    {
        cin >> n;
        
        if(!n) break;

        while(!v.empty()) v.pop_back();

        for(int i = 0 ; i < n ; i++) 
        {
            cin >> temp;
            v.push_back(temp);
            sel[i] = 0;
        }

        for(int i = 0 ; i < 6 ; i++) sel[i] = 1;

        do
        {
            for(int j = 0 ; j < n ; j++)
            {
                if(sel[j]) cout << v[j] <<' ';
            }
            cout << endl;
        }while(prev_permutation(sel,sel+n));
        cout << endl;
    }
}