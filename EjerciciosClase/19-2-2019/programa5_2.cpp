#include <iostream> 
#include <vector>
using namespace std;

class Coordenada{
    private:
        double x;
        double y;
    public:
        Coordenada(double = 0, double = 0);
        double obtenerX();
        double obtenerY();
};

class PoligonoIrregular{
    private:
        vector <Coordenada> vertices;
    public:
        PoligonoIrregular();
        void anadeVertice(Coordenada vertice);
        void imprimeVertices();
};

Coordenada::Coordenada(double xx, double yy) : x(xx), y(yy){}

double Coordenada::obtenerX(){
    return x;
}

double Coordenada::obtenerY(){
    return y;
}

PoligonoIrregular::PoligonoIrregular(){};

void PoligonoIrregular::anadeVertice(Coordenada vertice){
    vertices.push_back(vertice);
}

void PoligonoIrregular::imprimeVertices(){
    cout << "Vertices: " << endl;
    for(int i = 0; i < vertices.size(); i++){
        cout << "x = " << vertices[i].obtenerX() << " y = " << vertices[i].obtenerY() << endl;
    }
}

int main(){
    PoligonoIrregular algo;
    algo.anadeVertice(Coordenada(1,1));
    algo.anadeVertice(Coordenada(10,1));
    algo.anadeVertice(Coordenada(1,10));
    algo.anadeVertice(Coordenada(50,10));
    algo.imprimeVertices();
    return 0;
} 