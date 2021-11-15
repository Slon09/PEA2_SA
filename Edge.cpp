#include "Edge.h"

Edge::Edge() {

}

Edge::Edge(int sVertex, int eVertex, int weight)
{
    this->endVertex = eVertex;
    this->startVertex = sVertex;
    this->weight = weight;
}

Edge::~Edge()
{
    
}
