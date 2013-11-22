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
player::player(float a):size(a){};

void player::draw(float x, float y, float z){
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


	glPushMatrix();
	glRotatef(45,1,0,0);
	glBegin(GL_QUADS); 
  
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
    glColor3f(0.2,0,0); 
    glVertex3f(back1.x, back1.y, back1.z); 
    glVertex3f(back2.x, back2.y, back2.z); 
    glVertex3f(back3.x, back3.y, back3.z); 
    glVertex3f(back4.x, back4.y, back4.z); 
  
    //frontside 
    glColor3f(0.6, 0.1, 0); 
    glVertex3f(front1.x, front1.y, front1.z); 
    glVertex3f(front2.x, front2.y, front2.z); 
    glVertex3f(fa1.x, fa1.y, fa1.z); 
    glVertex3f(fb1.x, fb1.y, fb1.z); 
  
    glVertex3f(fa1.x, fa1.y, fa1.z); 
    glVertex3f(fa2.x, fa2.y, fa2.z); 
    glVertex3f(hexA2.x, hexA2.y, hexA2.z); 
    glVertex3f(hexA1.x, hexA1.y, hexA1.z); 
  
    glVertex3f(fa2.x, fa2.y, fa2.z); 
    glVertex3f(fa3.x, fa3.y, fa3.z); 
    glVertex3f(hexA3.x, hexA3.y, hexA3.z); 
    glVertex3f(hexA2.x, hexA2.y, hexA2.z); 
  
    glVertex3f(fa3.x, fa3.y, fa3.z); 
    glVertex3f(front3.x, front3.y, front3.z); 
    glVertex3f(front4.x, front4.y, front4.z); 
    glVertex3f(fb3.x, fb3.y, fb3.z); 
  
    glVertex3f(hexA5.x, hexA5.y, hexA5.z); 
    glVertex3f(hexA4.x, hexA4.y, hexA4.z); 
    glVertex3f(fb3.x, fb3.y, fb3.z); 
    glVertex3f(fb2.x, fb2.y, fb2.z); 
      
    glVertex3f(hexA5.x, hexA5.y, hexA5.z); 
    glVertex3f(fb2.x, fb2.y, fb2.z); 
    glVertex3f(fb1.x, fb1.y, fb1.z); 
    glVertex3f(hexA6.x, hexA6.y, hexA6.z); 
  
    //upside 
    glColor3f(.25, .30, 0.3); 
    glVertex3f(back1.x, back1.y, back1.z); 
    glVertex3f(back4.x, back4.y, back4.z); 
    glVertex3f(front2.x, front2.y, front2.z); 
    glVertex3f(front1.x, front1.y, front1.z); 
  
    //leftside 
    glColor3f(25, 25, 100); 
    glVertex3f(back1.x, back1.y, back1.z); 
    glVertex3f(front1.x, front1.y, front1.z); 
    glVertex3f(front4.x, front4.y, front4.z); 
    glVertex3f(back2.x, back2.y, back2.z); 
  
    //rightside 
    glColor3f(25, 25, 100); 
    glVertex3f(back4.x, back4.y, back4.z); 
    glVertex3f(back3.x, back3.y, back3.z); 
    glVertex3f(front3.x, front3.y, front3.z); 
    glVertex3f(front2.x, front2.y, front2.z); 
  
    //downside 
    glColor3f(.25, .30, 0.3); 
    glVertex3f(back3.x, back3.y, back3.z); 
    glVertex3f(back2.x, back2.y, back2.z); 
    glVertex3f(front4.x, front4.y, front4.z); 
    glVertex3f(front3.x, front3.y, front3.z); 
  
    //pipe 
    glColor3f(0.1, 0.1, 0.5); 
    glVertex3f(hexA1.x, hexA1.y, hexA1.z); 
    glVertex3f(hexA2.x, hexA2.y, hexA2.z); 
    glVertex3f(hexB2.x, hexB2.y, hexB2.z); 
    glVertex3f(hexB1.x, hexB1.y, hexB1.z); 
  
    glColor3f(0.1, 0.2, 0.5); 
    glVertex3f(hexB2.x, hexB2.y, hexB2.z); 
    glVertex3f(hexA2.x, hexA2.y, hexA2.z); 
    glVertex3f(hexA3.x, hexA3.y, hexA3.z); 
    glVertex3f(hexB3.x, hexB3.y, hexB3.z); 
  
    glColor3f(0.1, 0.3, 0.5); 
    glVertex3f(hexA3.x, hexA3.y, hexA3.z); 
    glVertex3f(hexA4.x, hexA4.y, hexA4.z); 
    glVertex3f(hexB4.x, hexB4.y, hexB4.z); 
    glVertex3f(hexB3.x, hexB3.y, hexB3.z); 
  
    glColor3f(0.1, 0.4, 0.5); 
    glVertex3f(hexA4.x, hexA4.y, hexA4.z); 
    glVertex3f(hexA5.x, hexA5.y, hexA5.z); 
    glVertex3f(hexB5.x, hexB5.y, hexB5.z); 
    glVertex3f(hexB4.x, hexB4.y, hexB4.z); 
  
    glColor3f(0.1, 0.5, 0.5); 
    glVertex3f(hexA5.x, hexA5.y, hexA5.z); 
    glVertex3f(hexA6.x, hexA6.y, hexA6.z); 
    glVertex3f(hexB6.x, hexB6.y, hexB6.z); 
    glVertex3f(hexB5.x, hexB5.y, hexB5.z); 
  
    glColor3f(0.1, 0.6, 0.5); 
    glVertex3f(hexA6.x, hexA6.y, hexA6.z); 
    glVertex3f(hexA1.x, hexA1.y, hexA1.z); 
    glVertex3f(hexB1.x, hexB1.y, hexB1.z); 
    glVertex3f(hexB6.x, hexB6.y, hexB6.z); 
  
    glEnd(); 
	glPopMatrix();

	glTranslatef(0, 1, 0);
	glTranslatef(0, 0, -1);
	glBegin(GL_LINES);

	glColor3f(1, 0, 0); 
	glVertex3f(-0.25, 0, 0);
	glVertex3f(0.25, 0, 0);

	glVertex3f(0, 0.25, 0);
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
	}