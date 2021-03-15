/* Tema 3. Clasa ”Vector” (vector de numere întregi)

X - membri privati pentru vectorul propriuzis si numarul de elemente;

X    	- constructor pentru initializarea cu un numar dat pe toate componentele

        (primeste ca parametru numarul respectiv si numarul componentelor);

X    	- constructori pentru initializare si copiere;

X    	- destructor (în cazul alocarii statice, se seteaza dimensiunea vectorului la zero, iar în cazul alocarii dinamice, se dezaloca zona de memorie utilizata);

X    	- metoda-operator public de atribuire =;

X - metoda publica pentru reactualizarea numarului de componente si initializarea componentelor cu un numar dat (primeste ca parametru numarul respectiv si numarul componentelor);

X - metoda publica pentru calculul sumei tuturor elementelor vectorului;

X - metoda publica pentru găsirea maximului și a pozitiei lui;

X - metoda publica pentru sortarea crescătoare a vectorului;

X - implementare in C++ folosind clase

X - datele membre private

X - constructori de initializare (cu si fara parametrii), constructor de copiere

X - get, set pentru toate datele membre

- ATENTIE: functiile pe care le-am numit mai jos metode (fie ca sunt supraincarcari de operatori, fie altfel de functii), pot fi implementate ca functii prieten in loc de metode ale claselor respective, daca se considera ca aceasta alegere este mai naturala;

X - supraincarcarea operatorilor << si >> pentru iesiri si intrari de obiecte, dupa indicatiile de mai jos, astfel incat sa fie permise (si ilustrate in program):

X - sa existe o metoda publica prin care se realizeaza citirea informațiilor complete a n obiecte, memorarea și afisarea acestora.

X - programul sa aiba un meniu interactiv

*/

#include <iostream>
#include <vector>

using namespace std;

class Vector{
    private:
        vector<int> v;
        int nr_elemente;
    public:
        Vector();                                               // Constructor de initializare fara parametru

        Vector(int n);                                          // Constructor de initializare cu parametru

        Vector(int n, int x);                                   // Constructor pentru initializarea cu un numar dat pe toate componentele

        Vector(const Vector &aux);                              // Constructor de copiere

        ~Vector();                                              // Destructor

        void set_vector(int x);                                 // Setter vector

        vector<int> get_vector();                               // Getter vector

        void set_nr_elemente(int nr);                           // Setter numar de elemente

        int get_nr_elemente();                                  // Getter numar de elemente

        void actualizare_vector(int n, int x);                  // Metoda pentru reactualizarea numarului de componente si initializarea acestora cu o valoare data

        int suma_vector();                                      // Metoda pentru suma elementelor unui vector

        void maxim_vector();                                    // Metoda pentru gasirea maximului si a pozitiei lui

        void sortare_vector();                                  // Metoda pentru sortarea crescatoare a vectorului

        vector<Vector> citire_elemente(vector<Vector> aux);     // Metoda pentru citirea, afisarea si memorarea a n obiecte

        friend ostream& operator<< (ostream&, const Vector&);   // Supraincarcarea operatorului <<

        friend istream& operator>> (istream&, Vector&);         // Supraincarcarea operatorului >>

        Vector operator= (Vector aux);                          // Supraincarcarea operatorului =
};

Vector :: Vector()
{
    v.resize(0);
    nr_elemente = 0;
}

Vector :: Vector(int n)
{
    v.resize(n);
    for(int i = 0; i < n; i++)
        cin>>v[i];
    nr_elemente = n;
}

Vector :: Vector(int n, int x)
{
    v.resize(n);
    for(int i = 0; i < n; i++)
        v[i] = x;
    nr_elemente = n;
}

Vector :: Vector(const Vector &aux)
{
    nr_elemente = aux.nr_elemente;
    v.resize(nr_elemente);
    for(int i = 0; i < v.size(); i++)
        v[i] = aux.v[i];
}

Vector :: ~Vector()
{
    v.resize(0);
    nr_elemente = 0;
}

void Vector :: set_vector(int x)
{
    for(int i = 0; i < this->v.size(); i++)
        this->v[i] = x;
}

vector<int> Vector :: get_vector ()
{
    return this->v;
}

int Vector :: get_nr_elemente()
{
    return this->nr_elemente;
}

void Vector :: set_nr_elemente(int nr)
{
    this->nr_elemente = nr;
}

void Vector :: actualizare_vector(int n, int x)
{
    v.resize(n);
    for(int i = 0; i < n; i++)
        v[i] = x;
    nr_elemente = n;
}

int Vector :: suma_vector()
{
    int suma = 0;
    for(int i : v)
        suma += i;
    return suma;
}

void Vector :: maxim_vector()
{
    int maxim = v[0];
    for(int i = 1; i < nr_elemente; i++)
        if(v[i] > maxim)
            maxim = v[i];
    cout<<maxim<<" ";
    for(int i = 0; i < nr_elemente; i++)
        if(v[i] == maxim)
        {
            cout<<i<<endl;
            break;
        }
}

void Vector :: sortare_vector()
{
    for(int i = 0; i < v.size() - 1; i++)
        for(int j = i + 1; j < v.size(); j++)
            if(v[i] > v[j])
                swap(v[i], v[j]);
    for(int i : v)
        cout<<i<<" ";
}

 vector<Vector> Vector :: citire_elemente(vector<Vector> aux)
 {
     int nr;
     cout<<"Introduceti numarul de obiecte ce vor fi adaugate : ";
     cin>>nr;
     aux.resize(nr);
     for(int i = 0; i < nr; i++)
     {
         Vector obiect;

         cin>>obiect;
         cout<<obiect;
         aux[i] = obiect;
     }
     return aux;
 }

ostream& operator<< (ostream& out, const Vector &aux)
{
    out << "Numarul de elemente din vector este : " << aux.nr_elemente << endl;
    out << "Elementele vectorului sunt : ";
    for(int i : aux.v)
        out<<i<<" ";
    out<<endl<<"==========================="<<endl;

    return out;
}

istream& operator>> (istream& in, Vector &aux)
{
    cout<<endl<<"Introduceti numarul de elemente din vector : ";
    in>>aux.nr_elemente;
    aux.v.resize(aux.nr_elemente);
    cout<<"Introduceti elementele vectorului : ";
    for(int i = 0; i < aux.nr_elemente; i++)
        in >> aux.v[i];
    cout<<endl<<"==========================="<<endl;
    return in;
}

Vector Vector :: operator=(Vector aux)
{
    nr_elemente = aux.nr_elemente;
    v.resize(nr_elemente);
    for(int i = 0; i < nr_elemente; i++)
        v[i] = aux.v[i];
    return *this;
}

int main()
{
    int run = 1;
    int optiune_constructor;

    while(run)
    {
        cout<<endl;
        cout<<"Introduceti modul in care doriti sa fie creat obiectul : "<<endl;
        cout<<"1 - Constructor fara parametru."<<endl;
        cout<<"2 - Constructor cu un singur parametru."<<endl;
        cout<<"3 - Constructor de initializare cu un numar dat pe toate elementele."<<endl;
        cout<<"4 - Citirea a n elemente."<<endl;
        cout<<"0 - Opreste executia programului !!!"<<endl;
        cout<<endl;
        cin>>optiune_constructor;

        switch(optiune_constructor)
        {
            case 0:
                {
                    run = 0;
                    cout<<endl<<"Executia programului va fi oprita."<<endl;
                    cout<<endl<<"Program realizat de Potcoveanu Florin-Razvan - Grupa 132."<<endl;
                    break;
                }
            case 1:
                {
                    int optiune_actiuni, run_actiuni = 1;

                    while(run_actiuni)
                        {

                            Vector obiect1;
                            cout<<endl;
                            cout<<"A fost creat un obiect vid.";
                            cout<<endl;
                            cout<<obiect1;
                            cout<<endl;
                            cout<<"Introduceti numarul actiunii pe care doriti sa o executati : "<<endl;
                            cout<<"1 - Reactualizarea numarului de componente si initializarea componenetelor cu un numar dat."<<endl;
                            cout<<"2 - Suma elementelor vectorului."<<endl;
                            cout<<"3 - Afisarea maximului si pozitiei pe care se afla."<<endl;
                            cout<<"4 - Sortarea crescatoare a algoritmului"<<endl;
                            cout<<"0 - Revenire la meniul anterior."<<endl;
                            cin>>optiune_actiuni;

                            switch(optiune_actiuni)
                            {
                                case 0:
                                    {
                                        run_actiuni = 0;
                                        break;
                                    }

                                case 1:
                                    {
                                        int numar, valoare;

                                        cout<<"Introduceti numarul de elemente din vector : ";
                                        cin>>numar;
                                        cout<<"Introduceti valoare : ";
                                        cin>>valoare;
                                        cout<<endl;

                                        obiect1.actualizare_vector(numar, valoare);

                                        cout<<obiect1;
                                        break;
                                    }

                                case 2:
                                    {
                                        cout<<"Nu se poate calcula suma pentru vector vid."<<endl;
                                        break;
                                    }

                                case 3:
                                    {
                                        cout<<"Nu se poate determina maximul pentru un vector vid."<<endl;
                                        break;
                                    }

                                case 4:
                                    {
                                        cout<<"Nu se poate sorta un vector vid."<<endl;
                                        break;
                                    }

                            }

                        }

                }

            case 2:
                {
                    int optiune_actiuni, run_actiuni = 1;

                    while(run_actiuni)
                        {
                            int elemente;

                            cout<<endl;
                            cout<<"Introduceti numarul de elemente din vector : ";
                            cin>>elemente;
                            cout<<"Introduceti elementele vectorului : ";

                            Vector obiect2(elemente);

                            cout<<"Introduceti numarul actiunii pe care doriti sa o executati : "<<endl;
                            cout<<"1 - Reactualizarea numarului de componente si initializarea componenetelor cu un numar dat."<<endl;
                            cout<<"2 - Suma elementelor vectorului."<<endl;
                            cout<<"3 - Afisarea maximului si pozitiei pe care se afla."<<endl;
                            cout<<"4 - Sortarea crescatoare a algoritmului"<<endl;
                            cout<<"0 - Revenire la meniul anterior."<<endl;
                            cin>>optiune_actiuni;

                            switch(optiune_actiuni)
                            {
                                case 0:
                                    {
                                        run_actiuni = 0;
                                        break;
                                    }

                                case 1:
                                    {
                                        int numar, valoare;

                                        cout<<"Introduceti numarul de elemente din vector : ";
                                        cin>>numar;
                                        cout<<"Introduceti valoare : ";
                                        cin>>valoare;
                                        cout<<endl;

                                        obiect2.actualizare_vector(numar, valoare);

                                        cout<<obiect2;
                                        break;
                                    }

                                case 2:
                                    {
                                        cout<<"Suma elementelor vectorului este : ";
                                        cout<<obiect2.suma_vector();
                                        break;
                                    }

                                case 3:
                                    {
                                        cout<<"Maximul si pozitia pe care se gaseste sunt : ";
                                        obiect2.maxim_vector();
                                        break;
                                    }

                                case 4:
                                    {
                                        cout<<"Vectorul sortat este : ";
                                        obiect2.sortare_vector();
                                        break;
                                    }

                            }

                        }

                }
            case 3:
                {
                    int optiune_actiuni, run_actiuni = 1;

                    while(run_actiuni)
                        {
                            int elemente, valoare;

                            cout<<endl;
                            cout<<"Introduceti numarul de elemente din vector : ";
                            cin>>elemente;
                            cout<<"Introduceti valoarea : ";
                            cin>>valoare;

                            Vector obiect3(elemente, valoare);

                            cout<<"Introduceti numarul actiunii pe care doriti sa o executati : "<<endl;
                            cout<<"1 - Reactualizarea numarului de componente si initializarea componenetelor cu un numar dat."<<endl;
                            cout<<"2 - Suma elementelor vectorului."<<endl;
                            cout<<"3 - Afisarea maximului si pozitiei pe care se afla."<<endl;
                            cout<<"4 - Sortarea crescatoare a algoritmului"<<endl;
                            cout<<"0 - Revenire la meniul anterior."<<endl;
                            cin>>optiune_actiuni;

                            switch(optiune_actiuni)
                            {
                                case 0:
                                    {
                                        run_actiuni = 0;
                                        break;
                                    }

                                case 1:
                                    {
                                        int numar, valoare;
                                        cout<<"Introduceti numarul de elemente din vector : ";
                                        cin>>numar;
                                        cout<<"Introduceti valoare : ";
                                        cin>>valoare;
                                        cout<<endl;

                                        obiect3.actualizare_vector(numar, valoare);

                                        cout<<obiect3;
                                        break;
                                    }

                                case 2:
                                    {
                                        cout<<"Suma elementelor vectorului este : ";
                                        cout<<obiect3.suma_vector();
                                        break;
                                    }

                                case 3:
                                    {
                                        cout<<"Maximul si pozitia pe care se gaseste sunt : ";
                                        obiect3.maxim_vector();
                                        break;
                                    }

                                case 4:
                                    {
                                        cout<<"Vectorul sortat este : ";
                                        obiect3.sortare_vector();
                                        break;
                                    }

                            }

                        }

                }

            case 4:
                {
                    int optiune_actiuni, run_actiuni = 1;

                    while(run_actiuni)
                    {
                        cout<<"Doriti sa mai cititi obiecte noi ? ( 1/0 )"<<endl;
                        cin>>optiune_actiuni;

                        switch(optiune_actiuni)
                        {
                            case 0:
                                {
                                    run_actiuni = 0;
                                    break;
                                }
                            case 1:
                                {
                                    vector<Vector> obiecte;
                                    Vector temporar;
                                    obiecte = temporar.citire_elemente(obiecte);
                                    break;
                                }
                        }
                    }
                }
        }
    }
}
