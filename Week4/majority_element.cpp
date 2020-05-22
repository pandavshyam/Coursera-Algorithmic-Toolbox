#include <algorithm>
#include <iostream>
#include <vector>
#include <bits/stdc++.h> 

using std::vector;
using namespace std;

int get_majority_element(vector<int> &a, int left, int right) {
    if (left == right){
        return a[left];
    }
    map<int, int> m; 
    for(int i = 0; i < right; i++) 
        m[a[i]]++; 
    int count = 0; 
    for(auto i : m) 
    { 
        if(i.second > right / 2) 
        { 
            count =1; 
            return 1;
        } 
    }  
    // for (size_t i = 0; i < a.size(); ++i){
    //     std::cout << a[i] << std::endl;
    // }
    // for (size_t i = 0; i < a.size(); ++i){
    //     std::cout << arr[i] << std::endl;
    // }

    // for (int j = 0; j < a.size(); j++){
    //     if (arr[j] > n/2){
    //         std::cout << arr[j];
    //         return 1;
    //     }
    // }
    return -1;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  std::cout << (get_majority_element(a, 0, a.size()) != -1) << '\n';
}
