#include <iostream>
#include <vector>
#include <list>
#include <iomanip>
using namespace std;

typedef unsigned int Vertex;
typedef float Weight;

class GraphAM
{
private:
    unsigned int num_vertices;
    unsigned int num_edges;
    Weight **adj;

public:
    GraphAM(unsigned int num_vertices);
    ~GraphAM();

    void add_edge(Vertex u, Vertex v, Weight w);
    void remove_edge(Vertex u, Vertex v);

    unsigned int get_num_vertices() { return num_vertices; }
    unsigned int get_num_edges() { return num_edges; }
    Weight get_weight_edge(Vertex u, Vertex v) { return adj[u][v]; }

    list<Vertex> get_adj(Vertex u)
    {
        std::list<Vertex> values;

        for (Vertex v = 0; v < num_vertices; ++v)
            if (adj[u][v] != 0)
                values.push_back(v);

        return values;
    }
};

/* Construtor ; Destrutor*/
GraphAM::GraphAM(unsigned int qtd_vertices) : num_vertices(qtd_vertices), num_edges(0)
{
    const unsigned int TAMANHO = qtd_vertices; // Qtd Linhas = Qtd Colunas (matriz quadrada)
    adj = new Weight *[TAMANHO];               // Vetor de ponteiros para pesos (pontos flutuantes)

    for (int i = 0; i < qtd_vertices; i++)
        adj[i] = new Weight[TAMANHO](); // Inicializar os vetores com zeros por padrão
}

GraphAM::~GraphAM()
{
    for (int u = 0; u < num_vertices; ++u)
        delete[] adj[u];

    adj = nullptr;
    // cout << "GraphAM obliterated" << endl;
}

/* Métodos */
void GraphAM::add_edge(Vertex u, Vertex v, Weight w)
{
    adj[u][v] = w;
    adj[v][u] = w;

    num_edges++;
}

void GraphAM::remove_edge(Vertex u, Vertex v)
{
    adj[u][v] = 0;
    adj[v][u] = 0;

    num_edges--;
}

void input_graph(GraphAM &g, unsigned int num_edges)
{
    Vertex u = 0, v = 0;
    for (int i = 0; i < num_edges; ++i)
    {
        cin >> u >> v;
        g.add_edge(u, v, 1);
    }
}

void display_matadj_graph(GraphAM &g)
{
    int k = 3;

    // Constrói cada linha da matriz
    for (unsigned int i = 0; i < g.get_num_vertices(); i++)
    {
        // Valores da linha
        for (unsigned int j = 0; j < g.get_num_vertices(); j++)
            cout << std::setw(k) << g.get_weight_edge(i, j) << " ";
        cout << endl;
    }
}

int main(int argc, char const *argv[])
{
    unsigned int num_vertices, num_edges;

    cin >> num_vertices >> num_edges;
    cout << "num_vertices:" << num_vertices << endl;
    cout << "num_edges:" << num_edges << endl;

    GraphAM g{num_vertices};
    input_graph(g, num_edges);

    display_matadj_graph(g);
    cout << std::endl;

    return 0;
}
