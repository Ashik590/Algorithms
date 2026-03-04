#include <bits/stdc++.h>
using namespace std;
#define optimize()              \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
#define nl "\n"
#define ll long long

ll maxSum(vector<int> &arr){
    ll currentSum = 0;
    ll maxSum = -INT_MAX;

    for (auto e: arr)
    {
        currentSum += e;

        maxSum = max(maxSum, currentSum);

        if(currentSum < 0) 
        currentSum = 0;
    }

    return maxSum;
}

int main(){
    optimize();
    
    vector<int> arr = {-2, -1, -3, -5};

    cout << maxSum(arr) << nl;
    
    return 0;
}