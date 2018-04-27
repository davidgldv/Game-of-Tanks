#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ncurses.h>
#include <time.h>

#define DELTA_T 0.01
#define N 20

struct TCoord {
    double x;
    double y;
};
struct Move{

     TCoord pos ,
     TCoord vel ,
     TCoord acc ,
     TCoord dir ,

};
int a;
int b;
void CalcularTank(struct TCoord tanks[N]){
    int contador = 0;

    clear();

    a = (COLS * 0.25);
    b = (COLS * 0.5);
    b += a;

    tanks[contador].x = (rand() % a) + 1;
    tanks[contador].y = LINES-1;
    contador++;
    tanks[contador].x = (b + (rand() %a)) - 1 ;
    tanks[contador].y = LINES-1;
}
void PintarTanque(struct TCoord tanks[N]) {

    int i = 0;
    clear();

    for(int f = 0; f < 4; f++){
        for(int c = 0; c < 4; c++)
            for(int i = 0; i < 2; i++)
                mvprintw( (int) tanks[i].y-c, tanks[i].x+f, "0"  ); 

    }


    for(int c = 0; c < 4; c++)
        for(int f = 4; f < 4; f++)
            for(int i = 0; i < 2; i++)
                mvprintw( (int) tanks[i].y-f, tanks[i].x+c, "o" ); 


}
void Actualizar(TCoord pos) {

    mvprintw( (int) pos.y, pos.x, "o");
    refresh();
}

int main(){
    struct TCoord tank[N];

    int jugador = 0;

    srand(time(NULL));
    initscr();
    curs_set(0);

    CalcularTank(tank);

    pos.x = (tank[0].x+4);
    pos.y = (tank[0].y-4);

    PintarTanque(tank);

    while(1){
        PintarTanque(tank);
        /*PreguntarVelyAng(alpha)*/
        sleep(1);
        /*Disparar*/
        /*Comprobar*/
    }

    curs_set(1);
    endwin();

    return EXIT_SUCCESS;
}
