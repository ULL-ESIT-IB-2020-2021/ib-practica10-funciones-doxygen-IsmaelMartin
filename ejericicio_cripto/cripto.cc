/** 
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 * 
 * @author IMH-ISMAEL MARTIN HERRERA
 * @brief Este programa encripta y desencripta fichero de texto introducidos por el usuario mediante 
 *        dos posibles métodos: el cifrado de César o el cifrado XOR
 * @see https://github.com/ULL-ESIT-IB-2020-2021/IB-P10-Files-Doxygen/blob/master/Files-Doxygen.md
 *      http://www.cplusplus.com/doc/tutorial/files/
 * 
*/

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "cripto_funciones.h"


int main(int argc, char* argv[]){
  Usage(argc, argv);
  ComprobarParametros(argv);
  std::string nombre_fichero_entrada{argv[1]};
  std::string nombre_fichero_salida{argv[2]};
  std::string metodo{argv[3][0]};
  std::string contrasena{argv[4][0]};
  /** La operación ha realizar puede ser (-), 
   * desencriptar o (+), para encriptar */
  std::string operacion{argv[5]}; 
  std::string contenido_encriptado;
  std::ifstream input(nombre_fichero_entrada, std::ifstream::in);
  std::stringstream buffer;
    buffer << input.rdbuf();
    std::string contenido{buffer.str()};
  std::ofstream fichero_modificado(nombre_fichero_salida, std::ofstream::out);
  ContarVocales(contenido);
  
  /** 
   *  Filtro para comprobar que método de encriptado se desea usar
   *  y posteriormente, en el caso del método César, se comprueba
   *  si se desea encriptar o desencriptar, para llamar a la función
   *  correspondiente. 
   * 
  */
  if (metodo == "1"){
    contenido_encriptado  = EncriptadoXor(contenido,contrasena);
    fichero_modificado << contenido_encriptado; 
  }
  else if (metodo == "2"){
    int k = stoi(contrasena);
    if(operacion == "+"){
      contenido_encriptado = EncriptadoCesar(contenido, k);
      fichero_modificado << contenido_encriptado;
    }
    else if (operacion == "-"){
      contenido_encriptado = DesencriptadoCesar(contenido, k);
      fichero_modificado << contenido_encriptado;
    }
  
  }
  
  return 0;
}

