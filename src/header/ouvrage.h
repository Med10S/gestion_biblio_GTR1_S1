#include <iostream>
#include "fonction_header.h"

using namespace std;
class ouvrage
{
protected:
    bool disponible;
    string nom;
    string date;
    string nom_emprinte;
    string date_empreint;
    string nom_editeur;
    string type;
    int id;

public:
    ouvrage(string, string);
    ouvrage(string, string, string, string, string);
    ouvrage(string, string, string);
    ouvrage(/* args */);
    /*des methodes viruales pure */
    virtual void afficher() const = 0;
    virtual void setDispo(bool) = 0;
    virtual void emprunt(string, string) = 0;
    virtual void update() = 0;
    virtual string getnom() = 0;
    virtual string get_type() = 0;
    virtual void setId(int) = 0;
    virtual int getId() { return id; };
    void supprimer(int);

    ~ouvrage();
};

inline ouvrage::ouvrage(string n_nom, string n_date, string n_nom_emprinte, string n_date_empreint, string new_editeur)
    : nom(n_nom), date(n_date),
      nom_emprinte(n_nom_emprinte),
      date_empreint(n_date_empreint), nom_editeur(new_editeur)
{
    disponible = true;
}
inline ouvrage::ouvrage(string n_nom, string n_date) : nom(n_nom), date(n_date)
{
    disponible = true;
}
inline ouvrage::ouvrage(string n_nom, string n_nom_editeur, string n_date)
    : nom(n_nom), nom_editeur(n_nom_editeur), date(n_date)
{
    disponible = true;
}

ouvrage::ouvrage(/* args */)
{
}

inline void ouvrage::supprimer(int index)
{
}

ouvrage::~ouvrage()
{
}
