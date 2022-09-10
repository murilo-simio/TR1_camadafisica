#include "camada_app.h"
#include "camada_fisica.h"

void AplicacaoTransmissora()
{
    string mensagem;
    int codFis;
    cout << "Digite uma mensagem: " << endl;
    cin >> mensagem;
    cout << "Selecione o tipo de codificacao:" << endl;
    cout << "1 - Binaria\n2 - Manchester\n3 - Bipolar" << endl;
    cin >> codFis;

    CamadaDeAplicacaoTransmissora(mensagem, codFis);

}

void CamadaDeAplicacaoTransmissora(const string& mensagem, int codFis)
{
    vector<int> frame = stoa(mensagem);
    CamadaFisicaTransmissora(frame, codFis);
}

void CamadaDeAplicacaoReceptora(const vector<int> &frame)
{
    string mensagem = atos(frame);
    AplicacaoReceptora(mensagem);
}

void AplicacaoReceptora(const string& mensagem) {
  cout << endl << "A mensagem recebida foi:" << mensagem << endl;
}