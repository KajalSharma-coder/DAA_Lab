#include <iostream>
#include <algorithm>
using namespace std;

struct Item {
    int weight;
    int profit;
    double ratio;
};

bool compare(Item a, Item b) {
    return a.ratio > b.ratio;
}

int main() {
    int n, capacity;

    cout << "Enter number of items: ";
    cin >> n;

    Item item[n];

    cout << "Enter weight and profit of each item:\n";

    for (int i = 0; i < n; i++) {
        cin >> item[i].weight >> item[i].profit;
        item[i].ratio = (double)item[i].profit / item[i].weight;
    }

    cout << "Enter knapsack capacity: ";
    cin >> capacity;

    // Sort according to profit/weight ratio
    sort(item, item + n, compare);

    double totalProfit = 0;

    for (int i = 0; i < n; i++) {

        if (capacity >= item[i].weight) {
            // Take complete item
            capacity -= item[i].weight;
            totalProfit += item[i].profit;
        }
        else {
            // Take fraction of item
            totalProfit += item[i].ratio * capacity;
            capacity = 0;
            break;
        }
    }

    cout << "Maximum Profit = " << totalProfit << endl;

    return 0;
}