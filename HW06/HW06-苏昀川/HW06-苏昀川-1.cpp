#include <iostream>
using namespace std ;


bool perfectNumber(int n){
    int sum = 1 ;
    if (n == 1) return true ;
    else {
        for (int i = 2; i < n; i++){
            if (n % i == 0) sum += i ;
        }
        if (sum == n) {
            sum = 1 ;
            return true ;
        }
        else {
            sum = 1 ;
            return false ;
        }
    }
}

int main(){
    int m, n ;
    cout << "Input m, n:" ;
    cin >> m >> n ;
    cout << "Perfect Number in [" << m << "," << n << "]:" ;
    for (int k = m; k <= n; k++){
        if (perfectNumber( k ))
            cout << k << " " ;
    }
    return 0 ;
}
