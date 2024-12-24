#include <iostream>
using namespace std;

struct ElmNode;
struct ElmEdge {
    ElmNode *Node;
    ElmEdge *Next;
};

struct ElmNode {
    int info;
    ElmEdge *firstEdge;
    ElmNode *Next;
};

struct Graph {
    ElmNode *first;
    int numNodes;
};

void CreateGraph(Graph &G) {
    G.first = NULL;
    G.numNodes = 0;
}

void InsertNode(Graph &G, int X) {
    ElmNode *newNode = new ElmNode;
    newNode->info = X;
    newNode->firstEdge = NULL;
    newNode->Next = NULL;
    if (G.first == NULL) {
        G.first = newNode;
    } else {
        ElmNode *temp = G.first;
        while (temp->Next != NULL) {
            temp = temp->Next;
        }
        temp->Next = newNode;
    }
    G.numNodes++;
}

void ConnectNode(ElmNode *N1, ElmNode *N2) {
    ElmEdge *newEdge1 = new ElmEdge;
    newEdge1->Node = N2;
    newEdge1->Next = N1->firstEdge;
    N1->firstEdge = newEdge1;

    ElmEdge *newEdge2 = new ElmEdge;
    newEdge2->Node = N1;
    newEdge2->Next = N2->firstEdge;
    N2->firstEdge = newEdge2;
}

ElmNode* GetNode(Graph G, int index) {
    ElmNode *temp = G.first;
    for(int i = 1; i < index; i++) {
        if(temp == NULL) return NULL;
        temp = temp->Next;
    }
    return temp;
}

void PrintMatrix(Graph G) {
    cout << "Adjacency Matrix:" << endl;
    for(int i = 1; i <= G.numNodes; i++) {
        ElmNode* node1 = GetNode(G, i);
        for(int j = 1; j <= G.numNodes; j++) {
            bool connected = false;
            ElmNode* node2 = GetNode(G, j);
            ElmEdge* edge = node1->firstEdge;
            while(edge != NULL) {
                if(edge->Node == node2) {
                    connected = true;
                    break;
                }
                edge = edge->Next;
            }
            cout << (connected ? "1" : "0") << " ";
        }
        cout << endl;
    }
}

int main() {
    Graph G;
    CreateGraph(G);

    int vertices, edges;
    cout << "Masukkan jumlah simpul: ";
    cin >> vertices;

    for(int i = 1; i <= vertices; i++) {
        InsertNode(G, i);
    }

    cout << "Masukkan jumlah sisi: ";
    cin >> edges;

    cout << "Masukkan pasangan simpul: " << endl;
    for(int i = 0; i < edges; i++) {
        int v1, v2;
        cin >> v1 >> v2;
        ElmNode *node1 = GetNode(G, v1);
        ElmNode *node2 = GetNode(G, v2);
        if(node1 != NULL && node2 != NULL) {
            ConnectNode(node1, node2);
        }
    }

    cout << endl;
    PrintMatrix(G);

    return 0;
}
