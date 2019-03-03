//C++ example code of basic things i learned.


#include<iostream>

//using namespace std;
double findArea(double);
double findCircumference(double);

struct shape{
    double area;
};

struct circle : shape{
    double radius;
    double circumference;
};

int main(void)
{
    cout << "Lets start with a circle! Can you enter the radius? I'll give you the circumference and area!" << endl;
    circle C1;
    cin >> C1.radius;
    C1.area = findAreaCir(C1.radius);
    C1.circumference = findCircumference(C1.radius);
    cout << "Ok," << endl << "Area: " << C1.area << endl;
    cout << "Circumference: " << C1.circumference << endl << endl;
    return 0;
}

double findAreaCir(double r)           //PI*r_squared
{
    return (r*r)*3.14;    
}

double findCircumference(double r)    //2*r*PI
{
    return (r*2)*3.14;
}