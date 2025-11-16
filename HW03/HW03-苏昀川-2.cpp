#include <iostream>

using namespace std ;

int main()
{
    int sisyphus , even = 0 , odd = 0 , temp , sis2 ;
    cout << "Input a natural number:" ;
    cin >> sisyphus ;
    cout << sisyphus ;
    while (true)        //这个循环用于输出每次的结果
    {
        odd = 0 ;
        even = 0 ;
        temp = sisyphus ;
        while ( temp > 0 )       //这个循环在求数字的偶数奇数个数
        {
            if ((temp % 10) % 2 == 0) even ++ ;
                else odd ++ ;
            temp /= 10 ;
        }
        sis2 = 100*even + 10*odd + even + odd ;      //暂存每次的结果
        if (sis2 == sisyphus) break ;
        cout << "->" <<sis2 ;
        sisyphus = sis2 ;
    }
}
