#include <iostream>
#include "student.h"
#include "professor.h"
#include <memory>
#include <cstdlib>
#include <chrono>
#include "io.h"


std::vector<std::unique_ptr<professor>> list_pro{};
std::vector<std::unique_ptr<student>> list_stu{};
std::vector<std::shared_ptr<azmoon>> list_azmoon{};
int vared_shode_pro{};
int vared_shode_stu{};

// Sentinel stored in azmoon::nomreha for a student who has not been graded yet.
const double NOMRE_DADE_NASHODE = 111.2;

bool name_karbari_tekrari(const std::string& u);
void sabt_stu();
void sabt_pro();
bool vorood_stu();
bool vorood_pro();
bool panel();
void panel_stu();
void panel_pro();
void azmoon_jadid();
void tarikhche();
void modiriyat();
void tashih();
void moroor();
void dadan_azmoon();
void nomarat();
int jaye_daneshjoo(const std::shared_ptr<azmoon>& az, int shomare_stu);

int main()
{
    while (panel()) {
    }
    return 0;
}




bool panel() {
    std::cout << "===============  panel azmoonyar  =============== \n";
    std::cout << "1 . vorood daneshjooyan" << std::endl;
    std::cout << "2 . vorood asatid" << std::endl;
    std::cout << "3 . sabt nam daneshjooyan" << std::endl;
    std::cout << "4 . sabt nam asatid" << std::endl;
    std::cout << "5 . khorooj az barname" << std::endl;

    std::cout << "\n->";
    int n;
    if (!bekhan_adad(n)) {
        return false;
    }
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

    case 5:
        return false;
    }

    return true;
}
bool name_karbari_tekrari(const std::string& u) {
    for (size_t i = 0; i < list_stu.size(); i++) {
        if (u == list_stu[i]->user_name) {
            return true;
        }
    }
    for (size_t i = 0; i < list_pro.size(); i++) {
        if (u == list_pro[i]->user_name) {
            return true;
        }
    }
    return false;
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
    if (name_karbari_tekrari(u)) {
        std::cout << "in name karbari qablan estefade shode ast!\n dobare talash konid." << std::endl;
        goto label1;
    }
    std::cout << "password :" << std::endl;
    std::cout << "->";
    std::cin >> p;
    std::cout << "\n";
    std::cout << "shomare daneshjoyi :" << std::endl;
    bekhan_adad(n);
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
    if (name_karbari_tekrari(u)) {
        std::cout << "in name karbari qablan estefade shode ast!\n dobare talash konid." << std::endl;
        goto label1;
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
    bekhan_adad(e);
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

label5:
    std::cout << std::endl;
    std::cout << "*******************************************************" << std::endl;

    std::cout << "karbar : " << list_stu[vared_shode_stu]->first_name << " " << list_stu[vared_shode_stu]->last_name << std::endl;
    std::cout << std::endl;

    std::cout << "1. moroor azmoon ha" << std::endl;
    std::cout << "2. dadan azmoon" << std::endl;
    std::cout << "3. nomarat" << std::endl;
    std::cout << "4. khorooj az hesab" << std::endl;

    std::cout << "\n->";
    int e;
    bekhan_adad(e);
    switch (e)
    {
    case 1:
        moroor();
        goto label5;
        break;
    case 2:
        dadan_azmoon();
        goto label5;
        break;
    case 3:
        nomarat();
        goto label5;
        break;
    case 4:
        break;

    }
}

// Where this student sits in an exam's parallel students/nomreha vectors.
// Returns -1 if the student is not enrolled on that exam.
int jaye_daneshjoo(const std::shared_ptr<azmoon>& az, int shomare_stu) {
    for (size_t i = 0; i < az->students.size(); i++) {
        if (az->students[i] == shomare_stu) {
            return static_cast<int>(i);
        }
    }
    return -1;
}

// Sits an exam: shows each question in turn and collects an answer, stopping
// early if the professor's time limit runs out. The whole sheet is stored as
// one string in the student's pasokhha slot for that exam, which is what the
// professor's grading screen reads.
//
// The clock is checked between questions, not during one. A student already
// looking at a question keeps as long as they like to answer it; the limit
// stops them being shown the next one. Interrupting a blocking read would need
// threads or platform-specific console input, which is more than this program
// is built for.
void dadan_azmoon() {
    student& man = *list_stu[vared_shode_stu];
    if (man.azmoonha.empty()) {
        std::cout << "shoma dar hich azmooni sabt nam nashodeid!" << std::endl;
        return;
    }

    std::cout << "======   azmoon haye shoma   ======" << std::endl;
    for (size_t i = 0; i < man.azmoonha.size(); i++) {
        std::cout << i + 1 << ". " << man.azmoonha[i]->get_name()
            << "  (" << man.azmoonha[i]->time << " daqiqe, "
            << man.azmoonha[i]->get_tedad_soal() << " soal)";
        if (i < man.pasokhha.size() && !man.pasokhha[i].empty()) {
            std::cout << "   --> qablan dade shode";
        }
        std::cout << std::endl;
    }
    std::cout << "\n->";
    int n;
    if (!bekhan_adad(n)) {
        return;
    }
    if (n < 1 || n > static_cast<int>(man.azmoonha.size())) {
        std::cout << "shomare azmoon motabar nist!" << std::endl;
        return;
    }

    size_t shomare_azmoon = static_cast<size_t>(n - 1);
    std::shared_ptr<azmoon> az = man.azmoonha[shomare_azmoon];

    while (man.pasokhha.size() <= shomare_azmoon) {
        man.pasokhha.push_back("");
    }
    if (!man.pasokhha[shomare_azmoon].empty()) {
        std::cout << "shoma qablan in azmoon ra dade id!" << std::endl;
        return;
    }
    if (az->soalat.empty()) {
        std::cout << "in azmoon hanooz soali nadarad!" << std::endl;
        return;
    }

    system("cls");
    std::cout << "===============  " << az->get_name() << "  ===============" << std::endl;
    std::cout << "tedad soalat : " << az->get_tedad_soal() << std::endl;
    std::cout << "zaman        : " << az->time << " daqiqe" << std::endl;
    std::cout << "\nbaraye shoroo Enter ra bezanid...";
    std::string khali;
    std::getline(std::cin, khali);
    std::getline(std::cin, khali);

    std::chrono::steady_clock::time_point shoroo = std::chrono::steady_clock::now();
    long long koll_sanie = static_cast<long long>(az->time) * 60;

    std::string barge;
    size_t javab_dade = 0;
    for (size_t i = 0; i < az->soalat.size(); i++) {
        long long gozashte = std::chrono::duration_cast<std::chrono::seconds>(
            std::chrono::steady_clock::now() - shoroo).count();
        long long mande = koll_sanie - gozashte;
        if (mande <= 0) {
            std::cout << "\nzaman azmoon tamam shod!" << std::endl;
            break;
        }

        system("cls");
        std::cout << "soal " << i + 1 << " az " << az->soalat.size()
            << "   |   zaman baqimande: " << mande / 60 << " daqiqe va "
            << mande % 60 << " sanie" << std::endl;
        std::cout << "-------------------------------------------------------" << std::endl;
        az->soalat[i]->show();
        std::cout << "\npasokh -> ";

        std::string pasokh;
        if (!std::getline(std::cin, pasokh)) {
            break;
        }
        barge += std::to_string(i + 1) + ") " + (pasokh.empty() ? "-" : pasokh) + "\n";
        javab_dade++;
    }

    for (size_t i = javab_dade; i < az->soalat.size(); i++) {
        barge += std::to_string(i + 1) + ") -\n";
    }
    man.pasokhha[shomare_azmoon] = barge;

    std::cout << "\npasokh haye shoma sabt shod. (" << javab_dade << " az "
        << az->soalat.size() << " soal javab dade shod)" << std::endl;
}

// The student's own grades, one line per exam they are enrolled on.
void nomarat() {
    student& man = *list_stu[vared_shode_stu];
    if (man.azmoonha.empty()) {
        std::cout << "shoma dar hich azmooni sabt nam nashodeid!" << std::endl;
        return;
    }
    std::cout << "======   nomarat   ======" << std::endl;
    for (size_t i = 0; i < man.azmoonha.size(); i++) {
        std::cout << man.azmoonha[i]->get_name() << " -> ";
        int p = jaye_daneshjoo(man.azmoonha[i], vared_shode_stu);
        if (p >= 0 && p < static_cast<int>(man.azmoonha[i]->nomreha.size())
            && man.azmoonha[i]->nomreha[p] != NOMRE_DADE_NASHODE) {
            std::cout << man.azmoonha[i]->nomreha[p] << std::endl;
        }
        else {
            std::cout << "nomre dade nashode!" << std::endl;
        }
    }
}

void azmoon_jadid() {
    std::cout << "name e azmoon jadid ra vared konid:" << std::endl;
    std::string nn;
    std::cin >> nn;
    std::cout << "modat zaman azmoon ra be daqiqe vared konid:" << std::endl;
    int t{};
    bekhan_adad(t);
    list_azmoon.push_back(std::make_shared<azmoon>(nn,t));
    list_pro[vared_shode_pro]->azmoonha.push_back(list_azmoon[list_azmoon.size() - 1]);
    
    label2:
    std::cout << "1. ezafe kardan e soalat" << std::endl;
    std::cout << "2. daneshjooyan" << std::endl;
    std::cout << "3. ezafe kardane in azmoon" << std::endl;

    int e;
    bekhan_adad(e);
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
        bekhan_adad(n);
        for (int j = 0; j < n; j++) {
            std::string esm, famil;
            int shomare;
            bool bood{ false };
            std::cout << "nam daneshjoo ra vared konid" << std::endl;
            std::cin >> esm;
            std::cout << "nam khanevadegi daneshjoo ra vared konid" << std::endl;
            std::cin >> famil;
            std::cout << "shomare daneshjooyi daneshjoo ra vared konid" << std::endl;
            bekhan_adad(shomare);
            for (size_t i = 0; i < list_stu.size(); i++) {
                if (list_stu[i]->first_name == esm && list_stu[i]->last_name == famil && list_stu[i]->stu_number == shomare) {
                    list_stu[i]->azmoonha.push_back(list_azmoon[list_azmoon.size() - 1]);
                    list_stu[i]->pasokhha.push_back("");
                    list_azmoon[list_azmoon.size() - 1]->students.push_back(static_cast<int>(i));
                    list_azmoon[list_azmoon.size() - 1]->nomreha.push_back(NOMRE_DADE_NASHODE);
                    bood = true;
                }
            }
            if (!bood) {
                list_stu.push_back(std::make_unique<student>(esm, famil, shomare));
                list_stu.back()->azmoonha.push_back(list_azmoon[list_azmoon.size() - 1]);
                list_stu.back()->pasokhha.push_back("");
                list_azmoon[list_azmoon.size() - 1]->students.push_back(static_cast<int>(list_stu.size() - 1));
                list_azmoon[list_azmoon.size() - 1]->nomreha.push_back(NOMRE_DADE_NASHODE);
            }
        }
        goto label2;
        break;
    case 3:
        break;
    }

   
}
void tarikhche() {
    if (list_pro[vared_shode_pro]->azmoonha.empty()) {
        std::cout << "hanooz hich azmooni ijad nakardeid!" << std::endl;
        return;
    }
    std::cout << "***************************" << std::endl;
    for (size_t i = 0; i < list_pro[vared_shode_pro]->azmoonha.size(); i++) {
        std::cout << i+1 << ".  "<<  list_pro[vared_shode_pro]->azmoonha[i]->get_name() << std::endl;
    }
    std::cout << "***************************" << std::endl;
    std::cout << "adade marboot be azmoon mored nazar ra vared konid:" << std::endl;
    std::cout << "\n->";
    int n;
    bekhan_adad(n);
    system("cls");
    std::cout << "***************************" << std::endl;
    std::cout << list_pro[vared_shode_pro]->azmoonha[n - 1]->name << " :" << std::endl;
    std::cout << "***************************" << std::endl;
    std::cout << "daneshjooyan e in emtehan be hamrah nomre ha:" << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
    if (list_pro[vared_shode_pro]->azmoonha[n - 1]->students.size() != 0) {
        for (size_t i = 0; i < list_pro[vared_shode_pro]->azmoonha[n - 1]->students.size(); i++) {
            int p = list_pro[vared_shode_pro]->azmoonha[n - 1]->students[i];
            std::cout << list_stu[p]->first_name << " " << list_stu[p]->last_name << std::endl;
            if (list_pro[vared_shode_pro]->azmoonha[n - 1]->nomreha[i] != NOMRE_DADE_NASHODE) {
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
    if (list_pro[vared_shode_pro]->azmoonha.empty()) {
        std::cout << "hanooz hich azmooni ijad nakardeid!" << std::endl;
        return;
    }
    std::cout << "adade marboot be azmoon mored nazar ra vared konid:" << std::endl;
    for (size_t i = 0; i < list_pro[vared_shode_pro]->azmoonha.size(); i++) {
        std::cout << i + 1 << ".  " << list_pro[vared_shode_pro]->azmoonha[i]->get_name() << std::endl;
    }
    int n;
    bekhan_adad(n);
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
    bekhan_adad(e);
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
        bekhan_adad(oo);
        for (int j = 0; j < oo; j++) {
            std::string esm, famil;
            int shomare;
            bool bood{ false };
            std::cout << "nam daneshjoo ra vared konid" << std::endl;
            std::cin >> esm;
            std::cout << "nam khanevadegi daneshjoo ra vared konid" << std::endl;
            std::cin >> famil;
            std::cout << "shomare daneshjooyi daneshjoo ra vared konid" << std::endl;
            bekhan_adad(shomare);
            for (size_t i = 0; i < list_stu.size(); i++) {
                if (list_stu[i]->first_name == esm && list_stu[i]->last_name == famil && list_stu[i]->stu_number == shomare) {
                    list_stu[i]->azmoonha.push_back(list_pro[vared_shode_pro]->azmoonha[n - 1]);
                    list_stu[i]->pasokhha.push_back("");
                    list_pro[vared_shode_pro]->azmoonha[n - 1]->students.push_back(static_cast<int>(i));
                    list_pro[vared_shode_pro]->azmoonha[n - 1]->nomreha.push_back(NOMRE_DADE_NASHODE);
                    bood = true;
                }
            }
            if (!bood) {
                list_stu.push_back(std::make_unique<student>(esm, famil, shomare));
                list_stu.back()->azmoonha.push_back(list_pro[vared_shode_pro]->azmoonha[n - 1]);
                list_stu.back()->pasokhha.push_back("");
                list_pro[vared_shode_pro]->azmoonha[n - 1]->students.push_back(static_cast<int>(list_stu.size() - 1));
                list_pro[vared_shode_pro]->azmoonha[n - 1]->nomreha.push_back(NOMRE_DADE_NASHODE);
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

    if (list_pro[vared_shode_pro]->azmoonha.empty()) {
        std::cout << "hanooz hich azmooni ijad nakardeid!" << std::endl;
        return;
    }
    std::cout << "adade marboot be azmoon mored nazar ra vared konid:" << std::endl;
    for (size_t i = 0; i < list_pro[vared_shode_pro]->azmoonha.size(); i++) {
        std::cout << i + 1 << ".  " << list_pro[vared_shode_pro]->azmoonha[i]->get_name() << std::endl;
    }
    int n;
    bekhan_adad(n);
label4:
    std::cout << "***************************" << std::endl;
    std::cout << "azmoon ---> " << list_pro[vared_shode_pro]->azmoonha[n - 1]->name << std::endl;
    std::cout << "***************************" << std::endl;
    std::cout << "daneshjooye mored nazar ra entekhab konid:" << std::endl;
    for (size_t i = 0; i < list_pro[vared_shode_pro]->azmoonha[n - 1]->students.size(); i++) {
        if (list_pro[vared_shode_pro]->azmoonha[n - 1]->nomreha[i] == NOMRE_DADE_NASHODE) {
            std::cout << i + 1 << ". " << list_stu[list_pro[vared_shode_pro]->azmoonha[n - 1]->students[i]]->first_name << " " << list_stu[list_pro[vared_shode_pro]->azmoonha[n - 1]->students[i]]->last_name << std::endl;
        }
    }
    std::cout << "\n->";
    int e{};
    bekhan_adad(e);

    std::shared_ptr<azmoon> azmoon_faal = list_pro[vared_shode_pro]->azmoonha[n - 1];
    int shomare_stu = azmoon_faal->students[e - 1];
    int shomare_pasokh = -1;
    for (size_t i = 0; i < list_stu[shomare_stu]->azmoonha.size(); i++) {
        if (list_stu[shomare_stu]->azmoonha[i] == azmoon_faal) {
            shomare_pasokh = static_cast<int>(i);
            break;
        }
    }
    if (shomare_pasokh >= 0 && shomare_pasokh < static_cast<int>(list_stu[shomare_stu]->pasokhha.size())
        && !list_stu[shomare_stu]->pasokhha[shomare_pasokh].empty()) {
        std::cout << list_stu[shomare_stu]->pasokhha[shomare_pasokh] << std::endl;
    }
    else {
        std::cout << "pasokhi sabt nashode ast!" << std::endl;
    }

    std::cout << "nomre ra vared konid:" << std::endl;
    std::cout << "\n->";
    int k;
    bekhan_adad(k);
    list_pro[vared_shode_pro]->azmoonha[n - 1]->nomreha[e - 1] = k;

    std::cout << "1. tashih daneshjooye digar" << std::endl;
    std::cout << "2. bazgasht be menu" << std::endl;
    std::cout << "\n->";
    int edame{};
    bekhan_adad(edame);
    if (edame == 1) {
        goto label4;
    }
}
void moroor() {
    std::cout << "======   moroor azmoon ha   ======" << std::endl;
    for (size_t i = 0; i < list_stu[vared_shode_stu]->azmoonha.size(); i++) {
        std::cout << list_stu[vared_shode_stu]->azmoonha[i]->name << std::endl;
    }


}