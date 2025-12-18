#include <iostream>

using namespace std ;

struct Complex {
    int r ;
    int i ;
};

Complex Input() ;
Complex Add(Complex num1, Complex num2) ;
Complex Multiply(Complex num1, Complex num2) ;
void Output(Complex sum) ;

int main() {
    Complex num1, num2, sum, product;
    cout << "Please input integers a,b,c,d: ";
    num1 = Input(); num2 = Input(); // Input 是输入函数
    sum = Add(num1, num2); // Add 是加法函数
    product = Multiply(num1, num2); // Multiply 是乘法函数
    cout << "Sum: "; Output(sum); // Output 是输出函数
    cout << endl << "Product: "; Output(product);
    return 0;
}

Complex Input() {
    Complex Temp ;
    cin >> Temp.r ;
    cin >> Temp.i ;
    return Temp ;
}
Complex Add(Complex num1, Complex num2){
    Complex Temp ;
    Temp.r = num1.r + num2.r ;
    Temp.i = num1.i + num2.i ;
    return Temp ;
}
Complex Multiply(Complex num1, Complex num2){
    Complex Temp ;
    Temp.r = num1.r*num2.r - num1.i*num2.i ;
    Temp.i = num1.r*num2.i + num1.i*num2.r ;
    return Temp ;
}
void Output(Complex z){
    if (z.r*z.r + z.i*z.i == 0) cout << '0' << endl ;
    else{
        if (z.r == 0) cout << z.i << 'i' << endl ;
        else{
            if (z.i == 0) cout << z.r << endl ;
            else cout << z.r << ( (z.i > 0) ? '+' : '\0' ) << z.i << 'i' <<endl ;
        }
    }
}
