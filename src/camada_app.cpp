#include "camada_app.h"

void AplicacaoTransmissora()
{
    string mensagem;
    cout << "Digite uma mensagem: " << endl;
    cin >> mensagem;

    // Chama a próxima camada
    CamadaDeAplicacaoTransmissora(mensagem);
}

