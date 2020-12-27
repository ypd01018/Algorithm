#include<bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;
int N,lft,rght,cnt,k;
bool arr[6000003];
int v[6000003]; 
//vector<int> v;
ll sum;
int main()
{
    cin >> N;
    int idx_mx=-1;
    for(int i=2;i<6000003;i++)
    {
        if(!arr[i])
        {
            for(int j=i+i;j<6000003;j+=i)
            {
                arr[j]=1;
            }
        }
    }
    for(int i=2;i<6000003;i++)
    {
        if(!arr[i]) 
        {
            if(i > N)
            {
                //idx_mx = v.size();
                idx_mx = k;
                break;
            } 
            //v.push_back(i);
            v[k++] = i;
            
        }
    }
    while(lft <= rght && rght <=idx_mx)
    {
        //cout << "lft:" << lft << " rght:" << rght <<" sum:" << sum << endl;
        if(sum < N)
        {
            sum+=v[rght];
            rght++;
        }
        else if(sum >N)
        {
            sum -= v[lft];
            lft++;
            if(lft >rght && lft <= idx_mx)
            {
                rght = lft;
                sum = v[lft];
            }
        }
        else if(sum == N)
        {
            cnt++;
            sum += v[rght];
            rght++;
        }
    }

    cout << cnt;

}