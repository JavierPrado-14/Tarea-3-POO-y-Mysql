// Tarea 3 POO y Mysql.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//
#include <mysql.h>
#include <iostream>
using namespace std;
int q_estado;
int main() {
    MYSQL* conectar;
    conectar = mysql_init(0);
    conectar = mysql_real_connect(conectar,"localhost","root","JavierPrado14","bd3_empresa", 3306, NULL, 0);
    if (conectar) {
        //cout << "La conexion es exitosa..."<<endl;
        string proveedor;
        string direccion;
        string nit;
        string telefono;
        cout << "Ingrese Nombre de proveedor: ";
        cin >> proveedor;
        cout << "Ingrese NIT: ";
        cin >> nit;
        cout << "Ingrese Direccion: ";
        cin >> direccion;
        cout << "Ingrese Telefono: ";
        cin >> telefono;
        string insert = "insert into proveedores(Proveedor,nit,direccion,telefono) values ('" +proveedor+"','" +nit+ "','" +direccion+ "','" +telefono+ "');";
        const char* i = insert.c_str();

        q_estado = mysql_query(conectar,i);
        if (q_estado) {
            cout << "Ingreso Exitoso....";
        }
        else {
            cout << "Error en Ingreso";
        }
       
    }
    else {
        cout << "Error en conexion...";
    }
    system("pause");
    return 0;

}

