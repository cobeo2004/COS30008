#include "Matrix3x3.h"
#include <cassert>

Matrix3x3 Matrix3x3::operator*(const Matrix3x3& aOther) const noexcept {
	
	Matrix3x3 result;
	for (size_t i = 0; i < 3; i++) {
		float* vectorComponents = new float[3];
		for (size_t j = 0; j < 3; j++) {
			vectorComponents[j] = row(i).dot(aOther.column(j));
		}
		result.fRows[i] = Vector3D(vectorComponents[0], vectorComponents[1], vectorComponents[2]);
		delete[] vectorComponents;
	}

	return result;
	
}

float Matrix3x3::det() const noexcept {
	float m11 = row(0)[0];
	float m12 = row(0)[1];
	float m13 = row(0)[2];
	float m21 = row(1)[0];
	float m22 = row(1)[1];
	float m23 = row(1)[2];
	float m31 = row(2)[0];
	float m32 = row(2)[1];
	float m33 = row(2)[2];

	return (m11 * ((m22 * m33) - (m23 * m32))) - (m12 * ((m21 * m33) - (m23 * m31))) + (m13 * ((m21 * m32) - (m22 * m31)));
}

Matrix3x3 Matrix3x3::transpose() const noexcept {
	return Matrix3x3(
		column(0),
		column(1),
		column(2)
	);
	
}

bool Matrix3x3::hasInverse() const noexcept {
	return det() != 0;
}

Matrix3x3 Matrix3x3::inverse() const noexcept {
	assert(hasInverse());
	float inverseOfDet = 1.0f / det();
	float m11 = row(0)[0];
	float m12 = row(0)[1];
	float m13 = row(0)[2];
	float m21 = row(1)[0];
	float m22 = row(1)[1];
	float m23 = row(1)[2];
	float m31 = row(2)[0];
	float m32 = row(2)[1];
	float m33 = row(2)[2];

	return Matrix3x3(
		Vector3D((m22 * m33) - (m23 * m32), (m13 * m32) - (m12 * m33), (m12 * m23) - (m13 * m22)),
		Vector3D((m23 * m31) - (m21 * m33), (m11 * m33) - (m13 * m31), (m13 * m21) - (m11 * m23)),
		Vector3D((m21 * m32) - (m22 * m31), (m12 * m31) - (m11 * m32), (m11 * m22) - (m12 * m21))
	) * inverseOfDet;
}

std::ostream& operator<<(std::ostream& aOStream, const Matrix3x3& aMatrix) {
	aOStream << "[";
	for (size_t i = 0; i < 2; i++) {
		aOStream << aMatrix.row(i).toString() << ", ";
	}
	aOStream << aMatrix.row(2).toString();
	aOStream << "]";
	return aOStream;
}