#include <iostream>
using namespace std;

long long countDigits(long long n) {
    long long cnt = 0;
    while (n > 0) {
        cnt++;
        n /= 10;
    }
    return cnt;
}

int main() {
    long long a, b, x;
    cin >> a >> b >> x;
    
    long long answer = 0;
    long long left = 1, right = 1000000000;
    
    while (left <= right) {
        long long mid = left + (right - left) / 2;
        long long cost = a * mid + b * countDigits(mid);
        
        if (cost <= x) {
            answer = max(answer, mid);
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    
    cout << answer << endl;
    
    return 0;
}