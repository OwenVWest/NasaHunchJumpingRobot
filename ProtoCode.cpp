#include <iostream>
using namespace std;

int main()
{
    // Hooke's law (F = -kx)
    // const float k = 58.21; // (N/m)
    // const float xi = 8.89; // (cm)
    const float A = 6.845; // (cm)
    const float c_rest = 140; // (angle)
    const float a_rest = 40; // (angle) 
    const float y_rest = 12.188; // (cm)
    const float x_rest = 4.436; // (cm)
    float F = 0; // (N)
    // float xf = 0;
    float x = x_rest;
    float y = y_rest;
    float c = c_rest;
    float a = a_rest;
    float temp_in = 0;
    cout << "Enter the ammount to shorten wire by using stepper motor: ";
    cin >> temp_in;
    if (temp_in > 12.188 or temp_in < 0) {
        cout << "Error, Input value is outside 0-12.188cm range";
        return 1;
    } else {
        y = y - temp_in;
        cout << "New wire length is ";
        cout << y;

    }

}

int find_angles()
{

}
int find_spring_length()
{

}

