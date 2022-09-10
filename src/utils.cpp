#include "utils.h"

// String to ASCII function
vector<int> stoa(string mensagem)
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

// ASCII to string function
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