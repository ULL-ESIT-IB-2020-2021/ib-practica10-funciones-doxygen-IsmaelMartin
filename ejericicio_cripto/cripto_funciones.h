#include <iostream>
#include <fstream>
#include <string>

const std::string kHelpText = R"(fichero_entrada: Fichero a codificar
fichero_salida:  Fichero codificado
método:          Indica el método de encriptado
                   1: Cifrado xor
                   2: Cifrado de César
password:        Palabra secreta en el caso de método 1, Valor de K en el método 2
operación:       Operación a realizar en el fichero
                   +: encriptar el fichero
                   -: desencriptar el fichero)";

void Usage(int argc, char *argv[]);
void ComprobarParametros(char *argv[]);
bool IsInteger(std::string str);
std::string EncriptadoXor(std::string contenido, std::string clave);
std::string EncriptadoCesar(std::string contenido, const int k);
std::string DesencriptadoCesar(std::string contenido, const int k);
void ContarVocales(std::string contenido);
