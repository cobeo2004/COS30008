
#include "Polygon.h"

float Polygon::getSignedArea() const noexcept {
	
	float result = 0.0f;
	if (fNumberOfVertices > 2) {
		for (size_t i = 0; i < fNumberOfVertices; i++)
		{
			size_t j = (i + 1) % fNumberOfVertices;
			result += 0.5 * ((fVertices[i].x() * fVertices[j].y()) - (fVertices[i].y() * fVertices[j].x()));
		}
	}

	return result;
}

Polygon Polygon::transform(const Matrix3x3& aMatrix) const noexcept {
    Polygon transformedPolygon = *this;

    for (size_t i = 0; i < fNumberOfVertices; ++i) {

        Vector3D transformedVertex = aMatrix * Vector3D(fVertices[i].x(), fVertices[i].y(), 1.0f);
        transformedPolygon.fVertices[i] = Vector2D(transformedVertex.x(), transformedVertex.y());
    }

    transformedPolygon.fNumberOfVertices = fNumberOfVertices;

    return transformedPolygon;
	
}

