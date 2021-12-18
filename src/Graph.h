#ifndef GRAPH_H
#define GRAPH_H

#include <string>
#include <queue>
#include <vector>
#include <iostream>
#include <iomanip>
#include <math.h>
#include <cstdlib>
#include <fstream>
#include <string>
#include <stdio.h>
#include <stdlib.h>


using namespace std;

class Graph
{
public:
    virtual ~Graph();
    Graph();
    Graph(string path);
    //wczytywane z pliku
    int edges, vertices;
    int **matrix;
    int bestPath;
    string instanceName;

    void printGraph();

    //algorytmy
    void tspBruteForce(int sVertex, int vertex, int *bestPathWeight, int currPathWeight, bool* visited, vector<int> currPath, vector<int>* bestPath);
    int tspDP(int sVertex, int positon, int* bestPathWeight, int currPathWeight, int visited, int** memo, int** citiesArray);

protected:
private:
    void initMatrix();
};

#endif // GRAPH_H
