#include <stdio.h>
#include <windows.h>


class Cadeado
{
private:
    int estado;//Mostra se ele se encontra desligado(estado=0) ou ligado(estado-0)
public:
    int modo;//Mostra se o cadeado est� aberto(modo=0) ou fechado(modo=1;)
    mudEstado(){estado=!estado;}//Fun��o de ligar e desligar o cadeado
    mudModo(){modo=!modo;}//Fun��o de abrir e fechar o cadeado
};

class Senha   // Classe da senha de 8 digitos formada a partir de dois digitos
{
private:
    int parte1;//� a primeira parte da senha
    int parte2;//� a segunda parte da senha
public:
    setSenha(int a,int b)  // Fun��o de definir a senha
    {
        parte1=a;parte2=b;
    }
    delSenha()  // Fun��o de deletar a senha
    {
        parte2=parte1=0;
    }
    int checkSenha(int a,int b) //Fun��o de comparar a senha digitada com a salva
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
    int a,b,Aviso=0,Confirma=0,conversor[4];// Aviso � para a ativa��o da luz ou mensagem de aviso. Confirma � para o bot�o de enter(confrmar) do cadeado, por�m esse bot�o funcionar� como enter tamb�m.
    Redef.setSenha(6,6);
    Um.mudEstado();
    Definicao:                    //O cadeado espera a defini��o da senha
        Aviso=1;                  //
        Sleep(500);               //           Regi�o de aviso
        Aviso=0;                  //        da defini��o da senha
        Sleep(500);               //
        fflush(NULL);             //
        scanf("%0bd",a);          //         Regi�o da defini��o
        fflush(NULL);             //             da senha
        scanf("%0bd",b);          //
        User.setSenha(a,b);       //
        if(User.checkSenha(a,b))  //
        {                         //
            Aviso=1;              //       Caso o valor seja salvo
            Sleep(500);           //    o cadeado ir� para a pr�xima
            Aviso=0;              //                fase
            Sleep(500);           //
            Um.mudEstado();       //
            goto Fechado;         //
        }                         //
        else                      //
        {                         //
            Aviso=1;              //
            Sleep(1000);          //           Caso contr�rio ir�
            Aviso=0;              //           piscar duas vezes e
            goto Definicao;       //     voltar para o come�o dessa fase
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
			Um.mudModo();				// O cadeado confere se as senhas s�o as mesmas
			Um.mudEstado();				//            e abre caso seja
			goto Aberto;				//
		}								//
		else
		{								//
			Aviso = 1;					// Caso contr�rio ir� piscar uma vez
			Sleep(1000);				//     e ir� esperar outra senha
			Aviso = 0;					//
			goto Stand_By;				//
		}								//

    Aberto:
        for(int i=0;i<4;i++)			//     O cadeado ir� receber uma senha
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
		{								//        Vai checar se � a senha de
			User.delSenha();			//               redefini��o.
			goto Definicao;				//       Caso seja ir� apagar a senha e
		}								//         voltar� para a defini��o.
		else							//       Caso contr�rio ir� verificar se
		{								//              � a senha salva.
			if (User.checkSenha)
			{							//       Se for ir� fechar o cadeado e
				Um.mudModo();			//           entrar� em stand by
				Um.mudEstado();
				goto Stand_By;
			}
			else
			{
				Aviso = 1;				//     Caso contr�rio ir� piscar uma vez
				Sleep(1000);			// e voltar� ao come�o do processso de Aberto.
				Aviso = 0;				//
				goto Aberto;
			}
		}
	Stand_By:
		while(!Confirma){}		//Ir� se manter desligado enquanto n�o for pressionado o bot�o confirma
		if (Um.modo)			// Depois ir� checar se o cadeado se encontra aberto ou fechado e levar para parte correspondente
		{
			goto Fechado;
		}
		else
		{
			goto Aberto;
		}

	return 0;
}
