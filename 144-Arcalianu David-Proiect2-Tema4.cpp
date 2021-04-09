#include <iostream>
#include <algorithm>
#include <string>

const int N = 100;

class Agenda
{
private:
    static int c_nr_persoane;
    std::string c_lista[N];
public:
    // constructor + destructor
    Agenda(){}
    ~Agenda(){}
    // getteri + setteri
//    std::string GetElementAgenda(int index) {return c_lista[index];}
    static int GetNrPersAgenda() {return c_nr_persoane;}
    static void SetNrPersoaneAgenda(int nr) {c_nr_persoane = nr;}
    void SetElementAgenda(int index, std::string element)
    {
        if(c_lista[index] == "")
            c_lista[index] = element;
        else c_lista[index] = c_lista[index] + " " + element;
    }
    void SetElementAgenda(int index, int element)
    {
        if(c_lista[index] == "")
            c_lista[index] = std::to_string(element);
        else c_lista[index] = c_lista[index] + " " + std::to_string(element);
    }
    // operatori
    std::string &operator[](int index)
    {
        return c_lista[index];
    }
    Agenda& operator=(Agenda& agenda)
    {
        c_nr_persoane = agenda.c_nr_persoane;
        for(int i=0; i<agenda.c_nr_persoane; i++)
            agenda.c_lista[i] = c_lista[i];
        return *this;
    }
    friend std::istream &operator>>(std::istream &in, Agenda &agenda)
    {
        in >> agenda.c_nr_persoane;
        for(int i=0; i<agenda.c_nr_persoane; i++)
            in >> agenda.c_lista[i];
        return in;
    }
    friend std::ostream &operator<<(std::ostream &out, Agenda &agenda)
    {
        for(int i=0; i<agenda.c_nr_persoane; i++)
            out << agenda.c_lista[i] << std::endl;
        return out;
    }
    // afisare
    virtual void Afisare(Agenda agenda)
    {
        for(int i=0; i<agenda.GetNrPersAgenda(); i++)
            std::cout << agenda.c_lista[i] << std::endl;
    }
};

int Agenda::c_nr_persoane;

class Persoana
{
protected:
    int c_id;
    std::string c_nume;
public:
    // constructori + destructor
    Persoana()
    {
        c_id = 0;
        c_nume = "";
    }
    Persoana(int id, std::string nume)
    {
        c_id = id;
        c_nume = nume;
    }
    Persoana(Persoana &persoana)
    {
        c_id = persoana.c_id;
        c_nume = persoana.c_nume;
    }
    ~Persoana(){}
    // getteri, setteri
    int GetIdPersoana(){return c_id;}
    std::string GetNumePersoana(){return c_nume;}
    void SetIdPersoana(int id){c_id = id;}
    void SetNumePersoana(std::string nume){c_nume = nume;}
    // operatori
    Persoana& operator=(Persoana& persoana)
    {
        c_id = persoana.c_id;
        c_nume = persoana.c_nume;
        return *this;
    }
    friend std::istream &operator>>(std::istream &in, Persoana &persoana)
    {
        in >> persoana.c_id;
        std::cin.get();
        getline(in,persoana.c_nume);
        return in;
    }
    friend std::ostream &operator<<(std::ostream &out, Persoana &persoana)
    {
        out << "Id: " << persoana.c_id << ", Nume: " << persoana.c_nume;
        return out;
    }
};

class Abonat : public Persoana
{
protected:
    std::string c_nr_tel;
public:
    // constructori + destructor
    Abonat()
    {
        c_nr_tel = "";
    }
    Abonat(std::string nr_tel)
    {
        c_nr_tel = nr_tel;
    }
    Abonat(Abonat &abonat)
    {
        c_nr_tel = abonat.c_nr_tel;
    }
    Abonat(int id, std::string nume, std::string nr_tel): Persoana(id,nume), c_nr_tel(nr_tel){}
    ~Abonat(){}
    // getter + setter
    std::string GetNrTel(){return c_nr_tel;}
    void SetNrTel(std::string nr_tel){c_nr_tel = nr_tel;}
    // operatori
    Abonat& operator=(Abonat& abonat)
    {
        c_nr_tel = abonat.c_nr_tel;
        return *this;
    }
    friend std::istream &operator>>(std::istream &in, Abonat &abonat)
    {
        in >> abonat.c_nr_tel;
        return in;
    }
    friend std::ostream &operator<<(std::ostream &out, Abonat &abonat)
    {
        out << "Numar telefon: " << abonat.c_nr_tel;
        return out;
    }
};

class Abonat_Skype : public Abonat
{
protected:
    std::string c_id_skype;
public:
    // constructori + destructor
    Abonat_Skype()
    {
        c_id_skype = "";
    }
    Abonat_Skype(std::string id_skype)
    {
        c_id_skype = id_skype;
    }
    Abonat_Skype(Abonat_Skype &abonat)
    {
        c_id_skype = abonat.c_id_skype;
    }
    Abonat_Skype(std::string nr_tel, std::string id_skype): Abonat(nr_tel), c_id_skype(id_skype){}
    ~Abonat_Skype(){}
    // getter + setter
    std::string GetIdSkype(){return c_id_skype;}
    void SetIdSkype(std::string id_skype){c_id_skype = id_skype;}
    // operatori
    Abonat_Skype& operator=(Abonat_Skype& abonat)
    {
        c_id_skype = abonat.c_id_skype;
        return *this;
    }
    friend std::istream &operator>>(std::istream &in, Abonat_Skype &abonat)
    {
        in >> abonat.c_id_skype;
        return in;
    }
    friend std::ostream &operator<<(std::ostream &out, Abonat_Skype &abonat)
    {
        out << "ID Skype: " << abonat.c_id_skype;
        return out;
    }
};

class Abonat_Skype_Romania : public Abonat_Skype
{
private:
    std::string c_adresa_email;
public:
    // constructori + destructor
    Abonat_Skype_Romania()
    {
        c_adresa_email = "";
    }
    Abonat_Skype_Romania(std::string adresa_email)
    {
        c_adresa_email = adresa_email;
    }
    Abonat_Skype_Romania(Abonat_Skype_Romania& abonat)
    {
        c_adresa_email = abonat.c_adresa_email;
    }
    Abonat_Skype_Romania(std::string adresa_email, std::string id_skype): Abonat_Skype(id_skype), c_adresa_email(adresa_email){}
    ~Abonat_Skype_Romania(){}
    // getter + setter
    std::string GetAdresaEmail(){return c_adresa_email;}
    void SetAdresaEmail(std::string adresa_email){c_adresa_email = adresa_email;}
    // operatori
    Abonat_Skype_Romania& operator=(Abonat_Skype_Romania& abonat)
    {
        c_adresa_email = abonat.c_adresa_email;
        return *this;
    }
    friend std::istream &operator>>(std::istream &in, Abonat_Skype_Romania &abonat)
    {
        in >> abonat.c_adresa_email;
        return in;
    }
    friend std::ostream &operator<<(std::ostream &out, Abonat_Skype_Romania &abonat)
    {
        out << "Adresa email: " << abonat.c_adresa_email;
        return out;
    }
};

class Abonat_Skype_Extern : public Abonat_Skype
{
private:
    std::string c_tara;
public:
    // constructori + destructor
    Abonat_Skype_Extern()
    {
        c_tara = "";
    }
    Abonat_Skype_Extern(std::string tara)
    {
        c_tara = tara;
    }
    Abonat_Skype_Extern(Abonat_Skype_Extern& abonat)
    {
        c_tara = abonat.c_tara;
    }
    Abonat_Skype_Extern(std::string tara, std::string id_skype): Abonat_Skype(id_skype), c_tara(tara){}
    ~Abonat_Skype_Extern(){}
    // getter + setter
    std::string GetTara(){return c_tara;}
    void SetTara(std::string tara){c_tara = tara;}
    // operatori
    Abonat_Skype_Extern& operator=(Abonat_Skype_Extern& abonat)
    {
        c_tara = abonat.c_tara;
        return *this;
    }
    friend std::istream &operator>>(std::istream &in, Abonat_Skype_Extern &abonat)
    {
        in >> abonat.c_tara;
        return in;
    }
    friend std::ostream &operator<<(std::ostream &out, Abonat_Skype_Extern &abonat)
    {
        out << "Tara: " << abonat.c_tara;
        return out;
    }
};

void printMenuOptions()
{
    std::cout << "1: Cititi n abonati si datele lor" << std::endl;
    std::cout << "2: Afisati abonatii" << std::endl;
    std::cout << "3: Afisati date pentru un abonat anume" << std::endl;
    std::cout << "4: Oprire" << std::endl;
}

std::string ToLower(std::string x)
{
    std::transform(x.begin(), x.end(), x.begin(), ::tolower);
    return x;
}

void Meniu()
{
    std::cout << "Alegeti dintre urmatoarele optiuni: " << std::endl;
    printMenuOptions();
    int exit_option = 4;
    int option;
    int nr;

    Agenda agenda;
    std::cin>>option;

    while(option != exit_option)
    {
        if(option == 1)
        {
            std::cout << "Cititi numarul de abonati:" << std::endl;
            std::cin >> nr;
            agenda.SetNrPersoaneAgenda(nr);

            Persoana persoana;
            Abonat abonat;
            Abonat_Skype abonatSkype;
            Abonat_Skype_Romania abonatSkypeRomania;
            Abonat_Skype_Extern abonatSkypeExtern;

            for(int i=0; i<agenda.GetNrPersAgenda(); i++)
            {
                std::cout << "Cititi id-ul si numele persoanei:" << std::endl;
                std::cin >> persoana;
                agenda.SetElementAgenda(i,persoana.GetIdPersoana());
                agenda.SetElementAgenda(i,persoana.GetNumePersoana());

                std::cout << "Cititi numarul de telefon:" << std::endl;
                std::cin >> abonat;
                agenda.SetElementAgenda(i,abonat.GetNrTel());

                std::cout << "Cititi id skype:" << std::endl;
                std::cin >> abonatSkype;
                agenda.SetElementAgenda(i,abonatSkype.GetIdSkype());

                std::string tara;
                std::cout << "Romania sau Extern?" << std::endl;
                std::cin.get();
                getline(std::cin,tara);
                if(ToLower(tara) == "romania")
                {
                    agenda.SetElementAgenda(i,tara);
                    std::cout << "Cititi adresa de email:" << std::endl;
                    std::cin >> abonatSkypeRomania;
                    agenda.SetElementAgenda(i,abonatSkypeRomania.GetAdresaEmail());
                }
                else
                {
                    abonatSkypeExtern.SetTara(tara);
                    agenda.SetElementAgenda(i,abonatSkypeExtern.GetTara());
                }
            }
        }
        if(option == 2)
        {
            agenda.Afisare(agenda);
        }
        if(option == 3)
        {
            std::cout << "Cititi numele abonatului pentru a afisa datele:" << std::endl;
            std::string nume;
            std::cin.get();
            getline(std::cin,nume);
            bool ok = 0;
            for(int i=0; i<agenda.GetNrPersAgenda(); i++)
            {
                size_t found = agenda[i].find(nume);
                if(found != std::string::npos)
                {
                    std::cout << agenda[i] << std::endl;
                    ok = 1;
                    break;
                }
            }
            if(!ok)
                std::cout << "Nu exista abonatul specificat" << std::endl;
        }
        std::cout << std::endl;
        printMenuOptions();
        std::cin >> option;
    }
}

int main()
{
    Meniu();
    return 0;
}
