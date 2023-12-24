#include "header/header.h"

int main()
{
    int choix;
    bibliotheque mabib;
    mabib.ajoute(new video("Nanometers and Gigabucks", "1996", "G. E. Moore",
                           "University Video Communications", 61));
    mabib.ajoute(new Periodique("Computational Linguistics", "12/2003", "MIT Press"));
    mabib.ajoute(new livre("Programmation orientee objets en C++ ", "2003", "(2nd edition)", "Micheloud et Rieder", "PPUR"));
    mabib.ajoute(new LivreExterne("Programmation orientee objets en C# ",
                                  "2003",
                                  "(2nd edition)",
                                  "Micheloud et Rieder",
                                  "PPUR", "mohammed sbihi", "11/07/2004", "ENSAF bibiloteque"));
    mabib.ajoute(new videoExterne("ma nouvelle video",
                                  "9/12/2012",
                                  "mohammed sbihi",
                                  20,
                                  "MsProg",
                                  "ahmed sbihi",
                                  "10/09/2004",
                                  "ENSAF bibiloteque", "null"));

    mabib.ajoute(new PeriodiqueExterne("journal Asabah", "11/07/2004", "MsProg", "ENSAF bibiloteque"));
    mabib[0]
        .emprunt("05/07/2004", "J.-C. Chappelier");
    mabib[0].setDispo(false);
    mabib.afficherObjets();

    while (choix != 100)
    {
    debut:
        system("cls");
        choix = 0;
        int choix2 = 0;
        cout << "choix possible sont : " << endl;

        for (unsigned int i = 0; i < mabib.size(); i++)
        {
            cout << i + 1 << " : " << mabib[i].get_type() << " sous le nom de :" << mabib[i].getnom() << endl;
        }
        cout << "tapez 100 pour quitter" << endl;
        cin >> choix;
        if (choix > mabib.size() && choix != 100)
        {
            cout << "desoler mais ";
            goto debut;
        }
        else if (choix == 100)
        {
            return 0;
        }
        while (choix2 != 100)
        {
        milieu:
            vector<string> t1 = {
                "modifier",
                "afficher",
                "supprimer",
            };
            for (int j = 0; j < t1.size(); j++)
            {
                cout << j + 1 << " : " << t1[j] << " " << mabib[choix - 1].get_type() << " sous le nom de :" << mabib[choix - 1].getnom() << endl;
            }
            cout << "tapez 100 pour quitter" << endl;
            cin >> choix2;
            if (choix2 > mabib.size() && choix2 != 100)
            {
                cout << "desoler mais ";
                goto milieu;
            }
            else if (choix2 == 100)
            {
                goto debut;
            }
            switch (choix2)
            {
            case 1:
                mabib[choix - 1].update();
                break;
            case 2:
                mabib[choix - 1].afficher();

                break;
            case 3:
                cout << " supression de " << choix - 1 << endl;
                mabib.supprimer(choix - 1);
                choix2 = 100;
                cout << "========================" << endl;
                mabib.afficherObjets();

                break;
            default:
                break;
            }
        }
    }
}