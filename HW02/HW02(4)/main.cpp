#include <iostream>

using namespace std;

int main()
{
    int x[4] , y[4] , x14 ,y14 ,x13 ,y13 ,x23 ,y23 ,x24 ,y24 ,x34 ,y34 ;
    float cossA , cossB ;
    cout << "Input:" ;
    cin >> x[1] >> y[1] ;
    cout << "Input:" ;
    cin >> x[2] >> y[2] ;
    cout << "Input:" ;
    cin >> x[3] >> y[3] ;
    cout << "Input:" ;
    cin >> x[4] >> y[4] ;
    x14 = x[1]-x[4] ;
    y14 = y[1]-y[4] ;
    x13 = x[1]-x[3] ;
    y13 = y[1]-y[3] ;
    x24 = x[2]-x[4] ;
    y24 = y[2]-y[4] ;
    x23 = x[2]-x[3] ;
    y23 = y[2]-y[3] ;
    x34 = x[3]-x[4] ;
    y34 = y[3]-y[4] ;
    cossA = (x14*x14 + y14*y14 +x13*x13 + y13*y13 - x34*x34 - y34*y34)/( 4*(x14*x14 + y14*y14)*(x13*x13 + y13*y13) ) ;
    cossB = (x24*x24 + y24*y24 +x23*x23 + y23*y23 - x34*x34 - y34*y34)/( 4*(x24*x24 + y24*y24)*(x23*x23 + y23*y23) ) ;
    if ( cossA == cossB ) {
        if ((x34*y[2] - y34*x[2] -x[3]*y[4]+x[4]*y[3]) * (x34*y[1] - y34*x[1] -x[3]*y[4]+x[4]*y[3]) > 0 ) {
            if ((x14*x13 + y14*y13)*(x24*x23 + y24*y23) > 0)
                cout << "您别说，这四个点儿还真共圆儿" ;
            else {
                if ((x14*x13 + y14*y13 == 0) && (x24*x23 + y24*y23 == 0) )
                    cout << "这四个点不仅共圆，还构成至少两个直角呢" ;
                else cout << "不共圆" ;
            }
        }
        else{
            if ((x34*y[2] - y34*x[2] -x[3]*y[4]+x[4]*y[3]) * (x34*y[1] - y34*x[1] -x[3]*y[4]+x[4]*y[3]) == 0) cout << "这四个点里至少有三个点共线哦，所以不共圆" ;
            else{
                 if ((x14*x13 + y14*y13)*(x24*x23 + y24*y23) < 0)
                    cout << "您别说，这四个点儿还真共圆儿" ;
                else {
                    if ((x14*x13 + y14*y13 == 0) && (x24*x23 + y24*y23 == 0) )
                        cout << "这四个点不仅共圆，还构成两个直角呢" ;
                    else cout << "不共圆" ;
                }
            }
        }
    }

    else cout << "不共圆。" ;
        return 0 ;

}
