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
void CalcularTank(struct TCoord tanks[N]);
void PintarTanque(struct TCoord tanks[N]);
void Trayectoria(TCoord *pos, TCoord *vel, TCoord acc);
void Actualizar(TCoord pos);


int a, b;

int main(){
    struct TCoord tank[N];
    struct TCoord pos = { 0., 0.  },
                  vel = { 4., 50.  },
                  acc = { 0., -9.80665  };

    srand(time(NULL));
    initscr();
    curs_set(0);

    CalcularTank(tank);

    pos.x = (tank[0].x+4);
    pos.y = (tank[0].y-4);

	PintarTanque(tank);

    while(1){
        Trayectoria(&pos, &vel, acc);
	PintarTanque(tank);
        Actualizar(pos);
    }

    curs_set(1);
    endwin();

    return EXIT_SUCCESS;
}
void Actualizar(TCoord pos) {
	
	mvprintw( (int) pos.y, pos.x, "o");
	refresh();
}

void Trayectoria(TCoord *pos, TCoord *vel, TCoord acc){
    vel->x += acc.x * DELTA_T;
    vel->y += acc.y * DELTA_T;
    pos->x += vel->x * DELTA_T;
    pos->y += vel->y * DELTA_T;

}
void CalcularTank(struct TCoord tanks[N]){
    int contador = 0;

    clear();

    a = (COLS * 0.25);
    b = (COLS * 0.5);
    b += a;

    tanks[contador].x = rand() % a;
    tanks[contador].y = LINES-1;
    contador++;
    tanks[contador].x = b + (rand() %a) ;
    tanks[contador].y = LINES-1;
}

void PintarTanque(struct TCoord tanks[N]) {

    int i = 0;
    clear();


    for(int f = 0; f < 4; f++){
        for(int c = 0; c < 4; c++)
            for(int i = 0; i < 2; i++)
                mvprintw( (int) tanks[i].y-c, tanks[i].x+f, "0" ); 

    }
}
