/*
 * Topicos Especiais em Programacao | UFRJ | 2023.1
 * Gabriele Jandres Cavalcanti | 119159948
 * Aula 4 | Problema C | The Light Square
 */

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 105;
int values[N], headEdge[N], totalEdges = 1;
int cells[2005][2005];
int dfn[N], low[N], vertexColor[N], vertexStack[N], inVertexStack[N], stackTop, controlIndex, totalSCC;
bool visitedSCC[N];

struct Edge {
	int y, x;
} e[2000 * 2000 * 4];

// adiciona uma aresta direcionada do vértice x para o vértice y
void addEdge(int x, int y) {
	e[totalEdges].y = y;
	e[totalEdges].x = headEdge[x];
	headEdge[x] = totalEdges++;
}

// algoritmo de Tarjan para encontrar as componentes fortemente conectadas (SCC) do grafo
void getSCC(int x) { 
	int y, i;
	vertexStack[++stackTop] = x;
	inVertexStack[x] = 1;
	dfn[x] = low[x] = ++controlIndex;
	for (i = headEdge[x]; i; i = e[i].x) {
		y = e[i].y;
		if (!dfn[y]) {
			getSCC(y);
			low[x] = min(low[x], low[y]);
		}
		else if (inVertexStack[y])
			low[x] = min(low[x], dfn[y]);
	}
	if (dfn[x] == low[x]) {
		totalSCC++;
		do {
			vertexColor[vertexStack[stackTop]] = totalSCC;
			inVertexStack[vertexStack[stackTop]] = 0;
		} while (vertexStack[stackTop--] != x);
	}
}

int main() {
	int size, i, j, sccColor1, sccColor2;
	vector<int> edges;
	string lightState;

	cin >> size;
	
	for (i = 1; i <= size; i++) {
		cin >> lightState;
		for (int j = 0; j < lightState.size(); j++) cells[i][j + 1] = lightState[j] - '0';
	}

	for (i = 1; i <= size; i++) {
		cin >> lightState;
		for (int j = 0; j < lightState.size(); j++)
			cells[i][j + 1] ^= lightState[j] - '0';
	}

	cin >> lightState;

	for (i = 1; i <= size; i++) values[i] = lightState[i - 1] - '0';

	for (i = 1; i <= size; i++) {
		for (j = 1; j <= size; j++) {
			if (cells[i][j]) {
				if (!values[i] && !values[j]) {
					cout << "-1" << endl;
					return 0;
				}
				if (!values[i] && values[j]) addEdge(2 * i, 2 * i - 1);
				if (values[i] && !values[j]) addEdge(2 * (j + size), 2 * (j + size) - 1);
				if (values[i] && values[j]) addEdge(2 * i, 2 * (j + size) - 1), addEdge(2 * i - 1, 2 * (j + size)), addEdge(2 * (size + j), 2 * i - 1), addEdge(2 * (j + size) - 1, 2 * i);
			}
			else {
				if (!values[i] && values[j]) addEdge(2 * i - 1, 2 * i);
				if (values[i] && !values[j]) addEdge(2 * (j + size) - 1, 2 * (j + size));
				if (values[i] && values[j]) addEdge(2 * i - 1, 2 * (j + size) - 1), addEdge(2 * (j + size) - 1, 2 * i - 1), addEdge(2 * i, 2 * (j + size)), addEdge(2 * (j + size), 2 * i);
			}
		}
	}

	for (i = 1; i <= 2 * 2 * size; i++)
		if (!dfn[i]) getSCC(i);

	for (i = 1; i <= 2 * 2 * size; i += 2)
		if (vertexColor[i] == vertexColor[i + 1]) {
			puts("-1");
			return 0;
		}
	
	for (i = 1; i <= 2 * 2 * size; i += 2) { 
		sccColor1 = vertexColor[i], sccColor2 = vertexColor[i + 1];

		if (visitedSCC[sccColor1]) {
			edges.push_back(i);
			continue;
		}

		if (visitedSCC[sccColor2]) continue;
		
		if (sccColor1 < sccColor2) {
			visitedSCC[sccColor1] = 1;
			edges.push_back(i);
		} else visitedSCC[sccColor2] = 1;
		
	}

	cout << edges.size() << endl;

	for (i = 0; i < edges.size(); i++) {
    	int x = edges[i];
    	if (x <= 2 * size) 
			cout << "row " << (x - 1) / 2 << endl;
		else
			cout << "col " << (x - 2 * size - 1) / 2 << endl;
	}

	return 0;
}