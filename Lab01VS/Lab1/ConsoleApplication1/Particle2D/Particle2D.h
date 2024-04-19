#pragma once
#include <iostream>
#include "Vector2D.h"

class Particle2D
{
private:
	float fMass;
	float fRadius;
	Vector2D fPosition;
	Vector2D fVel;
	Vector2D fAcc;

public:
	explicit Particle2D(float aMass = 0.0f,
		float aRadius = 0.0f,
		const Vector2D& aPosition = Vector2D(0.0f, 0.0f),
		const Vector2D& aVel = Vector2D(0.0f, 0.0f),
		const Vector2D& aAcc = Vector2D(0.0f, 0.0f)
	) noexcept;

	float mass() const noexcept { return this -> fMass; }
	float radius() const noexcept { return this -> fRadius; }
	const Vector2D& position() const noexcept { return this -> fPosition; }
	const Vector2D& velocity() const noexcept { return this -> fVel; }
	const Vector2D& acceleration() const noexcept { return this -> fAcc; }

	void applyAcceleration(const Vector2D& aAcc) noexcept;
	float direction() const noexcept;
	void align(float aAngleInDegrees) noexcept;
	float speed() const noexcept;

	void update() noexcept;

	friend std::ostream& operator<<(std::ostream& aOStream, const Particle2D& aParticle);
};
