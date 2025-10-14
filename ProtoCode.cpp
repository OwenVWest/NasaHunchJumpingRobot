#include <iostream>
#include <math.h>
#include <cmath>
using namespace std;

float find_spring_length(float y_len, float A_len)
{
    float hlf_y_len = y_len/2.0;
    float hlf_x_len = sqrt((pow(A_len, 2.0))-(pow(hlf_y_len, 2.0)));
    return (hlf_x_len*2.0);
}

float find_angle_a(float y_len, float A_len)
{
    float hlf_y_len = y_len/2;
    float temp = hlf_y_len/A_len;
    float angle_a = acos(temp);
    angle_a = angle_a * 180.0/M_PI;
    return angle_a*2;
}

float find_angle_c(float angle_a)
{   
    float half_a = angle_a/2;
    float temp_total = 90.0 + half_a;
    float angle_c = 180.0 - temp_total;
    return angle_c*2;
}

float find_spring_force(float spring_len, float spring_const, float org_spring_len)
{
    cout << spring_len - org_spring_len;
    float spring_diff = spring_len - org_spring_len;
    float force = spring_const*spring_diff;
    return force;
}

int main()
{
    // Hooke's law (F = -kx)
    const float k = 58.21; // (N/m)
    const float A = 6.845; // (cm)
    const float c_rest = 140; // (angle)
    const float a_rest = 40; // (angle) 
    const float y_rest = 12.188; // (cm)
    const float x_rest = 6.234; // (cm)
    float F = 0; // (N)
    float x = x_rest;
    float y = y_rest;
    float c = c_rest;
    float a = a_rest;
    float temp_in = 0;
    cout << "Enter the ammount to shorten wire by: ";
    cin >> temp_in;
    if (temp_in > 12.188 or temp_in < 0) {
        cout << "Error, Input value is outside 0-12.188cm range";
        return 1;
    } else {
        y = y - temp_in;
        cout << "New wire length is: ";
        cout << y;
        cout << "\n";
        x = find_spring_length(y,A);
        a = find_angle_a(y,A);
        c = find_angle_c(a);
        F = find_spring_force(x,k,x_rest);
        cout << "New length of spring: ";
        cout << x;
        cout << " cm\nNew angle of a is: ";
        cout << a;
        cout << " Degrees\nNew angle of c is: ";
        cout << c;
        cout << " Degrees\nForce output by spring on release will be: ";
        cout << F;
        cout << " Newtons \n";
        
    }
}



