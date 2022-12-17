#ifndef PETA_H
#define PETA_H

#include "canvas.h"

void peta_rect(canvas *c, int x1, int y1, int width, int height, int fill_color);

void peta_line(canvas *c, int x1, int y1, int x2, int y2, int stroke_color);

void peta_line_angle_mag(canvas *c, int x, int y, float theta, float r, int stroke_color);

void peta_circle(canvas *c, int x, int y, int r, int stroke_color);

#endif
