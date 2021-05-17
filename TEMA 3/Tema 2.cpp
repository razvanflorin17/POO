/*

    Cerințe comune tuturor temelor:

X   utilizarea sabloanelor (functii, clase)

X   utilizarea STL

X   utilizarea variabilelor, funcțiilor statice, constantelor și a unei functii const

X   utilizarea conceptelor de RTTI raportat la templat-uri (ex: upcast & dynamic_cast)

X   citirea informațiilor complete a n obiecte, memorarea și afișarea acestora


    TEMA 2.

        La ora de Biologie, copiii din ciclul gimnazial învață că regnul animal se împarte în 2 grupuri: nevertebrate și vertebrate. La rândul lor, vertebratele se împart în pești, păsări, mamifere și reptile.

        Cerința suplimentară:

X           - Să se adauge toate campurile relevante pentru modelarea acestei probleme.

X           - Să se construiască clasa template AtlasZoologic care sa conțină un număr de animale (incrementat automat la adaugarea unei noi file) și structura de obiecte de tipul regnurilor implementate, alocata dinamic. Sa se supraincarce operatorul += pentru inserarea unei fișe de observație a unui animal în structura.

X           - Să se construiască o specializare pentru tipul Pești care sa adapteze operatorii menționați și care sa afiseze, în plus, cati pesti rapitori de lungime mai mare de 1m s-au citit.

X           Structura de date: list<animal de un anumit tip *>

*/

#include <iostream>
#include <string>
#include <list>
#include <iterator>

using namespace std;


// CLASA ANIMALE

class Animale {
protected:
    string denumire;

public:

    Animale();

    Animale(string);

    Animale(const Animale &A);

    ~Animale();

    friend istream& operator >> (istream &in, Animale &A);

    virtual void afisare() const = 0;
};


Animale :: Animale(){ }


Animale :: Animale(string name){
    denumire = name;
}


Animale :: Animale(const Animale &A){
    denumire = A.denumire;
}


Animale :: ~Animale() {
    denumire.erase();
}


istream& operator >>(istream &in, Animale& A){

    in >> A.denumire;
    return in;
}


// CLASA NEVERTEBRATE

class Nevertebrate : public Animale {

public:

    Nevertebrate();

    Nevertebrate(string);

    Nevertebrate(const Nevertebrate &N);

    ~Nevertebrate();

    void afisare() const;
};


Nevertebrate :: Nevertebrate() : Animale() { }


Nevertebrate :: Nevertebrate(string name) : Animale(name) {
    denumire = name;
}


Nevertebrate :: Nevertebrate(const Nevertebrate &N) : Animale(N){
    denumire = N.denumire;
}


Nevertebrate ::~Nevertebrate() { }


void Nevertebrate :: afisare() const {
    cout << "Numele nevertebratei este : " << denumire << endl;
}


// CLASA VERTEBRATE

class Vertebrate : public Animale {

public:

    Vertebrate();

    Vertebrate(string);

    Vertebrate(const Vertebrate &V);

    ~Vertebrate();

    void afisare() const;
};


Vertebrate :: Vertebrate() : Animale() { }


Vertebrate :: Vertebrate(string name) : Animale(name) {
    denumire = name;
}


Vertebrate :: Vertebrate(const Vertebrate &V) : Animale(V){
    denumire = V.denumire;
}


Vertebrate ::~Vertebrate() { }


void Vertebrate :: afisare() const {
    cout << "Numele vertebratei este :" << denumire << endl;
}

// CLASA PASARI

class Pasari : public Vertebrate {

public:

    Pasari();

    Pasari(string);

    Pasari(const Pasari &P);

    ~Pasari();

    void afisare() const ;
};


Pasari :: Pasari() { }


Pasari :: Pasari(string name) {
    denumire = name;
}


Pasari :: Pasari(const Pasari &P) {
    denumire = P.denumire;
}


Pasari ::~Pasari() { }


void Pasari :: afisare() const {
    cout << "Numele pasarii este : " << denumire << endl;
}

// CLASA REPTILE

class Reptile : public Vertebrate {

public:

    Reptile();

    Reptile(string);

    Reptile(const Reptile &R);

    ~Reptile();

    void afisare() const ;
};


Reptile :: Reptile() { }


Reptile :: Reptile(string name) {
    denumire = name;
}


Reptile :: Reptile(const Reptile &R) {
    denumire = R.denumire;
}


Reptile ::~Reptile() { }


void Reptile :: afisare() const {
    cout << "Numele reptilei este : " << denumire << endl;
}


// CLASA PESTI

class Pesti : public Vertebrate {

    bool pradator;

    double lungime;

public:
    Pesti();

    Pesti(string, bool, double);

    Pesti(const Pesti &P);

    ~Pesti();

    friend istream& operator >> (istream &in, Pesti &P);

    void afisare() const;

    bool getPradator() { return pradator; };

    double getLungime() { return lungime; };
};


Pesti :: Pesti() { }


Pesti :: Pesti(string name, bool pradator=0, double lungime=0) {
    denumire = name;
    pradator = pradator;
    lungime = lungime;
}


Pesti :: Pesti(const Pesti &P) {
    denumire = P.denumire;
}


Pesti ::~Pesti() { }

istream& operator >>(istream &in, Pesti& P){

    in >> dynamic_cast<Animale&>(P);

    cout << "\nEste pradator? (1-da, 0-nu): ";
    in >> P.pradator;
    cout << "\nLungimea pestelui: ";
    in >> P.lungime;

    if(!in.good()){
        throw 1;
    }

    return in;
}

void Pesti :: afisare() const {
    if(pradator)
        cout << "Numele pestelui este " << denumire << ", este pradator iar lungimea sa este de " << lungime << " metrii\n";
    else
        cout << "Numele pestelui este " << denumire << ", nu este pradator iar lungimea sa este de " << lungime << " metrii\n";

}


// CLASA MAMIFERE

class Mamifere : public Vertebrate {

public:

    Mamifere();

    Mamifere(string);

    Mamifere(const Mamifere &M);

    ~Mamifere();

    void afisare() const ;
};


Mamifere :: Mamifere() { }


Mamifere :: Mamifere(string name) {
    denumire = name;
}


Mamifere :: Mamifere(const Mamifere &M) {
    denumire = M.denumire;
}


Mamifere ::~Mamifere() { }


void Mamifere :: afisare() const {
    cout << "Numele mamiferei este : " << denumire << endl;
}


// CLASA ATLAS

template <class Type>
class AtlasZoologic {

    int nr_animale = 0;

    list <Animale*> animale;

public:

    AtlasZoologic();

    ~AtlasZoologic() ;

    int getNumarAnimale();

    void afisare();

    void operator +=(Type &crt);
};


template<class Type>
AtlasZoologic<Type> :: AtlasZoologic() { }


template<class Type>
AtlasZoologic<Type> :: ~AtlasZoologic() { }


template <class Type>
void AtlasZoologic<Type> ::afisare()  {

    cout << "\nAtlasul de ";

    string aux = typeid(Type).name();

    for(int i = 0; i < aux.size(); i++)
        if(aux[i] < '0' || aux[i] > '9')
            cout << aux[i];
        else
            cout << "";

    cout << " contine: \n\n";

    list<Animale*>::iterator it;

    for(it = animale.begin(); it!=animale.end(); it++)
    {
        (*it)->afisare();
    }
}


template<class Type>
void AtlasZoologic<Type>::operator +=(Type &crt) {

    animale.push_back(&crt);
    nr_animale++;
}


template <class Type>
int AtlasZoologic<Type>:: getNumarAnimale() {
    return nr_animale;
}


// SPECIALIZARE PESTI

template <>
class AtlasZoologic <Pesti> {

    int nr_animale = 0;

    list <Pesti*> animale;

public:

    AtlasZoologic();

    ~AtlasZoologic() ;

    int getNumarAnimale();

    const int getNrPradatoriMari();

    void afisare();

    void operator +=(Pesti &crt);
};


AtlasZoologic<Pesti> :: AtlasZoologic() { }


AtlasZoologic<Pesti> :: ~AtlasZoologic() { }


void AtlasZoologic<Pesti> ::afisare()  {

    cout << "\nAtlasul de ";

    string aux = typeid(Pesti).name();

    for(int i = 0; i < aux.size(); i++)
        if(aux[i] < '0' || aux[i] > '9')
            cout << aux[i];
        else
            cout << "";

    cout << " contine: \n\n";


    list<Pesti*>::iterator it;

    for(it = animale.begin(); it != animale.end(); it++)
    {
        (*it)->afisare();
    }
}


void AtlasZoologic<Pesti>::operator +=(Pesti &crt) {

    animale.push_back(&crt);
    nr_animale++;
}


int AtlasZoologic<Pesti>:: getNumarAnimale() {
    return nr_animale;
}


const int AtlasZoologic<Pesti>:: getNrPradatoriMari() {

    int nr = 0;

    list<Pesti*>::iterator it;

    for(it = animale.begin(); it != animale.end(); it++)
        if((*it)->getPradator() && (*it)->getLungime() > 1.0)
            nr++;

    return nr;

}

// MAIN

int main()
{

    AtlasZoologic<Nevertebrate> atlas_nevertebrate;
    AtlasZoologic<Pesti> atlas_pesti;
    AtlasZoologic<Reptile> atlas_reptile;
    AtlasZoologic<Pasari> atlas_pasari;
    AtlasZoologic<Mamifere> atlas_mamifere;

    bool continuam = true;

    while(continuam){

        char choice;

        cout << "\nCe actiune doriti sa executati?\n\n"
              "A - Adaugare animal;\n"
              "N - Numar total animale\n"
              "T - Total atlase\n"
              "P - Pumar pesti pradatori mari\n"
              "S - Stop program\n\n";

        cin >> choice;

        switch (choice) {

            case 'A': {

                        int animal_choice;

                        cout << "\n0 - Nevertebrate\n"
                                "1 - Pesti\n"
                                "2 - Reptile\n"
                                "3 - Pasari\n"
                                "4 - Mamifere\n\n";

                        cin >> animal_choice;

                        switch (animal_choice) {

                            case 0: {
                                Nevertebrate *ob = new Nevertebrate;

                                cout << "\nIntroduceti numele nevertebratului : ";

                                cin >> *ob;

                                atlas_nevertebrate += *ob;
                                break;
                            }

                            case 1: {
                                Pesti *ob = new Pesti;

                                try {
                                    cout << "\nIntroduceti numele pestelui : ";
                                    cin >> *ob;
                                }

                                catch(...) {
                                    cout << "\nCitire peste esuata\n";
                                    return 0;
                                }

                                atlas_pesti += *ob;
                                break;
                            }

                            case 2: {
                                Reptile *ob = new Reptile;
                                cout << "\nIntroduceti numele reptilei : ";
                                cin >> *ob;
                                atlas_reptile += *ob;
                                break;
                            }

                            case 3: {
                                Pasari *ob = new Pasari;
                                cout << "\nIntroduceti numele pasarii : ";
                                cin >> *ob;
                                atlas_pasari += *ob;
                                break;
                            }

                            case 4: {
                                Mamifere *ob = new Mamifere;
                                cout << "\nIntroduceti numele mamiferului :";
                                cin >> *ob;
                                atlas_mamifere += *ob;
                                break;
                            }
                        }
                break;}

            case 'N': {

                        int sum = 0;
                        sum += atlas_nevertebrate.getNumarAnimale();
                        sum += atlas_pesti.getNumarAnimale();
                        sum += atlas_reptile.getNumarAnimale();
                        sum += atlas_pasari.getNumarAnimale();
                        sum += atlas_mamifere.getNumarAnimale();

                        if(sum != 1)
                            cout << "\n" << sum << " animale.\n" << endl;
                        else
                            cout << sum << " annimal.\n" << endl;

                break;
            }

            case 'T': {

                        atlas_nevertebrate.afisare();
                        atlas_pesti.afisare();
                        atlas_reptile.afisare();
                        atlas_pasari.afisare();
                        atlas_mamifere.afisare();

                 break;
            }

            case 'P': {
                if(atlas_pesti.getNrPradatoriMari() != 1)
                    cout << "\n" << atlas_pesti.getNrPradatoriMari() << " pradatori mari.\n" << endl;
                else
                    cout << atlas_pesti.getNrPradatoriMari() << "pradator mare.\n" << endl;
                break;
            }

            case 'S' : {
                continuam = false;
                cout << endl << "Executia programului va fi oprita !" << endl << endl;
                cout << "Program realizat de Potcoveanu Florin-Razvan - Grupa 132" << endl;;
                break;
            }

            default : cout << "\nOptiunea aleasa de dumneavoastra nu exista, incercati din nou. \n";

        }
    }

}
