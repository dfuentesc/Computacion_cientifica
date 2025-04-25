// verificar si un numero es par

/* 
   if (condicion) {
   instrucciones
   }
   else {
   instrucciones
   }
 */

#include <iostream> 

int main(void) 
{
  int num;

  // solicitar el numero
  std::cout << "Escriba un numero entero, por favor:" << std::endl;
  // leer el numero
  std::cin >> num;

  // verificar que el numero es par o no
  // imprimir
  // si el numero es par, imprimir "el numero es par"
  // si no, imprimir "el numero es impar"
  if (num%2 == 0) {  // el residuo es igual a 0
    std::cout << "El numero es par" << std::endl;
  } 
  if (num%2 != 0) {  // el residuo es diferente a 0
    std::cout << "El numero es impar" << std::endl;
  } 

  //else {
  //cout << "El numero es impar" << endl;
  //}

  return 0;
}