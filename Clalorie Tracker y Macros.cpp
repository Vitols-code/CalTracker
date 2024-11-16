// Calorie Tracker y Macros.cpp : This file contains the 'main' function. Program execution begins and ends there.
//




// Test for commit/push/pull
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


