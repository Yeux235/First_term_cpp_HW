#include <iostream>
using namespace std ;
#define max_R 10

int main()
{
    int R, maxM_in_R, T[max_R][max_R], Max[max_R][max_R] = {0} ;    //处理递推数列Max的边界值

    cout << "Input R:" ;
    cin >> R ;
    cout << "Input triangle:\n" ;
    for (int i = 0; i < R; i++){
        for (int j = 0; j <= i; j++)        //注意j最多取到i，如果取到R会导致被阻塞
        cin >> T[i][j] ;
    }

//这部分求递推数列：加到（i , j）的最大值

    Max[0][0] = T[0][0] ;
    for (int i = 0; i < R-1; i++){          //这里注意i j都只到R-1
        for(int j = 0; j < R-1; j++)
            Max[i+1][j+1] = T[i+1][j+1] + ((Max[i][j] > Max[i][j+1]) ? Max[i][j] : Max[i][j+1]) ;
    }

//这部分求第R行以每个元素为终点的最大路径的最大值
    maxM_in_R = Max[R-1][0] ;           //先初始化一下maxM_in_R
    for (int j = 0; j < R; j++){
        if (Max[R-1][j] > maxM_in_R)
            maxM_in_R = Max[R-1][j] ;
    }
    cout << maxM_in_R ;
}
/*#include <iostream>
#include <algorithm>
using namespace std;

const int MAX_R = 10;

int main() {
    int R;
    int a[MAX_R][MAX_R] = {0};
    int dp[MAX_R][MAX_R] = {0};

    cout << "Input R: ";
    if (!(cin >> R) || R < 1 || R > MAX_R) return 0;

    cout << "Input triangle:\n";
    for (int i = 0; i < R; ++i) {
        for (int j = 0; j <= i; ++j) {     // ← 每行只读 i+1 个
            cin >> a[i][j];
            dp[i][j] = a[i][j];            // 初始化 dp 为原值，便于自底向上
        }
    }

    // 自底向上：dp[i][j] 表示从 (i,j) 到底部的最大路径和
    for (int i = R - 2; i >= 0; --i) {
        for (int j = 0; j <= i; ++j) {
            dp[i][j] = a[i][j] + max(dp[i + 1][j], dp[i + 1][j + 1]);
        }
    }

    cout << "Max sum = " << dp[0][0] << "\n";
    return 0;
}
*///这是ChatGPT给的优化算法，从下向上算max，最终Max[0][0]即为最大路径
