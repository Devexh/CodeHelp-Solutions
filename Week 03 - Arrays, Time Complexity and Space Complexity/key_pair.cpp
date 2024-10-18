#include <bits/stdc++.h>
using namespace std;

bool twoSum(int arr[], int n, int x) {
    for (int i = 0; i < n; i++){
        for (int j = i + 1; j < n; j++) {
            if (arr[i] + arr[j] == x){
                return true;
        }
    }
    return false;
}}

bool twoSum2PointerApproach(int arr[], int n, int x) { //O(n)
    int l = 0;
    int h = n-1;
    while (l < h) {
        int csum = arr[l] + arr[h];
        if (csum == x) return true;
        else if (csum > x) h--; //current pair is too large therefore as the array is SORTED therefore decrement of h makes more sense
        else if (csum < x) l++; //currentpair is small therefore as the array is SORTED therefore increment of l makes more sense
    }
    return false;
}

bool hasArrayTwoCandidates(int arr[], int n, int x) {
    sort(arr, arr + n); // O(nlogn)
    int ans = twoSum(arr, n, x);
    return ans;
}