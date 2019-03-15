Cliente: Cliente.cpp PaqueteDatagrama.o SocketDatagrama.o
	g++ Cliente.cpp PaqueteDatagrama.o SocketDatagrama.o -o Cliente
SocketDatagrama.o: SocketDatagrama.cpp PaqueteDatagrama.o SocketDatagrama.h
	g++ SocketDatagrama.cpp -c
PaqueteDatagrama.o: PaqueteDatagrama.cpp PaqueteDatagrama.h
	g++ PaqueteDatagrama.cpp -c