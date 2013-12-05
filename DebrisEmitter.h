#include "LocalGraphicsLib.h"
#include "ImageIO.h"
#include <glut.h>
#define MAX_DEBRIS_PARTICLES 1000

using namespace std;
class DebrisEmitter{
public:

	DebrisEmitter(const char* file_name_1, const char* file_name_2);
	~DebrisEmitter(void);
	void debrisEmitterInit();
	void debrisEmitterDisplay();
	ImageIO* image1;
	ImageIO* image2;
	float	slowdown;
	float	zoom;
	GLuint	loop;
	GLuint	col;
	GLuint	delay;
	GLuint	texture[2];
	bool initFlag;
	bool destroy;
	particles *debris_particle[MAX_DEBRIS_PARTICLES];	// Particle Array 
};