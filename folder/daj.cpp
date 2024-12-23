#include <iostream>
#include <vector>
#include <queue>
#include <limits> 

using namespace std;

const int INF = numeric_limits<int>::max();


// pair<int, int> :: {인접 노드, 가중치}
vector<vector<pair<int, int>>> graph;


vector<int> dijkstra(int startNode) {
  int n = graph.size();

  vector<int> dist(n, INF);

  dist[startNode] = 0;

  // PQ
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
  pq.push({0, startNode});

  while (!pq.empty()) {

    int currentDist = pq.top().first;
    int currentNode = pq.top().second;
    pq.pop();

    // pass 
    if (currentDist > dist[currentNode]) {
      continue;
    }

    // curf
    for (auto neighbor : graph[currentNode]) {
      int nextNode = neighbor.first;
      int weight = neighbor.second;
      int newDist = currentDist + weight;

      // dist
      if (newDist < dist[nextNode]) {
        dist[nextNode] = newDist;
        pq.push({newDist, nextNode});
      }
    }
  }

  return dist;
}

int main() {

  graph.resize(6);
  graph[0] = {{1, 2}, {3, 5}};
  graph[1] = {{0, 2}, {2, 3}, {3, 1}};
  graph[2] = {{1, 3}, {3, 2}, {4, 5}};
  graph[3] = {{0, 5}, {1, 1}, {2, 2}, {4, 1}, {5, 2}};
  graph[4] = {{2, 5}, {3, 1}, {5, 1}};
  graph[5] = {{3, 2}, {4, 1}};


  vector<int> distances = dijkstra(0);


  for (int i = 0; i < distances.size(); ++i) {
    cout << "노드 0에서 노드 " << i << "까지의 최단 거리: " << distances[i] << endl;
  }

  return 0;
}
