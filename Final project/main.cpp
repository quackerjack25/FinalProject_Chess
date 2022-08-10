#include <GL\freeglut.h>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include "RgbImage.h"

using namespace std;
ifstream f;				// file stream game play
bool turn = true;		// true for white player
bool endOfGame = false; // end of game indicator

/*  Create checkerboard texture  */
#define checkImageWidth 64		// width of each square
#define checkImageHeight 64		// hright of each square

std::string board[8][8] = {	{"WR", "WN", "WB", "WQ", "WK", "WB", "WN", "WR"}, 
							{"WP", "WP", "WP", "WP", "WP", "WP", "WP", "WP"},
							{" ", " ", " ", " ", " ", " ", " ", " "},
							{" ", " ", " ", " ", " ", " ", " ", " "},
							{" ", " ", " ", " ", " ", " ", " ", " "},
							{" ", " ", " ", " ", " ", " ", " ", " "},
							{"BP", "BP", "BP", "BP", "BP", "BP", "BP", "BP"},
							{"BR", "BN", "BB", "BQ", "BK", "BB", "BN", "BR"} 
					};
static GLubyte checkImage[checkImageHeight][checkImageWidth][4];
RgbImage whitePawn( "whitePawn1.bmp" );
RgbImage whiteRook( "whiteRook1.bmp" );
RgbImage whiteBishop( "whiteBishop1.bmp" );
RgbImage whiteKnight( "whiteKnight1.bmp" );
RgbImage whiteKing( "whiteKing.bmp" );
RgbImage whiteQueen( "whiteQueen1.bmp" );

RgbImage blackPawn( "blackPawn1.bmp" );
RgbImage blackRook( "blackRook1.bmp" );
RgbImage blackBishop( "blackBishop1.bmp" );
RgbImage blackKnight( "blackKnight1.bmp" );
RgbImage blackKing( "blackKing1.bmp" );
RgbImage blackQueen( "blackQueen1.bmp" );

void init(void)
{    
	glClearColor(0, 1, 1, 0);
	// Choosing the type of projection
	glMatrixMode(GL_PROJECTION);
	// for setting the transformation which here is 2D
	gluOrtho2D(0, 800, 0,600);
}
void drawSquare(GLint x1, GLint y1, GLint x2, GLint y2, GLint x3, GLint y3, GLint x4, GLint y4, bool white)
{
	// if color is white then draw white box and change value of color = 1
	if (white)
	{
		glColor3ub(239, 216, 182); // white color value is yellow
	}
	// if color is not white then draw black box and change value of color light green
	else
	{
		
		glColor3ub(179, 135, 101); // black color value is light green
	}

	// Draw Square
	glBegin(GL_POLYGON);
		glVertex2i(x1, y1);
		glVertex2i(x2, y2);
		glVertex2i(x3, y3);
		glVertex2i(x4, y4);
	glEnd();
}

void chessboard()
{
	glClear(GL_COLOR_BUFFER_BIT); // Clear display window
	GLint x, y;
	bool white = true;

	for (x = 0; x <= 800; x += 100)
	{
		for (y = 0; y <= 600; y += 75)
		{
			drawSquare(x, y + 75, x + 100, y + 75, x + 100, y, x, y, white);
			white = 1-white;
		}
	}
}
void displayBoard() {
	cout << "\n\n";
	for (int i=0; i<8; i++) {
		for (int j=0; j<8; j++)
			cout << board[i][j] << "(" << i << "," << j << ")"" ";
		cout << endl;
	}
}

void display(void)
{
   	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
   	chessboard();
   	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_BLEND);
   	glPixelZoom(1, 1);
   	for (int i=0; i<8; i++) {
   		for (int j=0; j<8; j++) {
   			// White Pieces
   			if (board[i][j] == "WR") {
   				glRasterPos2i(25 + j*100, 5 + i*75);
   				glDrawPixels(whiteRook.GetNumCols(), whiteRook.GetNumRows(), GL_RGBA, GL_UNSIGNED_BYTE, whiteRook.ImageData());
			}
   			if (board[i][j] == "WN") {
   				glRasterPos2i(25 + j*100, 5 + i*75);
   				glDrawPixels(whiteKnight.GetNumCols(), whiteKnight.GetNumRows(), GL_RGBA, GL_UNSIGNED_BYTE, whiteKnight.ImageData());
			   }
   			if (board[i][j] == "WB") {
   				glRasterPos2i(25 + j*100, 5 + i*75);
   				glDrawPixels(whiteBishop.GetNumCols(), whiteBishop.GetNumRows(), GL_RGBA, GL_UNSIGNED_BYTE, whiteBishop.ImageData());
   				
			   }
   			if (board[i][j] == "WQ") {
   				glRasterPos2i(25 + j*100, 5 + i*75);
   				glDrawPixels(whiteQueen.GetNumCols(), whiteQueen.GetNumRows(), GL_RGBA, GL_UNSIGNED_BYTE, whiteQueen.ImageData());
			   }
   			if (board[i][j] == "WK") {
   				glRasterPos2i(25 + j*100, 5 + i*75);
   				glDrawPixels(whiteKing.GetNumCols(), whiteKing.GetNumRows(), GL_RGBA, GL_UNSIGNED_BYTE, whiteKing.ImageData());
			   }
   			if (board[i][j] == "WP") {
   				glRasterPos2i(25 + j*100, 5 + i*75);
   				glDrawPixels(whitePawn.GetNumCols(), whitePawn.GetNumRows(), GL_RGBA, GL_UNSIGNED_BYTE, whitePawn.ImageData());
			   }
			// Black Pieces
   			if (board[i][j] == "BR") {
   				glRasterPos2i(25 + j*100, 5 + i*75);
   				glDrawPixels(blackRook.GetNumCols(), blackRook.GetNumRows(), GL_RGBA, GL_UNSIGNED_BYTE, blackRook.ImageData());
			}
   			if (board[i][j] == "BN") {
   				glRasterPos2i(25 + j*100, 5 + i*75);
   				glDrawPixels(blackKnight.GetNumCols(), blackKnight.GetNumRows(), GL_RGBA, GL_UNSIGNED_BYTE, blackKnight.ImageData());
			   }
   			if (board[i][j] == "BB") {
   				glRasterPos2i(25 + j*100, 5 + i*75);
   				glDrawPixels(blackBishop.GetNumCols(), blackBishop.GetNumRows(), GL_RGBA, GL_UNSIGNED_BYTE, blackBishop.ImageData());
			   }
   			if (board[i][j] == "BQ") {
   				glRasterPos2i(25 + j*100, 5 + i*75);
   				glDrawPixels(blackQueen.GetNumCols(), blackQueen.GetNumRows(), GL_RGBA, GL_UNSIGNED_BYTE, blackQueen.ImageData());
			   }
   			if (board[i][j] == "BK") {
   				glRasterPos2i(25 + j*100, 5 + i*75);
   				glDrawPixels(blackKing.GetNumCols(), blackKing.GetNumRows(), GL_RGBA, GL_UNSIGNED_BYTE, blackKing.ImageData());
			   }
   			if (board[i][j] == "BP") {
   				glRasterPos2i(25 + j*100, 5 + i*75);
   				glDrawPixels(blackPawn.GetNumCols(), blackPawn.GetNumRows(), GL_RGBA, GL_UNSIGNED_BYTE, blackPawn.ImageData());
			   }

		}
	}
   	glFlush();
}

void mouseClick(int button, int state, int x, int y) {
	string move, t;
	int fromi, fromj, toi, toj;
	char piece, fromSquare, fromNo, toSquare, toNo;
	if (endOfGame) return;
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
		f >> move;
		if (move[0] == '#') {
			cout << "\n\nEnd of game: ";
			switch (move[1]) {
				case 'B': cout << "Black Win\n";; break;
				case 'W': cout << "White Win\n"; break;
				case 'D': cout << "Draw\n"; break;
				default:
					cout << "Unecognized ending\n";
			}
			endOfGame = true;
			return;
		}
		else if (turn) cout << move;
			 else cout << "   " << move << endl;
		
		fromSquare = move[0];
		fromNo = move[1];
		toSquare = move[3];
		toNo = move[4];
		
		fromi = fromSquare - 'a';
		fromj = fromNo - '0' - 1;
		toi = toSquare - 'a';
		toj = toNo - '0' - 1;
		
		move = board[fromj][fromi];
		board[fromj][fromi]= " ";
		board[toj][toi] = move;
		turn = !turn;
			
		glutPostRedisplay();
	}
}

void reshape(int w, int h)
{
   glViewport(0, 0, (GLsizei) w, (GLsizei) h);
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   gluPerspective(60.0, (GLfloat) w/(GLfloat) h, 1.0, 30.0);
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
   glTranslatef(0.0, 0.0, -3.6);
}

void keyboard (unsigned char key, int x, int y)
{
   switch (key) {
      case 27:
         exit(0);
         break;
      default:
         break;
   }
}

int main(int argc, char** argv)
{
	string filename;
	cout << "Game file name: ";
	cin >> filename;
	f.open(filename.c_str());
	if (!f) {
		cout << "File open error: " << filename << endl;
		return 0;
	}
	// Initialize GLUT
	glutInit(&argc, argv);
	// Set display mode
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	// Set top - left display window position.
	glutInitWindowPosition(700, 100);
	// Set display window width and height
	glutInitWindowSize(800, 600);
	// Create display window with the given title
	glutCreateWindow("Chess Board using OpenGL in C++");
	// Execute initialization procedure
	init();
   glutDisplayFunc(display);
   glutMouseFunc(mouseClick);
   glutKeyboardFunc(keyboard);
   glutMainLoop();
   return 0; 
}
