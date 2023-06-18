/*
 * Topicos Especiais em Programacao | UFRJ | 2023.1
 * Gabriele Jandres Cavalcanti | 119159948
 * Aula 9 (Lista 8) | Problema E | Morning Walk
*/

#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Vertex {
    int id;
    bool visited;
    vector<Vertex*> adj;          

    public:
        Vertex(int id) {
            this->id = id;
            visited = false;
        }

        bool isVisited() {
            return visited;
        }

        void setVisited() {
            this->visited = true;
        }

        int getDegree() {
            return adj.size();
        }

        void addAdj(Vertex* v) {
            adj.push_back(v);
        }

        vector<Vertex*> getAdj() {
            return adj;
        }
};

class Graph {
    map<int, Vertex*> vertices;	

    public:
        Graph(int numVertices) {
            for (int i = 0 ; i < numVertices ; i++) {
                Vertex* vertex = new Vertex(i);
                vertices.insert({i, vertex});
            }
                    
        }

        void DFS(Vertex* v) {
            v->setVisited();
            for (Vertex* u : v->getAdj())
                if (!u->isVisited()) DFS(u);
        }

        void addEdge(int u, int v) {
            Vertex* x = vertices[u];
            Vertex* y = vertices[v];
            x->addAdj(y);
            y->addAdj(x);
        }

        bool isConnected() {
            bool connected = false;
            for (auto& vertex : vertices) {
                if (vertex.second->getDegree() != 0) {
                    connected = true;
                    DFS(vertex.second);
                    break;
                }
            }

            for (auto& vertex : vertices) {
                if (vertex.second->isVisited() == false && vertex.second->getDegree() != 0)
                    connected = false;
                    
            }

            return connected;
        }


        bool hasEulerianPath() {
            bool eulerian = isConnected();

            for (auto& vertex: vertices) {
                if (vertex.second->getDegree() % 2 == 1) {
                    eulerian = false;
                    break;
                }               
            }              
            
            return eulerian;
        }
};

int main() {
    int numVertices, numEdges, i, u, v;

    while (cin >> numVertices && cin >> numEdges) {
        Graph graph(numVertices);
        
        for (i = 0; i < numEdges; i++) {
            cin >> u >> v;
            graph.addEdge(u,v);
        }

        cout << (graph.hasEulerianPath() ? "Possible" : "Not Possible") << endl;
    }

    return 0;
}