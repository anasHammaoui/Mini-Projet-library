#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100
//les variables global
    char titres[MAX][MAX], auteurs[MAX][MAX];
    int prix[MAX],quantite[MAX];
    int count = 0;
//Fomction de ajjouter pour ajouter les livres
void ajouter(){
    //ajoutre le titre
    printf("=> Entrer le titre de livre:");
    fgets(titres[count],MAX,stdin);
    titres[count][strcspn(titres[count],"\n")] = '\0';
    //ajouter l'auteur
    printf("=> Entrer l'auteur de livre:");
    fgets(auteurs[count],MAX,stdin);
    auteurs[count][strcspn(auteurs[count],"\n")] = '\0';
    //ajouter le prix
    printf("=> Entrer le prix de livre:");
    scanf("%d",&prix[count]);
    getchar();
    //ajouter la quantite
    printf("=> Entrer la quantite de livre:");
    scanf("%d",&quantite[count]);
    getchar();
    count++;
    return;
}
//Afficher les informations de livre
void afficher(){
    if (count >= 1){
    	for (int i = 0;i < count; i++){
        printf("=> Le titre de livre %d est : %s\n",i+1, titres[i]);
        printf("=> L'auteur de livre %d est : %s\n",i+1, auteurs[i]);
        printf("=> Le prix de livre %d est : %d\n",i+1, prix[i]);
        printf("=> La quantite de livre %d est : %d\n",i+1, quantite[i]);
        if (i != count -1){
        	printf("******************************\n");
        	}
    }
    	} else {
    		printf("----Il y'a aucun livre dans le librarie ---\n");
    	}
}
// Rechercher sur un livre
int rechercher(){
	char titreRech[MAX];
	printf("==> Entrer le titre de livre: ");
	fgets(titreRech,MAX,stdin);
	titreRech[strcspn(titreRech,"\n")] = '\0';
	// commencer la recherche sur le livre
	for(int i =0; i < count;i++){
		if (strcmp(titreRech,titres[i])== 0){
			printf("===>trouver sur element: %d<===\n",i+1);
			return i;
			}
		}
		printf("=== ce livre n'exist pas===\n");
		return -1;
	}
	// Mettre a jour la quantite
void mettQuant(){
	//prener l'index d'element que nou pouvons mise a jour
	int rechIndex = rechercher();
	int nvQuant;
	//checker si l'element est exist et commencer la mise a jour'
	if (rechIndex>=0){
		printf("++Entrer la nouvelle quantite: ");
		scanf("%d",&nvQuant);
		quantite[rechIndex] = nvQuant;
		printf("++++La quantite a ete mettre a jour avec succes+++\n");
		}
	}
	// Supprimer un livre de stock
int supprimer(){
	int rechIndex = rechercher();
	// checker si le livre est exist est aprs supprimer le livre
	if (rechIndex >= 0){
		for (int i = rechIndex; i < count; i++){
		strcpy(titres[rechIndex],titres[i+1]);
		strcpy(auteurs[rechIndex],auteurs[i+1]);
			quantite[rechIndex]=quantite[i+1];
			prix[rechIndex] = quantite[i+1];
			}
			count = count -1;
			printf("--- Le livre a ete supprimer avec success ---\n");
		}
	}
	
	// calculer le nombre total des livre exist
void nbTotal(){
	int total =0;
	//boucler pour calculer la quantite total
	for (int i =0; i <count; i++){
		total = total + quantite[i];
		}
		if (total > 0){
			printf("+++Le nombre total des livre est : %d livres+++\n",total);
			} else{
					printf("---La librarie est vide---\n");
				}
	}
int main(){
    int choix;
    do {
        printf("*****************MENU*****************\n");
        printf("1.Ajouter un livre.\n");
        printf("2.Afficher tous les livres disponibles.\n");
        printf("3.Rechercher un livre par son titre.\n");
        printf("4.Mettre a jour la quantite d'un livre.\n");
        printf("5.Supprimer un livre du stock.\n");
        printf("6.Afficher le nombre total de livres en stock.\n");
        printf("7.Quitter.\n");
        scanf("%d",&choix);
        getchar();
       printf("*****************FIN*****************\n");
        if (choix == 1){
            // la fonction system clear pour vider la menu avant commencer la fonction
            system("@cls||clear");
            ajouter();
        } else if (choix == 2) {
            system("@cls||clear");
            afficher();
        } else if (choix == 3){
        	system("@cls||clear");
        	rechercher();
        	} else if(choix == 4){
        		system("@cls||clear");
        		mettQuant();
        		} else if(choix == 5){
        			system("@cls||clear");
        			supprimer();
        			} else if (choix == 6){
        				system("@cls||clear");
        				nbTotal();
        				}
    } while (choix != 7);
}
