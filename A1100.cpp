
#include <iostream>
#include <string>

using namespace std;

void etom(const string &e);

void mtoe(const string &m);

string low[13] = {"tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"};/*NOLINT*/
string high[13] = {"tret", "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer",/*NOLINT*/
                   "jou"};

int main() {
    int N = 0;
    cin >> N;
    getchar();
    string s;

    while (N>0){
        getline(cin,s);//读取到空格就停止，这样可以保证输入
        if (s[0]>='0'&&s[0]<='9'){
            etom(s);
        } else{
            mtoe(s);
        }
        N--;
    }
    return 0;
}

void etom(const string &e) {
    int num = 0, quotient, remainder;
    for (char i : e) {
        num = num * 10 + i - '0';
    }
    if (num < 13) {
        cout << low[num] << endl;
    } else {
        quotient = num / 13;
        remainder = num % 13;
        if (remainder != 0) {
            cout << high[quotient] << " " << low[remainder] << endl;
        } else {
            cout << high[quotient] << endl;
        }
    }
}

void mtoe(const string &m) {
    int higher = 0, lower = 0;
    string s3, s4;
    s3 = m.substr(0, 3);
    if (m.length() > 3) {
        s4 = m.substr(4, 3);
    }
    for (int i = 0; i < 13; i++) {
        if (s3 == high[i]) {
            higher = i;
        }
        if (s3 == low[i] || s4 == low[i]) {
            lower = i;
        }
    }
    cout << higher * 13 + lower << endl;
}


