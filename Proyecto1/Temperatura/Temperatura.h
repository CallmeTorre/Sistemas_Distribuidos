#ifndef TEMPERATURA_H_
#define TEMPERATURA_H_

class Temperatura{
    private:
        float grados;
    public:
        Temperatura(float = 0);
        void setTempKelvin(float);
        void setTempFarenheit(float);
        void setTempCelsius(float);
        void printTempKelvin();
        void printTempFarenheit();
        void printTempCelsius();
};
#endif