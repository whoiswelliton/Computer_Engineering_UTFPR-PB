/*
 * Arquivo:C:\Users\WELLITON LEAL\Desktop\chained.c
 * Código Gerado para a familia MSP430Gxx com saída Mealy
 * Foi utilizado listas encadeadas como jogador de autômato
 * Desenvolvido por César Rafael Claure Torrico
 */
#include "msp430.h"

//Dados do autômato (Não pode ser declarado dentro da função main por ser const)
#define NTRANS 1044	//Número de Transições
#define NESTADOS 309	//Número de Estados
#define BUFFER 10  	//Máximo Número de Eventos no Buffer
const unsigned int event[NTRANS]={19,34,22,20,24,34,22,21,20,24,34,22,20,30,1,34,22,23,20,30,34,22,2,7,34,22,25,4,3,8,13,3,4,19,9,10,34,22,4,20,24,10,19,9,34,22,4,20,24,34,22,
		20,24,34,22,4,20,30,34,22,10,20,24,34,22,20,24,34,22,23,4,20,30,34,22,20,30,34,22,4,34,22,21,10,20,24,34,22,20,24,34,22,10,20,30,34,22,23,20,30,4,7,
		34,22,25,4,34,22,1,10,34,22,21,20,24,34,22,10,20,30,34,22,20,30,34,22,10,7,34,22,25,4,8,13,4,2,10,1,34,22,20,30,34,22,25,10,34,22,8,13,4,9,10,
		4,4,3,10,2,34,22,25,13,10,9,10,4,10,19,4,9,3,10,4,3,13,10,10,19,9,34,22,4,10,20,24,3,4,19,14,19,34,22,10,20,24,34,22,4,10,20,24,34,22,4,
		20,24,34,22,4,10,20,30,19,15,34,22,10,20,24,34,22,20,24,34,22,10,20,30,34,22,4,20,24,34,22,4,10,20,30,34,22,4,20,30,34,22,4,10,19,34,22,20,24,34,22,
		10,20,30,34,22,20,30,34,22,10,34,22,4,20,30,34,22,25,4,10,34,22,4,34,22,20,24,34,22,20,30,34,22,25,10,34,22,34,22,25,4,13,4,10,16,19,34,22,21,20,24,
		34,22,20,30,34,22,25,13,10,13,4,4,10,34,22,16,20,24,1,34,22,20,30,34,22,13,10,14,4,34,22,21,16,20,24,34,22,20,24,34,22,16,20,30,2,34,22,14,15,4,16,
		1,34,22,21,20,24,34,22,23,16,20,30,34,22,20,30,34,22,16,4,3,15,4,19,1,16,2,34,22,23,20,30,16,7,34,22,16,34,22,3,4,19,19,34,22,4,20,24,2,16,4,
		3,7,34,22,16,8,34,22,20,24,16,4,19,34,22,4,20,24,34,22,4,20,30,4,3,16,3,8,16,9,10,34,22,20,24,34,22,20,30,34,22,16,4,20,24,34,22,4,20,30,34,
		22,4,3,4,19,9,10,16,10,19,16,9,34,22,20,30,34,22,34,22,16,4,20,24,34,22,4,20,24,34,22,16,20,24,34,22,16,4,20,30,34,22,4,19,34,22,4,20,24,10,19,
		9,34,22,16,10,20,24,34,22,34,22,4,20,24,34,22,16,20,24,34,22,23,16,4,20,30,34,22,4,20,30,34,22,20,24,34,22,16,20,30,34,22,16,4,34,22,4,20,24,34,22,
		4,20,30,34,22,10,20,24,34,22,21,16,10,20,24,34,22,10,20,24,34,22,16,10,20,30,34,22,23,4,20,30,34,22,20,24,34,22,23,16,20,30,16,4,7,34,22,16,4,34,22,
		4,34,22,20,30,34,22,16,34,22,23,4,20,30,34,22,4,34,22,21,10,20,24,34,22,20,24,34,22,10,20,30,16,1,10,34,22,21,10,20,24,34,22,16,10,20,30,34,22,10,20,
		30,34,22,16,10,4,7,34,22,4,34,22,23,20,30,16,7,34,22,16,16,4,8,34,22,4,7,34,22,4,1,10,34,22,21,20,24,34,22,10,20,30,34,22,20,30,34,22,10,1,10,
		16,2,10,34,22,10,20,30,34,22,16,10,34,22,10,4,8,7,34,22,16,8,16,4,9,10,4,8,2,10,1,34,22,20,30,34,22,10,34,22,2,10,16,4,3,10,34,22,10,4,9,
		10,8,16,9,10,16,4,10,19,16,4,9,4,3,10,2,34,22,16,3,10,4,10,19,4,9,9,10,16,10,19,16,9,34,22,16,4,10,20,24,3,10,4,3,34,22,4,10,20,24,10,
		19,9,16,19,34,22,16,10,20,24,34,22,16,4,10,20,24,34,22,4,10,20,24,34,22,16,4,10,20,30,3,4,19,34,22,4,10,20,24,34,22,10,20,24,34,22,4,20,24,34,22,
		4,10,20,30,19,34,22,16,10,20,24,34,22,10,20,24,34,22,16,10,20,30,34,22,4,10,20,24,34,22,16,4,10,20,30,34,22,4,10,20,30,34,22,16,4,10,19,34,22,10,20,
		24,34,22,4,20,24,34,22,4,10,20,30,34,22,20,24,34,22,10,20,30,34,22,4,20,30,34,22,4,10,34,22,10,20,24,34,22,16,10,20,30,34,22,10,20,30,34,22,16,10,34,
		22,4,10,20,30,34,22,16,4,10,34,22,4,10,34,22,20,24,34,22,10,20,30,34,22,4,20,30,34,22,4,10,34,22,20,30,34,22,10,34,22,4,34,22,10,20,30,34,22,16,10,
		34,22,10,34,22,4,10,34,22,20,30,34,22,10,34,22,4,34,22,34,22,10,34,22};
const unsigned int in_state[NTRANS]={1,0,2,1,3,0,2,4,2,5,0,5,3,6,7,0,5,8,5,9,0,9,10,11,0,9,12,13,14,15,16,0,0,17,18,19,14,20,21,17,22,0,23,0,14,20,24,20,25,0,24,
		21,26,14,25,26,22,27,18,28,29,23,30,0,24,24,31,14,25,32,31,25,33,0,31,26,34,14,33,34,18,28,35,36,28,37,0,36,29,38,18,37,38,30,39,0,31,40,31,41,40,42,
		14,33,43,41,0,41,44,45,0,36,45,36,46,18,37,46,37,47,0,46,38,48,18,47,48,49,0,41,50,49,51,52,50,53,54,54,0,46,46,55,18,47,56,55,0,55,57,58,15,59,60,
		58,61,59,10,62,0,55,63,64,63,65,66,18,14,67,19,14,18,13,68,69,70,70,71,72,71,59,73,72,74,67,75,76,76,74,77,21,18,78,79,72,80,59,73,78,81,73,82,14,81,79,
		74,83,59,82,80,83,75,84,29,85,18,78,86,78,87,0,86,79,88,18,87,88,80,89,14,81,86,81,90,59,82,87,90,82,91,14,90,88,83,92,59,91,89,92,93,0,86,86,94,18,87,
		94,87,95,0,94,88,96,18,95,96,14,90,94,90,97,59,91,98,95,97,14,97,96,99,100,93,101,0,94,94,102,18,95,103,102,0,102,14,97,104,102,105,103,104,0,106,99,100,107,100,108,
		99,108,101,109,0,102,110,111,110,112,110,111,112,99,113,114,106,115,116,99,108,108,117,99,117,118,118,119,118,99,113,120,121,113,122,0,121,114,123,99,122,123,115,124,125,99,117,126,127,126,128,
		129,0,121,128,121,130,99,122,131,130,122,132,0,130,123,133,99,132,133,134,135,136,136,137,138,138,139,0,130,140,130,141,140,142,99,132,141,0,141,85,85,137,143,144,145,143,137,146,147,10,148,
		144,149,0,141,149,150,99,151,143,152,14,99,153,144,145,151,145,154,144,154,152,146,155,156,157,13,99,158,15,159,160,99,151,151,161,99,161,152,162,144,163,164,165,153,166,144,154,161,154,167,144,
		167,162,168,168,169,170,171,18,99,172,19,99,99,161,161,173,99,173,144,163,174,175,163,176,14,174,114,164,177,99,175,178,165,179,144,176,177,179,166,180,144,167,173,114,14,181,178,169,182,168,183,
		168,159,184,185,93,172,186,99,173,14,174,121,174,187,99,175,188,175,189,144,176,190,187,189,176,191,14,187,123,177,192,0,188,178,193,99,189,193,179,194,144,191,192,194,14,181,188,181,195,14,195,
		193,182,196,18,197,198,183,199,159,184,200,201,100,184,202,18,201,114,185,203,159,202,203,101,186,204,14,187,205,130,187,206,0,188,188,207,99,189,208,207,189,209,205,208,210,144,191,206,209,14,206,
		133,0,207,193,211,99,209,211,14,195,212,207,195,213,14,213,211,18,197,214,215,197,216,0,215,198,217,18,216,217,199,218,219,220,107,18,201,219,121,201,221,159,202,221,108,202,222,18,221,123,203,
		223,159,222,223,109,140,224,14,206,141,0,207,225,207,226,225,227,99,209,226,224,227,228,0,226,225,229,14,213,226,230,231,0,215,231,215,232,18,216,232,216,233,0,232,217,234,18,233,234,235,128,
		235,236,116,18,221,130,221,237,159,222,237,117,18,237,133,149,238,239,0,226,239,240,51,150,241,242,239,238,243,244,244,0,232,232,245,18,233,245,0,245,243,138,53,246,241,139,18,237,141,158,247,
		248,249,57,250,251,59,159,144,252,60,160,144,253,247,147,254,0,245,61,159,148,170,157,255,171,157,256,257,65,258,259,66,258,241,260,261,259,137,252,262,170,156,263,264,59,265,266,267,255,268,269,
		266,269,71,165,159,270,271,143,259,272,241,260,273,270,145,260,274,59,273,185,164,261,275,241,274,275,272,146,262,276,277,277,267,59,265,278,279,265,280,18,278,281,266,282,14,279,281,267,283,59,280,
		282,283,268,284,178,159,270,285,151,270,286,18,285,178,271,287,159,286,287,152,272,288,59,273,201,174,273,289,241,274,289,286,154,274,290,59,289,203,177,275,291,241,290,291,288,155,198,18,278,292,278,
		293,14,279,292,279,294,59,280,293,294,280,295,0,292,281,296,18,293,296,282,297,14,294,296,283,298,59,295,297,298,18,285,188,285,299,159,286,299,161,286,300,18,299,193,287,301,159,300,301,162,59,
		289,221,187,289,302,241,290,302,300,167,59,302,223,192,0,292,292,303,18,293,303,293,304,14,294,303,294,305,59,295,304,305,0,303,296,306,18,304,306,14,305,306,18,299,207,299,307,159,300,307,173,
		18,307,211,59,302,237,206,0,303,303,308,18,304,308,14,305,308,0,308,18,307,226,0,308};
const unsigned int rfirst[NESTADOS] = {1,5,10,14,15,20,22,23,24,27,29,30,31,32,34,36,0,41,43,44,49,53,58,63,67,73,77,80,86,90,95,100,102,106,108,110,115,120,124,127,128,131,133,135,137,138,142,146,148,149,150,
		153,154,157,158,161,163,165,0,168,170,172,174,175,176,178,179,185,186,188,189,190,195,201,206,212,213,214,219,223,228,233,239,244,248,249,253,258,262,265,270,275,278,282,286,290,292,296,299,301,306,310,
		313,315,317,319,324,325,329,331,332,333,335,341,345,350,351,353,354,356,358,363,369,373,376,378,379,381,382,384,389,391,394,396,397,399,400,405,406,409,410,412,414,418,421,426,431,433,435,436,439,443,447,
		453,458,461,462,464,466,469,471,475,477,483,488,493,499,502,503,508,510,511,517,519,524,529,536,541,545,550,554,559,564,569,576,581,587,593,597,603,606,610,613,617,620,626,629,635,639,644,647,653,659,664,
		668,670,673,678,680,683,686,688,690,693,695,700,705,709,712,714,717,722,726,729,731,732,734,736,740,742,744,745,749,752,754,756,760,763,766,767,770,774,777,780,781,783,786,789,791,793,796,798,805,807,809,
		815,817,818,820,826,833,839,846,847,849,855,860,865,871,872,878,883,889,895,902,908,913,914,919,924,930,934,939,944,948,953,959,964,968,974,979,983,987,992,997,1001,1005,1008,1011,1016,1020,1023,1027,1031,1034,1037,
		1039,1042,1044};
const unsigned int rnext[NTRANS] = {0,0,2,3,4,0,6,7,8,9,0,11,12,13,0,0,16,17,18,19,0,21,0,0,0,25,26,0,28,0,0,0,0,33,0,35,0,37,38,39,40,0,42,0,0,45,46,47,48,0,50,
		51,52,0,54,55,56,57,0,59,60,61,62,0,64,65,66,0,68,69,70,71,72,0,74,75,76,0,78,79,0,81,82,83,84,85,0,87,88,89,0,91,92,93,94,0,96,97,98,99,0,101,
		0,103,104,105,0,107,0,109,0,111,112,113,114,0,116,117,118,119,0,121,122,123,0,125,126,0,0,129,130,0,132,0,134,0,136,0,0,139,140,141,0,143,144,145,0,147,0,0,0,151,152,
		0,0,155,156,0,0,159,160,0,162,0,164,0,166,167,0,169,0,171,0,173,0,0,0,177,0,0,180,181,182,183,184,0,0,187,0,0,0,191,192,193,194,0,196,197,198,199,200,0,202,203,
		204,205,0,207,208,209,210,211,0,0,0,215,216,217,218,0,220,221,222,0,224,225,226,227,0,229,230,231,232,0,234,235,236,237,238,0,240,241,242,243,0,245,246,247,0,0,250,251,252,0,254,
		255,256,257,0,259,260,261,0,263,264,0,266,267,268,269,0,271,272,273,274,0,276,277,0,279,280,281,0,283,284,285,0,287,288,289,0,291,0,293,294,295,0,297,298,0,300,0,302,303,304,305,
		0,307,308,309,0,311,312,0,314,0,316,0,318,0,320,321,322,323,0,0,326,327,328,0,330,0,0,0,334,0,336,337,338,339,340,0,342,343,344,0,346,347,348,349,0,0,352,0,0,355,0,
		357,0,359,360,361,362,0,364,365,366,367,368,0,370,371,372,0,374,375,0,377,0,0,380,0,0,383,0,385,386,387,388,0,390,0,392,393,0,395,0,0,398,0,0,401,402,403,404,0,0,407,
		408,0,0,411,0,413,0,415,416,417,0,419,420,0,422,423,424,425,0,427,428,429,430,0,432,0,434,0,0,437,438,0,440,441,442,0,444,445,446,0,448,449,450,451,452,0,454,455,456,457,0,
		459,460,0,0,463,0,465,0,467,468,0,470,0,472,473,474,0,476,0,478,479,480,481,482,0,484,485,486,487,0,489,490,491,492,0,494,495,496,497,498,0,500,501,0,0,504,505,506,507,0,509,
		0,0,512,513,514,515,516,0,518,0,520,521,522,523,0,525,526,527,528,0,530,531,532,533,534,535,0,537,538,539,540,0,542,543,544,0,546,547,548,549,0,551,552,553,0,555,556,557,558,0,560,
		561,562,563,0,565,566,567,568,0,570,571,572,573,574,575,0,577,578,579,580,0,582,583,584,585,586,0,588,589,590,591,592,0,594,595,596,0,598,599,600,601,602,0,604,605,0,607,608,609,0,611,
		612,0,614,615,616,0,618,619,0,621,622,623,624,625,0,627,628,0,630,631,632,633,634,0,636,637,638,0,640,641,642,643,0,645,646,0,648,649,650,651,652,0,654,655,656,657,658,0,660,661,662,
		663,0,665,666,667,0,669,0,671,672,0,674,675,676,677,0,679,0,681,682,0,684,685,0,687,0,689,0,691,692,0,694,0,696,697,698,699,0,701,702,703,704,0,706,707,708,0,710,711,0,713,
		0,715,716,0,718,719,720,721,0,723,724,725,0,727,728,0,730,0,0,733,0,735,0,737,738,739,0,741,0,743,0,0,746,747,748,0,750,751,0,753,0,755,0,757,758,759,0,761,762,0,764,
		765,0,0,768,769,0,771,772,773,0,775,776,0,778,779,0,0,782,0,784,785,0,787,788,0,790,0,792,0,794,795,0,797,0,799,800,801,802,803,804,0,806,0,808,0,810,811,812,813,814,0,
		816,0,0,819,0,821,822,823,824,825,0,827,828,829,830,831,832,0,834,835,836,837,838,0,840,841,842,843,844,845,0,0,848,0,850,851,852,853,854,0,856,857,858,859,0,861,862,863,864,0,866,
		867,868,869,870,0,0,873,874,875,876,877,0,879,880,881,882,0,884,885,886,887,888,0,890,891,892,893,894,0,896,897,898,899,900,901,0,903,904,905,906,907,0,909,910,911,912,0,0,915,916,917,
		918,0,920,921,922,923,0,925,926,927,928,929,0,931,932,933,0,935,936,937,938,0,940,941,942,943,0,945,946,947,0,949,950,951,952,0,954,955,956,957,958,0,960,961,962,963,0,965,966,967,0,
		969,970,971,972,973,0,975,976,977,978,0,980,981,982,0,984,985,986,0,988,989,990,991,0,993,994,995,996,0,998,999,1000,0,1002,1003,1004,0,1006,1007,0,1009,1010,0,1012,1013,1014,1015,0,1017,1018,1019,
		0,1021,1022,0,1024,1025,1026,0,1028,1029,1030,0,1032,1033,0,1035,1036,0,1038,0,1040,1041,0,1043};

//mapeamento de eventos não controláveis como entradas
#define Buffer1_subida 2	//Entrada 0 Buffer1_subida
#define Buffer1_descida 4	//Entrada 1 Buffer1_descida
#define Buffer2_subida 8	//Entrada 2 Buffer2_subida
#define Buffer2_descida 10	//Entrada 3 Buffer2_descida
#define Buffer3_subida 14	//Entrada 4 Buffer3_subida
#define Buffer3_descida 16	//Entrada 5 Buffer3_descida
#define Sensor_Pequeno 20	//Entrada 6 Sensor_Pequeno
#define Sensor_Capacitivo 22	//Entrada 7 Sensor_Capacitivo
#define Sensor_Medio 24	//Entrada 8 Sensor_Medio
#define Sensor_Grande 30	//Entrada 9 Sensor_Grande
#define Sensor_Esteira 34	//Entrada 10 Sensor_Esteira
///////////

//definição dos eventos de saída
#define SP1_0_ON P1OUT |= BIT0
#define SP1_0_OFF P1OUT &=~BIT0

#define S0_ON  P2OUT |= BIT0	//Saida 0 ON //braço 1//valvula 1
#define S0_OFF P2OUT &=~BIT0	//Saida 0 OFF
#define S1_ON  P2OUT |= BIT1	//Saida 1 ON // braço 2 // valvula 2
#define S1_OFF P2OUT &=~BIT1	//Saida 1 OFF
#define S2_ON  P2OUT |= (BIT2+~BIT3)	//Saida 2 ON //braço 3 // valvula 3
#define S2_OFF P2OUT &=~BIT2	//Saida 2 OFF
#define S3_ON  P2OUT |= (BIT3+~BIT2)	//Saida 3 ON //braço 3 // valvula 4
#define S3_OFF P2OUT &=~BIT3	//Saida 3 OFF

#define S4_ON  P2OUT |= BIT4	//Saida 4 ON
#define S4_OFF P2OUT &=~BIT4	//Saida 4 OFF


#define S5_ON  P2OUT |= BIT5	//Saida 5 ON
#define S5_OFF P2OUT &=~BIT5	//Saida 5 OFF
#define S6_ON  P2OUT |= BIT6	//Saida 6 ON
#define S6_OFF P2OUT &=~BIT6	//Saida 6 OFF
#define S7_ON  P2OUT |= BIT7	//Saida 7 ON
#define S7_OFF P2OUT &=~BIT7	//Saida 7 OFF

//Definição de funções de inicialização
void config_clk(void);		//Configura Clock
void config_timer(void);		//Configura Timer
void config_io(void);		//Configura entradas e saídas
void tempo_ms(unsigned int);	//Função de temporização do timer A em milisegundos

//Declaração de variáveis globais
unsigned int buffer[BUFFER];		//Buffer para armazenar a fila de enventos externos
unsigned int n_buffer=0;		//Número de eventos no Buffer

void main(void)
{
	WDTCTL = WDTPW + WDTHOLD;		//Desabilita o WDT
	config_clk();				//configura o clk
	config_timer();			//configura o timer
	config_io();				//configura entradas e saídas

	unsigned int k;
	int occur_event;			//Evento ocorrido
	unsigned int current_state = 0;	//Estado atual inicializado com estado inicial
	int g=6; 			//Flag para gerador aleatório de eventos
	int gerar_evento=1;			//Flag para habilitar a temporização de eventos controláveis
	int mealy_output = 0;		//Inicializa saída periférica
	_enable_interrupt();		//Habilita interrupção geral

	while(1)
	{

		if(n_buffer == 0)//se não existir evento no buffer então gerar um evento interno(evento controlável)
		{
			if(TACTL&TAIFG)	//Se o timer estourar, habilita a geração de eventos 
			{
				gerar_evento=1;
				g=6;
			}
			if(gerar_evento==1)
			{
				switch(g)	//Aqui é implementado um gerador automático de eventos controláveis
				{
					case(0)://Ida Braço 1
						occur_event=1;
						g=10;
						break;
					case(1)://Volta_Braço1
						occur_event=3;
						g=10;
						break;
					case(2)://Ida Braço 2
						occur_event=7;
						g=10;
						break;
					case(3)://Volta_Braço2
						occur_event=9;
						g=10;
						break;
					case(4)://Ida Braço 3
						occur_event=13;
						g=10;
						break;
					case(5)://Volta_Braço3
						occur_event=15;
						g=10;
						break;
					case(6)://Coloca_peça
						occur_event=19;
						g=10;
						break;
					case(7)://Peça Pequena
						occur_event=21;
						g++;
						break;
					case(8)://Peça Media
						occur_event=23;
						g++;
						break;
					case(9)://Peça Grande
						occur_event=25;
						g=10;
						break;
					default:
					    break;
				}
			}
		}
		else 	//se existir evento não controlável pegar do buffer
		{
			occur_event = buffer[0];
			n_buffer--;
			k = 0;
			while(k<n_buffer)
			{
				buffer[k] = buffer[k+1];
				k++;
			}
		}

		//Jogador de autômato
		k = rfirst[current_state];
		if(k==0)
		{
			return;     //Dead Lock!!!
		}
		else
		{
			while(k>0)
			{
				k--;
				if(event[k] == occur_event)
				{
					current_state = in_state[k];
					mealy_output = 1;
					break;
				}
				k = rnext[k];
			}
		}

		if(mealy_output) //Se o evento ocorrido for válido, então imprimir saída física
		{
			switch(occur_event)
			{
				//eventos controláveis
				case(1):	//Adicionar Ação para o Evento 1;//ida do braço 1
                    S0_ON;
					break;
				case(3):	//Adicionar Ação para o Evento 3;//volta do braço 1
				    g=6;
				    gerar_evento=1;
                    S0_OFF;
					break;
				case(7):	//Adicionar Ação para o Evento 7;//ida braço 2
                    S1_ON;
					break;
				case(9):	//Adicionar Ação para o Evento 9;//volta braço 2
                    g=6;
				    gerar_evento=1;
                    S1_OFF;
					break;
				case(13):	//Adicionar Ação para o Evento 13;//ida braço 3
                    S2_ON;
					break;
				case(15):	//Adicionar Ação para o Evento 15;//volta braço 3
                    g=6;
				    gerar_evento=1;
                    S3_ON;
					break;
				//eventos para controle
				case(19):	//Adicionar Ação para o Evento 19;//coloca peça

					break;
				case(21):	//Adicionar Ação para o Evento 21;//peça pequena
                    g=0;
                    gerar_evento=1;
					break;
				case(23):	//Adicionar Ação para o Evento 23;//peça media
                    g=2;
                    gerar_evento=1;
					break;
				case(25):	//Adicionar Ação para o Evento 25;//peça grande
                    g=4;
                    gerar_evento=1;
					break;
				//eventos não controláveis
				case(2):	//Adicionar Ação para o Evento 2; //Entrada 0 Buffer1_subida
                    g=1;
					gerar_evento=1;
					break;
				case(4):	//Adicionar Ação para o Evento 4;//Entrada 1 Buffer1_descida

					//gerar_evento=1;
					break;
				case(8):	//Adicionar Ação para o Evento 8;//Entrada 2 Buffer2_subida
                    g=3;
					gerar_evento=1;
					break;
				case(10):	//Adicionar Ação para o Evento 10;//Entrada 3 Buffer2_descida

					//gerar_evento=1;
					break;
				case(14):	//Adicionar Ação para o Evento 14;//Entrada 4 Buffer3_subida
                    g=5;
					gerar_evento=1;
					break;
				case(16):	//Adicionar Ação para o Evento 16;//Entrada 5 Buffer3_descida

					//gerar_evento=1;
					break;
				case(20):	//Adicionar Ação para o Evento 20;//Entrada 6 Sensor_Pequeno

					//gerar_evento=1;
					break;
				case(22):	//Adicionar Ação para o Evento 22;//Entrada 7 Sensor_Capacitivo
                    g=7;//g=?;
					gerar_evento=1;//eeeeeeeeeeeeeeerro//como eu vejo a evolução dos estados para acionar determinado evento no caso pp, pm, pg//OBS
					break;
				case(24):	//Adicionar Ação para o Evento 24;//Entrada 8 Sensor_Medio

					//gerar_evento=1;
					break;
				case(30):	//Adicionar Ação para o Evento 30; //Entrada 9 Sensor_Grande

					//gerar_evento=1;
					break;
				case(34):	//Adicionar Ação para o Evento 34;//Entrada 10 Sensor_Esteira
                    g=6;
					gerar_evento=1;
					break;
			}//fim switch
			mealy_output = 0;
			occur_event = -1;
		}//fim if(mealy_output)
	}//fim while(1)
}//fim main

//Tratamento da Interrupção da porta P1
//--------------------------------------------------------------
//--------------------------------------------------------------
#pragma vector=PORT1_VECTOR
__interrupt void RTI_PORT1(void)
{
	if(P1IFG&BIT0)	//verifica se P1.0 foi presionado
	{
		P1IFG&=~BIT0;		//apaga o flag
		buffer[n_buffer]=Buffer1_subida;	//Atribuir evento a P1.0
		if(n_buffer<BUFFER-1) n_buffer++;
	}
	if(P1IFG&BIT1)	//verifica se P1.1 foi presionado
	{
		P1IFG&=~BIT1;		//apaga o flag
		buffer[n_buffer]=Buffer1_descida;	//Atribuir evento a P1.1
		if(n_buffer<BUFFER-1) n_buffer++;
	}
	if(P1IFG&BIT2)	//verifica se P1.2 foi presionado
	{
		P1IFG&=~BIT2;		//apaga o flag
		buffer[n_buffer]=Buffer2_subida;	//Atribuir evento a P1.2
		if(n_buffer<BUFFER-1) n_buffer++;
	}
	if(P1IFG&BIT3)	//verifica se P1.3 foi presionado
	{
		P1IFG&=~BIT3;		//apaga o flag
		buffer[n_buffer]=Buffer2_descida;	//Atribuir evento a P1.3
		if(n_buffer<BUFFER-1) n_buffer++;
	}
	if(P1IFG&BIT4)	//verifica se P1.4 foi presionado
	{
		P1IFG&=~BIT4;		//apaga o flag
		buffer[n_buffer]=Buffer3_subida;	//Atribuir evento a P1.4
		if(n_buffer<BUFFER-1) n_buffer++;
	}
	if(P1IFG&BIT5)	//verifica se P1.5 foi presionado
	{
		P1IFG&=~BIT5;		//apaga o flag
		buffer[n_buffer]=Buffer3_descida;	//Atribuir evento a P1.5
		if(n_buffer<BUFFER-1) n_buffer++;
	}
	if(P1IFG&BIT6)	//verifica se P1.6 foi presionado
	{
		P1IFG&=~BIT6;		//apaga o flag
		buffer[n_buffer]=Sensor_Pequeno;	//Atribuir evento a P1.6
		if(n_buffer<BUFFER-1) n_buffer++;
	}
	if(P1IFG&BIT7)	//verifica se P1.7 foi presionado
	{
		P1IFG&=~BIT7;		//apaga o flag
		buffer[n_buffer]=Sensor_Capacitivo;	//Atribuir evento a P1.7
		if(n_buffer<BUFFER-1) n_buffer++;
	}
	P1IFG=0;
}

#pragma vector=PORT2_VECTOR
__interrupt void RTI_PORT2(void)
{
        if(P2IFG&BIT5)  //verifica se P1.8 foi presionado
        {
            P2IFG&=~BIT5;       //apaga o flag
            buffer[n_buffer]=Sensor_Medio;    //Atribuir evento a P1.8
            if(n_buffer<BUFFER-1) n_buffer++;
        }
        if(P2IFG&BIT6)  //verifica se P1.9 foi presionado
        {
            P2IFG&=~BIT6;       //apaga o flag
            buffer[n_buffer]=Sensor_Grande;    //Atribuir evento a P1.9
            if(n_buffer<BUFFER-1) n_buffer++;
        }
        if(P2IFG&BIT7) //verifica se P1.10 foi presionado
        {
            P2IFG&=~BIT7;      //apaga o flag
            buffer[n_buffer]=Sensor_Esteira;   //Atribuir evento a P1.10
            if(n_buffer<BUFFER-1) n_buffer++;
        }
        P2IFG=0;
}

//Configuração de perifericos
//--------------------------------------------------------------
//--------------------------------------------------------------
void config_clk(void)	//configura o clock
{
	//O clock foi configurado a partir do DCO para aprox SMCLK=9,8Mhz
	DCOCTL = 0x00;
	__delay_cycles(100000);
	DCOCTL = MOD0 + MOD1 + MOD2 + MOD3 + MOD4 + DCO0;
	BCSCTL1 = XT2OFF + DIVA_0 + RSEL1 + RSEL2 + RSEL3;
}

//--------------------------------------------------------------
//--------------------------------------------------------------
void config_timer(void)	//configura o timer
{
	//Configura o timer se necessário
	//para este caso será utilizado o Timer A com temporização de eventos
	//f_ref aprox = (VLOCLK)12e3/4 = 3kHz
	//TASSEL_1 -- ACLK
	//ID_2 -- Divide - /4
	//MC_1 -- contagem até TACCR0
	TACTL = TASSEL_1 + ID_2 + MC_1;
	BCSCTL3 |= LFXT1S1;	//coloca como fonte de clk o VLOCLK ao invés do cristal oscilador externo
}

//--------------------------------------------------------------
//--------------------------------------------------------------
void config_io(void)	//configura entradas e saídas
{
	//Por default a porta 1 será considerada entrada e a porta 2 saída
	P1DIR = 0;		//toda a porta P1 como entrada
	P1REN |= BIT0+BIT1+BIT2+BIT3+BIT4+BIT5+BIT6+BIT7;	//habilita resistores de pull(up/down)
	P1OUT |= BIT0+BIT1+BIT2+BIT3+BIT4+BIT5+BIT6+BIT7;	//pull UP
	P1IE  |= BIT0+BIT1+BIT2+BIT3+BIT4+BIT5+BIT6+BIT7;	//habilita interrupção das entradas P1
	P1IES |= BIT0+BIT1+BIT2+BIT3+BIT4+BIT5+BIT6+BIT7;	//a borda de descida que provoca interrupção (descida = 1 - subida = 0)
	//P1IES &= ~(BIT0+BIT1+BIT2+BIT3+BIT4+BIT5+BIT6+BIT7);	//a borda de subida que provoca interrupção (descida = 1 - subida = 0)
	P1IFG = 0;			//Apaga o Flag da interrupção de todas as entradas

	P2DIR=BIT0+BIT1+BIT2+BIT3+BIT4;
	P2REN |= BIT5+BIT6+BIT7;   //habilita resistores de pull(up/down)
    P2OUT |= BIT5+BIT6+BIT7;   //pull UP
    P2IE  |= BIT5+BIT6+BIT7;   //habilita interrupção das entradas P2
	P2IES |= BIT5+BIT6+BIT7;

	P2SEL &= ~(BIT6 | BIT7); 					 //Bit 6 e 7 do P2 como IO 
	P2DIR |= BIT0+BIT1+BIT2+BIT3+BIT4;	//toda a porta P2 como saída
	P2OUT = 0;			//todas as saídas em nível lógico 0
}

//--------------------------------------------------------------
//--------------------------------------------------------------
void tempo_ms(unsigned int tempo)	//Função de temporização do timer A
{
	TACTL|= TACLR;		//zera o timer A
	TACCR0 =3*tempo;	//especifica tempo de estouro
	TACTL &= ~TAIFG;	//zera o Flag do estouro do Timer
}
