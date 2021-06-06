#include "gestionlocation.h"
#include "ui_gestionlocation.h"
#include <qstackedwidget.h>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

class Date{
    public:
        unsigned int jj;
        unsigned int mm;
        unsigned int aa;
};

class Voiture{
    public:
        int IDVoiture;
        string marque;
        string NomVoiture;
        string couleur;
        int Nbplaces;
        int PrixJour;
        string EnLocation;
};

class ContratLocation{
    public:
        float NumContrat;
        int IDVoiture;
        int IDClient;
        Date Debut;
        Date Fin;
        int Cout;
};

class Client{
    public:
        int IDClient;
        string Nom;
        string Prenom;
        int CIN;
        string Adresse;
        int Telephone;
};

int GestionLocation::search_client(int ID)
{
    Client var;
    ifstream file;
    string line, a, b, c, d, e;
    file.open("Clients", ios::in);
    if (file.is_open())
    {
        while (getline(file, line))
        {
            istringstream str(line);
            str >> var.IDClient >> a >> var.Nom >> b >> var.Prenom >> c >> var.CIN >> d >> var.Adresse >> e >> var.Telephone;
            if (var.IDClient == ID)
            {
                return 1;
            }
        }
        file.close();
    }
    else ui->stackedWidget->setCurrentIndex(18);
    return 0;

}

void GestionLocation::enlocation(int id, string strg)
{
    string line, a, b, c, d, e;
    ifstream f1;
    ofstream f2;
    Voiture va;
    f1.open("Voitures", ios::in);
    f2.open("Voiture", ios::app);
    if (f1.is_open() && f2.is_open())
    {
        while (getline(f1,line))
        {
            istringstream str(line);
            str >> va.IDVoiture >> a >> va.marque >> b >> va.NomVoiture >> c >> va.couleur >> d >> va.Nbplaces >> e >> va.PrixJour;
            if (va.IDVoiture == id)
            {
                va.EnLocation = strg;
                f2 << va.IDVoiture <<" | "<< va.marque <<" | "<< va.NomVoiture <<" | "<< va.couleur <<" | "<< va.Nbplaces <<" | "<< va.PrixJour <<"\n";
            }
            else
                f2 << va.IDVoiture <<" | "<< va.marque <<" | "<< va.NomVoiture <<" | "<< va.couleur <<" | "<< va.Nbplaces <<" | "<< va.PrixJour <<"\n";
        }
        f1.close();
        f2.close();
    }
    else ui->stackedWidget->setCurrentIndex(18);
}

GestionLocation::GestionLocation(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::GestionLocation)
{
    ui->setupUi(this);
}

GestionLocation::~GestionLocation()
{
    delete ui;
}

//first menu
void GestionLocation::on_rental_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void GestionLocation::on_managecar_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void GestionLocation::on_manageclient_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}

//second menu

void GestionLocation::on_return2_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

//third menu
void GestionLocation::on_return1_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void GestionLocation::on_listcar_clicked()
{
    Voiture var;
    ifstream f1;
    string line;
    f1.open("Voitures", ios::in);
    if (f1.is_open())
    {
        while (getline(f1,line))
        {
            istringstream str(line);
            ui->carlist->setText(ui->carlist->text() + QString::fromStdString(str.str()) + "\n");
        }
        f1.close();
    }
    else ui->stackedWidget->setCurrentIndex(18);
    ui->stackedWidget->setCurrentIndex(4);
}

void GestionLocation::on_addcar_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
}


//fourth menu
void GestionLocation::on_return3_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

//add car menu
void GestionLocation::on_return4_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void GestionLocation::on_addcar2_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
}

void GestionLocation::on_savereturn_clicked()
{
    ofstream Voi;
    Voiture var;
    Voi.open("Voitures", ios::app);
    if (Voi.is_open())
    {
        var.IDVoiture = ui->idvoit->text().toInt();
        var.marque = ui->marque->text().toStdString();
        var.NomVoiture = ui->nomvoit->text().toStdString();
        var.couleur = ui->couleur->text().toStdString();
        var.Nbplaces = ui->nbplace->text().toInt();
        var.PrixJour = ui->prixjour->text().toInt();
        var.EnLocation = "Non";
        Voi << var.IDVoiture <<" | "<< var.marque <<" | "<< var.NomVoiture <<" | "<< var.couleur <<" | "<< var.Nbplaces <<" | "<< var.PrixJour <<"\n";
        ui->idvoit->clear();
        ui->marque->clear();
        ui->nomvoit->clear();
        ui->couleur->clear();
        ui->nbplace->clear();
        ui->prixjour->clear();
        Voi.close();
    }
    else ui->stackedWidget->setCurrentIndex(18);
}

//modify car

void GestionLocation::on_recherche_clicked()
{
    bool found = true;
    int id;
    Voiture var;
    ifstream f1;
    string line, a, b, c, d, e;
    id = ui->idsearch->text().toInt();
    f1.open("Voitures", ios::in);
    if (f1.is_open())
    {
        while (getline(f1,line) && found)
        {
            istringstream str(line);
            str >> var.IDVoiture >> a >> var.marque >> b >> var.NomVoiture >> c >> var.couleur >> d >> var.Nbplaces >> e >> var.PrixJour;
            if (var.IDVoiture == id)
            {
                ui->idvoit_2->setEnabled(true);
                ui->marque_2->setEnabled(true);
                ui->nomvoit_2->setEnabled(true);
                ui->couleur_2->setEnabled(true);
                ui->nbplace_2->setEnabled(true);
                ui->prixjour_2->setEnabled(true);

                ui->idvoit_2->setText(QString::number(var.IDVoiture));
                ui->marque_2->setText(QString::fromStdString(var.marque));
                ui->nomvoit_2->setText(QString::fromStdString(var.NomVoiture));
                ui->couleur_2->setText(QString::fromStdString(var.couleur));
                ui->nbplace_2->setText(QString::number(var.Nbplaces));
                ui->prixjour_2->setText(QString::number(var.PrixJour));
                found = false;
            }
        }
        f1.close();
    }
    else ui->stackedWidget->setCurrentIndex(18);
}

void GestionLocation::on_modcar_clicked()
{
    ui->idvoit_2->setEnabled(false);
    ui->marque_2->setEnabled(false);
    ui->nomvoit_2->setEnabled(false);
    ui->couleur_2->setEnabled(false);
    ui->nbplace_2->setEnabled(false);
    ui->prixjour_2->setEnabled(false);
    ui->stackedWidget->setCurrentIndex(6);
}


void GestionLocation::on_savereturn_2_clicked()
{
    int id;
    Voiture var, va;
    ifstream f1;
    ofstream f2;
    string line, a, b, c, d, e;
    id = ui->idsearch->text().toInt();
    f1.open("Voitures", ios::in);
    f2.open("Voiture", ios::out);
    if (f1.is_open() && f2.is_open())
    {
        while (getline(f1,line))
        {
            istringstream str(line);
            str >> va.IDVoiture >> a >> va.marque >> b >> va.NomVoiture >> c >> va.couleur >> d >> va.Nbplaces >> e >> va.PrixJour;
            if (va.IDVoiture == id)
            {
                var.IDVoiture = ui->idvoit_2->text().toInt();
                var.marque = ui->marque_2->text().toStdString();
                var.NomVoiture = ui->nomvoit_2->text().toStdString();
                var.couleur = ui->couleur_2->text().toStdString();
                var.Nbplaces = ui->nbplace_2->text().toInt();
                var.PrixJour = ui->prixjour_2->text().toInt();
                var.EnLocation = "Non";
                f2 << var.IDVoiture <<" | "<< var.marque <<" | "<< var.NomVoiture <<" | "<< var.couleur <<" | "<< var.Nbplaces <<" | "<< var.PrixJour <<"\n";
            }
            else f2 << va.IDVoiture <<" | "<< va.marque <<" | "<< va.NomVoiture <<" | "<< va.couleur <<" | "<< va.Nbplaces <<" | "<< va.PrixJour <<"\n";
        }
        f1.close();
        f2.close();
    }
    else ui->stackedWidget->setCurrentIndex(18);

    ui->idvoit_2->clear();
    ui->marque_2->clear();
    ui->nomvoit_2->clear();
    ui->couleur_2->clear();
    ui->nbplace_2->clear();
    ui->prixjour_2->clear();
    remove("Voitures");
    rename("Voiture","Voitures");
}


void GestionLocation::on_savereturn_3_clicked()
{
    ofstream Cli;
    Client var;
    Cli.open("Clients", ios::app);
    if (Cli.is_open())
    {
        var.IDClient = ui->idclient->text().toInt();
        var.Nom = ui->nom->text().toStdString();
        var.Prenom = ui->prenom->text().toStdString();
        var.CIN = ui->cin->text().toInt();
        var.Adresse = ui->adresse->text().toStdString();
        var.Telephone = ui->telephone->text().toInt();
        Cli << var.IDClient <<" | "<< var.Nom <<" | "<< var.Prenom <<" | "<< var.CIN <<" | "<< var.Adresse <<" | "<< var.Telephone <<"\n";
        ui->idclient->clear();
        ui->nom->clear();
        ui->prenom->clear();
        ui->cin->clear();
        ui->adresse->clear();
        ui->telephone->clear();
        Cli.close();
    }
    else ui->stackedWidget->setCurrentIndex(18);
}


void GestionLocation::on_addclient_clicked()
{
    ui->stackedWidget->setCurrentIndex(8);
}


void GestionLocation::on_modclient_clicked()
{
    ui->idclient_2->setEnabled(false);
    ui->nom_2->setEnabled(false);
    ui->prenom_2->setEnabled(false);
    ui->cin_2->setEnabled(false);
    ui->adresse_2->setEnabled(false);
    ui->telephone_2->setEnabled(false);
    ui->stackedWidget->setCurrentIndex(9);
}


void GestionLocation::on_return4_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}


void GestionLocation::on_addclient_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(8);
}


void GestionLocation::on_savereturn_4_clicked()
{
    bool succes = false;
    int id;
    Client var;
    ifstream f1;
    ofstream f2;
    string line, a, b, c, d, e;
    id = ui->idclient_3->text().toInt();
    f1.open("Clients", ios::in);
    f2.open("Client", ios::out);
    if (f1.is_open() && f2.is_open())
    {
        while (getline(f1,line))
        {
            istringstream str(line);
            str >> var.IDClient >> a >> var.Nom >> b >> var.Prenom >> c >> var.CIN >> d >> var.Adresse >> e >> var.Telephone;
            if (var.IDClient != id)
            {
                var.IDClient = ui->idclient_2->text().toInt();
                var.Nom = ui->nom_2->text().toStdString();
                var.Prenom = ui->prenom_2->text().toStdString();
                var.CIN = ui->cin_2->text().toInt();
                var.Adresse = ui->adresse_2->text().toStdString();
                var.Telephone = ui->telephone_2->text().toInt();
                f2 << var.IDClient <<" | "<< var.Nom <<" | "<< var.Prenom <<" | "<< var.CIN <<" | "<< var.Adresse <<" | "<< var.Telephone <<"\n";
                succes = true;
            }
        }
        f1.close();
        f2.close();
    }
    else ui->stackedWidget->setCurrentIndex(18);
    remove("Clients");
    rename("Client","Clients");
    if (succes == true) ui->delmsg_3->setText("Succes");
    else ui->delmsg_3->setText("ERREUR");
}


void GestionLocation::on_listclient_clicked()
{
    ifstream f1;
    string line;
    f1.open("Clients", ios::in);
    if (f1.is_open())
    {
        while (getline(f1,line))
        {
            istringstream str(line);
            ui->list_3->setText(ui->list_3->text() + QString::fromStdString(str.str()) + "\n");
        }
        f1.close();
    }
    else ui->stackedWidget->setCurrentIndex(18);
    ui->stackedWidget->setCurrentIndex(7);
}


void GestionLocation::on_recherche_2_clicked()
{
    bool found = true;
    int id;
    Client var, va;
    ifstream f1;
    string line, a, b, c, d, e;
    id = ui->idsearch_2->text().toInt();
    f1.open("Voitures", ios::in);
    if (f1.is_open())
    {
        while (getline(f1,line) && found)
        {
            istringstream str(line);
            str >> var.IDClient >> a >> var.Nom >> b >> var.Prenom >> c >> var.CIN >> d >> var.Adresse >> e >> var.Telephone;
            if (var.IDClient == id)
            {
                ui->idclient_2->setEnabled(true);
                ui->nom_2->setEnabled(true);
                ui->prenom_2->setEnabled(true);
                ui->cin_2->setEnabled(true);
                ui->adresse_2->setEnabled(true);
                ui->telephone_2->setEnabled(true);

                ui->idclient_2->setText(QString::number(var.IDClient));
                ui->nom_2->setText(QString::fromStdString(var.Nom));
                ui->prenom_2->setText(QString::fromStdString(var.Prenom));
                ui->cin_2->setText(QString::number(var.CIN));
                ui->adresse_2->setText(QString::fromStdString(var.Adresse));
                ui->telephone_2->setText(QString::number(var.Telephone));
                found = false;
            }
        }
        f1.close();
    }
    else ui->stackedWidget->setCurrentIndex(18);
    if (found == false) ui->result_2->setText("Succes");
    else ui->result_2->setText("ERREUR");
}


void GestionLocation::on_deletecar_2_clicked()
{
    int id;
    Voiture va;
    ifstream f1;
    ofstream f2;
    string line, a, b, c, d, e;
    id = ui->idcar->text().toInt();
    f1.open("Voitures", ios::in);
    f2.open("Voiture", ios::out);
    if (f1.is_open() && f2.is_open())
    {
        while (getline(f1,line))
        {
            istringstream str(line);
            str >> va.IDVoiture >> a >> va.marque >> b >> va.NomVoiture >> c >> va.couleur >> d >> va.Nbplaces >> e >> va.PrixJour;
            if (va.IDVoiture != id)
            {
                f2 << va.IDVoiture <<" | "<< va.marque <<" | "<< va.NomVoiture <<" | "<< va.couleur <<" | "<< va.Nbplaces <<" | "<< va.PrixJour <<"\n";
            }
        }
        f1.close();
        f2.close();
        ui->delmsg->setText("Succes");
    }
    else ui->delmsg->setText("ERROR!");
    remove("Voitures");
    rename("Voiture","Voitures");
    ui->list->clear();

    f1.open("Voitures", ios::in);
    if (f1.is_open())
    {
        while (getline(f1,line))
        {
            istringstream str(line);
            ui->list->setText(ui->list->text() + QString::fromStdString(str.str()) + "\n");
        }
        f1.close();
    }
}

void GestionLocation::on_deleteclient_2_clicked()
{
    int id;
    Client var;
    ifstream f1;
    ofstream f2;
    string line, a, b, c, d, e;
    ui->delmsg_3->text();
    id = ui->idclient_3->text().toInt();
    f1.open("Clients", ios::in);
    f2.open("Client", ios::out);
    if (f1.is_open() && f2.is_open())
    {
        while (getline(f1,line))
        {
            istringstream str(line);
            str >> var.IDClient >> a >> var.Nom >> b >> var.Prenom >> c >> var.CIN >> d >> var.Adresse >> e >> var.Telephone;
            if (var.IDClient != id)
                f2 << var.IDClient <<" | "<< var.Nom <<" | "<< var.Prenom <<" | "<< var.CIN <<" | "<< var.Adresse <<" | "<< var.Telephone <<"\n";
        }
        f1.close();
        f2.close();
        remove("Clients");
        rename("Client","Clients");
    }
    else ui->stackedWidget->setCurrentIndex(18);
    ui->delmsg_3->setText("Succes");
    ui->list_3->clear();
    f1.open("Clients", ios::in);
    if (f1.is_open())
    {
        while (getline(f1,line))
        {
            istringstream str(line);
            ui->list_3->setText(ui->list_3->text() + QString::fromStdString(str.str()) + "\n");
        }
        f1.close();
    }
    else ui->stackedWidget->setCurrentIndex(18);
}

void GestionLocation::on_delcar_clicked()
{
    //load the data of the file in the label on click
    ui->stackedWidget->setCurrentIndex(10);
    ifstream f1;
    string line;
    f1.open("Voitures", ios::in);
    if (f1.is_open())
    {
        while (getline(f1,line))
        {
            istringstream str(line);
            ui->list->setText(ui->list->text() + QString::fromStdString(str.str()) + "\n");
        }
        f1.close();
    }
    else ui->stackedWidget->setCurrentIndex(18);
}


void GestionLocation::on_showcontract_clicked()
{
    ui->stackedWidget->setCurrentIndex(12);
}


void GestionLocation::on_search_clicked()
{
    bool find = true;
    int ID_Client, ID_Car;
    ContratLocation var;
    ifstream file;
    string line, a, b, c, d, e, f, g, h, i, j;
    ID_Client = ui->id_client->text().toInt();
    ID_Car = ui->id_car->text().toInt();
    file.open("ContratsLocations", ios::in);
    if (file.is_open())
    {
        while (getline(file, line) && find)
            {
                istringstream str(line);
                str >> var.NumContrat >> a >> var.IDVoiture >> b >> var.IDClient >> c >> var.Debut.jj >> d >> var.Debut.mm >> e >> var.Debut.aa >> f >> var.Fin.jj >> g >> var.Fin.mm >> h >> var.Fin.aa >> i >> var.Cout;
                if (var.IDClient == ID_Client && var.IDVoiture == ID_Car)
                {
                    ui->stackedWidget->setCurrentIndex(13);
                    ui->id_car->clear();
                    ui->id_client->clear();

                    ui->numcontrat->setText(QString::number(var.NumContrat));
                    ui->id_car_2->setText(QString::number(var.IDVoiture));
                    ui->id_client_2->setText(QString::number(var.IDClient));
                    ui->debutjj->setText(QString::number(var.Debut.jj));
                    ui->debutmm->setText(QString::number(var.Debut.mm));
                    ui->debutaa->setText(QString::number(var.Debut.aa));
                    ui->finjj->setText(QString::number(var.Fin.jj));
                    ui->finmm->setText(QString::number(var.Fin.mm));
                    ui->finaa->setText(QString::number(var.Fin.aa));
                    ui->cout->setText(QString::number(var.Cout));
                    find = false;
                }
            }
        file.close();
    }
    else
    {
        ui->searchresult->setText("ERREUR");
        ui->stackedWidget->setCurrentIndex(18);
    }
}


void GestionLocation::on_findclient_clicked()
{
    ContratLocation con;
    Voiture var;
    string line, a, b, c, d, e;
    ifstream f1;
    con.IDClient = ui->clientsearch->text().toInt();
    if (!search_client(con.IDClient))
    {
        ui->feedback->setText("Votre ID n'est existe pas");
    }
    else
    {
        con.IDVoiture = ui->carsearch->text().toInt();
        f1.open("Voitures", ios::in);
        if (f1.is_open())
        {
            while (getline(f1,line))
            {
                istringstream str(line);
                str >> var.IDVoiture >> a >> var.marque >> b >> var.NomVoiture >> c >> var.couleur >> d >> var.Nbplaces >> e >> var.PrixJour;
                if (var.EnLocation == "Non")
                {
                    ui->availablecars->setText(ui->list->text() + QString::fromStdString(str.str()) + "\n");
                }
            }
            f1.close();
            ui->stackedWidget->setCurrentIndex(15);
        }
        else ui->stackedWidget->setCurrentIndex(18);
        ui->numcontrat_2->setEnabled(false);
        ui->debutjj_2->setEnabled(false);
        ui->debutmm_2->setEnabled(false);
        ui->debutaa_2->setEnabled(false);
        ui->finjj_2->setEnabled(false);
        ui->finmm_2->setEnabled(false);
        ui->finaa_2->setEnabled(false);
        ui->cout_2->setEnabled(false);
    }
}


void GestionLocation::on_validate_clicked()
{
    bool find = false;
    ContratLocation var1;
    Voiture var;
    ifstream f1;
    string line, a, b, c, d, e;
    var1.IDClient = ui->clientsearch->text().toInt();
    var1.IDVoiture = ui->carsearch->text().toInt();
    f1.open("Voitures", ios::in);
    if (f1.is_open())
    {
        while (getline(f1,line) && find == false)
        {
            istringstream str(line);
            str >> var.IDVoiture >> a >> var.marque >> b >> var.NomVoiture >> c >> var.couleur >> d >> var.Nbplaces >> e >> var.PrixJour;
            if (var.EnLocation == "Non" && var.IDVoiture == var1.IDVoiture)
            {
                find = true;
            }
        }
        f1.close();
    }
    else ui->stackedWidget->setCurrentIndex(18);
    if(find)
    {
        ui->numcontrat_2->setEnabled(true);
        ui->debutjj_2->setEnabled(true);
        ui->debutmm_2->setEnabled(true);
        ui->debutaa_2->setEnabled(true);
        ui->finjj_2->setEnabled(true);
        ui->finmm_2->setEnabled(true);
        ui->finaa_2->setEnabled(true);
        ui->cout_2->setEnabled(true);
    }
}


void GestionLocation::on_saverent_clicked()
{
    ContratLocation var;
    ofstream f;
    var.IDClient = ui->clientsearch->text().toInt();
    var.IDVoiture = ui->carsearch->text().toInt();
    var.NumContrat = ui->numcontrat_2->text().toInt();
    var.Debut.jj = ui->debutjj_2->text().toInt();
    var.Debut.mm = ui->debutmm_2->text().toInt();
    var.Debut.aa = ui->debutaa_2->text().toInt();
    var.Fin.jj = ui->debutjj_2->text().toInt();
    var.Fin.mm = ui->debutmm_2->text().toInt();
    var.Fin.aa = ui->finaa_2->text().toInt();
    var.Cout = ui->cout_2->text().toInt();
    f.open("ContratsLocations", ios::app);
    if (f.is_open())
    {
        f << var.NumContrat << " | " << var.IDVoiture << " | " << var.IDClient << " | " << var.Debut.jj << " | " << var.Debut.mm << " | " << var.Debut.aa << " | " << var.Fin.jj << " | " << var.Fin.mm << " | " << var.Fin.aa << " | " << var.Cout;
        f.close();
    }
    else ui->stackedWidget->setCurrentIndex(18);
}


void GestionLocation::on_save_clicked()
{
    int IDVoit;
    ifstream f1;
    ofstream f2;
    ContratLocation var, va;
    string line, a, b, c, d, e, f, g, h, i;
    IDVoit = ui->id_voit->text().toInt();
    f1.open("ContratsLocations", ios::in);
    f2.open("Contrat", ios::app);
    if (f1.is_open() && f2.is_open())
    {
        while (getline(f1,line))
        {
            istringstream str(line);
            str >> var.NumContrat >> a >> var.IDVoiture >> b >> var.IDClient >> c >> var.Debut.jj >> d >> var.Debut.mm >> e >> var.Debut.aa >> f >> var.Fin.jj >> g >> var.Fin.mm >> h >> var.Fin.aa >> i >> var.Cout;
            if (var.IDVoiture == IDVoit)
            {
                va.IDClient = ui->idclient_4->text().toInt();
                va.IDVoiture = ui->idvoit_3->text().toInt();
                va.NumContrat = ui->numcontrat_3->text().toInt();
                va.Debut.jj = ui->debutjj_3->text().toInt();
                va.Debut.mm = ui->debutmm_3->text().toInt();
                va.Debut.aa = ui->debutaa_3->text().toInt();
                va.Fin.jj = ui->debutjj_3->text().toInt();
                va.Fin.mm = ui->debutmm_3->text().toInt();
                va.Fin.aa = ui->finaa_3->text().toInt();
                va.Cout = ui->cout_3->text().toInt();
                f2 << va.NumContrat << " | " << va.IDVoiture << " | " << va.IDClient << " | " << va.Debut.jj << " | " << va.Debut.mm << " | " << va.Debut.aa << " | " << va.Fin.jj << " | " << va.Fin.mm << " | " << va.Fin.aa << " | " << va.Cout;
            }
            else f2 << var.NumContrat << " | " << var.IDVoiture << " | " << var.IDClient << " | " << var.Debut.jj << " | " << var.Debut.mm << " | " << var.Debut.aa << " | " << var.Fin.jj << " | " << var.Fin.mm << " | " << var.Fin.aa << " | " << var.Cout;
        }
        f1.close();
        f2.close();
        remove("ContratsLocations");
        rename("Contrat", "ContratsLocations");
        enlocation(IDVoit, "Non");
    }
    else ui->stackedWidget->setCurrentIndex(18);
}



void GestionLocation::on_delcontrat_clicked()
{
    bool find = false;
    int id;
    ContratLocation var;
    ifstream f1;
    ofstream f2;
    string line, a, b, c, d, e, f, g, h, i;
    id = ui->idvoitcontrat->text().toInt();
    f1.open("ContratsLocations", ios::in);
    f2.open("Contrat", ios::out);
    if (f1.is_open() && f2.is_open())
    {
        while (getline(f1,line))
        {
            istringstream str(line);
            str >> var.NumContrat >> a >> var.IDVoiture >> b >> var.IDClient >> c >> var.Debut.jj >> d >> var.Debut.mm >> e >> var.Debut.aa >> f >> var.Fin.jj >> g >> var.Fin.mm >> h >> var.Fin.aa >> i >> var.Cout;
            if (var.IDVoiture != id)
            {
                f2 << var.NumContrat << " | " << var.IDVoiture << " | " << var.IDClient << " | " << var.Debut.jj << " | " << var.Debut.mm << " | " << var.Debut.aa << " | " << var.Fin.jj << " | " << var.Fin.mm << " | " << var.Fin.aa << " | " << var.Cout;
                find = true;
            }
        }
        f1.close();
        f2.close();
        remove("ContratsLocations");
        rename("Contrat", "ContratsLocations");
    }
    if (find == true) ui->delmsg_2->setText("Succes");
    else ui->delmsg_2->setText("ERREUR");
}




void GestionLocation::on_rentcar_clicked()
{
    ui->stackedWidget->setCurrentIndex(14);
}


void GestionLocation::on_modcontract_clicked()
{
    ui->stackedWidget->setCurrentIndex(16);
}


void GestionLocation::on_delcontract_clicked()
{
    ifstream f1;
    string line;
    f1.open("ContratsLocations", ios::in);
    if (f1.is_open())
    {
        while (getline(f1,line))
        {
            istringstream str(line);
            ui->list_2->setText(ui->list_2->text() + QString::fromStdString(str.str()) + "\n");
        }
        f1.close();
   }
    ui->stackedWidget->setCurrentIndex(17);
}


void GestionLocation::on_delclient_clicked()
{
    ifstream f1;
    string line;
    f1.open("Clients", ios::in);
    if (f1.is_open())
    {
        while (getline(f1,line))
        {
            istringstream str(line);
            ui->list_3->setText(ui->list_3->text() + QString::fromStdString(str.str()) + "\n");
        }
        f1.close();
    }
    else ui->stackedWidget->setCurrentIndex(18);
    ui->stackedWidget->setCurrentIndex(11);
}


void GestionLocation::on_return4_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}


void GestionLocation::on_return_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}


void GestionLocation::on_pushButton_12_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}


void GestionLocation::on_return_4_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}


void GestionLocation::on_return_5_clicked()
{
    ui->list->clear();
    ui->stackedWidget->setCurrentIndex(2);
}


void GestionLocation::on_return_6_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}


void GestionLocation::on_return_7_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}


void GestionLocation::on_return_8_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}


void GestionLocation::on_return_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}


void GestionLocation::on_return_9_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}


void GestionLocation::on_return_10_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}


void GestionLocation::on_return_11_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}


void GestionLocation::on_return_12_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

