
#include <SDL2/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>


#include <stdio.h>
#include <stdlib.h>

SDL_Window* displayWindow;
void Display_InitGL()
{
    glClearColor( 0.0f, 0.0f, 0.0f, 0.0f );
    
 }
 /* Fun��o de renderiza��o */
void Display_Render()
{
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
      glBegin(GL_TRIANGLES);
		//glColor3d(1, 1, 1);
		glVertex3f(-0.5, -0.5, 0);
		//glColor3d(1, 0, 0);
		glVertex3f(0.5, -0.5, 0);
		//cglColor3d(0, 1, 0);
		glVertex3f(0.0, 0.5, 0);
    glEnd();

    SDL_GL_SwapWindow(displayWindow);
}
 
 /* La�o principal */
int
main()
{
    SDL_Init(SDL_INIT_VIDEO);

    SDL_Renderer* displayRenderer;

	int flags = SDL_WINDOW_OPENGL;

	atexit(SDL_Quit);
	
    SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 5);
    SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 5);
    SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 5);
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 16);
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

    SDL_CreateWindowAndRenderer(800, 600, flags,&displayWindow, &displayRenderer);

	SDL_GL_CreateContext(displayWindow);
    
    Display_InitGL();
    
    Display_Render();
    
    SDL_Delay(5000);
    SDL_Quit();
    
    return 0;
}
