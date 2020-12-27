#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;
string name[100'003];
struct output_
{
    bool flag = true;
    bool in;
    string id;
}output[100'003];
unordered_map<string,string> um; 
vector<string> solution(vector<string> record) 
{
    for(int i=0;i<record.size();i++)
    {
        string a="",name; int n=0;  
        for(int j=0;j<record[i].size();j++)
        {
            if(record[i][j]==' ' || j==record[i].size()-1)
            {
                if(j==record[i].size()-1)  a.push_back(record[i][j]);
                if(n==0)
                {
                    if(a=="Enter") output[i].in=true;
                    else if(a=="Leave") output[i].in = false;
                    else output[i].flag = false;
                }
                else if(n==1)
                {
                    output[i].id = a;
                }
                else if(n==2)
                {
                    um[output[i].id]=a;
                }
                a.clear();
                n++;continue;
            }
            a.push_back(record[i][j]);
        }
    }
    vector<string> answer;
    for(int i=0;i<record.size();i++)
    {
        if(output[i].flag==false) continue;
        string a=um[output[i].id];
        if(output[i].in) a.append("님이 들어왔습니다.");
        else a.append("님이 나갔습니다.");
        answer.push_back(a);
    }
    return answer;
}
int main()
{
    vector<string> record;
    for(int i=0;i<5;i++)
    {
        string a;
        getline(cin,a);
        record.push_back(a);
    }
    solution(record);
}