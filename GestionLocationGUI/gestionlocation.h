#ifndef GESTIONLOCATION_H
#define GESTIONLOCATION_H

#include <QMainWindow>
#include <iostream>

QT_BEGIN_NAMESPACE
namespace Ui { class GestionLocation; }
QT_END_NAMESPACE

class GestionLocation : public QMainWindow
{
    Q_OBJECT

public:
    GestionLocation(QWidget *parent = nullptr);
    ~GestionLocation();

private slots:
    void on_rental_clicked();

    void on_return1_clicked();

    void on_return2_clicked();

    void on_return3_clicked();

    void on_managecar_clicked();

    void on_manageclient_clicked();

    void on_listcar_clicked();

    void on_return4_clicked();

    void on_addcar_clicked();

    void on_addcar2_clicked();

    void on_savereturn_clicked();

    void on_recherche_clicked();

    void on_modcar_clicked();

    void on_savereturn_2_clicked();

    void on_savereturn_3_clicked();

    void on_addclient_clicked();

    void on_modclient_clicked();

    void on_return4_2_clicked();

    void on_addclient_2_clicked();

    void on_savereturn_4_clicked();

    void on_listclient_clicked();

    void on_recherche_2_clicked();

    void on_deletecar_2_clicked();

    void on_delcar_clicked();

    void on_showcontract_clicked();

    void on_search_clicked();

    void on_findclient_clicked();

    void on_validate_clicked();

    void on_saverent_clicked();

    void on_save_clicked();

    void on_delcontrat_clicked();

    void on_deleteclient_2_clicked();

    void on_rentcar_clicked();

    void on_modcontract_clicked();

    void on_delcontract_clicked();

    void on_delclient_clicked();

    void on_return4_3_clicked();

    void on_return_3_clicked();

    void on_pushButton_12_clicked();

    void on_return_4_clicked();

    void on_return_5_clicked();

    void on_return_6_clicked();

    void on_return_7_clicked();

    void on_return_8_clicked();

    void on_return_2_clicked();

    void on_return_9_clicked();

    void on_return_10_clicked();

    void on_return_11_clicked();

    void on_return_12_clicked();

private:
    Ui::GestionLocation *ui;

    void enlocation(int id, std::string strg);

    int search_client(int ID);
};
#endif // GESTIONLOCATION_H
