#include <iostream>
#include <cstring>

using namespace std;

const char LETTERS[36] = {
    'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z',
    '0','1','2','3','4','5','6','7','8','9'
};

const char* MORSE[36] = {
    ".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-",
    "..-","...-",".--","-..-","-.--","--..",
    "-----",".----","..---","...--","....-",".....","-....","--...","---..","----."
};

int findIndexByLetter(char ch) {    //获取下标
    if (ch >= 'A' && ch <= 'Z') ch += 'a' - 'A' ;  //统一变成小写
    for (int i = 0; i < 36; ++i)
        if (LETTERS[i] == ch) return i;
    return -1;
}

int findIndexByMorse(const char* code) {
    for (int i = 0; i < 36; ++i)
        if (strcmp(MORSE[i], code) == 0) return i;
    return -1;
}

void encodeLine(const char* line) {
    for (int i = 0; line[i] != '\0'; ++i) {
        if (line[i] == ' ') { cout << "   "; continue; }
        int idx = findIndexByLetter(line[i]);
        if (idx != -1) {
            cout << MORSE[idx];
            if (line[i+1] != '\0' && line[i+1] != ' ') cout << ' ';
        }
    }
    cout << '\n';
}

void decodeLine(const char* line) {
    char token[8] = {0};
    int ti = 0, spaceCnt = 0;
    for (int i = 0; ; ++i) {
        char c = line[i];
        if (c == '.' || c == '-') {
            if (spaceCnt >= 3) cout << ' ';
            spaceCnt = 0;
            token[ti++] = c;
        } else if (c == ' ' || c == '\0') {
            if (ti > 0) {
                token[ti] = '\0';
                int idx = findIndexByMorse(token);
                if (idx != -1) cout << LETTERS[idx];
                ti = 0;
            }
            if (c == ' ') spaceCnt++;
            else break;
        }
    }
    cout << '\n';
}

int main() {
    char line[128];

    cout << "Input English (<=10 chars): ";
    cin.getline(line, 128);
    encodeLine(line);

    cout << "Input Morse (letters sep by 1 space, words by 3 spaces): ";
    cin.getline(line, 128);
    decodeLine(line);

    return 0;
}
