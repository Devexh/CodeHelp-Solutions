#include <bits/stdc++.h>
using namespace std;

//TODO: revise this concept

bool isPossibleSolution(int A[], int n, int m, int sol) {
    int pageSum = 0;
    int c = 1;
    for (int i = 0; i<n; i++) {
        if (A[i] > sol) {
            return false;
        }
        if (pageSum + A[i] > sol) {
            c++;
            pageSum = A[i];
            if (c>m) {
                return false;
            }
        }
        else {
            pageSum += A[i];
        }
    }
    return true;
}

int findPages(int A[], int n, int m) {
    if (m>n) return -1;

    int start = 0;
    int end = accumulate(A, A+n, 0); //* C++ STL accumulate for sum of array (start address, end address, initial sum)
    int ans = -1;

    while (start <= end) {
        int mid = (start+end) >> 1; //? (start+end) / 2
        if (isPossibleSolution(A, n, m, mid)) {
            ans = mid;
            end = mid - 1;
        }
        else {
            start = mid + 1;
        }
    }
    return ans;
}

int main() {
    return 0;
}