/**
 * @file test.cpp
 * @author Ekaterina Miller
 * @brief This is unity test file for the lab1
 * @date 2025-12-11
 * 
 * @build g++ -Wall -pedantic-errors test.cpp ../record.cpp -o unityTest
 * @run ./unityTest
 * 
 */
#include "../record.h"
#include <iostream>
#include <vector>
#include <sstream> 
//#include <algorithm> // For std::equal
using namespace std;


void assertEqual(const vector<Record> &expected, const vector<Record> &actual, string message) {
    //needs operator== for Record
    if (expected != actual) {
        cerr << "Assertion Failed: " << message << '\n';
    }
}

void assertEqual(bool expected, bool actual, string message) {
    if (expected != actual) {
        cerr << "Assertion Failed: " << message << ". Expected: " << expected << ", Actual: " << actual << std::endl;
    }
}

void assertEqual(string expected, string actual, string message) {
    if (expected != actual) {
        cerr << "Assertion Failed: " << message << ". Expected: \n" << expected << "\n, Actual: \n" << actual << std::endl;
    }
}


void testAddTeamFunction() {
    vector<Record> input1;
    vector<Record> expected1({{"Team Name", 1}});
    addTeam(input1, "Team Name");
    assertEqual(input1, expected1, "addTeam(input, \"Team Name\") to empty vector");

    vector<Record> input2({{"Some Name", 1}});
    vector<Record> expected2({{"Some Name", 1}, {"Team Name", 1}});
    addTeam(input2, "Team Name");
    assertEqual(input1, expected1, "addTeam(input, \"Team Name\") to non-empty vector");

}

void testSearchTeamFunction() {
    vector<Record> input1;
    assertEqual(false, searchTeam(input1, "Team Name"), "searchTeam(input, \"Team Name\") in empty vector ");

    vector<Record> input2({{"Name 1", 1}, {"Name 2", 7}, {"Name 3", 5}});
    assertEqual(true, searchTeam(input2, "Name 1"), "searchTeam(input, \"Name 1\") in non-empty vector name exist");
    assertEqual(true, searchTeam(input2, "Name 2"), "searchTeam(input, \"Name 2\") in non-empty vector name exist");
    assertEqual(true, searchTeam(input2, "Name 3"), "searchTeam(input, \"Name 3\") in non-empty vector name exist");

    assertEqual(false, searchTeam(input2, "Team Name"), "searchTeam(input, \"Team Name\") in non-empty vector name does not exist");

}

void testDisplayVectorFunction() {
    std::stringstream output1;
    vector<Record> input1;
    string expectedOutput1 = "   Team name             Number of wins\n-------------------------------------------\n";
    displayVector(input1, output1);
    assertEqual(expectedOutput1, output1.str(), "displayVector(input1) an empty vector ");

    std::ostringstream output2;
    vector<Record> input2({{"New York Yankees", 15}, {"New York Giants", 1}, {"Brooklyn Dodgers", 1}});
    string expectedOutput2 = "   Team name             Number of wins\n-------------------------------------------\nNew York Yankees              15\nNew York Giants               1\nBrooklyn Dodgers              1\n";
    displayVector(input2, output2);
    assertEqual(expectedOutput2, output2.str(), "displayVector(input1) non-empty vector ");

}

void testInsertionSortWFunction() {
    vector<Record> input1;
    vector<Record> expected1;
    insertionSortW(input1);
    assertEqual(input1, expected1, "insertionSortW(input1) on empty vector");

    vector<Record> input2({{"New York Yankees", 15}, {"New York Giants", 17}, {"Brooklyn Dodgers", 3}});
    vector<Record> expected2({{"New York Giants", 17}, {"New York Yankees", 15}, {"Brooklyn Dodgers", 3}});
    insertionSortW(input2);
    assertEqual(input2, expected2, "insertionSortW(input1) on non-empty vector");
}

int main() {

    std::cout << "Running tests..." << std::endl;
    testAddTeamFunction();
    testSearchTeamFunction();
    testDisplayVectorFunction();
    testInsertionSortWFunction();
    std::cout << "Tests finished." << std::endl;
    return 0;
}