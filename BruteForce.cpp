#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstdio>
#include <time.h>
#include <algorithm>
#include <string>
#include <sstream>
#include <limits.h>
#include <vector>
#include <queue>
#include <set>
#include <list>
#include <stdio.h>
#include <conio.h>
using namespace std;

int **readGraph(string);
int main()
{
    int number_of_vertex;
    string input;
    cout << "Podaj plik z grafem: ";
    cin >> input;

    cout << "dupa1" << endl;
    getch();

    int **graph = readGraph(input);

    cout << "dupa2" << endl;
    getch();
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }
    getch();
}

int **readGraph(string input)
{
    int n;
    ifstream file;
    file.open(input, ios::in);

    if (!file.good())
    {
        cout << "Nie odnaleziono pliku" << endl;
        getch();
    }
    string line;
    //pobieranie nazwy pliku
    getline(file, line);
    //pobieranie ilosci miast
    getline(file, line);
    n = stoi(line);
    int **graph = new int *[n];
    for (int i = 0; i < n; i++)
    {
        graph[i] = new int[n];
    }
    char vertexes[n];

    cout << "graf postawiony" << endl;

    for (int i = 0; i < n; i++)
    {
        if(!isspace(line[i]))
    }
    cout << "graf wczytany" << endl;

    return graph;
}

void tsp(int *graph, int startVertex)
{
}