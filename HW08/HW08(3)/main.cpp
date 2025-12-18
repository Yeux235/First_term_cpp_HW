#include <iostream>
using namespace std;

char *myfun(int &a, int &b) ;
char *p = new char[3]{'0', ' ', '\0'} ;
int myfun(int *a, int *b);
int main() {
    int x, y;
    cout << "Input: ";
    cin >> x >> y;
    cout << "Output: ";
    cout << myfun(x, y);
    cout << x << ' ' << y;
    return 0;
}

int myfun(int *a, int *b) {
    int c = *a - *b;
    *a *= 2;
    *b *= 3;
    return c;
}
char *myfun(int &b, int &a){        //这里b为x别名，a为y别名
    *p = '0' + (-myfun(&a, &b)) % 10 ;   //这里取y、x地址
    return p ;
}
