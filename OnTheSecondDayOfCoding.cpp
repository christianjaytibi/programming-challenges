/*
*   Problem: On The Second Day Of Coding...
*   Problem Link: https://hyperskill.org/learn/daily/53343
* */

#include <bits/stdc++.h>
using namespace std;


int main() {
    
    ifstream file("hyperskill-dataset-118981942.txt");
    int target;
    file >> target;
    
    vector<int> sweetnessLevels;
    string temp;
    while (getline(file, temp, ',')) {
        sweetnessLevels.push_back(stoi(temp));
    }
    
    int left{}, best{};
    int right = sweetnessLevels.size() - 1;
    
    while (left < right) {
        int average = ceil((double)(sweetnessLevels[left] + sweetnessLevels[right]) / 2);
        
        if (abs(target - average) < abs(target - best))
            best = average;
        
        if (average < target)
            left++;
        else if (average > target)
            right--;
        else
            break;
    }
    
    cout << best;
    return 0;
}
