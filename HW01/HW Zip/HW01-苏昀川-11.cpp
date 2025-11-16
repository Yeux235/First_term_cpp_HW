#include <iostream>
#include <cmath>
using namespace std ;

int main()
{
    float lat1 ,lat2 ,long1 ,long2 ,pi = 3.14159 ,D ;
    cout << "请输入第一组经度 纬度值：" <<endl ;
    cin >> long1 >> lat1  ;
    cout << "请输入第二组经度 纬度值：" <<endl ;
    cin >> long2 >> lat2 ;
    long1 = ( long1 /180 )*pi ;
    long2 = ( long2 /180 )*pi ;
    lat1 = ( lat1 /180 )*pi ;
    lat2 = ( lat2 /180 )*pi ;
    D = 6371 * acos( cos(lat1)*cos(lat2)*cos(long1 - long2) + sin(lat1)*sin(lat2) ) ; //这里D似被同化为float型，但又有所不同：
    D = static_cast<int>(D + 0.5) ;
    cout << D << "km" ;
}
