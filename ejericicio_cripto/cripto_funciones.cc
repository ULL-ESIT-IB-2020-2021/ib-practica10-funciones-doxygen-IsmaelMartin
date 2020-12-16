#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <iomanip>
#include "cripto_funciones.h"

/** Muestra el modo de uso correcto del programa
 *  En caso de que el uso no sea el correcto, muestra el mensaje y finaliza
 *  la ejecución del programa.
 *
 *  @param[in] argc Number of command line parameters
 *  @param[in] argv Vector containing (char*) the parameters
 */
void Usage(int argc, char* argv[]) {
  
  if (argc == 1 && argc != 6) {
    std::cout << argv[0] << ": faltan parámetros" << std::endl;
    std::cout << "Pruebe " << argv[0] << " --help para más información" << std::endl;
    exit(EXIT_SUCCESS);
  }
  if (argc == 2){
    std::string parameter{argv[1]};
    if (parameter == "--help") {
      std::cout << kHelpText << std::endl;
      exit(EXIT_SUCCESS);
    }
  }
  if (argc != 6){
    std::cout << argv[0] << ": faltan parámetros" << std::endl;
    std::cout << "Pruebe " << argv[0] << " --help para más información" << std::endl;
    exit(EXIT_SUCCESS);
  }
}
/** Comprueba que los parámetros introducidos
 *  son los necesarios para el correcto proceso de encriptado,
 *  en caso contrario imprime en pantalla el mensaje de error 
 *  correspondiente indicando que parámetro es incorrecto. 
 * */
void ComprobarParametros(char* argv[]){
  if (argv[3][0] != '1' && argv[3][0] != '2'){
    std::cout << "Error en el método de encriptado" << std::endl;
    exit(EXIT_FAILURE);
  }
  if (argv[3][0] == '2'){
    std::string k{argv[4][0]};
    if(IsInteger(k)){

    }
    else{
      std::cout << "Error en el método de encriptado" << std::endl;
      exit(EXIT_FAILURE);
    }
  }
  if (argv[5][0] != '+' && argv[5][0] != '-'){
    std::cout << "Error en la operación" << std::endl;
    exit(EXIT_FAILURE);
  }
  
}
/**
 * La siguiente función IsInteger comprueba si el parámetro
 * k que se introduce por línea de comandos es realmente un 
 * número entero, tal y como se precisa.
 * */ 
bool IsInteger(std::string str) {
  for(auto c: str){
    if(c < 48 || c > 57)
      return false;
  }

  return true;
} 
/**
 * A continuación, se presenta una función que encripta un fichero 
 * con el método de XOR. A la función se le pasa el contenido del 
 * fichero y la clave o contraseña correspondiente.
 *  */
std::string EncriptadoXor(std::string contenido, std::string clave){
  std::string contenido_encriptado{""};
  std::string clave_encriptada{""};
  for (auto i : clave){
    clave_encriptada += (clave[i]^128);
    std::cout << clave_encriptada;
  }
  for (int i : contenido){
    contenido_encriptado += (contenido[i]^clave_encriptada[i%clave_encriptada.length()]);
  }
  return contenido_encriptado;
}
/**
 * A continuación, se presenta una función que encripta un fichero 
 * con el método de césar. A la función se le pasa el contenido del 
 * fichero y la constate k.
 *  */
std::string EncriptadoCesar(std::string contenido, const int k){
  std::string contenido_encriptado;
  for (int i = 0; i < contenido.length(); ++i){
    char caracter_evaluar = contenido[i];
    int caracter = caracter_evaluar;
    caracter += k;
    char caracter_nuevo{caracter};
    contenido_encriptado += caracter_nuevo;
  }
  return contenido_encriptado;
}
/**
 * A continuación, se presenta una función que desencripta un fichero previamente
 * encriptado con el método de césar. A la función se le pasa el contenido del 
 * fichero y la constate k.
 *  */
std::string DesencriptadoCesar(std::string contenido, const int k){
  std::string contenido_desencriptado;
  for (int i = 0; i < contenido.length(); ++i){
    char caracter_evaluar = contenido[i];
    int caracter = caracter_evaluar;
    caracter -= k;
    char caracter_nuevo{caracter};
    contenido_desencriptado += caracter_nuevo;
  }
  return contenido_desencriptado;
}



 