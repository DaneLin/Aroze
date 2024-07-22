// Author : Bikty
#include <iostream>
#include "Utils.h"
#include "math/vector.h"


int main()
{
	std::cout << "Hello World\n";

	const int width = 512;
	const int height = 512;

	// 创建一个简单的红色渐变图像
	std::vector<std::vector<std::tuple<int, int, int>>> pixelData(height, std::vector<std::tuple<int, int, int>>(width));

	Vector3f RayOrigin(256, 256, -20);
	Vector3f CircleOrigin(256, 256, 0);
	float r = 10.f;

	for (int y = 0; y < height; ++y) {
		for (int x = 0; x < width; ++x) {

			Vector3f RayDirection(x - RayOrigin.x, y - RayOrigin.y, 20);
			RayDirection.normalize();
			float A = RayDirection.Point(RayDirection);
			float B = 2 * (RayOrigin - CircleOrigin).Point(RayDirection);
			float C = (RayOrigin - CircleOrigin).Point(RayOrigin - CircleOrigin) - r * r;

			if (B * B - 4 * A * C >= 0)
			{
				//std::cout << "ok" << std::endl;
				pixelData[y][x] = std::make_tuple(255, 0, 0); // 红色渐变
			}
		}
	}

	Aro::savePPM("output.ppm", width, height, pixelData);

	

	std::cin.get();
}