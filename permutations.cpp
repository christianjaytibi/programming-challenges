/*  
    Platform: CSES
    Problem: Permutations
    Problem Link: https://cses.fi/problemset/task/1070/
*/

#include <bits/stdc++.h>
using namespace std;

void solve(unsigned int &n) {
  if (n == 1) {
    cout << n;
    return;
  }

  if (n <= 3) {
    cout << "NO SOLUTION";
    return;
  }

  for (int i = 2; i <= n; i += 2) 
    cout << i << " ";
  
  for (int i = 1; i <= n; i += 2) 
    cout << i << " ";
}

int main() {
  unsigned int n{};
  cin >> n;
  solve(n);

  return 0;
}
