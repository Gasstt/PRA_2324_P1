#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <stdexcept>
#include <iostream>
#include "Shape.h"
#include "Point2D.h"


class Rectangle : public Shape{

	private:
		static bool check(Point2D* vertices){
		
			return Point2D::distance(vertices[0],vertices[1]) == Point2D::distance(vertices[2],vertices[3]) && Point2D::distance(vertices[1],vertices[2]) == Point2D::distance(vertices[3],vertices[0]);
		
		}

	public:
		Rectangle();

		Rectangle(std::string color, Point2D* vertices);

		Rectangle(const Rectangle &r);

		~Rectangle();


		Point2D get_vertex(int ind) const;

		Point2D operator[](int ind) const;

		virtual void set_vertices(Point2D* vertices);

		Rectangle& operator=(const Rectangle &r);

		friend std::ostream& operator<<(std::ostream &out, const Rectangle &r);

		//Metodos heredados
		
		double area()const override{
		
			return Point2D::distance(vs[0],vs[1])*Point2D::distance(vs[3],vs[0]);
		
		}

		double perimeter() const override{
		
			return (2*Point2D::distance(vs[0],vs[1]))+(2*Point2D::distance(vs[3],vs[0]));		
		
		}

		void translate(double incX, double incY)override{
		
			for(int z=0; z< N_VERTICES; z++){
			
				vs[z].x += incX;
				vs[z].y += incY;
			
			
			}
		
		}
		void print()override{
		
			std::cout<< "Rectanfulo de Color: "<< Shape::getcolor() <<  "con Vertices" << get_vertex(0) << get_vertex(1) << get_vertex(2) << get_vertex(3) << std::endl;
		
		}
				
		double max_side()const override{
			if(Point2D::distance(vs[0], vs[1]) > Point2D::distance(vs[3], vs[0]){
				return (Point2D::distance(vs[0], vs[1]);
			}else{
				return (Point2D::distance(vs[3], vs[0]);
			}
		}



		static int const N_VERTICES = 4;

	protected:
		Point2D* vs;



};
#endif

