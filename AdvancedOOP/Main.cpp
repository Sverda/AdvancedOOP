#include<iostream>
#include<list>
#include<set>
#include<time.h>
using namespace std;

multiset<int> InitializeObservations();

void Main()
{
	multiset<int> r = InitializeObservations();
	multiset<int> s = InitializeObservations();
}

multiset<int> InitializeObservations()
{
	srand(time(NULL));
	multiset<int> observations;
	for (int i = 0; i<1000; i++)
		observations.insert(rand() % 10);
	return observations;
}