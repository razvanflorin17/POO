/*
    Cerințe comune tuturor temelor (barem):

    Toate clasele vor conține obligatoriu

X X X constructori de inițializare (0.25p),
X X X parametrizați (0.25p)
X X X și de copiere (0.25p);
X X X destructor (0.25p);
X X X operatorii „=” (0.5p),
X X X „>>” (0.5p),
X X X „<<” (0.5p) supraîncărcați corespunzător,

X   moșteniri & encapsulare (0.5p)

X   Clasele derivate trebuie sa contina constructori parametrizati (prin care sa se evidentieze transmiterea parametrilor catre constructorul din clasa de baza) si destructori. (1p)

X   În fiecare proiect vor fi ilustrate conceptele de upcasting, downcasting, funcții virtuale (pure – unde se consideră mai natural) – 1.5p (0.5p / cerință)

X   Utilizarea de variabile și de funcții statice – 1p

X   Citirea informațiilor complete a n obiecte, memorarea și afișarea acestora – 0.5p

X   Meniu interactiv – 0.5p

X   Rezolvarea corectă a cerințelor suplimentare corespunzatoare fiecarei teme – 1.5p.

    Se acordă punctaje parțiale corespunzător și 1p oficiu.

    - Dacă sursa nu compilează, se acorda nota 1 (punctul din oficiu).

    - După expirarea termenului limită se mai pot trimite teme pe mail pentru o perioadă de grație de 2 zile (48 de ore). Pentru fiecare zi parțială de întârziere se vor scădea 2 puncte. După expirarea termenului de grație, proiectele nu vor fi acceptate și vor fi notate cu 0. Punctul din oficiu este primit doar dacă a fost trimis proiectul în perioada limită + perioada de grație.

    Tema 11.

        Se dau clasele:

X           Persoana (string nume, string cnp);

X           Abonat (int nrMaxCarti, int nrCartiImprumutate, int pretAbonament) : Persoana

X           Sa se creeze clasa dosar care retine informatiile abonatilor la o biblioteca si contine un vector de pointeri la obiect abonat si lungimea acestuia.

X           Sa se realizeze verificarile necesare in constructor si la citire astfel ca sa nu poti avea mai multe carti imprumutate decat numarul maxim de carti
X           si numarul maxim de carti sa nu poata fi mai mare decat pretul abonamentului.  Sa se defineasca o metoda de calculare a varstei persoanei din cnp, sa
X           se citeasca si afiseze n obiecte de tip abonat care sa fie adaugate in dosar.

*/


#include <iostream>
#include <string.h>
#include <vector>

using namespace std;

class Persoana
{

protected:

    string nume;
    string cnp;

public:
    Persoana();                                                     // Constructor fara parametri

    Persoana(string nume_persoana, string cnp_persoana);            // Constructor cu paramaetri

    Persoana(const Persoana &aux);                                  // Constructor de copiere

    ~Persoana();                                                    // Destructor

    virtual void varsta(string data);                               // Functie virtuala pentru calculul varstei unui Abonat

    Persoana operator= (Persoana aux);                              // Supraincarcarea operatorului =

    friend ostream& operator<< (ostream&, const Persoana&);         // Supraincarcarea operatorului <<

    friend istream& operator>> (istream&, Persoana&);               // Supraincarcarea operatorului >>

};

Persoana :: Persoana()
{
    nume = "";
    cnp = "";
}

Persoana :: Persoana(string nume_persoana, string cnp_persoana)
{
    nume = nume_persoana;
    cnp = cnp_persoana;
}

Persoana :: Persoana(const Persoana &aux)
{
    nume = aux.nume;
    cnp = aux.cnp;
}

Persoana :: ~Persoana()
{
    nume.clear();
    cnp.clear();
}

void Persoana :: varsta(string data)
{

}

Persoana Persoana :: operator= (Persoana aux)
{
    nume = aux.nume;
    cnp = aux.cnp;

    return *this;
}

ostream& operator<< (ostream& out, const Persoana& aux)
{
    out << endl << "Numele persoanei este : " << aux.nume << endl << endl;
    out << "CNP-ul persoanei este : " << aux.cnp << endl;
    out << endl << "============================================" << endl;
    return out;
}

istream& operator>> (istream& in, Persoana& aux)
{
    cout << endl << "Introduceti numele persoanei : ";
    getline(in, aux.nume);
    cout << endl << "Introduceti CNP-ul persoanei : ";
    getline(in, aux.cnp);
    cout << endl << "============================================" << endl;

    return in;
}

class Abonat : public Persoana
{

protected:

    int nrMaxCarti, nrCartiImprumutate, pretAbonament;

    static int pretCarte;

public:

    Abonat();                                                                                       // Constructor

    Abonat(int maxim, int imprumutate, int pret, string nume_persoana, string cnp_persoana);        // Constructor cu parametrii

    Abonat(const Abonat &aux);                                                                      // Constructor de copiere

    void varsta(string data);                                                                       // Metoda pentru calculul varstei unei persoane in functie de CNP

    ~Abonat();                                                                                      // Destructor

    Abonat operator= (Abonat aux);                                                                  // Supraincarcarea operatorului =

    friend ostream& operator<< (ostream&, const Abonat&);                                           // Supraincarcarea operatorului <<

    friend istream& operator>> (istream&, Abonat&);                                                 // Supraincarcarea operatorului >>

};

int Abonat :: pretCarte = 20;

Abonat :: Abonat() : Persoana()
{
    nrMaxCarti = 0;
    nrCartiImprumutate = 0;
    pretAbonament = 0;
}

Abonat :: Abonat(int maxim, int imprumutate, int pret, string nume_persoana, string cnp_persoana) : Persoana(nume_persoana, cnp_persoana)
{
    if(imprumutate <= maxim && maxim * pretCarte <= pret)
    {
        nrMaxCarti = maxim;
        nrCartiImprumutate = imprumutate;
        pretAbonament = pret;
    }
    else
    {
        cout << endl << "============================================" << endl;
        cout << "Datele introduse sunt incorecte. Introduceti datele din nou. ( numarul maxim de carti <= numar carti imprumutate && numar maxim de carti <= pret ( " << pretCarte << " ) )" << endl << endl;
        cout << "Numar maxim de carti : ";
        cin >> maxim;
        cout << "Numar carti imprumutate : ";
        cin >> imprumutate;
        cout << "Pret abonament : ";
        cin >> pret;
        cout << endl << "============================================" << endl;
        nrMaxCarti = maxim;
        nrCartiImprumutate = imprumutate;
        pretAbonament = pret;
    }
}

Abonat :: Abonat(const Abonat &aux)
{
    nume = aux.nume;
    cnp = aux.cnp;
    nrMaxCarti = aux.nrMaxCarti;
    nrCartiImprumutate = aux.nrCartiImprumutate;
    pretAbonament = aux.pretAbonament;
}

Abonat :: ~Abonat()
{
    nrMaxCarti = 0;
    nrCartiImprumutate = 0;
    pretAbonament = 0;
    nume.clear();
    cnp.clear();
}

void Abonat :: varsta(string data)
{
    string aux = "";

    aux = aux + cnp[1] + cnp[2] + cnp[3] + cnp[4] + cnp[5] + cnp[6];

    int x = stoi(aux);
    int y = stoi(data);

    if(y - x > 0)
        cout << endl << "Varsta persoanei este : " << (y - x) / 10000;
    else
        cout << endl << "Varsta persaonei este : " << (y - x) / 10000 + 100;

    aux.clear();
}

Abonat Abonat :: operator= (Abonat aux)
{
    nume = aux.nume;
    cnp = aux.cnp;
    nrMaxCarti = aux.nrMaxCarti;
    nrCartiImprumutate = aux.nrCartiImprumutate;
    pretAbonament = aux.pretAbonament;

    return *this;
}

ostream& operator<< (ostream& out, const Abonat& aux)
{
    out << endl << "Numele persoanei este : " << aux.nume << endl;
    out << "CNP-ul persoanei este : " << aux.cnp << endl;
    out << "Numarul maxim de carti : " << aux.nrMaxCarti << endl;
    out << "Numarul de carti imprumutate : " << aux.nrCartiImprumutate << endl;
    out << "Pret abonament : " << aux.pretAbonament << endl;
    out << endl << "============================================" << endl;
    return out;
}

istream& operator>> (istream& in, Abonat& aux)
{
    cout << endl << "Introduceti numele persoanei : ";
    getline(in, aux.nume);
    cout << endl << "Introduceti CNP-ul persoanei : ";
    getline(in, aux.cnp);

    int ok = 1;

    cout << endl << "Introduceti numarul maxim de carti : ";
    cin >> aux.nrMaxCarti;
    cout << endl << "Introduceti numarul de carti imprumutate : ";
    cin >> aux.nrCartiImprumutate;
    cout << endl << "Introduceti pretul abonamentului : ";
    cin >> aux.pretAbonament;

    cout << endl << "============================================" << endl;

    while(ok)
    {
        if(aux.nrCartiImprumutate > aux.nrMaxCarti || aux.nrMaxCarti * aux.pretCarte > aux.pretAbonament)
        {
            cout << endl << "============================================" << endl;
            cout << "Datele introduse sunt incorecte. Introduceti datele din nou. ( numarul maxim de carti <= numar carti imprumutate && numar maxim de carti <= pret ( " << aux.pretCarte << " ) )" << endl;
            cout << "Introduceti numarul maxim de carti : ";
            cin >> aux.nrMaxCarti;
            cout << "Introduceti numarul de carti imprumutate : ";
            cin >> aux.nrCartiImprumutate;
            cout << "Introduceti pretul abonamentului : ";
            cin >> aux.pretAbonament;
            cout << endl << "============================================" << endl;
            ok = 1;
        }
        else
            ok = 0;

    }

    cin.get();

    return in;
}

class Dosar
{
    protected:

        vector<Abonat> abonati;
        int nr_elemente;

    public:

        Dosar();                                                                                        // Constructor fara parametri

        Dosar(int n);                                                                                   // Constructor cu parametri

        Dosar(const Dosar &aux);                                                                        // Constructor de copiere

        ~Dosar();                                                                                       // Destructor

        vector<Abonat> citire_elemente(vector<Abonat> aux);                                               // Metoda de citire a n elemente de tipul Abonat

        Dosar operator= (Dosar aux);                                                                    // Supraincarcarea operatorului =

        friend ostream& operator<< (ostream&, const Dosar&);                                            // Supraincarcarea operatorului <<

        friend istream& operator>> (istream&, Dosar&);                                                  // Supraincarcarea operatorului >>

};

Dosar :: Dosar()
{
    abonati.resize(0);
    nr_elemente = 0;
}

Dosar :: Dosar(int n)
{
    abonati.resize(n);
    for(int i = 0; i < n; i++)
    {
        Abonat aux;
        cin >> aux;
        abonati[i] = aux;
    }
    nr_elemente = n;
}

Dosar :: Dosar(const Dosar &aux)
{
    abonati.resize(aux.nr_elemente);

    for(int i = 0; i < aux.nr_elemente; i++)
        abonati[i] = aux.abonati[i];

    nr_elemente = aux.nr_elemente;
}

Dosar :: ~Dosar()
{
    abonati.resize(0);
    nr_elemente = 0;
}

vector<Abonat> Dosar :: citire_elemente(vector<Abonat> aux)
{
     int n;

     cout << "Introduceti numarul de abonati : ";

     cin >> n;

     aux.resize(n);

     cin.get();

     for(int i = 0; i < n; i++)
     {
         Abonat temp;

         cin >> temp;

         aux[i] = temp;
     }
     return aux;
}

Dosar Dosar :: operator= (Dosar aux)
{
    abonati.resize(aux.nr_elemente);

    for(int i = 0; i < aux.nr_elemente; i++)
        abonati[i] = aux.abonati[i];

    nr_elemente = aux.nr_elemente;

    return *this;
}

ostream& operator<< (ostream& out, const Dosar& aux)
{
    out << endl << "Dosarul contine " << aux.nr_elemente << " abonati."<<endl;

    for(int i = 0; i < aux.nr_elemente; i++)
        out << aux.abonati[i];

    return out;
}

istream& operator>> (istream& in, Dosar& aux)
{
    cout << endl << "Introduceti numarul de abonati : ";
    in >> aux.nr_elemente;

    cout << endl << "Introduceti abonatii : " << endl;

    aux.abonati.resize(aux.nr_elemente);

    in.get();

    for(int i = 0; i < aux.nr_elemente; i++)
    {
        Abonat temp;
        cin >> temp;
        aux.abonati[i] = temp;
    }

    return in;
}


int main()
{
    int ok_1 = 1, optiune;

    while(ok_1)
    {
        cout << endl << "Selectati un obiect pentru a fi citit : " << endl << endl;
        cout << "1. Persoana" << endl;
        cout << "2. Abonat" << endl;
        cout << "3. Dosar" << endl;
        cout << "0. OPRESTE EXECUTIA PROGRAMULUI !!!" << endl << endl;
        cin >> optiune;

        switch(optiune)
        {
            case 0:
                {
                    ok_1 = 0;
                    cout << endl << "Executia programului va fi oprita !" << endl << endl;
                    cout << "Program realizat de Potcoveanu Florin-Razvan - Grupa 132" << endl;;
                    break;
                }
            case 1:
                {
                    cout << endl << "Selectati constructorul : " << endl << endl;
                    cout << "1. Constructor fara parametri (creeaza un obiect de tipul Persoana vid)" << endl;
                    cout << "2. Constructor cu parametri (creeaza un obiect de tipul Persoana cu nume si CNP introduse de la tastatura)" << endl;
                    cout << "0. Revenire la meniul anterior" << endl << endl;

                    int optiune_Persoana;

                    cin>>optiune_Persoana;

                    switch(optiune_Persoana)
                    {
                        case 0:
                            break;
                        case 1:
                            {
                                Persoana fara_parametru;
                                cout << endl << "A fost creat un obiect vid." << endl;

                                cout << endl << "Doriti sa afisati obiectul ? (0/1)" << endl << endl;

                                int ok;

                                cin >> ok;

                                if(ok)
                                    cout << fara_parametru;

                                break;
                            }
                        case 2:
                            {
                                string nume;
                                string cnp;

                                cin.get();

                                cout << endl << "Introduceti numele persoanei : ";
                                getline(cin, nume);

                                cout << "Introduceti CNP-ul persoanei : " ;
                                getline(cin, cnp);

                                Persoana cu_parametru(nume, cnp);

                                cout << endl << "Obiectul a fost creat." << endl << endl;

                                cout << endl << "Doriti sa afisati obiectul ? (0/1)" << endl << endl;

                                int ok;

                                cin >> ok;

                                if(ok)
                                    cout << cu_parametru;

                                break;
                            }
                    }

                    break;
                }

            case 2:
                {
                    cout << endl << "Selectati constructorul : " << endl << endl;
                    cout << "1. Constructor fara parametri (creeaza un obiect de tipul Abonat vid)" << endl;
                    cout << "2. Constructor cu parametri (creeaza un obiect de tipul Abonat cu numar maxim de carti, numar de carti imprumutate, pret abonament, nume si CNP introduse de la tastatura)" << endl;
                    cout << "0. Revenire la meniul anterior" << endl << endl;

                    int optiune_Abonat;

                    cin >> optiune_Abonat;

                    switch(optiune_Abonat)
                    {
                        case 0:
                            break;

                        case 1:
                            {
                                Abonat fara_parametru;

                                cout << endl << "Obiectul a fost creat." << endl << endl;

                                cout << "Doriti sa afisati obiectul ? (0/1)" << endl << endl;

                                int ok;

                                cin >> ok;

                                if(ok)
                                    cout << fara_parametru;

                                break;
                            }

                        case 2:
                            {
                                int m, i, p;
                                string nume, cnp;

                                cout << endl << "Introduceti numarul maxim de carti : ";
                                cin >> m;

                                cout << endl << "Introduceti numarul de carti imprumutate : ";
                                cin >> i;

                                cout << endl << "Introduceti pretul abonamentului : ";
                                cin >> p;

                                cin.get();

                                cout << endl << "Introduceti numele persoanei : ";
                                getline(cin, nume);

                                cout << endl << "Introduceti CNP-ul persoanei : " ;
                                getline(cin, cnp);

                                Abonat cu_parametru(m, i, p, nume, cnp);

                                cout << endl << "Obiectul a fost creat." << endl << endl;

                                cout << "Doriti sa afisati obiectul ? (0/1)" << endl << endl;

                                int ok;

                                cin >> ok;

                                if(ok)
                                    cout << cu_parametru;

                                cout << endl << "Doriti sa aflati varsta abonatului ? (0/1)" << endl << endl;

                                int ok2;

                                cin >> ok2;

                                if(ok2)
                                    {
                                        string date;

                                        cout << endl << "Introduceti data de azi ( in format YYMMDD ) : ";

                                        cin >> date;

                                        cu_parametru.varsta(date);

                                        cout << endl;
                                    }
                                break;


                            }
                    }
                    break;
                }

            case 3:
                {
                    cout << endl << "Selectati constructorul : " << endl << endl;
                    cout << "1. Constructor fara parametri (creeaza un obiect de tipul Dosar vid)" << endl;
                    cout << "2. Constructor cu parametri (creeaza un obiect de tipul Dosar cu n elemente introduse de la tastatura)" << endl;
                    cout << "3. Citirea si memorarea a n elemente " << endl;;
                    cout << "0. Revenire la meniul anterior" << endl << endl;

                    int optiune_Dosar;

                    cin >> optiune_Dosar;

                    switch(optiune_Dosar)
                    {
                        case 0:
                            break;

                        case 1:
                            {
                                Dosar fara_parametru;

                                cout << endl << "Obiectul a fost creat." << endl << endl;

                                cout << "Doriti sa afisati obiectul ? (0/1)" << endl << endl;

                                int ok;

                                cin >> ok;

                                if(ok)
                                    cout << fara_parametru;

                                break;
                            }

                        case 2:
                            {
                                int n;

                                cout << endl << "Introduceti numarul de abonati : ";
                                cin >> n;

                                cin.get();

                                Dosar cu_parametru(n);

                                cout << endl << "Obiectul a fost creat." << endl << endl;

                                cout << "Doriti sa afisati obiectul ? (0/1)" << endl << endl;

                                int ok;

                                cin >> ok;

                                if(ok)
                                    cout << cu_parametru;

                                break;
                            }

                        case 3:
                            {
                                cout << endl;

                                vector<Abonat> obiecte;

                                Dosar temporar;

                                obiecte = temporar.citire_elemente(obiecte);

                                cout << endl << "Doriti sa afisati abonatii din Dosar ? (0/1)" << endl << endl;

                                int ok;

                                cin >> ok;

                                if(ok)
                                    for(int i = 0; i < obiecte.size(); i++)
                                        cout << obiecte[i];

                                cout << endl << "Doriti sa afisati varstele abonatilor din Dosar ? (0/1)" << endl << endl;

                                int ok2;

                                cin >> ok2;

                                if(ok2)
                                    {
                                        string date;

                                        cout << endl << "Introduceti data de azi ( in format YYMMDD ) : ";

                                        cin >> date;

                                        for(int i = 0; i < obiecte.size(); i++)
                                            obiecte[i].varsta(date);

                                        cout << endl;
                                    }

                            }
                    }
                    break;
                }


        }
    }

    return 0;
}
