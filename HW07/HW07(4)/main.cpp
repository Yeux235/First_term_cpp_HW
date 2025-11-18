#include <iostream>


const int MAX_LEN = 20 ;
const int BUFFER_SIZE = MAX_LEN + 1 ;

using namespace std;

int minlen(char **str, int n) ;
int counting(char *p) ;

int main()
{
    int n ;
    cout << "Input:" ;
    cin >> n ;
    while (cin.get() != '\n') ;
    //while循环不断用掉缓冲区多余字符，直到换行符
    char **str = new char*[n] ;
    //表示开辟n块空间，储存char*，再返回这些空间首地址

    for (int i = 0; i <= n; i++){
        str[i] = new char[BUFFER_SIZE] ;
        cin.getline(str[i], 20) ;
    }
    cout << "Output:" << minlen(str, n) ;
}


int minlen(char **str, int n){
    int minimum = counting(str[0]) ;//初始变量
    //幽默的是，我第一遍写的时候又写错了逻辑，相邻两数小值赋给了min……
    for (int i = 0; i < n ; i++){
        if (counting(str[i]) < minimum)
            minimum = counting(str[i]) ;//更新变量min
    }
    return minimum ;
}

int counting(char *p){
    int sum = 0  ;
    int i = 0 ;
    while (p[i] != '\0'){
        if (p[i++] != ' ') sum++ ;
    }
    return sum ;
}
