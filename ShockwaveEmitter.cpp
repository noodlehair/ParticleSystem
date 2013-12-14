#include "ShockwaveEmitter.h"
#include "LocalGraphicsLib.h"
#define MAX_SHOCK_PARTICLES 1


ShockwaveEmitter::ShockwaveEmitter(const char* file_name){

	image = new ImageIO(file_name);
	slowdown = 1000.0f;
	zoom = -100.0f;
	dx = 2.0f * 5;
	dz = 2.0f * 5;
	initFlag = false;
	for (loop = 0; loop < MAX_SHOCK_PARTICLES; loop++)
	{
		shockwave_particle[loop] = new particles();

	}
}
ShockwaveEmitter :: ~ShockwaveEmitter(void){
	delete image;
	for (loop = 0; loop < MAX_SHOCK_PARTICLES; loop++)
	{
		delete shockwave_particle[loop];

	}
}

void ShockwaveEmitter::shockwaveEmitterInit(){
	//ImageIO* image = new ImageIO("C:/Users/Lanceton/Dropbox/Compsci 344 Final Project/Particle System Code/shock.ppm");
	LoadGLTextures(image, &texture[0]);
	glShadeModel(GL_SMOOTH);
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glClearDepth(1.0f);
	glDepthMask(GL_FALSE);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE);
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
	glHint(GL_POINT_SMOOTH_HINT, GL_NICEST);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture[0]);

	for (loop = 0; loop<MAX_SHOCK_PARTICLES; loop++)
	{
		shockwave_particle[loop]->x = 0;
		shockwave_particle[loop]->y = 0;
		shockwave_particle[loop]->z = 0;
		shockwave_particle[loop]->active = true;
		shockwave_particle[loop]->life = 1.0f;
		shockwave_particle[loop]->fade = float(rand() % 100) / 100000.0f;
		shockwave_particle[loop]->r = 1.0;
		shockwave_particle[loop]->g = 103 / 255.0;;
		shockwave_particle[loop]->b = 0.0;
		shockwave_particle[loop]->xi = float((rand() % 50) - 26.0f) * 15;
		shockwave_particle[loop]->yi = float((rand() % 50) - 25.0f) * 15;
		shockwave_particle[loop]->zi = float((rand() % 50) - 25.0f) * 15;
		shockwave_particle[loop]->xg = 0.0f;
		shockwave_particle[loop]->yg = 0.0f;
		shockwave_particle[loop]->zg = 0.0f;
	}




}
void ShockwaveEmitter::shockwaveEmitterDisplay(){
	if (!initFlag){
		shockwaveEmitterInit();
		initFlag = true;
	}
	for (loop = 0; loop<MAX_SHOCK_PARTICLES; loop++)
	{
		glDepthMask(GL_FALSE);
		if (shockwave_particle[0]->active)
		{
			float x = shockwave_particle[0]->x;
			float y = shockwave_particle[0]->y;
			float z = shockwave_particle[0]->z;

			//printf("y: %f \n", y);

			glColor4f(shockwave_particle[0]->r, shockwave_particle[0]->g, shockwave_particle[0]->b, shockwave_particle[0]->life);
			glBindTexture(GL_TEXTURE_2D, texture[0]);
			glBegin(GL_TRIANGLE_STRIP);
			glTexCoord2d(1, 1); glVertex3f(x + dx, y, z + dz);
			glTexCoord2d(0, 1); glVertex3f(x - dx, y, z + dz);
			glTexCoord2d(1, 0); glVertex3f(x + dx, y, z - dz);
			glTexCoord2d(0, 0); glVertex3f(x - dx, y, z - dz);
			glEnd();
			//printf("hrllo");
			dx += 0.5f;
			dz += 0.5f;
			

			shockwave_particle[0]->xi += shockwave_particle[0]->xg;
			shockwave_particle[0]->yi += shockwave_particle[0]->yg;
			shockwave_particle[0]->zi += shockwave_particle[0]->zg;
			shockwave_particle[0]->life -= (shockwave_particle[0]->fade + 0.020);
		}
	}



}