#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int n, i, j, flag = 0;
    scanf("%d", &n);
    vector<int> ori(n), out(n);
    for (i = 0; i < n; i++)scanf("%d", &ori[i]);
    for (i = 0; i < n; i++)scanf("%d", &out[i]);
    for (i = 0; i < n - 1 && out[i] <= out[i + 1]; i++);
    for (j = i + 1; j < n && ori[j] == out[j]; j++);
    if (j == n) {
        printf("Insertion Sort\n");
        sort(ori.begin(), ori.begin() + i + 2);
    } else {
        printf("Merge Sort\n");
        for (i = 2; i / 2 <= n; i *= 2) {
            if (out == ori)flag = 1;
            for (j = 0; j < n; j += i) {
                sort(ori.begin() + j, ori.begin() + min(n, j + i));
            }
            if (flag)break;
        }
    }
    for (i = 0; i < n; i++) {
        if (i != 0)printf(" ");
        printf("%d", ori[i]);
    }
}
