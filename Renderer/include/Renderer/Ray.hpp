#pragma once

#include "Math/vector3.hpp"

class Ray
{
public:
	Ray();
	Ray(Vector3 origin, Vector3 direction);

	const Vector3& GetOrigin() const;
	const Vector3& GetDirection() const;

	Vector3 GetPointAtDistance(double distance);

	void SetOrigin(Vector3 origin);
	void SetDirection(Vector3 direction);

private:
	Vector3 origin;
	Vector3 direction;
};