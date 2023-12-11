#include "fonction_header.h"

class LivreExterne : public livre
{
private:
    string origine;

public:
    LivreExterne(string, string, string, string, string, string, string, string);
    LivreExterne();
    void afficher() const override;
    void setDispo(bool);
    void emprunt(string, string);
    void update();
    void update_source();
    string getnom() override;
    string get_type() override;
    ~LivreExterne();
};
string LivreExterne::getnom()
{
    return this->nom;
}
string LivreExterne::get_type()
{
    return this->type;
}
LivreExterne::LivreExterne(string new_nom,
                           string new_date,
                           string new_nom_edition,
                           string new_nom_auteur,
                           string new_maisson, string nom_empreinteur, string date_empreinte, string new_origine)
    : origine(new_origine),
      livre(new_nom_auteur,
            new_nom_edition,
            new_maisson)
{
    nom = new_nom;
    date = new_date;
    nom_editeur = "null";
    nom_emprinte = nom_empreinteur;
    date_empreint = date_empreinte;
    type = "livre externe";
}
LivreExterne::LivreExterne(/* args */)
{
}

void LivreExterne::afficher() const
{
    livre::afficher();

    cout << "provenant de " << origine << endl;
}

inline void LivreExterne::setDispo(bool b)
{
    livre::setDispo(b);
}

inline void LivreExterne::emprunt(string date, string nom)
{
    livre::emprunt(date, nom);
}

inline void LivreExterne::update()
{
    livre::update();
    update_source();
}
inline void LivreExterne::update_source()
{
    updateField("biblotheque source", origine);
}

LivreExterne::~LivreExterne()
{
}
