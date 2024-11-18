#include <iostream>
//El <iostream proporciona los objetos que pueden leer los datos de entrada y salida del usuario
#include <iomanip>
//El <iomanip> es utilizado para gestionar el formato de entrada y salida
using namespace std;
 
 const int maxFood = 10;
//El max food  es el maximo de comidas que se pueden poner
 const int numNutrientes = 4;
//Los tipos de nutrintes dentro del programa

 //array para lista de alimentos 
string foodNames[maxFood] = {
    "manzana", "pollo", "arroz", "huevo", "pan",
    "platano", "leche", "tomate", "queso", "yogur"
};
  //Valores de nutricionales por cada alimento las cuales son 100 gramos

  float nutrientes[maxFood] [numNutrientes] = {
        {52, 0.3, 14, 0.2},
        {165, 31, 0, 3.6},
        {130, 2.4, 28, 0.3},
        {155, 13, 1.1, 11},
        {265, 9, 49, 3.2},
        {89, 1.1, 23, 0.3},
        {42, 3.4, 5, 1},
        {18, 0.6, 3.9, 0.2},
        {402, 25, 1.3, 33},
        {59, 10, 3.6, 0.4}
    };
    
// Funcion para mostrar los valores nutricionales de un alimento dado su indice
void showFood(int index, float cantidad) {
    cout << fixed << setprecision(2);
    cout << "Calorias: " << nutrientes[index][0] * cantidad / 100 << " kcal" << endl;
    cout << "Proteinas: " << nutrientes[index][1] * cantidad / 100 << " g" << endl;
    cout << "Carbohidratos: " << nutrientes[index][2] * cantidad / 100 << " g" << endl;
    cout << "Grasas: " << nutrientes[index][3] * cantidad / 100 << " g" << endl;
}


int main(){
    string foodEntered[maxFood];
    float qtyEntered[maxFood];
    int contador = 0;

    char opcion = 's';
    do {
        if (contador >= maxFood) {
            cout << "se ha alcanzado el limite de alimentos." << endl;
            break;
        }
        
        cout<<"Ingrese el nombre de un alimento (manzana, pollo, arroz, huevo, pan, platano, leche, tomate, queso, yogur): ";
        cin >> foodEntered[contador];

        int index = -1;
        for (int i = 0; i < maxFood; i++) {
            if (foodEntered[contador] == foodNames[i]) {
                index = i;
                break;
            }
        }

        if (index != -1) {
            float cantidad;

            while (true) { //bucle infinito hasta que se ingrese una cantidad valida
                cout << "Ingrese una cantidad en gramos: ";
                cin >> cantidad;

                if (cin.fail()) {


                    cin.clear();// Limpiar el estado de error de `cin`
                    cin.ignore(1000, '\n');// Ignorar el resto de la linea
                    cout << "Entrada no valida. Por favor ingrese un numero." << endl;
                }
                else if (cantidad <= 0) {
                    cout << "Cantidad debe ser positiva." << endl;
                }
                else {
                    qtyEntered[contador] = cantidad;
                    showFood(index, qtyEntered[contador]);
                    contador++;
                        break; //Salir del loop cuando se ingresa un cantidad valida
                }
            }
        }
        else {
            cout << "Alimento no encontrado en base de datos." << endl;
        }

        cout << "Desea ingresar otro alimento? (s/n): ";
        cin >> opcion;

    } while (opcion == 's');

    









    return 0;
}


