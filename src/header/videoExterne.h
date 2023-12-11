#include "fonction_header.h"

class videoExterne : public video
{
private:
    string origine;

public:
    videoExterne(string, string, string, int, string, string, string, string, string);
    videoExterne();
    void afficher() const override;
    void setDispo(bool);
    void emprunt(string, string);
    void update();
    void update_source();
    string getnom() override;
    string get_type() override;
    ~videoExterne();
};
videoExterne::videoExterne(string new_nom,
                           string new_anne_apparition,
                           string new_nom_auteur,
                           int n_duree,
                           string new_maisson, string nom_empreinteur, string date_empreinte, string new_origine, string new_editeur)
    : origine(new_origine),
      video(new_nom,
            new_anne_apparition,
            new_nom_auteur,
            new_maisson, n_duree, nom_empreinteur, date_empreinte, new_editeur)
{

    type = "video externe";
    if (nom_empreinteur != "null")
    {
        setDispo(false);
    }
}
videoExterne::videoExterne(/* args */)
{
}

string videoExterne::getnom()
{
    return this->nom;
}
string videoExterne::get_type()
{
    return this->type;
}

void videoExterne::afficher() const
{
    video::afficher();

    cout << "provenant de " << origine << endl;
}

inline void videoExterne::setDispo(bool b)
{
    video::setDispo(b);
}

inline void videoExterne::emprunt(string date, string nom)
{
    video::emprunt(date, nom);
}

inline void videoExterne::update()
{
    video::update();
    update_source();
}
inline void videoExterne::update_source()
{
    updateField("biblotheque source", origine);
}

videoExterne::~videoExterne()
{
}