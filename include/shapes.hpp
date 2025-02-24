#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <cmath>


/*-------------------Dot-class-------------------*/

struct Dot {
    double x;
    double y;

    Dot();

    friend std::istream& operator >> (std::istream& stream, Dot& obj);

    friend std::ostream& operator << (std::ostream& stream, Dot& obj);
};



/*-------------------Shape class-------------------*/
/*---------------------Abstract--------------------*/

class Shape {
protected:
    std::string name;
    std::vector<Dot> coordinates;
public:
    Shape();

    const std::string get_name() const;

    virtual double get_perimeter() const = 0;

    virtual void display() const = 0;

    virtual void display_with_perimeter() const = 0;

    virtual ~Shape();
};



/*-------------------Circle class-------------------*/

class Circle : public Shape {
    double radius;
public:
    Circle();

    double get_perimeter() const override;

    void display() const override;

    void display_with_perimeter() const override;

    friend std::istream& operator >> (std::istream& stream, Circle& obj);
};



/*-------------------Triangle class-------------------*/

class Triangle : public Shape {
public:
    Triangle();
    
    double get_perimeter() const override;

    void display() const override;

    void display_with_perimeter() const override;
    
    friend std::istream& operator >> (std::istream&, Triangle&);
};



/*-------------------Rectangle class-------------------*/

class Rectangle : public Shape {
public:
    Rectangle();

    double get_perimeter() const override;

    void display() const override;

    void display_with_perimeter() const override;

    friend std::istream& operator >> (std::istream&, Rectangle&);
};