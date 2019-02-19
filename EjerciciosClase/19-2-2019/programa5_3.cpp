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
        static int numVertices;
    public:
        PoligonoIrregular();
        void anadeVertice(Coordenada vertice);
        void imprimeVertices();
        static int getNumVertices();
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
    numVertices ++;
    return;
}

void PoligonoIrregular::imprimeVertices(){
    cout << "Vertices: " << endl;
    for(int i = 0; i < vertices.size(); i++){
        cout << "x = " << vertices[i].obtenerX() << " y = " << vertices[i].obtenerY() << endl;
    }
}

int PoligonoIrregular::numVertices = 0;

int PoligonoIrregular::getNumVertices(){
    return numVertices;
}

int main(){
    /* Para probar con reserve tienes que comentar push_back, 
    descomentar reserve y la asignacion del i-esimo elemento del arreglo*/
    vector <PoligonoIrregular> vector_poligonos;
    //vector_poligonos.reserve(100);
    cout << "Capacidad inicial: " << vector_poligonos.capacity() << endl;
    cout << "Tamano inicial: " << vector_poligonos.size() << endl;
    for(int i = 0; i < 100; i++){
        PoligonoIrregular algo;
        for(int j = 0; j < rand(); j++){
            algo.anadeVertice(Coordenada(rand(),rand()));
        }
        //vector_poligonos[i] = algo;
        vector_poligonos.push_back(algo);
    }
    PoligonoIrregular algo;
    cout << "Capacidad final: " << vector_poligonos.capacity() << endl;
    cout << "Tamano final: " << vector_poligonos.size() << endl;
    cout << "Vertices Totales " << algo.getNumVertices() << endl;
    return 0;
} 