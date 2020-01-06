#include <stdio.h>
#include <stdlib.h>
#include <string.h>



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

		int b;
		fin=fin->precedent;
		b=fin->contenu;

		printf("La dernière valeur est %d\n",b);
}


	return 0;
}