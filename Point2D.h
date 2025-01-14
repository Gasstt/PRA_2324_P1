#ifndef POINT2D_H
#define POINT2D_H
#include <iostream>
#include <cmath>


class Point2D{
	public:
		double x;
		double y;
		
		Point2D(double x=0, double y=0){
			this -> x = x;
			this -> y = y;
		
		}
		
		static double distance(const Point2D &a, const Point2D &b){
		
			return sqrt(pow(a.x - b.x,2)+pow(a.y - b.y,2));
		
		}
/*		Point2D& operator=(const Point2D &a){
			this->x = a.x;
			this->y = a.y;
			return *this;
		
		
				}*/

		friend bool operator==(const Point2D &a, const Point2D &b){
		
			if(a.x == b.x && a.y == b.y){
			
				return true;
			}
			return false;
		
		}

		friend bool operator!=(const Point2D &a, const Point2D &b){
		
			if(a.x != b.x && a.y != b.y){
			
				return true;
			}

			return false;
		}

		friend std::ostream& operator<<(std::ostream &out, const Point2D &p){
			
			out << "(" << p.x << ", " << p.y << ")";
			return out;
		
		}




};
#endif
