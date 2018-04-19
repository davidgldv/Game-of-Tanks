#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ncurse.h>

#define DELTA_T 0.01

struct TCoord {
    double x;
    double y;
};
void CalcularTank();
void interfaz();
void selecjugador();
void selecVelyAng();
void disparar();
void comprobar();
int main(){
    struct TCoord pos = { 0., 0.  },
                  vel = { 0., 0..  },
                  acc = { 0., -9.80665  };

    CalcularTanK();
    while(1){
        interfaz();
        selecjugador();
        selecVelocidadyAngulo();
        disparar();
        comprobar();

    }

    return EXIT_SUCCESS;
}
