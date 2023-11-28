#include<iostream>
#include<cstdlib> // atoi
#include<vector>
#include<list>
#include <iomanip> // setw
using namespace std;

typedef unsigned int Vertex;
typedef unsigned int Weight;

class WeightedGraphAM {
    private:
        unsigned int num_vertices;
        unsigned int num_edges;
        Weight **adj;
    public:

    WeightedGraphAM(unsigned int num_vertices);
    ~WeightedGraphAM();
    void add_edge(Vertex u,Vertex v, Weight w);
    void remove_edge(Vertex u,Vertex v);
    unsigned int get_num_vertices() { return num_vertices;}
    unsigned int get_num_edges() {return num_edges;}
    list<Vertex> get_adj(Vertex v);
    Weight get_weight_edge(Vertex u,Vertex v);


};
