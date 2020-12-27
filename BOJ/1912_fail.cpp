    #include<bits/stdc++.h>
    #define endl "\n"

    using namespace std;
    int N,arr[100'003],max_total=-1000;
    int main()
    {
        ios::sync_with_stdio(0);
        cin.tie(0);
        cin >> N;
        for(int i=0;i<N;i++) cin >> arr[i];

        for(int i=1;i<N;i++)
        {
            for(int j=i;j<N;j++)
            {
                int total=0;
                for(int k=i;k<j;k++)
                {
                    total +=arr[k];
                }
                max_total = max(total,max_total);
            }
        }

        cout << max_total;
    }