#ifndef RECORD_H
#define RECORD_H
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

struct Record 
{
    string teamName;
    int numberOfWins;
};
//needed for UnityTesting testing
bool operator==(const Record &r1, const Record &r2);

void addTeam(vector<Record> &v, string name);
bool searchTeam(vector<Record> &v, string name);
//Refactored Code (takes std::ostream reference) for UnityTesting not changes to main:
void displayVector(const vector<Record> &v, std::ostream& os = std::cout);
void insertionSortW(vector<Record> &v);

#endif