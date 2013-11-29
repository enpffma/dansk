#include <stdio.h>

#define VERB_NUM		25
#define REPEAT_CNT	2
typedef struct
{
	char question[20];
	char answer[50];
	char repeat_count;
}danish_verb;

danish_verb list[] =
{
	{ "at arbejde" , "arbejder-arbejdede" , REPEAT_CNT} ,
	{ "at cykle"	,"cykler-cyklede" , REPEAT_CNT} ,
	{ "at lave"	,"laver-lavede" , REPEAT_CNT} ,
	{ "at snakke"	,"snakker-snakkede" , REPEAT_CNT} ,
	{ "at bo"	,"bor-boede" , REPEAT_CNT} ,
	{ "at spise"	,"spiser-spiste" , REPEAT_CNT} ,
	{ "at læse"	,"læser-læste" , REPEAT_CNT} ,
	{ "at køre"	,"kører-kørte" , REPEAT_CNT} ,
	{ "at høre"	,"hører-hørte" , REPEAT_CNT} ,
	{ "at købe"	,"køber-købte" , REPEAT_CNT} ,
	
	{ "at rejse"	,"rejser-rejste" , REPEAT_CNT} ,
	{ "at være"	,"er-var" , REPEAT_CNT} ,
	{ "at have"	,"har-havde" , REPEAT_CNT} ,
	{ "at gå"	,"går-gik" , REPEAT_CNT} ,
	{ "at få"	,"får-fik" , REPEAT_CNT} ,
	{ "at sidde"	,"sidder-sad" , REPEAT_CNT} ,
	{ "at ligge"	,"ligger-lå" , REPEAT_CNT} ,
	{ "at stå"	,"står-stod" , REPEAT_CNT} ,
	{ "at tage"	,"tager-tog" , REPEAT_CNT} ,
	{ "at drikke"	,"drikker-drak" , REPEAT_CNT} ,

	{ "at skrive"	,"skriver-skrev" , REPEAT_CNT} ,
	{ "at gøre"	,"gør-gjorde" , REPEAT_CNT} ,
	{ "at sove"	,"sover-sov" , REPEAT_CNT} ,
	{ "at komme"	,"kommer-kom" , REPEAT_CNT} ,
	{ "at se"	,"ser-så" , REPEAT_CNT} ,
};


void main()
{
	int i,j,k,shit_count=0,len;
	
	char ans[50];
	
	srand(time(NULL));
	
	i=rand() % VERB_NUM;
	
	while(1)
	{
		memset(ans,0,sizeof(ans));
		
		printf("%s\n",list[i].question);
		
		
retry1:
		scanf("%s",ans);
		
		if (memcmp(list[i].answer,ans,strlen(ans)))
		{
			printf("SHIT!!!!!!\n");
			shit_count++;
			
			goto retry1;
		}
		
		len=strlen(ans);

retry2:
		scanf("%s",ans);
		
		if (memcmp(list[i].answer + len +1 ,ans , strlen(ans)))
		{
			printf("SHIT!!!!!!\n");
			shit_count++;
			
			goto retry2;
		}
		
		
		
		{	
			printf("hmm!!\n\n");
			
			list[i].repeat_count --;
			
			
			for(i=0,k=0;i<VERB_NUM;i++)
				k+=list[i].repeat_count;
			
			if(!k)
				break;
				
			printf("remaining quesionts: %d\n\n",k);
				
			while(!(list[i=rand() % VERB_NUM].repeat_count));
			
		}
	}
	
	printf("FINISH!!! shit count:%d\n",shit_count);
}

