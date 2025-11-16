#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

// 将整数转换为指定进制（8 或 16）的字符串
string convertToBase(long value, int base) {
    if (value == 0) return "0";
    string digits = "0123456789ABCDEF";
    string result = "";
    while (value > 0) {
        int r = value % base;
        result = digits[r] + result;
        value /= base;
    }
    return result;
}

int main() {
    string s;
    cout << "Input: ";
    cin >> s;

    int base = 10;
    string type = "decimal";

    // 判断输入进制
    if (s.length() > 2 && s[0] == '0' && (s[1] == 'X' || s[1] == 'x')) {
        base = 16;
        type = "hexadecimal";
    } else if (s.length() > 1 && s[0] == '0') {
        base = 8;
        type = "octal";
    }

    // 转换为十进制整数
    long value = strtol(s.c_str(), nullptr, base);

    // 输出格式
    cout << "Output: " << type
         << ", " << value                          // 十进制
         << ", 0" << convertToBase(value, 8)       // 八进制
         << ", 0x" << convertToBase(value, 16)     // 十六进制
         << endl;

    return 0;
}
