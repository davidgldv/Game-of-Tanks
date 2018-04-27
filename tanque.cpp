#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ncurses.h>
#include <time.h>

#define DELTA_T 0.01
#define N 20

struct Coord {
    double x;
    double y;
};
struct Move{

     Coord pos ,
     Coord vel ,
     Coord acc ,
     Coord dir ,

};
int a;
int b;
void calcular_tank(struct Coord tanks[N]){
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
void pintar_tanque(struct Coord tanks[N]) {

    int i = 0;
    clear();

    for(int f = 0; f < 4; f++){
        for(int c = 0; c < 4; c++)
            for(int i = 0; i < 2; i++)
                mvprintw( (int) tanks[i].y-c, tanks[i].x+f, "0"  )

    }


    for(int c = 0; c < 4; c++)
        for(int f = 4; f < 4; f++)
            for(int i = 0; i < 2; i++)
                mvprintw( (int) tanks[i].y-f, tanks[i].x+c, "o" ); 


}
 preguntar_disparo(){

      mvprintf("Jugador %i",)

 }
int main(){
    struct Coord tank[N];
    int jugador = 0;
    int turno = 0;

    srand(time(NULL));
    initscr();
    curs_set(0);

    calculartank(tank);

    Coord.pos.x = (tank[0].x+4);
    Coord.pos.y = (tank[0].y-4);

    pintar_tanque(tank);

    while(1){
        pintar_tanque(tank);
        /*PreguntarVelyAng(alpha)*/
        sleep(1);
        /*Disparar*/
        /*Comprobar*/
    }

    curs_set(1);
    endwin();

    return EXIT_SUCCESS;
}
