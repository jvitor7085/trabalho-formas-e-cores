#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>

// Função callback de redesenho da janela de visualização{
void Desenha(void)
{
	printf("*** Callback de redesenho da tela\n");
	
	// Define a cor de fundo de tela como branco
	glClearColor(1.0f, 1.0f, 1.0f, 0.0f);
	// Limpa a janela de visualização com a cor de fundo definida
	glClear(GL_COLOR_BUFFER_BIT);
	// Exibe o desenho na janela
	glFlush();
}

// Função callback chamada para gerenciar eventos de teclas
void Teclado (unsigned char tecla, int x, int y)  
{
	printf("*** Tratamento de teclas comuns\n");
	printf(">>> Tecla: %c\n",tecla);

	if (tecla == 27) 
		exit(0);
}

// Função callback chamada para gerenciar eventos de teclas especiais(F1,PgDn,...)
void TeclasEspeciais (int tecla, int x, int y)  
{
	printf("*** Tratamento de teclas especiais\n");
	switch (tecla)
	{
		case GLUT_KEY_F1:	printf(">>> Tecla F1 pressionada\n");
							//MenuCor(0);
							break;
		case GLUT_KEY_F2:	printf(">>> Tecla F2 pressionada\n");
							//MenuCor(1);
							break;
		case GLUT_KEY_F3:	printf(">>> Tecla F3 pressionada\n");
							//MenuCor(2);
							break;
		case GLUT_KEY_F4:	printf(">>> Tecla F4 pressionada\n");
							//MenuFormas(0);
							break;
		case GLUT_KEY_F5:	printf(">>> Tecla F5 pressionada\n");
							//MenuFormas(1);
							break;
		case GLUT_KEY_F6:	printf(">>> Tecla F6 pressionada\n");
							//MenuFormas(2);
							break;
	}
}

// Função que trata a opção selecionada do menu principal
void MenuPrincipal(int op) {

}

// Função que trata a opção selecionada do menu "Forma"
void MenuFormas(int op)
{
	printf("*** Menu FORMAS: ");	
	switch(op) {
		case 0:
			printf("Opcao QUADRADO");
				glClearColor(1, 1, 1, 0);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0, 0, 0);
	
	glBegin(GL_QUADS);
		glVertex3f(-0.5, -0.5, 0);
		glVertex3f(-0.5, 0.5, 0);
		glVertex3f(0.5, 0.5, 0);
		glVertex3f(0.5, -0.5, 0);
	glEnd();
	
	glFlush();
			break;
		case 1:
			
			
			printf("Opcao TRIANGULO");
				glClearColor(1, 1, 1, 0);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0, 0, 0);
	
	glBegin(GL_TRIANGLES);
		glVertex3f(-0.5, -0.5, 0);
		glVertex3f(0.0, 0.5, 0);
		glVertex3f(0.5, -0.5, 0);
	glEnd();
	
	glFlush();
			break;
		case 2:
			printf("Opcao LOSANGO");
				glClearColor(1, 1, 1, 0);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0, 0, 0);
	
	glBegin(GL_QUADS);
		glVertex3f(0.0, 0.5, 0);
		glVertex3f(0.5, 0.0, 0);
		glVertex3f(0.0,-0.5, 0);
		glVertex3f(-0.5,0.0, 0);
	glEnd();
	
	glFlush();
			break;
	}
	printf("\n");
}

// Função que trata a opção selecionada do menu "Cor"
void MenuCor(int op)
{
	printf("*** Menu COR: ");	
	switch(op) {
		case 0:
			printf("Opcao VERMELHO");
			glClearColor(1,0,0,0);
			glClear(GL_COLOR_BUFFER_BIT);
			break;
			
		case 1:
			printf("Opcao VERDE");
			glClearColor(0, 1, 0, 0);
			glClear(GL_COLOR_BUFFER_BIT);
			break;
			
		case 2:
			printf("Opcao AZUL");
			glClearColor(0, 0, 1, 0);
			glClear(GL_COLOR_BUFFER_BIT);
			break;
	}
	glFlush();
	printf("\n");
}

// Função responsável por criar os menus
void CriaMenu() 
{
	int menu,submenu1,submenu2;

	// Cria submenu para seleção de cor
	submenu1 = glutCreateMenu(MenuCor);
	glutAddMenuEntry("Vermelho (F1)",0);
	glutAddMenuEntry("Verde (F2)",1);
	glutAddMenuEntry("Azul (F3)",2);

	// Cria submenu para seleção de formas
	submenu2 = glutCreateMenu(MenuFormas);
	glutAddMenuEntry("Quadrado (F4)",0);
	glutAddMenuEntry("Triângulo (F5)",1);
	glutAddMenuEntry("Losango (F6)",2);

	// Cria menu principal...
	menu = glutCreateMenu(MenuPrincipal);
	// ... e adiciona ambos submenus a ele
	glutAddSubMenu("Cores",submenu1);
	glutAddSubMenu("Formas",submenu2);

	// Associa o menu ao botão direito do mouse
	glutAttachMenu(GLUT_RIGHT_BUTTON);
}

// Programa Principal
int main(int argc, char** argv)
{
    // Inicia a GLUT (OpenGlut) com os parâmetros argc e argv
    glutInit(&argc, argv);
    
	// Define do modo de operação da GLUT
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

	// Especifica a posição inicial da janela GLUT
	glutInitWindowPosition(0,0);

	// Especifica o tamanho inicial em pixels da janela GLUT
	glutInitWindowSize(500,400);

	// Cria a janela passando como argumento o título da mesma
	glutCreateWindow("Trabalho 16/12/2021");

	// Registra a função callback de redesenho da janela de visualização
	glutDisplayFunc (Desenha);

	// Registra a função callback para tratamento das teclas ASCII
	glutKeyboardFunc (Teclado);

	// Registra a função callback para tratamento das teclas especiais
	glutSpecialFunc (TeclasEspeciais);

	// Chama função para criar o menu
	CriaMenu();
	

	// Inicia o processamento e aguarda interações do usuário
	glutMainLoop();

	return 0;
}
