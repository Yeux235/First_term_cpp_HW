#include <iostream>
#include <cstring>

using namespace std;

class LongLongInt {
private:
    int length;
    char *digit;
    void turnover(char *&digits){
        for (int s=0, e=strlen(digits)-1; s<e; s++, e--){
            char temp = digits[s];
            digits[s] = digits[e];
            digits[e] = temp;
        }
    }
    void cleanup(){
        if (digit){
            delete [] digit;
            digit = nullptr;
        }
        length = 0;
    }
public:
    LongLongInt(const char *p = "") : length(0), digit(nullptr) {//初始化列表？
        length = strlen(p);
        digit = new char[length+1];
        strcpy(digit, p);
    }
    //下面是拷贝构造函数
    LongLongInt(const LongLongInt& other){
        length = other.length;
        digit = new char[length+1];
        strcpy(digit, other.digit);
    }
    ~LongLongInt(){
        cleanup();
    }
    //赋值运算符重载
    LongLongInt& operator=(const LongLongInt& other){
        if (this!=&other) {   //考虑b=b情况
            cleanup();
            length = other.length;
            digit = new char [length+1];
            strcpy(digit, other.digit);
        }
        return *this;
    }

    void add(LongLongInt &a1, LongLongInt &a2){
        //倒序 不算'\0'
        turnover(a1.digit);
        turnover(a2.digit);
        //相加
        LongLongInt &longer = ( a1.length >= a2.length ? a1 : a2);
        char *tempRes = new char[longer.length+2];

        int idx = 0;
        int carry = 0;

        while (idx<longer.length || carry){
            int val1 = (idx<a1.length) ? (a1.digit[idx]-'0') : 0;
            int val2 = (idx<a2.length) ? (a2.digit[idx]-'0') : 0;
            int sum = val1 + val2 + carry;

            tempRes[idx] = (sum%10) + '0';
            carry = sum/10;
            idx++;
        }
        tempRes[idx] = '\0';

        cleanup();
        length = idx;
        digit = tempRes;

        turnover(a1.digit);
        turnover(a2.digit);
        turnover(this->digit);
    }
    void add(LongLongInt &a, int x){
        char temp[10];
        int tempX = x, i = 0;
        if (tempX == 0){
            temp[i++] = '0'; temp[i] = '\0';
        }else{
            while(tempX > 0){
                temp[i++] = (tempX%10)+'0';
                tempX /= 10;
            }
            temp[i] = '\0';
        }
        for(int s=0, e=i-1; s<e; s++, e--) {
            char t = temp[s];
            temp[s] = temp[e];
            temp[e] = t;
        }
        LongLongInt tempObj(temp);
        this->add(a, tempObj); //为啥加this？
    }
    const char *display() const {return digit;} //为啥加const


};


int main() {
    int n, x;
    cout << "Number of digits: ";
    cin >> n; cin.get();
    char *p = new char[n+1];
    cout << "Input: ";
    for(int i=0; i<n; i++) cin.get(p[i]);
    p[n] = '\0';
    LongLongInt a(p); delete [] p;
    LongLongInt b = a;
    cout << "Add: ";
    cin >> x;
    b.add(a, x);
    cout << "Output b: " << b.display() << endl;
    a.add(b, a);
    cout << "Output a: " << a.display() << endl;
    return 0;
}
