#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;


const int NUM_STATUS = 4, NUM_MEMBER = 3;

struct statusNames {
    const char *statusName ;
};

struct skillNames {
    const char *skillNames ;
};

struct Hero {
    const char *name ;
    int status[4] ;
    double threshold[4] ;
    skillNames skNames[2] ;
    statusNames sNames[4] = { {"HP"}, {"ATK"}, {"DEF"}, {"Skill"} } ;

    //这里不方便直接写setInfo函数，因为无法对常量指针name再赋值。
};




void PlayerTraining(int day, Hero (&hero)[3] ) ;
void OutputStatus(Hero &hero) ;
bool MemberTraining(int plan, Hero &hero/*, int W_F[ ], bool success_or_not[]*/) ;


int main(){
    int PlayerID, day ;
    struct  Hero hero[3] = {
                                             { {"Warrior"}, {20, 10, 10, 0}, {0.8, 0.6, 0.8, 0.2}, {"Taunt", nullptr} },
                                             { {"Archer"}, {16, 12, 8, 0}, {0.6, 0.8, 0.6, 0.3}, {"Focus", nullptr} },
                                             { {"Priest"}, {12, 6, 10, 0}, {0.6, 0.6, 0.6, 0.4}, {"Heal", "Cure"} }
                                         };

    cout << "Player ID and Days for Training:" ;
    cin >> PlayerID >> day ;
    srand(PlayerID) ;

    PlayerTraining(day, hero) ;

}



void PlayerTraining( int day, Hero (&hero)[3]) {
    int plan = 0 ;
    int win_times = 0 ;

    for(int num = 0; num<3; num++)
    OutputStatus(hero[num]) ;
    for(int i = 0; i<60; i++) cout << "-" ;
    cout << '\n' ;

    for (int d = 0; d < day; d++){
        bool success[3] = {false} ;
        cout << "Day" << d+1 <<endl ;
        do{
            cout << "Select the training plan(1-HP, 2-ATK, 3-DEF, 4-Skill):" ;
            cin >> plan ;
        }while (plan < 0 || plan > 4) ;
        if (plan == 0) break ;

        cout << hero[0].sNames[--plan].statusName << " Training:" << endl;
        for(int j = 0; j < 3; j++){
            success[j] = MemberTraining(plan, hero[j]) ;
            win_times += success[j] ;
        }

        //接下来就是输出单次训练结果，分类情况需明确
        if (plan == 3){
            for (int a = 0; a < 3; a++){
                cout << hero[a].name << " " ;
                if (!success[a]) cout << "Failure" << endl ;
                else{
                    cout << "Success" ;
                    if (hero[a].status[3] == 1) cout << ", Skill\"" << hero[a].skNames[0].skillNames << "\" is learned" << endl ;
                    else {
                        if (a!=2) cout << ", No more skills to learn" << endl ;
                        else {
                            if (hero[2].status[3] == 2) cout << ", Skill\"" << hero[2].skNames[0].skillNames << "\" is learned" << endl ;
                            else cout << ", No more skills to learn" << endl ;
                        }
                    }
                }
            }
        }
        else{
            for(int a = 0; a<3; a++){
                cout << hero[a].name ;
                if (success[a]) cout << "Success, " << hero[0].sNames[plan].statusName << "+1" <<endl ;
                else cout << "Failure" << endl ;
            }
        }
    for(int i = 0; i<60; i++) cout << "-" ;
    cout << endl ;
    }
    for(int num = 0; num<3; num++)
    OutputStatus(hero[num]) ; /*参数应为Hero类型变量的引用
                                                不过这里，调用函数将hero[num]传至函数部分，
                                                &把heronum绑定到hero[num]*/
    cout << "Training Success/Failure:" << win_times << "/" << 3*day - win_times ;
}



bool MemberTraining(int plan, Hero &heroj){
    double rand_num = ((double)rand())/RAND_MAX ;
    if (rand_num <= heroj.threshold[plan]){
        heroj.status[plan]++ ;
        return true ;
    }
    else {
        return false ;
    }
}



void OutputStatus(Hero &heronum){
    cout << heronum.name << " Status:" << heronum.sNames[0].statusName << ' ' << heronum.status[0] << ", "
                                                                 << heronum.sNames[1].statusName << ' ' << heronum.status[1] << ", "
                                                                 << heronum.sNames[2].statusName << ' ' << heronum.status[2] << ", "
                                                                 << heronum.sNames[3].statusName << ": " ;
    if(heronum.status[3] == 0) cout << "None" << endl ;
    else{
        if (heronum.status[3] == 1) cout << heronum.skNames[0].skillNames << endl ;
        else cout << heronum.skNames[0].skillNames << heronum.skNames[1].skillNames << endl ;
    }
}

