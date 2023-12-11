#include <iostream>
#include <string.h>
#include "header/fonction_header.h"
using namespace std;

void updateField(const string &fieldName, string &field)
{
    cout << "Modification de " << fieldName << " (exit pour annuler): ";
    string var;
    getline(cin, var);

    if (var == "exit")
    {
        cout << "exit" << endl;
    }
    else
    {
        field = var;
    }
}

void UpdateEmpreint(string &nom_empreinteur, string &date_empreinte, bool &disp)
{
    int choix = 0;

    cout << "1: modifier les donne de l'emprateur ou la date de l'empreinte" << endl;
    cout << "2: supprimer l'empreinte" << endl;
    cin >> choix;
    cin.ignore();

    switch (choix)
    {
    case 1:
        updateField("l'empeinteur ", nom_empreinteur);
        updateField("date de l'empreinte", date_empreinte);
        disp = false;
        break;
    case 2:
        nom_empreinteur = "null";
        date_empreinte = "null";
        disp = true;
        break;
    default:
        // TODO:ajouter une default case et une verification ;(si l'utilisateur entre une valeur de plus)
        break;
    }
    string var;
    getline(cin, var);
}
