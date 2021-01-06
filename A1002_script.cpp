#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
struct Polynomial {
    int exponent;
    double coefficient;
} polynomial;

bool cmp(Polynomial a, Polynomial b);

int main() {
    vector<Polynomial> fstpolynomial;
    vector<Polynomial> secpolynomial;

    int fstP, secP;
    cin >> fstP;
    for (int i = 0; i < fstP; ++i) {
        fstpolynomial.push_back(polynomial);
    }
    for (int i = 0; i < fstP; ++i) {
        cin >> fstpolynomial[i].exponent >> fstpolynomial[i].coefficient;
    }

    cin >> secP;
    for (int j = 0; j < secP; ++j) {
        secpolynomial.push_back(polynomial);
    }
    for (int j = 0; j < secP; ++j) {
        cin >> secpolynomial[j].exponent >> secpolynomial[j].coefficient;
    }

    //test
//    for (Polynomial e:fstpolynomial) {
//        cout << e.exponent << " " << e.coefficient<<" ";
//    }
//    cout << endl;
//    for (Polynomial e:secpolynomial) {
//        cout << e.exponent << " " << e.coefficient<<" ";
//    }
    int all = fstP + secP;

    for (int i = 0; i < secpolynomial.size(); ++i) {
        for (int j = 0; j < secpolynomial.size(); ++j) {
            if (fstpolynomial[i].exponent == secpolynomial[j].exponent) {
                fstpolynomial[i].coefficient += secpolynomial[j].coefficient;
                if (fstpolynomial[i].coefficient==0){
                    auto iter = fstpolynomial.begin()+i;
                    fstpolynomial.erase(iter);
                    all--;
                }

                all--;
                auto it=secpolynomial.begin()+j;
                secpolynomial.erase(it);
            } else {
                fstpolynomial.push_back(secpolynomial[j]);
            }
        }
    }
    sort(fstpolynomial.begin(), fstpolynomial.end(), cmp);


    cout << all ;
    int L = fstpolynomial.size();
//    cout<<L;
    for (int i = 0; i < L; ++i) {
        printf(" %d %.1f",fstpolynomial[i].exponent,fstpolynomial[i].coefficient);
    }
    printf("\n");

//    for (int i = 0; i < L - 1; ++i) {
//        cout << "|" << fstpolynomial[i].exponent << " " << fstpolynomial[i].coefficient << "|" << " ";
//    }
//    cout << "|" << fstpolynomial[L - 1].exponent << " " << fstpolynomial[L - 1].coefficient << "|";
    return 0;
}

bool cmp(Polynomial a, Polynomial b) {
    return a.exponent > b.exponent;
}


