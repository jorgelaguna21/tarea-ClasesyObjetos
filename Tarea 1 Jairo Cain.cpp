#include <iostream>
#include <string>

using namespace std;

class Empleado {
private:
    //Atributos privados
    string clave;
    string nombre;
    string domicilio;
    double sueldo;
    string jefe;

public:
    Empleado(string clave, string nombre, string domicilio, double sueldo, string jefe) {
        this->clave = clave;
        this->nombre = nombre;
        this->domicilio = domicilio;
        this->sueldo = sueldo;
        this->jefe = jefe;
    }
// Aqui se usan los setter para poder modificar los datos registrados y los getters para obtener los valores.
    void setDomicilio(string nuevoDomicilio) {
        domicilio = nuevoDomicilio;
    }

    void actualizarSueldo(double porcentajeIncremento) {
        sueldo += (sueldo * porcentajeIncremento / 100);
    }

    void imprimirDatos() {
        cout << "Clave: " << clave << endl;
        cout << "Nombre: " << nombre << endl;
        cout << "Domicilio: " << domicilio << endl;
        cout << "Sueldo: " << sueldo << endl;
        cout << "Jefe: " << jefe << endl;
    }

    void setJefe(string nuevoJefe) {
        jefe = nuevoJefe;
    }

    string getClave() {
        return clave;
    }
};

int main() {
    //Ingresé 2 empleados con su codigo y datos
    Empleado JefePlanta("JP001", "Juan Pérez", "Calle 123", 5000, "Gerente");
    Empleado JefePersonal("JP002", "María Rodríguez", "Calle 456", 4000, "Gerente");

    int opcion;
    string clave, nuevoDomicilio, nuevoJefe;
    double porcentajeIncremento;
//menu que tiene 5 opcines, la cual una es para salir.
    while (true) {
        cout << "Menú de opciones:" << endl;
        cout << "1. Cambiar domicilio de un empleado" << endl;
        cout << "2. Actualizar sueldo de un empleado" << endl;
        cout << "3. Imprimir datos de un empleado" << endl;
        cout << "4. Cambiar jefe de un empleado" << endl;
        cout << "5. Salir" << endl;
        cout << "Ingrese su opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                cout << "Ingrese la clave del empleado: ";
                cin >> clave;
                cout << "Ingrese el nuevo domicilio: ";
                cin.ignore();
                getline(cin, nuevoDomicilio);
                if (JefePlanta.getClave() == clave) {
                    JefePlanta.setDomicilio(nuevoDomicilio);
                } else if (JefePersonal.getClave() == clave) {
                    JefePersonal.setDomicilio(nuevoDomicilio);
                } else {
                    cout << "Empleado no encontrado" << endl;
                }
                break;
            case 2:
                cout << "Ingrese la clave del empleado: ";
                cin >> clave;
                cout << "Ingrese el porcentaje de incremento: ";
                cin >> porcentajeIncremento;
                if (JefePlanta.getClave() == clave) {
                    JefePlanta.actualizarSueldo(porcentajeIncremento);
                } else if (JefePersonal.getClave() == clave) {
                    JefePersonal.actualizarSueldo(porcentajeIncremento);
                } else {
                    cout << "Empleado no encontrado" << endl;
                }
                break;
            case 3:
                cout << "Ingrese la clave del empleado: ";
                cin >> clave;
                if (JefePlanta.getClave() == clave) {
                    JefePlanta.imprimirDatos();
                } else if (JefePersonal.getClave() == clave) {
                    JefePersonal.imprimirDatos();
                } else {
                    cout << "Empleado no encontrado" << endl;
                }
                break;
            case 4:
                cout << "Ingrese la clave del empleado: ";
                cin >> clave;
                cout << "Ingrese el nuevo jefe: ";
                cin.ignore();
                getline(cin, nuevoJefe);
                if (JefePlanta.getClave() == clave) {
                    JefePlanta.setJefe(nuevoJefe);
                } else if (JefePersonal.getClave() == clave) {
                    JefePersonal.setJefe(nuevoJefe);
                } else {
                    cout << "Empleado no encontrado" << endl;
                }
                break;
            case 5:
                return 0;
            default:
                cout << "Opción inválida" << endl;
        }
    }

    return 0;
}
