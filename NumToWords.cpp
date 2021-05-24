#include <iostream>
#include <string>
#include <vector>
#include <math.h>
using namespace std;

//Ylen Diaz - 1092830
//Mario Galan - 1095589
//Jonathan Diaz - 1093760
//Fernando Grullón -
//Rafael Derick -
//Alejandro Paez -

//Vectores para representaciones literales de valores númericos en español
//permite almacenar varios valores bajo una sola variable y realizar operaciones complejas con esta (valores de un mismo tipo)
//en este caso funciona como un tipo de contenedor
vector<string> unoAnueve{ "cero","uno", "dos", "tres", "cuatro", "cinco", "seis", "siete", "ocho", "nueve" };
vector<string> diezAdiecinueve{ "diez", "once", "doce", "trece", "catorce", "quince","dieciséis", "diecisiete", "dieciocho", "diecinueve" };
vector<string> veinteAnoventa{ "", "", "veinte", "trenta", "cuarenta", "cincuenta", "sesenta", "setenta", "ochenta", "noventa" };
vector<string> CienANovecientos{ "", "ciento", "", "", "", "quinientos", "", "setecientos", "", "novecientos" };

//Vectores para representaciones literales de valores númericos en inglés
vector<string> oneToNine{ "","one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };
vector<string> TenToTwenty{ "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen","sixteen", "seventeen", "eighteen", "nineteen" };
vector<string> TwentyToNinety{ "", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety" };


//Esta funcion recursiva retorna la conversion de numeros a letras
string nameForNumberSpanish(long number)
{
    int size = log10(number); //Captura el size del numero, para luego encontrar la potencia. Ej: 52 -> size: 1
    
    if (number == 0) //Si el número es cero retorna "cero"
    {
        return "cero";
    }

    int poww = pow(10, size); //Encuentra la potencia del número. Ej: 52 -> poww = 10^1 = 10
    long num = (number / poww); //Se captura en la variable num la division entre el numero ingresado y la potencia. Ej: num = (52/10) = 5
    long temp = num * poww; //Se captura el valor del producto entre num y poww

    if (size == 0) //Si el size del numero es igual a cero (Significa que es un digito): 
    {
        return unoAnueve[num]; //Retorna el valor del vector en la posición que tenga la variable num
    }
    else if (size == 1 && temp < 20) //Si el size del numero es uno y el valor de la variable temp es menor a 20 (el numero esta entre 10 y 19): 
    {
        return diezAdiecinueve[number - 10]; //Retorna el valor del vector, y como parametro el numero introducido a la funcion menos diez
    }
    else if (size == 1 && temp > 19) //Si el size del numero es uno y el valor de la variable temp es mayor a 19 (el numero esta entre 20 y 99):
    {
        return veinteAnoventa[num] + ((number % poww != 0) ? " y " + nameForNumberSpanish(number % poww) : " "); //Retorna el vector en la posicion que tenga la variable num + //Pregunta si el modulo de la potencia con el numero introducido es diferente de cero. En todo caso, 
    }                                                                                                               //se llama de nuevo a la funcion introduciendo como parametro el modulo de la potencia con el numero. En caso de que sea igual a cero, sólo retornaria el valor del vector.
    else if (temp == 100 || temp == 500 || temp == 700 || temp == 900) //Casos especificos(por gramatica) para estos números:                        
    {
        return CienANovecientos[num] + ((number % 100 != 0) ? " " + nameForNumberSpanish(number % 100) : " "); //Retorna el vector en la posicion que tenga la variable num y aplica la recursividad explicada anteriormente con un modulo de 100, este ultimo siempre y cuando el resultado sea diferente de cero
    }
    else if (size == 2) // En este caso size es igual a 2 (para los números con 3 digitos) 
    {
        return nameForNumberSpanish(number / 100) + "cientos" + ((number % 100 != 0) ? " " + nameForNumberSpanish(number % 100) : " "); //Aplica la recursivad primero con el numero/100 + "cientos" y luego con un modulo de 100, (!=0)
    }
    else if (temp == 1000) //Caso especifico (por gramatica): (1000)
    {
        return "mil" + ((number % 1000 != 0) ? " " + nameForNumberSpanish(number % 1000) : " "); //Retorna "mil" y Aplica la recursivad con un modulo de 1000, (!=0)
    }
    else if (size < 6)//En este caso size es menor que 6 (para los números de 4, 5 y 6 dígitos)
    {
        return nameForNumberSpanish(number / 1000) + " mil" + ((number % 1000 != 0) ? " " + nameForNumberSpanish(number % 1000) : " "); //Aplica la recursivad primero con el numero/1000  + "mil" y luego con un modulo de 1000, (!=0)
    }
    else if (temp == 1000000) //Caso especifico (por gramatica): (1000000)
    {
        return "un millón" + ((number % 1000000 != 0) ? " " + nameForNumberSpanish(number % 1000000) : " "); //Retorna "un millon" y Aplica la recursivad con un modulo de 1000000, (!=0)
    }
    else if (size > 5) //Cuando el size es mayor a 5 (se manejan los números de 7 digitos mayores a un millón)
    {
        return nameForNumberSpanish(number / 1000000) + " millones" + ((number % 1000000 != 0) ? " " + nameForNumberSpanish(number % 1000000) : " "); //Aplica la recursivad primero con el numero/1000000  + "millones" y luego con un modulo de 1000000, (!=0)
    }
}

//Misma función alternativa para convertir números en su representación en palabras - (version en inglés)
string nameForNumberEnglish(long number) 
{
    int size = log10(number); 
    
    if (number == 0)
    {
        return "zero";
    }

    int poww = pow(10, size);
    long num = (number / poww); 
    long temp = num * poww;  
    
    if (size == 0)
    {
        return oneToNine[num]; 
    }
    else if (size == 1 && temp < 20)
    {
        return TenToTwenty[num] + ((number % poww != 0) ? "-" + nameForNumberEnglish(number % poww) : " ");
    }
    else if (size == 1 && temp > 19)
    {
        return TwentyToNinety[num] + ((number % poww != 0) ? "-" + nameForNumberEnglish(number % poww) : " ");
    }
    else if (size == 2)
    {
        return nameForNumberEnglish(number/100) + " hundred" + ((number % 100 != 0) ? " " + nameForNumberEnglish(number % 100) : " ");
    }
    else if (size < 6)
    {
        return nameForNumberEnglish(number/1000) + " thousand" + ((number % 1000 != 0) ? " " + nameForNumberEnglish(number % 1000) : " ");
    }
    else if (size > 5)
    {
        return nameForNumberEnglish(number/1000000) + " million" + ((number % 1000000 != 0) ? " " + nameForNumberEnglish(number % 1000000) : " ");
    }
}

//Esta funcion retorna los decimales del numero introducido
int Get_centavos(double input)
{
    double decimales = 0;
    double entero = round(input); //Redondea el numero ingresado

    if (entero > input) //Si el numero redondeado es mayor al numero ingresado se le resta 1 para poder conseguir el decimal
    {
        entero = entero - 1;
        
        decimales = (input - entero) * 100; //resta el numero ingresado menos el entero (da como resultado el decimal)
    }
    else //Si no es mayor:
    {
        decimales = (input - entero) * 100; //resta el numero ingresado menos el entero *100 (da como resultado el decimal)
    }
    return int(decimales); //Retorna la parte decimal
}

int main()
{
    double input; //Variable para capturar el numero del usuario
    cout << "Ingrese un numero entero: ";
    cin >> input; //Captura la variable

    int decimales = Get_centavos(input); //Llama a la funcion Get_centavos, como parametro el numero capturado, y el resultado se guarda en la variable
    long number = long(input); //Convierte el numero double a long

    //Spanish Version
    cout << "---- Spanish Version ----" << endl;
    cout << "> " << nameForNumberSpanish(number); //LLama la funcion para la conversion e Imprime la conversion de numeros a letras [en español]
    cout << " con " << decimales << " /100\n" << endl; //Imprime el decimal del numero

    //English Version
    cout << "---- English Version ----" << endl;
    cout << "> " << nameForNumberEnglish(number); //LLama la funcion para la conversion e Imprime la conversion de numeros a letras [in english]
    cout << " with " << decimales << " /100\n" << endl; //Imprime el decimal del numero

    return 0;
}