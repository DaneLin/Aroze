#pragma once

struct Vector3f
{
	double x, y, z;
	Vector3f(double InX, double InY, double InZ)
		: x(InX), y(InY), z(InZ)
	{}

	Vector3f CrossProduct(const Vector3f& other)
	{
		double tmpX = y * other.z - other.y * z;
		double tmpY = z * other.x - other.z * x;
		double tmpZ = x * other.y - other.x * y;
		return { tmpX, tmpY, tmpZ };
	}

	double Point(const Vector3f& other)
	{
		return x * other.x + y * other.y + z * other.z;
	}

	Vector3f operator- (const Vector3f& other)
	{
		return Vector3f(x - other.x, y - other.y, z - other.z);
	}

	Vector3f operator*(const double& other)
	{
		return Vector3f(x * other, y * other, z * other);
	}

	// 归一化方法
	void normalize() {
		float length = std::sqrt(x * x + y * y + z * z);
		if (length > 0) { // 防止除以零
			x /= length;
			y /= length;
			z /= length;
		}
	}
};

