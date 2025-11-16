#include<iostream>

 using namespace std ;

 int main()
 {
     int money , x , y , z , sum = 0 ;
     cout << "Input:" ;
     cin >> money ;
     for (x = 1 ; 5*x < money ; ++x)    //我第一次试图写三层循环，但是写完了运行后xyz的值总是很奇怪。
     {
         for (y = 1 ; 2*y < money - 5*x ; ++y)
         {
             sum++ ;
         }
     }
     cout << "Methods = " << sum ;
     return 0 ;


 }
//以下是错误代码，请欣赏：
// int main()
 //{
//     int money , i , j , k , sum = 0 ;
//     cout << "Input:" ;
//     cin >> money ;
//     for ( i = 1 ; 5*i < money ; i++ )
//     {
//         for ( j = 1 ; 2*j < money - 5*i ; j++ )
//         {
//             for ( k = 1 ; k < money - 5*i - 2*j )     //错误代码示例：惯性思维导致的
//                if ( k = money - 5*i - 2*j ) sum++ ;
//         }
//     }
// }
