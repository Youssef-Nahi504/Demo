#include <stdio.h>

#define maxEtudiants 1000

typedef struct Ex_Gestion_Etu
{
    int code_massar;
    char nom[15];
    char prenom[15];
    int age;
    float note;
} etudiant;

etudiant list_Etudiant[maxEtudiants];

int nbEtudiants = 0;

void ajouterEtudiant()
{

    etudiant etudiant1;

    printf("Entrer votre code massar : ");
    scanf("%d", &etudiant1.code_massar);

    printf("Entrer votre nom : ");
    scanf("%s", etudiant1.nom);

    printf("Entrer votre prenom : ");
    scanf("%s", etudiant1.prenom);

    printf("Entrer votre age : ");
    scanf("%d", &etudiant1.age);

    printf("Entrer votre note : ");
    scanf("%f", &etudiant1.note);

    list_Etudiant[nbEtudiants] = etudiant1;
    nbEtudiants++;
}
void ModifierEtudiant()
{

    int cm;
    int index_exist = -1;
    printf("Entrer votre code massar : ");
    scanf("%d", &cm);
    for (int i = 0; i < nbEtudiants; i++)
    {
        if (list_Etudiant[i].code_massar == cm)
        {
            index_exist = i;
        }
    }
    if (index_exist == -1)
    {
        printf("Code Massar n'existe pas !");
    }
    else
    {
        printf("Entrer votre code massar : ");
        scanf("%d", &list_Etudiant[index_exist].code_massar);

        printf("Entrer votre nom : ");
        scanf("%s", list_Etudiant[index_exist].nom);

        printf("Entrer votre prenom : ");
        scanf("%s", list_Etudiant[index_exist].prenom);

        printf("Entrer votre age : ");
        scanf("%d", &list_Etudiant[index_exist].age);

        printf("Entrer votre note : ");
        scanf("%f", &list_Etudiant[index_exist].note);
    }
}
void SupprimerEtudiant()
{
}

void ExporterListesEtudiants()
{

    FILE *FichierListeEtudiants = fopen("FichierListeEtudiants.txt", "w");

    for (int i = 0; i < nbEtudiants; i++)
    {
        if (FichierListeEtudiants != NULL)
        {
            fprintf(FichierListeEtudiants, "%s;%s;%s;%d;%.2f\n"),
                list_Etudiant[i].code_massar,
                list_Etudiant[i].nom,
                list_Etudiant[i].prenom,
                list_Etudiant[i].age,
                list_Etudiant[i].note;
        }
        fclose(FichierListeEtudiants);
        printf("Donnees exportees avec succes dans %s.\n\n", FichierListeEtudiants);
    }
}

void ImporterListeEtudiants()
{
    FILE *FichierEtudiants = fopen("FichierListeEtudiants.txt", "r");
    while (fscanf(FichierEtudiants, "%s;%s;%s;%d;%.2f\n",
                  list_Etudiant[nbEtudiants].code_massar,
                  list_Etudiant[nbEtudiants].nom,
                  list_Etudiant[nbEtudiants].prenom,
                  list_Etudiant[nbEtudiants].age,
                  list_Etudiant[nbEtudiants].note) != EOF)
    {
        nbEtudiants++;
    }
    fclose(FichierEtudiants);
    printf(">>>> %d Etudiants importees",nbEtudiants);
}

void Afficher_liste_Etudiants()
{
    for (int i = 0; i < nbEtudiants; i++)
    {

        printf("etudiant %d ==> code: %d - Nom complet: %s %s - age:%d - note:%f",
               (i + 1),
               list_Etudiant[i].code_massar,
               list_Etudiant[i].nom,
               list_Etudiant[i].prenom,
               list_Etudiant[i].age,
               list_Etudiant[i].note);
    }
}

void Quitter()
{
}
void menu()
{
    int choix;
    do
    {

        printf("1 : Ajouter un etudiant\n");
        printf("2 : Modifier un etudiant\n");
        printf("3 : Suprrimer un etudiant\n");
        printf("4 : Afficher liste des etudiant\n");
        printf("5 : Quitter\n");
        printf("6 : Importer liste des etudiant\n");
        printf("7 : Exporter liste des etudiant\n");
        printf("Quelle option voulez vous choisir : ");
        scanf("%d", &choix);

        switch (choix)
        {
        case 1:
            ajouterEtudiant();
            break;
        case 2:
            ModifierEtudiant();
            break;
        case 3:
            SupprimerEtudiant();
            break;
        case 4:
            Afficher_liste_Etudiants();
            break;
        case 5:
            Quitter();
            break;
        case 6:
            ImporterListeEtudiants();
            break;
        case 7:
            ExporterListesEtudiants();
            break;

        default:
            break;
        }
    } while (choix != 5);
}

int main()
{

     menu();
    /*FILE *fp1, *fp2;

    if((fp1 = fopen("titi.txt","r")) != NULL){
        if ((fp2 = fopen("titibis.txt","w")) != NULL){
           int c = 0;
           int p = 0;
           while (c!=EOF && p!=EOF){
            c = getc(fp1);
            p = putc(c,fp2);
            printf("%c:%c\n",p,c);
            printf("%d:%d\n",p,c);
           }
        }
    }
    if (fp1 != NULL) fclose(fp1);
    if (fp2 != NULL) fclose(fp2);

    FILE *fptr;

     Open a file in writing mode
    fptr = fopen("filename.txt", "w");

     Write some text to the file
    for (int i = 1; i <= 100; i++)
    {
        fprintf(fptr, "%d some text\n",i);
    }


     Close the file
    fclose(fptr);

    FILE *fptr;

    fptr = fopen("filename.txt", "r");

    int a,b,c;

    while(fscanf(fptr,"%d %d %d \n", &a , &b ,&c) != EOF){
        printf("%d %d %d \n",a,b,c);
    }

    fclose(fptr);*/
    return 0;
}

