#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    while (cin >> n) {
        vector<int> prices(n);
        for (int i = 0; i < n; i++) {
            cin >> prices[i];
        }
        
        int m;
        cin >> m;
        
        sort(prices.begin(), prices.end());
        
        int left = 0, right = n - 1;
        int bestI = 0, bestJ = 0;
        int minDiff = 1000001;
        
        while (left < right) {
            int sum = prices[left] + prices[right];
            
            if (sum == m) {
                int diff = prices[right] - prices[left];
                if (diff < minDiff) {
                    minDiff = diff;
                    bestI = prices[left];
                    bestJ = prices[right];
                }
                left++;
                right--;
            } else if (sum < m) {
                left++;
            } else {
                right--;
            }
        }
        
        cout << "Peter should buy books whose prices are " << bestI << " and " << bestJ << "." << endl;
        cout << endl;
    }
    
    return 0;
}