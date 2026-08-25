#include <iostream>
using namespace std;
class Contador {
		public:   int valor;
							static int total;
    // Constructor
    Contador(int v = 0) : valor(v) {
		    total++;
		    cout << "Contador creado. total de Contadores = " << total << endl;
		    }
    // Destructor
    ~Contador() {
		    cout << "Contador destruido. valor = " << valor << endl;
		    }
    // Método para incrementar el contador de instancia
    void incrementar() {
		    valor++;
		    }
		};
// Definición e inicialización del miembro estático
int Contador::total = 0;
int main() {
		// Crea varios objetos en el stack
		Contador c1(5);
		Contador c2(10);
    // Inspecciona con el depurador las direcciones de c1 y c2.
    // Observa que 'total' es compartido entre todos los objetos.
    c1.incrementar();
    c2.incrementar();
    cout << "c1.valor = " << c1.valor << endl;    cout << "c2.valor = " << c2.valor << endl;
    cout << "Contador::total = " << Contador::total << endl;
    // Puedes también crear un objeto dinámico para comparar:
    Contador* c3 = new Contador(15);
    c3->incrementar();
    cout << "c3->valor = " << c3->valor << endl;
    // Coloca breakpoints en la creación de cada objeto y en las llamadas a 'incrementar()'
    // Observa cómo el miembro estático 'total' se comparte y no se almacena en el stack de cada objeto.
    delete c3;
    return 0;
    }