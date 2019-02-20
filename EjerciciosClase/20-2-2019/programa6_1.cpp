#include <iostream> 
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;

class Coordenada{
    private:
        double x;
        double y;
        double magnitud;
    public:
        Coordenada(double = 0, double = 0, double = 0);
        double obtenerX();
        double obtenerY();
        double obtenerMagnitud();
        bool operator< (const Coordenada &other) const {
        return magnitud < other.magnitud;
    }
};

class PoligonoIrregular{
    private:
        vector <Coordenada> vertices;
    public:
        PoligonoIrregular();
        void anadeVertice(Coordenada vertice);
        void imprimeVertices();
        void ordenaA();
};

Coordenada::Coordenada(double xx, double yy, double mag) : x(xx), y(yy), magnitud(mag){}

double Coordenada::obtenerX(){
    return x;
}

double Coordenada::obtenerY(){
    return y;
}

double Coordenada::obtenerMagnitud(){
    return magnitud;
}

PoligonoIrregular::PoligonoIrregular(){};

void PoligonoIrregular::anadeVertice(Coordenada vertice){
    vertices.push_back(vertice);
}

void PoligonoIrregular::imprimeVertices(){
    std::vector<Coordenada>::iterator i;
    cout << "Vertices: " << endl;
    for(i = vertices.begin(); i != vertices.end(); i++){
        cout << "x = " << (*i).obtenerX() << " y= " << (*i).obtenerY() << endl;
        cout << "magnitud = " << (*i).obtenerMagnitud() << endl;
    }
}

void PoligonoIrregular::ordenaA(){
    std::sort(vertices.begin(), vertices.end());
}

vector<int> genRandom(){
    vector<int> randvector(200);
    for(int i = -100;i < 0; i++){
        randvector.push_back(i);
    }
    for(int j = 1; j < 100; j++){
        randvector.push_back(j);
    }
    return randvector;
}

int main(){
    PoligonoIrregular poligono;
    vector<int> randvector = genRandom();
    for(int i = 0; i < 20; i++){
        int coord1 = randvector[rand() % randvector.size()];
        int coord2 = randvector[rand() % randvector.size()];
        int magnitud = sqrt(pow(coord1, 2) + pow(coord2, 2));
        poligono.anadeVertice(Coordenada(coord1, coord2, magnitud));
    }
    poligono.ordenaA();
    poligono.imprimeVertices();
    return 0;
} 