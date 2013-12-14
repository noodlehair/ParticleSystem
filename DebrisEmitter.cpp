#include "DebrisEmitter.h"
#include "LocalGraphicsLib.h"

#define MAX_DEBRIS_PARTICLES 100

DebrisEmitter::DebrisEmitter(const char* file_name_1, const char* file_name_2){

	image1 = new ImageIO(file_name_1);
	image2 = new ImageIO(file_name_2);
	slowdown = 70.0f;
	zoom = -100.0f;
	initFlag = false;
	for (loop = 0; loop < MAX_DEBRIS_PARTICLES; loop++)
	{
		debris_particle[loop] = new particles();
	}
}
DebrisEmitter :: ~DebrisEmitter(void){
	delete image1;
	delete image2;
	for (loop = 0; loop < MAX_DEBRIS_PARTICLES; loop++)
	{
		delete debris_particle[loop];
	}
}

void DebrisEmitter::debrisEmitterInit(){
	//ImageIO* thedebris_image1 = new ImageIO("C:/Users/Lanceton/Dropbox/Compsci 344 Final Project/Particle System Code/debris1.ppm");
	LoadGLTextures(image1, &texture[0]);
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

	for (loop = 0; loop<MAX_DEBRIS_PARTICLES; loop++)
	{
		debris_particle[loop]->x = 0;
		debris_particle[loop]->y = 0;
		debris_particle[loop]->z = 0;
		debris_particle[loop]->active = true;
		debris_particle[loop]->life = 1.0f;
		debris_particle[loop]->fade = float(rand() % 100) / 10000.0f ;
		debris_particle[loop]->r = 227 / 255.0;
		debris_particle[loop]->g = 140.0 / 255.0;;
		debris_particle[loop]->b = 45 / 255.0;
		debris_particle[loop]->xi = float((rand() % 50) - 26.0f) * 2;
		debris_particle[loop]->yi = float((rand() % 50) - 25.0f) * 2;
		debris_particle[loop]->zi = float((rand() % 50) - 25.0f) * 2;
		debris_particle[loop]->xg = 0.0f;
		debris_particle[loop]->yg = 0.0f;
		debris_particle[loop]->zg = 0.0f;
	}
	//ImageIO* thedebris_image2 = new ImageIO("C:/Users/Lanceton/Dropbox/Compsci 344 Final Project/Particle System Code/debris2.ppm");
	


}
void DebrisEmitter::debrisEmitterDisplay(){

	if (!initFlag){
		debrisEmitterInit();
		initFlag = true;
	}
	for (loop = 0; loop<MAX_DEBRIS_PARTICLES; loop++)
	{
		glDepthMask(GL_FALSE);
		if (debris_particle[loop]->active)
		{
			float x = debris_particle[loop]->x;
			float y = debris_particle[loop]->y;
			float z = debris_particle[loop]->z;


			glColor4f(debris_particle[loop]->r, debris_particle[loop]->g, debris_particle[loop]->b, debris_particle[loop]->life);
			glBindTexture(GL_TEXTURE_2D, texture[0]);
			glBegin(GL_TRIANGLE_STRIP);
			glTexCoord2d(1, 1); glVertex3f(x + 1.0f, y + 1.0f, z);
			glTexCoord2d(0, 1); glVertex3f(x - 1.0f, y + 1.0f, z);
			glTexCoord2d(1, 0); glVertex3f(x + 1.0f, y - 1.0f, z);
			glTexCoord2d(0, 0); glVertex3f(x - 1.0f, y - 1.0f, z);
			glEnd();

			debris_particle[loop]->x += debris_particle[loop]->xi / (slowdown);
			debris_particle[loop]->y += debris_particle[loop]->yi / (slowdown);
			debris_particle[loop]->z += debris_particle[loop]->zi / (slowdown);

			debris_particle[loop]->xi += debris_particle[loop]->xg;
			debris_particle[loop]->yi += debris_particle[loop]->yg;
			debris_particle[loop]->zi += debris_particle[loop]->zg;
			debris_particle[loop]->life -= debris_particle[loop]->fade;
		}
	}
	


}