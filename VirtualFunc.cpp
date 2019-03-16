//Virtual Function example

/* 
    Virtualization is making the base class have one definition of functions 
    and also having the same function perform a new task when derived.

    Polymorphism is being able to determine which is needed during runtime 
    using pointers instead of calling the objects directly
*/

#include <iostream>

class Shape
{
    public:
    virtual void print()
    {
        std::cout<<std::endl<< "Base Shape:";
    }
    void calcArea()
    {
        std::cout<<std::endl<< "How???" <<std::endl;
    }
};

class Square: public Shape
{
    public:
    void print()
    {
        std::cout<<std::endl<< "Square:";
    }
    void calcArea()
    {
        std::cout<<std::endl<< "Length^2" <<std::endl;
    }
};

int main(void)
{
    std::cout<<std::endl<< "Virtual function demonstration" << std::endl;
    Shape unknown;
    Square S;

    //same functions, different results
    unknown.print();
    unknown.calcArea();
    S.print();
    S.calcArea();

    //now the polymorphism bit:
    Shape *Base;
    Base = &S; //assigned it to point to derived class address.

    std::cout<< std::endl << "Now with a base pointer assigned to derived, however area function isn't virtual" <<std::endl;
    Base->print();
    Base->calcArea();

    return 0;
}