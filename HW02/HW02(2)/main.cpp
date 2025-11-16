#include <iostream>

using namespace std;

int main()
{
    char a , b , c , d , e ;
    string x ;
    cout << "Veuillez entrer un nombre ид cinq chiffres: " ;
    a = cin.get() ;
    b = cin.get() ;
    c = cin.get() ;
    d = cin.get() ;
    e = cin.get() ;
    x =  (a == e && b == d) ? "Oui" : "Non" ;
    cout << "Sortie:" << x ;
    return 0;
}
