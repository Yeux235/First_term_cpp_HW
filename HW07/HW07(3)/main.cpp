#include <iostream>
#include <cstring>
using namespace std ;


bool leap_year(int year) ;
char* Julian(int year, int day) ;

int main(){
    int year, day ;
    cout << "Please input year and day:" ;
    cin >> year >> day ;
    if (!strcmp(Julian(year, day), "NULL") )
        cout << "Output:" << "N/A" ;
    else
        cout << "Output:" << Julian (year, day) ;
    return 0 ;
}


bool leap_year(int year){
    if (year % 4 == 0){
        if (year % 100 == 0){
            if (year % 400 == 0)
                return true ;
            else
                return false ;
        }
        return true ;
    }
    else
        return false ;
}

char* Julian(int year, int day){
    char month[12][7] = { "Jan.", "Feb.", "Mar.", "Apr.", "May", "Jun.",
                            "Jul.", "Aug.", "Sept.", "Oct.", "Nov.", "Dec." } ;
    char date[3] ;
    static char buffer[10] ;//用于储存拼接的字符串 生命周期
    buffer[0] = '\0' ;//strcat拼接字符串会以第一个字符串的\0为起始

    int num[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31} ;
    int remainder = day ;
    int i = 0 ;
    if (leap_year( year)) num[1] = 29 ;

    while ( remainder > num[i]){
        remainder -= num[i++] ;
        if (i == 12){
            strcat (buffer, "NULL");
            return buffer ;
        }
    }
    //朴素的方法把int变为str[]
    date[1] = (remainder/10) ? remainder%10 + '0' : ' ' ;
    date[0] = (remainder/10) ? remainder/10 + '0' : remainder%10 + '0' ;
    date[2] = '\0' ;

    strcat (buffer, month[i]) ;
    strcat (buffer, " ") ;
    strcat (buffer, date) ;
    return buffer ;

}
