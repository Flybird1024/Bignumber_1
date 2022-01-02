#include <iostream>
#include <vector>

using namespace std;

int nLength(string num) { // 計算字串長度
    int n = 0, x = 0;
    x = num.size();
    for (;x > 0;x--) n++;
    return n - 1; // 字串一開始是從 0 開始而不是 1 所以 n-1
}

int main() {
    string num1, num2; // 計算值
    int a = 0, b = 0, n1, n2;  // a 為計算時所留下來沒有進位的值，b 為計算後須進位的值 n1、n2為字串長度
    char op; // 運算符號
    vector<int> answer; // 答案
    cout << "輸入第一個數: ";
    cin >> num1;
    n1 = nLength(num1); // 字串 num1 的長度
    cout << "輸入加(+)或乘(*): ";
    cin >> op;
    cout << "輸入第二個數: ";
    cin >> num2;
    n2 = nLength(num2); // 字串 num2 的長度
    if (op == '+') { // 判斷運算符號並進行對應的計算方式
        if (n1 < n2) { // 在進行運算之前，若未把最大的數放在最前面，進行計算時將會出現錯誤，所以要將最大的數放在最前面
            swap(num1, num2); // 將 num1 跟 num2 進行交換
            swap(n1, n2); // 將 n1 跟 n2 進行交換
            cout << num2 << op << num1; // 輸出運算方式
        }
        else {
            cout << num1 << op << num2; // 輸出運算方式
        }
        // 運算式
        for (;n2 >= 0;n1--, n2--) {
            a = (num1[n1] - 48) + (num2[n2] - 48) + b;
            b = a / 10;
            a = a % 10;
            answer.push_back(a);
        }
        for (;n1 >= 0;n1--) {
            a = num1[n1] + b;
            b = a / 10;
            a = a % 10;
            answer.push_back(a);
        }
        if (b > 0) answer.push_back(b);
        // 結束運算
    }
    else if (op == '*') {

    }
    cout << " 的答案為: "; // 輸出答案(answer)
    // 將 answer 陣列由後往前輸出 (運算式進位後所放的位置為起始值的後面)
    int x = 0;
    x = answer.size() - 1;
    for (;x >= 0;x--) cout << answer[x]; // 輸出答案
}