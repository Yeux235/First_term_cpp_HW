#include <iostream>
using namespace std ;


int myfun(int arr[7]) {
    int mult = 1, add = 0, num_not_0 = 0 , result ;
    bool flag ;

    for (int i=0; i<7; ++i){
        add += arr[i] ;
        mult *= ((!(bool)arr[i])+arr[i]) ;  //要点：通过bool强制类型转换构造了{a_n} = 1，1，2，3，4……
        num_not_0 += (bool)arr[i] ; //非零个数
    }

    flag = num_not_0 % 2 ;
    result = flag * add + (!flag) * mult ;
    return result ;
}


int main(){
    int arr[7] ;
    cout << "Input:" ;
    for(int i=0; i<7; ++i){
        cin >> arr[i] ;
    }
    cout << "Output:" << myfun(arr) ;
}
