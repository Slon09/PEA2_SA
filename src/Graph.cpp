#include "Graph.h"
#include <iostream>
#include <fstream>
#include <sstream>


using namespace std;

Graph::Graph() {

}

Graph::Graph(string path)
{
    setlocale(LC_ALL, "polish");
    ifstream file;
    file.open(path, ios::in);

    string line;
    if (file.is_open())
    {
        getline(file, line);
        this->instanceName = line;

        getline(file, line);
        istringstream s(line);
        s >> this->vertices;

        this->initMatrix();

        for (int i = 0; i < vertices; i++)
        {
            getline(file, line);
            istringstream s(line);
            for (int j = 0; j < vertices; j++)
            {
                s >> matrix[i][j];
            }
        }
        getline(file, line);
        this->bestPath = atoi(line.c_str());
    }

}

Graph::~Graph()
{
    
}

void Graph::initMatrix()
{
    //macierz sąsiedztwa
    matrix = new int* [vertices];
    for (int i = 0; i < this->vertices; i++)
    {
        matrix[i] = new int[vertices];
    }
    //wypelnianie macierzy zerami
    for (int i = 0; i < vertices; i++)
    {
        for (int j = 0; j < vertices; j++)
        {
            matrix[i][j] = 0;
        }
    }
}


void Graph::printGraph() {
    cout << endl;
    cout << this->vertices << endl;
    for (int i = 0; i < this->vertices; i++) {
        for (int j = 0; j < this->vertices; j++)
        {
            cout << this->matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << this->bestPath << endl;
}



void Graph::tspBruteForce(int sVertex, int vertex, int* bestPathWeight, int currPathWeight, bool* visited, vector<int> currPath, vector<int>* bestPath) 
{
        currPath.push_back(vertex); 
        

        if (currPath.size() == this->vertices) {
            currPathWeight += this->matrix[vertex][sVertex];

            if (currPathWeight < *bestPathWeight) {
                *bestPathWeight = currPathWeight;
                *bestPath = currPath;
                float PRD = 100 * (((float)*bestPathWeight - (float)this->bestPath) / (float)this->bestPath);
                printf("Dlugosc cyklu: %d\t PRD: %0.2f%%\n", *bestPathWeight, PRD);
            }
        }

        visited[vertex] = true;
        for (int i = 0; i < this->vertices; i++) {
            if (!visited[i]) {
                currPathWeight += this->matrix[vertex][i];       
                    this->tspBruteForce(sVertex, i, bestPathWeight, currPathWeight, visited, currPath, bestPath);
                currPathWeight -= this->matrix[vertex][i];
            }
        }
        visited[vertex] = false;
        currPath.pop_back();
}

int Graph::tspDP(int sVertex, int position, int* bestPathWeight, int currPathWeight, int visited, int** memo, int** lastCityArray) {
    
    int all_visited = (1 << this->vertices) - 1;

    if (visited == all_visited) {
        return this->matrix[position][sVertex];
    }

    if (memo[visited][position] != -1) {
        return memo[visited][position];
    }

    int cost = INT_MAX;
    int tmpCity = -1;

    for (int city = 0; city < this->vertices; city++) {
        
        if ((visited  &  (1 << city)) == 0) {
            int newVisited = (visited | (1 << city));

            int tmpCost = this->matrix[position][city] + this->tspDP(sVertex, city, bestPathWeight, currPathWeight, newVisited, memo, lastCityArray);
            if (tmpCost < cost) {
                cost = tmpCost;
                tmpCity = city;
            }
            *bestPathWeight = cost;

        }
    }

    lastCityArray[visited][position] = tmpCity;
    return memo[visited][position] = cost;
}
