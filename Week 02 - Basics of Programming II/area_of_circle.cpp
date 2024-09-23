#include <bits/stdc++.h>
using namespace std;

float circleArea(float radius) {
    float area = 3.14 *radius*radius;
    return area;
}

int main() {
    float radius;
    cin >> radius;
    float area = circleArea(radius);
    cout << "Area of circle is: " << area << endl;
    return 0;
}