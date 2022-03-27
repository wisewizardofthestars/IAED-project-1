#include <ctype.h>
#include <stdio.h> /* output, input functions*/
#include <stdlib.h>
#include <string.h>

#include "structs.h" /* structs and define*/

aero aeros[AERO_M];
int nr_aero,nr_voos;
voo voos[MAX_VOO];
data data_h;




/*command 'v' adiciona ou lista todos os voos*/

int v_oo(){
	char id[MAX_ID], id_og[ID_M], id_new[ID_M];
	int pass, mark_og, mark_new,ch,c,len;
	hora hora_og, duracao;
	data data_og;
	mark_og = 0;
	mark_new = 0;

	ch = getchar();

	/* to creat a flight*/

	if(ch != '\n'){

		/* too many flights error*/

		if(nr_voos >= 	MAX_VOO){
			printf(ERR_V4);
			return 0;
		}

		scanf("%s%s%s", id, id_og, id_new);
		scanf("%d-%d-%d",&data_og.dia, &data_og.mes,&data_og.ano);
		scanf("%d:%d",&hora_og.horas,&hora_og.min);
		scanf("%d:%d", &duracao.horas,&duracao.min);
		scanf("%d",&pass);
		


		/* error capcity pass nr*/
		if((pass > MAX_PASS) || (pass < MIN_PASS)){
			printf(ERR_V7);
			return 0;
		}

		/*duration error*/
		if(duracao.horas > MAX_DUR){
			printf(ERR_V6);
			return 0;
		}

		if((duracao.horas == MAX_DUR) && (duracao.min)){
			printf(ERR_V6);
			return 0;
		}

		/* data error handler*/
		if((data_og.ano < data_h.ano)){
			printf(ERR_V5);
			printf("here1");
			return 0;
		}
		else if(data_og.ano == data_h.ano){
			if(data_og.mes < data_h.mes){
				printf(ERR_V5);
				printf("here2");
				return 0;
			}
			else if(data_og.mes == data_h.mes){
				if(data_og.dia < data_h.dia){
					printf(ERR_V5);
					printf("here3");
					return 0;
				}
			}
		}
		else if(data_og.ano > data_h.ano){
			if(data_og.mes > data_h.mes){
				printf(ERR_V5);
				printf("here4");
				return 0;
			}
			else if(data_og.mes == data_h.mes){
				if (data_og.dia > data_h.dia){
					printf(ERR_V5);
					printf("here5");
					return 0;
				}
			}
		}

		
		/*id error*/
		len = strlen(id);
		/* to chekc for lower letter*/
		for (c = 0; c <= 1; c++) {
			if islower (id[c]) {
				printf(ERR_V1);
				printf("herrrre1");
				return 0;
			}
		}

		/* to see if it has the right nr of char*/
		if ((len < 3) || (len > 6)){
			printf("herereee2");
			printf(ERR_V1);
			return 0;
		}
		/* to check if the last char are digits*/
		for(c = 2; c < len;c++){
			if((id[c] < '0') || (id[c] > '9')){
				printf(ERR_V1);
				return 0;
			}
		}


		/* 3errors and putting in the list*/
		/* NEEDED ABSTRAÇÃO SHIT, its so fucking ugly dis code*/
		for(c = 0; c < nr_voos; c++){
			if((voos[c].id == id) && (data_og.ano == \
			voos[c].data_og.ano) && (data_og.mes == \
			voos[c].data_og.mes) && (data_og.dia ==\
			voos[c].data_og.dia)){
				printf(ERR_V2);
				return 0;
			}
		}

		for(c = 0; c < nr_aero; c++){
			if(!strcmp(aeros[c].id, id_og)){
				mark_og ++;
			}
			if(strcmp(aeros[c].id, id_new)) {
				mark_new++;
			}
		}

		if((!mark_og) || (!mark_new)){
			if(!mark_og){
				printf("%s%s", id_og,ERR_V3);
			}
			if(!mark_new){
				printf("%s%s", id_new, ERR_V3);
			}
			return 0;
		}

		/* to creat the filghts*/
		strcpy(voos[nr_voos].id, id);
		strcpy(voos[nr_voos].id_new, id_new);
		strcpy(voos[nr_voos].id_og, id_og);
		voos[nr_voos].pass = pass;

		voos[nr_voos].data_og.dia = data_og.dia;
		voos[nr_voos].data_og.mes = data_og.mes;
		voos[nr_voos].data_og.ano = data_og.ano;

		voos[nr_voos].hora_og.horas = hora_og.horas;
		voos[nr_voos].hora_og.min = hora_og.min;

		voos[nr_voos].duracao.horas = duracao.horas;
		voos[nr_voos].duracao.min = duracao.min;
	
		nr_voos++;
	}
	else if (nr_voos > 0){
		for(c = 0; c < nr_voos; c++){
			printf("%s %s %s ",voos[c].id, \
			voos[c].id_og, voos[c].id_new);
			printf("%d-%d-%d ",voos[c].data_og.dia,\
			voos[c].data_og.mes,voos[c].data_og.ano);
			printf("%d:%d\n",voos[c].hora_og.horas,\
			voos[c].hora_og.min);
		}
	}
	return 1;		
}





/*'a' command: adicionar um novo aeroporto ao sistema*/
/* kinda done ig falta so passar os parametros para dentro
da função thats a mistery for me*/

/*'l' command: listar os aeroportos*/
int l_istar() {
    char id_aero[ID_M];
    int mark, c, ch,i,cont;
    mark = 0;
	cont = 0;
    /* the mark marks if theres something after the 
    'l' command, ou seja se entra no loop,
    nest caso também vai marcar se o id é valido*/
	ch = getchar();

/*
	scanf("%s",id_aero);
	printf("passes the scan\n");
	*/

    while(ch != '\n'){
		scanf("%s",id_aero);
        for(c = 0; c <= nr_aero; c++){
            if (!strcmp(aeros[c].id,id_aero)){
				for(i = 0; i < nr_voos; i++){
					if (!strcmp(voos[i].id,id_aero)){
						cont ++;
					}
				}
                printf("%s %s", aeros[c].id, aeros[c].cidade);
                printf(" %s %d\n", aeros[c].pais, cont );
                /* falta o nr de voos-STRUCT*/
				/* FAZER EM A um alogritmo de ordenação à 
				medida que se adiconam aeroportos*/
                mark = 1;
				/* whens a specifi airport it works, kinda*/
                break;

            }
		
        }
		if(!mark){
			printf(ERR_L1);
			return 0;
		}
		ch = getchar();
    }
	/* quando não há nada depois do l, ou sea«ja listar todos os airp*/
    if((!mark) && (nr_aero > 0)){
        for(c = 0; c <= nr_aero - 1; c++){
            printf("%s %s ", aeros[c].id, aeros[c].cidade);
            printf("%s %d\n", aeros[c].pais, cont);
			/* falta o nr de voos*/
        }
    }
	return 1;
}

int a_dicionar() {
	char id[ID_M], pais[PAIS_M], cidade[CIDADE_M];
	/* declarar uma string de ids, cidade e pais*/

	int c,i, mark;
	mark = 0;

	scanf("%s %s", id, pais);

	fgets(cidade, CIDADE_M, stdin);

	/* erros handler*/
	for (c = 0; c <= 2; c++) {
		if islower (id[c]) {
			printf(ERR_A2);
			return 0;
		}
	}

	/* too many aerports handler*/
	if (nr_aero >= AERO_M) {
		printf(ERR_A3);
		return 0;
	}

	else {
		for (c = 0; c < nr_aero; c++) {
			if (!strcmp(aeros[c].id,id)) {
				printf(ERR_A1);
				return 0;
			}
		}
		/* se o vetor ainda não tem outros aeros*/
		if(!nr_aero){
		strcpy(aeros[nr_aero].id, id);
		strcpy(aeros[nr_aero].pais, pais);
		strcpy(aeros[nr_aero].cidade, cidade);
		}
		/* caso tenha outros comparar para ficar já ordenado*/
		else{
			for(c = nr_aero-1; c >= 0; c--){
				for(i = 0; i <= 2; i++){
					if(id[i] < aeros[c].id[i]){
						strcpy(aeros[c + 1].id, aeros[c].id);
						strcpy(aeros[c + 1].pais, aeros[c].pais);
						strcpy(aeros[c + 1].cidade, aeros[c].cidade);
						

						strcpy(aeros[c].id, id);
						strcpy(aeros[c].pais, pais);
						strcpy(aeros[c].cidade, cidade);
						mark = 1;
						break;
					}
				}
			}
			if(!mark){
				strcpy(aeros[nr_aero].id, id);
				strcpy(aeros[nr_aero].pais, pais);
				strcpy(aeros[nr_aero].cidade, cidade);
			}
		}

		nr_aero++;
	}

	/* new_aero = (aero) {.id = "ALL", .pais = "III", .cidade = "AAA" };*/
	printf("airport %s\n", id);
	return 1;
	/*output id do aeroporto*/
}

int commands() {
	char com;
	com = getchar();
	switch (com) {
		case 'a':
			a_dicionar();
			return 1;
			
		case 'l':
			l_istar();
			return 1;
            
		case 'v':
			v_oo();
			return 1;
			/*
		case 'p':
			handle_users_command(something);
			return 1;
		case 'c':
			handle_move_command(something);
			return 1;
		case 't':
			handle_list_by_activities_command(something);
			return 1; */
		case 'q':
			/* stops the program */
			return 0;
		default:
			/* ignore unknown commands */
			return 1;
	}
}

int main() {
	int mark;
	nr_aero = 0;
	nr_voos = 0;
	mark = 1;
	data_h.dia = 1;
	data_h.mes = 1;
	data_h.ano = 2022;

	while (mark) {
		mark = commands();
	}
	return 0;
}