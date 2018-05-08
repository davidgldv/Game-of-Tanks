#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<math.h>
#include <ncurses.h>

#define N 2

typedef struct {
    double x;
    double y;
}Coord2;

typedef struct {
    Coord2 pos;
    Coord2 vel;
    Coord2 acc;
    int  dir;
}Movil;

typedef struct {
    Movil body;
    int life;
}Player;

void  calculartanques(Player jugador[N]){
  int  a=(COLS * 0.25);
  int  b=(COLS * 0.5);
    b+=a;
    jugador[0].body.pos.x = (rand() %a +1);
    jugador[0].body.pos.y = LINES -1;
    jugador[1].body.pos.x = (a +(rand() %a) -1);
    jugador[1].body.pos.y = LINES -1;

};

void pintar(Player jugador[N]){

    mvprintw(LINES - jugador[0].body.pos.y, jugador[0].body.pos.x,"[][][][]");
    mvprintw(LINES - jugador[1].body.pos.y, jugador[1].body.pos.x,"[][][][]");
};

//preguntardisparo(){}
//disparar(){}
int main () {
    Movil bala = {{0.,0.},{0.,0.},{0.,-9.8},0};

    Player jugador[N] ={
    {{ {0.,1.},{0.,0.},{0.,0.},1 }, 100},
    {{ {0.,1.},{0.,0.},{0.,0.},-1 }, 100}
    };
    clear();

    initscr();
    curs_set(0);
    calculartanques(jugador);

    while(1){
    pintar(jugador);
    }
    sleep(1);
    refresh();
    endwin();

    return 0;
}
