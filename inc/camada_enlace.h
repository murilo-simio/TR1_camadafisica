#include "camada_fisica.h"

static int enlace;

void CamadaEnlaceTransmissora(vector<int> &frame, int codFis, int error);
int CamadaEnlaceReceptora(vector<int> &frame);
vector<int> CamadaEnlaceReceptoraEnquadramento(vector<int> &frame);
vector<int> CamadaEnlaceTransmissoraEnquadramento(vector<int> frame);
vector<int> CamadaEnlaceTransmissoraEnquadramentoContagemDeCaracteres(vector<int> frame);
vector<int> CamadaEnlaceTransmissoraEnquadramentoInsercaoDeBytes(vector<int> &frame);
vector<int> CamadaEnlaceReceptoraEnquadramentoInsercaoDeBytes(vector<int> &frame);
vector<int> CamadaEnlaceReceptoraEnquadramentoContagemDeCaracteres(vector<int> frame);