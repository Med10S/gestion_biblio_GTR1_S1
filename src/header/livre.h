#include <iostream>
#include <vector>
#include "fonction_header.h"

using namespace std;
class livre : virtual public ouvrage
{
protected:
    string auteur;
    string nom_edition;
    string maison;

public:
    livre();
    livre(const livre &);
    void operator=(const livre &);
    livre(string, string, string);
    livre(string, string, string, string, string);
    livre(string, string, string, string, string, string, string);
    void afficher() const override;
    void emprunt(string, string) override;
    void setDispo(bool) override;
    void update() override;
    void setId(int) override;

    string getnom() override;
    string get_type() override;

    ~livre();
};
void livre::setId(int var)
{
    id = var;
}
string livre::getnom()
{
    return this->nom;
}
string livre::get_type()
{
    return this->type;
}
inline void livre::operator=(const livre &l)
{
    this->auteur = l.auteur;
    this->date = l.date;
    this->maison = l.maison;
    this->disponible = l.disponible;
    this->nom = l.nom;
    this->nom_emprinte = l.nom_emprinte;
    this->nom_editeur = l.nom_editeur;
    this->date_empreint = l.date_empreint;
    this->nom_edition = l.nom_edition;
    this->type = l.type;
}

void livre::emprunt(string n_date, string n_nom_empreint)
{
    nom_emprinte = n_nom_empreint;
    date_empreint = n_date;
}

livre::livre()
{
}

inline livre::livre(const livre &l)
{

    this->auteur = l.auteur;
    this->date = l.date;
    this->maison = l.maison;
    this->disponible = l.disponible;
    this->nom = l.nom;
    this->nom_emprinte = l.nom_emprinte;
    this->nom_editeur = l.nom_editeur;
    this->date_empreint = l.date_empreint;
    this->nom_edition = l.nom_edition;
    this->type = l.type;
}
livre::livre(string new_auteur, string n_nom_edition, string n_maison)
{
    auteur = new_auteur;
    nom_edition = n_nom_edition;
    maison = n_maison;

    type = "livre";
}

livre::livre(string new_nom,
             string new_date,
             string new_nom_edition,
             string new_nom_auteur,
             string new_maisson, string nom_empreinteur, string date_empreinte)
    : ouvrage(new_nom, new_date, nom_empreinteur, date_empreinte, "null"), auteur(new_nom_auteur), nom_edition(new_nom_edition), maison(new_maisson) { type = "livre"; }

livre::livre(string new_nom,
             string new_date,
             string new_nom_edition,
             string new_nom_auteur,
             string new_maisson)
    : ouvrage(new_nom, new_date),
      auteur(new_nom_auteur),
      nom_edition(new_nom_edition),
      maison(new_maisson)
{
    nom_editeur = "null";
    type = "livre";
}

void livre::afficher() const
{
    string disp;
    disp = disponible ? "disponible" : "indisponible";

    cout << type << " : " << endl;
    cout << "id : " << id << endl;

    cout << "\t" << nom << " " << nom_edition << endl;
    cout << "\tpar " << auteur << endl;
    cout << "\tpublie en " << date << " par " << maison << endl;
    if (nom_editeur != "null")
    {
        cout << "\tediter par " << nom_editeur << endl;
    }
    cout << disp << endl;
    if (!disponible)
    {
        cout << "empreinter par " << nom_emprinte << " le " << date_empreint << endl;
    }
}
inline void livre::setDispo(bool disp)
{
    disponible = disp;
}
inline void livre::update()
{
    /*
    je vais creer un copie ce mon object
    pour faire dessus les modification
    si l'utilisateur est satisfait
    il peux choisir d'enregister a la fin */
    livre l(*this);
    int a = 0;
    cout << "modification du livre sous le non " << nom << endl;
    vector<string> t1 = {"nom", "date", "maison d'edition", "auteur", "nom de l'edition", "empreinter(oui/non)", "nom de l'editeur"};
    for (size_t i = 0; i < t1.size(); i++)
    {
        cout << i + 1 << ": modifier " << t1[i] << endl;
    }
    cin >> a;
    cin.ignore(); // Ignorer le caractère de nouvelle ligne restant dans le buffer

    switch (a)
    {
    case 1:
    {
        updateField("nom", l.nom);
        break;
    }
    case 2:
    {
        updateField("date", l.date);
        break;
    }
    case 3:
    {
        updateField("maison", l.maison);
        break;
    }
    case 4:
        updateField("auteur", l.auteur);
        break;
    case 5:
        updateField("nom de l'edition", l.nom_edition);
        break;
    case 6:

        UpdateEmpreint(l.nom_emprinte, l.date_empreint, l.disponible);
        break;

    case 7:
        updateField("nom de l'editeur", l.nom_editeur);
        break;

    default:
        cout << "Choix non valide." << endl;
        break;
    }
    cout << "resultat final :" << endl;
    l.afficher();
    string var;
    cout << "enregister ? (oui/non)" << endl;
    getline(cin, var);
    cout << var << endl;
    if (var == "oui")
    {
        *this = l;
    }
    else
    {
        cout << "anullation" << endl;
    }
}
livre::~livre()
{
}
