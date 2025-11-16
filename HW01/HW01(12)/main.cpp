#include <iostream>

using namespace std;

int main()
{
    int Int1 , Int2 ,AveInt ;
    float Flo1 , Flo2 ;
    cout << "请依次输入两个正整数，两个浮点数" ;
    cin >> Int1 >> Int2 >> Flo1 >> Flo2 ;
    cout << "Average:"<< (Int1 + Int2 + Flo1 + Flo2)/4 << endl ;
    AveInt = (Int1 + Int2 + Flo1 + Flo2)/4 + 0.5 ;
    cout << "Int Average :"<< AveInt ;
}
