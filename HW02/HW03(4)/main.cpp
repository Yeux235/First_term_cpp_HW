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
    for (int k = 0 ; k < 11 ; )
    {
        double rand_num ;
        int plan_num, skill_get = 0, temp ;
        temp = skill_get ;
        rand_num = double(rand()) / RAND_MAX ;
        cout << '\n' << "Day " << k+1 << endl ;
        do
        {
            cout << "Select the training plan (1-HP, 2-ATK, 3-DEF, 4-Skill):" << endl ;
            cin >> plan_num ;
        }while(plan_num > 5&& plan_num < 0) ;
             switch (plan_num)
             {
                case 1 :{if (rand_num <= 0.8) {HP++ ; k++;} break ;}
                case 2 :{if (rand_num <= 0.8) {ATK++ ; k++;} break ;}
                case 3 :{if (rand_num <= 0.8) {DEF++ ; k++;} break ;}
                case 4 :
                {
                    if (rand_num <= 0.2 && skill_get == 0)
                    {
                        cout << "Skill Training: Success, Skill \"Heal\" is learned" << '\n' ;
                        skill_get ++ ;
                        k++ ;
                    }
                        else
                        {
                            if (rand_num > 0.2)
                                cout << "Skill Training: Failure" << '\n' ;
                            else
                                break ;
                        }
                }
            }
            for (int i = 0 ; i < 61 ; i++) cout << "-" ;
        }
        cout << '\n' << "Player Status: HP " << HP << ", ATK " << ATK << ", DEF " << DEF << "; Skill: None" << endl ;
    }

