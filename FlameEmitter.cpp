#include "FlameEmitter.h"
#include "LocalGraphicsLib.h"
#include <windows.h>
#include <mmsystem.h>
#pragma comment(lib, "winmm.lib")

FlameEmitter::FlameEmitter(const char* file_name){

	image = new ImageIO(file_name);
	slowdown = 5.0f;
	zoom = -20.0f;
	initFlag = false;
	destroy = false;
	const_adder[0] = 0.5;
	const_adder[1] = 0.5;
	const_adder[2] = 0.5;
	const_adder[3] = 0.5;
	for (loop = 0; loop < MAX_PARTICLES; loop++)
	{
		particle[loop] = new particles();
	}
}
FlameEmitter :: ~FlameEmitter(void){
	delete image;
	for (loop = 0; loop < MAX_PARTICLES; loop++)
	{
		delete particle[loop];
	}
}

void FlameEmitter::flameEmitterInit(){
	//ImageIO* the_image = new ImageIO("C:/Users/Lanceton/Dropbox/Compsci 344 Final Project/Particle System Code/falme.ppm");
	PlaySound(TEXT("explosion4.wav"), NULL, SND_FILENAME | SND_ASYNC);
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
	//float x = -1.1, y = 1.1;
	float initx = -0.5;

	/*particle[1]->x = -1;;
	particle[2]->y = 1;*/
	for (loop = 0; loop<MAX_PARTICLES; loop++)
	{
		dx[loop] = 0.2;
		dy[loop] = 0.2;
		particle[loop]->x = 0;
		particle[loop]->y = 0;
		particle[loop]->z = 0;
		const_adder[loop] = 1.8;
		//particle[loop].y =y;
		//x+=0.001;
		//y-=0.001;
		initx = 0.5;
		particle[loop]->active = true;
		particle[loop]->life = 1.0f;
		float ran = float(rand() / RAND_MAX);
		ran = 5 + ran*(10 - 5);
		printf(" %d %f \n", loop, ran);
		particle[loop]->fade = ran / 1000.0f;
		particle[loop]->r = 1;
		particle[loop]->g = 120 / 255.0;
		particle[loop]->b = 0;
		particle[loop]->xi = float((rand() % 50) - 26.0f) * 3;
		particle[loop]->yi = float((rand() % 50) - 25.0f) * 3;
		particle[loop]->zi = float((rand() % 50) - 25.0f) * 3;
		particle[loop]->xg = 0.0f;
		particle[loop]->yg = 0.0f;
		particle[loop]->zg = 0.0f;
	}

}
void FlameEmitter::flameEmitterDisplay(){

	if (!initFlag){
		flameEmitterInit();
		initFlag = true;
	}
	for (loop = 0; loop<MAX_PARTICLES; loop++)
	{
		glDepthMask(GL_FALSE);
		if (particle[loop]->active)
		{
			float x = particle[loop]->x;
			float y = particle[loop]->y;
			float z = particle[loop]->z + zoom;
			//printf(" %d %f \n", loop, particle[loop]->fade);
			//printf(" %d %f  life\n", loop, particle[loop]->life);

			glColor4f(particle[loop]->r, particle[loop]->g, particle[loop]->b, particle[loop]->life);
			glBindTexture(GL_TEXTURE_2D, texture[0]);
			glBegin(GL_TRIANGLE_STRIP);
			glTexCoord2d(1, 1); glVertex3f(x + dx[loop], y + dy[loop], z);
			glTexCoord2d(0, 1); glVertex3f(x - dx[loop], y + dy[loop], z);
			glTexCoord2d(1, 0); glVertex3f(x + dx[loop], y - dy[loop], z);
			glTexCoord2d(0, 0); glVertex3f(x - dx[loop], y - dy[loop], z);
			glEnd();

			
			dx[loop] += const_adder[loop];
			dy[loop] += const_adder[loop];
			
			if (dx[loop] > 7)
			{
				particle[loop]->life -= particle[loop]->fade;

				const_adder[loop] = 0;

				
				particle[loop]->x += particle[loop]->xi / (slowdown * 500);
				particle[loop]->y += particle[loop]->yi / (slowdown * 500);
				particle[loop]->z += particle[loop]->zi / (slowdown * 500);

				//	printf(" %d %f %f %f  he \n", loop, particle[loop]->x, particle[loop]->y, particle[loop]->z);
			}

			if (particle[loop]->life<-0.7f)
			{
				destroy = true;

			}




		}
	}
	//getchar();

}