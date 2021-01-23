//
// Created by Xiang_Duan on 2021/1/23.
//
#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    //input
    int N, p;
    cin >> N >> p;
    vector<int> vec,vec1;

    while (N > 0) {
        int temp;
        cin >> temp;
        vec.push_back(temp);
        --N;
    }
//    for(int e:vec){
//        cout<<e<<" ";
//    }
    multiset<int> ordermp;
    for (int e:vec) {
        ordermp.insert(e);
    }
    for (int e:ordermp) {
//        cout << e << " ";
        vec1.push_back(e);
    }
    int result=0,temp=0;
    for (int i=0;i<vec1.size();i++){
        for (int j = i+result; j < vec1.size(); ++j) {
            if (vec1[j]<=vec1[i]*p){
                temp=j-i+1;
                if (temp>result){
                    result=temp;
                }
            } else{
                break;
            }
        }
    }
    cout<<result<<endl;



    return 0;
}
