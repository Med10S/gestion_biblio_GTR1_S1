#include <iostream>
#include <string.h>
using namespace std;

/// @brief elle permet de demander a l'utlisateur une valeur string a enter et elle enregistre cette
/// valeur dans l'address memoire passer dans le deuxieme argument
/// @param fieldName le nom a afficher de l'attribue a modiffier
/// @param field la refference de l'attribue a modifier
void updateField(const string &fieldName, string &field);

/// @brief elle permet de modifier ou de supprimer l'empriente
/// @param nom_empreinteur la refference de l'attribue nom_emprinte de ouvrage
/// @param date_empreinte la refference de l'attribue date_empreint de ouvrage
/// @param disp la refference de l'attribue disponible de ouvrage
void UpdateEmpreint(string &nom_empreinteur, string &date_empreinte, bool &disp);