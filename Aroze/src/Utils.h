#pragma once
#include <iostream>
#include <cmath>
#include <fstream>
#include <vector>

namespace Aro
{
	// Clamp value between 0 and 255
	void Clamp(int& value)
	{
		if (value < 0)
		{
			value = 0;
		}
		else if (value > 255)
		{
			value = 255;
		}
	}

	int GrammaCorrect(int& value)
	{
		return pow(value, 1 / 2.2f);
	}

    void savePPM(const std::string& filename, int width, int height, const std::vector<std::vector<std::tuple<int, int, int>>>& pixelData) {
        std::ofstream file(filename);

        if (!file) {
            std::cerr << "�޷����ļ�: " << filename << std::endl;
            return;
        }

        // д���ļ�ͷ
        file << "P3\n" << width << " " << height << "\n255\n";
           
        int count = 0;
        // д����������
        for (const auto& row : pixelData) {
            for (const auto& pixel : row) {
                file << std::get<0>(pixel) << " " << std::get<1>(pixel) << " " << std::get<2>(pixel) << " ";
            }
            count++;
            std::clog << "\r���ڱ���ͼ��: " << count * 100 / height<< "%" << std::flush;
            file << "\n";
        }

        file.close();

        std::cout << "\rPPMͼ���ѱ���Ϊ" << filename << std::endl;
    }
}

