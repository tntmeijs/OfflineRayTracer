#include "Thirdparty/Nothings/stb_image_write.h"
#include "Math/vector3.hpp"
#include "Renderer/Ray.hpp"

#define OUTPUT_FILE_NAME "renderer_output.png"

struct Color
{
	unsigned char r, g, b;
};

Vector3 GetColorFromRay(const Ray& ray)
{
	double t = 0.5 * (ray.GetDirection().y + 1.0);
	return  Vector3(1.0, 1.0, 1.0) * (1.0 - t) + Vector3(0.5, 0.7, 1.0) * t;
}

int main(int argc, char* argv[])
{
	const int width = 1280;
	const int height = 720;

	auto* imageData = new Color[width * height];

	Vector3 lowerLeftCorner(-2.0, -1.0, -1.0);
	Vector3 horizontal(4.0, 0.0, 0.0);
	Vector3 vertical(0.0, 2.0, 0.0);
	Vector3 origin(0.0, 0.0, 0.0);

	for (int h = height -1; h >= 0; --h)
	{
		for (int w = 0; w < width; ++w)
		{
			double u = static_cast<double>(w) / static_cast<double>(width);
			double v = static_cast<double>(h) / static_cast<double>(height);

			Ray ray(origin, lowerLeftCorner + (horizontal * u) + (vertical * v));

			Vector3 color = GetColorFromRay(ray);
			color *= 255.0;

			// 2D to 1D index (column-based)
			int index = width * h + w;

			imageData[index].r = static_cast<unsigned char>(color.r);
			imageData[index].g = static_cast<unsigned char>(color.g);
			imageData[index].b = static_cast<unsigned char>(color.b);
		}
	}

	stbi_flip_vertically_on_write(true);

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