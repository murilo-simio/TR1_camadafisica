#include "camada_fisica.h"
#include "camada_app.h"

void CamadaFisicaTransmissora(const vector<int> &frame, int codFis)
{

    vector<int> fluxoBrutoDeBits;

    switch (codFis)
    {
    case 1:
    {
        fluxoBrutoDeBits = CamadaFisicaTransmissoraCodificacaoBinaria(frame);
        break;
    }
    case 2:
    {
        fluxoBrutoDeBits = CamadaFisicaTransmissoraCodificacaoManchester(frame);
        break;
    }
    case 3:
    {
        fluxoBrutoDeBits = CamadaFisicaTransmissoraCodificacaoBipolar(frame);
        break;
    }
    }
    MeioDeComunicacao(fluxoBrutoDeBits, codFis);
}

void MeioDeComunicacao(const vector<int> &fluxoBrutoDeBits, int codFis)
{

    vector<int> fluxoBrutoDeBitsPontoA, fluxoBrutoDeBitsPontoB;
    fluxoBrutoDeBitsPontoA = fluxoBrutoDeBits;

    for (unsigned i = 0; i < fluxoBrutoDeBitsPontoA.size(); i++)
    {
        fluxoBrutoDeBitsPontoB.push_back(fluxoBrutoDeBitsPontoA.at(i));
    }

    CamadaFisicaReceptora(fluxoBrutoDeBitsPontoB, codFis);
}

void CamadaFisicaReceptora(const vector<int> &fluxoBrutoDeBits, int codFis)
{

    vector<int> frame;

    switch (codFis)
    {
    case 1:
    {
        frame = CamadaFisicaReceptoraCodificacaoBinaria(fluxoBrutoDeBits);
        break;
    }
    case 2:
    {
        frame = CamadaFisicaReceptoraCodificacaoManchester(fluxoBrutoDeBits);
        break;
    }
    case 3:
    {
        frame = CamadaFisicaReceptoraCodificacaoBipolar(fluxoBrutoDeBits);
        break;
    }
    }
    CamadaDeAplicacaoReceptora(frame);
}

vector<int> CamadaFisicaTransmissoraCodificacaoBinaria(vector<int> frame)
{

    for (unsigned i = 0; i < frame.size(); i++)
    {
        if (i % 8 == 0)
        {
            cout << endl;
        }
        cout << frame.at(i);
    }
    cout << endl;
    return frame;
}

vector<int> CamadaFisicaTransmissoraCodificacaoManchester(vector<int> frame)
{

    vector<int> quadro;

    for (unsigned i = 0; i < frame.size(); i++)
    {
        quadro.push_back(frame.at(i) ^ 0);
        quadro.push_back(frame.at(i) ^ 1);
        if (i % 8 == 0)
        {
            cout << endl;
        }
        cout << (frame.at(i) ^ 0);
        cout << (frame.at(i) ^ 1);
    }

    cout << endl;

    return quadro;
}

vector<int> CamadaFisicaTransmissoraCodificacaoBipolar(vector<int> frame)
{
    bool flag = false;

    for (unsigned i = 0; i < frame.size(); i++)
    {
        if (i % 8 == 0)
        {
            cout << endl;
        }

        if (frame.at(i) == 1)
        {
            if (flag)
            {
                frame.at(i) = -1;
                cout << "-1";
            }
            else
            {
                cout << " 1";
            }
            flag = !flag;
        }
        else
        {
            cout << " 0";
        }
        cout << " ";
    }

    cout << endl;

    return frame;
}

vector<int> CamadaFisicaReceptoraCodificacaoBinaria(vector<int> fluxoBrutoDeBits)
{
    return fluxoBrutoDeBits;
}

vector<int> CamadaFisicaReceptoraCodificacaoManchester(vector<int> fluxoBrutoDeBits)
{

    vector<int> frame;

    for (unsigned i = 0; i < fluxoBrutoDeBits.size(); i += 2)
    {
        frame.push_back(fluxoBrutoDeBits.at(i));
    }

    return frame;
}

vector<int> CamadaFisicaReceptoraCodificacaoBipolar(vector<int> fluxoBrutoDeBits)
{

    for (unsigned i = 0; i < fluxoBrutoDeBits.size(); i++)
    {
        fluxoBrutoDeBits.at(i) = fabs(fluxoBrutoDeBits.at(i));
    }

    return fluxoBrutoDeBits;
}