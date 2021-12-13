#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <cmath>

int main()
{
	std::ifstream infile("in.txt");

	int x, y;
	
	int x_left = 0, x_right = 0, y_left = 0, y_right = 0;
	double cos_right = 1, cos_left = 1;

	int x0, y0;
	infile >> x0 >> y0;
	
    
	while (infile >> x >> y)
	{
		double cos = (x0*x+y0*y)/(sqrt(x*x+y*y)*sqrt(x0*x0+y0*y0));
		cos = std::round(cos);
        
		if (cos <= cos_left && (y0*x < x0*y)) 
		{
			cos_left = cos;
			x_left = x; 
			y_left = y;

		}
		if (cos <= cos_right && (y0*x >= x0*y)) 
		{
			cos_right = cos;
			x_right = x; 
			y_right = y;
		}
	}

	std::cout << "Leftmost: " << x_left << " " << y_left << "\n";
	std::cout << "Rightmost: " << x_right << " " << y_right << "\n";
}
