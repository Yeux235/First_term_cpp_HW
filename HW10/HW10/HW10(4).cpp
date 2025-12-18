#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;


const int NUM_STATUS = 4, NUM_MEMBER = 3;

struct statusNames {
    const char *statusName ;
};

struct skillNames {
    const char *skillName ;
};

struct Hero {
    const char *HeroName ;
    double threshold[4] ;
    skillNames hero_skill[2];
};

struct Person {
    const char *PersonName ;
    int status[4] ;

    Hero *role ;
    int idx;

    int sk_get = 0;
    skillNames GottenSkills[5] = {nullptr} ;
    bool Skill[5] = {false};
    statusNames sNames[4] = { {"HP"}, {"ATK"}, {"DEF"}, {"Skill"} } ;

};


void Transfer(Person person[]) ;
void PlayerTraining(int day, Person person[] ) ;
void OutputStatus(Person &person) ;
bool MemberTraining(int plan, Person &person) ;


int main(){
    int PlayerID, day ;
    Hero hero[3] = {
    { "Warrior", {0.8, 0.6, 0.8, 0.2}, {"Taunt", nullptr} },
    { "Archer", {0.6, 0.8, 0.6, 0.3}, {"Focus", nullptr} },
    { "Priest", {0.6, 0.6, 0.6, 0.4}, {"Heal", "Cure"} }
    };

    Person person[3] = {
    { {"Sandy"}, {20, 10, 10, 0}, {hero} },
    { {"Robin"}, {16, 12, 8, 0}, {hero+1} },
    { {"Alice"}, {12, 6, 10, 0}, {hero+2} }
    };
    for (int i = 0; i < 3; i++)
        person[i].idx = person[i].role - hero;


    cout << "Player ID and Days for Training:" ;
    cin >> PlayerID >> day ;
    srand(PlayerID) ;

    PlayerTraining(day, person) ;

}



void PlayerTraining( int day, Person person[]) {
    int plan = 0 ;
    int win_times = 0 ;

    for(int num = 0; num<3; num++)
    OutputStatus(person[num]) ;
    for(int i = 0; i<60; i++) cout << "-" ;
    cout << '\n' ;

    for (int d = 0; d < day; d++){
        bool success[3] = {false} ;
        cout << "Day" << d+1 <<endl ;
        while (true){
            cout << "Select the training plan(1-HP, 2-ATK, 3-DEF, 4-Skill):" ;
            cin >> plan;
            if (plan >= 0 && plan <= 4) break;
            if (plan == 9) {
                Transfer(person);
            }
        }
        cout << person[0].sNames[--plan].statusName << " Training:" << endl;
        for(int j = 0; j < 3; j++){
            success[j] = MemberTraining(plan, person[j]) ;
            win_times += success[j] ;
        }

        //接下来就是输出单次训练结果，分类情况需明确
        if (plan == 3){
            for (int a = 0; a < 3; a++){
                cout << person[a].PersonName << " " ;
                if (!success[a]) cout << "Failure" << endl ;
                else{
                    cout << "Success" ;
                    //1.  从无到有且尚未获得这个技能
                    if (person[a].status[3] == 1&&!person[a].Skill[person[a].idx]) {
                        cout << ", Skill \"" << person[a].role->hero_skill[0].skillName << "\" is learned" << endl ;
                        person[a].GottenSkills[person[a].sk_get++].skillName = person[a].role->hero_skill[0].skillName;
                        person[a].Skill[person[a].idx] = true;
                    }
                    else {
                        //2.  到2了且不是priest 或者学过这个技能了
                        if (person[a].idx != 2 || person[a].Skill[person[a].idx])
                            cout << ", No more skills to learn" << endl ;
                        //3.  至此只剩>=2 && role为priest的情况
                        else {
                            if (person[a].status[3] == 2 && !person[a].Skill[3]) {
                                cout << ", Skill \"" << person[a].role->hero_skill[1].skillName << "\" is learned" << endl ;
                                person[a].GottenSkills[person[a].sk_get].skillName = person[a].role->hero_skill[1].skillName;
                                person[a].Skill[3] = true;
                                person[a].sk_get++;
                            }
                            else cout << ", No more skills to learn" << endl ;
                        }
                    }
                }
            }
        }
        else{
            for(int a = 0; a<3; a++){
                cout << person[a].PersonName ;
                if (success[a]) cout << " Success, " << person[0].sNames[plan].statusName << "+1" <<endl ;
                else cout << " Failure" << endl ;
            }
        }
    for(int i = 0; i<60; i++) cout << "-" ;
    cout << endl ;
    }
    for(int num = 0; num<3; num++)
        OutputStatus(person[num]) ; /*参数应为Hero类型变量的引用
                                                不过这里，调用函数将hero[num]传至函数部分，
                                                &把heronum绑定到hero[num]*/
    cout << "Training Success/Failure:" << win_times << "/" << 3*day - win_times ;
}

bool MemberTraining(int plan, Person &personj){
    double rand_num = ((double)rand())/RAND_MAX ;
    if (rand_num <= personj.role->threshold[plan]){
        personj.status[plan]++ ;
        return true ;
    }
    else {
        return false ;
    }
}

void OutputStatus(Person &personnum){
    cout << personnum.PersonName << ' '<< personnum.role->HeroName << " Status:"
            << personnum.sNames[0].statusName << ' ' << personnum.status[0] << ", "
            << personnum.sNames[1].statusName << ' ' << personnum.status[1] << ", "
            << personnum.sNames[2].statusName << ' ' << personnum.status[2] << ", "
            << personnum.sNames[3].statusName << ": " ;
    int NumOfSkill = 0;
    for(int i = 0; i < 4; i++)
        NumOfSkill += personnum.Skill[i];
    if (NumOfSkill){
        for(int i = 0; i < personnum.sk_get; i++){
            if (i!=0) cout << ',';
            cout << personnum.GottenSkills[i].skillName;
        }
        cout << endl;
    }
    else cout << "None" << endl;
}

void Transfer(Person person[]){
    int x1, x2;
    cout << "Transfer (0-Sandy,1-Robin, 2-Alice):";
    cin >> x1;
    cout << "To Class (0-Warrior, 1-Archer, 2-Priest):";
    cin >> x2;

    person[x1].role += (x2 - person[x1].idx);
    person[x1].idx = x2;
    cout << person[x1].PersonName << " becomes " << person[x1].role->HeroName << endl;
    person[x1].status[3] = 0; //初始化技能计数器
}
