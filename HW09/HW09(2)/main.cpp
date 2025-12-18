#include <iostream>
#include <cstring>

using namespace std ;

struct Date {
    int year ;
    int month ;
    int day ;

    void setDate(){
        cin >> year >> month >> day ;
    }
};
struct PerInf {
    char Name[21] ;
    Date Birthday ;
    char Tel[12] ;
    char Address[51] ;

    //注意setInfo传Input_date引用传递（或者写成指针不过略麻烦？）
    void setInfo(char *Input_name, Date &Input_date, char *Input_tel, char *Input_address){
        strcpy(Name, Input_name) ;
        Birthday = Input_date ;
        strcpy(Tel, Input_tel) ;
        strcpy(Address, Input_address) ;
    }

    //成员函数可以直接访问结构体内的所有成员变量
    void Output(){
        cout << Name <<" " << Birthday.year << '/'
                                          << Birthday.month <<'/'
                                          << Birthday.day << " "
                                          << Tel << " "
                                          << Address << endl ;
    }
};

int main(){
    int n ;
    cout << "Please input n(n < 10):" ;
    cin >> n ;
    char Input_name[21], Input_tel[12], Input_address[51] ;
    Date Input_date ;
    PerInf *Student = new PerInf [n] ;

    for(int i = 0; i < n; i++){
        cin.getline(Input_name,20,' ') ;
        Input_date.setDate() ;
        cin.getline(Input_tel,11,' ') ;
        cin.getline(Input_address, 50) ;
        Student[i].setInfo(Input_name, Input_date, Input_tel, Input_address) ;
        strcpy(Input_name, "") ;
        strcpy(Input_tel, "") ;
        strcpy(Input_address, "") ;
    }
    for (int i = 0; i < n; i++){
        Student[i].Output() ;
    }
    delete [] Student ;
    return 0 ;
}
