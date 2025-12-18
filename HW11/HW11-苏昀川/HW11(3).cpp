#include <iostream>

using namespace std;

class Cell;

class Virus{
    int life;
public:
    Virus(int x):life(x){}
    void eat(Cell &c, int amount);
    bool time_pass() { life--; return (life ? true : false); }
};

class Cell{
    friend class Virus;
 private:
    int size;
 public:
    Cell(int x):size(x){}
    void time_pass(){if(size) size++;}
};

int main() {
    int cell, virus, amount, cnt;
    cout << "Input cell, virus, amount: "; cin >> cell >> virus >> amount;
    Cell c(cell); Virus v(virus);
    for(cnt=0; ; cnt++){
        v.eat(c, amount);
        if( ! v.time_pass() ) break;
        c.time_pass();
    }
    cout << "Output: Time = " << cnt << endl;
    return 0;
}
void Virus::eat(Cell &c, int amount){
    amount = (amount > c.size) ? c.size : amount ;
    life += amount;
    c.size -= amount;
}
