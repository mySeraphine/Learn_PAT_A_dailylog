#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int num, cur_len = 0;
    pair<int, int> res;
    cin >> num;

    int sqt = sqrt(num);
    for (int i = 2; i <= sqt; ++i) {//note:i is probably the same of sqrt(num),so "<=" is needed
        if (num % i == 0) {
            int temp_num = num, temp_i = i;
            while (temp_num % temp_i == 0) {
                temp_num /= temp_i;
                temp_i++;
            }
            if (temp_i - i > cur_len) {
                cur_len = temp_i - i;
                res = {i, cur_len};
            }
        }
    }

    //if no consecutive factors
    if (!cur_len) {
        cout << 1 << endl;
        cout << num << endl;
        return 0;
    }
    //if there is consecutive factors
    cout << cur_len << endl;
    cout << res.first;
    for (int i = 1; i < res.second; i++) {
        cout << "*" << res.first + i;
    }
    cout << endl;

    return 0;
}


