#include "canvas.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

canvas* make_canvas(int width, int height, int color) {
	canvas* c = (canvas*) malloc(sizeof(canvas));
	c->width = width;
	c->height = height;

	c->canvas = (int**) malloc(height * sizeof(int*));
	for(int i = 0; i < height; ++i) {
		c->canvas[i] = (int*) malloc(width * sizeof(int));
		for(int j = 0; j < width; ++j) {
			c->canvas[i][j] = color;
		}
	}

	return c;
}

void render_to_file(canvas* c, char *file_name) {
	FILE* fp = fopen(file_name, "w");
	char buf[50];

	sprintf(buf, "P6 %d %d 255 ", c->width, c->height);
	fwrite(buf, strlen(buf), sizeof(char),fp);

	unsigned char r, g, b;
	int color;
	for(int i = 0; i < c->height; ++i) {
		for(int j = 0; j < c->width; ++j) {
			color = c->canvas[i][j];
			r = (color & 0x00FF0000) >> 16;
			g = (color & 0x0000FF00) >> 8;
			b = (color & 0x000000FF);

			fwrite(&r, sizeof(unsigned char), 1, fp);
			fwrite(&g, sizeof(unsigned char), 1, fp);
			fwrite(&b, sizeof(unsigned char), 1, fp);
		}
	}

	fclose(fp);
}
