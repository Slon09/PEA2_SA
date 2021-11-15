#include <iostream>
#include <fstream>
#include <conio.h>
using namespace std;

void print(int **tab, int n);
int main()
{

    ifstream plik("C:\\Users\\Ja\\Desktop\\instances\\m6.atsp");
    int n; //liczba wierzcholkow
    string nul;
    if (plik.good())
    {
        plik >> nul;
        plik >> n;
    }
    else
        cout << "nie mozna otworzyc plku! \n";

    //w tablice wpiszemy liste sasiedztaw
    int **tab = new int *[n];
    for (int i = 0; i < n; i++)
        tab[i] = new int[n];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            plik >> tab[i][j];

    cout << "wczytana lista sasiedztwa: \n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << tab[i][j] << "  ";
        cout << endl;
    }


    _getch();
}