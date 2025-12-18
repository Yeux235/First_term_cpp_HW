#include <iostream>

using namespace std;

class SavingAccount{
private:
    static int counter; //设置idx，在类内明确数组长度

    static double rate;
    int idx;
    double amount = 0; //？
    double interest = 0;
public:
    SavingAccount(){
        idx = ++counter;
        /*amount = 0; interest = 0;*/

    }
    static void setRate(double newRate){
        rate = newRate;
    }
    static void nextMonth(SavingAccount sa[]){
        for (int i = 0; i<counter; i++){
            sa[i].interest = sa[i].amount*rate;
            sa[i].interest = (int(100* sa[i].interest+0.5))/100.0;
            sa[i].amount += sa[i].interest;
        }
    }
    void deposit(double amount){
        this->amount += amount;
    }

    void show(){
        cout << "Account No." << idx << ':' << amount;
    }
};

int SavingAccount::counter = 0; //must initialize static member variable outside the class
double SavingAccount::rate = 0;

int main() {
    int num, index;
    double rate, amount;
    cout << "Number of Accounts: ";
    cin >> num;
    SavingAccount *sa = new SavingAccount [num];

    while(true) {
        cout << "Input the monthly rate: ";
        cin >> rate;
        SavingAccount::setRate(rate); //设置本月利率
        cout << "Input the index, amount for deposit: ";
        cin >> index >> amount;
        if (index < 0 || index >= num) break;
        sa[index].deposit(amount); //存款
        SavingAccount::nextMonth(sa); //时间经过一个月
    }
    cout << "Input the index for output: ";
    cin >> index;
    sa[index].show(); //显示账户的账号和当前金额

    return 0;
}
