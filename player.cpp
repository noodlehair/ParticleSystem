#include <stdio.h>
#include <stdlib.h>
#include "player.h"
#include "node.h"
 
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <glut.h>
#endif

#define GLUT_DISABLE_ATEXIT_HACK
player::player(float a) { 
	image = new ImageIO("spaceship.ppm");
	upImage = new ImageIO("spaceship1.ppm");
	size = a; 
	glGenTextures(1, &p_tex1);
		textureMapping(p_tex1, upImage);
		glGenTextures(1, &p_tex);
		textureMapping(p_tex, image);
		//glEnable(GL_TEXTURE_2D);
		//glBindTexture(GL_TEXTURE_2D, p_tex);
		printf("PALAYER");
}


void player::textureMapping(GLuint texture, ImageIO* image){

	glEnable(GL_TEXTURE_2D);
	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glBindTexture(GL_TEXTURE_2D, texture);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, image->getWidth(), image->getHeight(), 0, GL_RGB, GL_FLOAT, image->getImageDisplayArray());
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
}

void player::draw(float x, float y, float z){
	glPushAttrib(GL_ALL_ATTRIB_BITS);
	float ambient=1;
	float diffuse=1;
	float specular=1;
	float emission=0;
	float shininess=50;
	GLfloat mat_ambient[]  = {ambient, ambient, ambient, 1.0f};         
        GLfloat mat_diffuse[]  = {diffuse, diffuse, diffuse, 1.0f};         
        GLfloat mat_specular[] = {specular, specular, specular, 1.0f};         
        GLfloat mat_emission[] = {emission, emission, emission, 1.0f};         
        GLfloat mat_shininess  = shininess;           
        glMaterialfv(GL_FRONT, GL_AMBIENT,   mat_ambient);         
        glMaterialfv(GL_FRONT, GL_DIFFUSE,   mat_diffuse);         
        glMaterialfv(GL_FRONT, GL_SPECULAR,  mat_specular);         
        glMaterialfv(GL_FRONT, GL_EMISSION,  mat_emission);         
        glMaterialf (GL_FRONT, GL_SHININESS, mat_shininess);

	glPushMatrix();
	glTranslatef(x, 0, 0);
	glTranslatef(0, y-1, 0);
	glTranslatef(0, 0, z-5);
	glRotatef(45,1,0,0);
	glEnable(GL_TEXTURE_2D);
	
  
    node back1(-0.25, 0.15, 0.25); 
    node back2(-.5, -.35, .25); 
    node back3(.5, -.35, .25); 
    node back4(.25, .15, .25); 
      
    node front1(-.25,.25,-.25); 
    node front2(.25, .25, -.25); 
    node front3(.25,-.25,-.25); 
    node front4(-.25, -.25, -.25); 
  
    node hexA1(0.05, .087, -0.25); 
    node hexA2(0.1, 0, -0.25); 
    node hexA3(0.05, -0.087, -0.25); 
    node hexA4(-0.05, -0.087, -0.25); 
    node hexA5(-0.1, 0, -0.25); 
    node hexA6(-0.05, 0.087, -0.25); 
  
    node hexB1(0.05, .087, -0.75); 
    node hexB2(0.1, 0, -0.75); 
    node hexB3(0.05, -0.087, -0.75); 
    node hexB4(-0.05, -0.087, -0.75); 
    node hexB5(-0.1, 0, -0.75); 
    node hexB6(-0.05, 0.087, -0.75); 
  
    node fa1(0.25, 0.087, -0.25); 
    node fa2(0.25, 0, -0.25); 
    node fa3(0.25, -0.087, -0.25); 
  
    node fb1(-0.25, 0.087, -0.25); 
    node fb2(-0.25, 0, -0.25); 
    node fb3(-0.25, -0.087, -0.25); 
  
    //backside 
	glBindTexture(GL_TEXTURE_2D, p_tex);
	glColor3f(.25, .30, 0.3);
	glBegin(GL_QUADS);
	
	glTexCoord2d(1, 1);
	glVertex3f(back1.x, back1.y, back1.z);
	glTexCoord2d(0, 1);
	glVertex3f(back2.x, back2.y, back2.z);
	glTexCoord2d(1, 0);
	glVertex3f(back3.x, back3.y, back3.z);
	glTexCoord2d(0, 0);
	glVertex3f(back4.x, back4.y, back4.z);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	//frontside 
	glBegin(GL_QUADS);
	
	glColor3f(0.6, 0.1, 0); glVertex3f(front1.x, front1.y, front1.z);
	glColor3f(0.6, 0.1, 0); glVertex3f(front2.x, front2.y, front2.z);
	glColor3f(0.6, 0.1, 0); glVertex3f(fa1.x, fa1.y, fa1.z);
	glColor3f(0.6, 0.1, 0); glVertex3f(fb1.x, fb1.y, fb1.z);

	glColor3f(0.6, 0.1, 0); glVertex3f(fa1.x, fa1.y, fa1.z);
	glColor3f(0.6, 0.1, 0); glVertex3f(fa2.x, fa2.y, fa2.z);
	glColor3f(0.6, 0.1, 0); glVertex3f(hexA2.x, hexA2.y, hexA2.z);
	glColor3f(0.6, 0.1, 0); glVertex3f(hexA1.x, hexA1.y, hexA1.z);

	glColor3f(0.6, 0.1, 0); glVertex3f(fa2.x, fa2.y, fa2.z);
	glColor3f(0.6, 0.1, 0); glVertex3f(fa3.x, fa3.y, fa3.z);
	glColor3f(0.6, 0.1, 0); glVertex3f(hexA3.x, hexA3.y, hexA3.z);
	glColor3f(0.6, 0.1, 0); glVertex3f(hexA2.x, hexA2.y, hexA2.z);

	glColor3f(0.6, 0.1, 0); glVertex3f(fa3.x, fa3.y, fa3.z);
	glColor3f(0.6, 0.1, 0); glVertex3f(front3.x, front3.y, front3.z);
	glColor3f(0.6, 0.1, 0); glVertex3f(front4.x, front4.y, front4.z);
	glColor3f(0.6, 0.1, 0); glVertex3f(fb3.x, fb3.y, fb3.z);

	glColor3f(0.6, 0.1, 0); glVertex3f(hexA5.x, hexA5.y, hexA5.z);
	glColor3f(0.6, 0.1, 0); glVertex3f(hexA4.x, hexA4.y, hexA4.z);
	glColor3f(0.6, 0.1, 0); glVertex3f(fb3.x, fb3.y, fb3.z);
	glColor3f(0.6, 0.1, 0); glVertex3f(fb2.x, fb2.y, fb2.z);

	glColor3f(0.6, 0.1, 0); glVertex3f(hexA5.x, hexA5.y, hexA5.z);
	glColor3f(0.6, 0.1, 0); glVertex3f(fb2.x, fb2.y, fb2.z);
	glColor3f(0.6, 0.1, 0); glVertex3f(fb1.x, fb1.y, fb1.z);
	glColor3f(0.6, 0.1, 0); glVertex3f(hexA6.x, hexA6.y, hexA6.z);
	glEnd();
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, p_tex1);
	//upside 
	glColor3f(.25, .30, 0.3);
	glBegin(GL_QUADS);
	//
	glTexCoord2d(1, 1);
	glVertex3f(back1.x, back1.y, back1.z);
	glTexCoord2d(0, 1);
	glVertex3f(back4.x, back4.y, back4.z);
	glTexCoord2d(1, 0);
	glVertex3f(front2.x, front2.y, front2.z);
	glTexCoord2d(0, 0);
	glVertex3f(front1.x, front1.y, front1.z);
	glEnd();
	glBindTexture(GL_TEXTURE_2D, p_tex);
	//leftside 
	glColor3f(.25, .30, 0.3);
	glBegin(GL_QUADS);
	//
	glTexCoord2d(1, 1);
	glVertex3f(back1.x, back1.y, back1.z);
	glTexCoord2d(0, 1);
	glVertex3f(front1.x, front1.y, front1.z);
	glTexCoord2d(1, 0);
	glVertex3f(front4.x, front4.y, front4.z);
	glTexCoord2d(0, 0);
	glVertex3f(back2.x, back2.y, back2.z);
	glEnd();
	glBindTexture(GL_TEXTURE_2D, p_tex);
	//rightside 
	glColor3f(.25, .30, 0.3);
	glBegin(GL_QUADS);
	//
	glTexCoord2d(1, 1);
	glVertex3f(back4.x, back4.y, back4.z);
	glTexCoord2d(0, 1);
	glVertex3f(back3.x, back3.y, back3.z);
	glTexCoord2d(1, 0);
	glVertex3f(front3.x, front3.y, front3.z);
	glTexCoord2d(0, 0);
	glVertex3f(front2.x, front2.y, front2.z);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	//downside 
	glBegin(GL_QUADS);
	
	glColor3f(.25, .30, 0.3); glVertex3f(back3.x, back3.y, back3.z);
	glColor3f(.25, .30, 0.3); glVertex3f(back2.x, back2.y, back2.z);
	glColor3f(.25, .30, 0.3); glVertex3f(front4.x, front4.y, front4.z);
	glColor3f(.25, .30, 0.3); glVertex3f(front3.x, front3.y, front3.z);
	glEnd();
	//pipe 
	glBegin(GL_QUADS);
	
	glColor3f(0.2, 0.0, 0.0); glVertex3f(hexA1.x, hexA1.y, hexA1.z);
	glColor3f(0.2, 0.0, 0.0); glVertex3f(hexA2.x, hexA2.y, hexA2.z);
	glColor3f(0.2, 0.0, 0.0); glVertex3f(hexB2.x, hexB2.y, hexB2.z);
	glColor3f(0.2, 0.0, 0.0); glVertex3f(hexB1.x, hexB1.y, hexB1.z);

	
	glColor3f(0.2, 0.0, 0.0); glVertex3f(hexB2.x, hexB2.y, hexB2.z);
	glColor3f(0.2, 0.0, 0.0); glVertex3f(hexA2.x, hexA2.y, hexA2.z);
	glColor3f(0.2, 0.0, 0.0); glVertex3f(hexA3.x, hexA3.y, hexA3.z);
	glColor3f(0.2, 0.0, 0.0); glVertex3f(hexB3.x, hexB3.y, hexB3.z);

	
	glColor3f(0.2, 0.0, 0.0); glVertex3f(hexA3.x, hexA3.y, hexA3.z);
	glColor3f(0.2, 0.0, 0.0); glVertex3f(hexA4.x, hexA4.y, hexA4.z);
	glColor3f(0.2, 0.0, 0.0); glVertex3f(hexB4.x, hexB4.y, hexB4.z);
	glColor3f(0.2, 0.0, 0.0); glVertex3f(hexB3.x, hexB3.y, hexB3.z);

	
	glColor3f(0.2, 0.0, 0.0); glVertex3f(hexA4.x, hexA4.y, hexA4.z);
	glColor3f(0.2, 0.0, 0.0); glVertex3f(hexA5.x, hexA5.y, hexA5.z);
	glColor3f(0.2, 0.0, 0.0); glVertex3f(hexB5.x, hexB5.y, hexB5.z);
	glColor3f(0.2, 0.0, 0.0); glVertex3f(hexB4.x, hexB4.y, hexB4.z);

	glColor3f(0.2, 0.0, 0.0); glVertex3f(hexA5.x, hexA5.y, hexA5.z);
	glColor3f(0.2, 0.0, 0.0); glVertex3f(hexA6.x, hexA6.y, hexA6.z);
	glColor3f(0.2, 0.0, 0.0); glVertex3f(hexB6.x, hexB6.y, hexB6.z);
	glColor3f(0.2, 0.0, 0.0); glVertex3f(hexB5.x, hexB5.y, hexB5.z);

	
	glColor3f(0.2, 0.0, 0.0); glVertex3f(hexA6.x, hexA6.y, hexA6.z);
	glColor3f(0.2, 0.0, 0.0); glVertex3f(hexA1.x, hexA1.y, hexA1.z);
	glColor3f(0.2, 0.0, 0.0); glVertex3f(hexB1.x, hexB1.y, hexB1.z);
	glColor3f(0.2, 0.0, 0.0); glVertex3f(hexB6.x, hexB6.y, hexB6.z);

	glEnd();
	glTranslatef(0, 0.4, 0);
	glTranslatef(0, 0, -1);
	glBegin(GL_LINES);

	glColor3f(1, 0, 0); 
	glVertex3f(-0.25, 0, 0);
	glColor3f(1, 0, 0);
	glVertex3f(0.25, 0, 0);
	glColor3f(1, 0, 0);
	glVertex3f(0, 0.25, 0);
	glColor3f(1, 0, 0);
	glVertex3f(0, -0.25, 0);
	glEnd();
	
/*
	//glTranslatef(x, 0, 0);
	glTranslatef(0, 1, 0);
	glTranslatef(0, 0, 0);

	glBegin(GL_LINES);

	glColor3f(1, 0, 0); 
	glVertex3f(-0.5, 0, 0);
	glVertex3f(0.5, 0, 0);

	glVertex3f(0, 0.5, 0);
	glVertex3f(0, -0.5, 0);

	/*glEnable(GL_LINE_STIPPLE);  
    glLineStipple(1,0xAAAA);  
    glBegin(GL_LINES);  
         
    glVertex2f(0.0,0.0);  
    glVertex2f(0.0,0.5);  
    //glDisable(GL_LINE_STIPPLE);  
    glEnd();  
    glDisable(GL_LINE_STIPPLE);  
    glBegin(GL_LINE_LOOP);  
    //draw a circle with specific points.  
    int circle_points = 100;  
    float angle = 0;  
    int i = 0;  
      
    for(i = 0;i<circle_points;i++) {  
        // draw with yellow and black in turn.  
        if(i%2==0){  
          glColor3f(1.0,1.0,0.0);         
        }else{  
          glColor3f(0.0,0.0,0.0);  
        }  
        angle = 2*i*PI/circle_points;  
        //the cos and sin will occupy hole screen.  
        glVertex2f(0.5*cos(angle),0.5*sin(angle));      
    }  */
    //glEnd(); 
	


    glPopMatrix(); 
	glPopAttrib();
	 
	}