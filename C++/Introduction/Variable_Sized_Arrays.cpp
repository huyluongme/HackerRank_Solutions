#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n, q;
    vector<vector<int>> arr;
    cin >> n >> q;
    arr.resize(n);
    for(int i = 0; i < n; i++){
        int k, tmp;
        cin >> k;
        for(int j = 0; j < k; j++){
            cin >> tmp;
            arr[i].push_back(tmp);
        }
    }
    for(int i = 0; i < q; i++){
        int j, k;
        cin >> j >> k;
        cout << arr[j][k] << endl;
    }
    return 0;
}