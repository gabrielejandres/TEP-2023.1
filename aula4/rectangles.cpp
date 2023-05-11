/*
 * Topicos Especiais em Programacao | UFRJ | 2023.1
 * Gabriele Jandres Cavalcanti | 119159948
 * Aula 4 | Problema F | Rectangles
*/

#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;

#define vertices 2005
#define edges 4005

int graph[vertices][edges], transposedGraph[vertices]; // grafo e grafo transposto
int visited[vertices], totalVisited; // vetor de visitados e indice de visitados
int vertexStack[vertices], stackTop; // pilha de vertices e topo da pilha
int inVertexStack[vertices], visitedVertices[vertices]; // vetor de vertices na pilha e vetor de vertices visitados
int SCComponents[vertices]; // vetor de componentes fortemente conexas
int totalSCC; // numero total de componentes fortemente conexas

struct Point {
    float x, y; // coordenadas do ponto

    // Permite que os objetos dessa estrutura sejam comparados e ordenados com base em suas coordenadas x e y
    bool operator<(const Point &a) const {
        if (a.x != x) return x < a.x;
        return y < a.y;
    }
};

struct Segment {
    Point s, t; // pontos inicial e final do segmento
};

// calcula a intersecao de dois segmentos de linha AB e AO
float intersect(Point o, Point a, Point b) {
    return (a.x-o.x) * (b.y-o.y) - (a.y-o.y) * (b.x-o.x);
}

// encontra o menor poligono convexo que contem todos os pontos de entrada
void convexHull(int n, Point p[], Point ch[]) {
    sort(p, p+n);
    int m = 0, i, t;
    for (i = 0; i < n; i++) {
        while (m >= 2 && intersect(ch[m-2], ch[m-1], p[i]) <= 0)
            m--;
        ch[m++] = p[i];
    }
    for (i = n-1, t = m+1; i >= 0; i--) {
        while(m >= t && intersect(ch[m-2], ch[m-1], p[i]) <= 0) m--;
        ch[m++] = p[i];
    }
}

// verifica se o ponto p está na linha que contém o segmento segment.
int onLine(Segment segment, Point p) {
    if ((segment.s.x-segment.t.x)*(p.y-segment.s.y) != (segment.s.y-segment.t.y)*(p.x-segment.s.x)) return 0;
    if (p.x < segment.s.x && p.x < segment.t.x) return 0;
    if (p.x > segment.s.x && p.x > segment.t.x) return 0;
    if (p.y < segment.s.y && p.y < segment.t.y) return 0;
    if (p.y > segment.s.y && p.y > segment.t.y) return 0;
    return 1;
}

// verifica se dois segmentos de reta se intersectam
int intersection(Segment a, Segment b) {
    if (onLine(a, b.s) || onLine(a, b.t) || onLine(b, a.s) || onLine(b, a.t)) return 1;

    if (intersect(a.s, a.t, b.s)*intersect(a.s, a.t, b.t) < 0 &&
       intersect(a.t, a.s, b.s)*intersect(a.t, a.s, b.t) < 0 &&
       intersect(b.s, b.t, a.s)*intersect(b.s, b.t, a.t) < 0 &&
       intersect(b.t, b.s, a.s)*intersect(b.t, b.s, a.t) < 0)
       return 1;
    return 0;
}

// adiciona uma aresta direcionada do vértice x para o vértice y
void addEdge(int x, int y) {
    graph[x][transposedGraph[x]++] = y;
}

// algoritmo de Tarjan para encontrar as componentes fortemente conectadas (SCC) do grafo
int getSCC(int nd) {
    inVertexStack[nd] = visitedVertices[nd] = 1;
    vertexStack[++stackTop] = nd;
    visited[nd] = ++totalVisited;
    int mn = visited[nd];
    for (int i = 0; i < transposedGraph[nd]; i++) {
        if (!visitedVertices[graph[nd][i]]) mn = min(mn, getSCC(graph[nd][i]));
        if (inVertexStack[graph[nd][i]]) mn = min(mn, visited[graph[nd][i]]);
    }
    if (mn == visited[nd]) {
        do {
            inVertexStack[vertexStack[stackTop]] = 0;
            SCComponents[vertexStack[stackTop]] = totalSCC;
        } while (vertexStack[stackTop--] != nd);
        totalSCC++;
    }
    return mn;
}

int main() {
    int numRectangles, i, j, hasSolution, f1, f2, f3, f4;
    Point p[4], rectangle[1000][10];
    Segment a, b;

    cin >> numRectangles;

    while (numRectangles != 0) {
        for (i = 0; i < numRectangles; i++) {
            for (j = 0; j < 4; j++) cin >> p[j].x >> p[j].y;
            convexHull(4, p, rectangle[i]);
        }

        memset(visitedVertices, 0, sizeof(visitedVertices));
        memset(inVertexStack, 0, sizeof(inVertexStack));
        memset(transposedGraph, 0, sizeof(transposedGraph));

        for (i = 0; i < numRectangles; i++) {
            for (j = 0; j < i; j++) {
                a.s = rectangle[i][0];
                a.t = rectangle[i][2];
                b.s = rectangle[j][0];
                b.t = rectangle[j][2];
                f1 = intersection(a, b);

                a.s = rectangle[i][0];
                a.t = rectangle[i][2];
                b.s = rectangle[j][1];
                b.t = rectangle[j][3];
                f2 = intersection(a, b);

                a.s = rectangle[i][1];
                a.t = rectangle[i][3];
                b.s = rectangle[j][0];
                b.t = rectangle[j][2];
                f3 = intersection(a, b);

                a.s = rectangle[i][1];
                a.t = rectangle[i][3];
                b.s = rectangle[j][1];
                b.t = rectangle[j][3];
                f4 = intersection(a, b);

                if (f1) {
                    addEdge(i<<1, j<<1|1);
                    addEdge(j<<1, i<<1|1);
                }

                if (f2) {
                    addEdge(i<<1, j<<1);
                    addEdge(j<<1|1, i<<1|1);
                }

                if (f3) {
                    addEdge(i<<1|1, j<<1|1);
                    addEdge(j<<1, i<<1);
                }

                if (f4) {
                    addEdge(i<<1|1, j<<1);
                    addEdge(j<<1|1, i<<1);
                }
            }
        }

        totalSCC = 1;
        for (i = 0; i < 2*numRectangles; i++) {
            if (!visitedVertices[i]) {
                stackTop = -1;
                totalVisited = 0;
                getSCC(i);
            }
        }
        
        hasSolution = 1;
        for (i = 0; i < numRectangles; i++)
            if (SCComponents[i<<1] == SCComponents[i<<1|1]) hasSolution = 0;

        cout << (hasSolution ? "YES" : "NO") << endl;
        cin >> numRectangles;
    }
    return 0;
}