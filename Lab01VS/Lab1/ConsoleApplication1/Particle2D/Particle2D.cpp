#ifndef _USE_MATH_DEFINES
#define M_PI 3.14159265358979323846
#else
#define _USE_MATH_DEFINES
#endif

#include "Particle2D.h"


Particle2D::Particle2D(float aMass,
	float aRadius,
	const Vector2D& aPosition,
	const Vector2D& aVelocity,
	const Vector2D& aAcceleration) noexcept :
	fMass(aMass),
	fRadius(aRadius),
	fPosition(aPosition),
	fVel(aVelocity),
	fAcc(aAcceleration)
{}

void Particle2D::applyAcceleration(const Vector2D& aAcc) noexcept
{
	fAcc = fAcc + aAcc;
}

float Particle2D::direction() const noexcept
{
	return fVel.direction();
}

void Particle2D::align(float aAngleInDegrees) noexcept
{
	fVel = fVel.align(aAngleInDegrees);
}

float Particle2D::speed() const noexcept
{
	return fVel.length();
}

void Particle2D::update() noexcept
{
	fVel = fVel + fAcc;
	fPosition = fPosition + fVel;
}

std::ostream& operator<<(std::ostream& aOStream, const Particle2D& aParticle) 
{
	aOStream << "Speed: " << aParticle.speed() << std::endl 
		<< "Direction: " << aParticle.direction() << std::endl 
		<< "Position: " << "[ " << round(aParticle.position().x()) <<
		", " << round(aParticle.position().y()) << " ]" << std::endl;
	return aOStream;
}