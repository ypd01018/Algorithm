#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
using namespace std;

unordered_map<string,string> um;
string input;

void init(){
    um[" <br> "] = "\n";
    um[" <hr> "] = "--------------------------------------------------------------------------------";   
}

vector<string> get_parse_vector_char(string str, char parse)
{

    vector<string> ret;
    string tmp = "";

    for (int i = 0; i < str.size(); i++)
    {
        char c = str[i];
        if (c == parse)
        {
            if (!tmp.empty())
                ret.push_back(tmp);
            tmp = "";
        }
        else
            tmp.push_back(c);
    }
    if (!tmp.empty())
        ret.push_back(tmp);

    return ret;
}

int main() {
    init();

    string input = "";
    string s;
    vector<string> split;
    while (1) {
        cin >> s;
        if(cin.eof() == true) break;
        split.push_back(s);
    }

    vector<string> answer;

    string line = "";
    for(int i=0;i<split.size();i++) {
        if(split[i] == "<br>") {
            answer.push_back(line);
            line = "";
        }
        else if(split[i] == "<hr>") {
            if(!line.empty()) answer.push_back(line);
            answer.push_back("--------------------------------------------------------------------------------");
            line = "";
        }
        else {
            if(line.size() + split[i].size() >= 80) {
                answer.push_back(line);
                line = split[i] + ' ';
            }
            else
                line += split[i] + ' ';
        }
    }
    if(!line.empty()) answer.push_back(line);
    for(int i=0;i<answer.size();i++) {
        cout << answer[i];
        if(i != answer.size()-1) cout << '\n';
    }
}