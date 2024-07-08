#include <iostream>
#include "menu.h"

using namespace std;

void displayMenu(){
    cout << "-_-_-_-_-_-_- L A Z A R U S -_-_-_-_-_-_-_-" << endl;
    cout << "1. Cadastrar um astronauta" << endl;
    cout << "2. Criar uma nova viagem espacial" << endl;
    cout << "3. Adicionar astronauta a uma viagem" << endl;
    cout << "4. Remover astronauta de uma viagem" << endl;
    cout << "5. Lançar alguma viagem programada" << endl;
    cout << "6. Notificar chegada de viagem" << endl;
    cout << "7. Notificar explosão de viagem" << endl;
    cout << "8. Mostrar todas as viagens" << endl;
    cout << "9. Mostrar detahes de uma viagem" << endl;
    cout << "10. Procurar astronauta no sistema" << endl;
    cout << "11. Sair do programa" << endl;
}

void verifyStatus(int id, vector<Journey> journeys){
    if(journeys[id].getStatus() == 0){
        cout << "Viagem concluída sem êxito" << endl;
    }
    else if(journeys[id].getStatus() == 1){
        cout << "Viagem planejada" << endl;
    }
    else if (journeys[id].getStatus() == 2){
        cout << "Viagem em curso" << endl;
    }
    else{
        cout << "Viagem concluída com êxito" << endl;
    }
}

int searchAstronaut(string cpf, vector<Astronaut>& astronauts){
    for(int i = 0; i < astronauts.size(); i++){
        if(cpf == astronauts[i].getCpf()){
            return i;
        }
    }
}

void cadastreAstro(string cpf, vector<Astronaut> astronauts){
    string nome;
    cout << "Digite o nome completo do astronauta: ";
    cin >> nome;
    Astronaut astro(cpf, nome);
    astronauts.push_back(astro);
}

bool astronautAlreadyRegistered(string cpf, vector<Astronaut> astronauts){
    for(int i = 0; i < astronauts.size(); i++){
        string cpfAux = astronauts[i].getCpf();
        if(cpf == cpfAux){
            return true;
        }
    }
    return false;
}

void cadastreJourney(int id, vector<Journey>& journeys){
    Journey trip(id);
    journeys.push_back(trip);
}

void addAstro(vector<Journey>& journeys, vector<Astronaut>& astronauts){
    int id;
    string cpf;
    cout << "Digite o ID da viagem que deseja cadastrar seu astronauta: ";
    cin >> id;
    cout << "\nDigite o CPF do seu astronauta agora: ";
    cin >> cpf;
    int position = searchAstronaut(cpf, astronauts);
    shared_ptr<Astronaut> astronaut = make_shared<Astronaut>(astronauts[position]);
    vector<std::shared_ptr<Astronaut>> astronautsInJourney = journeys[id].getAstrosInJourney();
    
    if(astronautAlreadyRegistered(cpf, astronauts)){
        for(int i = 0; i < astronautsInJourney.size(); i++){
            if(astronautsInJourney[i]->getCpf() == cpf){
                cout << "\nO astronauta já está cadastrado nessa viagem!" << endl;
            }
            else if(astronauts[position].getStatus() == 0){
                cout << "\nO astronauta está morto!" << endl;
            }
        }
        journeys[id].addAstronaut(astronaut);
        cout << "\nO astronauta foi adicionado a sua viagem!";
        astronauts[position].addId(id);
        }
    
    else{
        cout << "\nO astronauta não está cadastro em nosso banco de dados!" << endl;
    }
}

void detailsOfJourney(int id, vector<Journey> &journeys){
    std::vector<std::shared_ptr<Astronaut>> astrosInJourney = journeys[id].getAstrosInJourney();
    cout << "Essa viagem possui " << astrosInJourney.size() << " astronautas!" << endl;
    cout << "Eles são: " << endl;
    for(int i = 0; i < astrosInJourney.size(); i++){
        astrosInJourney[i]->showAstronaut();
        cout << "-----------------------------------------------------------";
    }
    verifyStatus(id, journeys);
}

void showJourney(vector<Journey> &journeys){
    for(int i = 0; i < journeys.size(); i++){
        cout << "ID: " << journeys[i].getID() << " || Status: ";
        verifyStatus(i, journeys);
    }
}

void finishJourney(int status, vector<Journey> &journeys){
    int id;
    cout << "Digite o ID da viagem: ";
    cin >> id;
    cout << endl;
    id --;
    if(journeys[id].getStatus() == 1){
        journeys[id].changeJourneyStatus(status);
    }
    else{
        cout << "Viagem indisponível no momento, para mais detalhes consulte no menu inicial!" << endl;
    }
}

void removeAstro(vector<Journey> journeys){
    int id;
    string cpf;
    cout << "Digite o ID da viagem que deseja cadastrar seu astronauta: ";
    cin >> id;
    cout << "\nDigite o CPF do seu astronauta agora: ";
    cin >> cpf;
    journeys[id].removeAstronautByCpf(cpf);
}

void beginJourney(vector<Journey> &journeys){
    int id;
    cout << "Digite o ID da viagem: ";
    cin >> id;
    cout << endl;
    id --;
    vector<std::shared_ptr<Astronaut>> astronautsInJourney = journeys[id].getAstrosInJourney();
    for(int i =0; i < astronautsInJourney.size(); i++){
        if(astronautsInJourney[i]->getStatus() == 0 || astronautsInJourney[i]->getStatus() == 2){
            cout << "Alguns dos astronautas não estão prontos para começar a missão." << endl;
            cout << "Consulte detalhes no menu inicial dentro da opção 'Mostrar detahes de uma viagem'" << endl;
            return;
        }
    }
    journeys[id].changeJourneyStatus(2);
}