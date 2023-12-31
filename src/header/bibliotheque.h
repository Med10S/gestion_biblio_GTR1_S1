#include <iostream>
#include <vector>
#include <memory>
using namespace std;

class bibliotheque
{
private:
    static const int MAX_OUVRAGES = 100; // la taille maximale du tableau
    ouvrage *ouvrages[MAX_OUVRAGES];
    int compteur; // un compteur qui vas donner l'id au nouveaux ouvrages

public:
    static int id_compteur;
    bibliotheque();
    int ajoute(ouvrage *);
    void afficherObjets();
    unsigned int size() { return id_compteur; };
    // chaque fois un nouveau object est creer le compteur est incrementer
    // decrementer a la suppression
    void supprimer(int id);
    ~bibliotheque();
    ouvrage &operator[](int index);
};
int bibliotheque::id_compteur = 0;
bibliotheque::bibliotheque() : compteur(0)
{
}

void bibliotheque::supprimer(int id)
{
    for (int i = 0; i < compteur; ++i)
    {

        cout << id + 1 << ouvrages[i]->getId() << endl;
        if (ouvrages[i]->getId() == id + 1)
        {
            // Supprimer l'ouvrage et décaler les éléments suivants
            delete ouvrages[i];
            for (int j = i; j < compteur - 1; ++j)
            {
                ouvrages[j] = ouvrages[j + 1];
            }
            id_compteur = id_compteur - 1;
            return; // Sortir de la boucle si l'ouvrage a été trouvé et supprimé
        }
    }
}
bibliotheque::~bibliotheque()
{
    for (int i = 0; i < compteur; ++i)
    {
        delete ouvrages[i];
    }
}

/*j'ai creer un id_compteur static
pour qu'il ne depond pas de l'object mais de toute la class
et car compteur vas decrementer si un ouvrage est supprimer
donc j'aurais une collision d'id */

int bibliotheque::ajoute(ouvrage *objet)
{
    if (compteur < MAX_OUVRAGES)
    {
        ouvrages[compteur] = objet;
        ++compteur;
        id_compteur++;
        objet->setId(id_compteur);
        return id_compteur;
    }
    else
    {
        throw out_of_range("Limite d'ouvrages atteinte");
    }
}

void bibliotheque::afficherObjets()
{
    for (int i = 0; i < id_compteur; ++i)
    {
        cout << "i = " << i << "id_compteur " << id_compteur << endl;
        ouvrages[i]->afficher();
    }
}

/*surcharge de l'operateur [ ] pour acceder au element de l'object*/
ouvrage &bibliotheque::operator[](int index)
{
    if (index >= 0 && index < compteur)
    {
        return *ouvrages[index];
    }
    else
    {
        throw out_of_range("Index hors limites");
    }
}
