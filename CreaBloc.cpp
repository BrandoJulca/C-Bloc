#include <iostream>
#include <fstream>
#include <unistd.h> // Incluir la biblioteca unistd.h para usar getcwd()
#include <sstream> // Incluir la biblioteca sstream para convertir el contador a string
using namespace std;

int main() {
    // Declaración de variables
    string linea;

    // Obtener la ruta del directorio actual
    char buffer[FILENAME_MAX];
    getcwd(buffer, FILENAME_MAX);
    string rutaActual(buffer);

    // Concatenar el nombre base del archivo al directorio actual
    string nombreBaseArchivo = rutaActual + "/datos";
    string nombreArchivo;

    // Verificar si el archivo ya existe
    ifstream archivoExistente;
    int contador = 1;
    do {
        stringstream ss;
        ss << contador;
        nombreArchivo = nombreBaseArchivo + " (" + ss.str() + ").txt";
        archivoExistente.open(nombreArchivo.c_str());
        contador++;
    } while (archivoExistente);

    ofstream archivo(nombreArchivo.c_str());
    // Verifica si se pudo abrir el archivo correctamente
    if (!archivo) {
        cerr << "No se pudo abrir el archivo: " << nombreArchivo << endl;
        return 1;
    }
    // Escribe la línea en el archivo
    cout << "Crea un archivo de bloc de notas desde consola \n ";
    cout << "Que texto deseas poner en el bloc? :";
    getline(cin, linea);
    archivo << linea << endl;

    // Cierra el archivo
    archivo.close();
    cout << "El texto se ha guardado en: " << nombreArchivo << endl;
    return 0;
}
