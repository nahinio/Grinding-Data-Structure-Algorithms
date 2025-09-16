/*
Given a sorted array of nums and an integer x, write a program to find the lower bound of x.

The lower bound algorithm finds the first and smallest index in a sorted array where the value at that index is greater than or equal to a given key i.e. x.
*/

#include<bits/stdc++.h>
using namespace std;

int lowerBound(vector<int> &v, int x){
    int low = 0, high = v.size() - 1;
    int ans = -1;

    while(low <= high){
        int mid = low + (high - low) / 2;

        if(v[mid] >= x){
            ans = mid;
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }

    return ans;
}

int main(){
    int n;
    cin >> n;

    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin>> temp;
        v.push_back(temp);
    }
    
    int x;
    cin >> x;

    cout << lowerBound(v, x) << endl;

    return 0;
}