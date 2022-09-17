#include "utils.h"

// String to vector function
vector<int> stov(string mensagem)
{

    vector<int> frame;

    for (unsigned i = 0; i < mensagem.size(); i++)
    {
        frame.push_back(int(mensagem.at(i)));
    }
    return frame;
}

// Vector to string function
string vtos(vector<int> frame)
{

    string mensagem = "";

    for (unsigned i = 0; i < frame.size(); i++)
    {

        mensagem.append(1, char(frame[i]));
    }

    return mensagem;
}

// Returns a random number between 0-100
int randomNumberGenerator()
{
    srand(time(NULL));
    return (rand() % 100);
}

// ASCII to bits function
vector<int> atob(vector<int> mensagem)
{

    vector<int> frame;

    for (unsigned i = 0; i < mensagem.size(); i++)
    {

        vector<int> tFrame;
        int binChar = int(mensagem.at(i));

        for (unsigned j = 0; j < 8; j++)
        {
            if (binChar % 2 == 0)
            {
                tFrame.push_back(0);
            }
            else
            {
                tFrame.push_back(1);
            }
            binChar = binChar >> 1;
        }

        for (int k = 8 - 1; k >= 0; k--)
        {
            frame.push_back(tFrame.at(k));
        }
    }
    return frame;
}

// Bits to ASCII
vector<int> btoa(vector<int> frame)
{

    vector<int> quadro;
    int intChar = 0;

    for (unsigned i = 0; i < frame.size(); i++)
    {
        if (i != 0 && i % 8 == 0)
        {
            quadro.push_back(intChar);
            intChar = 0;
        }
        intChar = intChar << 1;
        intChar += frame.at(i);
    }
    quadro.push_back(intChar);
    return quadro;
}

string atos(vector<int> frame)
{

    string mensagem = "";
    int intChar = 0;

    for (unsigned i = 0; i < frame.size(); i++)
    {

        if (i != 0 && i % 8 == 0)
        {
            mensagem.append(1, char(intChar));
            intChar = 0;
        }

        intChar = intChar << 1;
        intChar += frame.at(i);
    }

    mensagem.append(1, char(intChar));

    return mensagem;
}