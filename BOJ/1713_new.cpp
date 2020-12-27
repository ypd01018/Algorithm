#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
int N,K,num,photo[30],n_photo,day;
priority_queue<int> pq;
struct student
{
    bool check = false;
    int location;
    int good;
    int date;
};
student stu[130];


int find()
{
    int min_good = stu[photo[0]].good;
    for(int i=0;i<N;i++)
    {
        min_good = min(min_good,stu[photo[i]].good);
    }
    int min_date = 10000,ret;
    for(int i=0;i<N;i++)
    {
        if(min_good ==stu[photo[i]].good && min_date > stu[photo[i]].date)
        {
            ret = i;
            min_date = stu[photo[i]].date;
        }
    }
    return ret;
}
void print()
{
    cout << endl;
    for(int i=0;i<n_photo;i++)
    {
        cout << photo[i]<<" photo - " << "good:" <<stu[photo[i]].good << "  date:" <<stu[photo[i]].date << endl; 
    }
    cout << endl;
}
void print_ans()
{
    for(int i=0;i<N;i++)
    {        
        pq.push((-1)*photo[i]);
    }
    while(!pq.empty())
    {
        cout << (-1)*pq.top() << ' ';
        pq.pop();
    }
}
int main()
{
    cin >> N >> K;
    for(int i=0;i<K;i++)
    {
        day++;
        cin >> num;
        if(!stu[num].check) // 액자에 없으면
        {
            if(n_photo<N)//액자에 없는데 액자가 여분이 있을 경우
            {
                photo[n_photo] = num;
                stu[num].check = true;
                stu[num].date = day;
                stu[num].good=1;
                stu[num].location = n_photo;
                n_photo++;
            }
            else // 액자에 없는데 액자가 여분이 없을 경우
            {
                int target = find();
                stu[photo[target]].check = false;

                photo[target] = num;
                stu[num].check = true;
                stu[num].date = day;
                stu[num].good=1;
                stu[num].location = target;
            }
        }
        else // 이미 액자에 있으면
        {
            stu[num].good++;
        }
    }

    print_ans();


}