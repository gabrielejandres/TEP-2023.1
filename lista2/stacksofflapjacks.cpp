/*
  * Topicos Especiais em Programacao | UFRJ | 2023.1
  * Gabriele Jandres Cavalcanti | 119159948
  * Aula 2 | Problema E | Stacks of Flapjacks
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

void flip(vector<int>& stack, int index) {
    reverse(stack.begin(), stack.begin() + index + 1);
}

int getMax(vector<int>& stack, int n) {
    auto it = max_element(stack.begin(), stack.end() - n);
    return distance(stack.begin(), it);
}

vector<int> calculateFlips(vector<int>& pancakes) {
    int stackSize = pancakes.size();
    int maxIndex;
    vector<int> flips;
    
    for (int i = 0; i < stackSize; i++) {
        maxIndex = getMax(pancakes, i);

        if (maxIndex != stackSize - i - 1) {
            if (maxIndex != 0) {
                flip(pancakes, maxIndex);
                flips.push_back(stackSize - maxIndex);              
            }
            flip(pancakes, stackSize - i - 1);
            flips.push_back(i + 1);             
        }
    }

    return flips;
}

void getFlips(string pancakes) {
    vector<int> pancake_vector;
    istringstream iss(pancakes);
    int num;

    while (iss >> num) 
        pancake_vector.push_back(num);

    vector<int> flips = calculateFlips(pancake_vector);
    for (int flip : flips)
        cout << flip << " ";
}

int main() {
    string line;
    while (getline(cin, line)) {
        cout << line << endl;
        getFlips(line);
        cout << 0 << endl; 
    }

    return 0;
}