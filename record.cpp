#include "record.h"

void displayVector(const vector<Record> &v, std::ostream& os)
{
    os << "   Team name             Number of wins\n"
         << "-------------------------------------------\n";
    for (size_t i{0}; i<v.size(); i++)
    {
        os<<setw(30)<<left<<v[i].teamName<<v[i].numberOfWins<<'\n';
    }
}

void insertionSortW(vector<Record> &v)
{
    for (size_t startScan = 1; startScan < v.size(); ++startScan)
    {
        Record key = v[startScan];
        int index = startScan - 1;

        while (index >= 0 && v[index].numberOfWins < key.numberOfWins)
        {
            v[index+1] = v[index];
            --index;
        }
        v[index+1] = key;
    }
}

void addTeam(vector<Record> &v, string name)
{
    //create and object
    Record temp{name, 1};
    //push it to the vector
    v.push_back(temp);
}

bool searchTeam(vector<Record> &v, string name)
{
    for (size_t i{0}; i<v.size(); i++)
    {
        if (v[i].teamName == name) //if name exist
        {
            v[i].numberOfWins++;//update numberOfwins;
            return true;
        }
    }
    return false;
}

bool operator==(const Record &r1, const Record &r2){
    return (r1.numberOfWins==r2.numberOfWins && r1.teamName==r2.teamName);
}