#include "LocalGraphicsLib.h"
#include "ImageIO.h"
#include <glut.h>
#define MAX_SHOCK_PARTICLES 1
using namespace std;
class ShockwaveEmitter{
public:

	ShockwaveEmitter(const char* file_name);
	~ShockwaveEmitter(void);
	void shockwaveEmitterInit();
	void shockwaveEmitterDisplay();
	ImageIO* image;
	float	slowdown;
	float	zoom;
	GLuint	loop;
	GLuint	col;
	GLuint	delay;
	GLuint	texture[1];
	float dx;   // shockwave x increment size 
	float dz;   // shockwave z increment size
	bool initFlag;
	particles *shockwave_particle[MAX_SHOCK_PARTICLES];	// Particle Array 
};