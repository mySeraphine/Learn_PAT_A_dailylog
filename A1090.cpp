
#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int N;
double p1,r1;
class node{
public:
    vector<int>backs;
};
vector<node> tree(100100);  //节点要设置得足够多
double prices=0;
int nos=0;

void DFS(int a,double p);

int main() {
    cin>>N>>p1>>r1;
    int begins=0;
    for (int i = 0; i < N; ++i) {
        int temp;
        cin>>temp;
        if (temp==-1){
            begins=i;
        } else{
            tree[temp].backs.push_back(i);
        }
    }
    DFS(begins,p1);
    cout<<fixed<<setprecision(2)<<prices<<" "<<nos<<endl;
    return 0;
}

void DFS(int a,double p){
    if (tree[a].backs.size()==0){
        if (p>prices){
            prices=p;
            nos=1;
        } else if (p==prices){
            nos++;
            return;
        } else{
            return;
        }
    } else{
        for (int i = 0; i < tree[a].backs.size(); ++i) {
            double price=p*(1+0.01*r1);
            DFS(tree[a].backs[i],price);
        }
    }
}
