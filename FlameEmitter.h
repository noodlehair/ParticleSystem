#include "LocalGraphicsLib.h"
#include "ImageIO.h"
#include <glut.h>
#include <unordered_set>
#define	MAX_PARTICLES	5
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
	particles *particle[MAX_PARTICLES];	// Particle Array 
	float const_adder[MAX_PARTICLES];
	float dx[MAX_PARTICLES];;
	float dy[MAX_PARTICLES];;
	bool destroy;
};