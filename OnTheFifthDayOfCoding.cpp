/*
*   Problem: On The Fifth Day Of Coding...
*   Problem Link: https://hyperskill.org/learn/daily/53346
* */

#include <bits/stdc++.h>
using namespace std;


int main() {
    ifstream file("hyperskill-dataset-119048796.txt");
    vector<pair<double, double>> points;
    
    string line;
    while (file >> line) {
        stringstream ss(line);
        char comma;
        double x, y;
        ss >> x >> comma >> y;
        points.push_back(make_pair(x, y));
    }
    
    double area = 0e-2;
    for (int i = 0; i < points.size(); ++i) {
        int j = (i + 1) % points.size();
        area += ((points[i].first * points[j].second) - (points[i].second * points[j].first));
    }
    
    area /= 2;
    cout << area;
    return 0;
}
