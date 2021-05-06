#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

string symbol = "+*-";
long long mx = 0;

string calc(string a, string b, string want) {
    long long l_a = stoll(a);
    long long l_b = stoll(b);
    
    long long val;

    if(want=="+") val = l_a + l_b;
    else if(want=="-") val = l_a - l_b;
    else val = l_a * l_b;

    return to_string(val);
}

string char_to_string(char c) {
    string ret = "";
    ret+=c;

    return ret;
}

vector<string> parse(string expression) {
    vector<string> ret;
    string tmp = "";
    for(int i=0;i<expression.size();i++) {
        char a = expression[i];
        
        if(a == '*' || a == '-' || a == '+') {
            ret.push_back(tmp);
            ret.push_back(char_to_string(a));
            tmp = "";
        }
        else tmp.push_back(a);

        if(i == expression.size()-1) ret.push_back(tmp);
    }

    return ret;
}

vector<string> all_calc(vector<string> v, string want) {
    vector<string> ret;
    for(int i=0;i<v.size();i++) {
        string s = v[i];
        if(s != want) ret.push_back(s);
        else {
            string a = ret.back(); ret.pop_back();
            string b = v[++i];
            string result = calc(a,b,want);
            ret.push_back(result);
        }
    }

    return ret;
}

long long solution(string expression) {
    vector<string> parse_v = parse(expression);

    sort(symbol.begin(), symbol.end());

    do {
        cout << symbol << endl;
        vector<string> v = parse_v;
        for(int i=0;i<symbol.size();i++) {
            v = all_calc(v,char_to_string(symbol[i]));
            for(int j=0;j<v.size();j++) cout << v[j] << ' ';
            cout << endl;
        } 
        
        string val = v[0];
        long long long_val = stoll(val);
        mx = max(llabs(long_val),mx);
    }while(next_permutation(symbol.begin(), symbol.end()));

    return mx;
}

int main() {
    string expression = "100-200*300-500+20";
    cout << solution(expression);
}

