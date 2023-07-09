/*
 * Topicos Especiais em Programacao | UFRJ | 2023.1
 * Gabriele Jandres Cavalcanti | 119159948
 * Aula 8 (Lista 10) | Problema J | What Goes Up
*/

#include <iostream>
#include <vector>

using namespace std;

void printLongestSubsequence(vector<int>& sequence, vector<int>& path, int pos) {
    if (pos == -1) return;
    printLongestSubsequence(sequence, path, path[pos]);
    cout << sequence[pos] << endl;
}

void calculateLongestSubsequence(vector<int>& sequence) {
    int length, longestSubseqEnd = 0, longestSubseqCount = 0, position, i;
    vector<int> longestSubseq(sequence.size());
    vector<int> longestSubseq_id(sequence.size());
    vector<int> path(sequence.size());

    for (i = 0; i < sequence.size(); i++) {
        position = lower_bound(longestSubseq.begin(), longestSubseq.begin() + longestSubseqCount, sequence[i]) - longestSubseq.begin();
        longestSubseq[position] = sequence[i];
        longestSubseq_id[position] = i;
        path[i] = (position > 0) ? longestSubseq_id[position - 1] : -1;

        if (position == longestSubseqCount) {
            ++longestSubseqCount;
            longestSubseqEnd = i;
        }
    }

    cout << longestSubseqCount << endl;
    cout << "-" << endl;
    printLongestSubsequence(sequence, path, longestSubseqEnd);
}

int main() {
    int number;
    vector<int> sequence;

    while (cin >> number)
        sequence.push_back(number);

    calculateLongestSubsequence(sequence);

    return 0;
}
