

#include "Polygon.h"

Polygon::Polygon() noexcept
{
	fNumberOfVertices = 0;
}

void Polygon::readData(std::istream& aIStream)
{
	while (aIStream >> fVertices[fNumberOfVertices])
		fNumberOfVertices++;
}

size_t Polygon::getNumberOfVertices() const noexcept
{
	return fNumberOfVertices;
}

const Vector2D& Polygon::getVertex(size_t aIndex) const
{
	if (aIndex < fNumberOfVertices)
		return fVertices[aIndex];
	throw std::out_of_range("aIndex out of range");
}

float Polygon::getPerimeter() const noexcept
{
	float ans = 0.0f;
	if (fNumberOfVertices > 2)
	{
		for (size_t i = 1; i < fNumberOfVertices; i++)
		{
			Vector2D p = fVertices[i] - fVertices[i - 1];
			ans += p.length();
		}
		ans += (fVertices[0] - fVertices[fNumberOfVertices - 1]).length();

	}


	return ans;
}

Polygon Polygon::scale(float aScalar) const noexcept
{
	Polygon res = *this;
	for (size_t i = 0; i < res.fNumberOfVertices; i++)
	{
		res.fVertices[i] = aScalar * fVertices[i];
	}
	return res;
}

