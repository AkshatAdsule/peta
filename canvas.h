#ifndef CANVAS_H
#define CANVAS_H

typedef struct canvas_struct {
	int** canvas;
	int width;
	int height;
} canvas;

/**
 * Creates a new canvas with the given color as the background
 * @param width The width of the canvas
 * @param height The height of the canvas
 * @param color The background color
 */
canvas* make_canvas(int width, int height, int color);

/**
 * Renders the given canvas to the given file in PPM format
 * @param c The canvas to render
 * @param file_name The file to render to
 */
void render_to_file(canvas* c, char* file_name);

#endif
