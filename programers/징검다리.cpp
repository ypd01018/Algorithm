#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int solution(int distance, vector<int> rocks, int n)
{
    sort(rocks.begin(),rocks.end());
    int lft = 0, rght = distance, answer = 0;

    while(lft<=rght){
        int mid = (lft+rght)/2;

        int prev = 0, cnt = 0;
        for(int i=0;i<rocks.size();i++){
            int dis = rocks[i] - prev;
            if(dis<mid) {
                cnt++;
                if(cnt>n) break;
            }
            else prev = rocks[i];
        }
        if(cnt>n) rght = mid-1;
        else {
            answer = max(answer, mid);
            lft = mid+1;
        }
    }

    return answer;
}

int main(){
    cout << solution(25, { 2, 14, 11, 21, 17 }, 2);
}