/*
  * Topicos Especiais em Programacao | UFRJ | 2023.1
  * Gabriele Jandres Cavalcanti | 119159948
  * Aula 3 | Problema F | Power Strings
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

/* 
    aplicacao do algoritmo KMP: podemos utilizar o algoritmo KMP para encontrar o tamanho do maior prefixo 
da string que é um sufixo proprio. 
*/
int KMP(string str) {
    int strSize = str.length(), j = 0, i;
    vector<int> prefixTable(strSize);

    for (i = 1; i < strSize; i++) {
        while (j > 0 && str[i] != str[j]) j = prefixTable[j - 1];
        if (str[i] == str[j]) j++;
        prefixTable[i] = j;
    }

    return prefixTable[strSize - 1];
}

int main() {
    string str;
    int stringSize, substringSize;

    cin >> str;

    while (str != ".") {
        stringSize = str.length();
        substringSize = KMP(str);
        cout << stringSize / (stringSize - substringSize) << endl;
        cin >> str;
    }

    return 0;
}
