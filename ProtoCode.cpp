#include <iostream>
using namespace std;

int main()
{
    // Hooke's law (F = -kx)
    const int k = 58.21; // (N/m)
    const int xi = 8.89; // (cm)
    const int A = 6.845; // (cm)
    int F = 0; // (N)
    int xf = 0;
    cout << "Enter the value for var xf: ";
    cin >> xf;
    F << (xf-xi);
    cout << F;
}