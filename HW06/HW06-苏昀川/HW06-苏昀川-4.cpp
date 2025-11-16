#include <iostream>
#include <cstdlib>
using namespace std;


const int NUM_STATUS = 4, NUM_MEMBER = 3;
const char statusName[NUM_STATUS][10] = {"HP", "ATK", "DEF", "Skill"};


void PlayerTraining(int day, int status[3][4], int W_F[] ) ;
void OutputStatus(int num, const char member[][10], const char skillName[][2][10], int status[3][4]) ;
void MemberTraining(int plan, int j, int status[3][4], const double rate[NUM_MEMBER][NUM_STATUS], int W_F[ ], bool success_or_not[]) ;
//注：声明和定义时需标明数组234……维宽度，以便编译器通过公式+首地址→a[i][j][k]
//如为一维数组则int a[] int *a 这样能表示出a为指针


int main(){
    int PlayerID, day ;
    int W_F[2] = {0} ;
    int status[3][4] = {{20, 10, 10, 0}, {16, 12, 8, 0}, {12, 6, 10, 0}} ;

    cout << "Player ID and Days for Training:" ;
    cin >> PlayerID >> day ;
    srand(PlayerID) ;

    PlayerTraining(day, status, W_F ) ;

}



void PlayerTraining( int day, int status[3][4], int W_F[]) {
    int plan = 0 ;
    static const char member[NUM_MEMBER][10] = {"Warrior", "Archer", "Priest"};
    static const char skillName[NUM_MEMBER][2][10] = {{"Taunt", ""}, {"Focus", ""}, {"Heal", "Cure"}};
    static const double rate[NUM_MEMBER][NUM_STATUS] = {{0.8, 0.6, 0.8, 0.2},
                                                                                                    {0.6, 0.8, 0.6, 0.3},
                                                                                                    {0.6, 0.6, 0.6, 0.4}};
    for(int num = 0; num<3; num++)
    OutputStatus(num, member, skillName, status) ;
    for(int i = 0; i<60; i++) cout << "-" ;
    cout << '\n' ;4

    for (int d = 0; d < day; d++){
        bool success_or_not[3] = {false} ; //记录每次membertraining结果
        cout << "Day" << d+1 <<endl ;
        do{
            cout << "Select the training plan(1-HP, 2-ATK, 3-DEF, 4-Skill):" ;
            cin >> plan ;
        }while (plan < 0 || plan > 4) ;
        if (plan == 0) break ;
        plan -- ;

        cout << statusName[plan] << " Training:" << endl;
        for(int j = 0; j < 3; j++)
            MemberTraining(plan, j, status, rate, W_F, success_or_not) ;

        //接下来就是输出单次训练结果，分类情况需明确
        if (plan == 3){
            for (int a = 0; a < 3; a++){
                cout << member[a] << " " ;
                if (!success_or_not[a]) cout << "Failure" << endl ;
                else{
                    cout << "Success" ;
                    if (status[a][3] == 1) cout << ", Skill\"" << skillName[a][0] << "\" is learned" << endl ;
                    else {
                        if (a!=2) cout << ", No more skills to learn" << endl ;
                        else {
                            if (status[2][3] == 2) cout << ", Skill\"" << skillName[2][0] << "\" is learned" << endl ;
                            else cout << ", No more skills to learn" << endl ;
                        }
                    }
                }
            }
        }
        else{
            for(int a = 0; a<3; a++){
                cout << member[a] ;
                if (success_or_not[a]) cout << "Success, " << statusName[plan] << "+1" <<endl ;
                else cout << "Failure" << endl ;
            }
        }
    for(int i = 0; i<60; i++) cout << "-" ;
    cout << '\n' ;
    }
    for(int num = 0; num<3; num++)
    OutputStatus(num, member, skillName, status) ;
    cout << "Training Success/Failure:" << W_F[0] << "/" << W_F[1] ;
}



void MemberTraining(int plan, int j, int status[3][4], const double rate[NUM_MEMBER][NUM_STATUS], int W_F[], bool success_or_not[]){
    float rand_num = ((double)rand())/RAND_MAX ;
    if (rand_num <= rate[j][plan]){
        status[j][plan]++ ;
        W_F[0]++ ;
        success_or_not[j] = !success_or_not[j] ;
    }
    else {
        W_F[1]++ ;
    }
}



void OutputStatus(int num, const char member[][10], const char skillName[][2][10], int status[3][4]){
    cout << member[num] << " Status:" << statusName[0] << ' ' << status[num][0] << ", "
                                                                << statusName[1] << ' ' << status[num][1] << ", "
                                                                << statusName[2] << ' ' << status[num][1] << ", "
                                                                << statusName[3] << ": " ;
    if(status[num][3] == 0) cout << "None" << endl ;
    else{
        if (status[num][3] == 1) cout << skillName[num][0] << endl ;
        else cout << skillName[num][0] << skillName[num][1] << endl ;
    }
}
//呜呜呜我从一点断断续续写到22：10可算是完美收官了
