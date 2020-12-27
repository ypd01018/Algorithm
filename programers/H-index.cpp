#include <string>
#include <vector>
#include<algorithm>
#include<iostream>
using namespace std;
bool cmp(int a,int b){
    if(a>b) return true;
    else return false;
}
int solution(vector<int> citations) {
    int answer = 0;
    sort(citations.begin(),citations.end(),cmp);
    for(int i=0;i<citations.size();i++){    
        //cout << citations[i] << ' ';
        if(citations[i]>=answer) answer++;
        else if(answer>citations[i])
        {
            answer = min(answer,citations[i-1]);
            break;
        }
        else break;
    }
    return answer;
}
int main(){
    vector<int> citations;
    int N; cin >> N;
    for(int i=0;i<N;i++){
        int a; cin >>a;
        citations.push_back(a);
    }
    cout << solution(citations);
}