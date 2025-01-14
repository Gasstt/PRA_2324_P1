#ifndef SQUARE_H
#define SQUARE_h
#include "Rectangle.h"
#include <iostream>


class Square : public Rectangle{
	private:
		static bool check(Point2D* vertices){
		
		
			return Point2D::distance(vertices[0],vertices[1]) == Point2D::distance(vertices[1],vertices[2]) ==Point2D::distance(vertices[2],vertices[3]) ==Point2D::distance(vertices[3],vertices[0]) ;
		
		}
	public:

		Square();
		Square(std::string color, Point2D* vertices);
		friend std::ostream& operator<<(std::ostream &out, const Square &square);	
		virtual void print() override{
		
			std::cout<< "Cuadrado de Color: "<< Shape::getcolor() <<  "con Vertices" << get_vertex(0) << get_vertex(1) << get_vertex(2) << get_vertex(3) << std::endl;
		
		}
		virtual void set_vertices(Point2D* vertices){
		
			if( check(vertices)){
							
				for(int x=0;x< N_VERTICES; x++){
											
					vs[x] = vertices[x];
														
				}
									
			}else{
				throw std::invalid_argument("No forman un cuadrado");
											
			}
		
		}
		virtual double area() const override{
			return Point2D::distance(get_vertex(0),get_vertex(1))* Point2D::distance(get_vertex(1),get_vertex(2));
		}
		virtual double perimeter() const override{
			return Point2D::distance(get_vertex(0),get_vertex(1)) + Point2D::distance(get_vertex(1),get_vertex(2)) + Point2D::distance(get_vertex(2),get_vertex(3)) + Point2D::distance(get_vertex(3),get_vertex(0)) ;
		
		}
		virtual void translate(double incX, double incY){
		
			for(int x=0; x< N_VERTICES;x++){
				vs[x].x += incX;
				vs[x].y += incY;
			
			
			}
		
		
		}

	
double max_side()const override{
	if(Point2D::distance(vertices[0], vertices[1]) > Point2D::distance(vertices[3], vertices[0]){
		return (Point2D::distance(vertices[0], vertices[1]);
	}else{
		return (Point2D::distance(vertices[3], vertices[0]);
	}
}







};





#endif
