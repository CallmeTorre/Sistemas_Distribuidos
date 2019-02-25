#ifndef ORTOEDRO_H_
#define ORTOEDRO_H_
#include "Coordenada.h"

class Ortoedro{
    private:
        Coordenada cercanaOrigen;
        Coordenada alejadaOrigen;
    public:
        Ortoedro(Coordenada cercanaOrigen, Coordenada alejadaOrigen);
        double obtieneArea();
        double obtieneVolumen();
};
#endif