#include <iostream>
#include <string>
#include<fstream>
using namespace std;
int main()
{

    string cle,mot,crypt;
    char cle_asc;
    int val,decodeasc,longueur_mot,valeur_ascii,longueur_cle,j(-1),choix;
    cout<<"Vous avez la possibilite d'ecrire un mot à crypter ou choisir un fichier\n";
    cout<<"1- Ecrire fichier\n";
    cout<<"2- Fichier\n";
    cout<<"Faites votre choix:";
    cin>>choix;
    switch(choix){
    case 1:
        cout<<"Entrer des majuscules pour aider\n";
        cout<<"Entrez la cle de cryptage : ";
        cin>>cle;
        cout<<"Entrez le mot a crypter par cette cle : ";
        cin>>mot;
        longueur_cle=cle.length();
        longueur_mot=mot.size();
        for(int i=0;i<longueur_mot;i++)
        {
            j+=1;
            if(j>longueur_cle-1)
            {
                j=0;
            }
            cle_asc=int(cle[j]);
            val =cle_asc-65;
            decodeasc=int(mot[i]);
           if((decodeasc+val)>90)
            {
                int plus=(decodeasc+val)-90;
                valeur_ascii=65+plus-1;
            }
            else
            {
                valeur_ascii=decodeasc+val;
            }
            crypt+=char(valeur_ascii);
        }

        cout<<"Le cryptyage de "<<mot<<" est : "<<crypt;
        break;
    case 2:
        fstream lecture_fichier("crypto.txt",ios::in);
        string line;
         cout<<"Entrez la cle de cryptage : ";
        cin>>cle;
        while(getline(lecture_fichier,line)){
        longueur_mot=line.size();
         for(int i=0;i<longueur_mot;i++)
        {
            j+=1;
            if(j>longueur_cle-1)
            {
                j=0;
            }
            cle_asc=int(cle[j]);
            val =cle_asc-65;
            decodeasc=int(line[i]);
           if((decodeasc+val)>90)
            {
                int plus=(decodeasc+val)-90;
                valeur_ascii=65+plus-1;
            }
            else
            {
                valeur_ascii=decodeasc+val;
            }
            crypt+=char(valeur_ascii);
        }

        }
        cout<<"La cyptographie de "<<line<<" est:"<<crypt;


    }

}
