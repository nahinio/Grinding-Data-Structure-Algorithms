#include <bits/stdc++.h>
using namespace std;

int sum(vector<int> &v, int n){
    if(n == 0) return 0;

    return v[n - 1] + sum(v, n - 1);

}

int main() {
    int t;
    cin >> t;

    for(int j = 1; j <= t; j++){
        int n;
        cin >> n; 

        vector<int> v;

        for (int i = 0; i < n; i++)
        {
            int temp;
            cin >> temp;
            v.push_back(temp);
        }

        cout << "Case " << j << ": " << sum(v, v.size()) << endl;
        
    }

    return 0;
}