#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void dfs(int root, int depth);

vector<vector<int>> vec;
vector<int> levelnum(101);
int n, m, id, k;

int main() {
    scanf("%d %d", &n, &m);
    vec.resize(n + 1);
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &id, &k);
        vec[id].resize(k);
        for (int j = 0; j < k; j++) {
            scanf("%d", &vec[id][j]);
        }
    }
    dfs(1, 1);
    int index = max_element(levelnum.begin(), levelnum.end()) - levelnum.begin();     //max_element属于头文件algorithm，对数组操作，找到最大的元素，并返回一个迭代器
    printf("%d %d\n", levelnum[index], index);


    return 0;
}

void dfs(int root, int depth) {
    levelnum[depth]++;
    if (vec[root].empty()) {
        return;
    }
    for (int i = 0; i < vec[root].size(); i++) {
        dfs(vec[root][i], depth + 1);
    }
}
