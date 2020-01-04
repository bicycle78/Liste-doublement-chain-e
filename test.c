#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct Element2 Element2;
struct Element2{
    int nbre;
    Element2 *next;
};
typedef struct stack stack;
struct stack{
    Element2 *premier;
};



void push(int nvNombre,stack *s){
    Element2 *nouveau = malloc(sizeof(*nouveau));
    if (s == NULL || nouveau == NULL)
    {
        printf("Erreur");
    }

    nouveau->nbre = nvNombre;
    nouveau->next = s->premier;
    s->premier = nouveau;
}

/*@require s une pile
assigns s
ensures retire et retourne l'élément au sommet de la pile */

int pop2(stack *s){ //fonction pour retirer l'élément du haut de la pile
    if (s == NULL)
        return 0;

    int nombreDepile = 0;
    Element2 *elementDepile = s->premier;

    if (s != NULL && s->premier != NULL){
        nombreDepile = elementDepile->nbre;
        s->premier = elementDepile->next;
        free(elementDepile);
    }

    return nombreDepile;
}

/*@require s une pile
assigns nothing
ensures affiche s*/

void afficherPile(stack *pile){
    if (pile == NULL)
        exit(EXIT_FAILURE);
    Element2 *actuel = pile->premier;

    while (actuel != NULL){
        printf("%d (%c) |", actuel->nbre,actuel->nbre);
        actuel = actuel->next;
    }

    printf("\n");
}







typedef struct Element Element;
struct Element{
    int contenu;
    Element *suivant;
    Element *precedent;
};


Element *trouverFin(Element *premier){
	Element *tmp;
	if(premier==NULL)
		return NULL;
	tmp=premier;
	while(tmp->suivant!=NULL){
		tmp=tmp->suivant;
	}
	return tmp;
}


void afficherContenuApartirdudebut(Element *premier){
	Element *pt;
	pt=premier;

	while(pt!=NULL){
		printf("La valeur est %d\n",pt->contenu );
		pt=pt->suivant;
	}
}

void afficherContenuApartirdefin(Element *dernier){
	Element *pt;
	pt=dernier;

	while(pt!=NULL){
		printf("La valeur est %d\n",pt->contenu );
		pt=pt->precedent;
	}
}

Element *createElement(int val){
	Element *nouveau=(Element*) malloc(sizeof(Element));
	nouveau->contenu=val;
	nouveau->suivant=NULL;
	return nouveau;
}

void insertFin(Element **LD,Element *nouveau){
	if(*LD==NULL){
		nouveau->precedent=NULL;
		*LD=nouveau;
		return;
	}

	Element *dernier;
	dernier=trouverFin(*LD);
	nouveau->precedent=dernier;
	dernier->suivant=nouveau;
}

void init(Element **premier,Element *nouveau){
	nouveau->suivant=*premier;
	if(*premier==NULL){
		*premier=nouveau;
		return;
	}	
	
	(*premier)->precedent=nouveau;
	*premier=nouveau;

}

void insertDebut(Element **premier,Element *nouveau){
	nouveau->suivant=*premier;
	nouveau->precedent=(*premier)->precedent;
	if(*premier==NULL){
		*premier=nouveau;
		return;
	}	
	
	(*premier)->precedent=nouveau;
	*premier=nouveau;

}

int pop(Element **LD){ //fonction pour retirer l'élément du haut de la pile
    if (LD == NULL)
        return 0;

    int nombreDepile = 0;
    Element *elementDepile = *LD;

    if (LD != NULL){
        nombreDepile = elementDepile->contenu;
        *LD = elementDepile->suivant;

   

        (*LD)->precedent=elementDepile;


        
    }

    return nombreDepile;
}


void inverser(Element **LD,Element *fin3){
	Element *fin4;
	Element *fin5;
	fin5=*LD;
	fin4=fin5->precedent;
	fin5->precedent=fin3;
	fin4->precedent=NULL;
	fin3->precedent=fin4;
}


int main(){

	stack *s=malloc(sizeof(int));
	s->premier=NULL;

	Element *LD;
	LD=NULL;

	Element *LD_copy;
	LD_copy=NULL;

	int val;
	Element *nouv;

	val=69;
	nouv=createElement(val);
	init(&LD,nouv);

	val=96;
	nouv=createElement(val);
	insertDebut(&LD,nouv);

	val=78;
	nouv=createElement(val);
	insertDebut(&LD,nouv);


	val=55;
	nouv=createElement(val);
	insertFin(&LD,nouv);


	afficherContenuApartirdudebut(LD);


	printf("Là je vais afficher le contenu à l'envers\n");
	
	Element *fin;

	fin=trouverFin(LD);
	printf("%d\n",fin->contenu );

	while(fin->precedent!=NULL){

		int bite;
		fin=fin->precedent;
		bite=fin->contenu;

		printf("La dernière valeur est %d\n",bite);
}

	int a;
	int b;

	a=pop(&LD);

	b=pop(&LD);

	printf("On va refaire la même opération\n");

	Element *fin2;

	fin2=trouverFin(LD);
	printf("%d\n",fin2->contenu );

	while(fin2->precedent!=NULL){

		int bite;
		fin2=fin2->precedent;
		bite=fin2->contenu;

		printf("La dernière valeur est %d\n",bite);
}
	printf("Je vais tenter un truc\n");


	val=LD->precedent->contenu;
	nouv=createElement(val);

	free(LD->precedent);
	pop(&LD);


	insertDebut(&LD,nouv);



	afficherContenuApartirdudebut(LD);

	printf("Je la revois ?\n");


	Element *fin3;

	fin3=trouverFin(LD);

	while(fin3->precedent!=NULL){

		fin3=fin3->precedent;

}

	printf("%d\n",fin3->contenu );



	inverser(&LD,fin3);



afficherContenuApartirdefin(LD);

printf("Bonjouir\n");
afficherContenuApartirdudebut(LD);


printf("Je la fais jouir\n");
insertDebut(&LD,LD->precedent);


afficherContenuApartirdudebut(LD);

/*printf("Là si c'est différent je la revois #Sarah\n");

	afficherContenuApartirdudebut(LD);

	printf("Là on va passer aux choses sérieuses\n");

	int c=a+b;
	
	nouv=createElement(c);
	insertDebut(&LD,nouv);	

	afficherContenuApartirdudebut(LD);


	printf("Là ça va être la merde\n");
	Element *fin3;

	fin3=trouverFin(LD);
	printf("%d\n",fin3->contenu );

	while(fin3->precedent!=NULL){

		int bite;
		fin3=fin3->precedent;
		bite=fin3->contenu;

		printf("La dernière valeur est %d\n",bite);
}


	printf("Or is it ?\n");

	pop(&LD);
	afficherContenuApartirdudebut(LD);


	printf("\n");
	Element *fin4;

	fin4=trouverFin(LD);
	printf("%d\n",fin4->contenu );

	while(fin4->precedent!=NULL){

		int bite;
		fin4=fin4->precedent;
		bite=fin4->contenu;

		printf("La dernière valeur est %d\n",bite);
}*/


	return 0;
}