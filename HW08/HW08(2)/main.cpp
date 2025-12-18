#include <iostream>

using namespace std ;

int main(){
    char *str = new char[101] ;
    cout << "Input:" ;
    cin.getline(str, 101) ;

    bool in_word = false ;
    int num = 0 ;
    for (int i = 0; str[i] != '\0'; i++){
        if (str[i] != ' '){
            if (!in_word) {
                in_word = true ;
                num++ ;
            }
        }else in_word = false ;
    }
    cout << "Output:" << num << endl ;

    //计算每个单词长度存到lenth[]
    int *lenth = new int[num] ;
    for (int i = 0; i < num; i++)
        lenth[i] = 0 ;

    in_word = false ;

    int j = -1 ; //这个表示第j个单词
    for (int i = 0; str[i] != '\0'; i++){
        if (str[i] != ' '){
            if (!in_word){  //这两行确定了是否进入了新单词
                in_word = true ;
                j++ ;
            }
            if (in_word) lenth[j]++ ;
        } else in_word = false ;
    }


    //接下来就是读入每个单词，存到sentence[j][]
    char **sentence = new char* [num] ;
    for (int i = 0; i < num; i ++)
        sentence[i] = new char[lenth[i] + 1] ; //多留一位放\0（然而开始忘了这么干了）
    in_word  = false ;
    j = -1 ;
    for (int i = 0; str[i] != '\0'; i++){
        if (str[i] != ' '){
            if (!in_word){      //确定开始进入单词，于是开始读入
                in_word = true ;
                j++ ;
                for (int k = 0; str[i+k] != ' '&& str[i+k] != '\0'; k++){
                    sentence[j][k] = str[i+k] ;
                }
                sentence[j][lenth[j]] = '\0' ;
            }
        } else in_word = false ;
    }



    int *turn = new int [num] ;
    cout << "Input:" ;
    for (int i = 0; i < num; i++)
        turn[i] = (cin.get() - '0') ;  //在这里卡了好久，没意识到cin.get()读入的是字符
    while(cin.get() != '\n')
        continue ;

    cout << "Output:" ;
    for (int i = 0; i < num; i++)
        cout <<  sentence[turn[i]] << " "  ;
    delete [] str ;
    delete [] lenth ;
    for (int i = 0; i < num; i++)
        delete sentence[i] ;             //这里sentence是二级指针，先销毁一级指针指向内存，再销毁二级指针指向内存
    delete [] sentence ;
    return 0 ;
}
