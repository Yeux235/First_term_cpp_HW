#include <iostream>

using namespace std;

class Circle{
private:
    int x ;
    int y ;
    int Radius ;
public:
    Circle(){
        x = 0 ;
        y = 0 ;
        Radius = 0 ;
    }
    void getO(int &x1, int &y1){
        x1 = x ;
        y1 = y ;
    }
    void setR(int R){
        Radius = R ;
    }
    int getR(){
        return Radius ;
    }
    void moveTo(int x2, int y2){
        x = x2 ;
        y = y2 ;
    }
    void display(){
        cout << "X = " << x << ", Y = " << y << ", Radius = " << Radius <<endl;
    }
};



int main() {
    Circle a, b;
    int x, y, r;
    a.getO(x, y);
    cout << "The center of Circle A is: " << x << ", " << y << endl;
    cout << "Set the radius of Circle A to: "; cin >> r;
    a.setR(r);
    cout << "The radius of Circle A is: " << a.getR() << endl;
    b = a;
    cout << "Move the center of Circle B to: "; cin >> x >> y;
    b.moveTo(x, y); b.getO(x, y);
    cout << "The center of Circle B is: " << x << ", " << y << endl;
    b.display();
    return 0 ;
}
