#include<iostream>
#include<algorithm>
#define endl "\n"
using namespace std;
int N,M,target,arr[1000],arr_idx,day;
struct student
{
    int name;
    int locate=0;
    int good =0;
    int arr_day =0;
};
student stu[1000];

void add_photo()
{
    arr_idx++;
    arr[arr_idx]=target;
    stu[target].locate = arr_idx;
    stu[target].good = 1;
    stu[target].arr_day=day;
}
int find_min()
{
    int mn = 99999;
    for(int i=1;i<=N;i++)
    {
        int val = arr[i];
        if(stu[val].good < mn)
        {
            mn = stu[val].good;
        }
    }
    int mn_day=99999,mn_idx;
    for(int i=1;i<=N;i++)
    {
        int val = arr[i];
        if(stu[val].good == mn && stu[val].arr_day < mn_day)
        {
            mn_day = stu[val].arr_day;
            mn_idx = i;
        }
    }
    stu[arr[mn_idx]].arr_day=0;
    stu[arr[mn_idx]].good=0;
    stu[arr[mn_idx]].locate=0;
    return mn_idx;
}
void print()
{
    for(int j=1;j<N*2;j++)
    {
        for(int i=1;i<N;i++)
        {
            if(stu[arr[i]].good < stu[arr[i+1]].good) swap(arr[i],arr[i+1]);
            else if(stu[arr[i]].good == stu[arr[i+1]].good)
            {
                if(stu[arr[i]].arr_day > stu[arr[i+1]].arr_day) swap(arr[i],arr[i+1]);
            }
        }
    }

    for(int i=1;i<=N;i++)
    {
        if(!arr[i]) break;
        cout << arr[i] << " ";
    }
}
int main()
{
	//ios::sync_with_stdio(0);
	//cin.tie(0);
	
	cin >> N >> M;
    for(int i=0;i<N;i++) stu[i].name=i;
    for(int i=0;i<M;i++)
    {
        day++;
        cin >> target;
        if(!stu[target].locate)//타겟이 배열에 없으면
        {
            if(arr_idx<N)//배열이 안찼으면
            {
                //cout <<"yet"<<endl;
                add_photo();
            }
            else//배열이 찼으면
            {
                int idx = find_min(); 
                arr[idx] = target;
                stu[arr[idx]].arr_day=day;
                stu[arr[idx]].good=1;
                stu[arr[idx]].locate=idx;
            }
            
        }
        else//배열에 있으면 추천만
        {
            stu[target].good++;
        }
        /*
        cout << "--------------------"<<day<<"----------------------"<<endl;
        for(int j=1;j<=N;j++)
        {
            cout << "arr[" <<j<<"]: " << arr[j] << "  good: " << stu[arr[j]].good << " arr_day:" << stu[arr[j]].arr_day << endl;  
        }
        */
    }

    print();

}