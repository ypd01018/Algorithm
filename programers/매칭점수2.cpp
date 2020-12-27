#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <list>
using namespace std;
int basic_score[22],n_external[22],internal_other[22][22],mx_idx;
double total_score[22],mx;
unordered_map<string,int> url;
bool alp(char a)
{
    if(('a'<=a && a <='z')||('A'<=a && a <='Z')) return true;
    return false;
}
string change_small(string a)
{
    for(int i=0;i<a.size();i++) 
    if('A'<=a[i] && a[i] <='Z') a[i] = a[i]-'A' + 'a';
    
    return a;
}
int find_basic_score(string word,string pages)
//특수문자가 발견되면 만든 단어를 찾는 단어와 맞는지 비교. 비교를 위해 찾은 단어는 소문자로 변환. 맞다면 cnt++. 비교 후 단어 string 초기화.
// 최종 cnt는 자신의 기본 점수
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
string make_sentence(list<char> find_sentence)
{
    string ret = "";
    list<char>::iterator iter = find_sentence.begin();
    for(iter;iter!=find_sentence.end();iter++) ret.push_back(*iter);
    return ret;
}
//아래의 32글자가 나타나면 자신의 url이 나타난다는 조건.
//그러므로 초기 31글자를 모으고 32글자부터 글자를 한글자씩 붙이고 비교 시작
//한글자씩 비교할 때마다 뒤에 글자를 붙이고 앞에서 글자를 빼야 32글자가 되므로 linked-list 사용
//linked-list이므로 위의 make_sentence를 이용해서 string으로 변환하고 비교
//찾고자 하는 32글자가 발견되면 발견된 글자 +2번 째 인덱스부터 "가 나올 때 까지의 글자를 모은 다음 
//해시로 해당 url에 자신의 인덱스번호를 부여 후 리턴
void find_my_url(int n,string pages)
{
    string want_sentence = "<meta property=\"og:url\" content=";//32글자
    list<char> find_sectence; 
    for(int i=0;i<31;i++) find_sectence.push_back(pages[i]);
    for(int i=32;i<pages.size();i++)
    {
        char a = pages[i];
        find_sectence.push_back(a);
        if(make_sentence(find_sectence)==want_sentence)
        {
            string my_url="";
            for(int j = i+2;j<pages.size();j++)
            {
                if(pages[j]=='\"')
                {
                    url[my_url] = n;
                    break;
                }
                my_url.push_back(pages[j]);
            }
            return;
        }
        find_sectence.pop_front();
    }
}
void find_external(int n,string pages)
//위의 자신의 url 찾는 방법과 완전 동일
//발견되면 internal_other[가리키는 url의 번호][자신의 번호] 를 1로 만듬
{
    string want_sentence = "<a href=";//8글자
    list<char> find_sectence; 
    int cnt=0;
    for(int i=0;i<7;i++) find_sectence.push_back(pages[i]);
    for(int i=8;i<pages.size();i++)
    {
        char a = pages[i];
        find_sectence.push_back(a);
        if(make_sentence(find_sectence)==want_sentence)
        {
            string external_url="";
            for(int j = i+2;j<pages.size();j++)
            {
                if(pages[j]=='\"')
                {
                    cout << n << ':' << external_url << endl;
                    internal_other[url[external_url]][n]=1;
                    cnt++;
                    break;
                }
                external_url.push_back(pages[j]);
            }
        }
        find_sectence.pop_front();
    }
    n_external[n]=cnt;
}
double calc_score(int n,int end)
//기본 점수+(자신을 향하는 링크를 가진 곳이 있으면 계산한 점수)
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
        find_my_url(i+1,pages[i]);
    }
    for(int i=0;i<pages.size();i++) find_external(i+1,pages[i]);
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
}

​