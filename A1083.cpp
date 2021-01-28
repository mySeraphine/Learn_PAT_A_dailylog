
#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

struct Student{
    char name[12];
    char id[12];
    int grade;
}student;

bool cmp(Student a,Student b){
    return a.grade>=b.grade;
}

vector<Student> stds;
int main() {
    int N;
    cin>>N;
    while (N>0){
        scanf("%s %s %d",student.name,student.id,&student.grade);
        stds.push_back(student);
        N--;
    }
    int grade1,grade2;
    cin>>grade1>>grade2;

    sort(stds.begin(),stds.end(),cmp);
//    for (Student e:stds){
//        printf("%s %s %d\n",e.name,e.id,e.grade);
//    }
//    cout<<grade1<<grade2;
    int l=stds.size();
    bool flag= true;
    for (int i = 0; i < l; ++i) {
        Student n=stds.at(i);

        if (n.grade>=grade1&&n.grade<=grade2){
            printf("%s %s\n",n.name,n.id);
            flag= false;
        }
    }
    if (flag) cout << "NONE"<<endl;

    return 0;
}
