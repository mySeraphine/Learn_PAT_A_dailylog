//
// Created by Xiang_Duan on 2021/1/16.
//
#include <iostream>
#include <vector>
#include <string>

using namespace std;
int main() {
    string shop,eva;
    cin>>shop>>eva;

//    cout<<shop<<endl;
//    cout<<eva;
    vector<int> beads={0};

    for (int i = 0; i < shop.length(); ++i) {  //用输入的字符串的每一位的char的ascii码值来作为区分
        beads[shop[i]]++;
    }
    int sum=shop.length();
    int need=0;
    for (int j = 0; j < eva.length(); ++j) {
        if (beads[eva[j]]!=0){
            beads[eva[j]]--;
            sum--;
        } else{
            need++;
        }
    }
    if (need==0){
        cout<<"Yes "<<sum<<endl;
    } else{
        cout<<"No "<<need;
    }


    return 0;
}
