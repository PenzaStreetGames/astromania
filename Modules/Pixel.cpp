#include "Constants.h"

class Pixel() {

public:
	char symbol;
	int color, background;
	Pixel(char symbol = 0, int color = colors["White"], int background = color["Black"]) {
		this.symbol = symbol;
		this.color = color;
		this.background = background;
	}
}