#include "peta.h"

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "canvas.h"

void peta_rect(canvas *c, int x1, int y1, int width, int height, int fill_color) {
	for(int i = y1; i < y1 + height && i < c->height; ++i) {
		for(int j = x1; j < x1 + width && j < c->width; ++j) {
			c->canvas[i][j] = fill_color;
		}
	}
}

/* LINES */

void _plot_line_low(canvas* c, int x1, int y1, int x2, int y2, int stroke_color) {
	int dx = x2 - x1;
	int dy = y2 - y1;
	int yi = 1;

	if(dy < 0) {
		yi = -1;
		dy = -dy;
	}
	int D = (2 * dy) - dx;
	int y = y1;

	for(int x = x1; x <= x2 && x < c->width && x >= 0; ++x) {
		c->canvas[y][x] = stroke_color;
		if(D > 0) {
			y += yi;
			D += (2 * (dy - dx));
		} else {
			D += (2 * dy);
		}
	}
}

void _plot_line_high(canvas* c, int x1, int y1, int x2, int y2, int stroke_color) {
	int dx = x2 - x1;
	int dy = y2 - y1;
	int xi = 1;

	if(dx < 0) {
		xi = -1;
		dx = -dx;
	}
	int D = (2 * dx) - dy;
	int x = x1;

	for(int y = y1; y <= y2 && y < c->height && y >= 0; ++y) {
		c->canvas[y][x] = stroke_color;
		if(D > 0) {
			x += xi;
			D += (2 * (dx - dy));
		} else {
			D += (2 * dx);
		}
	}
}

void peta_line(canvas *c, int x1, int y1, int x2, int y2, int stroke_color) {
	if(abs(y2 - y1) < abs(x2 - x1)) {
		if(x1 > x2) {
			_plot_line_low(c, x2, y2, x1, y1, stroke_color);
		} else {
			_plot_line_low(c, x1, y1, x2, y2, stroke_color);
		}
	} else {
		if(y1 > y2) {
			_plot_line_high(c, x2, y2, x1, y1, stroke_color);
		} else {
			_plot_line_high(c, x1, y1, x2, y2, stroke_color);
		}
	}
}

void peta_line_angle_mag(canvas *c, int x, int y, float theta, float r, int stroke_color) {
	int x2 = x + (r * cos(theta));
	int y2 = y + (r * sin(theta));

	peta_line(c, x, y, x2, y2, stroke_color);
}


/* CIRCLE */

void peta_circle(canvas *c, int x, int y, int r, int stroke_color) {
	int** buf = c->canvas;

	int xi = r;
	int yi = 0;

	buf[yi + y][xi + x] = stroke_color;
	buf[-yi + y][xi + x] = stroke_color;
	buf[xi + y][yi + x] = stroke_color;
	buf[xi + y][-yi + x] = stroke_color;

	int P = 1 - r;
	while(xi > yi) {
		yi++;

		if(P <= 0) {
			P = P + 2*yi + 1;
		} else {
			xi--;
			P = P + 2*yi - 2*xi + 1;
		}

		if(xi < yi) {
			break;
		}

		buf[yi + y][xi + x] = stroke_color;
		buf[yi + y][-xi + x] = stroke_color;
		buf[-yi + y][xi + x] = stroke_color;
		buf[-yi + y][-xi + x] = stroke_color;
		buf[xi + y][yi + x] = stroke_color;
		buf[xi + y][-yi + x] = stroke_color;
		buf[-xi + y][yi + x] = stroke_color;
		buf[-xi + y][-yi + x] = stroke_color;
	}
}
