/*
*   Problem: On The Eighth Day Of Coding...
*   Problem Link: https://hyperskill.org/learn/daily/53349
*   Topic: Eight Queens Problem
* */

#include <bits/stdc++.h>
using namespace std;

int main() {
  ifstream file("hyperskill-dataset-119120519.txt");

  int attackPairs{};
  map<int, int> rows{};
  map<int, int> cols{};
  map<int, int> firstDiag{};
  map<int, int> secondDiag{};

  int r, c;
  char comma;
  string line;
  while (file >> line) {
    stringstream ss(line);
    ss >> r >> comma >> c;

    if (rows.count(r)) attackPairs += rows[r];
    rows[r]++;

    if (cols.count(c)) attackPairs += cols[c];
    cols[c]++;

    if (firstDiag.count(r - c)) attackPairs += firstDiag[r - c];
    firstDiag[r - c]++;

    if (secondDiag.count(r + c)) attackPairs += secondDiag[r + c];
    secondDiag[r + c]++;
  }

  cout << attackPairs;
  return 0;
}
