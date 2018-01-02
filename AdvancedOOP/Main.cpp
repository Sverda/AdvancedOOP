#include<iostream>
#include<cstdlib>
#include<ctime>
#include<vector>
#include<set>
#include<algorithm>
#include<numeric>
#include"StaticticEquationFunctor.h"
using namespace std;

multiset<double> InitializeObservations(int n, int constraint);
int MultisetDistance(multiset<double>::iterator begin, multiset<double>::iterator end);

void main()
{
	srand(time(nullptr));
	const int size = 1000;
	const int amountOfSpecies = 10;

	multiset<double> r = InitializeObservations(size, amountOfSpecies);
	multiset<double> s = InitializeObservations(size, amountOfSpecies);

	vector<double> counterOfR(10), counterOfS(10);
	pair<vector<double>, vector<double>> observationsCounters(counterOfR, counterOfS);
	for (int i = 0; i < amountOfSpecies; ++i)
	{
		pair<multiset<double>::iterator, multiset<double>::iterator> specificObservationBounds = equal_range(r.begin(), r.end(), i);
		observationsCounters.first[i] = MultisetDistance(specificObservationBounds.first, specificObservationBounds.second);

		specificObservationBounds = equal_range(s.begin(), s.end(), i);
		observationsCounters.second[i] = MultisetDistance(specificObservationBounds.first, specificObservationBounds.second);
	}

	const double result = inner_product(observationsCounters.first.begin(), observationsCounters.first.end(), observationsCounters.second.begin(), 0, plus<double>(), StatisticEquation<double>());
	cout << "Equation result: " << result << endl;
	getchar();
}

multiset<double> InitializeObservations(int n, int constraint)
{
	multiset<double> observations;
	for (int i = 0; i < n; i++)
		observations.insert(rand() % constraint);
	return observations;
}

int MultisetDistance(multiset<double>::iterator begin, multiset<double>::iterator end)
{
	int n = 0;
	for (multiset<double>::iterator i = begin; i != end; ++i)
	{
		++n;
	}
	return n;
}