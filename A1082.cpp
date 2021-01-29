#include <iostream>

using namespace std;

string sss[10] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};
string wei[6] = {"Shi", "Bai", "Qian", "Wan", "Yi"};

int main() {
    string s;
    cin >> s;
    int len = s.length();
    int left = 0, right = len - 1;
    if (s[0] == '-') {
        cout << "Fu";
        left++;
    }
    while (left + 4 <= right) {
        right -= 4;
    }
    while (left < len) {
        bool flag = false;
        bool havewei = false;
        while (left <= right) {
            if (left > 0 && s[left] == '0') {
                flag = true;
            } else {
                if (flag) {
                    cout << " ling";    //有空格
                    flag = false;
                }
                if (left > 0) {
                    cout << " ";
                }
                cout << sss[s[left] - '0'];
                havewei = true;
                if (left != right) {
                    cout << " " << wei[right - left - 1]; //双指针法，查找是否需要输出shi，bai，qian
                }
            }
            left++;
        }
        if (havewei && right != len - 1) {
            cout << " " << wei[(len - 1 - right) / 4 + 2];  //双指针法，查找是否需要输出wan，yi
        }
        right += 4;
    }
    cout << endl;
    return 0;
}
