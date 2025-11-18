#include <iostream>
using namespace std ;

int main() {
    int total, n, sum = 0 ; //total用于计算剩余玩家数量，以作为终止条件
    int index = 0 ;
    bool *arr = new bool [n] ;


    cout << "Please input n:" ;
    cin >> n ;
    total = n ;
    for (int i = 0; i < n; i++)
        arr[i] = true ;


    while(arr[index]&&total > 1){
        sum++ ;                             //sum每

        if (sum == 3){
            sum = 0;
            arr[index] = false ;
            total-- ;
        }
        do {
            if (index < n-1) index ++ ;
            else index -= n-1 ;
        }while (!arr[index]) ;
    }
    cout << "Last code:" << index + 1 ;
}
