#include <GL/glut.h>
#include <gl/gl.h>
#include <math.h>

// Fungsi menggambar elips (oval horizontal)
void drawEllipse(float cx, float cy, float a, float b, int num_segments) {
    glBegin(GL_POLYGON);
    for (int i = 0; i < num_segments; i++) {
        float theta = 2.0f * 3.14159f * float(i) / float(num_segments);
        float x = a * cosf(theta);
        float y = b * sinf(theta);
        glVertex2f(cx + x, cy + y);
    }
    glEnd();
}
// Fungsi menggambar lingkaran
void drawCircle(float cx, float cy, float r, int num_segments) {
    glBegin(GL_POLYGON);
    for (int i = 0; i < num_segments; i++) {
        float theta = 2.0f * 3.14159f * float(i) / float(num_segments);
        float x = r * cosf(theta);
        float y = r * sinf(theta);
        glVertex2f(cx + x, cy + y);
    }
    glEnd();
}

void drawWheel(float cx, float cy) {
    // **Roda (Hitam)**
    glColor3f(0.0, 0.0, 0.0);
    drawCircle(cx, cy, 0.1, 100);

    // **Velg (Abu-abu)**
    glColor3f(0.5, 0.5, 0.5);
    drawCircle(cx, cy, 0.04, 50);

    // **Jari-jari Velg**
    glColor3f(0.8, 0.8, 0.8);
    glBegin(GL_LINES);
    for (int i = 0; i < 6; i++) {
        float angle = 2.0f * 3.14159f * float(i) / 6;
        float x = 0.04 * cosf(angle);
        float y = 0.04 * sinf(angle);
        glVertex2f(cx, cy);
        glVertex2f(cx + x, cy + y);
    }
    glEnd();
}
void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Badan Mobil
    glColor3f(1.0, 3.0, 0.0); // Warna kuning 
    glBegin(GL_POLYGON);
    glVertex2f(-0.6, -0.2);
    glVertex2f(0.6, -0.2);
    glVertex2f(0.6, 0.1);
    glVertex2f(-0.6, 0.1);
    glEnd();

    // Atap Mobil
    glColor3f(0.0, 0.0, 1.0); // Warna biru
    glBegin(GL_POLYGON);
    glVertex2f(-0.3, 0.1);
    glVertex2f(0.3, 0.1);
    glVertex2f(0.2, 0.4);
    glVertex2f(-0.2, 0.4);
    glEnd();

    // Jendela Kiri
    glColor3f(0.7, 0.9, 1.0); // Warna kaca
    glBegin(GL_POLYGON);
    glVertex2f(-0.2, 0.2);
    glVertex2f(-0.05, 0.2);
    glVertex2f(-0.05, 0.35);
    glVertex2f(-0.2, 0.35);
    glEnd();

    // Jendela Kanan
    glBegin(GL_POLYGON);
    glVertex2f(0.05, 0.2);
    glVertex2f(0.2, 0.2);
    glVertex2f(0.2, 0.35);
    glVertex2f(0.05, 0.35);
    glEnd();
    
    // Gagang Pintu Kiri (Oval Horizontal)
    glColor3f(0.3, 0.3, 0.3); // Warna abu-abu gelap
    drawEllipse(-0.12, 0.05, 0.05, 0.015, 50);

    // Gagang Pintu Kanan (Oval Horizontal)
    drawEllipse(0.12, 0.05, 0.05, 0.015, 50);


    // Lampu Depan Kanan
    glColor3f(0.8, 0.9, 1.0); // Warna biru
    glBegin(GL_POLYGON);
    glVertex2f(0.6, 0.0);
    glVertex2f(0.65, 0.05);
    glVertex2f(0.65, -0.05);
    glVertex2f(0.6, -0.05);
    glEnd();
    
    // Roda dengan Velg
    drawWheel(-0.4, -0.3); // Roda kiri
    drawWheel(0.4, -0.3);  // Roda kanan

    glFlush();
    
}

// Latar belakang putih
void init() {
    glClearColor(1.0, 1.0, 1.0, 1.0); 
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1, 1, -1, 1);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Mobil OpenGL");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
