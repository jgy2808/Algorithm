#include <iostream>
using namespace std;

class Point {
private:
	int xpos, ypos;
public:
	Point(int x, int y){
		xpos = x;
		ypos = y;
	}
	void ShowPointInfo() const {
		cout << "[" << xpos << ", " << ypos << "]" << endl;
	}
};

class Circle {
private:
	Point cir;
	int  radius;
public:
	Circle(int x, int y, int rad) : cir(x, y){
		radius = rad;
	}
	void ShowCircleInfo() const {
		cout << "radius: " << radius << endl;
		cir.ShowPointInfo();
	}
};

class Ring {
private:
	Circle circle1;
	Circle circle2;
public:
	Ring(int inXpos, int inYpos, int inRadius, int outXpos, int outYpos, int outRadius) 
		: circle1(inXpos, inYpos, inRadius) , circle2(outXpos, outYpos, outRadius) {
	}
	void ShowRingInfo() const {
		cout << "inner Circle Info..." << endl;
		circle1.ShowCircleInfo();
		cout << "outter Circle Info..." << endl;
		circle2.ShowCircleInfo();
	}
};

int main(void) {
	Ring ring(1, 1, 4, 2, 2, 9);
	ring.ShowRingInfo();
	return 0;
}