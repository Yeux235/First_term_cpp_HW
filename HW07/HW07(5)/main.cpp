#include <iostream>

using namespace std;

int main()
{
    char temp ;
    char ch1[20] ;
    char ch2[20] ;
    char *p = ch1 ;
    cout << "Input:" ;
    while (p-ch1<20 ){
        *p = cin.get() ;
        if (*p == '\n') break ;
        p++ ;
    }
    *p = '\0' ;
    p = ch2 ;
    cout << "Input:" ;
    while (p-ch2<20){
        *p = cin.get() ;
        if (*p == '\n') break ;
        p++ ;
    }
    *p = '\0' ;
    p = ch1 ;
    while (*p!='\0' && *(ch2+(p-ch1))!='\0'){
        temp = *p ;
        *p = *(ch2+(p-ch1)) ; //指针相减有意义，指针相加无意义
        *(ch2+(p-ch1)) = temp ;
        p++ ;
    }
    cout << "Output:" << ch1 << endl ;
    cout << "Output:" << ch2 << endl ;
    return 0 ;
}
