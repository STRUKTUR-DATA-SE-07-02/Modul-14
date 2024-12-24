#include <iostream>
#include <string>
using namespace std;

struct ElmNode;
struct ElmEdge {
    ElmNode *Node;
    int weight;
    ElmEdge *Next;
};

struct ElmNode {
    string info;
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

void InsertNode(Graph &G, string X) {
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

void ConnectNode(ElmNode *N1, ElmNode *N2, int weight) {
    ElmEdge *newEdge = new ElmEdge;
    newEdge->Node = N2;
    newEdge->weight = weight;
    newEdge->Next = N1->firstEdge;
    N1->firstEdge = newEdge;
}

ElmNode* FindNode(Graph G, string name) {
    ElmNode *temp = G.first;
    while (temp != NULL) {
        if (temp->info == name) return temp;
        temp = temp->Next;
    }
    return NULL;
}

void PrintMatrix(Graph G) {

    cout << "      ";
    ElmNode *col = G.first;
    while (col != NULL) {
        cout << col->info << "     ";
        col = col->Next;
    }
    cout << endl;

    // Print matrix
    ElmNode *row = G.first;
    while (row != NULL) {
        cout << row->info << "     ";
        ElmNode *col = G.first;
        while (col != NULL) {
            bool found = false;
            int weight = 0;
            ElmEdge *edge = row->firstEdge;
            while (edge != NULL) {
                if (edge->Node == col) {
                    found = true;
                    weight = edge->weight;
                    break;
                }
                edge = edge->Next;
            }
            cout << weight << "      ";
            col = col->Next;
        }
        cout << endl;
        row = row->Next;
    }
}

int main() {
    Graph G;
    CreateGraph(G);

    int numNodes;
    cout << "Silakan masukan jumlah simpul : ";
    cin >> numNodes;

    cout << "Silakan masukan nama simpul\n";
    for (int i = 0; i < numNodes; i++) {
        string nodeName;
        cout << "Simpul " << i + 1 << " : ";
        cin >> nodeName;
        InsertNode(G, nodeName);
    }

    cout << "Silakan masukkan bobot antar simpul\n";
    ElmNode *node1 = G.first;
    while (node1 != NULL) {
        ElmNode *node2 = G.first;
        while (node2 != NULL) {
            int weight;
            cout << node1->info << "-->" << node2->info << " = ";
            cin >> weight;
            if (weight != 0) {
                ConnectNode(node1, node2, weight);
            }
            node2 = node2->Next;
        }
        node1 = node1->Next;
    }

    cout << endl;
    PrintMatrix(G);

    return 0;
}
