
#include <iostream>
#include <stack>

using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    int sum = a + b;


    if (sum == 0) {
        cout << 0 << endl;
    } else {
        bool fu = false;
        if (sum < 0) {
            fu = true;
            sum *=(-1);
        }
        stack<char> stack;
        int cnt = 0;
        while (sum > 0) {

            char temp = sum % 10 + '0';
            sum /= 10;
            stack.push(temp);
            ++cnt;
            if (cnt % 3 == 0) {
                stack.push(',');
            }
        }
        if (stack.top() == ',') {
            stack.pop();
        }
        if (fu) {
            stack.push('-');
        }
        while (!stack.empty()) {//注意弹出栈的内容
            cout << stack.top();
            stack.pop();
        }
    }
    return 0;
}
