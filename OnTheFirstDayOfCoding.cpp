/*
*   Problem: On The First Day Of Coding...
*   Problem Link: https://hyperskill.org/learn/daily/53336
* */

#include <bits/stdc++.h>
using namespace std;


int main() {
    ifstream file("hyperskill-dataset-118967086.txt");
    string line;
    
    int hour, minute;
    char colon;
    string error;
    
    map<string, int> errorsAllDay;
    map<string, int> errorsFiltered;
    
    while (getline(file, line)) {
        stringstream ss(line);
        ss >> hour >> colon >> minute >> error;

        errorsAllDay[error] += 1;
        
        if (hour == 15 && minute <= 30) 
            errorsFiltered[error] += 1;
    }
    
    auto mostErrorAllDay = max_element(errorsAllDay.begin(), errorsAllDay.end(),
        [](const pair<string, int>& a, const pair<string, int>& b){
            return a.second < b.second;
        });
    
    errorsFiltered.erase(mostErrorAllDay->first);
    
    auto res = max_element(errorsFiltered.begin(), errorsFiltered.end(),
        [](const pair<string, int>& a, const pair<string, int>& b){
            return a.second < b.second;
        });
    
    cout << res->first;
    return 0;
}
