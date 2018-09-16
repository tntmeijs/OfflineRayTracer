#pragma once

class Vector3
{
public:
	union
	{
		struct
		{
			double x, y, z;
		};

		struct 
		{
			double r, g, b;
		};

		double components[3];
	};

	Vector3();
	Vector3(double x, double y, double z);
	
	Vector3& operator+=(const Vector3 rhs);
	Vector3& operator-=(const Vector3 rhs);
	Vector3& operator*=(const Vector3 rhs);
	Vector3& operator*=(double rhs);
	Vector3& operator/=(const Vector3 rhs);
	
	Vector3 operator-() const;
	Vector3 operator-(const Vector3& rhs);
	Vector3 operator+(const Vector3& rhs);
	Vector3 operator*(const Vector3& rhs);
	Vector3 operator*(double rhs);
	Vector3 operator/(const Vector3& rhs);

	Vector3 Cross(const Vector3& rhs);
	Vector3 Normalized() const;

	double Length() const;
	double LengthSquared() const;
	double Dot(const Vector3& rhs) const;

	void Normalize();

	static Vector3 Cross(const Vector3& lhs, const Vector3& rhs);

	static double Length(const Vector3& rhs);
	static double Dot(const Vector3& lhs, const Vector3& rhs);
	
	static void Normalize(Vector3& rhs);
};