//
// Created by Xiang_Duan on 2021/1/28.
//
#include <iostream>
#include <string>
#include <unordered_set>
#include <sstream>

using namespace std;

string orig,tpout;
unordered_set<char> found;

int main() {
//    orig="7_This_is_a_test";
//    tpout="_hs_s_a_es";
    cin>>orig>>tpout;

    int len=orig.length();
    int j=0;
    for (int i = 0; i < len; ++i) {
        if (orig[i]==tpout[j]){
            j++;
        } else{
            if (orig[i] <='z'&& orig[i]>= 'a'){
                orig[i]+='A'-'a'; //将小写字母转成大写
            }
            stringstream ss;
            ss<<orig[i];
            char c;
            ss>>c;
            if (found.find(c)==found.end()){
                found.insert(c);
                cout<<c;
            }
        }
    }
    cout<<endl;
    return 0;
}
