#include<iostream>
#define endl "\n"
#include<algorithm>
#include<vector>

using namespace std;

int N,S,sel[30] = {0},temp,total=0;
vector<int> v;
bool next_flag = true;

int main()
{
    cin >> N >> S ;
    for(int i = 0 ; i< N ;i++)
    {
        cin >>temp;
        v.push_back(temp);
    }

    for(int i = 0 ; i < N ; i++)
    {
        for(int j=0;j<N;j++)
        {
            sel[j]=0;
        }

        for(int j=0;j<i+1;j++)
        {
            sel[N-1-j]=1;
        }
        do
        {
            temp=0;
            for(int j = 0 ; j < N ;j++)
            {
                if(sel[j])
                {
                    temp += v[j];
                }       
            }
            if(temp == S) total++;
        }while(next_permutation(sel,sel+N));
        
    }
    cout << total;
}