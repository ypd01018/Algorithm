#include<bits/stdc++.h>

using namespace std;
int N,problem,arr[30],turn,arr_input[30],cnt;
bool flag = false;
int main()
{
    cin >> N >>problem;
    for(int i=0;i<N;i++)
    {
        arr[i]=i+1;
    }

    switch(problem)
    {

        case 1:
            cin >> turn;
            for(int i = 0 ; i < turn-1 ; i ++)
            {
                next_permutation(arr,arr+N);
            }
            for(int i = 0 ; i < N; i++) cout << arr[i] <<' ';
            break;

        case 2:
            for(int i = 0 ; i < N ; i ++)
            {
                int tmp;
                cin >> tmp;
                arr_input[i] = tmp;
            }

            while(!flag)
            {
                cnt++;
                flag = true;
                for(int i =0;i<N;i++)
                {
                    if(arr[i] != arr_input[i]) flag = false;
                }

                next_permutation(arr,arr+N);
                
            }
            cout << cnt;


    }

}