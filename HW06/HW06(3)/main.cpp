#include <iostream>
#include <cstring>
using namespace std;


bool func(char array[ ], int len);


int main() {
    char ch[20];


    cout<< "Input: ";
    cin >> ch;


    cout << "Output:" ;
    if (ch[0] == ch[strlen(ch)-1]){
        if (func(ch, strlen(ch)))
            cout << "Yes" ;
        else cout << "No" ;
    }
    else cout << "No" ;
    return 0;
}


bool func(char array[ ], int len) {
    if (array[0] != array[len-1])
        return false ;
    else
        if(len <=1) return true ; //递归出口
        else return func(array+1, len-2) ; //在这里递归，我死活没想到。
}


