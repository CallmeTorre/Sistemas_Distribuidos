#ifndef FRACCION_H_
#define FRACCION_H_

class Fraccion{
    private:
        int numerador;
        int denominador;
        int gcd(int, int);
    public:
        Fraccion(int = 1, int = 1);
        double obtenResultado();
        void reducirFraccion();
};
#endif