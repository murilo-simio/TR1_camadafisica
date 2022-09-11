#include <vector>
#include <iostream>
#include <string>
#include <stdio.h>
#include <cmath>

#include "utils.h"

using namespace std;

void CamadaFisicaReceptora(const vector<int> &fluxoBrutoDeBits, int codFis);
void CamadaFisicaTransmissora(const vector<int>& frame, int codFis, int error);
void MeioDeComunicacao(const vector<int> &fluxoBrutoDeBits, int codFis, int error);
vector<int> CamadaFisicaReceptoraCodificacaoBinaria(vector<int> fluxoBrutoDeBits);
vector<int> CamadaFisicaReceptoraCodificacaoBipolar(vector<int> fluxoBrutoDeBits);
vector<int> CamadaFisicaReceptoraCodificacaoManchester(vector<int> fluxoBrutoDeBits);
vector<int> CamadaFisicaTransmissoraCodificacaoBinaria(vector<int> frame);
vector<int> CamadaFisicaTransmissoraCodificacaoBipolar(vector<int> frame);
vector<int> CamadaFisicaTransmissoraCodificacaoManchester(vector<int> frame);