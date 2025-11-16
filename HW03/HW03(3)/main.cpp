#include<iostream>
using namespace std ;

int main()
{
    char a ;
    cout << "Input:" ;
    do
    {
        a = cin.get() ;
        if (a != ' ')
            cout << a ;
    }
    while (a != '.') ;
    return 0 ;
}

/*int main()
{
    char a ;
    cout << "Input:" ;
    while ( true )
    {
        cin.get( a ) ;
        if (a != ' ') cout << a ;
        if (a == '.') break ;
    }
}*/
