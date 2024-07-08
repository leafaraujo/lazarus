#include <iostream>
#include "menu/menu.h"

using namespace std;

int main(){
    std::vector<Astronaut> astronauts;
    std::vector<Journey> journeys;
    int choice = 0, id = 1, idSearch = 0;
    string cpf;

    while(true){
        displayMenu();
        cout << "Selecione a opção desejada: ";
        cin >> choice;
        cout << endl;
        
        switch (choice){
            case 1:
                cout << "Digite o CPF do seu Astronauta: ";
                cin >> cpf;
                if(astronautAlreadyRegistered(cpf, astronauts)){
                    cout << "Esse CPF já está registrado!" << endl;
                }
                else{
                    cadastreAstro(cpf, astronauts);
                    cout << "O CPF foi registrado com sucesso em nosso banco de dados!";
                }
                cout << endl;
                break;
            case 2:  
                cadastreJourney(id , journeys);
                cout << "A sua viagem foi cadastrada com sucesso em nosso banco de dados!" << endl;
                cout << "O número de id é: " << id << endl;
                id ++;
                break;
            case 3:
                addAstro(journeys, astronauts);
                break;
            case 4:
                removeAstro(journeys);
                break;
            case 5:
                beginJourney(journeys);
                break;
            case 6:
                finishJourney(3, journeys);
                break;
            case 7:
                finishJourney(0, journeys);
                break;
            case 8:
                if(journeys.size() == 0){
                    cout << "Não existem viagens cadastradas em nosso sistema!";
                }
                else{
                    showJourney(journeys);
                }
                break;
            case 9:
                cout << "Digite o ID da viagem que deseja saber detalhes: ";
                cin >> idSearch;
                if(idSearch < journeys.size()){
                detailsOfJourney(idSearch - 1, journeys);
                }
                else{
                    cout << "Esse ID não está cadastrado!" << endl;
                }
                break;   
            case 10:
                cout << "Digite o CPF do astronauta que deseja buscar" << endl;
                cin >> cpf;
                if(astronautAlreadyRegistered(cpf, astronauts)){
                    idSearch = searchAstronaut(cpf, astronauts);
                    astronauts[idSearch].showAstronaut();
                    astronauts[idSearch].showId();
                }
                else{
                    cout << "O astronauta não está cadastrado em nosso banco de dados!" << endl;
                }
                break;

            case 11:
                cout << "Finalizando o seu programa" << endl;
                cout << "A única forma dos homens chegarem a algum lugar é deixando algo para trás." << endl;
                false;
                break;
            default:
                cout <<"Essa opção não existe! Por favor, digite uma opção válida." << endl;
                break;
        }
    }
    astronauts.clear();
    journeys.clear();
    return 0;
}