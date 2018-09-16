#include "Renderer/Ray.hpp"

Ray::Ray()
{
	this->origin = Vector3(0.0, 0.0, 0.0);
	this->direction = Vector3(0.0, 0.0, -1.0);
}

Ray::Ray(Vector3 origin, Vector3 direction)
{
	this->origin = origin;
	this->direction = direction.Normalized();
}

const Vector3 & Ray::GetOrigin() const
{
	return this->origin;
}

const Vector3 & Ray::GetDirection() const
{
	return this->direction;
}

Vector3 Ray::GetPointAtDistance(double distance)
{
	return Vector3(this->origin + (this->direction * distance));
}

void Ray::SetOrigin(Vector3 origin)
{
	this->origin = origin;
}

void Ray::SetDirection(Vector3 direction)
{
	this->direction = direction.Normalized();
}
