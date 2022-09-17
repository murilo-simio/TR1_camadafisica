#include "camada_enlace.h"
#include "camada_app.h"

void CamadaEnlaceTransmissora(vector<int> &frame, int codFis, int error)
{
    vector<int> quadro ;
    // quadro = CamadaEnlaceTransmissoraEnquadramento(frame);
    quadro = atob(frame);
    CamadaFisicaTransmissora(quadro, codFis, error);
}

vector<int> CamadaEnlaceTransmissoraEnquadramento(vector<int> frame)
{
    vector<int> quadro;

    switch (enlace)
    {
    case 1:
    {
        quadro = CamadaEnlaceTransmissoraEnquadramentoContagemDeCaracteres(frame);
        break;
    }
    case 2:
    {
        quadro = CamadaEnlaceTransmissoraEnquadramentoInsercaoDeBytes(frame);
        break;
    }
    }

    return quadro;
}

vector<int> CamadaEnlaceTransmissoraEnquadramentoContagemDeCaracteres(vector<int> frame)
{

    vector<int> quadro;
    int size = frame.size();
    unsigned int i = 0, j = 0, header = 0;

    if (size >= 4)
    {
        header = 4;
    }
    else if (size != 0)
    {
        header = size + 1;
    }

    while (size > 0)
    {
        if (i == 0)
        {
            quadro.push_back(header);
            i++;
        }
        else
        {
            quadro.push_back(frame.at(j));
            i++;
            j++;
            size--;

            if (i == header)
            {
                i = 0;
                if (size < 4)
                {
                    header = size + 1;
                }
            }
        }
    }

    return quadro;
}

vector<int> CamadaEnlaceTransmissoraEnquadramentoInsercaoDeBytes(vector<int> &frame)
{
    vector<int> quadro;
    int i = 0, j = 0;
    int max = 5, min = 2;

    int flag = int('x'), esc = int('m');
    int size = frame.size();
    int bytes = (randomNumberGenerator() % max) + min;

    quadro.push_back(flag);

    while (i < size)
    {
        if (frame.at(i) == flag || frame.at(i) == esc)
        {
            quadro.push_back(esc);
        }

        quadro.push_back(frame.at(i));
        i++;
        j++;

        if (i == size)
        {
            quadro.push_back(flag);
        }
        else
        {
            if (j == bytes)
            {
                j = 0;
                bytes = (rand() % max) + min;
                quadro.push_back(flag);
                quadro.push_back(flag);
            }
        }
    }
    return quadro;
}

vector<int> CamadaEnlaceReceptoraEnquadramentoInsercaoDeBytes(vector<int> &frame)
{

    vector<int> quadro;
    int size = frame.size();
    int i = 0;
    int flag = int('x'), esc = int('m');
    bool escape = false;

    while (i < size)
    {
        if (frame.at(i) == flag)
        {
            if (escape)
            {
                quadro.push_back(frame.at(i));
                escape = false;
            }
        }
        else if (frame.at(i) == esc)
        {
            if (escape)
            {
                quadro.push_back(frame.at(i));
                escape = false;
            }
            else
            {
                escape = true;
            }
        }
        else
        {
            quadro.push_back(frame.at(i));
        }
        i++;
    }

    return quadro;
}

vector<int> CamadaEnlaceReceptoraEnquadramentoContagemDeCaracteres(vector<int> frame)
{
    vector<int> quadro;
    unsigned int i = 0, j = 0, header = 0;

    while (i < frame.size())
    {
        j = 0;
        header = 0;
        header = frame.at(i);
        j = i + 1;
        i += header;
        while (j < i)
        {
            quadro.push_back(frame.at(j));
            j++;
        }
    }
    return quadro;
}

int CamadaEnlaceReceptora(vector<int> &frame)
{
    // frame = CamadaEnlaceReceptoraControleDeErro(frame);
    if (frame.size() == 1)
    {
        return 1;
    }
    frame = btoa(frame);
    vector<int> quadro = CamadaEnlaceReceptoraEnquadramento(frame);
    CamadaDeAplicacaoReceptora(quadro);

    return 0;
}

vector<int> CamadaEnlaceReceptoraEnquadramento(vector<int> &frame)
{
    vector<int> quadro;

    switch (enlace)
    {
    case 1:
    {
        quadro = CamadaEnlaceReceptoraEnquadramentoContagemDeCaracteres(frame);
        break;
    }
    case 2:
    {
        quadro = CamadaEnlaceReceptoraEnquadramentoInsercaoDeBytes(frame);
        break;
    }
    }
    return quadro;
}