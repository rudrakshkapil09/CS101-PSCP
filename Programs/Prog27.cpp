#include <iostream>
using namespace std;

struct point{
	int x;
	int y;
};

struct point newPoint(point &a, point &b){
	point c;
	c.x = a.x * b.x;
	c.y = a.y * b.y;
	return c;
}

int main()
{
	cout << "\n[This is a program that uses a structure Point to model a point]\n\n";
	
	point A;
	point B;
	point C;

	cout << "Enter the X and Y coordinates of the first point:\n";
	cin >> A.x >> A.y;

	cout << "Enter the X and Y coordinates of the second point:\n";
	cin >> B.x >> B.y;
	
	C = newPoint(A, B);
	cout << "The new point is (" << C.x << ", " << C.y << ")\n";
	return 0;
}
