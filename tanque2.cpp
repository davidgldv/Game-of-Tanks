#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<math.h>
#include <ncurses.h>

#define N 2
#define DELTA_T 0.01
typedef struct {
	double x;
	double y;
}Coord2;

typedef struct {
	Coord2 pos;
	Coord2 vel;
	Coord2 acc;
	Coord2  dir;
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
	jugador[0].body.pos.y = 1;
	jugador[1].body.pos.x = (b +(rand() %a) -1);
	jugador[1].body.pos.y = 1;

}

void pintar(Player jugador[N]){

	mvprintw( LINES -jugador[0].body.pos.y, jugador[0].body.pos.x,"[][][][]");
	mvprintw( LINES -jugador[1].body.pos.y, jugador[1].body.pos.x,"[][][][]");
}

Coord2 preguntardisparo(int turno){
	Coord2 res;
	double vel ,alpha ; 
	mvprintw( 1, 2, "Jugador %i ", turno % 2 + 1 );
	mvprintw( 2, 2, "========== ");
	mvprintw( 4, 2, "Velocidad: " );
	scanw(" %lf", &vel);
	mvprintw( 6, 2, "Angulo:" );
	scanw(" %lf", &alpha);

	res.x = vel * cos(alpha / 360. * 2 * M_PI);
	res.y = vel * sin(alpha / 360. * 2 * M_PI);

	return res;
	
}


void disparar(int turno,Movil bala) {
	Coord2 ini;
    	do{
           if(turno %2 == 0){
	    ini = bala.pos;
            bala.vel.x += bala.acc.x * DELTA_T;
            bala.vel.y += bala.acc.y * DELTA_T;
            bala.pos.x += bala.vel.x * DELTA_T;
            bala.pos.y += bala.vel.y * DELTA_T;
	  }
    
           if(turno %2 > 0){
	    ini = bala.pos;
            bala.vel.x -= bala.acc.x * DELTA_T;
            bala.vel.y += bala.acc.y * DELTA_T;
            bala.pos.x -= bala.vel.x * DELTA_T;
            bala.pos.y += bala.vel.y * DELTA_T;
	  }
            mvprintw( LINES - ini.y, ini.x, " ");
            mvprintw( LINES - bala.pos.y, bala.pos.x, "O");
            refresh();
            usleep(1000000 * DELTA_T);
    	}while(bala.pos.y > 0);	
}
void comprobar(int turno,Movil bala, Player jugador[N]){
	int a = (COLS *0.5);
	int b = (LINES *0.5);
	if(turno % 2 == 0 && bala.pos == jugador[1].body.pos){
		clear();
		mvprintw(b,a, "El jugador 1 ha ganado");
	}
	if(turno % 2 > 0 && bala.pos == jugador[0].body.pos){
		clear();
		mvprintw(b,a, "El jugador 2 ha ganado");
	}

}
int main () {
	Movil bala = {{0.,0.},{0.,0.},{0.,-9.8},{0.,0.}};
	int turno = 0;
	Player jugador[N] ={
		{{ {5.,1.},{0.,0.},{0.,0.},{1.,0.} }, 3},
		{{ {50.,1.},{0.,0.},{0.,0.},{-1.,0.} }, 3}
	};
	clear();

	initscr();
	curs_set(0);
	calculartanques(jugador);

	while(1){
		pintar(jugador);
		refresh();
		sleep(1);
		bala.pos=jugador[turno % 2].body.pos;
		bala.vel=preguntardisparo(turno);
		disparar(turno,bala);
		comprobar(turno,bala,jugador);
		turno++;
		clear();
	}
	endwin();

	return 0;
}
