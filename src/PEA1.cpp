// PEA1.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include <string>
#include <fstream>
#include <locale.h>
#include <cstdlib>
#include <cstdio>
#include <conio.h>
#include <time.h>
#include <algorithm>
#include <string>
#include <sstream>
#include <limits.h>
#include <vector>
#include <queue>
#include <set>
#include <list>
#include <chrono>
#include "Graph.h"

using namespace std;
using namespace std::chrono;

void menu();
void tspDP(Graph* g, int startVertex);
void tspBruteForce(Graph*, int);
void tspBF(Graph* g, int sVertex);


int main()
{
    
    setlocale(LC_ALL, "polish");
    
    char input = ' ';

    while (input != 'q') {
        menu();
        cout << endl;
        cout << "Aby wyjsc wcisnij q" << endl;
        cout << "Aby powtorzyc wcisjni dowolny klawisz" << endl;
        input = _getch();
    }

    return 0;
}

void menu() {
    system("cls");
    string path;
    cout << "Ścieżka do pliku: ";
    cin >> path;

    Graph* g = new Graph(path);
    g->printGraph();

    cout << endl;
    cout << "Wybierz algorytm" << endl;
    cout << "1.Brute force" << endl;
    cout << "2.DP" << endl;
    char input;
    input = _getch();
    cout << endl;
    switch (input) {
    case '1':
        tspBruteForce(g, 0);
        break;
    case '2':
        tspDP(g, 0);
        break;
    }
}

void tspBruteForce(Graph* g, int startVertex) {
    bool* visited = new bool[g->vertices];
    vector<int>* bestPath = new vector<int>;
    vector<int> currPath;

    int* bestPathWeight = new int;
    *bestPathWeight = INT_MAX;
    int currPathWeight = 0;

    for (int i = 0; i < g->vertices; i++) {
        visited[i] = false;
    }

    auto start = high_resolution_clock::now();
        g->tspBruteForce(startVertex, startVertex, bestPathWeight, currPathWeight, visited, currPath, bestPath);
    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<milliseconds>(stop - start);
    printf("\nCzas działania algorytmu: %d ms\n", duration);
    printf("Waga najlepszej ścieżki: %d \n", *bestPathWeight);
    printf("Ścieżka:\n");

    for (int i = 0; i < bestPath->size(); i++) {
        printf("%d->", bestPath->at(i));
    }
    cout << startVertex << endl;
}


void tspDP(Graph* g, int startVertex) {

    int* bestPathWeight = new int;
    *bestPathWeight = INT_MAX;

    int currPathWeight = 0;

    int visited = (1 << (startVertex));

    int** memo = new int* [(1 << g->vertices)];
    int** lastCityArray = new int* [(1 << g->vertices)];

    for (int i = 0; i < (1 << g->vertices); i++) {
        memo[i] = new int[g->vertices];
        lastCityArray[i] = new int[g->vertices];
        for (int j = 0; j < g->vertices; j++) {
            memo[i][j] = -1;
            lastCityArray[i][j] = -1;
        }
    }

    int* bestPath = new int[g->vertices];
    bestPath[0] = startVertex;
    int index = 1;
    visited = 1;
    int lastCityIndex = 0;
    int tmpLastCityIndex;

    auto start = high_resolution_clock::now();
        int w = g->tspDP(startVertex, startVertex, bestPathWeight, currPathWeight, visited, memo, lastCityArray);
    
        for (int i = 0; i < g->vertices - 1; i++) {
            bestPath[index] = lastCityArray[visited][lastCityIndex];
            index++;
            tmpLastCityIndex = lastCityIndex;
            lastCityIndex = lastCityArray[visited][lastCityIndex];
            visited += (1 << lastCityArray[visited][tmpLastCityIndex]);
        }
    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<milliseconds>(stop - start);

    printf("\nCzas działania algorytmu: %d ms\n", duration);
    cout << endl;

    float PRD = 100 * (((float)w - (float)g->bestPath) / (float)g->bestPath);
    printf("Dlugosc cyklu: %d\t PRD: %0.2f%%\n", *bestPathWeight, PRD);
    cout << "Sciezka: ";
    for (int i = 0; i < g->vertices; i++) {
        cout << bestPath[i] << "->";
   }
    cout << startVertex << endl;
}



// Uruchomienie programu: Ctrl + F5 lub menu Debugowanie > Uruchom bez debugowania
// Debugowanie programu: F5 lub menu Debugowanie > Rozpocznij debugowanie

// Porady dotyczące rozpoczynania pracy:
//   1. Użyj okna Eksploratora rozwiązań, aby dodać pliki i zarządzać nimi
//   2. Użyj okna programu Team Explorer, aby nawiązać połączenie z kontrolą źródła
//   3. Użyj okna Dane wyjściowe, aby sprawdzić dane wyjściowe kompilacji i inne komunikaty
//   4. Użyj okna Lista błędów, aby zobaczyć błędy
//   5. Wybierz pozycję Projekt > Dodaj nowy element, aby utworzyć nowe pliki kodu, lub wybierz pozycję Projekt > Dodaj istniejący element, aby dodać istniejące pliku kodu do projektu
//   6. Aby w przyszłości ponownie otworzyć ten projekt, przejdź do pozycji Plik > Otwórz > Projekt i wybierz plik sln


