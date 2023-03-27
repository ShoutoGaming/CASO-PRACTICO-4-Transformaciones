#include <GL/glut.h> 


float vertices[4][2] = { {-0.5, -0.5}, {0.5, -0.5}, {0.5, 0.5}, {-0.5, 0.5} };


float translate_x = 0.0, translate_y = 0.0;
float scale_x = 1.0, scale_y = 1.0;
float angle = 0.0;


void drawPolygon() {
    glClear(GL_COLOR_BUFFER_BIT); 

    glMatrixMode(GL_MODELVIEW); 
    glLoadIdentity();

    glTranslatef(translate_x, translate_y, 0.0);
    glRotatef(angle, 0.0, 0.0, 1.0);
    glScalef(scale_x, scale_y, 1.0);

    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_POLYGON);
    for (int i = 0; i < 4; i++) {
        glVertex2f(vertices[i][0], vertices[i][1]);
    }
    glEnd();

    glFlush();
}


void mouseClick(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
 
        translate_x = ((float)x - 250.0) / 250.0;
        translate_y = -((float)y - 250.0) / 250.0;
        scale_x = ((float)x - 250.0) / 250.0 + 1.0;
        scale_y = -((float)y - 250.0) / 250.0 + 1.0;
        angle = ((float)x - 250.0) * 180.0 / 250.0;
    }

    glutPostRedisplay();
}


int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Polígono");

    glClearColor(0.0, 0.0, 0.0, 0.0); 
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0); 

    glutDisplayFunc(drawPolygon); 
    glutMouseFunc(mouseClick); 

    glutMainLoop(); 

    return 0; 
}
