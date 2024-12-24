#include <iostream>
#include <queue>

using namespace std;

struct ElmNode;

struct ElmEdge {
    ElmNode *Node;
    ElmEdge *Next;
};

struct ElmNode {
    char info;
    bool visited;
    ElmEdge *firstEdge;
    ElmNode *Next;
};

struct Graph {
    ElmNode *first;
};

// Fungsi untuk membuat graf baru
void CreateGraph(Graph &G) {
    G.first = NULL; // Inisialisasi graf kosong
}

// Fungsi untuk menambahkan node baru ke graf
void InsertNode(Graph &G, char X) {
    ElmNode *newNode = new ElmNode; // Alokasi memori untuk node baru
    newNode->info = X;             // Menyimpan informasi
    newNode->visited = false;      // Status awal belum dikunjungi
    newNode->firstEdge = NULL;     // Belum ada tepi
    newNode->Next = NULL;          // Node berikutnya adalah NULL

    if (G.first == NULL) {
        G.first = newNode; // Jika graf kosong, tambahkan sebagai simpul pertama
    } else {
        ElmNode *temp = G.first;
        while (temp->Next != NULL) {
            temp = temp->Next; // Cari node terakhir dalam daftar
        }
        temp->Next = newNode; // Tambahkan node baru di akhir
    }
}

// Fungsi untuk membuat hubungan antar node (menambahkan tepi)
void ConnectNode(ElmNode *N1, ElmNode *N2) {
    ElmEdge *newEdge = new ElmEdge; // Alokasi memori untuk tepi baru
    newEdge->Node = N2;            // Tepi menghubungkan ke simpul N2
    newEdge->Next = N1->firstEdge; // Sisipkan di awal daftar tepi
    N1->firstEdge = newEdge;       // Perbarui daftar tepi N1
}

// Fungsi untuk mencetak informasi node dalam graf
void PrintInfoGraph(Graph G) {
    ElmNode *temp = G.first;
    while (temp != NULL) {
        cout << temp->info << " "; // Cetak informasi setiap simpul
        temp = temp->Next;         // Lanjut ke simpul berikutnya
    }
    cout << endl;
}

// Fungsi untuk mengatur ulang status visited semua simpul
void ResetVisited(Graph &G) {
    ElmNode *temp = G.first;
    while (temp != NULL) {
        temp->visited = false; // Reset visited ke false
        temp = temp->Next;
    }
}

// Fungsi untuk traversal graf menggunakan DFS
void PrintDFS(Graph G, ElmNode *N) {
    if (N == NULL) {
        return; // Basis rekursi, jika simpul NULL, selesai
    }
    N->visited = true; // Tandai simpul telah dikunjungi
    cout << N->info << " "; // Cetak informasi simpul

    ElmEdge *edge = N->firstEdge;
    while (edge != NULL) {
        if (!edge->Node->visited) {
            PrintDFS(G, edge->Node); // Rekursi ke simpul yang terhubung
        }
        edge = edge->Next;
    }
}

void PrintBFS(Graph G, ElmNode *N) {
    queue<ElmNode*> q;
    q.push(N);
    N->visited = true;

    while (!q.empty()) {
        ElmNode *current = q.front();
        q.pop();
        cout << current->info << " ";

        ElmEdge *edge = current->firstEdge;
        while (edge != NULL) {
            if (!edge->Node->visited) {
                edge->Node->visited = true;
                q.push(edge->Node);
            }
            edge = edge->Next;
        }
    }
}

int main() {
    Graph G;
    CreateGraph(G);

    InsertNode(G, 'A');
    InsertNode(G, 'B');
    InsertNode(G, 'C');
    InsertNode(G, 'D');
    InsertNode(G, 'E');
    InsertNode(G, 'F');
    InsertNode(G, 'G');
    InsertNode(G, 'H');

    ElmNode *A = G.first;
    ElmNode *B = A->Next;
    ElmNode *C = B->Next;
    ElmNode *D = C->Next;
    ElmNode *E = D->Next;
    ElmNode *F = E->Next;
    ElmNode *G1 = F->Next;
    ElmNode *H = G1->Next;

    ConnectNode(A, B);
    ConnectNode(A, C);
    ConnectNode(B, D);
    ConnectNode(B, E);
    ConnectNode(C, F);
    ConnectNode(C, G1);
    ConnectNode(D, H);

    cout << "DFS traversal: ";
    ResetVisited(G);
    PrintDFS(G, A);
    cout << endl;

    cout << "BFS traversal: ";
    ResetVisited(G);
    PrintBFS(G, A);
    cout << endl;

    return 0;
}