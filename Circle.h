#include <iostream>
#include "Shape.h"
class Circle : public Shape{

	private:
		Point2D center;
		double radius;
	public:
		Circle(): Shape(){
			center.x = 0.0;
			center.y = 0.0;
			radius = 1;
		}

		Circle(std::string color, Point2D center, double radius):Shape(color){				
			this->center = center;
			this->radius = radius;
		
		}
		Circle(Point2D center, double radius):Shape(){
		
			this->center = center;
			this -> radius = radius;
		
		}
		Point2D get_center() const{
			return center;
		
		}
		void set_center(Point2D p){
			center = p;
		
		}

		double get_radius() const{
		
			return radius;
		}
		void set_radius(double r){
		
			radius = r;
		}
		friend std::ostream& operator<<(std::ostream &out, const Circle &c){
		
			out<<"Ciruclo de color = "<< c.getcolor()<<" Punto:"<< c.center <<" de radio: " <<c.radius << std::endl;
			return out;
		
		}

		//Metodos heredados
		
		 double area()const override {
		
			return 3.141592 * pow(radius,2);
		
		}
		 double perimeter() const override{
		
			return 2*3.141592*radius;
		
		}
		 void translate(double incX, double incY)override {
		
			center.x += incX;
			center.y += incY;	
		
		}
		 void print()override{
			std::cout<<"Ciruclo de color = "<< Shape::getcolor()<<" Punto:"<< center <<" de radio: " <<radius << std::endl;
		
		}
};
