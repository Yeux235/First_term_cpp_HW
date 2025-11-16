#include <iostream>
using namespace std ;

int main()
{
    float X , S ;
    int H , M  ;
    cout << "Input:" ;
    cin >> X ;
    H = X ;
    M = (X - H)*60 ;
    S = static_cast<int>(((X-H)*60-M)*60 + 0.5);
    cout << "Output:"<< H <<"h"<< M<<"m"<< S <<"s" ;
    return 0 ;
}
