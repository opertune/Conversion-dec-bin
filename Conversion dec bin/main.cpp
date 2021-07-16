/**
* Conversion decimal - binaire
* Author : Opertune
* Date : 17/10/2019
*/

#include <iostream>
#include <math.h>
#include <string>
#include <sstream>

using namespace std;

int main()
{
    // D�claration
    char choix;
    string binaire;
    int nb;

    // Boucle sur le menu
    choix = 'Z';
    while (choix != 'Q' && choix != 'q')
    {
        cout << endl << "Conversion entier vers binaire [1]";
        cout << endl << "Conversion binaire vers entier [2]";
        cout << endl << "quitter ...................... [Q]";
        cout << endl << "votre choix................... ";
        cin >> choix;

        // Conversion entier vers binaire
        if (choix == '1')
        {
            binaire = "";
            cout << "Entrer un entier : ";
            cin >> nb;
            while (nb != 0)
            {
                // r�cup�ration du reste et conversion en caract�re
                char c = (nb%2) + '0';

                // concat�nation du caract�re
                binaire = c + binaire;
                nb = nb/2;
            }
            cout << "conversion en binaire = " + binaire;
        }
        else
        {
            // Conversion binaire vers entier
            if (choix == '2')
            {
                nb = 0;
                int k = 0;
                cout << endl << "Entrer un nombre binaire : ";
                cin >> binaire;
                while (binaire.size() > 0)
                {
                    // extration du dernier caract�re de binaire
                    string s = binaire.substr(binaire.size()-1, 1) ;
                    istringstream myStream(s);
                    int result ;

                    // conversion du caract�re en entier
                    myStream>>result ;

                    // ajout dans nb du bit r�cup�r� multipli� par la puissance de 2
                    nb += result * pow(2, k) ;

                    // on enl�ve le dernier caract�re
                    binaire = binaire.substr(0, binaire.size()-1) ;
                    k++ ;
                }
                cout << "Conversion en base 10 = " << nb;
            }
        }
    }
}
