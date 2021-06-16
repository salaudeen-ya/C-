#include <iostream>
#include <conio.h>
#include <time.h>
#include <windows.h>

using namespace std;

enum eDir {STOP = 0, LEFT = 1, UPLEFT = 2, DOWNLEFT = 3, RIGHT = 4, UPRIGHT = 5, DOWNRIGHT = 6};

class cBall{
    private:
        int x, y;
        int originX, originY;
        eDir direction;

    public:
        cBall(int positionX, int positionY){
            x = positionX;
            y = positionY;
            originX = positionX;
            originY = positionY;
            direction = STOP;
        }
        void reset() {
            x = originX;
            y = originY;
            direction = STOP;
        }
        void changeDir(eDir d){
            direction = d;
        }
        void randomDir(){
            direction = (eDir)((rand()%6) + 1);
        }
        inline int getX() { return x; }
        inline int getY() { return y; }
        inline eDir getDir() { return direction; }
        void move(){
            switch (direction){
                case STOP:
                    break;
                case LEFT:
                    x--;
                    break;
                case RIGHT:
                    x++;
                    break;
                case UPLEFT:
                    x--, y--;
                    break;
                case DOWNLEFT:
                    x--, y++;
                case UPRIGHT:
                    x++, y--;
                case DOWNRIGHT:
                    x++, y++;
                    break;
                default:
                    break;

            }
        }

        friend ostream &operator<<(ostream &o, cBall c){
            o << "Ball [" << c.x << ", " << c.y << "][" << c.direction << "]";
            return o;
        }

};

class Paddle {
    private:
        int x,y;
        int originX, originY;
    public:
        Paddle() { x = y = 0; }
        Paddle(int positionX, int positionY) : Paddle() {
            originX = positionX;
            originY = positionY;
            x = positionX;
            y = positionY;
        }
        void reset() {
            x = originX;
            y = originY;
        }
        inline int getX() { return x; }
        inline int getY() { return y; }
        inline void moveUp() { y--; }
        inline void moveDown() { y++; }
        friend ostream &operator<<(ostream &o, Paddle p){
            o << "Paddle [" << p.x << ", " << p.y << "]";
            return o;
        }



};

class GameManager{
    private:
        int width, height, score1, score2;
        bool quit;
        char up1, up2, down1, down2;
        cBall *ball;
        Paddle *p1;
        Paddle *p2;
    public:
        GameManager(int w, int h) {
            srand(time(NULL));
            quit = false;
            up1 = 'w';
            up2 = 'i';
            down1 = 's';
            down2 = 'k';
            score1 = score2 = 0;
            width = w;
            height = h;
            ball = new cBall (w/2, h/2);
            p1 = new Paddle (1, h/2 - 3);
            p2 = new Paddle (w-2, h/2 - 3);
        }
        ~GameManager(){
            delete ball, p1, p2;
        }
        void scoreup(Paddle *player){
            if (player == p1)
                score1++;
            if (player == p2)
                score2++;
            ball-> reset();
            p1-> reset();
            p2-> reset();
        }

        void ClearScreen() {
        COORD cursorPosition;
        cursorPosition.X = 0;
        cursorPosition.Y = 0;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorPosition);
        }

        void draw() {
            ClearScreen();
            for (int i = 0; i < width + 2; i++){
                cout << "\xB2";
            }
            cout << endl;

            for (int i = 0; i < height; i++){
                for (int j = 0; j < width; j++){
                    int ballX = ball-> getX();
                    int ballY = ball-> getY();
                    int player1X = p1-> getX();
                    int player2X = p2-> getX();
                    int player1Y = p1 -> getY();
                    int player2Y = p2-> getY();
                    if (j == 0)
                        cout << "\xB2";

                    if (ballX == j && ballY == i)
                        cout << "0";
                    else if (player1X == j && player1Y  == i)
                        cout << "\xDB";
                    else if (player1X == j && player1Y + 1 == i)
                        cout << "\xDB";
                    else if (player2X == j && player1Y + 2 == i)
                        cout << "\xDB";
                    else if (player2X == j && player1Y + 3 == i)
                        cout << "\xDB";

                    else if (player1X == j && player2Y  == i)
                        cout << "\xDB";
                    else if (player1X == j && player2Y + 1 == i)
                        cout << "\xDB";
                    else if (player2X == j && player2Y + 2 == i)
                        cout << "\xDB";
                    else if (player2X == j && player2Y + 3 == i)
                        cout << "\xDB";
                    else
                        cout << " ";

                    if (j == width - 1)
                        cout << "\xB2";
                }
                cout << endl;
            }

            cout << endl;

            for (int i = 0; i < width + 2; i++){
                cout << "\xB2";
            }
            cout << endl;
            cout << "Score 1: " << score1 << endl << "Score 2: " << score2 << endl;

        }

        void input(){
            ball-> move();
             int ballX = ball-> getX();
             int ballY = ball-> getY();
             int player1X = p1-> getX();
             int player2X = p2-> getX();
             int player1Y = p1 -> getY();
             int player2Y = p2-> getY();

             if (_kbhit()){
                char current = _getch();
                if(current == up1){
                    if(player1Y > 0)
                        p1-> moveUp();
                }
                if (current == up2){
                    if (player2Y > 0)
                        p2-> moveUp();
                }
                if(current == down1){
                    if (player1Y + 4 < height)
                        p1->moveDown();
                }
                if (current == down2){
                    if (player2Y + 4 < height)
                        p2 -> moveDown();
                }
                if (ball->getDir() == STOP)
                    ball->randomDir();
                if (current == 'q')
                    quit = true;
             }

        }

        void logic(){

              int ballX = ball-> getX();
              int ballY = ball-> getY();
              int player1X = p1-> getX();
              int player2X = p2-> getX();
              int player1Y = p1 -> getY();
              int player2Y = p2-> getY();

              for (int i = 0; i < 4; i++)
                if (ballX == player1X + 1)  // to bounce off the paddle
                    if(ballY == player1Y + i)
                        ball->changeDir((eDir)((rand()%3) + 4));

            for (int i = 0; i < 4; i++)
                if (ballX == player2X + 1)  // to bounce off the paddle
                    if(ballY == player2Y + i)
                        ball->changeDir((eDir)((rand()%3) + 1));

            if (ballY == height - 1)
                ball->changeDir(ball->getDir()== DOWNRIGHT ? UPRIGHT : UPLEFT);

            if (ballY == 0)
                ball->changeDir(ball->getDir()== UPRIGHT ? DOWNRIGHT : DOWNLEFT);

            if (ballX == 0)
                scoreup(p2);
            if (ballX = width - 1)
                scoreup(p1);
        }

        void run(){
            while (!quit){
                draw();
                input();
                logic();
            }
        }
};


int main()
{
    GameManager gm (40, 20);
    gm.run();

    return 0;
}
