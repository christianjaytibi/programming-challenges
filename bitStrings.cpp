/*
    Platform: CSES
    Problem: Bit Strings
    Problem link: https://cses.fi/problemset/task/1617/
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;

int main() {
  ll n;
  cin >> n;
  ll ans = 2;

  for (ll i = 1; i < n; ++i) {
    ans = (ans * 2) % MOD;
  }
  cout << ans;
  return 0;
}
