#include <iostream>
using namespace std ;

int main()
{
    char a , b , c ;
    int n ;
    cout << "Input1 :" ;
    cin.get ( a ) ;
    cin.get ( b ) ;
    cin.get ( c ) ;
    cout << "Input2 :" ;
    cin >> n ;

    if ( a-n <'A')  a = 'Z'+1-('A'-a+n) ; else a -= n ;
    if ( b-n <'A')  b = 'Z'+1-('A'-b+n) ; else b -= n ;
    if ( c-n <'A')  c = 'Z'+1-('A'-c+n) ; else c -= n ;
    cout << "Output :" << a << b << c ;
}
