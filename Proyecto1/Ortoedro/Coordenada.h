#ifndef COORDENADA_H_
#define COORDENADA_H_

class Coordenada{
    private:
        double x;
        double y;
        double z;
    public:
        Coordenada(double x = 0, double y = 0, double z = 0);
        double obtenerX();
        double obtenerY();
        double obtenerZ();
};
#endif