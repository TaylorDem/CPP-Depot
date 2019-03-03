//C++ example code of basic things i learned.
#include<iostream>

//using namespace std;   //heard this was bad coding practice.
double findAreaCir(double);
double findCircumference(double);
void chooseCircle(void);
void chooseRectangle(void);

struct Shape{
    double area;  
    //in the future once I have more shapes I could make this virtual and define the area within each shape to be calculated upon creation.
};

struct Circle : Shape{
    double radius;
    double circumference;
};

struct Rectangle : Shape{
    double width;
    double height;
};

int main(void)
{
    while (true){
        std::cout << std::endl << "I've got two different shapes to choose from. Do you want a Circle or a Rectangle? (C/R)   Use input 'Q' to quit" << std::endl;
        char choice;
        std::cin >> choice;
        //first check bad input.
        if  (   ((choice != 'R') && (choice != 'r'))  &&  
                ((choice != 'C') && (choice != 'c'))  && 
                ((choice != 'Q') && (choice != 'q')) 
            )
        {
            std::cout << "\nbad input\n";
        }

        //handle choices. probs could use a switch or some kind of better system if I have many more options later.
        if (choice == 'R' || choice == 'r') chooseRectangle();
        if (choice == 'C' || choice == 'c') chooseCircle();

        //quit command
        if (choice == 'Q' || choice == 'q') return 0;
    }
}

double findAreaCir(double r)           //PI*r_squared
{
    return (r*r)*3.14;    
}

double findCircumference(double r)    //2*r*PI
{
    return (r*2)*3.14;
}

void chooseCircle(void)
{
    std::cout << std::endl << "Can you enter the radius? I'll give you the circumference and area!\n";
    Circle C1;
    std::cin >> C1.radius;
    C1.area = findAreaCir(C1.radius);
    C1.circumference = findCircumference(C1.radius);
    std::cout << "Ok," << std::endl << "Area: " << C1.area << std::endl; 
    std::cout << "Circumference: " << C1.circumference << "\n\n";
    return;
}

void chooseRectangle(void)  
{
    std::cout << std::endl << "Can you enter the width first?\n";
    Rectangle R1;
    std::cin >> R1.width;
    std::cout << std::endl << "Alright now enter the height.\n";
    std::cin >> R1.height;
    R1.area = R1.width * R1.height;
    std::cout << "Ok," << std::endl << "Area: " << R1.area << std::endl; 
    return;
}