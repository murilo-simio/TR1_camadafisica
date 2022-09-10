// Teleinformática e Redes 1
// Simulação de Camada Física
// Murilo Simionato Arnemann 18/0107453
#include <iostream>
#include <string>
#include <stdio.h>
#include <vector>

#include "camada_fisica.h"

using namespace std;

void main()
{
    AplicacaoTransmissora();
}

void AplicacaoTransmissora()
{
    string mensagem;
    cout << "Digite uma mensagem: " << endl;
    cin >> mensagem;

    // Chama a próxima camada
    CamadaDeAplicacaoTransmissora(mensagem);
}
