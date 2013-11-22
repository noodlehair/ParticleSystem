#include "LocalGraphicsLib.h"
#include "ImageIO.h"
#include <glut.h>
#define MAX_FLASH_PARTICLES 2
using namespace std;
class FlashEmitter{
public:

	FlashEmitter(const char* file_name);
	~FlashEmitter(void);
	void flashEmitterInit();
	void flashEmitterDisplay();
	ImageIO* image;
	float	slowdown;
	float	zoom;
	GLuint	loop;
	GLuint	col;
	GLuint	delay;
	GLuint	texture[1];
	float dx;
	float dy;
	float const_adder;
	bool initFlag;
	particles flash_particle[MAX_FLASH_PARTICLES];	// Particle Array 
};