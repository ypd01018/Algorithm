#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <list>
using namespace std;
const string pre_my_url ="<meta property=\"og:url\" content=";
const string pre_external_url = "<a href="; 
int basic_score[22],n_external[22],internal_other[22][22],mx_idx;
double total_score[22],mx;
unordered_map<string,int> url;
bool alp(char a)
{
    if('a'<=a && a <='z') return true;
    if('A'<=a && a <='Z') return true;
    return false;
}
string change_small(string a)
{
    for(int i=0;i<a.size();i++)
    {
        if('A'<=a[i] && a[i] <='Z') a[i] = a[i]-'A' + 'a';
    }
    return a;
}
int find_basic_score(string word,string pages)
{
    
    int i=0,ret = 0,cnt=0; string find_word="";
    for(int i=0;i<pages.size();i++)
    {
        char a = pages[i];
        if(!alp(a)) 
        {
            find_word = change_small(find_word);
            if(find_word==word) cnt++;
            find_word.clear();
            continue;
        }    

        find_word.push_back(pages[i]);
    }
    return cnt;
}
bool check_sentence(int end,string want_sentence, string pages)
{
    int i = end+1-want_sentence.size();
    string sentence="";
    for(i;0<=i&&i<=end;i++) sentence.push_back(pages[i]);
    if(sentence == want_sentence) return true;
    else return false;
}
void find_sentence(int n,string want_sentence, string pages)
{
    int cnt =0;
    for(int i=0;i<pages.size();i++)
    {
        char a = pages[i];
        if(a==want_sentence[want_sentence.size()-1])
        {
            if(!check_sentence(i,want_sentence,pages)) continue;
            string find_url="";
            for(int j=i+2;j<=pages.size();j++)
            {
                if(pages[j]=='\"')
                {
                    if(want_sentence ==pre_my_url)
                    {
                        url[find_url] = n;
                        return;
                    }
                    else if(want_sentence == pre_external_url)
                    {
                        cnt++;
                        internal_other[url[find_url]][n]=1;
                        break;
                    }
                }
                find_url.push_back(pages[j]);
            }
        }
    }
    if(want_sentence==pre_external_url) n_external[n]=cnt;
}
double calc_score(int n,int end)
{
    double ret = basic_score[n];
    for(int i=1;i<=end;i++)
    {
        if(!internal_other[n][i]) continue;
        ret+= ((double)basic_score[i]/(double)n_external[i]);
    }
    return ret;
}
int solution(string word, vector<string> pages) 
{
    word = change_small(word); // 찾아야 하는 단어를 소문자로 바꾸고 시작
    for(int i=0;i<pages.size();i++) 
    {
        basic_score[i+1]=find_basic_score(word,pages[i]);
        find_sentence(i+1,pre_my_url,pages[i]);
    }
    for(int i=0;i<pages.size();i++) find_sentence(i+1,pre_external_url,pages[i]);
    for(int i=0;i<pages.size();i++) 
    {
        total_score[i+1] = calc_score(i+1,pages.size());
        if(mx<total_score[i+1])
        {
            mx = total_score[i+1];
            mx_idx = i;
        }
    }
    return mx_idx;
}​