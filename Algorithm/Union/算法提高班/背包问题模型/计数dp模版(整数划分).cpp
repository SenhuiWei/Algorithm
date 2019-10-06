// n = n1 + n2 + ... + nk;
#include <iostream>

using namespace std;

const int N = 1010, mod = 1e9 + 7;

int n;
int f[N];

int main() {
    cin >> n;
  
    // 三重循环到两重到一维的最终优化版
    f[0] = 1; // 初始化空集为1 一定不要忘记
    for (int i = 1; i <= n; i ++) {
        for (int j = i; j <= n; j ++) {
            f[j] = (f[j] + f[j - i]) % mod;
            // 朴素：f[i][j] = f[i - 1][j] + f[i][j - i];
        }
    }
    
    cout << f[n] << endl;

    return 0;
}

/*
    初始化空集为1始化空集f[0] = 1的原因:
    从状态转移方程f[j] = (f[j] + f[j - i]) % mod;可以看到
    只有可能f[j - i] 是f[0]，而这是其实就是表示我用一个i完成了划分，所以也是一种方案
    拿n = 2举例
    模拟循环如下:
    i = 1
    f[1] = f[1] + f[0]; // 右边f[1] = 0,f[0] = 1; 表示用一个1去划分1这个方案
    f[2] = f[2] + f[1]; // 右边f[2] = 0,f[1] = 1; 表示用两个1去划分2这个方案
    i = 2
    f[2] = f[2] + f[0]; // 右边f[2] = 1,f[0] = 1;     右边f[2]的1表示前面用两个1去划分2的方案，右边f[0] = 1表示用一个2去划分为2的这个方案

    背包问题 是否初始化根据具体表达式
    1.求最值不需要初始化
    因为从表达式f[j] = max(f[j], f[j - v[i]] + w[i]);中可以看出f的值是会增长的

    2.求方案数需要初始化f[0] = 1;
    而f[j] = f[j] + f[j - i]若不初始化为0是不可能增长的 

    朴素做法解释：
    f[i][j] = f[i - 1][j] + f[i - 1][j - i] + f[i - 1][j - 2 * i] + ...;
    f[i][j - i] =           f[i - 1][j - i] + f[i - 1][j - 2 * i] + ...;
    因此f[i][j] = f[i - 1][j] + f[i][j - i];

    二维到一维优化
    j正向遍历即可，因为这样可以保证是等价变形
*/