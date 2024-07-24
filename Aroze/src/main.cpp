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

	Vector3f RayOrigin(200, 200, -20);
	Vector3f CameraPos(256, 256, -10);
	Vector3f CircleOrigin(256, 256, 0);
	double r = 9.f;

	for (int y = 0; y < height; ++y) {
		for (int x = 0; x < width; ++x) {
			Vector3f RayDirection(x - CameraPos.x, y - CameraPos.y, -CameraPos.z);
			RayDirection.normalize();
			Vector3f RayOri2CircleOri = CameraPos - CircleOrigin;
			double A = RayDirection.Point(RayDirection);
			double B = RayOri2CircleOri.Point(RayDirection);
			double C = RayOri2CircleOri.Point(RayOri2CircleOri) - r * r;

			double Delta = B * B - A * C;
			if (Delta >= 0)
			{
				//std::cout << "ok" << std::endl;
				double SqrtDelta = std::sqrt(Delta);
				double t1 = -B - SqrtDelta;
				double t2 = -B + SqrtDelta;

				double FinalT = t1;
				if (t1 < 0.f)
				{
					FinalT = t2;
				}
				if (FinalT < 0.f)
				{
					continue;
				}

				Vector3f HitPoint = RayOrigin + FinalT * RayDirection;
				Vector3f PointNormal = HitPoint - CircleOrigin;
				PointNormal.normalize();
				Vector3f Light2Point = RayOrigin - HitPoint;
				Light2Point.normalize();
				double Cosine = PointNormal.Point(Light2Point);
				if (Cosine < 0)
				{
					Cosine = 0;
				}
				//std::cout << Cosine << std::endl;
				pixelData[y][x] = std::make_tuple(255 * Cosine, 0, 0); // 红色渐变
			}
		}
	}

	Aro::savePPM("output.ppm", width, height, pixelData);

	

	std::cin.get();
}