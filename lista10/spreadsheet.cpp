/*
 * Topicos Especiais em Programacao | UFRJ | 2023.1
 * Gabriele Jandres Cavalcanti | 119159948
 * Aula 8 (Lista 10) | Problema A | Spreadsheet
*/

#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

int calculateCellValue(int row, int column, vector<vector<int>>& computedValues, vector<vector<string>>& spreadsheet) {
    if (spreadsheet[row][column].empty()) return computedValues[row][column];

    string formula;
    int total = 0, cellIndex = 0, cellCol = 0, cellRow;
    istringstream iss(spreadsheet[row][column]);
    
    while (getline(iss, formula, '+')) {   
        while (isalpha(formula[cellIndex])) {
            cellCol *= 26;
            cellCol += (formula[cellIndex] - 'A' + 1);
            cellIndex++;
        }
        
        cellCol--;
        cellRow = stoi(formula.substr(cellIndex)) - 1;
        total += calculateCellValue(cellRow, cellCol, computedValues, spreadsheet);
        cellIndex = 0;
        cellCol = 0;
    }
    
    spreadsheet[row][column].clear();
    computedValues[row][column] = total;
    return total;
}

int main() {
    int row, column, numCases, numRows, numColumns;
    string input;
    vector<vector<int>> computedValues;
    vector<vector<string>> spreadsheet;

    cin >> numCases;

    while (numCases--) {
        cin >> numColumns >> numRows;

        computedValues.resize(numRows, vector<int>(numColumns, -1));
        spreadsheet.resize(numRows, vector<string>(numColumns));

        for (row = 0; row < numRows; row++) {
            for (column = 0; column < numColumns; column++) {
                cin >> input;
                if (input[0] == '=') spreadsheet[row][column] = input.substr(1);
                else computedValues[row][column] = stoi(input);
            }
        }

        for (row = 0; row < numRows; row++) {
            for (column = 0; column < numColumns; column++) {
                cout << calculateCellValue(row, column, computedValues, spreadsheet);
                cout << (column == numColumns - 1 ? "\n" : " ");
            }
        }

        computedValues.clear();
        spreadsheet.clear();
    }

    return 0;
}