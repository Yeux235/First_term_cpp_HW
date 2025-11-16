#include <iostream>
#include <string>
using namespace std;

int main() {
    // 读入整行
    cout << "Input: ";
    string line;
    getline(cin, line);

    // 按长度分组：长度 1..10
    string group[11];   // group[L]：长度为 L 的单词按出现顺序拼接后的字符串
    int    cnt[11] = {0}; // cnt[L]：长度为 L 的单词个数

    // 手动切分单词（只含字母与空格）
    string word;
    for (size_t i = 0; i <= line.size(); ++i) {
        char c = (i < line.size() ? line[i] : ' '); // 末尾补一个空格，统一收尾
        if (c != ' ') {
            word += c;
        } else if (!word.empty()) {
            int L = (int)word.size();          // 单词长度 1..10
            group[L] += word;                  // 依次拼接
            cnt[L]++;                          // 该长度单词数量 +1
            word.clear();
        }
    }

    // 收集非空分组
    string outStr[10];   // 最多 10 种长度
    int    outLen[10];   // 每组拼接后的总长度
    int    outCnt[10];   // 每组包含的单词数
    int m = 0;
    for (int L = 1; L <= 10; ++L) {
        if (cnt[L] > 0) {
            outStr[m] = group[L];
            outLen[m] = (int)group[L].size();  // 也等于 cnt[L] * L
            outCnt[m] = cnt[L];
            ++m;
        }
    }

    // 按规则排序：先按 outLen 升序；若相等，outCnt 降序
    for (int i = 0; i < m - 1; ++i) {
        for (int j = 0; j < m - 1 - i; ++j) {
            bool needSwap = false;
            if (outLen[j] > outLen[j + 1]) needSwap = true;
            else if (outLen[j] == outLen[j + 1] && outCnt[j] < outCnt[j + 1]) needSwap = true;
            if (needSwap) {
                // 交换三个并行数组
                string ts = outStr[j]; outStr[j] = outStr[j + 1]; outStr[j + 1] = ts;
                int tl = outLen[j];   outLen[j] = outLen[j + 1]; outLen[j + 1] = tl;
                int tc = outCnt[j];   outCnt[j] = outCnt[j + 1]; outCnt[j + 1] = tc;
            }
        }
    }

    // 输出
    cout << "Output: ";
    for (int i = 0; i < m; ++i) {
        if (i) cout << ' ';
        cout << outStr[i];
    }
    cout << '\n';
    return 0;
}
