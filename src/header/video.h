#include "fonction_header.h"

class video : public ouvrage
{
private:
    string auteur;
    int duree;
    string maison;

public:
    video(string, string, string, string, int);
    video(string, string, string, string, int, string, string, string);
    video(string, int, string);
    video(const video &);
    video(/* args */);
    void afficher() const override;
    void setDispo(bool) override;
    void emprunt(string, string) override;
    void update() override;
    void setId(int) override;
    string getnom() override;
    string get_type() override;
    void operator=(const video &v1);
    ~video();
};

video::video(string n_auteur, int n_dure, string n_maison)
{
    auteur = n_auteur;
    duree = n_dure;
    maison = n_maison;
}
video::video(const video &v)
{
    this->auteur = v.auteur;
    this->date = v.date;
    this->maison = v.maison;
    this->disponible = v.disponible;
    this->nom = v.nom;
    this->nom_emprinte = v.nom_emprinte;
    this->nom_editeur = v.nom_editeur;
    this->duree = v.duree;
    this->date_empreint = v.date_empreint;
    this->type = v.type;
    this->id = v.id;
}
video::video(string new_nom,
             string new_anne_apparition,
             string new_auteur,
             string n_maison, int new_duree) : ouvrage(new_nom, new_anne_apparition, "null", "null", "null"),
                                               auteur(new_auteur),
                                               maison(n_maison),
                                               duree(new_duree)
{
    type = "video";
}
video::video(string new_nom,
             string new_anne_apparition,
             string new_auteur,
             string n_maison, int new_duree, string n_nom_emprinte, string date_empreint, string new_editeur)
    : ouvrage(new_nom, new_anne_apparition, n_nom_emprinte, date_empreint, new_editeur),
      auteur(new_auteur),
      maison(n_maison),
      duree(new_duree)
{
    type = "video";
}
video::video(/* args */)
{
}
video::~video()
{
}

inline void video::operator=(const video &v)
{
    this->auteur = v.auteur;
    this->date = v.date;
    this->maison = v.maison;
    this->disponible = v.disponible;
    this->nom = v.nom;
    this->nom_emprinte = v.nom_emprinte;
    this->nom_editeur = v.nom_editeur;
    this->duree = v.duree;
    this->type = v.type;
    this->id = v.id;

    this->date_empreint = v.date_empreint;
}

inline void video::update()
{
    /*
    je vais creer un copie ce mon object
    pour faire dessus les modification
    si l'utilisateur est satisfait
    il peux choisir d'enregister a la fin */
    video v(*this);

    int a = 0;
    cout << "modification de la video sous le non " << nom << endl;
    vector<string> t1 = {"nom", "date", "maison", "empreinter", "auteur", "duree", "nom de l'editeur"};
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
        updateField("nom", v.nom);
        break;
    }
    case 2:
    {
        updateField("date", v.date);
        break;
    }
    case 3:
    {
        updateField("maison", v.maison);
        break;
    }
    case 4:

        UpdateEmpreint(v.nom_emprinte, v.date_empreint, v.disponible);
        break;
    case 5:
        updateField("auteur", v.auteur);
        break;
    case 6:
    {
        int var = 0;
        cout << "modification de la duree : " << endl;
        cin >> var;
        v.duree = var;
        // TODO : ajouter une verification de la valeur entre par l'utlisateur
        break;
    }
    case 7:
        updateField("nom de l'editeur", v.nom_editeur);
        break;

    default:
        cout << "Choix non valide." << endl;
        break;
    }
    cout << "resultat final :" << endl;
    v.afficher();
    string var;
    cout << "enregister ? (oui/non)" << endl;
    getline(cin, var);
    cout << var << endl;
    if (var == "oui")
    {
        *this = v;
    }
    else
    {
        cout << "anullation" << endl;
    }
}

inline void video::setDispo(bool disp)
{
    disponible = disp;
}
void video::setId(int var)
{
    id = var;
}
string video::getnom()
{
    return this->nom;
}
string video::get_type()
{
    return this->type;
}

inline void video::emprunt(string n_date, string n_nom_empreint)
{
    nom_emprinte = n_nom_empreint;
    date_empreint = n_date;
}
inline void video::afficher() const
{
    string disp;
    disp = disponible ? "disponible" : "indisponible";

    cout << type << " : " << endl;
    cout << "id : " << id << endl;
    cout << "\t" << nom << endl;
    cout << "\tpar " << auteur << endl;
    cout << "\tpublier en " << date << " par " << maison << endl;
    cout << "\tduree : " << duree << " minutes" << endl;
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
