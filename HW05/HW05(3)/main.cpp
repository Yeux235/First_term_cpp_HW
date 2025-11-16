#include <iostream>
using namespace std;

char getUChar() {
    char ch;

    while (true) { // 外层循环：直到输入中出现大写字母为止
        cout << "Input:"  ;
        bool found = false;   // 标志是否找到大写字母

        while (true) {        // 内层循环：逐个读取输入字符
            ch = cin.get();   // 读一个字符（包括空格和回车）

            if (ch == '\n') break;           // 一行结束
            if (ch >= 'A' && ch <= 'Z') {    // 找到大写字母
                found = true;
                break;                        // 跳出内层循环
            }
        }

        if (found) return ch;                 // 找到 → 返回结果
        else {
            cout << "\n";
        }
    }
}

int main() {
    char result = getUChar();
    cout << "Output:" << result << endl;
    return 0;
}
