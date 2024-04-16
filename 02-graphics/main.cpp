#include <iostream>

#include "tgaimage/tgaimage.h"
#include "model.h"
#include "line/line.h"

const TGAColor white = TGAColor(255, 255, 255, 255);
const TGAColor red   = TGAColor(255, 0,   0,   255);

void draw_red_dot_and_save()
{
	TGAImage image(100, 100, TGAImage::RGB);
	image.set(52, 41, red);
	image.flip_vertically(); // i want to have the origin at the left bottom corner of the image
	image.write_tga_file("output.tga");
}

void line_unoptimized(int x0, int y0, int x1, int y1, TGAImage &image, TGAColor color)
{
	// states whether height is larger than width
	bool steep = false;
	int dy = y1-y0;
	int dx = x1-x0;
	float abs_slope = std::abs(dy-dx);

	// Check if width is smaller than height
	if (std::abs(dx) < std::abs(dy))
	{
		std::swap(x0, y0);
		std::swap(x1, y1);
		steep = true;
	}

	// check if given points are reversed
	// i.e. end point given first
	// assuming starting point has lower x value
	// and ending point has hight x value
	// >> If reversed, reverse them
	if (x0 > x1)
	{
		std::swap(x0, x1);
		std::swap(y0, y1);
	}

	for (int x = x0; x < x1; x++)
	{
		float t = (x-x0) / (float)dx;
		int y = y0 * (1.-t) + y1 * t;
		if (steep)
		{
			image.set(y, x, color);
		} else {
			image.set(x, y, color);
		}
	}
	
	
}




void draw_3_lines_and_save()
{
	TGAImage image(100, 100, TGAImage::RGB);
	for (size_t i = 0; i < 1000000; i++)
	{
		line(13, 20, 80, 40, image, white); 
		line(20, 13, 40, 80, image, red); 
		line(80, 40, 13, 20, image, red);
	}
	image.flip_vertically();
	image.write_tga_file("lines.tga");
}

int main(int argc, char** argv) {
	Model *model = NULL;

    if (2==argc) {
        model = new Model(argv[1]);
    } else {
        model = new Model("wavefront_obj/african_head.obj");
    }

	const int width  = 800;
	const int height = 800;
	
	TGAImage image(width, height, TGAImage::RGB);


    for (int i=0; i<model->nfaces(); i++) {
        std::vector<int> face = model->face(i);
        for (int j=0; j<3; j++) {
            Vec3f v0 = model->vert(face[j]);
            Vec3f v1 = model->vert(face[(j+1)%3]);
            int x0 = (v0.x+1.)*width/2.;
            int y0 = (v0.y+1.)*height/2.;
            int x1 = (v1.x+1.)*width/2.;
            int y1 = (v1.y+1.)*height/2.;
            line(x0, y0, x1, y1, image, white);
        }
    }


	image.flip_vertically();
	image.write_tga_file("face_wireframe.tga");
	
	return 0;
}