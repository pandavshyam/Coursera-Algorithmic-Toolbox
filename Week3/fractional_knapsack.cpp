#include <iostream>
#include <vector>

using std::vector;

double get_optimal_value(int capacity, vector<int> weights, vector<int> values) {
    double value = 0.0;

    for (int i = 0; i < weights.size(); i++) {
        if (capacity == 0) return value;
        int max_i = 0;
        double max = 0;

        for (int i = 0; i < weights.size(); i++) {
            if (weights[i] != 0 && (double) values[i] / weights[i] > max) {
                max = (double) values[i] / weights[i];
                max_i = i;
            }
        }
        int a = std::min(capacity, weights[max_i]);
        value += a * (double) values[max_i] / weights[max_i];
        weights[max_i] -= a;
        capacity -= a;
    }

    return value;
}

int main() {
    int n;
    int capacity;
    std::cin >> n >> capacity;
    vector<int> values(n);
    vector<int> weights(n);
    for (int i = 0; i < n; i++) {
        std::cin >> values[i] >> weights[i];
    }

    double optimal_value = get_optimal_value(capacity, weights, values);

    std::cout.precision(10);
    std::cout << optimal_value << std::endl;
    return 0;
}