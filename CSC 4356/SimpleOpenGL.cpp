// assignment1.cpp : Defines the entry point for the console application.
//Timothy Rine
//CSC 4356
//Assignment 1
//9-20-18

#include "pch.h"
#include "glut.h"
#define _USE_MATH_DEFINES
#include <math.h>
#include <time.h>       

int win_H, win_W;
time_t timer;
struct tm curr_time;


void
reshape(int w, int h)
{

	glViewport(0, 0, w, h);       /* Establish viewing area to cover entire window. */
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, w, 0, h, -1, 1);
	glScalef(1, -1, 1);
	glTranslatef(0, -h, 0);
}

void
display(void)
{

	glClear(GL_COLOR_BUFFER_BIT);

	// Insert your own code here

	//Initialize circle variables and set the radius to 150
	float x1, y1, x2, y2;
	float triangleFanAngle;
	double radius = 150;

	//Set the variables for the center to be (256,256)
	x1 = 256, y1 = 256;

	//Make the circle white
	glColor3f(1, 1, 1);

	glPushMatrix();
	//Begin making the triangles and set the starting point to the center, (256,256)
	glBegin(GL_TRIANGLE_FAN);
	glVertex2f(x1, y1);

	//Loop from 1 to 360, creating the triangles that form the circle (base of the clock) incrementing by 1 each time for the smoothest circumfrence
	//I couldn't figure out how to do make the clock hands move so I am submitting what I could get. It draws a stationary clock.
	//From trigonometry we know that you can find the (x, y) points around a circle if you know the radius and the angle. The radius was given (150) and the angles are ones that we create in the loop.
	//X-coordinate: x = radius *  cos(angle)
	//Y-coordinate: y = radius *  sin(angle)
	for (triangleFanAngle = 1; triangleFanAngle < 361; triangleFanAngle += 1)
	{
		x2 = x1 + cos(triangleFanAngle)*radius;
		y2 = y1 + sin(triangleFanAngle)*radius;
		glVertex2f(x2, y2);
	}

	glEnd();
	glPopMatrix();

	//Initialize hour, minute, second variables to the current time (int)
	int hour = curr_time.tm_hour;
	int minute = curr_time.tm_min;
	int second = curr_time.tm_sec;

	//Convert these variables from int to float
	float hourf = hour * 30.0 + minute / 2.0 + second / 120.0;
	float minf = minute * 6.0 + second / 10.0;
	float secf = second * 6.0;

	//Initialize the hour hand

	glPushMatrix();
	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_TRIANGLE_STRIP);
	glVertex2f(266, 256);
	glVertex2f(246, 256);
	glVertex2f(261, 176);
	glVertex2f(251, 176);

	glRotatef(hourf, 1, 1, 0);
	glTranslatef(256, 256, 0);

	glEnd();
	glPopMatrix();

	//Initialize the minute hand

	glPushMatrix();
	glColor3f(0.0, 1.0, 0.0);
	glBegin(GL_TRIANGLES);
	glVertex2f(262, 256);
	glVertex2f(250, 256);
	glVertex2f(256, 196);

	glRotatef(minf, 1, 1, 0);
	glTranslatef(256, 256, 0);

	glEnd();
	glPopMatrix();

	//Initialize the second hand

	glPushMatrix();
	glLineWidth(2.5);
	glColor3f(0.0, 0.0, 1.0);
	glBegin(GL_LINES);
	glVertex3f(256, 256, 0);
	glVertex3f(256, 146, 0);

	glEnd();
	glPopMatrix();

	// Your code ends here

	glutSwapBuffers(); // swap the back buffer to front


}

void TimeEvent(int time_val)
{
	time(&timer); // get the current date and time from system
	localtime_s(&curr_time, &timer);
	glutPostRedisplay();
	glutTimerFunc(30, TimeEvent, 1);// By using a timed event, your application should run at the same speed on any machine.
}

int
main(int argc, char **argv)
{
	GLenum type;

	glutInit(&argc, argv);

	type = GLUT_DEPTH;
	type |= GLUT_RGB;
	type |= GLUT_DOUBLE;
	glutInitDisplayMode(type);

	time(&timer); // get current date and time
	localtime_s(&curr_time, &timer);

	// set window size and create a window for rendering
	win_W = 512;
	win_H = 512;
	glutInitWindowSize(win_H, win_W);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("My clock");

	glutDisplayFunc(display);
	glutReshapeFunc(reshape);

	glutTimerFunc(30, TimeEvent, 1);
	glutMainLoop();
	return 0;
}

