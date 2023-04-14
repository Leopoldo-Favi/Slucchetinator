#include <iostream>
#include <string>
#include <string.h>
#include <fstream>
#include <sstream>
#include <vector>


using namespace std;



int main(int argc, char** argv) {
	
	//C:\Users\Leopoldo\Desktop\numeri
	
	int manopole;
	cout << "inserisce numero di manopole";                
	cin >> manopole;
	
    ifstream in("numeri.txt");
    
    ofstream file("out.txt");
    
    string line;
    
    vector<int> var;
    vector<int> possoCambiareB;
    vector<int> possoCambiare;
    int qualeCambiare = manopole-1;
    vector<vector<string>> insiemone;
    vector<string> combinazioni;
    
    //modalità debug
    bool debMode = false;
    if (manopole == 9999)
	{
		debMode = true;
	}
    
    //definisci le variabili
    if (!debMode){
	
    for(int i=0;i<manopole;i++)  //leggi il file numeri  e salva le informazioni in insiemone   per 4 manopole con 10 valori ciascuna scrivi un file cosi  0 1 2 3 4 5 6 7 8 9
    {         																															//                 0 1 2 3 4 5 6 7 8 9		
    	getline(in,line);																												//     			   0 1 2 3 4 5 6 7 8 9					
    																																	//     			   0 1 2 3 4 5 6 7 8 9				
    	vector<string> listaValoriManopole; //lista di cose che devono cambiare di posto (possono essere cifre, numeri, stringhe che hanno bisogno di uno shuffle)
    	int quantiValori=0;
    	
    	for(int j=0;j<line.length();j++)
		{
			char c=line.at(j);
			
			
			string s;             //converti char c in string s
			s.push_back(c);
			
			if(j==0)
			{
				listaValoriManopole.push_back(s);  //inizializza
			}
			else if(c==' ')
			{
				j++;
				
				c=line.at(j);
				string s;
			    s.push_back(c);
			    
				listaValoriManopole.push_back(s);  //nuova variabile dell'array
				quantiValori++;
			}
			else
			{
				listaValoriManopole[quantiValori]=listaValoriManopole[quantiValori] + s;
			}
			
			cout << "  " << listaValoriManopole[quantiValori] << "   ";
		}
		
		insiemone.push_back(listaValoriManopole);	
	}
	
	int Ncombinazioni = 1; 
	
	for(int i=0;i<manopole;i++) //calcola il numero di combinazioni
	{
		Ncombinazioni *= insiemone[i].size();
	}
	
	for(int i=0;i<manopole;i++) //definisci "var"
    {
	    var.push_back(0);
    }
	
	
	int x = Ncombinazioni;   //definisci "possoCambiare"
	for(int i=0;i<manopole;i++) 
	{
		x /= insiemone[i].size();
		possoCambiareB.push_back(x-1);
	}
	
	possoCambiare = possoCambiareB;
	
	
	
	
	
	
	//scrivi le combinazioni
	
	for(int i=0;i<Ncombinazioni;i++)  
	{
		qualeCambiare = manopole-1;   //resetta
		
		combinazioni.push_back("0"); //inizializza lo slot di vector<string> combinazioni
		
		for(int j=0;j<manopole;j++) //scrivi 
		{
			//debug 
			stringstream ss1;
			ss1 << var[j];
			string num1 = ss1.str();
			cout << num1;
			
			if(j == 0)
			{
				combinazioni[i] = insiemone[j][var[j]]; //cambia lo slot che serve solo da placeholder
			}
			else
			{
				combinazioni[i] = combinazioni[i] + insiemone[j][var[j]]; //aggiungi i caratteri dopo il primo
			}
			
			
		}
		
		bool doppione = false;
		
		if( i != 0 ) //il primo non può essere uguale a qualcosa
		{
			// i = combinazioni.size()-1
			for(int j=0;j<i;j++) //controlla che non sia uguale a qualcosa di precendente 
		    {		    	
			    if(combinazioni[i] == combinazioni[i-1-j])
				{
					doppione = true;
				}
		    }
		}
		
		
		
		//magheggi per far tornare i conti
		
		
		for(int j=0;j<manopole;j++)
		{
			//debug 
 			
			
			stringstream ss2;
			ss2 << possoCambiare[manopole-1-j];
			string num2 = ss2.str();
			cout << " |" << num2 << "| ";
			
			if(var[qualeCambiare-j] >= insiemone[qualeCambiare-j].size()-1)
			{
				
				if(possoCambiare[qualeCambiare-j] > 0)  //abbassa posso cambiare
				{
					possoCambiare[qualeCambiare-j]-=1;
				}
				
				
				else if(possoCambiare[qualeCambiare-j]==0)
				{
					var[qualeCambiare-j] = 0; 
					possoCambiare[qualeCambiare-j] = possoCambiareB[qualeCambiare-j]; //resetta possoCambiare 
					
					/*
					bool nonCiSonoAltriMassimi = false;
					for(int k=0; k<manopole-j; k++)
					{
						if(var[qualeCambiare-j-k] < insiemone[qualeCambiare-j-1].size()-1)
						{
							nonCiSonoAltriMassimi = true;
							break;
						}
					}
					
					if(nonCiSonoAltriMassimi) //se devono cambiare più di uno lo fa solo l'ultimo
					{
						qualeCambiare -= (1+j);
					}
					*/
					
					
					if(var[qualeCambiare-j-1] < insiemone[qualeCambiare-j-1].size()-1) //se devono cambiare più di uno lo fa solo l'ultimo
					{
	
						qualeCambiare -= (1+j);

					}
					
				}
				
			}
			
		}
		
		var[qualeCambiare]+=1;
		
		
		
		cout << "   | " << combinazioni[i] << " | ";
		file << combinazioni[i] << endl;
		
		if(!doppione){ cout << "          il programma sta funzionando" ;}
		else if (doppione){ cout << "NINONINO STACCA STACCA"; break;}
		
		cout << "     " << i << "     " << endl; 	
		
		
		if(i == 10100)
		{	
			cout << "FERMI TUTTI" << endl;
			break;
		}
	}
	
	file.close();
	
	cout << "immetti posizione (da 0) e numero che vuoi controllare" << endl;
	int pos; //posizione del numero 	
	char num; //numero 
	cin >> pos;
	cin >> num;
	
	
	//visualizza solo le combinazioni con un numero in una posizione
	
	for(int i=0; i<Ncombinazioni; i++)
	{
		if(combinazioni[i].at(pos) == num)
		{
			cout << combinazioni[i] << endl;
		}
	}
	
}  
	
	else if (debMode)
	{
		for(int i=0; i<var.size(); i++)
		{
			cout << to_string(var[i]) << endl;
		}
	}
	
	return 0;
}
