// miblackjack.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <time.h>
using namespace std;

//jugador
string jugador1;
int puntosHU = 0;
int fichas = 0;
int apuesta = 0;
int puntosTotal = 0;
string option = "";
int valoresCartas[11];

//jugador Croupier
string maquina = "Croupier";
int puntosCro = 0;

// barajas y palos
string barajas[3][13] = {
    {"Corazon", "Pica", "Rombo", "Trebol"},
    {"A","2","3","4","5","6","7","8","9","10","J","Q","K"},
    {"0","2","3","4","5","6","7","8","9","10","10","10","10"}
};



void inicioJuego() {

    cout << "┌────────┐░░░┌─────────┐\n";
    cout << "│▓▓▓▓▓▓▓▓│░░░│6♠░░░░░░░│\n";
    cout << "│▓▓▓▓▓▓┌─────│░░░░░░░░░│\n";
    cout << "│▓▓▓▓▓▓│3♦░░░│░░░░♠░░░░│\n";
    cout << "│▓▓▓▓▓▓│░░░░░│░░░░░░░░░│\n";
    cout << "│▓▓▓▓▓▓│░░░░♦│░░░░░░░░░│\n";
    cout << "│▓▓▓▓▓▓│░░░░░│░░░░░░░♠6│\n";
    cout << "└──────│░░░░░└──..─────┘\n";
    cout << "░░░░░░░│░░░░░░░♦3│\n";
    cout << "░░░░░░░└──..─────┘\n\n\n\n";
    cout << "Bienvenido al Black Jack 21\n";
    cout << "Soy el Corupier a continuacion te indico las reglas del juego\n\n";
    cout << "[1] GANA si...\n";
    cout << "	Alcanza un 21 y el croupier no empata a 21 o se pasa de 21\n";
    cout << "	Alcanza menos de 21 pero la banca se pasa de 21\n\n";
    cout << "[2] EMPATA si...\n";
    cout << " 	Alcanza un 21 y el croupier alcanza tambien 21\n\n";
    cout << "[3] PIERDE si...\n";
    cout << " 	Se pasa de 21\n";
    cout << " 	Tiene una puntuacion menor a 21, pero la banca tiene una puntuacion mayor, sin pasarse de 21.\n\n";
    cout << "Quieres jugar?\n";
    cout << "Si o No";
    cin >> option;
    if (option == "si")
    {
        jugar();
    }
    system("Pause");
    system("cls");


}

void jugar() {
    cout << "Insete su nombre para empezar a jugar\n\n";
    cout << "Aqui: "; cin >> jugador1;
    cout << "Introduza las fichas que desea tener\n";
    cout << "Aqui: "; cin >> fichas;
    cout << "Introduzca la cantidad a apostar \n";
    cout << "Aqui: "; cin >> apuesta;
    mostrarCartas(jugador1, fichas, apuesta, 0);

}

void mostrarCartas(string jugador, int fichas, int apuesta, int turno) {

    //TODO show name, fichas, apuesta

    if (turno == 0) {
        int* carta = generarCarta();

        string palo0 = barajas[0][carta[0]];

        string cartaToShow = barajas[1][carta[1]];

        valoresCartas[0] = atoi(barajas[2][carta[1]].c_str());



        carta = generarCarta();
        string palo1 = barajas[0][carta[0]];
        string cartaToShow1 = barajas[1][carta[1]];
        valoresCartas[1] = atoi(barajas[2][carta[1]].c_str());

        turno = 1;

        //TODO show cartatoShowX and PaloX
    }
    else {

        int* carta = generarCarta();
        string palo = barajas[0][carta[0]];
        string cartaToShow = barajas[1][carta[1]];
        valoresCartas[turno] = atoi(barajas[2][carta[1]].c_str());

        //TODO show cartatoShow and Palo

    }

    jugada(turno);
}


void jugada(int turno) {
    int seleccion = 2;
    if (seleccion == 2) {//todo te plantas
    }
    else {
        mostrarCartas(jugador1, fichas, apuesta, turno + 1);
    }
}

int* generarCarta() {
    static int carta[2];

    //TODO random 0-3
    int palo = rand() % 4;

    int carta = rand() % 12;


    int palo = 0;
    //TODO random 0-12
    int valor = 3;
    //ex 4 de picas
    carta[0] = palo;
    carta[1] = valor;
    return carta;
}

int main() {
    inicioJuego();
    jugar();

}