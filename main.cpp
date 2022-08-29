// Teleinformática e Redes 1
// Simulação de Camada Física
// Murilo Simionato Arnemann 18/0107453
#include <iostream>
#include <string>
#include <stdio.h>
#include <vector>

using namespace std;

void main(){
    AplicacaoTransmissora();
}

void AplicacaoTransmissora(){
    string mensagem;
    cout << "Digite uma mensagem: " << endl;
    cin >> mensagem;

    // Chama a próxima camada
    CamadaDeAplicacaoTransmissora(mensagem);
}

void CamadaDeAplicacaoTransmissora(string mensagem){
    vector<int> frame(mensagem.length());
    CamadaFisicaTransmissora(frame);
}

void CamadaFisicaTransmissora(vector<int> frame[]){
    int tipoDeCodificacao = 0;
    vector<int> fluxoBrutoDeBits;

    switch (tipoDeCodificacao){
        case 0:
            fluxoBrutoDeBits = CamadaFisicaTransmissoraCodificacaoBinaria(frame);
            break;
        case 1:
            fluxoBrutoDeBits = CamadaFisicaTransmissoraCodificacaoManchester(frame);
            break;
        case 2:
            fluxoBrutoDeBits = CamadaFisicaTransmissoraCodificacaoBipolar(frame);
            break;
    }

    MeioDeComunicacao(fluxoBrutoDeBits);
}

vector<int> CamadaFisicaTransmissoraCodificacaoBinaria(vector<int> frame){

}

vector<int> CamadaFisicaTransmissoraCodificacaoManchester(vector<int> frame){
    
}

vector<int> CamadaFisicaTransmissoraCodificacaoBipolar(vector<int> frame){
    
}

void MeioDeComunicacao(vector<int> fluxoBrutoDeBits){

}