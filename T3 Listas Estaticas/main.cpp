#include <iostream>
#include <string>

using namespace std;

class Empleado
{
private:
    int ClaveEmpleado;
    string Nombre;
    string Domicilio;
    float Sueldo;
    string ReportA;

public:
    Empleado(int C = 0, string N = "", string D = "", float S = 0.0, string R = "")
        : ClaveEmpleado(C), Nombre(N), Domicilio(D), Sueldo(S), ReportA(R) {}

    // Setters
    void SetClaveEmpleado(int C) { ClaveEmpleado = C; }
    void SetNombre(string N) { Nombre = N; }
    void SetDomicilio(string D) { Domicilio = D; }
    void SetSueldo(float S) { Sueldo = S; }
    void SetReportA(string R) { ReportA = R; }

    // Getters
    int GetClaveEmpleado() const { return ClaveEmpleado; }
    string GetNombre() const { return Nombre; }
    string GetDomicilio() const { return Domicilio; }
    float GetSueldo() const { return Sueldo; }
    string GetReportA() const { return ReportA; }

    // Overload operators
    friend ostream &operator<<(ostream &o, const Empleado &e)
    {
        o << "Clave: " << e.ClaveEmpleado << endl;
        o << "Nombre: " << e.Nombre << endl;
        o << "Domicilio: " << e.Domicilio << endl;
        o << "Sueldo: $" << e.Sueldo << endl;
        o << "Reporta: " << e.ReportA << endl;
        return o;
    }

    friend istream &operator>>(istream &i, Empleado &e)
    {
        cout << "\nIngresa la Clave: ";
        i >> e.ClaveEmpleado;
        cout << "Ingresa Nombre: ";
        i.ignore(); // Clear newline from input buffer
        getline(i, e.Nombre);
        cout << "Ingresa Domicilio: ";
        getline(i, e.Domicilio);
        cout << "Ingresa Sueldo: $";
        i >> e.Sueldo;
        cout << "Ingresa Reporta: ";
        i.ignore(); // Clear newline from input buffer
        getline(i, e.ReportA);
        return i;
    }

    bool operator==(const Empleado &e) const { return ClaveEmpleado == e.ClaveEmpleado; }
    bool operator!=(const Empleado &e) const { return ClaveEmpleado != e.ClaveEmpleado; }
    bool operator<(const Empleado &e) const { return ClaveEmpleado < e.ClaveEmpleado; }
    bool operator<=(const Empleado &e) const { return ClaveEmpleado <= e.ClaveEmpleado; }
    bool operator>(const Empleado &e) const { return ClaveEmpleado > e.ClaveEmpleado; }
    bool operator>=(const Empleado &e) const { return ClaveEmpleado >= e.ClaveEmpleado; }

    void Imprime() const
    {
        cout << "\tDatos del empleado...\n";
        cout << "Clave: " << ClaveEmpleado << endl;
        cout << "Nombre: " << Nombre << endl;
        cout << "Domicilio: " << Domicilio << endl;
        cout << "Sueldo: $" << Sueldo << endl;
        cout << "Reporta: " << ReportA << endl;
    }
};

const int Tam = 500;

class Pila {
private:
    Empleado datos[Tam];
    int ult;

public:
     Pila(){
         ult=-1;
         }

    void insertar(const Empleado &elem)
    {
        if (llena()) {
            cout << "\nError: La pila está llena." << endl;
            return;
        }
        datos[++ult] = elem;
    }

    void insertarEnPosicion(const Empleado &elem, int pos)
    {
        if (llena() || pos < 0 || pos > ult + 1) {
            cout << "\nError: Posición inválida o pila llena." << endl;
            return;
        }
        for (int i = ult; i >= pos; --i) {
            datos[i + 1] = datos[i];
        }
        datos[pos] = elem;
        ++ult;
    }

    void eliminar()
    {
        if (vacia()) {
            cout << "\nError: La pila está vacía." << endl;
            return;
        }
        --ult;
    }

    bool vacia() const
    {
        if(ult==-1)
            return true;
        return false;

    }

    bool llena() const
    {
        if(ult==Tam-1)
            return true;
        return false;

    }

    Empleado recupera(int pos) const
    {
        if (vacia() || pos < 0 || pos > ult) {
            cout << "\nError: Posición inválida." << endl;
            return Empleado(); // Devuelve un empleado por defecto
        }
        return datos[pos];
    }

    void mostrar() const
    {
        if (vacia()) {
            cout << "\nLa pila está vacía." << endl;
            return;
        }
        for (int i = 0; i <= ult; ++i) {
            cout << "Elemento en posición " << i << ": " << datos[i] << endl;
        }
    }

    int buscar(int clave) const
    {
        for (int i = 0; i <= ult; ++i) {
            if (datos[i].GetClaveEmpleado() == clave) {
                return i; // Retorna la posición si se encuentra el empleado
            }
        }
        return -1; // Retorna -1 si no se encuentra
    }
};

int main()
{
    Pila Mipila;
    int opcion;
    Empleado emp;
    int clave, pos;

    do {
        cout << "\n1. Insertar empleado";
        cout << "\n2. Insertar empleado en posición específica";
        cout << "\n3. Eliminar empleado";
        cout << "\n4. Buscar empleado por clave";
        cout << "\n5. Mostrar empleados";
        cout << "\n6. Salir";
        cout << "\nElige una opción: ";
        cin >> opcion;
        cin.ignore(); // Limpiar el buffer de entrada

        switch (opcion) {
            case 1:
                cout << "Ingrese los datos del empleado:" << endl;
                cin >> emp;
                Mipila.insertar(emp);
                break;
            case 2:
                cout << "Ingrese los datos del empleado:" << endl;
                cin >> emp;
                cout << "Ingrese la posición en la que desea insertar el empleado: ";
                cin >> pos;
                Mipila.insertarEnPosicion(emp, pos);
                break;
            case 3:
                Mipila.eliminar();
                break;
            case 4:
                cout << "Ingrese la clave del empleado a buscar: ";
                cin >> clave;
                pos = Mipila.buscar(clave);
                if (pos != -1) {
                    cout << "Empleado encontrado en la posición " << pos << ": " << Mipila.recupera(pos) << endl;
                } else {
                    cout << "Empleado con clave " << clave << " no encontrado." << endl;
                }
                break;
            case 5:
                Mipila.mostrar();
                break;
            case 6:
                cout << "Saliendo del programa..." << endl;
                break;
            default:
                cout << "Opción inválida. Inténtalo de nuevo." << endl;
        }
    } while (opcion != 6);

    return 0;
}

