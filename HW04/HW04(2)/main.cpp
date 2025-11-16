#include<iostream>
using namespace std ;
#define max_num 1000

int main()
{
    int k, n ;
    bool arr[max_num] = {0} ;
    cin >> n >> k ;

    for ( int j = 1; j <= k; j++ ){
        for ( int i = 0; i < n; i++ ){
            if ((i+1) % j == 0)
              arr[i] = !arr[i] ;
        }
    }
    for (int i = 0; i < n; i++){
        if ( arr[i] )
            cout << i+1 << " " ;
    }
}
