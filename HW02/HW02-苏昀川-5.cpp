#include<iostream>
using namespace std ;

int main(){
    int x = 1 , n , s = 0 ;
    int a ;
    cout << "Input a,n:" ;
    cin >> a >> n ;
    for ( int k = 0; k < n; ++k ){
        s += x*(n-k) ;
        x *= 10 ;
    }

    cout << "Output:" << a*s ;
    return 0 ;
}
