#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int N;
    long long p;
    cin >> N >> p;	//N为数组长度，p为参数 
    int a[N];
    for (int i = 0; i < N; i++)
        cin >> a[i];
    sort(a, a + N);	//递增
    
    int result = 0, temp = 0;	//temp为第一个指针确定的情况下，满足构成完美数列的数字个数 
    for (int i = 0; i < N; i++)
	{
		//result一直在增大，当第一个指针后移时，第二个指针在第一个指针之后的第result个开始即可 
        for (int j = i + result; j < N; j++)	
		{
            if (a[j] <= a[i] * p)
			{
                temp = j - i + 1;
                if (temp > result)	//result一直在增大 
                    result = temp;
            }
			else
			{
                break;	//跳出内层循环，第一个指针后移 
            }
        }
    }
    cout << result;
    return 0;
}
