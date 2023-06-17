/*
 * Topicos Especiais em Programacao | UFRJ | 2023.1
 * Gabriele Jandres Cavalcanti | 119159948
 * Aula 7 | Problema F | Continents
*/

#include <iostream>
#include <cstring>

#define MAX 20

using namespace std;

char map[MAX][MAX], visited[MAX][MAX], land;
int totalRegions;

// Busca em profundidade recursiva 
void DFS(int x, int y, int rows, int columns) {
    if (y < 0) y = rows - 1;
    if (y >= rows) y = 0;

    if (x < 0 || x >= columns) return;
    if (visited[x][y] != 0 || map[x][y] != land) return;

    visited[x][y] = 1; 
    totalRegions++;

    DFS(x + 1, y, rows, columns);
    DFS(x, y + 1, rows, columns);
    DFS(x - 1, y, rows, columns);
    DFS(x, y - 1, rows, columns);
}

int main() {
    int i, j, numRegions, kingXCoordinate, kingYCoordinate, columns, rows;
    while (cin >> columns && cin >> rows) {
        memset(visited, 0, sizeof(visited));
        for (i = 0; i < columns; i++) cin >> map[i];

        cin >> kingXCoordinate >> kingYCoordinate;
        land = map[kingXCoordinate][kingYCoordinate]; // onde o rei esta localizado
        DFS(kingXCoordinate, kingYCoordinate, rows, columns);

        numRegions = 0; // quantidade de regioes do maior continente encontrado 
        for (i = 0; i < columns; i++) {
            for (j = 0; j < rows; j++) {
                totalRegions = 0;
                DFS(i, j, rows, columns);
                if (totalRegions > numRegions) numRegions = totalRegions;
            }
        }
        cout << numRegions << endl;
    }

    return 0;
}