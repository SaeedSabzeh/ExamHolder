#include <iostream>
#include "student.h"
#include "professor.h"
#include <memory>
#include <Windows.h>


std::vector<std::unique_ptr<professor>> list_pro{};
std::vector<std::unique_ptr<student>> list_stu{};
std::vector<std::shared_ptr<azmoon>> list_azmoon{};
int vared_shode_pro{};
int vared_shode_stu{};

void sabt_stu();
void sabt_pro();
bool vorood_stu();
bool vorood_pro();
void panel();
void panel_stu();
void panel_pro();
void azmoon_jadid();
void tarikhche();
void modiriyat();
void tashih();
void moroor();

int main()
{
 
    while (true) {
        panel();
    }
    return 0;
}




void panel() {
    std::cout << "===============  panel azmoonyar  =============== \n";
    std::cout << "1 . vorood daneshjooyan" << std::endl;
    std::cout << "2 . vorood asatid" << std::endl;
    std::cout << "3 . sabt nam daneshjooyan" << std::endl;
    std::cout << "4 . sabt nam asatid" << std::endl;

    std::cout << "\n->";
    int n;
    std::cin >> n;
    system("cls");
    switch (n) {
    case 1:
        std::cout << "========   vorood daneshjooyan   ========" << std::endl;
        if (vorood_stu()) {
            panel_stu();
        }
        else {
            std::cout << "========>   username va password motabar nist!" << std::endl;
        }
        break;

    case 2:
        std::cout << "========   vorood asatid   ======== " << std::endl;
        if (vorood_pro()) {
            panel_pro();
        }
        else {
            std::cout << "========>   username va password motabar nist!" << std::endl;
        }
        break;

    case 3:
        std::cout << "========   sabte nam daneshjooyan   ========" << std::endl;
        sabt_stu();
        break;

    case 4:
        std::cout << "========   sabte nam asatid   ========" << std::endl;
        sabt_pro();
        break;
    }


}
void sabt_stu() {
    std::string f, l, u, p;
    int n;
    std::cout << "nam :" << std::endl;
    std::cout << "->";
    std::cin >> f;
    std::cout << "\n";
    std::cout << "name khanevadegi :" << std::endl;
    std::cout << "->";
    std::cin >> l;
    std::cout << "\n";
    std::cout << "username :" << std::endl;
    label1:
    std::cout << "->";
    std::cin >> u;
    std::cout << "\n";
    for (size_t i = 0; i < list_stu.size(); i++) {
        if (u == list_stu[i]->user_name || u == list_pro[i]->user_name) {
            std::cout << "in name karbari qablan estefade shode ast!\n dobare talash konid." << std::endl;
            goto label1;
        }
    }
    std::cout << "password :" << std::endl;
    std::cout << "->";
    std::cin >> p;  
    std::cout << "\n";
    std::cout << "shomare daneshjoyi :" << std::endl;
    std::cin >> n;
    list_stu.push_back(std::make_unique<student>(f, l, u, p, n));
}

void sabt_pro() {
    std::string f, l, u, p;

    std::cout << "nam :" << std::endl;  
    std::cout << "->";
    std::cin >> f;
    std::cout << "\n";
    std::cout << "name khanevadegi :" << std::endl;  
    std::cout << "->";
    std::cin >> l;    
    std::cout << "\n";
    std::cout << "username :" << std::endl;
label1:
    std::cout << "->";
    std::cin >> u;
    std::cout << "\n";
    for (size_t i = 0; i < list_stu.size(); i++) {
        if (u == list_stu[i]->user_name || u == list_pro[i]->user_name) {
            std::cout << "in name karbari qablan estefade shode ast!\n dobare talash konid." << std::endl;
            goto label1;
        }
    }
    std::cout << "password :" << std::endl;
    std::cout << "->";
    std::cin >> p;
    std::cout << "\n";
    list_pro.push_back(std::make_unique<professor>(f, l, u, p));
}
bool vorood_stu() {
    std::string u, p;
    std::cout << "usename :" << std::endl;
    std::cout << "->";
    std::cin >> u;
    std::cout << "\n";
    std::cout << "password :" << std::endl;
    std::cout << "->";
    std::cin >> p;
    std::cout << "\n";
    for (size_t i = 0; i < list_stu.size(); i++) {
        if (u == list_stu[i]->user_name && p == list_stu[i]->password) {
            vared_shode_stu = i;
            return true;
        }
    }
    return false;
}
bool vorood_pro() {
    std::string u, p;
    std::cout << "usename :" << std::endl;
    std::cout << "->";
    std::cin >> u;
    std::cout << "\n";
    std::cout << "password :" << std::endl;
    std::cout << "->";
    std::cin >> p;
    std::cout << "\n";
    for (size_t i = 0; i < list_pro.size(); i++) {
        if (u == list_pro[i]->user_name && p == list_pro[i]->password) {
            vared_shode_pro = i;
            return true;
        }
    }
    return false;
}

void panel_pro() {
    system("cls");
    std::cout << "*******************************************************" << std::endl;
    std::cout << "ba movafaqiat vared shodid!" << std::endl;
label3:
    std::cout << "\n";
    std::cout << "*******************************************************" << std::endl;
   
    std::cout << "karbar : " << list_pro[vared_shode_pro]->first_name << " " << list_pro[vared_shode_pro]->last_name << std::endl;
    std::cout << std::endl;

    std::cout << "1. ijad azmoon" << std::endl;
    std::cout << "2. tarikhche azmoon haye bargozar shode" << std::endl;
    std::cout << "3. modiriyat azmoon ha" << std::endl;
    std::cout << "4. tashih azmoon haye bargozar shode" << std::endl;
    std::cout << "5. khorooj az hesab" << std::endl;

    std::cout << "\n->";

    int e;
    std::cin >> e;
    switch (e)
    {
    case 1:
        azmoon_jadid();
        goto label3;
        break;
    case 2:
        tarikhche();
        goto label3;
        break;
    case 3:
        modiriyat();
        goto label3;
        break;
    case 4:
        tashih();
        goto label3;
        break;
    case 5: 
        break;
    }
}
void panel_stu () {
    system("cls");
    std::cout << "*******************************************************" << std::endl;
    std::cout << "ba movafaqiat vared shodid!" << std::endl;
    std::cout << "*******************************************************" << std::endl;

    std::cout << "karbar : " << list_stu[vared_shode_pro]->first_name << " " << list_stu[vared_shode_pro]->last_name << std::endl;
    std::cout << std::endl;

    std::cout << "1. moroor azmoon ha" << std::endl;
    std::cout << "2. azmoon haye baadi va dar hal bargozari" << std::endl;
    std::cout << "3. nomarat" << std::endl;
    std::cout << "4. khorooj az hesab" << std::endl;

    std::cout << "\n->";
    int e;
    std::cin >> e;
    switch (e)
    {
    case 1:
        moroor();
        break;
    case 2:

        break;
    case 3:
        break;
    case 4: 
        break;

    }
}

void azmoon_jadid() {
    std::cout << "name e azmoon jadid ra vared konid:" << std::endl;
    std::string nn;
    std::cin >> nn;
    std::cout << "modat zaman azmoon ra be daqiqe vared konid:" << std::endl;
    int t{};
    std::cin >> t;
    list_azmoon.push_back(std::make_shared<azmoon>(nn,t));
    list_pro[vared_shode_pro]->azmoonha.push_back(list_azmoon[list_azmoon.size() - 1]);
    
    label2:
    std::cout << "1. ezafe kardan e soalat" << std::endl;
    std::cout << "2. daneshjooyan" << std::endl;
    std::cout << "3. ezafe kardane in azmoon" << std::endl;

    int e;
    std::cin >> e;
    switch (e)
    {
    case 1:
        list_azmoon[list_azmoon.size() - 1]->add_soal();
        goto label2;
        break;
    case 2:
        std::cout << "tedad daneshjooyan jahat ezafe kardan ra vared konid" << std::endl;
        int n;
        std::cout << "->";
        std::cin >> n;
        for (int j = 0; j < n; j++) {
            std::string esm, famil;
            int shomare;
            bool bood{ false };
            std::cout << "nam daneshjoo ra vared konid" << std::endl;
            std::cin >> esm;
            std::cout << "nam khanevadegi daneshjoo ra vared konid" << std::endl;
            std::cin >> famil;
            std::cout << "shomare daneshjooyi daneshjoo ra vared konid" << std::endl;
            std::cin >> shomare;
            for (int i = 0; i < list_stu.size(); i++) {
                if (list_stu[i]->first_name == esm && list_stu[i]->last_name == famil && list_stu[i]->stu_number == shomare) {
                    list_stu[i]->azmoonha.push_back(list_azmoon[list_azmoon.size() - 1]);
                    list_azmoon[list_azmoon.size() - 1]->students.push_back(i);
                    list_azmoon[list_azmoon.size() - 1]->nomreha.push_back(111.2);
                    bood = true;
                }
            }
            if (!bood) {
                list_stu.push_back(std::make_unique<student>(esm, famil, shomare));
                list_stu.back()->azmoonha.push_back(list_azmoon[list_azmoon.size() - 1]);
                list_azmoon[list_azmoon.size() - 1]->students.push_back(list_stu.size() - 1);
                list_azmoon[list_azmoon.size() - 1]->nomreha.push_back(111.2);
            }
        }
        goto label2;
        break;
    case 3:
        break;
    }

   
}
void tarikhche() {
    std::cout << "***************************" << std::endl;
    for (int i = 0; i < list_pro[vared_shode_pro]->azmoonha.size(); i++) {
        std::cout << i+1 << ".  "<<  list_pro[vared_shode_pro]->azmoonha[i]->get_name() << std::endl;
    }
    std::cout << "***************************" << std::endl;
    std::cout << "adade marboot be azmoon mored nazar ra vared konid:" << std::endl;
    std::cout << "\n->";
    int n;
    std::cin >> n;
    system("cls");
    std::cout << "***************************" << std::endl;
    std::cout << list_pro[vared_shode_pro]->azmoonha[n - 1]->name << " :" << std::endl;
    std::cout << "***************************" << std::endl;
    std::cout << "daneshjooyan e in emtehan be hamrah nomre ha:" << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
    if (list_pro[vared_shode_pro]->azmoonha[n - 1]->students.size() != 0) {
        for (int i = 0; i < list_pro[vared_shode_pro]->azmoonha[n - 1]->students.size(); i++) {
            int p = list_pro[vared_shode_pro]->azmoonha[n - 1]->students[i];
            std::cout << list_stu[p]->first_name << " " << list_stu[p]->last_name << std::endl;
            if (list_pro[vared_shode_pro]->azmoonha[n - 1]->nomreha[i] != 111.2) {
                std::cout << "->";
                std::cout << list_pro[vared_shode_pro]->azmoonha[n - 1]->nomreha[i] << std::endl;
            }
            else {
                std::cout << "->";
                std::cout << "nomre dade nashode!" << std::endl;

            }
            std::cout << std::endl;
        }
    }
    else{
        std::cout << "hich daneshjooyi be in azmoon ezafe nashode ast!" << std::endl;
    }

}
void modiriyat() {
    std::cout << "adade marboot be azmoon mored nazar ra vared konid:" << std::endl;
    for (int i = 0; i < list_pro[vared_shode_pro]->azmoonha.size(); i++) {
        std::cout << i + 1 << ".  " << list_pro[vared_shode_pro]->azmoonha[i]->get_name() << std::endl;
    }
    int n;
    std::cin >> n;
label4:
    system("cls");

    std::cout << "***************************" << std::endl;
    std::cout << list_pro[vared_shode_pro]->azmoonha[n - 1]->name << " :" << std::endl;
    std::cout << "zaman ekhtesas dadeshode: " << list_pro[vared_shode_pro]->azmoonha[n - 1]->time << " daqiqe" << std::endl;
    std::cout << "***************************" << std::endl;
    std::cout << "1. taqyire nam azmoon" << std::endl;
    std::cout << "2. taqyire zaman azmoon" << std::endl;
    std::cout << "3. ezafe kardane daneshjoo be in azmoon" << std::endl;
    std::cout << "4. ezafe kardane soal be in azmoon" << std::endl;
    std::cout << "5. bazgasht be menu e qabli" << std::endl;

    std::cout << "\n->" ;
    int e;
    std::cin >> e;
    switch (e)
    {
    case 1:
        std::cout << "nam jadid ra baraye in azmoon vared konid:" << std::endl;
        std::cout << "\n->";
        std::cin >> list_pro[vared_shode_pro]->azmoonha[n - 1]->name;
        goto label4;
        break;
    case 2:
        std::cout << " time jadid ra baraye in azmoon vared konid:" << std::endl;
        std::cout << "\n->";
        std::cin >> list_pro[vared_shode_pro]->azmoonha[n - 1]->time;
        goto label4;
        break;
    case 3:
        std::cout << "tedad daneshjooyan jahat ezafe kardan ra vared konid" << std::endl;
        int oo;
        std::cout << "->";
        std::cin >> oo;
        for (int j = 0; j < oo; j++) {
            std::string esm, famil;
            int shomare;
            bool bood{ false };
            std::cout << "nam daneshjoo ra vared konid" << std::endl;
            std::cin >> esm;
            std::cout << "nam khanevadegi daneshjoo ra vared konid" << std::endl;
            std::cin >> famil;
            std::cout << "shomare daneshjooyi daneshjoo ra vared konid" << std::endl;
            std::cin >> shomare;
            for (int i = 0; i < list_stu.size(); i++) {
                if (list_stu[i]->first_name == esm && list_stu[i]->last_name == famil && list_stu[i]->stu_number == shomare) {
                    list_stu[i]->azmoonha.push_back(list_pro[vared_shode_pro]->azmoonha[n - 1]);
                    list_stu[i]->pasokhha.push_back("");
                    list_pro[vared_shode_pro]->azmoonha[n - 1]->students.push_back(i);
                    list_pro[vared_shode_pro]->azmoonha[n - 1]->nomreha.push_back(0.0);
                    bood = true;
                }
            }
            if (!bood) {
                list_stu.push_back(std::make_unique<student>(esm, famil, shomare));
                list_stu.back()->azmoonha.push_back(list_azmoon[list_azmoon.size() - 1]);
                list_stu.back()->pasokhha.push_back({""});
                list_pro[vared_shode_pro]->azmoonha[n - 1]->students.push_back(list_stu.size() - 1);
                list_pro[vared_shode_pro]->azmoonha[n - 1]->nomreha.push_back(0.0);
            }
        }
        goto label4;
        break;
    case 4:
        list_pro[vared_shode_pro]->azmoonha[n - 1]->add_soal();
        goto label4;
        break;
    case 5:
        break;
    }


}

void tashih() {
    system("cls");
    std::cout << "======   tashih azmoonha   ======" << std::endl;

    std::cout << "adade marboot be azmoon mored nazar ra vared konid:" << std::endl;
    for (int i = 0; i < list_pro[vared_shode_pro]->azmoonha.size(); i++) {
        std::cout << i + 1 << ".  " << list_pro[vared_shode_pro]->azmoonha[i]->get_name() << std::endl;
    }
    int n;
    std::cin >> n;
label4:
    std::cout << "***************************" << std::endl;
    std::cout << "azmoon ---> " << list_pro[vared_shode_pro]->azmoonha[n - 1]->name << std::endl;
    std::cout << "***************************" << std::endl;
    std::cout << "daneshjooye mored nazar ra entekhab konid:" << std::endl;
    for (int i = 0; i < list_pro[vared_shode_pro]->azmoonha[n - 1]->students.size(); i++) {
        if (list_pro[vared_shode_pro]->azmoonha[n - 1]->nomreha[i] == 111.2) {
            std::cout << i + 1 << ". " << list_stu[list_pro[vared_shode_pro]->azmoonha[n - 1]->students[i]]->first_name << " " << list_stu[list_pro[vared_shode_pro]->azmoonha[n - 1]->students[i]]->last_name << std::endl;
        }
    }
    std::cout << "\n->";
    int e{};
    std::cin >> e;
    std::cout << list_stu[list_pro[vared_shode_pro]->azmoonha[n - 1]->students[e - 1]]->pasokhha[] << std::endl;

    std::cout << "nomre ra vared konid:" << std::endl;
    std::cout << "\n->";
    int k;
    std::cin >> k;
    list_pro[vared_shode_pro]->azmoonha[n - 1]->nomreha[e - 1] = k;
    goto label4;
}
void moroor() {
    std::cout << "======   moroor azmoon ha   ======" << std::endl;
    for (int i = 0; i < list_stu[vared_shode_stu]->azmoonha.size(); i++) {
        std::cout << list_stu[vared_shode_stu]->azmoonha[i]->name << std::endl;
    }


}