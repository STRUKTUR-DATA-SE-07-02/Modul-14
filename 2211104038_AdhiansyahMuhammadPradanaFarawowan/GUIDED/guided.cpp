#include <iostream>
#include <queue>

struct ElmNode;

struct ElmEdge
{
    ElmNode *Node;
    ElmEdge *next;
};

struct ElmNode
{
    char info;
    bool visited;
    ElmEdge *first_edge;
    ElmNode *next;
};

struct Graph
{
    ElmNode *first;
};

void create_graph(Graph &G)
{
    G.first = NULL;
}

void insert_node(Graph &G, char X)
{
    ElmNode *new_node = new ElmNode;
    new_node->info = X;
    new_node->visited = false;
    new_node->first_edge = NULL;
    new_node->next = NULL;

    if (G.first == NULL)
    {
        G.first = new_node;
    }
    else
    {
        ElmNode *temp = G.first;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = new_node;
    }
}

void connect_node(ElmNode *N1, ElmNode *N2)
{
    ElmEdge *new_edge = new ElmEdge;
    new_edge->Node = N2;
    new_edge->next = N1->first_edge;
    N1->first_edge = new_edge;
}

void print_infos_graph(Graph G)
{
    ElmNode *temp = G.first;
    while (temp != NULL)
    {
        std::cout << temp->info << " ";
        temp = temp->next;
    }
    std::cout << '\n';
}

void reset_visited(Graph &G)
{
    ElmNode *temp = G.first;
    while (temp != NULL)
    {
        temp->visited = false;
        temp = temp->next;
    }
}

void traverse_dfs(Graph G, ElmNode *N)
{
    if (N == NULL)
    {
        return;
    }
    N->visited = true;
    std::cout << N->info << " ";
    ElmEdge *edge = N->first_edge;
    while (edge != NULL)
    {
        if (!edge->Node->visited)
        {
            traverse_dfs(G, edge->Node);
        }
        edge = edge->next;
    }
}

void traverse_bfs(Graph G, ElmNode *N)
{
    std::queue<ElmNode *> q;
    q.push(N);
    N->visited = true;

    while (!q.empty())
    {
        ElmNode *current = q.front();
        q.pop();
        std::cout << current->info << " ";

        ElmEdge *edge = current->first_edge;
        while (edge != NULL)
        {
            if (!edge->Node->visited)
            {
                edge->Node->visited = true;
                q.push(edge->Node);
            }
            edge = edge->next;
        }
    }
}

int main()
{
    Graph G;
    create_graph(G);

    insert_node(G, 'A');
    insert_node(G, 'B');
    insert_node(G, 'C');
    insert_node(G, 'D');
    insert_node(G, 'E');
    insert_node(G, 'F');
    insert_node(G, 'G');
    insert_node(G, 'H');

    ElmNode *A = G.first;
    ElmNode *B = A->next;
    ElmNode *C = B->next;
    ElmNode *D = C->next;
    ElmNode *E = D->next;
    ElmNode *F = E->next;
    ElmNode *G1 = F->next;
    ElmNode *H = G1->next;

    connect_node(A, B);
    connect_node(A, C);
    connect_node(B, D);
    connect_node(B, E);
    connect_node(C, F);
    connect_node(C, G1);
    connect_node(D, H);

    std::cout << "DFS traversal: ";
    reset_visited(G);
    traverse_dfs(G, A);
    std::cout << '\n';

    std::cout << "BFS traversal: ";
    reset_visited(G);
    traverse_bfs(G, A);
    std::cout << '\n';

    return 0;
}
