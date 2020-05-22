#include <iostream>
using namespace std;

void fibbonacchi(int n){
    int arr[n];
    arr[0] = 0;
    arr[1] = 1;
    for (int i = 2; i <= n; i++){
        arr[i] = arr[i-1] + arr[i-2];
    }
    for (int j = 0; j < sizeof(arr); j++){
        cout << arr[j] << ' ';
    }
}

int main(){
    int n;
    cout << "Enter number : \n";
    cin >> n;
    fibbonacchi(n);
    return 0;
}