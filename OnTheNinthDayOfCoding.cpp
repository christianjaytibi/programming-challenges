/*
*   Problem: On The Ninth Day Of Coding...
*   Problem Link: https://hyperskill.org/learn/daily/53350
*   Type: Graph Theory (Dijkstra's Algorithm)
*
*   /\_/\
*  ( o.o )
*   > ^ <
*
* */

#include <bits/stdc++.h>
using namespace std;

const int N = 20;
const int M = 20;

struct Node {
  int value, r, c;

  Node(int value, int r, int c) : value(value), r(r), c(c) {};

  bool operator<(const Node& that) const { return this->value > that.value; }
  bool operator==(const Node& that) const {
    return this->r == that.r && this->c == that.c;
  }
};

bool isValid(int, int);
int dijkstra(vector<vector<int>>&, Node&, Node&);

int main() {
  vector<vector<int>> graph(N, vector<int>(M));
  ifstream file("hyperskill-dataset-119146086.txt");

  string line, temp;
  for (int i = 0; file >> line; ++i) {
    stringstream ss(line);
    for (int j = 0; getline(ss, temp, ','); ++j) {
      graph[i][j] = stoi(temp);
    }
  }
  file.close();

  Node source(0, 0, 0);
  Node target(graph[N - 1][M - 1], N - 1, M - 1);

  int livesLost = dijkstra(graph, source, target);
  cout << livesLost;
  return 0;
}

bool isValid(int r, int c) {
  return (r >= 0) && (c >= 0) && (r < N) && (c < M);
}

int dijkstra(vector<vector<int>>& graph, Node& root, Node& target) {
  int distances[N][M];
  fill(&distances[0][0], &distances[0][0] + (N * M), INT_MAX);

  int dx[] = {0, 0, -1, 1};
  int dy[] = {-1, 1, 0, 0};

  priority_queue<Node> pq;
  pq.push(root);
  distances[root.r][root.c] = 0;

  while (!pq.empty()) {
    Node node = pq.top();
    pq.pop();

    if (node == target) {
      break;
    }

    for (int i = 0; i < 4; ++i) {
      int r = node.r + dx[i];
      int c = node.c + dy[i];

      if (!isValid(r, c)) {
        continue;
      }

      Node neighbor(graph[r][c], r, c);
      int newDistance = neighbor.value + node.value;

      if (newDistance < distances[r][c]) {
        distances[r][c] = newDistance;
        neighbor.value = newDistance;
        pq.push(neighbor);
      }
    }
  }

  return distances[target.r][target.c];
}
