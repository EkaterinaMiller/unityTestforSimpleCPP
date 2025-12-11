/**
 * @file main.cpp
 * @brief This program Reads the winners of World Series from the file,
 *          creats a vector of structures, where each element is the record that shows 
 *          the team name and the number of time team won.
 *          The program display the original vector of record, 
 *          then sorts the vector based on the number of wins and display it again
 * @date 2025-12-11
 * 
 */
#include "record.h"
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main()
{
    //open the file, check for error
    ifstream file("WorldSeriesWinners.txt");
    if (!file){
        cerr <<"Error opening file\n";
        exit(EXIT_FAILURE);
    }
    //create a vector
    vector<Record> winners;

    //read each line of the file
    string line;
    while (getline(file, line)){
        //if vector is empty, add a team
        if(winners.empty()){
            addTeam(winners, line);
        }else{//else (vector is not empty)
            //go through each record and see if team name == line
            bool found=searchTeam(winners, line);
            if (!found)
            {
                addTeam(winners, line);
            }
        }
    
    }
    //display vector
    displayVector(winners);

    cout<<"\n\n################Sorted vector################\n\n";

    insertionSortW(winners);
    displayVector(winners);


}