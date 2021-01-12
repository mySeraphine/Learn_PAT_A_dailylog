#include <iostream>
#include <string>

using namespace std;

int main() {

    string str;
    cin>>str;
    int len=str.length();
    int res=0,cntP=0,cntT=0;

    for (int i = 0; i < len; ++i) {
        if (str.at(i)=='T'){
            cntT++;
        }
    }
    for (int j = 0; j < len; ++j) {
        if (str.at(j)=='P'){
            cntP++;
        } else if (str.at(j)=='T'){
            cntT--;                 //排列组合。在每个A之前的P个数和在A之后的T的个数乘积相加，即为排列组合得到PAT的个数
        } else if (str.at(j)=='A'){
            res = (res+(cntT*cntP)%1000000007)%1000000007;  //结果对1000000007取模，可能是为了防止数据溢出
        }
    }
    cout<<res<<endl;

    return 0;
}

