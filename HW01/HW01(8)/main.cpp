#include <iostream>
#include <iomanip>
using namespace std ;

int main()
{
    char A , B ;
    cout << "Input:" ;
    cin >> A >> B ;
    cout << (A-64) / 10 << (A-64) % 10 << (B-64) /10 << (B-64) %10 ;
    return 0 ;

}
