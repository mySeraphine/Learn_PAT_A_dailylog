//
// Created by Xiang_Duan on 2021/1/22.
//
#include <iostream>
#include <vector>
#include <stack>


using namespace std;

class Node{
public:
    int value{};
    Node* lchild=nullptr;
    Node* rchild=nullptr;
};

stack<int> temp;
vector<int>inorder;
vector<int> preorder;
int N;

Node* buildtree(int a1,int a2,int b1,int b2){
    if (a1>a2){
        return nullptr;
    }
    Node* root =new Node();
    root ->value=preorder[a1];
    int inorderpos=0;
    for (int i = b1; i <=b2 ; ++i) {
        if (inorder[i]==preorder[a1]){
            inorderpos=i;
            break;
        }
    }
    int prepos=a1+(inorderpos-b1);
    root->lchild=buildtree(a1+1,prepos,b1,inorderpos-1);
    root->rchild=buildtree(prepos+1,a2,inorderpos+1,b2);
    return root;
}

int cnt=0;
void postPrint(Node* root){
    if (root==nullptr){
        return;
    }
    postPrint(root->lchild);
    postPrint(root->rchild);
    if (cnt!=0){
        printf(" ");
    }
    if (cnt==0){
        cnt=1;
    }
    cout<<root->value;
}

int main(){
    cin>>N;
    for (int i = 0; i < 2 * N; ++i) {
        string s;
        cin>>s;
        if (s=="Pop"){
            int t=temp.top();
            temp.pop();
            inorder.push_back(t);
        } else{
            int num;
            cin>>num;
            preorder.push_back(num);
            temp.push(num);
        }
    }
    Node* root;
    root = buildtree(0,preorder.size()-1,0,inorder.size()-1);
    postPrint(root);


    return 0;
}
