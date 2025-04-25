#include <vector>
#include <iostream>

void print_v0(const std::vector<double> & mydata);
void print_v1(const std::vector<double> & mydata);

int main(void)
{

    std::vector<double> data = {0.1, 0.5, -0.6};
    print_v0(data);
    print_v1(data);
    return 0;
}
void print_v0(const std::vector<double> & mydata){
    for (int ii = 0; ii < mydata.size(); ii++) {
        std::cout << mydata[ii] << " ";
    }
    std::cout << "\n";
}

void print_v1(const std::vector<double> & mydata){
    for (auto x:mydata) {  // ir sacando cada valor de data y lo va imprimiendo
        std::cout << x << " ";
    
    } 
    std::cout << "\n";
}

// & cuando le coloco esto a las variables, es referencia de la variable principal y no crea una copia, esto soluciona la copia de muchos datos
// const hace que la funcion no me cambie los datos ya que pues al ser una referencia podria modificar la funcion