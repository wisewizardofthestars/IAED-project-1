#define ID_M 4 /*para ids de airports and ids de voos*/
#define PAIS_M 31
#define CIDADE_M 51
#define AERO_M 40
/*for a; airport stuff*/
/*errors*/
#define ERR_A1 "duplicate airport\n"
#define ERR_A2 "invalid airport ID\n"
#define ERR_A3 "too many airports\n"
#define ERR_L1 "no such airport ID\n"
#define ERR_V1 "invalid flight\n"
#define ERR_V2 "flight already exists\n"
#define ERR_V3 ": no such airport ID\n" /*por id do airp bf*/
#define ERR_V4 "too many flights\n"
#define ERR_V5 "invalid date\n"
#define ERR_V6 "invalid duration\n"
#define ERR_V7 "invalid capacity\n"

/* for v; voos stuff*/
#define MAX_PASS 100
#define MIN_PASS 10
#define MAX_ID 7
#define MAX_DUR 12
#define MAX_VOO 30000

/*to define a classe thats the aeroports*/

typedef struct {
	char id[ID_M];
	char pais[PAIS_M];
	char cidade[CIDADE_M];
} aero;

typedef struct {
	int horas;
	int min;
} hora;


typedef struct {
	int dia;
	int mes;
	int ano;
} data;

/*%02f para mostrar o 0 quando mneor que 10*/

typedef struct {
	char id[ID_M];
	/* id do voo 2 letras seguidos maiusculas de 9999 nrs*/
	char id_og[ID_M];
	/* id do aeroporto de partida */
	char id_new[ID_M];
	/* aeroporto de chegada */
	hora hora_og;
	/* hora de partida*/
	data data_og;
	/* data de partida; voos com o mesmo codigo tem de ser em dias diferentes*/
	hora duracao;
	/* duração do voo*/
	int pass;
	/* nr de passageiros */
} voo;
