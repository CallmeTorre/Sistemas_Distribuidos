#ifndef COORDENADA_H_
#define COORDENADA_H_

class Coordenada{
    private:
        double radius;
        double angle;
    public:
        Coordenada(double radius = 0, double angle = 0);
        double obtenerX();
        double obtenerY();
};
#endif