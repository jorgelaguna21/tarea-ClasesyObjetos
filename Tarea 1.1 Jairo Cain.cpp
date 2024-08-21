#include <iostream>
#include <cstring>

using namespace std;

class Materia {
private:
    int Clave;
    char Nombre[50];
    char ProfesorTit[50];
    char LibroTexto[50];

public:
    // Constructor
    Materia(int clave, const char* nombre, const char* profesorTit, const char* libroTexto) {
        Clave = clave;
        strcpy(Nombre, nombre);
        strcpy(ProfesorTit, profesorTit);
        strcpy(LibroTexto, libroTexto);
    }

    // Metodos
    void Imprime() {
        cout << "Clave: " << Clave << endl;
        cout << "Nombre: " << Nombre << endl;
        cout << "Profesor Titular: " << ProfesorTit << endl;
        cout << "Libro de Texto: " << LibroTexto << endl;
    }

    void CambiaClave(int nuevaClave) {
        Clave = nuevaClave;
    }

    void CambiaProfe(const char* nuevoProfesorTit) {
        strcpy(ProfesorTit, nuevoProfesorTit);
    }
};

int main() {
    // Declaracion de objetos
    Materia Programacion(101, "Programacion I", "Juan Perez", "Fundamentos de Programacion");
    Materia BasesDatos(102, "Bases de Datos I", "Maria Rodriguez", "Sistemas de Gestion de Bases de Datos");

    int opcion;
    do {
        cout << "\nMenu:" << endl;
        cout << "1. Imprimir datos de Programacion" << endl;
        cout << "2. Imprimir datos de Bases de Datos" << endl;
        cout << "3. Cambiar clave de Programacion" << endl;
        cout << "4. Cambiar profesor de Bases de Datos" << endl;
        cout << "5. Salir" << endl;
        cout << "Ingrese una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                Programacion.Imprime();
                break;
            case 2:
                BasesDatos.Imprime();
                break;
            case 3: {
                int nuevaClave;
                cout << "Ingrese la nueva clave de Programacion: ";
                cin >> nuevaClave;
                Programacion.CambiaClave(nuevaClave);
                break;
            }
            case 4: {
                char nuevoProfesor[50];
                cout << "Ingrese el nuevo profesor de Bases de Datos: ";
                cin.ignore(); // Limpiar el buffer de entrada
                cin.getline(nuevoProfesor, 50);
                BasesDatos.CambiaProfe(nuevoProfesor);
                break;
            }
            case 5:
                cout << "Saliendo del programa..." << endl;
                break;
            default:
                cout << "Opcion invalida." << endl;
        }
    } while (opcion != 5);

    return 0;
}
