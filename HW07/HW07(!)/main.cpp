#include <iostream>
using namespace std ;

int search(int arr[], int n, int key) ;


int main(){
    int n, key ;
    cout << "Please input n:" ;
    cin >> n ;
    int *arr = new int [n] ;
    cout << "Please input " << n << " integers:" ;
    for (int i = 0; i < n; i++) cin >> arr[i] ;
    cout << "Please input key:" ;
    cin >> key ;
    int result = search (arr, n, key) ;
    delete [] arr ;
    switch (result) {
        case -1 : cout << "Not Found" ; break ;
        default : cout << "Index=" << result ;
    }
}


int search(int *arr, int n, int key){
    int Index[n] ; //用于标记输入数组的顺序
    for (int i = 0; i < n; i++) Index[i] = i ;
    for (int i = 0; i < n; i++){
        bool flag = false ;
        for (int j =0; j < n-1-i; j++){
            int temp ;
            if (arr[j] > arr[j+1]){
                temp = arr[j+1] ;
                arr[j+1] = arr[j] ;
                arr[j] = temp ;
                temp = Index[j+1] ;
                Index[j+1] = Index[j] ;
                Index[j] = temp ;
                flag = true ;
            }
        }
        if (!flag) break ;
    }
//二分法查找
    int low = 0, high = n-1 ;
    do{
        int mid = (low + high)/2 ;
        if (arr[mid] == key)
                return Index[mid] ;
        if (arr[mid] > key) high = mid - 1 ;
        else low = mid + 1 ;
    }  while (low <= high) ;
    return -1 ;
}
