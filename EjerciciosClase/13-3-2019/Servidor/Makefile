Servidor: Servidor.cpp PaqueteDatagrama.o SocketDatagrama.o
	g++ Servidor.cpp PaqueteDatagrama.o SocketDatagrama.o -o Servidor
SocketDatagrama.o: SocketDatagrama.cpp PaqueteDatagrama.o SocketDatagrama.h
	g++ SocketDatagrama.cpp -c
PaqueteDatagrama.o: PaqueteDatagrama.cpp PaqueteDatagrama.h
	g++ PaqueteDatagrama.cpp -c