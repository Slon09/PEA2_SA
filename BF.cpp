
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

using namespace std;

double time_measure;
int number;
int graph1[10][10];
int number_of_vertex;

int startTime()
{
	time_measure = clock(); //poczatek mierzenia czasu

	return time_measure;
}

int stopTime(string output)
{

	ofstream time_file;
	time_file.open(output, ofstream::app);

	time_measure = (clock() - time_measure) / (double)(CLOCKS_PER_SEC / 1000); // koniec mierzenia czasu
																			   //zapis do plikU

	if (time_file.is_open())
	{
		time_file << "Matrix;Prim;" << time_measure << endl;
		time_file.close();
		cout << endl;
	}

	return time_measure;
}

int readFromFile(string input)
{
	ifstream file;
	file.open(input);
	string line;

	if (file.is_open())
	{
		getline(file, line);
		istringstream reading1(line);
		reading1 >> number_of_vertex;

		for (int i = 0; i < 6; i++)
		{

			getline(file, line);
			istringstream reading2(line);

			for (int j = 0; j < number_of_vertex; j++)
			{
				reading2 >> graph1[i][j];
				cout << graph1[i][j] << " ";
			}
			cout << "\n";
		}
	}
	return number_of_vertex;
}

int travellingSalesmanProblem(int graph1[10][10], int start_point, int number_of_vertex, string output)
{

	ofstream time_file;
	time_file.open(output, ofstream::app);

	time_measure = clock(); //poczatek mierzenia czasu

	// store all vertex apart from source vertex
	vector<int> vertex;
	for (int i = 0; i < number_of_vertex; i++)
		if (i != start_point)
			vertex.push_back(i);

	// store minimum weight Hamiltonian Cycle.
	int min_path = INT_MAX;
	do
	{

		// store current Path weight(cost)
		int current_pathweight = 0;

		// compute current path weight
		int k = start_point;
		for (int i = 0; i < vertex.size(); i++)
		{
			current_pathweight += graph1[k][vertex[i]];
			k = vertex[i];
		}
		current_pathweight += graph1[k][start_point];

		// update minimum
		min_path = min(min_path, current_pathweight);

	} while (
		next_permutation(vertex.begin(), vertex.end()));

	return min_path;

	time_measure = (clock() - time_measure) / (double)(CLOCKS_PER_SEC / 1000); // koniec mierzenia czasu
																			   //zapis do plikU

	if (time_file.is_open())
	{
		time_file << "Matrix;Prim;" << time_measure << endl;
		time_file.close();
		cout << endl;
	}
}

int main()
{

	int size[20];
	int new_size;
	int size_now;
	string parameters;
	string input1, input2;
	string output;
	fstream config_file;
	string line;

	int start_point = 0;

	//readINI("parameters.ini");

	config_file.open("parameters.ini");

	getline(config_file, line);
	istringstream reading1(line);
	reading1 >> input1;

	getline(config_file, line);
	istringstream reading2(line);
	reading2 >> input2;

	getline(config_file, line);
	istringstream reading_output(line);
	reading_output >> output;

	cout << output << endl;

	cout << input1 << "\n";
	readFromFile(input1);

	startTime();
	cout << travellingSalesmanProblem(graph1, start_point, number_of_vertex, output) << "\n"
		 << endl;
	stopTime(output);

	cout << input2 << "\n";
	readFromFile(input2);
	cout << travellingSalesmanProblem(graph1, start_point, number_of_vertex, output) << "\n"
		 << endl;

	//getline(config_file, line);
	//istringstream reading2(line);

	//getline(config_file, line);
	//istringstream reading3(line);

	//config_file.close();

	//ofstream times;
	//times.open(output, ofstream::app);

	//for (int i = 0; i < 13; i++) {
	//	reading2 >> new_size;
	//	size[i] = new_size;
	//	cout << size[i] << ",  ";
	//}

	config_file.close();

	return 0;
}
