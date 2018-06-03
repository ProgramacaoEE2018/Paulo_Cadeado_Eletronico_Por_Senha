#include <stdio.h>
#include <windows.h>


class Cadeado
{
private:
    int estado;//Mostra se ele se encontra desligado(estado=0) ou ligado(estado-0)
public:
    int modo;//Mostra se o cadeado está aberto(modo=0) ou fechado(modo=1;)
    mudEstado(){estado=!estado;}//Função de ligar e desligar o cadeado
    mudModo(){modo=!modo;}//Função de abrir e fechar o cadeado
};

class Senha   // Classe da senha de 8 digitos formada a partir de dois digitos
{
private:
    int parte1;//É a primeira parte da senha
    int parte2;//É a segunda parte da senha
public:
    setSenha(int a,int b)  // Função de definir a senha
    {
        parte1=a;parte2=b;
    }
    delSenha()  // Função de deletar a senha
    {
        parte2=parte1=0;
    }
    int checkSenha(int a,int b) //Função de comparar a senha digitada com a salva
    {
        if(a==parte1&&b==parte2) return 1;
        else return 0;
    }
};

int convBinDec(int a[4])
{
    int k=0;
    for(int i=0;i<4;i++)
        k=k+a[i]*(2^i);
    return k;
}

int main()
{
    Senha Redef,User;
    Cadeado Um;
    int a,b,Aviso=0,Confirma=0,conversor[4];// Aviso é para a ativação da luz ou mensagem de aviso. Confirma é para o botão de enter(confrmar) do cadeado, porém esse botào funcionará como enter também.
    Redef.setSenha(6,6);
    Um.mudEstado();
    Definicao:                    //O cadeado espera a definição da senha
        Aviso=1;                  //
        Sleep(500);               //           Região de aviso
        Aviso=0;                  //        da definição da senha
        Sleep(500);               //
        fflush(NULL);             //
        scanf("%0bd",a);          //         Região da definição
        fflush(NULL);             //             da senha
        scanf("%0bd",b);          //
        User.setSenha(a,b);       //
        if(User.checkSenha(a,b))  //
        {                         //
            Aviso=1;              //       Caso o valor seja salvo
            Sleep(500);           //    o cadeado irá para a próxima
            Aviso=0;              //                fase
            Sleep(500);           //
            Um.mudEstado();       //
            goto Fechado;         //
        }                         //
        else                      //
        {                         //
            Aviso=1;              //
            Sleep(1000);          //           Caso contrário irá
            Aviso=0;              //           piscar duas vezes e
            goto Definicao;       //     voltar para o começo dessa fase
        }                         //
    Fechado:
        for(int i=0;i<4;i++)            //     O cadeado recebe uma
        {								//            senha
            fflush(NULL);				//
            scanf("%i",conversor[i]);   //
        }								//
        a=convBinDec(conversor[4]);		//
        for(int i=0;i<4;i++)			//
        {								//
            fflush(NULL);				//
            scanf("%i",conversor[i]);	//
        }								//
        b=convBinDec(conversor[4]);		//
		if (User.checkSenha(a, b))
		{
			Um.mudModo();				// O cadeado confere se as senhas são as mesmas
			Um.mudEstado();				//            e abre caso seja
			goto Aberto;				//
		}								//
		else
		{								//
			Aviso = 1;					// Caso contrário irá piscar uma vez
			Sleep(1000);				//     e irá esperar outra senha
			Aviso = 0;					//
			goto Stand_By;				//
		}								//

    Aberto:
        for(int i=0;i<4;i++)			//     O cadeado irá receber uma senha
        {								//
            fflush(NULL);				//
            scanf("%i",conversor[i]);	//
        }								//
        a=convBinDec(conversor[4]);		//
        for(int i=0;i<4;i++)			//
        {								//
            fflush(NULL);				//
            scanf("%i",conversor[i]);	//
        }								//
        b=convBinDec(conversor[4]);		//
		if (Redef.checkSenha(a, b))		//
		{								//        Vai checar se é a senha de
			User.delSenha();			//               redefinição.
			goto Definicao;				//       Caso seja irá apagar a senha e
		}								//         voltará para a definição.
		else							//       Caso contrário irá verificar se
		{								//              é a senha salva.
			if (User.checkSenha)
			{							//       Se for irá fechar o cadeado e
				Um.mudModo();			//           entrará em stand by
				Um.mudEstado();
				goto Stand_By;
			}
			else
			{
				Aviso = 1;				//     Caso contrário irá piscar uma vez
				Sleep(1000);			// e voltará ao começo do processso de Aberto.
				Aviso = 0;				//
				goto Aberto;
			}
		}
	Stand_By:
		while(!Confirma){}		//Irá se manter desligado enquanto não for pressionado o botão confirma
		if (Um.modo)			// Depois irá checar se o cadeado se encontra aberto ou fechado e levar para parte correspondente
		{
			goto Fechado;
		}
		else
		{
			goto Aberto;
		}

	return 0;
}
