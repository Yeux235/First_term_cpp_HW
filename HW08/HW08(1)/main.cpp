#include <iostream>

using namespace std ;

char *mystrrchr(char *str, char ch) ;


int main(){
    char str[32] ;
    char ch ;
    cout << "Input a string:" ;
    for (int i = 0; i < 32; i++){
        str[i] = cin.get() ;
        if (str[i] == '\n'){
            str[i] = '\0' ;
            break ;
        }
    }
    cout << "Input a char:" ;
    cin >> ch ;
    cout << "Output:" << mystrrchr(str, ch) ;
    return 0 ;
}



char *mystrrchr(char *str, char ch){
    char *p = str ;
    bool flag = false ;
    for (int i = 0; str[i] != '\0'; i++){ //在这里卡了半天，for括号里第二个位置写成==了。。。
        if (str[i] == ch){
            p = &str[i] ;
            flag = true ;
        }
    }

    if (flag) return p ;
    return nullptr ;
}
