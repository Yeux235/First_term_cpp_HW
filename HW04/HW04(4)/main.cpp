#include <iostream>
#include <cstdlib>
using namespace std;


int main()
{
    //一大坨初始化：注意char类型数组只能存一个字符串常量，char*指针可以存多个字符串常量的首地址
    const char* ch[3][3] = {{"Warrior", "Taunt", "None"},
                                          {"Archer", "Focus", "None"},
                                          {"Priest", "Heal", "Cure"}} ;
    const char* name[4]={"HP", "ATK", "DEF", "Skill"} ;
    float threshold[3][4] = {{0.8, 0.6, 0.8, 0.2}, {0.6, 0.8, 0.6, 0.3}, {0.6, 0.6, 0.6, 0.4}} ;
    int num[3][4] = {{20, 10, 10, 0},
                               {16, 12, 8, 0},
                               {12, 6, 10, 0}} ;
    int seed, plan ;
    int counter[3][3] ;
    for(int i = 0; i < 3; i++){
        for(int j =0; j <3; j++)
            counter[i][j] = num[i] [j] ;
    }
        //展示起始值
    cout << "Player ID:" ;
    cin >> seed ;
    srand(seed) ;
    for( int i = 0; i < 3; i++)
        cout << ch[i][0] << "Status: HP " << num[i][0] << ",ATK " << num[i][1] << ",DEF " << num[i][2] << ";Skill: None\n" ;
    for (int i = 0; i < 60; i++)
        cout << "-" ;

        //主程序部分

    for( int k = 0; k < 10; k++){
        cout << "\nDay" << k + 1 << endl ;
        do{
            cout << "Select the training plan(1-HP, 2-ATK, 3-DEF, 4-Skill):" ;
            cin >> plan ;
        }while ( plan < 0 || plan > 4) ;

        if (plan == 0){
            for (int j =0; j < 60; j++) cout << "-" ;
            break ;
        }

        cout << name[plan-1] << " Training:\n" ;
        for( int i = 0; i < 3; i++ ){
            float rand_num = ((double)rand()) / RAND_MAX ;

                //开始
            if (rand_num <= threshold[i][plan]){
                if ( plan == 4 && ((i < 2 && num[i][3] < 1) || (i == 2 && num[i][3]<2))){
                    cout << ch[i][0] << " Success, Skill\"" << ch[i][num[i][3]+1] << "\" is learned\n" ;
                    num[i][3]++ ;
                }
                else {
                    if (plan != 4) {cout << ch[i][0] << " Success, " << name[plan-1] << "+1\n" ; num[i][plan-1]++ ;}
                    else cout << ch[i][0] << " Success, No more skills to learn\n" ;
                }
            }
            else cout << ch[i][0] << " Failure\n" ;
        }
        for( int s= 0; s < 60; s++) cout<< "-" ;
    }

    int sum[3], turn[3] = {1, 2, 3}, temp;
    for( int i = 0; i < 3; i++){
    sum [i] = num[i][1] + num[i][2] + num[i][3] + num[i][4] - counter[i][1] - counter[i][2] - counter[i][3];
    }

    for( int i = 0; i < 3; i++){
        for (int j = 0; j < 2 - i; j++ ){
            if (sum[j] < sum[j+1] || (sum[j] == sum[j+1] && turn[j] > turn[j+1]) ){
                temp = sum[j] ;
                sum[j] = sum[j+1] ;
                sum [j+1] = temp;

                temp = turn[j] ;
                turn[j] = turn[j+1] ;
                turn[j+1] = temp ;
            }
        }
    }
    cout <<'\n' ;
    for (int i = 0; i < 3; i++){
        cout << ch[turn[i]-1][0] << " Status: HP " << num[turn[i]-1][0] << ", ATK " << num[turn[i]-1][1] << ", DEF " << num[turn[i]-1][2] << " Skill: " ;
        if (turn[i]-1 == 2){
            switch (num[2][3]){
            case 0 : cout << "None" << endl ; break ;
            case 1 : cout << ch[2][2] << endl ; break ;
            case 2 : cout << ch[2][1] << " " << ch[2][2] << endl ;
            }
        }
        else cout << ( (num[turn[i]-1][3] == 1) ? ch[turn[i]-1][1] : ch[turn[i]-1][2] )<< endl ;
        }

}


