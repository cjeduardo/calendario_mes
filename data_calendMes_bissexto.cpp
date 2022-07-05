#include <iostream>
using namespace std;

struct Data {
    int dia;
    int mes;
    int ano;
};

int diaDaSemana(Data data){
    int semana;

    if(data.mes == 1 || data.mes == 2) { // Janeiro ou fevereiro serao os mese 13 ou 14 do ano anterior
        data.mes += 12;
        data.ano -= 1;
    }
    
    semana = data.dia + 2*data.mes + (3*(data.mes+1)/5) + data.ano + data.ano/4 - data.ano/100 + data.ano/400 + 2;
    // Dia da semana: 0 - sabado, 1 - domingo, 2 - segunda, 3 - terca, 4 - quarta, 5 - quinta, 6 - sexta
    return (semana % 7);
}

void imprimeDiaSemana(Data data){
    int semana = diaDaSemana(data)-1;
    if (semana == -1) semana = 6;

    switch(semana)
    { 
        case 0://Domingo
            cout << "A data " << data.dia << "-" << data.mes << "-" << data.ano << " calha num Domingo\n\n";   
        break;  
        case 1://segunda-feira
            cout << "A data " << data.dia << "-" << data.mes << "-" << data.ano << " calha numa Segunda-feira\n"; 
        break; 
        case 2://terça-feira
            cout << "A data " << data.dia << "-" << data.mes << "-" << data.ano << " calha numa Terca-feira\n"; 
        break;
        case 3://quarta-feira
            cout << "A data " << data.dia << "-" << data.mes << "-" << data.ano << " calha numa Quarta-feira\n"; 
        break; 
        case 4://quinta-feira
            cout << "A data " << data.dia << "-" << data.mes << "-" << data.ano << " calha numa Quinta-feira\n"; 
        break;  
        case 5://Sexta-feira
            cout << "A data " << data.dia << "-" << data.mes << "-" << data.ano << " calha numa Sexta-feira\n"; 
        break;
        case 6://Sábado.
            cout << "A data " << data.dia << "-" << data.mes << "-" << data.ano << " calha num Sabado\n\n"; 
        break;          
    }
}

void imprimirCalend(Data data, int diasMes){
    // Dia da semana: 0 - sabado, 1 - domingo, 2 - segunda, 3 - terca, 4 - quarta, 5 - quinta, 6 - sexta
    // Dia na Matriz 0 - domingo, 1 - segunda, 2 - terca, 3 - quarta, 4 - quinta, 5 - sexta, 6 - sabado
    int auxdia = data.dia;
    data.dia = 1;
    int diaDaSemanaPrimeiroDia = diaDaSemana(data)-1; // Pega o primeiro dia da semana
    data.dia = auxdia;
    if(diaDaSemanaPrimeiroDia == -1)// Acerto
        diaDaSemanaPrimeiroDia = 6;

    cout << "\n------------- Calendario, Mes: " << data.mes << " de " << data.ano << " ---------------\n" << endl;
    cout << "Dom\tSeg\tTer\tQua\tQui\tSex\tSab\n";
    int dia = 1;

    for(int d = 0; d < 6; d++){
        for(int ds = 0; ds < 7; ds++){
            if(d == 0 && ds < diaDaSemanaPrimeiroDia){
                cout << "   \t";
            }else{
                if( data.dia == dia)
                cout << "|" << dia << "|\t";
                else
                    cout << dia << " \t";

                if(dia == diasMes){
                    d = 7; // Para terminar o ciclo, pois os dias já terminaram
                    break;
                }
                dia++;
            }
            
        }
        cout << "\n";
    }

    cout << "--------------------------------------------------------\n" << endl;
}

int main(int argc, char **argv){
    Data data;
    bool bissexto = true;
    
    int mesDias[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    //int calend[6][7] = {0};

    cout << "Digite o dia: "; cin >> data.dia;
	cout << "Digite o mes: "; cin >> data.mes;
	cout << "Digite o ano: "; cin >> data.ano;
    cout << "\n";
    //cin >> data.dia >> data.mes >> data.ano;


    if( data.ano % 4 == 0 ) {
        if(data.ano % 100 == 0 ) {
            if( data.ano % 400 != 0 ) {
                bissexto = false;
            }
        }
    }else 
        bissexto = false;

    if( bissexto ){
        mesDias[1] = 29;
    }
    // Verificando se a data Existe no calendário
    if( (data.mes <= 12 && data.mes >= 1) && (data.dia > mesDias[data.mes-1] || data.dia < 1) )
    {
        cout << "A data " << data.dia << "-" << data.mes << "-" << data.ano << " nao existe no calendario Gregoriano. \n";
        exit(1);
    }

    imprimirCalend(data, mesDias[data.mes-1]);
    imprimeDiaSemana(data);

    cout << data.ano << (bissexto ? " - eh " : " - nao eh") << " Bissexto\n\n" << endl;

    getchar();
    return 0;
}
