#include <stdio.h>
#include <stdlib.h>
#include "ImageIO.h"

class player{
public:
	player(float a);

	void draw(float x, float y, float z);
	void textureMapping(GLuint texture, ImageIO* image);
	ImageIO *image;
	ImageIO *upImage;
	GLuint p_tex;
	GLuint p_tex1;
private:
	float size;

};