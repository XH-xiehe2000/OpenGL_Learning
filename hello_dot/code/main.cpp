#include <stdio.h>
#include <gl/glew.h>     // GLEW��չ��,�������Ҫ����freeglut.hǰ
#include <gl/freeglut.h> // freeGLUTͼ�ο�
#include "opengl_math.h" 

GLuint VBO;

static void RenderScenceCB() {
	glClear(GL_COLOR_BUFFER_BIT);

	// ��GL_ARRAY_BUFFER������
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	// ���߹�����������bufer�е�����
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);

	// ��ʼ���Ƽ���ͼ��(����һ����)
	glDrawArrays(GL_POINTS, 0, 1);

	// ����ǰ�󻺴�
	glutSwapBuffers();
}
static void CreateVertexBuffer()
{
	// ��������һ������Ķ�������
	Vector3f Vertices[1];
	// ����������Ļ����
	LoadVector3(Vertices[0], 0.0f, 0.0f, 0.0f);

	// ����������
	glGenBuffers(1, &VBO);
	// ��GL_ARRAY_BUFFER������
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	// �󶨶�������
	glBufferData(GL_ARRAY_BUFFER, sizeof(Vertices), Vertices, GL_STATIC_DRAW);
}

int main(int argc, char ** argv) {

	// ��ʼ��GLUT
	glutInit(&argc, argv);

	// ��ʾģʽ��˫���塢RGBA
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);

	// ��������
	glutInitWindowSize(480, 320);      // ���ڳߴ�
	glutInitWindowPosition(100, 100);  // ����λ��
	glutCreateWindow("Hello dot");   // ���ڱ���

									   // ��ʼ��Ⱦ
	glutDisplayFunc(RenderScenceCB);

	// ���GLEW�Ƿ����������Ҫ��GLUT��ʼ��֮��
	GLenum res = glewInit();
	if (res != GLEW_OK) {
		fprintf(stderr, "Error: '%s'\n", glewGetErrorString(res));
		return 1;
	}

	// ������պ����ɫֵ
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

	// �������㻺����
	CreateVertexBuffer();

	// ��ʼGLUT���ڲ�ѭ��
	glutMainLoop();

	return 0;
}