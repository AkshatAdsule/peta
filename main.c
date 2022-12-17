#include "canvas.h"
#include "peta.h"

#include <stdbool.h>
#include <math.h>

#define PI M_PI

int main(void) {
	canvas *c = make_canvas(500, 500, 0x00);
	/* bool is_white = true; */

	/* for(int i = 0; i < 500; i += 50) { */
		/* for(int j = 0; j < 500; j+= 50) { */
			/* peta_rect(c, i, j, 50, 50, is_white ? 0xFFFFFF : 0x000000); */
			/* is_white = !is_white; */
		/* } */
		/* is_white = !is_white; */
	/* } */

	/* peta_line(c, 0, 0, 300, 499, 0xFF00FF); */

	// for(float theta = 0; theta <= 2 * PI; theta += (PI / 32.0)) {
		// peta_line_angle_mag(c, 250, 250, theta, 200, 0x00FFFF);
	// }
	// peta_circle(c, 250, 250, 200, 0x0000FF);
	
	int color = 0xFF0000;

	for(int i = 0; i < 250; ++i) {
		peta_circle(c, 250, 250, i, color);

		if(i % 25 == 0) {
			color = color == 0xFFFFFF ? 0xFF0000 : 0xFFFFFF;
		}
	}

	render_to_file(c, "file.ppm");
}
