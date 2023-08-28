#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, Z,temp;
        cin >> N >> Z; // Missing input for N and Z
        
        priority_queue<int> arr; // Specify the type for the queue
        for (int i = 0; i < N; i++) {
            cin >> temp;
            arr.push(temp);
        }
        
        int heap = 0;
        while (arr.top()!=0 && Z > 0) { // Check if the queue is empty
            heap++;
            temp = arr.top();
            Z -= temp;
            arr.pop();
            arr.push(temp / 2);
        }
        
        if (Z > 0) {
            cout << "Evacuate" << endl; // Fixed the typo
        } else {
            cout << heap << endl;
        }
    }
    return 0;
}
