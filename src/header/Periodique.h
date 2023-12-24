#include "fonction_header.h"

class Periodique : public ouvrage
{
private:
    string maison;

public:
    Periodique(string, string, string);
    Periodique(string, string, string, string, string, string);
    Periodique(const Periodique &);
    void operator=(const Periodique &);
    void afficher() const override;
    void emprunt(string, string) override;
    void setDispo(bool) override;
    void update() override;
    void setId(int) override;

    string getnom() override;
    string get_type() override;
    ~Periodique();
};
void Periodique::setId(int var)
{
    id = var;
}
string Periodique::getnom()
{
    return this->nom;
}
string Periodique::get_type()
{
    return this->type;
}
Periodique::Periodique(const Periodique &v)
{
    this->date = v.date;
    this->maison = v.maison;
    this->disponible = v.disponible;
    this->nom = v.nom;
    this->nom_emprinte = v.nom_emprinte;
    this->nom_editeur = v.nom_editeur;
    this->date_empreint = v.date_empreint;
    this->type = v.type;
    this->id = v.id;
}
inline void Periodique::operator=(const Periodique &v)
{
    this->date = v.date;
    this->maison = v.maison;
    this->disponible = v.disponible;
    this->nom = v.nom;
    this->nom_emprinte = v.nom_emprinte;
    this->nom_editeur = v.nom_editeur;
    this->date_empreint = v.date_empreint;
    this->type = v.type;
    this->id = v.id;
}
Periodique::Periodique(string n_nom, string n_date, string n_maison)
    : ouvrage(n_nom, n_date, "null", "null", "null"), maison(n_maison)
{
    type = "Journal";
}
Periodique::Periodique(string n_nom, string n_date, string n_maison, string n_nom_emprinte, string n_date_empreint, string n_editeur)
    : ouvrage(n_nom, n_date, n_nom_emprinte, n_date_empreint, n_editeur), maison(n_maison)
{
    type = "Journal";
}
inline void Periodique::emprunt(string n_date, string n_nom_empreint)
{
    nom_emprinte = n_nom_empreint;
    date_empreint = n_date;
}
inline void Periodique::afficher() const
{
    string disp;
    disp = disponible ? "disponible" : "indisponible";

    cout << type << " : " << endl;
    cout << "id : " << id << endl;
    cout << "\t" << nom << " de " << date << endl;
    cout << "\tpublie par " << maison << endl;
    if (nom_editeur != "null")
    {
        cout << "\tediter par " << nom_editeur << endl;
    }
    cout << disp << endl;
    if (nom_emprinte != "null")
    {
        cout << "empreinter par " << nom_emprinte << " le " << date_empreint << endl;
    }
}
inline void Periodique::setDispo(bool disp)
{
    disponible = disp;
}

inline void Periodique::update()
{
    /*
   je vais creer un copie ce mon object
   pour faire dessus les modification
   si l'utilisateur est satisfait
   il peux choisir d'enregister a la fin */
    Periodique p(*this);

    int a = 0;
    cout << "modification du journal sous le non " << nom << endl;
    vector<string> t1 = {"nom", "date", "maison", "empreinter(oui/non)", "nom de l'editeur"};
    for (int i = 0; i < t1.size(); i++)
    {
        cout << i + 1 << ": modifier " << t1[i] << endl;
    }
    cin >> a;
    cin.ignore(); // Ignorer le caractère de nouvelle ligne restant dans le buffer

    switch (a)
    {
    case 1:
    {
        updateField("nom", p.nom);
        break;
    }
    case 2:
    {
        updateField("date", p.date);
        break;
    }
    case 3:
    {
        updateField("maison", p.maison);
        break;
    }
    case 4:
    {
        UpdateEmpreint(p.nom_emprinte, p.date_empreint, p.disponible);
        break;
    }
    case 5:
        updateField("nom de l'editeur", p.nom_editeur);
        break;
    default:
        cout << "Choix non valide." << endl;
        break;
    }
    cout << "resultat final :" << endl;
    p.afficher();
    string var;
    cout << "enregister ? (oui/non)" << endl;
    getline(cin, var);
    cout << var << endl;
    if (var == "oui")
    {
        *this = p;
    }
    else
    {
        cout << "anullation" << endl;
    }
}
Periodique::~Periodique()
{
}
