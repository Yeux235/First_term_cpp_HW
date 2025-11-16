#include <iostream>

using namespace std;
#define MAX_SIZE 10

int main(){
    int m, n,mat[MAX_SIZE][MAX_SIZE] ;
    bool found = false ;
    cout << "Please input m, n:" ;
    cin >> m >> n ;
    cout << "Please input array:" ;
    for (int i = 0; i < m; i++){
        for (int k = 0; k < n; k++)
            cin >> mat[i][k] ;
    }


    for (int i=0; i < m; i++){
        int row_max = mat[i][0], col_min ;
            //=====首先找i行最大值=====
        for (int k = 1; k < n; k++){
            if (mat[i][k] >= row_max) row_max = mat[i][k] ;
        }
            //=====然后遍历i行最大元素们=====
        for (int k = 0; k < n; k++){
            if (mat[i][k] == row_max){
            //===开始找最大元素所在列的最小值===
                col_min = mat[0][k] ;
                for (int j = 1; j < m; j++){
                    if ( mat[j][k] < col_min ) col_min = mat[j][k] ;
                }

            //===找出列最小值并确认是否为鞍点===
                for (int j = 0; j < m; j++){
                    if (mat[j][k] == col_min){
                        if ( i == j ){
                            cout << "mat[" << i << "][" << k << "]=" << col_min << endl ;
                            found = true ;      //用bool flag判断语句是否执行过
                        }
                    }
                }
            }
        }
    }
    if ( !found   cout << "not found" ;
    return 0 ;
}
