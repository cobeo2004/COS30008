#include "Vector2D.h"


//Define constructor

Vector2D::Vector2D(float aX, float aY) noexcept : fX(aX), fY(aY) {}

//Operators implementation
Vector2D Vector2D::operator+(const Vector2D& aOther) const noexcept
{
	return Vector2D(x() + aOther.x(), y() + aOther.y());
}

Vector2D Vector2D::operator-(const Vector2D& aOther) const noexcept
{
	return Vector2D(x() - aOther.x(), y() - aOther.y());
}

Vector2D Vector2D::operator*(const Vector2D& aOther) const noexcept
{
	return Vector2D(x() * aOther.x(), y() * aOther.y());
}


//Function implementation
float Vector2D::dot(const Vector2D& aOther) const noexcept
{
	return x() * aOther.x() + y() * aOther.y();
}

float Vector2D::cross(const Vector2D& aOther) const noexcept
{
	return x() * aOther.y() - y() * aOther.x();
}

float Vector2D::length() const noexcept
{
	float val = std::sqrt(x() * x() + y() * y());
	float rounded = std::round(val * 100.0f) / 100.0f;

	return rounded;
}

Vector2D Vector2D::normalize() const noexcept
{
	return *this * (1.0f / length());
}

float Vector2D::direction() const noexcept
{
	float val = std::atan2(y(), x()) * 180.0f / static_cast<float>(M_PI);
	float rounded = std::round(val * 100.0f) / 100.0f;

	return rounded;
}

Vector2D Vector2D::align(float aAngleInDegrees) const noexcept
{
	float IRadians = aAngleInDegrees * static_cast<float>(M_PI) / 180.0f;
	Vector2D INewAngle = length() * Vector2D(std::cos(IRadians), std::sinf(IRadians));

	return INewAngle;
}

Vector2D operator* (const float aScalar, const Vector2D& aVector) noexcept
{
	return aVector * aScalar;
}


// I/O operators implementation
std::istream& operator>>(std::istream& aIStream, Vector2D& aVector)
{
	return aIStream >> aVector.fX >> aVector.fY;
}

std::ostream& operator<<(std::ostream& aOStream, const Vector2D& aVector)
{
	return aOStream << "[" << round(aVector.fX) << ", " << round(aVector.fY) << "]";
}

