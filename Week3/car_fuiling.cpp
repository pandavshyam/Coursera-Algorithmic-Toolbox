#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;
using std::max;

int compute_min_refills(int dist, int tank, vector<int> & stops) {
    // write your code here

    int currentRiffil = 0,lastRefill,numRifill = 0;
    while (currentRiffil <= stops.size()){
        lastRefill = currentRiffil;
        while ( (currentRiffil <= stops.size()) && ((stops.at(currentRiffil+1) - stops.at(currentRiffil)) <= tank))
        {
            currentRiffil = currentRiffil + 1;
            //cout << currentRiffil << stops[currentRiffil] << "\t";
        }
        if (currentRiffil == lastRefill){
            return -1;
        }
        if (currentRiffil <= stops.size()){
            numRifill += 1;
        }
    }
    return numRifill;
}


int main() {
    int d = 0;
    cin >> d;
    int m = 0;
    cin >> m;
    int n = 0;
    cin >> n;

    vector<int> stops(n);
    cout << stops.at(0) << std::endl;
    for (size_t i = 0; i < n; ++i)
        cin >> stops.at(i);
    
    cout << compute_min_refills(d, m, stops) << "\n";

    return 0;
}