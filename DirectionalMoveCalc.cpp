#include <iostream>
#include <math.h>
#include <cmath>

//Goal: Take input of goal angle, a goal direction angle and goal height and find if it is possible / how much to retract motors if it is possible
//The X axis for this code goes from the leg in line with the camera servo to the center of the robot (from a top down view)
double OneLegRetractAmount(double ForceNeededN, double LenLegSide, double SpringConst, double SpringLen, double wireLen) // Find amount to retract an individual leg based on required force
{
    double newLengthSpring = ForceNeededN/SpringConst;
    newLengthSpring = newLengthSpring + SpringLen;
    double HalfSpring = newLengthSpring/2;
    double tempVar = HalfSpring/LenLegSide;
    double AngC = acos(tempVar);
    AngC = AngC * 180/M_PI;
    double newLengthWire = sqrt((pow(LenLegSide, 2.0))-(pow(HalfSpring, 2.0)));
    return wireLen-newLengthWire;
}
double Forceneeded(double weight, double height, double angle,double g,double springk) // Find the force needed for an object of a set weight to reach a set height based on the angle above the x axis
{
    double angleRads = angle * M_PI / 180.0;
    double v = sqrt(2*g*height / (sin(angleRads) * sin(angleRads)));
    double x = sqrt((weight*v*v)/springk);
    double forcemax = springk*x;
    return forcemax;
}
double ForceneededXY(double force, double angle,int toReturn)// Split the force vector into its X and Y components (If toReturn = 1 returns x, if toReturn = 2 returns y)
{
    double angleRadians = angle * M_PI / 180.0;
    double Ycomponent = force * cos(angleRadians);
    double Xcomponent = force * sin(angleRadians);
    if (toReturn == 1)
        return Xcomponent;
    else if (toReturn == 2)
    {
        return Ycomponent;
    }
    else
        return 0;
}
int main()
{
    // --Main Variables--
    const double TotalWeight = 1.0; // kg
    const double SpringConst = 156; // N/m
    const double cRest = 77.66; // Degrees (angles at ends of wire)
    const double aRest = 102.34; // Degrees (angles at ends of spring) 
    const double wireRest = 9.078; // cm (wire length)
    const double springRest = 6.46; // cm (spring length)
    const double LegSideLen = 7.167; // cm
    const double g = 9.81; // m/s^2 (gravity)
    double GoalHeight = 0; // Meters
    double GoalDirAngle = 0; // Degrees
    double GoalAngle = 0; // Degrees
    double Forcetotal = 0; // N
    double ForceX = 0; // N
    double ForceY = 0; // N
    // --Main Variables End--
    std::cout << "\nEnter the goal height in meters: ";
    std::cin >> GoalHeight;
    std::cout << "\nEnter the goal directional angle: ";
    std::cin >> GoalDirAngle;
    std::cout << "\nEnter the goal XY (vertical) angle: ";
    std::cin >> GoalAngle;
    Forcetotal = Forceneeded(TotalWeight, GoalHeight, GoalAngle, g, SpringConst);
    ForceX = ForceneededXY(Forcetotal, GoalAngle, 1);
    ForceY = ForceneededXY(Forcetotal, GoalAngle, 2);
    std::cout << Forcetotal;

}
