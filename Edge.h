#ifndef EDGE_H
#define EDGE_H


class Edge
{
    public:
        Edge();
        Edge(int, int, int);
        //pola krawedz
        //wierzcholek startowy, koncowy i waga krawedzi
        int startVertex, endVertex, weight;

        //funktor sortujący
        //sortuje krawedzie względem wagi niemalejaco
        bool operator()(const Edge &e1, const Edge &e2){
            if(e1.weight > e2.weight) return true;
            if(e1.weight < e2.weight) return false;
            return false;
        }
        ~Edge();
};

#endif // EDGE_H
