#include <Thirdparty/Nothings/stb_image_write.h>

#define OUTPUT_FILE_NAME "renderer_output.png"

struct Color
{
	unsigned char r, g, b;
};

int main(int argc, char* argv[])
{
	const int width = 1280;
	const int height = 720;

	Color* imageData = new Color[width * height];

	for (int h = 0; h < height; ++h)
	{
		for (int w = 0; w < width; ++w)
		{
			// 2D to 1D index (column-based)
			int index = width * h + w;

			float r = static_cast<float>(w + 1) / static_cast<float>(width);
			float g = static_cast<float>(h + 1) / static_cast<float>(height);

			imageData[index].r = static_cast<unsigned char>(255.0f * r);
			imageData[index].g = static_cast<unsigned char>(255.0f * g);
			imageData[index].b = 51;
		}
	}

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