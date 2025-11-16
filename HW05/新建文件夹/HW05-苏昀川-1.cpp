#include <iostream>

using namespace std;

int main()
{
    char ch[81], diff[81] ;
    bool flag[256] = {false} ;      //这里直接为每个char建立flag，以ASCII码为标签。
    int len = 0 ;//输入字符串长度

    cout << "Please input a string:" ;
    cin.getline(ch, 81) ;  //enter结束输入后自动在末尾补\0
    while (ch[len] != '\0') len++ ;


    int j =0 ; //diff长度（加上\0）
    for (int i = 0; i < len; i ++){
        if (!flag[(int)ch[i]]){  //条件判断这个ch是否重复过
            diff[j] = ch[i] ;
            j++ ;                   //i遍历ch[]，而diff取ch未重复的值
            flag[(int)ch[i]] = !flag[(int)ch[i]] ;
        }
        diff[j] = '\0' ;
    }




    //万事俱备：diff长度，字符不重。冒泡即可。
    for (int i = 0; i <= j-1; i++){
        bool flag_of_bubble = false ;
        for (int k = 0; k < j-1-i; k++){
            if (diff[k] < diff[k+1]){
                char temp = diff[k+1] ;
                diff[k+1] = diff[k] ;
                diff[k] = temp ;
                flag_of_bubble = true ;
            }
        }
        if (!flag_of_bubble) break ;
    }


    for (int i = 0; i < j+1; i++){
        cout << diff[i] ;
    }
    return 0 ;
}
