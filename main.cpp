#include "Thirdparty/Nothings/stb_image_write.h"
#include "Math/vector3.hpp"

#define OUTPUT_FILE_NAME "renderer_output.png"

struct Color
{
	unsigned char r, g, b;
};

int main(int argc, char* argv[])
{
	const int width = 1280;
	const int height = 720;

	auto* imageData = new Color[width * height];

	for (int h = 0; h < height; ++h)
	{
		for (int w = 0; w < width; ++w)
		{
			Vector3 color;

			color.r = 255.0 * (double)w / (double)width;
			color.g = 255.0 * (double)h / (double)height;
			color.b = 255.0 * 0.2;

			// 2D to 1D index (column-based)
			int index = width * h + w;

			imageData[index].r = static_cast<unsigned char>(color.r);
			imageData[index].g = static_cast<unsigned char>(color.g);
			imageData[index].b = static_cast<unsigned char>(color.b);
		}
	}

	stbi_flip_vertically_on_write(1);

	if (stbi_write_png(
		OUTPUT_FILE_NAME,
		width, height,
		3,
		imageData,
		sizeof(Color) * width) == 0)
	{
		return -1;
	}

	delete[] imageData;

    return 0;
}