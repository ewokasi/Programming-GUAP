
#include <iostream>

#include <GL/glut.h> // opengl
#include "SOIL/SOIL.h"
#include <cstdio>

#include "read_texture.h"

char title[] = "BOX 3D";

GLfloat angle_y = 0.0f;
GLfloat angle_x = 0.0f;
GLfloat pos_x = 0.0f;
GLfloat pos_y = 0.0f;
GLfloat zoom = -7.0f;
GLuint texture;
GLuint texture2;
int refreshMills = 15;

void display() {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glMatrixMode(GL_MODELVIEW);

  glLoadIdentity();
  glTranslatef(pos_x, pos_y, zoom);
  glRotatef(angle_x, 0.0f, 1.0f, 0.0f);
  glRotatef(angle_y, 1.0f, 0.0f, 0.0f);

  glEnable(GL_TEXTURE_2D);
  glEnable(GL_LIGHT0);
  glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);

  glBindTexture (GL_TEXTURE_2D, texture);

  glBegin(GL_TRIANGLES);
      glTexCoord2f(0.0f, 1.0f); glVertex3f( 0.0f, 1.0f, 0.0f);
      glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, -1.0f, 1.0f);
      glTexCoord2f(0.25f, 0.0f); glVertex3f(1.0f, -1.0f, 1.0f);

      // Right
      glTexCoord2f(0.0f, 1.0f); glVertex3f(0.0f, 1.0f, 0.0f);
      glTexCoord2f(0.75f, 0.0f); glVertex3f(1.0f, -1.0f, 1.0f);
      glTexCoord2f(1, 0.0f);  glVertex3f(1.0f, -1.0f, -1.0f);

      // Back
      glTexCoord2f(0.0f, 1.0f); glVertex3f(0.0f, 1.0f, 0.0f);
      glTexCoord2f(0.5f, 0.0f); glVertex3f(1.0f, -1.0f, -1.0f);
      glTexCoord2f(0.75f, 0.0f);  glVertex3f(-1.0f, -1.0f, -1.0f);

      // Left
      glTexCoord2f(0.0f, 1.0f);  glVertex3f( 0.0f, 1.0f, 0.0f);
      glTexCoord2f(0.25f, 0.0f);  glVertex3f(-1.0f,-1.0f,-1.0f);
      glTexCoord2f(0.4f, 0.0f); glVertex3f(-1.0f,-1.0f, 1.0f);

  glEnd();

  glTranslatef(0.0f, -2.0f, 0.0f);
  glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
  glRotatef(90.0f, 1.0f, 0.0f, 0.0f);

  glBindTexture (GL_TEXTURE_2D, texture2);
  glBegin(GL_QUADS);

    glTexCoord2f(0.0f, 0.0f); glVertex3f( 1.0f, 1.0f, -1.0f);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f, 1.0f, -1.0f);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f, 1.0f,  1.0f);
    glTexCoord2f(1.0f, 0.0f); glVertex3f( 1.0f, 1.0f,  1.0f);


    glTexCoord2f(0.0f, 0.0f); glVertex3f( 1.0f, -1.0f,  1.0f);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f, -1.0f,  1.0f);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f, -1.0f, -1.0f);
    glTexCoord2f(1.0f, 0.0f); glVertex3f( 1.0f, -1.0f, -1.0f);


    glTexCoord2f(0.0f, 0.0f); glVertex3f( 1.0f,  1.0f, 1.0f);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f,  1.0f, 1.0f);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f, -1.0f, 1.0f);
    glTexCoord2f(1.0f, 0.0f); glVertex3f( 1.0f, -1.0f, 1.0f);


    glTexCoord2f(0.0f, 0.0f); glVertex3f( 1.0f, -1.0f, -1.0f);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f, -1.0f, -1.0f);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f,  1.0f, -1.0f);
    glTexCoord2f(1.0f, 0.0f); glVertex3f( 1.0f,  1.0f, -1.0f);


    glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f,  1.0f,  1.0f);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f,  1.0f, -1.0f);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f, -1.0f, -1.0f);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f,  1.0f);


    glTexCoord2f(0.0f, 0.0f); glVertex3f(1.0f,  1.0f, -1.0f);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(1.0f,  1.0f,  1.0f);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(1.0f, -1.0f,  1.0f);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(1.0f, -1.0f, -1.0f);
  glEnd();

  glFlush();
  glDisable(GL_TEXTURE_2D);

  glPopMatrix();
  glutSwapBuffers();
}

// инициализируем всякий кал
void initGL() {
  glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // цвет фона
  glClearDepth(1.0f);                   // глубина фона
  glEnable(GL_DEPTH_TEST);   // врубаем depth test
  glDepthFunc(GL_LEQUAL);    // тип depth test
  glShadeModel(GL_SMOOTH);   //
  glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);  //
}

void process_Normal_Keys(unsigned char key, int x, int y) {

    switch (key) {

    // rot_x
    case ('a'):
        angle_x -= 10;
        break;

    case ('d'):
        angle_x += 10;
        break;

    // rot_y
    case ('w'):
        angle_y -= 10;
        break;

    case ('s'):
        angle_y += 10;
        break;

    // zoom
    case ('z'):
        zoom += 1;
        break;

    case ('x'):
        zoom -= 1;
        break;

    default:
        break;

    // pos_x
    case ('q'):
        pos_x -= 0.1;
        break;

    case ('e'):
        pos_x += 0.1;
        break;

    // pos_y
    case ('r'):
        pos_y += 0.1;
        break;

    case ('f'):
        pos_y -= 0.1;
        break;

    }

}

void reshape(GLsizei width, GLsizei height) {

  if (height == 0) height = 1;
  GLfloat aspect = (GLfloat)width / (GLfloat)height;


  glViewport(0, 0, width, height);

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();

  gluPerspective(45.0f, aspect, 0.1f, 100.0f);
}

void timer(int value) {
   glutPostRedisplay();
   glutTimerFunc(refreshMills, timer, 0);
}


int main(int argc, char** argv) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
  glutInitWindowSize(640, 480); // размеры окна
  glutInitWindowPosition(50, 50); // позиция окна на экране
  glutCreateWindow(title); // создаём окно

  initGL();
  //texture = LoadTexture_test( "box_image.bmp" , 540, 540);
  //texture = LoadTexture_test( "box_image0.bmp" , 316, 316);
  //texture = LoadTexture( "box_image1.bmp" , 316, 316);
  //texture = LoadTexture( "Crate.bmp" , 256, 256);
  //texture = LoadTexture_test( "anime.bmp" , 640, 832);

  texture = SOIL_load_OGL_texture("abeme.bmp", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_INVERT_Y);
  texture2 = SOIL_load_OGL_texture("box_image.bmp", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_INVERT_Y);

  //glTexParameterfv(GL_TEXTURE_2D, GL_TEXTURE_BORDER_COLOR, texture);


  glutDisplayFunc(display);
  glutReshapeFunc(reshape);


  glutTimerFunc(0, timer, 0);
  glutKeyboardFunc(process_Normal_Keys);

  glutMainLoop();

  return 0;
}
