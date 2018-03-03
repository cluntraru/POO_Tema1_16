# POO_Tema1_16
Prima tema la laboratorul de POO, tema 16 din lista (graf ponderat neorientat)


Cerinte comune tuturor temelor:

    - implementare in C++ folosind clase

    - ATENTIE: functiile pe care le-am numit mai jos metode (fie ca sunt supraincarcari de operatori, fie altfel de functii),
        pot fi implementate ca functii prieten in loc de metode ale claselor respective, daca se considera ca aceasta alegere este mai naturala;

    - supraincarcarea operatorilor << si >> pentru iesiri si intrari de obiecte, dupa indicatiile de mai jos, astfel incat sa fie permise (si ilustrate in program):

    - citirea de la tastatura si dintr-un fisier;

    - scrierea pe ecran sau intr-un fisier;

    - citirea informațiilor complete a n obiecte, memorarea și afisarea acestora

    - implementarea constructorului de copiere si supraincarcarea operatorului =, pentru fiecare clasa

    - supraincarcarea operatorului ==, a lui !=, si a lui < (pentru a putea compara 2 obiecte si a putea sorta un vector de obiecte folosind functia sort)

    - bonus 1p (care se acorda daca toate temele au avut 10) pentru folosirea de templateuri, astfel incat tema aceasta ar putea fi notata cu 11.


Tema 16. grafuri ponderate, reprezentate ca grafuri neorientate cu ponderi atasate muchiilor, in ce mod doreste programatorul:

    - clasa graf ponderat sa contina metode pentru:

    - citirea grafului, care sa supraincarce operatorul >>;

    - afisarea grafului, care sa supraincarce operatorul <<;

    - citirea si afisarea sa foloseasca acelasi mod de reprezentare a grafului, care sa arate intreaga structura a grafului;

    - ???? determinarea matricii ponderilor drumurilor cu ponderi minime;

    - determinarea nodurilor intermediare de pe drumul de pondere minima intre doua noduri;

    - determinarea componentelor conexe, nu ca grafuri, ci ca liste de noduri;

    - determinarea arborelui partial de cost minim al componentei conexe a unui nod dat;

    - o metoda care sa determine daca graful este conex, care poate folosi orice metoda descrisa anterior;

    - o metoda de supraincarcare a operatorului *, care sa determine, din doua grafuri ponderate
        avand aceeasi multime de noduri, graful ponderat cu aceeasi multime de noduri ca si acele
        doua grafuri, si cu multimea muchiilor egala cu intersectia multimilor muchiilor acelor doua grafuri,
        cu fiecare muchie avand ca pondere minimul dintre ponderile muchiilor corespunzatoare din acele doua grafuri;

    -Clasa graf trebuie sa foloseasca implementarea unei clase de Nod pentru a retine informatia despre un anumit nod.

    -Clasa trebuie implementata folosind alocare dinamica
