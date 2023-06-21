#pragma once
#include "Jogo.h"
#include "Usuario.h"
#include "Conta.h"
#include <fstream>
#include <algorithm>
#include <string>
#include <vector>
#include <regex>

using namespace std;

class App {
private:
    vector<Jogo> jogos;
    vector<Usuario> usuarios;
    string auxNome, auxEmail, auxSenha, auxId;
    double auxSaldo = 0;
    double auxValor = 0;
    int contador = 0, tamanhoId = 0, op = 0;
    Usuario usuarioAtivo;
public:
    App() {};

    // Validação de jogos já cadastrados

    bool jogoJaCadastrado(string auxiliar) {
        for (int i = 0; i < jogos.size(); i++) {
            if (jogos[i].getTituloJogo() == auxiliar) {
                return true;
            }
        }

    }
    
    // Validação do usuario já cadastrado

    bool usuarioJaCadastrado(string auxiliar) {

        for (int i = 0; i < usuarios.size(); i++) {
            if (usuarios[i].getEmail() == auxiliar) {
                return true;
            }
            else {
                if (usuarios[i].getId() == auxiliar) {
                    return true;
                }
            }
        }

    };

    // Busca caracteres

    bool encontraCaractere(string variavel) {
        regex caracteres("^[a-z]+$");
        return regex_match(variavel, caracteres);
    }

    // Busca numeros

    bool encontraNumeros(string variavel) {
        regex caracteres("^[0-9]+$");
        return regex_match(variavel, caracteres);
    }

    // MENUS DO PROGRAMA

    int menuCadastro() {
        cout << endl << "[1] -> Registrar";
        cout << endl << "[2] -> Login";
        cout << endl << "[3] -> Entrar sem login";
        cout << endl << "[4] -> Sair da aplicacao";

        cout << endl << endl << "Informe a opcao desejada: ";
        cin >> op;
        while (op > 4 || op <= 0) {
            cout << "-> Informe uma opcao validade: ";
            cin >> op;
        }

        return op;
    }
    int menuEmpresa() {
        cout << endl << "[1] -> Cadastrar novo jogo";
        cout << endl << "[2] -> Lista de jogos";
        cout << endl << "[3] -> Voltar para o login";

        cout << endl << endl << "Informe a opcao desejada: ";
        cin >> op;
        while (op > 3 || op <= 0) {
            cout << "-> Informe uma opcao validade: ";
            cin >> op;
        }
        return op;
    }
    int menuUsuario() {
        cout << endl << "[1] -> Lista de jogos;";
        cout << endl << "[2] -> Comprar jogo;";
        cout << endl << "[3] -> Adicionar saldo a carteira;";
        cout << endl << "[4] -> Mostrar meu saldo";
        cout << endl << "[5] -> Voltar para o login";


        cout << endl << endl << "Informe a opcao desejada: ";
        cin >> op;
        while (op > 5 || op <= 0) {
            cout << "-> Informe uma opcao validade: ";
            cin >> op;
        }
        return op;
    }
    int menuNaoCadastrado() {
        cout << endl << "[1] -> Lista de jogos";
        cout << endl << "[2] -> Voltar para o login";

        cout << endl << endl << "Informe a opcao desejada: ";
        cin >> op;
        while (op > 2 || op <= 0) {
            cout << "-> Informe uma opcao validade: ";
            cin >> op;
        }
        return op;

    }

    // INICIO DA APLICACAO

    void Inicio() {
        cout << "APERTE QUALQUER TECLA PARA INICIAR O PROGRAMA.. " << endl;
        cin.get();
        cout << endl << "INICIADO." << endl << endl;
        
    }

    // CADASTRAMENTO DE USUARIOS
    int Cadastro() {
        string email, senha;
        int auxEscolha = menuCadastro();

        while (auxEscolha <= 3) {
            switch (auxEscolha) {

                case 1: {
                    cout << endl << "<- REGISTRO ->" << endl;

                    cout << endl << "Nome -> ";
                    cin.ignore();
                    getline(cin, auxNome);
                    while (encontraNumeros(auxNome) == true) { // Reconhece numeros no nome, e não permite.
                        cout << "! Digite apenas letras ->  ";
                        getline(cin, auxNome);
                    }

                    cout << endl << "CPF / CNPJ -> ";
                    cin >> auxId;
                    while (auxId.size() != 11 && auxId.size() != 14 || encontraCaractere(auxId) == true) { // Não deixa o usuário colocar letras e nem numeros diferentes de 11 e 14.
                        cout << "! Digite 11 numeros para CPF ou 14 numeros para CNPJ, e nao coloque letras -> ";
                        cin >> auxId;
                    }
                    while (usuarioJaCadastrado(auxId) == true) { // Procura se a ID já nao foi cadastrada.
                        cout << "! Informe uma identidade que ainda nao foi cadastrado -> ";
                        cin >> auxId;
                        while (auxId.size() != 11 && auxId.size() != 14 || encontraCaractere(auxId) == true) { // Não deixa o usuário colocar letras e nem numeros diferentes de 11 e 14.
                            cout << "! Digite 11 numeros para CPF ou 14 numeros para CNPJ, e nao coloque letras -> ";
                            cin >> auxId;
                        }
                    }

                    cout << endl << "Email -> ";
                    cin >> auxEmail;
                    while (usuarioJaCadastrado(auxEmail) == true) { // Procura se o email já nao foi cadastrado.
                        cout << "! Informe um email que ainda nao foi cadastrado -> ";
                        cin >> auxEmail;
                    }


                    cout << endl << "Senha-> ";
                    cin >> auxSenha;
                    auxValor = 0;

                    Usuario usuario(auxNome, auxId, auxEmail, auxSenha, auxSaldo);

                    usuarios.push_back(usuario);



                }
                break;

                case 2: {
                    cout << endl << "-> Informe o seu email: ";
                    cin >> email;

                    cout << endl << "-> Informe a sua senha: ";
                    cin >> senha;

                    for (int i = 0; i < usuarios.size(); i++) {     // Percorre o vector usuarios.
                        if (usuarios[i].getEmail() == email && usuarios[i].getSenha() == senha) {   // Autenticação do usuario

                            cout << endl << "-> Seja bem vindo " << usuarios[i].getNome() << " ! " << endl;

                            tamanhoId = usuarios[i].getId().size(); // Descobre o tamanho do ID, e chama o menu correto.
                            usuarioAtivo = usuarios[i];

                            contador = 1; // Valida que o usuario esta cadastrado
                            return Run();
                        }
                    }
                    cout << endl << "-> Email ou senha incorreta" << endl;
                }
                break;

                case 3:
                    contador = 3;   // Valida que o usuario não esta cadastrado
                    return Run();
                break;
            }
            
            auxEscolha = menuCadastro();
        }

        return 0;
    }

    // INICIALIZAÇÂO DO PROGRAMA

    int Run() {
        int auxAno = 0;
        int auxEscolha;
        double auxValor = 0;
        string auxCompra;
        string auxTitulo, auxTipo;

        if (tamanhoId == 14 && contador == 1) {   // Chama o menu empresa, pois valida o tamanhoId e o contador.
            auxEscolha = menuEmpresa();
            while (auxEscolha <= 3) {
                switch (auxEscolha) {

                    case 1: {

                        if (contador == 1 && tamanhoId == 14) {   // CADASTRO DO JOGO
                            {
                                cout << endl << "Titulo-> ";
                                cin.ignore();
                                getline(cin, auxTitulo);
                                while (jogoJaCadastrado(auxTitulo) == true) { // Procura se a ID já nao foi cadastrada.
                                    cout << "! Informe um jogo que ainda nao foi cadastrado -> ";
                                    getline(cin, auxTitulo);
                                }

                                cout << endl << "Ano de lancamento-> ";
                                cin >> auxAno;
                                while (auxAno < 1800 || auxAno <= 0 || auxAno > 2023) { // Não permite que seja colocado um ano igual ou menor que zero.
                                    cout << "Informe uma data correta-> ";
                                    cin >> auxAno;
                                }
                           
                                cout << endl << "Tipo-> ";
                                cin.ignore();
                                getline(cin, auxTipo);
                                while (encontraNumeros(auxTipo) == true) { // Reconhece numeros no nome, e não permite.
                                    cout << "! Digite apenas letras ->  ";
                                    getline(cin, auxTipo);

                                }

                                

                                cout << endl << "Valor-> ";
                                cin >> auxValor;
                                while (auxValor < 0) { // Não permite numeros menores que zero.
                                    cout << "Informe um valor igual ou maior do que zero-> ";
                                    cin >> auxValor;
                                }

                                Jogo jogo(auxTitulo, auxTipo, auxAno, auxValor);    // Cria um objeto JOGO

                                jogos.push_back(jogo);     // Guarda o objeto JOGO dentro de uma posição do VECTOR
                            }
                        }
                        else {
                            cout
                                << endl
                                << "-> Apenas empresas com acesso, conseguem adicionar novos jogos."
                                << endl;
                        }
                    }
                    break;

                    case 2: {
                        if (jogos.empty()) {    // Encontra o vector vazio.
                            cout << endl << "! Nenhum Jogo cadastrado !" << endl;
                        }
                        else {      // Lista todos os jogos dentro do vector.
                            cout << endl << "<- Jogos para Download ->" << endl;

                            for (int i = 0; i < jogos.size(); i++) { // Percorre todo o vector de jogos.
                                cout << endl << "TITULO -> ' " << jogos[i].getTituloJogo() << " '";
                                cout << endl << "TIPO -> ' " << jogos[i].getTipoJogo() << " '";
                                cout << endl << "ANO DE LANCAMENTO -> ' " << jogos[i].getAno() << " '";
                                cout << endl << "VALOR -> ' " << jogos[i].getValor() << "R$" << " '" << endl;
                                cout << endl << "<-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~->" << endl;
                            }
                        }
                    }
                    break;

                    case 3: { // Retorna para o menu cadastro
                        for (int i = 0; i < usuarios.size(); i++)
                        {
                            if (usuarios[i].getEmail() == usuarioAtivo.getEmail())
                            {
                                usuarios[i] = usuarioAtivo;
                            }

                        }
                        contador = 0;
                        return Cadastro();
                    }
                    break;

                }
                auxEscolha = menuEmpresa();
            }
        }

        else {      
            if (tamanhoId == 11 && contador == 1) { // Chama o menu usuario, pois valida o tamanhoId e o contador.

                auxEscolha = menuUsuario();
                while (auxEscolha <= 5) {

                    switch (auxEscolha) {

                        case 1: {
                            if (jogos.empty()) {    // Encontra o vector vazio
                                cout << endl << "! Nenhum Jogo cadastrado !" << endl;
                            }
                            else {      // Lista todos os jogos dentro do vector
                                cout << endl << "<- Jogos para Download ->" << endl;

                                for (int i = 0; i < jogos.size(); i++) {    // Percorre o vector jogos.
                                    cout << endl << "TITULO -> ' " << jogos[i].getTituloJogo() << " '";
                                    cout << endl << "TIPO -> ' " << jogos[i].getTipoJogo() << " '";
                                    cout << endl << "ANO DE LANCAMENTO -> ' " << jogos[i].getAno() << " '";
                                    cout << endl << "VALOR -> ' " << jogos[i].getValor() << "R$" << " '" << endl;
                                    cout << endl << "<-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~->" << endl;
                                }
                            }
                        }
                        break;

                        case 2: { // Compra jogo
                            if (usuarioAtivo.getSaldo() != 0) {    // VERIFICA SE O VALOR É DIFERENTE DE ZERO

                                cout << endl << "QUAL ELEMENTO VOCE DESEJA COMPRAR: ";
                                cin.ignore();
                                getline(cin, auxCompra);

                                bool encontraJogo = false;

                                for (int i = 0; i < jogos.size(); i++) { // PERCORRE O VECTOR PARA ECONTRAR O JOGO DESEJADO

                                    if (jogos[i].getTituloJogo() == auxCompra) { // VERIFICA SE O AUXCOMPRA É IGUAL A ALGUM NOME DE JOGO
                                        encontraJogo = true; // Recebe true se econtrar
                                        if (usuarioAtivo.getSaldo() >= jogos[i].getValor()) {
                                            usuarioAtivo.setSaldo(usuarioAtivo.getSaldo() - jogos[i].getValor());
                                            cout << endl << "-> JOGO ADQUIRIDO COM SUCESSO" << endl;
                                        }
                                        else {
                                            cout << endl << "-> Voce nao tem dinheiro suficiente." << endl;
                                        }
                                    }
                                }
                                if (!encontraJogo) { // Se for diferente de true, não é encontrado.
                                    cout << endl << "-> JOGO NAO ENCONTRADO" << endl;
                                }
                            }
                            else {
                                cout << endl << "-> Voce nao tem dinheiro em sua carteira." << endl;
                            }

                        
                        }
                        break;

                        case 3: { // Adiciona saldo

                            cout << endl << "-> Informe sua senha para continuar: ";
                            cin >> auxSenha;     

                            if (usuarioAtivo.getSenha() != auxSenha) { // Valida a senha do usuário, para colocar saldo.
                                cout << endl << "! Senha do usuário incorreta." << endl;
                            }
                            else {
                                cout << endl << "Qual valor a ser depositado ->";
                                cin >> auxValor;

                                while (auxValor <= 0) { // Não permite valores iguais ou menores do que 0.
                                    cout << "Valores acima de zero ->";
                                    cin >> auxValor;
                                }
                                auxSaldo = usuarioAtivo.getSaldo() + auxValor; // Soma o valor adiconado com o valor que já esta na carteira.
                                usuarioAtivo.setSaldo(auxSaldo); // Guarda o valor dentro do saldo do usuário.
                            }   
                            
                        }
                        break;

                        case 4: { // Mostra saldo atualizado.
                            cout << endl << "Saldo atualizado -> " << usuarioAtivo.getSaldo() << "R$" << endl;    
                        }
                        break;

                        case 5: { // Volta ao menu cadastro..
                            for (int i = 0; i < usuarios.size(); i++)
                            {
                                if (usuarios[i].getEmail() == usuarioAtivo.getEmail())
                                {
                                    usuarios[i] = usuarioAtivo;
                                }

                            }
                            auxSaldo = 0;
                            contador = 0;
                            return Cadastro();
                        }
                        break;
                    }
                    auxEscolha = menuUsuario();
                }

            }
            else {
                if (contador == 3) { // Validação do usuário não cadastrado.
                    auxEscolha = menuNaoCadastrado();
                    while (auxEscolha != 4) {

                        switch (auxEscolha) {

                            case 1: {
                            if (jogos.empty()) {    // ENCONTRA O VECTOR VAZIO
                                cout << endl << "! Nenhum Jogo cadastrado !" << endl;
                            }
                            else {      // LISTA TODOS OS JOGOS DENTRO DO VECTOR
                                cout << endl << "<- Jogos para Download ->" << endl;

                                for (int i = 0; i < jogos.size(); i++) { // PERCORRE TODO O VECTOR JOGOS
                                    cout << endl << "TITULO -> ' " << jogos[i].getTituloJogo() << " '";
                                    cout << endl << "TIPO -> ' " << jogos[i].getTipoJogo() << " '";
                                    cout << endl << "ANO DE LANCAMENTO -> ' " << jogos[i].getAno() << " '";
                                    cout << endl << "VALOR -> ' " << jogos[i].getValor() << "R$" << " '" << endl;
                                    cout << endl << "<-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~->" << endl;
                                }
                            }
                        }
                            break;

                            case 2: { // RETORNA PARA O MENU CADASTRO
                            for (int i = 0; i < usuarios.size(); i++)
                            {
                                if (usuarios[i].getEmail() == usuarioAtivo.getEmail())
                                {
                                    usuarios[i] = usuarioAtivo;
                                }

                            }
                            contador = 0;
                            return Cadastro();
                        }
                            break;

                        }
                        auxEscolha = menuNaoCadastrado();
                    }

                }

            }

        }

        return 0;

    }

    // FIM DA APLICACAO

    void Fim() {
        cout << endl << "FIM DO PROGRAMA..." << endl;
    }

};