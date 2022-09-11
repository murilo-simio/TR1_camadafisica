#include "camada_app.h"
#include "camada_fisica.h"
#include "camada_enlace.h"

void AplicacaoTransmissora()
{
    string mensagem;
    int codFis, error;
    cout << "Digite uma mensagem: " << endl;
    getline(cin, mensagem);
    cout << "Selecione o tipo de codificacao: " << endl;
    cout << "1 - Binaria\n2 - Manchester\n3 - Bipolar" << endl;
    cin >> codFis;
    cout << "Probabilidade de erro (0-100): " << endl;
    cin >> error;
    cout << "Selecione o tipo de enquadramento: " << endl;
    cout << "1 - Contagem de caracter\n2 - Insercao de bytes" << endl;
    cin >> enlace;

    CamadaDeAplicacaoTransmissora(mensagem, codFis, error);

}

void CamadaDeAplicacaoTransmissora(const string& mensagem, int codFis, int error)
{
    vector<int> frame = stov(mensagem);

    CamadaEnlaceTransmissora(frame, codFis, error);
}

void CamadaDeAplicacaoReceptora(const vector<int> &frame)
{
    string mensagem = vtos(frame);
    AplicacaoReceptora(mensagem);
}

void AplicacaoReceptora(const string& mensagem) {
  cout << endl << "A mensagem recebida foi:" << mensagem << endl;
}