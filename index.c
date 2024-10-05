#include <stdio.h>
#include <string.h>
#include <stdlib.h> 

#define MAXRESERVATIONS 100


struct Date {
    int day;
    int month;
    int year;
};

struct Reservation {
    char reference[20];
    char nom[20];
    char prenom[20];
    int age;
    char telephone[10];
    struct Date date;
    char statut[20];
};

struct Reservation reservations[MAXRESERVATIONS];

int reservationsCounter = 4;

int afficherTousLesReservations() {
    system("cls");

    if (reservationsCounter>= MAXRESERVATIONS) {
      printf("+------------------------------------------------------+\n");
      printf("| Aucune Reservation Trouver. Veuillez En Ajouter Une. |\n");
      printf("+------------------------------------------------------+\n");
      return 1;
    }

    printf("+---------------------------------------------------------------------------------------------------------------------------+\n");
    printf("|                                                     List Des Reservations                                                 |\n");
    printf("+----------------------+----------------------+----------------------+-----+------------+------------+----------------------+\n");
    printf("|       Reference      |         Nom          |        Prenom        | Age |  Telephone |    Date    |         Statut       |\n");
    printf("+----------------------+----------------------+----------------------+-----+------------+------------+----------------------+\n");

    for (int i = 0; i < reservationsCounter; i++) {
        printf("| %-20s | %-20s | %-20s | %-3i | %-10s | %02d/%02d/%04d | %-20s | \n", 
               reservations[i].reference, 
               reservations[i].nom, 
               reservations[i].prenom, 
               reservations[i].age, 
               reservations[i].telephone, 
               reservations[i].date.day, 
               reservations[i].date.month, 
               reservations[i].date.year, 
               reservations[i].statut);
        printf("+----------------------+----------------------+----------------------+-----+------------+------------+----------------------+\n");    }
}

int afficherUneReservation(){
    system("cls");

    if (reservationsCounter>= MAXRESERVATIONS) {
      printf("+------------------------------------------------------+\n");
      printf("| Aucune Reservation Trouver. Veuillez En Ajouter Une. |\n");
      printf("+------------------------------------------------------+\n");
      return 1;
    }

    printf("+--------------------------+\n");
    printf("| Afficher Une Reservation |\n");
    printf("+--------------------------+\n");
    char reference[20];
    printf("[+] Entrer Le Reference De La Reservation : ");
    scanf("%s", &reference);
    printf("[+] Recherche...\n");
    for(int index = 0; index < reservationsCounter; index++){
      if(strcmp(reservations[index].reference, reference) == 0){
        printf("[+] Reservation Trouvee \n");
        printf("+---------------------------------------------------------------------------------------------------------------------------+\n");
        printf("|                                                     Reservation %-6s                                                    |\n", reservations[index].reference);
        printf("+----------------------+----------------------+----------------------+-----+------------+------------+----------------------+\n");
        printf("|       Reference      |         Nom          |        Prenom        | Age |  Telephone |    Date    |         Statut       |\n");
        printf("+----------------------+----------------------+----------------------+-----+------------+------------+----------------------+\n");
        printf("| %-20s | %-20s | %-20s | %-3i | %-10s | %-2d/%-2d/%-4d | %-20s | \n", 
        reservations[index].reference, 
        reservations[index].nom, 
        reservations[index].prenom, 
        reservations[index].age, 
        reservations[index].telephone, 
        reservations[index].date.day, 
        reservations[index].date.month, 
        reservations[index].date.year, 
        reservations[index].statut);
        printf("+----------------------+----------------------+----------------------+-----+------------+------------+----------------------+\n");
        return 1;
      }
    }
    printf("[+] Reservation Introuvable\n");
}

int ajouterUneReservation(){
    system("cls");

    if (reservationsCounter>= MAXRESERVATIONS) {
      printf("+------------------------------------------------------+\n");
      printf("| Aucune Reservation Trouver. Veuillez En Ajouter Une. |\n");
      printf("+------------------------------------------------------+\n");
      return 1;
    }

    struct Reservation newReservation;
    sprintf(newReservation.reference, "REF%03d", reservationsCounter + 1);
    printf("+-------------------------+\n");
    printf("| Ajouter Une Reservation |\n");
    printf("+-------------------------+\n");
    printf("[+] REF : %s\n", newReservation.reference);
    printf("[+] Nom : ");
    scanf("%s", newReservation.nom);
    printf("[+] Prenom : ");
    scanf("%s", newReservation.prenom);
    printf("[+] Age : ");
    scanf("%i", &newReservation.age);
    printf("[+] Numero De Telephone : ");
    scanf("%s", newReservation.telephone);
    printf("[+] Date (DD/MM/YYYY) : ");
    scanf("%i/%i/%i", &newReservation.date.day, &newReservation.date.month, &newReservation.date.year);

    int statut;
    printf("[+] Statut : \n");
    printf("  [+] 1. Valide\n");
    printf("  [+] 2. Reporte\n");
    printf("  [+] 3. Annule\n");
    printf("  [+] 4. Traite\n");
    printf(">>> ");
    scanf("%i", &statut);
    switch (statut) {
        case 1:
            strcpy(newReservation.statut, "Valide");
            break;
        case 2:
            strcpy(newReservation.statut, "Reporte");
            break;
        case 3:
            strcpy(newReservation.statut, "Annule");
            break;
        case 4:
            strcpy(newReservation.statut, "Traite");
            break;
        default:
            printf("[+] Commande Non Valide. Veuillez Reessayer.\n");
            return 1; 
    }

    reservations[reservationsCounter ++] = newReservation;

    printf("[+] Reservation Ajoutee Avec Succes \n");
}

int modifierUneReservation(){
    system("cls");

    if (reservationsCounter>= MAXRESERVATIONS) {
      printf("+------------------------------------------------------+\n");
      printf("| Aucune Reservation Trouver. Veuillez En Ajouter Une. |\n");
      printf("+------------------------------------------------------+\n");
      return 1;
    }

    printf("+--------------------------+\n");
    printf("| Modifier Une Reservation |\n");
    printf("+--------------------------+\n");
    char reference[20];
    printf("[+] Entrer Le Reference De La Reservation : ");
    scanf("%s", &reference);
    printf("[+] Recherche...\n");
    int found;
    int index;
    for(index = 0; index < reservationsCounter; index++){
      if(strcmp(reservations[index].reference, reference) == 0){
        printf("[+] Reservation Trouvee\n");
        printf("+---------------------------------------------------------------------------------------------------------------------------+\n");
        printf("|                                                     List Des Reservations                                                 |\n");
        printf("+----------------------+----------------------+----------------------+-----+------------+------------+----------------------+\n");
        printf("|       Reference      |         Nom          |        Prenom        | Age |  Telephone |    Date    |         Statut       |\n");
        printf("+----------------------+----------------------+----------------------+-----+------------+------------+----------------------+\n");
        printf("| %-20s | %-20s | %-20s | %-3i | %-10s | %-2d/%-2d/%-4d | %-20s | \n", 
        reservations[index].reference, 
        reservations[index].nom, 
        reservations[index].prenom, 
        reservations[index].age, 
        reservations[index].telephone, 
        reservations[index].date.day, 
        reservations[index].date.month, 
        reservations[index].date.year, 
        reservations[index].statut);
        printf("+----------------------+----------------------+----------------------+-----+------------+------------+----------------------+\n");
        found = 1;
        break;
      }
    }
    if(!found){
      printf("[+] Reservation Introuvable\n");
      return 1;
    }
    printf("[+] .1 Nom\n");
    printf("[+] .2 Prenom\n");
    printf("[+] .3 Age\n");
    printf("[+] .4 Telephone\n");
    printf("[+] .5 Date\n");
    printf("[+] .6 Status\n");
    int command;
    printf(">>> ");
    scanf("%i", &command);
    switch(command){
      case 1:
        printf("[+] Nom : ");
        scanf("%s", &reservations[index].nom);
        break;
      case 2:
        printf("[+] Prenom : ");
        scanf("%s", &reservations[index].prenom);
        break;
      case 3:
        printf("[+] Age : ");
        scanf("%i", &reservations[index].age);
        break;
      case 4:
        printf("[+] Telephone : ");
        scanf("%s", &reservations[index].telephone);
        break;
      case 5:
        printf("[+] Date (DD/MM/YYYY) : ");
        scanf("%i/%i/%i", &reservations[index].date.day, &reservations[index].date.month, &reservations[index].date.year);
        break;
      case 6:
        printf("[+] Statut : \n");
        printf(" |_[+] 1. Valide\n");
        printf(" |_[+] 2. Reporte\n");
        printf(" |_[+] 3. Annule\n");
        printf(" |_[+] 4. Traite\n");
        printf(">>> ");
        int statut;
        scanf("%i", &statut);
        switch (statut) {
        case 1:
            strcpy(reservations[index].statut, "Valide");
            break;
        case 2:
            strcpy(reservations[index].statut, "Reporte");
            break;
        case 3:
            strcpy(reservations[index].statut, "Annule");
            break;
        case 4:
            strcpy(reservations[0].statut, "Traite");
            break;
        default:
            printf("[+] Commande Non Valide. Veuillez Reessayer.\n");
            return 1; 
    }
        break;
    }
    printf("[+] Reservation Modifiee Avec Secces \n");

}

int supprimerUneReservation(){
    system("cls");

    if (reservationsCounter>= MAXRESERVATIONS) {
      printf("+------------------------------------------------------+\n");
      printf("| Aucune Reservation Trouver. Veuillez En Ajouter Une. |\n");
      printf("+------------------------------------------------------+\n");
      return 1;
    }

    printf("+---------------------------+\n");
    printf("| Supprimer Une Reservation |\n");
    printf("+---------------------------+\n");
    char reference[20];
    printf("[+] Entrer Le Reference De La Reservation : ");
    scanf("%s", &reference);
    printf("[+] Recherche...\n");
    int found;
    int index;
    for(index = 0; index < reservationsCounter; index++){
      if(strcmp(reservations[index].reference, reference) == 0){
        printf("[+] Reservation Trouvee \n");
        printf("+---------------------------------------------------------------------------------------------------------------------------+\n");
        printf("|                                                     List Des Reservations                                                 |\n");
        printf("+----------------------+----------------------+----------------------+-----+------------+------------+----------------------+\n");
        printf("|       Reference      |         Nom          |        Prenom        | Age |  Telephone |    Date    |         Statut       |\n");
        printf("+----------------------+----------------------+----------------------+-----+------------+------------+----------------------+\n");
        printf("| %-20s | %-20s | %-20s | %-3i | %-10s | %-2d/%-2d/%-4d | %-20s | \n", 
        reservations[index].reference, 
        reservations[index].nom, 
        reservations[index].prenom, 
        reservations[index].age, 
        reservations[index].telephone, 
        reservations[index].date.day, 
        reservations[index].date.month, 
        reservations[index].date.year, 
        reservations[index].statut);
        printf("+----------------------+----------------------+----------------------+-----+------------+------------+----------------------+\n");
        found = 1;
        break;
      }
    }
    if(!found){
      printf("[+] Reservation Introuvable\n");
      return 1;
    }
    
    char sure[20];
    printf("[+] Sure ? Oui / Non : ");
    scanf("%s", &sure);
    if(strcmp(sure, "Oui") == 0 || strcmp(sure, "oui") == 0){
      for(int i = index; i < reservationsCounter; i++){
        reservations[i] = reservations[i + 1];
      }
       reservationsCounter--;
       printf("[+] Reservation Supprimee Avec Succes \n");
    }else if(strcmp(sure, "Non") == 0 || strcmp(sure, "non")){
      printf("[+] Suppression A Ete Annulee\n");
    }else{
      printf("[+] Commande Non Valide. Veuillez Reessayer.\n");
      }
}

int rechercherUneReservation() {
     system("cls");

    if (reservationsCounter>= MAXRESERVATIONS) {
      printf("+------------------------------------------------------+\n");
      printf("| Aucune Reservation Trouver. Veuillez En Ajouter Une. |\n");
      printf("+------------------------------------------------------+\n");
      return 1;
  }

    system("cls");
    printf("+-----------------------------+\n");
    printf("|  Rechercher Une Reservation |\n");
    printf("+-----------------------------+\n");
    printf("| .1 | Par Reference          |\n");
    printf("| .2 | Par Nom                |\n");
    printf("| .3 | Par Date               |\n");
    printf("+-----------------------------+\n");
    printf(">>> ");

    int command;
    scanf("%i", &command);
    int found = 0;
    int results[100];
    int j = 0;
    char reference[5];  
    char nom[20];     
    struct Date date;   
    switch(command) {
        case 1: 
            printf("[+] Entrer Le Reference De La Reservation : ");
            scanf("%s", reference);
            printf("[+] Recherche...\n");
            for (int i = 0; i < reservationsCounter; i++) {
                if (strcmp(reservations[i].reference, reference) == 0) {
                    results[j] = i;
                    j++;
                    found = 1; 
                    break;     
                }
            }
            break;

        case 2: 
            printf("[+] Entrez Le Nom : ");
            scanf("%s", nom);
            printf("[+] Recherche...\n");
            for (int i = 0; i < reservationsCounter; i++) {
                if (strcmp(reservations[i].nom, nom) == 0) {
                    results[j] = i;
                    j++;
                    found = 1;
                }
            }
            break;

        case 3: 
            printf("[+] Entrez La Date (DD/MM/YYYY): ");
            printf("[+] Recherche...\n");
            scanf("%i/%i/%i", &date.day, &date.month, &date.year);
            for (int i = 0; i < reservationsCounter; i++) {
                if (reservations[i].date.day == date.day &&
                    reservations[i].date.month == date.month &&
                    reservations[i].date.year == date.year) {
                    results[j] = i;
                    j++;
                    found = 1; 
                }
            }
            break;

        default:
            printf("[+] Commande Non Valide. Veuillez Reessayer.\n");
            break;
    }

    if(found){
        printf("+---------------------------------------------------------------------------------------------------------------------------+\n");
        printf("|                                                     List Des Reservations                                                 |\n");
        printf("+----------------------+----------------------+----------------------+-----+------------+------------+----------------------+\n");
        printf("|       Reference      |         Nom          |        Prenom        | Age |  Telephone |    Date    |         Statut       |\n");
        printf("+----------------------+----------------------+----------------------+-----+------------+------------+----------------------+\n");

        for (int i = 0; i < j; i++) { 
            printf("| %-20s | %-20s | %-20s | %-3i | %-10s | %02d/%02d/%04d | %-20s | \n", 
                   reservations[results[i]].reference, 
                   reservations[results[i]].nom, 
                   reservations[results[i]].prenom, 
                   reservations[results[i]].age, 
                   reservations[results[i]].telephone, 
                   reservations[results[i]].date.day, 
                   reservations[results[i]].date.month, 
                   reservations[results[i]].date.year, 
                   reservations[results[i]].statut);
            printf("+----------------------+----------------------+----------------------+-----+------------+------------+----------------------+\n");
        }
    }
    else{
        printf("[+] Rservation Non Trouvee\n");
    }
    return 0;
  
  }
int triLesReservation(){
    system("cls");

    if (reservationsCounter>= MAXRESERVATIONS) {
      printf("+------------------------------------------------------+\n");
      printf("| Aucune Reservation Trouver. Veuillez En Ajouter Une. |\n");
      printf("+------------------------------------------------------+\n");
      return 1;
    }

    printf("+----------------------+\n");
    printf("| Tri Les Reservations |\n");
    printf("+----------------------+\n");
    printf("| .1 | Tri Par Nom     |\n");
    printf("| .2 | Tri Par Date    |\n");
    printf("| .3 | Tri Par Statut  |\n");
    printf("+----------------------+\n");
    int command;
    printf(">>> ");
    scanf("%i", &command);
    int sorted = 0;
    int statutSortResults[100];
    int indice = 0;
    int statutSort = 0;
    switch(command) {
        case 1:
            for (int i = 0; i < reservationsCounter; i++) {
              for (int j = 0; j < reservationsCounter; j++) {
                if (strcmp(reservations[j].nom, reservations[j + 1].nom) > 0) {
                  struct Reservation temp = reservations[j];
                  reservations[j] = reservations[j + 1];
                  reservations[j + 1] = temp;
                }
              }
            }
            sorted = 1;
            break;

        case 2:
        for (int i = 0; i < reservationsCounter; i++) {
              for (int j = 0; j < reservationsCounter; j++) {
                if (
                reservations[j].date.year > reservations[j + 1].date.year 
                
                ||

                reservations[j].date.year <= reservations[j + 1].date.year
                &&
                reservations[j].date.month > reservations[j + 1].date.month 
                
                ||

                reservations[j].date.year <= reservations[j + 1].date.year
                &&
                reservations[j].date.month <= reservations[j + 1].date.month
                &&
                reservations[j].date.day > reservations[j + 1].date.day
                )
                {
                struct Reservation temp = reservations[j];
                reservations[j] = reservations[j + 1];
                reservations[j + 1] = temp;
                }
              }
            }
            sorted = 1;
            break;

        case 3:
          statutSort = 1;
          printf("[+] Statut : \n");
          printf(" .1 Valide\n");
          printf(" .2 Reporte\n");
          printf(" .3 Annule\n");
          printf(" .4 Traite\n");
          printf(">>> ");
          int statut;
          scanf("%i", &statut);
          switch(statut){
            case 1:
              for(int i = 0; i < reservationsCounter; i++){
                if(strcmp(reservations[i].statut, "Valide") == 0){
                    statutSortResults[indice] = i;
                    indice++;
                    statutSort = 1;
                }
              }
              break;
            case 2:
              for(int i = 0; i < reservationsCounter; i++){
                if(strcmp(reservations[i].statut, "Reporte") == 0){
                    statutSortResults[indice] = i;
                    indice++;
                }
              }
              break;
            case 3:
              for(int i = 0; i < reservationsCounter; i++){
                if(strcmp(reservations[i].statut, "Annule") == 0){
                    statutSortResults[indice] = i;
                    indice++;
                }
              }
              break;
            case 4:
              for(int i = 0; i < reservationsCounter; i++){
                if(strcmp(reservations[i].statut, "Traite") == 0){
                    statutSortResults[indice] = i;
                    indice++;
                }
              }
              break;
            default:
              printf("[+] Commande Non Valide. Veuillez Reessayer.\n");
              break;
        }
}
if(sorted || statutSort){
        printf("+---------------------------------------------------------------------------------------------------------------------------+\n");
        printf("|                                                     List Des Reservations                                                 |\n");
        printf("+----------------------+----------------------+----------------------+-----+------------+------------+----------------------+\n");
        printf("|       Reference      |         Nom          |        Prenom        | Age |  Telephone |    Date    |         Statut       |\n");
        printf("+----------------------+----------------------+----------------------+-----+------------+------------+----------------------+\n");

        if(sorted){
          for (int i = 0; i < reservationsCounter; i++) { 
            printf("| %-20s | %-20s | %-20s | %-3i | %-10s | %02d/%02d/%04d | %-20s | \n", 
                   reservations[i].reference, 
                   reservations[i].nom, 
                   reservations[i].prenom, 
                   reservations[i].age, 
                   reservations[i].telephone, 
                   reservations[i].date.day, 
                   reservations[i].date.month, 
                   reservations[i].date.year, 
                   reservations[i].statut);
            printf("+----------------------+----------------------+----------------------+-----+------------+------------+----------------------+\n");
          }
       }
        else if(statutSort){
          for (int i = 0; i < indice; i++) { 
            printf("| %-20s | %-20s | %-20s | %-3i | %-10s | %02d/%02d/%04d | %-20s | \n", 
                   reservations[statutSortResults[i]].reference, 
                   reservations[statutSortResults[i]].nom, 
                   reservations[statutSortResults[i]].prenom, 
                   reservations[statutSortResults[i]].age, 
                   reservations[statutSortResults[i]].telephone, 
                   reservations[statutSortResults[i]].date.day, 
                   reservations[statutSortResults[i]].date.month, 
                   reservations[statutSortResults[i]].date.year, 
                   reservations[statutSortResults[i]].statut);
            printf("+----------------------+----------------------+----------------------+-----+------------+------------+----------------------+\n");
          }
        }
    }
}

int statistiques(){
  system("cls");

  if (reservationsCounter>= MAXRESERVATIONS) {
      printf("+------------------------------------------------------+\n");
      printf("| Aucune Reservation Trouver. Veuillez En Ajouter Une. |\n");
      printf("+------------------------------------------------------+\n");
      return 1;
  }

  int totalDage;
  int trancheDage[3] = {0, 0, 0};
  int statuts[4] = {0, 0, 0, 0};

  for(int index = 0; index < reservationsCounter; index++){
    totalDage += reservations[index].age;
    if(reservations[index].age>= 18 && reservations[index].age <= 18){
      trancheDage[0] += 1;
    }else if(reservations[index].age >= 19 && reservations[index].age <= 35){
      trancheDage[1] += 1;
    }else if(reservations[index].age >= 36){
      trancheDage[2] += 1;
    }
    if(strcmp(reservations[index].statut, "Valide") == 0){
      statuts[0] += 1;
    }else if(strcmp(reservations[index].statut, "Reporte") == 0){
      statuts[1] += 1;
    }else if(strcmp(reservations[index].statut, "Annule") == 0){
      statuts[2] += 1;
    }else if(strcmp(reservations[index].statut, "Traite") == 0){
      statuts[3] += 1;
    }
  }
  int moyenneDage = totalDage / reservationsCounter;

  printf("+-----------------------------------------------------------------------------------------------------+\n");
  printf("|                                     Statistiques Des Reservations                                   |\n");
  printf("+-------+----------------+--------------------------------+-------------------------------------------+\n");
  printf("| Total |  Moyenne D'age |          Tranche D'age         |          Reservations Par Statut          | \n");
  printf("+-------+----------------+----------+-----------+---------+----------+----------+----------+----------+\n");
  printf("|       |                | 0-18 ans | 19-35 ans | +36 ans |  Valide  | Reporte  |  Annule  |  Traite  |\n");
  printf("|       |                +----------+-----------+---------+----------+----------+----------+----------+\n");
  printf("| %-5i | %-14i | %-8i | %-9i | %-7i | %-8i | %-8i | %-8i | %-8i |\n", 
  reservationsCounter, 
  moyenneDage, trancheDage[0], 
  trancheDage[1], 
  trancheDage[2],
  statuts[0], 
  statuts[1], 
  statuts[2], 
  statuts[3]);
  printf("+-------+----------------+----------+-----------+---------+----------+----------+----------+----------+\n");

};

int terminal() {
    system("title Systeme De Gestion Des Reservations");
    system("cls");

    int command;

    while (1) {
        printf("+------------------------------------------+\n");
        printf("|    Systeme De Gestion Des Reservations   |\n");
        printf("+------------------------------------------+\n");
        printf("| 1 | Afficher Tous Les Reservations       |\n");
        printf("| 2 | Afficher Une Reservation             |\n");
        printf("| 3 | Ajouter Une Reservation              |\n");
        printf("| 4 | Modifier Une Reservation             |\n");
        printf("| 5 | Supprimer Une Reservation            |\n");
        printf("| 6 | Rechercher Une Reservation           |\n");
        printf("| 7 | Tri Les Reservations                 |\n");
        printf("| 8 | Statistiques                         |\n");
        printf("| 9 | Quitter                              |\n");
        printf("+------------------------------------------+\n");

        printf("\n>>> ");
        scanf("%d", &command);

        switch (command) {
            case 1:
                afficherTousLesReservations();
                break;
            case 2:
                afficherUneReservation();
                break;
            case 3:
                ajouterUneReservation();
                break;
            case 4:
                modifierUneReservation();
                break;
            case 5:
                supprimerUneReservation();
                break;
            case 6:
                rechercherUneReservation();
                break; 
            case 7:
                triLesReservation();
                break;
            case 8:
                statistiques();
                break;
            case 9:
                printf("[+] Fermeture En Cours...\n");
                printf("[+] A la Prochaine ! \n");
                return 0;
            default:
                system("cls");
                printf("[+] Commande Non Valide. Veuillez Reessayer.\n");
        }
    }
}

int main() {

    strcpy(reservations[0].nom, "CEXEMPLE");
    strcpy(reservations[0].prenom, "CEXEMPLE");
    strcpy(reservations[0].telephone, "1234567890");
    reservations[0].age =  36;
    strcpy(reservations[0].statut, "Valide");
    strcpy(reservations[0].reference, "REF001");
    reservations[0].date = (struct Date){1, 1, 2024};

    strcpy(reservations[1].nom, "EEXEMPLE");
    strcpy(reservations[1].prenom, "EEXEMPLE");
    strcpy(reservations[1].telephone, "0987654321");
    reservations[1].age =  28;
    strcpy(reservations[1].statut, "Reporte");
    strcpy(reservations[1].reference, "REF002");
    reservations[1].date = (struct Date){1, 1, 2022};

    strcpy(reservations[2].nom, "DEXEMPLE");
    strcpy(reservations[2].prenom, "DEXEMPLE");
    strcpy(reservations[2].telephone, "0987654321");
    reservations[2].age =  18;
    strcpy(reservations[2].statut, "Annule");
    strcpy(reservations[2].reference, "REF003");
    reservations[2].date = (struct Date){2, 2, 2023};
  
    strcpy(reservations[3].nom, "AEXEMPLE");
    strcpy(reservations[3].prenom, "AEXEMPLE");
    strcpy(reservations[3].telephone, "0987654321");
    reservations[3].age =  19;
    strcpy(reservations[3].statut, "Valide");
    strcpy(reservations[3].reference, "REF004");
    reservations[3].date = (struct Date){3, 3, 2020};
  

    strcpy(reservations[4].nom, "BEXEMPLE");
    strcpy(reservations[4].prenom, "BEXEMPLE");
    strcpy(reservations[4].telephone, "0987654321");
    reservations[4].age =  20;
    strcpy(reservations[4].statut, "Traite");
    strcpy(reservations[4].reference, "REF005");
    reservations[4].date = (struct Date){4, 4, 2021};
  

    terminal();
    return 0;
}
