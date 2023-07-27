#include <bits/stdc++.h>

using namespace std;
 
class Rectangle{

private:
	
	int lenth;
	int height;
	 	
public:
	
	Rectangle() : lenth(5), height(10){}
	Rectangle(const int& l, const int& h) : lenth(l), height(h){} 
	
	void perimeter(){
		int per = (lenth + height) * 2;
		cout << "Rectangle Perimeter : " << per << endl; 
	}
	void area(){
		int are = lenth * height;
		cout << "Rectangle Area : " << are << endl;
	}
	void printShape(){
		for (int i = 1; i <= height; i++) {
        	for (int j = 1; j <= lenth; j++) {
      	      if (i == 1 || i == height || j == 1 || j == lenth) {
      	          cout << "* ";
      	      } else {
      	          cout << "  ";
      	      }
      	  }
     	   cout << endl;
   		}
	}
	
 };
 
class Circle{
	
private:
	
	int radius;
	float PI = 3.14;
	
public:
	
	int r = 2;
	void setRadius(){
		cout << endl << "Enter Radius : ";
		cin >> r;
		radius = r;
	}
	void perimeter(){
		float per = 2 * PI *  radius;
		cout << "Circle Perimeter : " << per << endl;
	}
	void area(){
		float are = (radius * radius) * PI;
		cout << "Circle Area : " << are << endl;
	}
	void printShape(){
		for (int i = -radius; i <= radius; i++) {
        	for (int j = -radius; j <= radius; j++) {
        	    if (abs(sqrt(i * i + j * j) - radius) < 0.5) {
      	          cout << "* ";
        	    } else {
        	        cout << "  ";
         	   }
      		}
			cout << endl;
   		}
	}
	
};
 
int main(){
	
	Rectangle r1(10, 5);
	Circle c1;
	
	r1.area();
	r1.perimeter();
	r1.printShape();
	
	c1.setRadius();
	c1.perimeter();
	c1.area();
	c1.printShape();
	
 }