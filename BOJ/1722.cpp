#include<bits/stdc++.h>

using namespace std;
long long N,problem,turn,ans[30],cnt,arr[30],arr_input[30],issued[30],N_cpy;
bool flag = false;
long long factorial(long long a)
{
    long long tmp =1;
    for(long long i = 1 ; i < a+1 ; i ++)
    {
        tmp *= i;
    }
    return tmp;
}
void case_1()
{
    cin >> turn;
    long long  tmp=0,prev_tmp;
    for(long long i = 0 ; i < N ; i++)
    {
        for(long long j = 1 ; j <N+1 ;j++)
        {
            if(!issued[j])
            {
                tmp += factorial(N-1-i); // 첫 tmp는 6 , 2번째 tmp는 
                if(turn <= tmp)
                {
                    tmp -=factorial(N-1-i);
                    ans[i] = j;
                    issued[j] = true;
                    break;
                }
            }
        }
    }

    for(long long i = 0 ; i < N; i++) cout << ans[i] <<' ';
            
}
void case_2()
{
    long long cnt = 1 ;
    for(long long i = 0 ; i < N ; i ++)
    {
        long long tmp;
        cin >> tmp;
        arr_input[i] = tmp;
    }

    for(long long i = 0 ; i < N ; i++)
    {
        for(long long j = 1 ; j < N+1 ; j++)
        {
            if(!issued[j])
            {
                if(arr_input[i] == j)
                {
                    issued[j] = true;
                    break;
                }
                cnt += factorial(N-1-i);
            }

        }
    }

    cout << cnt;
}
int main()
{
    cin >> N >>problem;
    
    for(long long i=0;i<N;i++)
    {
        arr[i] = i+1 ;
    }

    switch(problem)
    {

        case 1:
        {
            case_1();
            break;
        }


        case 2:
        {
            case_2();
            break;
        }

    }

}