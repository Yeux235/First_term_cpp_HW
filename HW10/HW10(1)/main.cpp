#include <iostream>

using namespace std;

struct C_P {
    char city[31] ;
    int population ;
    C_P *next ;
};

C_P *JumpToNode(C_P *head, int j) ;// j==0时返回head；j==sum-1返回rear
void bubble (C_P *, C_P*) ;

int main()
{
    int sum = 0 ; //单元个数（包括head rear）
    C_P *head, *p, *rear, *s ;
    head = rear = new C_P ;
    while (true){
        char first ;
        p = new C_P ;
        first = cin.get() ;
        if (first == '@'){
            delete p ;
            break ;
        }
        p->city[0] = first ;
        cin.getline(p->city+1, 29,' ') ;
        sum++ ;
        cin >> p->population ;
        cin.get() ;
        rear->next = p ;
        rear = p ;
    }
    rear->next = nullptr ;

    for (int j = 0; j < sum-1; j++){
        //C_P *stop = JumpToNode(head, sum+1-j) ;
        //本来想这么控制终止条件，忽略了冒泡之后stop顺序不再是原来的了
        //感谢opus4.5Think成功解决我的问题
        s = head ;
        p = s->next ;
        bool flag = false ;
        for (int i = 0; i < sum-1-j && p && p->next; i++){
            if (p->population < p->next->population){
                bubble(s, p) ; //冒泡函数，交换p和下一个位置
                flag = true ;
                s = s->next ;
            } else {
                s = p ;
                p = p->next ;
            }
        }
        if (!flag) break ;
    }
    rear = JumpToNode(head, sum) ;
    p = JumpToNode(head, sum+1) ;
    delete p ;
    rear->next = nullptr ;

    p = head->next ;
    while (p != nullptr){
        cout << p->city << ' ' ;
        p = p->next ;
    }
    return 0 ;
}


C_P *JumpToNode(C_P *head, int j){ //head为第一个单元
    C_P *temp = head ;
    if (j == 1) return head ;
    for (int i = 1; i < j; i++){  //把head作为第一个单元考虑
        temp = temp->next ;
    }
    return temp ;
}

void bubble(C_P *s, C_P *p){
    C_P *q = p->next ;
    C_P *r = q->next ;

    s->next = q ;
    q->next = p ;
    p->next = r ;
}
