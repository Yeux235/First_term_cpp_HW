#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;


const int NUM_STATUS = 4, NUM_MEMBER = 3;

struct statusNames {
    static constexpr const char* status_name[] = {"HP", "ATK", "DEF", "Skill"};
};

struct SkillList {
    const char* const SkillName[4] = {"Taunt", "Focus", "Heal", "Cure"};
    bool get_or_not[4] = {false};
};

struct Hero {
    const char *HeroName ;
    double threshold[NUM_STATUS] ;
};

Hero hero[3] = {
    { "Warrior", {0.8, 0.6, 0.8, 0.2} },
    { "Archer", {0.6, 0.8, 0.6, 0.3} },
    { "Priest", {0.6, 0.6, 0.6, 0.4} }
    };

class Member {
friend void PlayerTraining(int, int, Member team[], int&, int&);
    const char *name ;
    int type; //职业序号
    int status[NUM_STATUS] ;

    SkillList skill;
public:
    Member(const char *Name, int type_idx, int hp, int atk, int def) :
        name(Name), type(type_idx), status{hp, atk, def, 0}{}
    bool MemberTraining(int);
    static void Transfer(Member member[]);
    void OutputStatus();
};


void PlayerTraining(int, int, Member team[], int&, int& ) ;

int main() {
    Member team[3] { {"Sandy",0,20,10,10}, {"Robin",1,16,12,8}, {"Alice",2,12,6,10} };
    int playerID, numDays, success = 0, failure = 0;
    cout << "Player ID and Days for Training: ";
    cin >> playerID >> numDays;
    PlayerTraining(playerID, numDays, team, success, failure);
    cout << "Training Success/Failure: " << success << "/" << failure << endl;
    return 0;
}



void PlayerTraining( int playerID, int numDays, Member team[], int &success, int &failure ) {
    srand(playerID);

    int plan = 0 ;

    for(int i = 0; i < 3; i++) team[i].OutputStatus();

    for(int i = 0; i<60; i++) cout << "-" ;
    cout << '\n' ;

    for (int d = 0; d < numDays; d++){
        bool result[3] = {false} ;
        cout << "Day" << d+1 <<endl ;
        while (true){
            cout << "Select the training plan(1-HP, 2-ATK, 3-DEF, 4-Skill):" ;
            cin >> plan;
            if (plan >= 0 && plan <= 4) break;
            if (plan == 9) {
                Member::Transfer(team);
            }
        }
        cout << statusNames::status_name[--plan] << " Training:" << endl;
        for(int j = 0; j < 3; j++){
            result[j] = team[j].MemberTraining(plan) ;
            success += result[j] ;
        }

        //接下来就是输出单次训练结果，分类情况需明确
        if (plan == 3){
            for (int a = 0; a < 3; a++){
                cout << team[a].name << " " ;
                if (!result[a]) cout << "Failure" << endl ;
                else{
                    cout << "Success" ;
                    //1.对应英雄第一个技能没学会 :
                    if (!team[a].skill.get_or_not[team[a].type]){
                        team[a].skill.get_or_not[team[a].type] = true;
                        cout << ", Skill \"" << team[a].skill.SkillName[team[a].type] << "\" is learned" << endl;
                    } else{
                        //2.不是priest
                        if (team[a].type != 2){
                            cout << ", No more skill to learn" << endl;
                        } else{
                            //3.是priest，且没学会Cure
                            if (!team[a].skill.get_or_not[3]){
                                team[a].skill.get_or_not[3] = true;
                                cout << ", Skill \"" << team[a].skill.SkillName[3] << "\" is learned" << endl;
                            } else{
                                cout << ", No more skill to learn" << endl;
                            }
                        }
                    }
                }
            }
        }
        else{
            for(int a = 0; a<3; a++){
                cout << team[a].name;
                if (result[a]) cout << " Success, " << statusNames::status_name[plan] << "+1" <<endl ;
                else cout << " Failure" << endl ;
            }
        }
    for(int i = 0; i<60; i++) cout << "-" ;
    cout << endl ;
    }
    for(int num = 0; num<3; num++)
        team[num].OutputStatus() ;

    failure = 3*numDays - success ;
}

bool Member::MemberTraining(int plan){
    double rand_num = ((double)rand())/RAND_MAX ;
    if (rand_num <= hero[type].threshold[plan]){//吊诡的是，
        status[plan]++ ;                    //HPATKDEF状态在这里更新
        return true ;                         //而skill的status在这里只是为了保证内存不越界
    }                                                //skill的状态实际在接下来逻辑判断里更新
    else {
        return false ;
    }
}

void Member::OutputStatus(){
    cout << name << ' '<< hero[type].HeroName << " Status:"
            << statusNames::status_name[0] << ' ' << status[0] << ", "
            << statusNames::status_name[1] << ' ' << status[1] << ", "
            << statusNames::status_name[2] << ' ' << status[2] << ", "
            << statusNames::status_name[3]  <<':';
    int NumOfSkill = 0;
    for(int i = 0; i < 4; i++)
        NumOfSkill += skill.get_or_not[i];
    if (NumOfSkill){
        for(int i = 0; i < 4; i++){
            if (skill.get_or_not[i]){
                if (i!=0) cout << ',';
                cout << skill.SkillName[i];
            }
        }
        cout << endl;
    }
    else cout << "None" << endl;
}

 void Member::Transfer(Member team[]){
    int x1, x2;
    cout << "Transfer (0-Sandy,1-Robin, 2-Alice):";
    cin >> x1;
    cout << "To Class (0-Warrior, 1-Archer, 2-Priest):";
    cin >> x2;
    team[x1].type = x2;
    cout << team[x1].name << " becomes "
            << hero[team[x1].type].HeroName << endl;
}
