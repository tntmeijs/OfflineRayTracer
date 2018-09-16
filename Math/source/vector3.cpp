#include "Math/vector3.hpp"

#include <math.h>

Vector3::Vector3()
{
	this->x = 0.0;
	this->y = 0.0;
	this->z = 0.0;
}

Vector3::Vector3(double x, double y, double z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}

Vector3& Vector3::operator+=(const Vector3 rhs)
{
	this->x += rhs.x;
	this->y += rhs.y;
	this->z += rhs.z;

	return *this;
}

Vector3& Vector3::operator-=(const Vector3 rhs)
{
	this->x -= rhs.x;
	this->y -= rhs.y;
	this->z -= rhs.z;

	return *this;
}

Vector3& Vector3::operator*=(const Vector3 rhs)
{
	this->x *= rhs.x;
	this->y *= rhs.y;
	this->z *= rhs.z;

	return *this;
}

Vector3& Vector3::operator/=(const Vector3 rhs)
{
	this->x /= rhs.x;
	this->y /= rhs.y;
	this->z /= rhs.z;

	return *this;
}

Vector3 Vector3::operator-() const
{
	return Vector3(-this->x, -this->y, -this->z);
}

Vector3 Vector3::operator-(const Vector3& rhs)
{
	return Vector3(this->x - rhs.x, this->y - rhs.y, this->z - rhs.z);
}

Vector3 Vector3::operator+(const Vector3& rhs)
{
	return Vector3(this->x + rhs.x, this->y + rhs.y, this->z + rhs.z);
}

Vector3 Vector3::operator*(const Vector3& rhs)
{
	return Vector3(this->x * rhs.x, this->y * rhs.y, this->z * rhs.z);
}

Vector3 Vector3::operator/(const Vector3& rhs)
{
	return Vector3(this->x / rhs.x, this->y / rhs.y, this->z / rhs.z);
}

Vector3 Vector3::Cross(const Vector3& rhs)
{
	return Vector3(this->y * rhs.z - this->z * rhs.y, this->z * rhs.x - this->x * rhs.z, this->x * rhs.y - this->y * rhs.x);
}

double Vector3::Length() const
{
	return sqrt(this->x * this->x + this->y * this->y + this->z * this->z);
}

double Vector3::LengthSquared() const
{
	return this->x * this->x + this->y * this->y + this->z * this->z;
}

double Vector3::Dot(const Vector3& rhs) const
{
	return this->x * rhs.x + this->y * rhs.y + this->z * rhs.z;
}

void Vector3::Normalize()
{
	double length = Length();

	this->x /= length;
	this->y /= length;
	this->z /= length;
}

Vector3 Vector3::Cross(const Vector3 & lhs, const Vector3 & rhs)
{
	return Vector3(rhs.y * rhs.z - rhs.z * rhs.y, rhs.z * rhs.x - rhs.x * rhs.z, rhs.x * rhs.y - rhs.y * rhs.x);
}

double Vector3::Length(const Vector3& rhs)
{
	return sqrt(rhs.x * rhs.x + rhs.y * rhs.y + rhs.z * rhs.z);
}

double Vector3::Dot(const Vector3& lhs, const Vector3& rhs)
{
	return lhs.x * rhs.x + lhs.y * rhs.y + lhs.z * rhs.z;
}

void Vector3::Normalize(Vector3& rhs)
{
	double length = Vector3::Length(rhs);

	rhs.x /= length;
	rhs.y /= length;
	rhs.z /= length;
}