#include <iostream>

using namespace std ;
int main()
{
    long x , y , i = 2 ;
    while ( i == 2 )
        {
        cin >> x ;
        while ( x < 100 || x > 999)
            {
            cout << "请输入一个”正“三位数" ;
            cin >> x ;
            }
        y = ( x - ( x / 100 ) *100 ) ;
        cout << "百位数：" << ( x / 100 ) <<'\n'<<"十位数：" << ( y / 10 ) <<'\n'<< "个位数：" << ( x - ( x / 100 )*100 - (y/10)*10 ) <<  endl ;
        cout << "继续输入请按2，结束程序请按4" ;
        cin >> i ;
        if ( i != 2) continue ;
        cout << " 请输入一个正三位数：" ;
        }
    return 0 ;
}





