/*
*   Problem: On The Sixth Day Of Coding...
*   Problem Link: https://hyperskill.org/learn/daily/53347
*   Topic: Graph Theory (Breadth-First Search)
* */

#include <bits/stdc++.h>
using namespace std;

struct Node {
  string name;
  vector<Node*> neighbors{};

  Node(const string& name) : name(move(name)) {};
};

class Graph {
 public:
  Node* root;
  map<string, unique_ptr<Node>> nodes{};

  Node* addNode(string& name) {
    nodes.emplace(name, make_unique<Node>(name));
    return nodes[name].get();
  }

  void addEdge(Node* a, Node* b) {
    a->neighbors.push_back(b);
    b->neighbors.push_back(a);
  }
};

Node* findFurthest(Graph&);
void populate(Graph&, const string&);

int main() {
  string dataset = "hyperskill-dataset-119049466.txt";
  Graph graph;
  populate(graph, dataset);
  Node* furthestNode = findFurthest(graph);

  cout << furthestNode->name;
  return 0;
}

/* Find the node furthest from the root using BFS */
Node* findFurthest(Graph& graph) {
  deque<Node*> q{};
  map<string, int> visited;
  int degreeOfSeparation = 0;

  q.push_back(graph.root);
  visited[graph.root->name] = degreeOfSeparation;

  while (!q.empty()) {
    Node* node = q.front();
    q.pop_front();

    for (Node* neighbor : node->neighbors) {
      int distance = visited[node->name] + 1;
      auto res = visited.emplace(neighbor->name, distance);
      if (res.second) {
        q.push_back(neighbor);
      }
    }
    degreeOfSeparation++;
  }

  auto cmp = [](const pair<string, int>& a, const pair<string, int>& b) {
    return a.second > b.second;
  };
  auto furthestEntry = min_element(visited.begin(), visited.end(), cmp);

  return graph.nodes[furthestEntry->first].get();
}

/* Parse input from file, create and add nodes to graph */
void populate(Graph& graph, const string& fileName) {
  ifstream file(fileName);
  string rootName;
  file >> rootName;

  graph.root = graph.addNode(rootName);

  string line;
  while (file >> line) {
    stringstream ss(line);
    string a, b;

    getline(ss, a, ',');
    getline(ss, b, ',');

    Node* nodeA = graph.addNode(a);
    Node* nodeB = graph.addNode(b);
    graph.addEdge(nodeA, nodeB);
  }

  file.close();
}
