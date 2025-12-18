#include <iostream>
#include <cstring>
#define HEAL_VALID 20
#define HEAL_EFFECT 10
#define TOTAL_MONEY 50
using namespace std;
class Weapon{
 public:
     Weapon(const int eff, const int pri) : effect(eff), price(pri){
     } //effect和price均为常量，要在这里初始化
    const int effect;
    const int price;
};
class Actor{
    char name[10];
    int hp;
    int atk;
    int def;
    bool heal;
    bool isPlayer;    //Action函数中判断是否需要cin>>act
public:
    Actor(char *name_, int money);
    Actor(int enemy_choice, int money);
    void Action(Actor &foe);
    void equip(const Weapon &w){atk += w.effect;}
    char *get_name(){return name;}  //主模块里无法直接访问private内的变量
    int get_hp(){return hp;}
};
int main()
{
    char name[10];
    int money, enemy_choice, weapon_choice;
    Weapon sword(10, 10);
    cout << "What's your name? (No more than 9 letters) ";
    cin >> name;
    cout << "You have $" << TOTAL_MONEY << " in total." << endl;
    cout << "How much will you pay for your basic attributes? $";
    cin >> money;
    Actor player(name, money);
    cout << "---------------------" << endl;
    cout << "Input a digit to choose your enemy (0 for Wolf, or otherwise Slime): ";
    cin >> enemy_choice;
    Actor enemy(enemy_choice, money);
    cout << "---------------------" << endl;
    cout << "You have $" << TOTAL_MONEY - money << " left." << endl;

    if(TOTAL_MONEY - money >= sword.price) {
        cout << "If you want to spend $10 to buy a sword, input 1: ";
        cin >> weapon_choice;
        if(weapon_choice == 1){
            cout << name << " has a sword now! ATK+" << sword.effect << "!" << endl;
            player.equip(sword);
        }else cout << name << " has no sword." << endl;
    }
    cout << "===== " << player.get_name() << " vs " << enemy.get_name() << " ====="
            << endl;
    if(money < 1) {cout << "You Lose!" << endl; return 0;}

    //for循环对战部分
    for(int i=1; i<=10; ++i) {
        cout << "Round " << i << endl;
        player.Action(enemy);
        enemy.Action(player);
        cout << player.get_name() << "'s remaining HP: " << player.get_hp() << endl;
        cout << enemy.get_name() << "'s remaining HP: " << enemy.get_hp() << endl;
        cout << "---------------------" << endl;
        if (player.get_hp() <= 0 && enemy.get_hp() > 0){
            cout << "You Lose!";
            return 0;
        }
        if (player.get_hp() > 0 && enemy.get_hp() <= 0){
            cout << "You Win!";
            return 0;
        }
    }
    cout << "End of Game with Draw." << endl;
    return 0;
}
Actor :: Actor(char *name_, int money) { //这个是玩家的构造函数
        strcpy(name, name_);
        hp = money;
        atk = money/2;
        def = money/3;
        heal = (money>=HEAL_VALID);
        isPlayer = true;
        cout << "Welcome to this game, "<< name<<endl;
        cout << "Your status: HP" <<hp<<", ATK"<<atk<<",, DEF"<<def<<endl;
        cout << "You can act with 1 to attack the enemy, " << (heal? "2 to heal yourself, " : "") <<
"and otherwise wait" << endl;
}

Actor :: Actor(int enemy_choice, int m){
        if(!enemy_choice){
            strcpy(name, "Wolf") ;
            hp = 25 + m/4 ;
            atk = 9 + m/6 ;
            def = 6 +m/6 ;
            heal = false ;
            isPlayer = false;
            cout << "Your enemy Wolf: HP" << hp << ", ATK"<<atk<<", DEF"<<def<<endl;
        }else{
            strcpy(name, "Slime") ;
            hp = 20 + m/5 ;
            atk = 8 + m/6 ;
            def = 7 +m/6 ;
            heal = true ;
            isPlayer = false;
            cout << "Your enemy Slime: HP" << hp << ", ATK"<<atk<<", DEF"<<def<<endl;
        }
    }
void Actor::Action(Actor &foe){
    int act;
    if (isPlayer) {
        cout << name << "'s act:" ;
        cin >> act ;
        if (act > 1 && !heal) act++ ;
        if(act == 1) {
            cout << name << " attacks " << foe.get_name() << '!' << endl;
            int damage = atk - foe.def;
            if(damage < 0) damage = 0;
            foe.hp -= damage;
        }else if(act == 2) {
            cout << name << " does self-healing!" << endl;
            hp += HEAL_EFFECT;
        }else cout << name << "is waiting..." << endl;
    }else {
        cout << name << " attacks " << foe.get_name() << '!' << endl;
    }
}
