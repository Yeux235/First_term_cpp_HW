#include <iostream>
#include <cstring>
#define HEAL_VALID 20
#define HEAL_EFFECT 10
using namespace std;

struct Actor{
    char name[10];
    int hp ;
    int atk ;
    int def ;
    bool heal ;
};

Actor &GetPlayer(char[], int);
Actor &GetEnemy(int);
void Action(Actor&, Actor&, int) ;

int main() {
    char name[10];
    int money, act;
    cout << "What's your name? (No more than 9 letters) ";
    cin >> name;
    cout << "How much will you pay for the game? $";
    cin >> money;
    Actor &player = GetPlayer(name, money);
    Actor &enemy = GetEnemy(money);

    cout << "===== " << player.name << " vs " << enemy.name << " =====" << endl;
    if(money < 1) { cout << "You Lose!" << endl; return 0; }
    for(int i=1; i<=10; ++i) {
        cout << "Round " << i << endl;
        cout << name << ((money < 20)? "'s act(1-attack; otherwise-wait" : "'s act(1-attack; 2-heal; otherwise-wait):") ;
        cin >> act ;
        if (act > 1 && money < 20) act++ ;

        Action(player, enemy, act);     //执行行为
        if(enemy.hp < 10 && enemy.heal) act = 2;     //enemy奶自己
        else act = 1;
        Action(enemy, player, act);
        if(player.hp > 0 && enemy.hp <= 0) {
            cout << "You Win!" << endl; return 0;
        }else if(enemy.hp > 0 && player.hp <= 0){
            cout << "You Lose!" << endl; return 0;
        }else if(player.hp <= 0 && enemy.hp <= 0) {
            cout << "End of Game with Draw." << endl;
            delete &enemy ;
            delete &player ;
            return 0;
        }
        cout << player.name << "'s remaining HP: " << player.hp << endl;
        cout << enemy.name << "'s remaining HP: " << enemy.hp << endl;
        cout << "---------------------" << endl;
    }
    cout << "End of Game with Draw." << endl;
    delete &player ;
    delete &enemy ;
    return 0;
}


Actor &GetPlayer(char name[], int m){
    cout << "Welcome to this game, " << name << '!' << endl ;
    Actor *Player = new Actor ;
    strcpy(Player->name, name) ;
    Player->hp = m ; Player->atk = m/2; Player->def = m/3 ;
    Player->heal = (m>=HEAL_VALID) ;
    cout << "Your status: HP" << Player->hp
             << ", ATK" << Player->atk
             << ", DEF" << Player->def << endl ;
    cout << "You can attack the enemy and heal yourself." << endl ;
    return *Player ;
}


Actor &GetEnemy(int m){
    cout << "Input a digit to choose your enemy (0 for Wolf, or otherwise Slime): ";
    int choice;
    cin >> choice;
    Actor *enemy = new Actor ;
    if (!choice) {
        strcpy(enemy->name, "Wolf") ;
        enemy->hp = 25 + m/4 ;
        enemy->atk = 9 + m/6 ;
        enemy->def = 6 +m/6 ;
        enemy->heal = false ;
    }else {
        strcpy(enemy->name, "Slime") ;
        enemy->hp = 20 + m/5 ;
        enemy->atk = 8 + m/6 ;
        enemy->def = 7 +m/6 ;
        enemy->heal = true ;
    }
    cout << "Your enemy " << enemy->name << ": HP" << enemy->hp << ", ATK" <<
    enemy->atk << ", DEF" << enemy->def << endl;
    return *enemy ;
}


void Action(Actor &user, Actor &target, int act )
{
    if(act == 1) {
        cout << user.name << " attacks " << target.name << "!" << endl;
        int damage = user.atk - target.def;
        if(damage < 0) damage = 0;
        target.hp -= damage;
    }else if(act == 2) {
        cout << user.name << " does self-healing!" << endl;
        user.hp += HEAL_EFFECT;
    }else cout << user.name << "is waiting..." << endl ;
}
