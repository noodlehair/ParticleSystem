#include "LocalGraphicsLib.h"
#include "ImageIO.h"
#include <glut.h>
#include <unordered_set>
#define	MAX_PARTICLES	2000
using namespace std;
class FlameEmitter{
public:

	FlameEmitter(const char* file_name);
	~FlameEmitter(void);
	void flameEmitterInit();
	void flameEmitterDisplay();
	ImageIO* image;
	float	slowdown;
	float	zoom;
	GLuint	loop;
	GLuint	col;
	GLuint	delay;
	GLuint	texture[1];
	bool initFlag;
	particles particle[MAX_PARTICLES];	// Particle Array 
	bool destroy;
};