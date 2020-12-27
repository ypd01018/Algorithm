#include <iostream>

#include <algorithm>

using namespace std;

 

const int MAX = 10000;

 

int N, M;

int ride[MAX];

 

long long binarySearch(void)

{

        long long low = 0, high = 2000000000LL * 30LL;

        long long result = -1;

        while (low <= high)

        {

                 long long mid = (low + high) / 2;

                 long long children = M;

                 for (int i = 0; i < M; i++)

                         children += mid / ride[i];

 

                 if (children >= N)

                 {

                         result = mid;

                         high = mid - 1;

                 }

                 else

                         low = mid + 1;

        }

 

        return result;

}

 

int main(void)

{

        ios_base::sync_with_stdio(0);

        cin.tie(0);

        cin >> N >> M;

       

        for (int i = 0; i < M; i++)

                 cin >> ride[i];

 

        //놀이기구 수보다 아이들의 수가 적을 경우

        if (N <= M)

        {

                 cout << N << "\n";

                 return 0;

        }

 

        //마지막 아이가 탑승한 시간을 찾는다

        long long time = binarySearch();
        cout << time << endl;
        long long children = M;

        //(time - 1)까지 탑승한 아이들을 전부 더한다

        for (int i = 0; i < M; i++)

                 children += (time - 1) / ride[i];
        cout << "pre_child :" << children << endl;

        //time에 탑승한 아이를 확인한다

        for (int i = 0; i < M; i++)

        {

                 if (!(time % ride[i]))

                         children++;

 

                 if (children == N)

                 {

                         cout << i + 1 << "\n";

                         break;

                 }

        }

        return 0;

}

