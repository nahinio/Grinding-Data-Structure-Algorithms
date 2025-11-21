#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    for (int tc = 1; tc <= t; tc++) {
        int n;
        cin >> n;
        
        vector<long long> sticks(n);
        for (int i = 0; i < n; i++) {
            cin >> sticks[i];
        }
        
        sort(sticks.begin(), sticks.end());
        
        int count = 0;
        for (int i = 0; i < n - 2; i++) {
            for (int j = i + 1; j < n - 1; j++) {
                long long sum = sticks[i] + sticks[j];
                for (int k = j + 1; k < n; k++) {
                    if (sticks[k] < sum) {
                        count++;
                    } else {
                        break;
                    }
                }
            }
        }
        
        cout << "Case " << tc << ": " << count << endl;
    }
    return 0;
}