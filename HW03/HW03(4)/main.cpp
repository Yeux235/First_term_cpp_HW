#include <iostream>
#include<cstdlib>

using namespace std;

int main()
{
    int seed ;
    cout << "Player ID :" ;
    cin >> seed ;
    int HP , ATK , DEF ;
    srand( seed ) ;
    HP = (double)rand() *13 / (RAND_MAX + 1) + 12 ;
    ATK = (double)rand() *7 / (RAND_MAX + 1) + 6 ;
    DEF = (double)rand() *5 / (RAND_MAX + 1) + 4 ;
    cout << "Player Status: HP " << HP << ", ATK " << ATK << ", DEF " << DEF << "; Skill: None" << endl ;
    for (int i = 0 ; i < 61 ; i++) cout << "-" ;

    //各项指标初始化
    bool Skill = false ;
    for (int k = 0 ; k < 10 ; k++ )
    {
        double rand_num ;
        int plan_num ;
        rand_num = double(rand()) / RAND_MAX ;
        cout << '\n' << "Day " << k+1 << endl ;

        //do while循环：需要输入量作为 判断循环进行 的条件
        //亦可用while(true) if(!条件) break ;替换
        do
        {
            cout << "Select the training plan (1-HP, 2-ATK, 3-DEF, 4-Skill):" ;
            cin >> plan_num ;
        } while(plan_num > 5 || plan_num < 0 || (plan_num == 4 && Skill )) ;


        if (plan_num == 0) {
            for (int l = 0; l < 61; l++) cout << "-" ;
            break;
        }
             switch (plan_num)
             {
                case 1 :{
                            if (rand_num <= 0.8) {
                                HP++;
                                cout << "HP Training: Success, HP+1\n" ;
                            }
                            else cout << "HP Training: Failure\n" ;
                            break ;
                }
                case 2 :{
                            if (rand_num <= 0.8) {
                            ATK++;
                                cout << "ATK Training: Success, ATK+1\n" ;
                            }
                            else cout << "ATK Training: Failure\n" ;
                            break ;
                }
                case 3 :{
                            if (rand_num <= 0.8) {
                                DEF++;
                                cout << "DEF Training: Success, DEF+1\n" ;
                            }
                            else cout << "DEF Training: Failure\n" ;
                            break ;
                }
                case 4 :{
                            if (rand_num <= 0.2 ){
                                cout << "Skill Training: Success, Skill \"Heal\" is learned\n" ;
                                Skill = !Skill ;
                            }
                            else
                                cout << "Skill Training: Failure\n"  ;
                }
            }
            for (int i = 0 ; i < 61 ; i++) cout << "-" ;
        }

        //下面等号右侧表达式返回的结果是指针（指向字符串常量），由ch存放
        //如果想直接cout右侧表达式结果，需加括号，<<优先级高于 ? :
        const char* ch = (Skill) ? "Learned" : "None" ;
        cout << '\n' << "Player Status: HP " << HP << ", ATK " << ATK << ", DEF " << DEF << "; Skill :" << ch << endl ;
    }

