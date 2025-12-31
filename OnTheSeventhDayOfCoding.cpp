/*
*   Problem: On The Seventh Day Of Coding...
*   Problem Link: https://hyperskill.org/learn/daily/53348
*   Topic: Graph Theory (Eulerian Paths)
* */

#include <bits/stdc++.h>
using namespace std;

int main() {
  ifstream file("hyperskill-dataset-119101049.txt");
  map<string, int> bridgeCounts;

  string line;
  while (file >> line) {
    stringstream ss(line);
    string landMass1, landMass2;

    getline(ss, landMass1, ',');
    getline(ss, landMass2, ',');

    bridgeCounts[landMass1]++;
    bridgeCounts[landMass2]++;
  }
  file.close();

  int oddDegrees{};
  for (const pair<string, int>& entry : bridgeCounts) {
    if (entry.second % 2 == 1) {
      oddDegrees++;
    }
  }

  int ans{};
  if (oddDegrees > 2) {
    ans = oddDegrees / 2 - 1;
  }

  cout << ans;
  return 0;
}
