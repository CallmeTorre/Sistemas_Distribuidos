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
        cout << "x = " << (*i).obtenerX() << " y= " << (*i).obtenerY() << " magnitud = " << (*i).obtenerMagnitud()<< endl;
    }
}

void PoligonoIrregular::ordenaA(){
    std::sort(vertices.begin(), vertices.end());
}

int main(){
    PoligonoIrregular poligono;

    srand(time(NULL));

    int i;
	for ( i = 0; i < 5; ++i)
	{	
		double x=0,y=0;
		float r1, r2, r3, r4;
		r1=rand()%200+(-99); r2=rand()%1000; r3=rand()%1000; r4=rand()%200+(-99);
		if(r2<=100){
			while(r2<=100){
				r2=rand()%1000;
				if(((int)r2%100)==0 || ((int)r2%10)==0){
					while(((int)r2%100)==0 || ((int)r2%10)==0){
						r2=rand()%1000;
					}
				}
			}
		}else{
			if(((int)r2%100)==0 || ((int)r2%10)==0){
				while(((int)r2%100)==0 || ((int)r2%10)==0){
					r2=rand()%1000;
				}
			}			
		}
		
		if(r3<=100){
			while(r3<=100){
				r3=rand()%1000;
				if(((int)r3%100)==0 || ((int)r3%10)==0){
					while(((int)r3%100)==0 || ((int)r3%10)==0){
						r3=rand()%1000;
					}
				}
			}
		}else{
			if(((int)r3%100)==0 || ((int)r3%10)==0){
				while(((int)r3%100)==0 || ((int)r3%10)==0){
					r3=rand()%1000;
				}
			}			
		}		
		r2=r2/1000; r3=r3/1000;
		if(r1<0){
			x=r1+(-r2);
		}else{
			x=r1+r2;
		}
		
		if(r4<0){
			y=r4+(-r3);
		}else{
			y=r4+r3;
		}
        float magnitud = sqrt(pow(x, 2) + pow(y, 2));
        poligono.anadeVertice(Coordenada(x, y, magnitud));
    }
    poligono.imprimeVertices();
    poligono.ordenaA();
    cout << "-----------------------------";
    poligono.imprimeVertices();
    return 0;
} 