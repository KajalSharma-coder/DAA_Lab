#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Node {
    int worker;
    int cost;
    int bound;
    vector<int> assigned;
};

// Calculate lower bound
int calculateBound(vector<vector<int>>& cost, Node node, int n) {
    int bound = node.cost;

    for (int i = node.worker + 1; i < n; i++) {
        int minCost = 99999;

        for (int j = 0; j < n; j++) {
            bool used = false;

            for (int x : node.assigned) {
                if (x == j) {
                    used = true;
                    break;
                }
            }

            if (!used) {
                minCost = min(minCost, cost[i][j]);
            }
        }

        bound += minCost;
    }

    return bound;
}

struct Compare {
    bool operator()(Node a, Node b) {
        return a.bound > b.bound;
    }
};

void assignmentProblem(vector<vector<int>>& cost, int n) {

    priority_queue<Node, vector<Node>, Compare> pq;

    Node root;
    root.worker = -1;
    root.cost = 0;
    root.assigned = {};
    root.bound = calculateBound(cost, root, n);

    pq.push(root);

    int minCost = 99999;
    vector<int> bestAssignment;

    while (!pq.empty()) {

        Node current = pq.top();
        pq.pop();

        // If bound is greater than current best, ignore it
        if (current.bound >= minCost)
            continue;

        // All workers assigned
        if (current.worker == n - 1) {
            if (current.cost < minCost) {
                minCost = current.cost;
                bestAssignment = current.assigned;
            }
            continue;
        }

        int nextWorker = current.worker + 1;

        // Try assigning every available job
        for (int job = 0; job < n; job++) {

            bool used = false;

            for (int x : current.assigned) {
                if (x == job) {
                    used = true;
                    break;
                }
            }

            if (!used) {

                Node child;
                child.worker = nextWorker;
                child.cost = current.cost + cost[nextWorker][job];
                child.assigned = current.assigned;
                child.assigned.push_back(job);

                child.bound = calculateBound(cost, child, n);

                if (child.bound < minCost) {
                    pq.push(child);
                }
            }
        }
    }

    cout << "Minimum Assignment Cost = " << minCost << endl;

    cout << "Assignment:" << endl;

    for (int i = 0; i < n; i++) {
        cout << "Worker " << i + 1
             << " -> Job " << bestAssignment[i] + 1
             << " (Cost = " << cost[i][bestAssignment[i]] << ")" 
             << endl;
    }
}

int main() {

    int n;

    cout << "Enter number of workers/jobs: ";
    cin >> n;

    vector<vector<int>> cost(n, vector<int>(n));

    cout << "Enter cost matrix:" << endl;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> cost[i][j];
        }
    }

    assignmentProblem(cost, n);

    return 0;
}