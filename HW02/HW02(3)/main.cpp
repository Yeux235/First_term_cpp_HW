#include <iostream>
using namespace std ;

int main()
{
    int litre ,cata ;
    char service ;
    double bill = 10 ;
    cout << "你要加几升油呀：" ;
    cin >> litre ;
    cout << "你要加哪种油（90/93/97/0）：" ;
    cin >> cata ;
    cout << "请选择服务等级（s自助服务/a协助服务）：" ;
    cin >> service ;
    cout << "结账：" ;
    if (service == 's')
        switch (cata) {
            case 0 : bill = (int (5.59*litre*95+0.5))*0.01 ; break ;
            case 90 : bill = ( int (5.82*litre*95+0.5))*0.01 ; break ;
            case 93 : bill = (int (5.96*litre*95+0.5))*0.01 ; break ;
            case 97 : bill = (int (6.36*litre*95+0.5))*0.01 ; break ;
        }
    if (service == 'a')
        switch (cata) {
            case 0 : bill = (int (5.59*litre*97+0.5))*0.01 ; break ;
            case 90 : bill = ( int (5.82*litre*97+0.5))*0.01 ; break ;
            case 93 : bill = (int (5.96*litre*97+0.5))*0.01 ; break ;
            case 97 : bill = (int (6.36*litre*97+0.5))*0.01 ; break ;
        }
    cout << bill ;
    return 0 ;
}
