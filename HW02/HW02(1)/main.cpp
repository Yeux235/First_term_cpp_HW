#include <iostream>

using namespace std;

int main()
{
    char x ;
    cout << "Input :" ;
    cin >> x ;
    cout << "Output: " ;
    if ((x > 64 && x < 91) || (x >96 && x < 123) )
        switch (x) {
            case 65: cout << "Vowel" ; break ;
            case 97: cout << "Vowel" ; break ;
            case 69: cout << "Vowel" ; break ;
            case 101: cout << "Vowel" ; break ;
            case 73: cout << "Vowel" ; break ;
            case 105: cout << "Vowel" ; break ;
            case 111: cout << "Vowel" ; break ;
            case 79: cout << "Vowel" ; break ;
            case 85: cout << "Vowel" ; break ;
            case 117: cout << "Vowel" ; break ;
            default : cout <<"Consonant" ;
        }
    else  cout << "Not a letter" ;

    return 0;
}
