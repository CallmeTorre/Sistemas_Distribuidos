#ifndef FECHA_H_
#define FECHA_H_

class Fecha{
    private:
        int dia;
        int mes;
        int anio;
        int array_algo[5000];
    public:
        Fecha(int = 3, int = 4, int = 2014); 
        void inicializaFecha(int, int, int); 
        void muestraFecha();
        int convierte();
        bool leapyr();
        int countleapyr();
}; 
#endif