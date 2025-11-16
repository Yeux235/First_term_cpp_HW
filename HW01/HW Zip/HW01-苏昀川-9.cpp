#include <iostream>

using namespace std;

int main()
{
    int F ;
    float C100 , C ;
    cout << "Input F:" ;
    cin >> F ;
    C100 = 5*(100*F - 3200)/9.0 + 0.5 ;
    C = int ( C100 ) / 100.0 ;
    cout << "Output:" << C ;
    return 0;
}
