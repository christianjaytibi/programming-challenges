/*
*   Problem: You Can (not) Escape
*   Problem Link: https://hyperskill.org/learn/daily/53143
* */

#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

struct Node {
  int x;
  int y;

  Node() : x(0), y(0) {}
  Node(int x, int y) : x(x), y(y) {}
};

/**
 * Checks if a node candidate is within the range of the matrix.
 */
bool isWithinRange(Node& node, int numRows, int numCols) {
  return node.x >= 0 && node.x < numCols && node.y >= 0 && node.y < numRows;
}

/**
 * Reconstruct the shortest path and the directions from source to target
 */
string reconstructPath(map<pii, pii>& parent, Node& source, Node& target) {
  string path{};

  pii childNode = {target.x, target.y};
  while (parent.count(childNode)) {
    pii parentNode = parent.at(childNode);

    if (parentNode.first < childNode.first) {
      path += "R";
    } else if (parentNode.first > childNode.first) {
      path += "L";
    } else if (parentNode.second < childNode.second) {
      path += "D";
    } else if (parentNode.second > childNode.second) {
      path += "U";
    }

    childNode = parentNode;
  }

  reverse(path.begin(), path.end());
  return path;
}

/**
 * Implements Breadth-First Search Algorithm
 */
void bfs(vector<vector<char>>& matrix, Node& source, Node& target) {
  int numRows = matrix.size();
  int numCols = matrix[0].size();

  deque<Node> q{};
  vector<vector<bool>> visited(numRows, vector<bool>(numCols, false));
  map<pii, pii> parent{};

  visited[source.y][source.x] = true;
  q.push_back(source);

  int dx[] = {0, 0, -1, 1};
  int dy[] = {-1, 1, 0, 0};
  int numOfAllDirections = 4;

  while (!q.empty()) {
    Node node = q.front();
    q.pop_front();

    if (node.x == target.x && node.y == target.y) {
      break;
    }

    for (int i = 0; i < numOfAllDirections; ++i) {
      Node newNode(node.x + dx[i], node.y + dy[i]);

      if (isWithinRange(newNode, numRows, numCols) &&
          matrix[newNode.y][newNode.x] != '#' &&
          !visited[newNode.y][newNode.x]) {
        parent[{newNode.x, newNode.y}] = {node.x, node.y};
        visited[newNode.y][newNode.x] = true;
        q.push_back(newNode);
      }
    }
  }

  cout << reconstructPath(parent, source, target);
}

int main() {
  ifstream file("hyperskill-dataset-117477307.txt");
  string str{};

  vector<vector<char>> mapOfMansion{};

  Node source;
  Node target;

  for (int i = 0; file >> str; ++i) {
    for (int j = 0; j < str.length(); ++j) {
      if (str[j] == 'P') {
        source.x = j;
        source.y = i;
      } else if (str[j] == 'G') {
        target.x = j;
        target.y = i;
      }
    }

    vector<char> v(str.begin(), str.end());
    mapOfMansion.push_back(v);
  }

  bfs(mapOfMansion, source, target);

  return 0;
}
