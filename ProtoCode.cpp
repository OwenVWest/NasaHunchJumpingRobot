#include <iostream>
#include <math.h>
#include <cmath>
using namespace std;
double roundToTwoDecimalPlaces(double value) {
    return std::round(value * 100.0f) / 100.0f;
}
double find_spring_length(double y_len, double A_len)
{
    double hlf_y_len = y_len/2.0;
    double hlf_x_len = sqrt((pow(A_len, 2.0))-(pow(hlf_y_len, 2.0)));
    return (hlf_x_len*2.0);
}

double find_angle_a(double y_len, double A_len)
{
    double hlf_y_len = y_len/2;
    double temp = hlf_y_len/A_len;
    double angle_a = acos(temp);
    angle_a = angle_a * 180.0/M_PI;
    return angle_a*2;
}

double find_angle_c(double angle_a)
{   
    double half_a = angle_a/2;
    double temp_total = 90.0 + half_a;
    double angle_c = 180.0 - temp_total;
    return angle_c*2;
}

double find_spring_force(double spring_len, double spring_const, double org_spring_len)
{
    double spring_diff_m = (spring_len - org_spring_len) / 100.0; // cm -> m
    double force = spring_const * spring_diff_m; // F = k * Δx (N)
    return force;
}

int main()
{
    // Hooke's law (F = -kx)
    const double k = 58; // (N/m)
    const double A = 7.167; // (cm)
    const double c_rest = 77.66; // (angle)
    const double a_rest = 102.34; // (angle) 
    const double y_rest = 9.078; // (cm) // wire
    const double x_rest = 6.46; // (cm) // spring
    double F = 0; // (N)
    double x = x_rest;
    double y = y_rest;
    double c = c_rest;
    double a = a_rest;
    double temp_in = 0;
    cout << "Enter the ammount to shorten wire by: ";
    cin >> temp_in;
    if (temp_in > 12.188 or temp_in < 0) {
        cout << "Error, Input value is outside 0-12.188cm range";
        return 1;
    } else {
        y = y - temp_in;
        cout << "New wire length is: ";
        cout << y;
        x = find_spring_length(y,A);
        a = find_angle_a(y,A);
        c = find_angle_c(a);
        F = find_spring_force(x,k,x_rest);
        cout << "\n";
        cout << "New length of spring: ";
        cout << roundToTwoDecimalPlaces(x);
        cout << " cm\nNew angle of a is: ";
        cout << roundToTwoDecimalPlaces(a);
        cout << " Degrees\nNew angle of c is: ";
        cout << roundToTwoDecimalPlaces(c);
        cout << " Degrees\nForce output by spring on release will be: ";
        cout << roundToTwoDecimalPlaces(F);
        cout << " Newtons \n";
        
    }
}



