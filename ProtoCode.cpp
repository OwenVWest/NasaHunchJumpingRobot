#include <iostream>
using namespace std;

int main()
{
    // Hooke's law (F = -kx)
    const float k = 58.21; // (N/m)
    const float xi = 8.89; // (cm)
    const float A = 6.845; // (cm)
    
    float F = 0; // (N)
    float xf = 0;
    cout << "Enter the value for var xf: ";
    cin >> xf;
    F = xf-xi;
    cout << F;

}