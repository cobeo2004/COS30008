#pragma once
#include "Vector2D.h"

#define M_VERTICES 30

class Polygon
{
private:
	Vector2D fVertices[M_VERTICES];
	size_t fNumberOfVertices;

public:
	Polygon() noexcept;
	void readData(std::istream& aIstream);

	size_t getNumberOfVertices() const noexcept;
	const Vector2D& getVertex(size_t aIndex) const;
	float getPerimeter() const noexcept;

	Polygon scale(float aScalar) const noexcept;
};