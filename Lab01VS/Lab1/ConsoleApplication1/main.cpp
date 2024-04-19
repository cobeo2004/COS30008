#include <iostream>
#include <fstream>
#include <cmath>

#include "Polygon.h"





int main(int argc, char** argv)
{
	if (argc < 2)
	{
		std::cerr << "Args missing." << std::endl << "Usage: VectorOperations <fileName>" << std::endl;
		return 1;
	}

	std::ifstream lInput(argv[1], std::ifstream::in);
	if (!lInput.good())
	{
		std::cerr << "Cannot open input file: " << argv[1] << std::endl;
		return 2;
	}

	Polygon lPolygon;
	lPolygon.readData(lInput);
	lInput.close();

	for (size_t i = 0; i < lPolygon.getNumberOfVertices(); i++)
		std::cout << "Vertex #" << i << ": " << lPolygon.getVertex(i) << std::endl;

	std::cout << "The perimeter of lPolygon is " << lPolygon.getPerimeter() << std::endl;

	std::cout << "The number of vertices: " << lPolygon.getNumberOfVertices() << std::endl;
	
	Polygon lScaled = lPolygon.scale(4.0f);
	std::cout << "The perimeter of lScaled is " << lScaled.getPerimeter() << std::endl;

	float lFactor = lScaled.getPerimeter() / lPolygon.getPerimeter();
	std::cout << "Scale factor: " << lFactor << std::endl;

	return 0;
}