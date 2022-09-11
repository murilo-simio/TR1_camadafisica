#include <string>
#include <vector>
#include <iostream>

#include "utils.h"

using namespace std;

void AplicacaoReceptora(const string& mensagem);
void AplicacaoTransmissora();
void CamadaDeAplicacaoReceptora(const vector<int> &frame);
void CamadaDeAplicacaoTransmissora(const string& mensagem, int codFis);