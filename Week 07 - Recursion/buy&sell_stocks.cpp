#include <bits/stdc++.h>
using namespace std;

void maxProfitFinder(vector<int>& prices, int i, int& minPrice, int& maxProfit) {
    // base
    if (i == prices.size()) return;
    // sol for one case
    if (prices[i] < minPrice) minPrice = prices[i];
    int todaysProfit = prices[i] - minPrice;
    if (todaysProfit > maxProfit) maxProfit = todaysProfit;

    //Recursive call
    maxProfitFinder(prices, i+1, minPrice, maxProfit);
}

int maxProfit(vector<int>& prices) {
    int minPrice = INT_MAX;
    int maxProfit = INT_MIN;
    maxProfitFinder(prices, 0, minPrice, maxProfit);
    return maxProfit;
}

int main() {
    return 0;
}
