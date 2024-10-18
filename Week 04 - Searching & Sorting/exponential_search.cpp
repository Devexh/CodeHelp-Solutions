#include <bits/stdc++.h>
using namespace std;
//TODO: doubling search, galloping search, strazik search
//? application: Search in infinite arrays(unbound arrays), better than bs if x is in beginning

//TODO: for infinite array
// int i = 0;
// int j = 1;
// while(arr[j]< x) {
//     i = j;
//     j = j*2;
// }
// start = i; end = j;
// then apply binary search

int bs(int a[], int start, int end, int x) {
    while(start <= end) {
        int mid = (start+end)/2;
        if (a[mid] == x) {
            return mid;
        }
        else if (x > a[mid]) {
            start = mid+1;
        }
        else {
            end = mid-1;
        }
    }
    return -1;
}

int expSearch(int a[], int n, int x) { //? O(log(2^(logm-1)))
    if (a[0] == x) return 0; //* base condition as we will start the loop from 1

    int i = 1;
    while (i<n && a[i] <= x) {
        i = i*2; 
    }
    return bs(a, i/2, min(i, n-1), x); 
}

int main() {
    int a[] = {3,4,5,6,11,13,14,15,56,70};
    int n = sizeof(a)/sizeof(int);
    int x = 56;
    int ans = expSearch(a, n, x);
    cout << ans << endl;
    return 0;
}