#include "fonction_header.h"

class PeriodiqueExterne : public Periodique
{
private:
    string origine;

public:
    PeriodiqueExterne(string, string, string, string, string, string, string);
    PeriodiqueExterne(string, string, string, string);
    void afficher() const override;
    void setDispo(bool);
    void emprunt(string, string);
    void update();
    void update_source();
    string getnom() override;
    string get_type() override;
    ~PeriodiqueExterne();
};

PeriodiqueExterne::PeriodiqueExterne(string n_nom,
                                     string n_date,
                                     string n_maison,
                                     string nom_empreinteur,
                                     string date_empreinte,
                                     string new_editeur,
                                     string new_origine)
    : Periodique(n_nom, n_date, n_maison, nom_empreinteur, date_empreinte, new_editeur),
      origine(new_origine)
{
    type = "Journal Externe";
    if (nom_empreinteur != "null")
    {
        setDispo(false);
    }
}

PeriodiqueExterne::PeriodiqueExterne(string n_nom,
                                     string n_date,
                                     string n_maison,
                                     string new_origine)
    : Periodique(n_nom, n_date, n_maison), origine(new_origine)
{
    type = "Journal Externe";
}

PeriodiqueExterne::~PeriodiqueExterne()
{
}
string PeriodiqueExterne::getnom()
{
    return this->nom;
}
string PeriodiqueExterne::get_type()
{
    return this->type;
}

void PeriodiqueExterne::afficher() const
{
    Periodique::afficher();

    cout << "provenant de " << origine << endl;
}

inline void PeriodiqueExterne::setDispo(bool b)
{
    Periodique::setDispo(b);
}

inline void PeriodiqueExterne::emprunt(string date, string nom)
{
    Periodique::emprunt(date, nom);
}

inline void PeriodiqueExterne::update()
{
    Periodique::update();
    update_source();
}
inline void PeriodiqueExterne::update_source()
{
    updateField("biblotheque source", origine);
}
