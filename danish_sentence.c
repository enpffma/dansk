#include <stdio.h>

#define VERB_NUM		10
#define REPEAT_CNT	2


typedef struct
{
	char question[50];
	char answer[100];
	char repeat_count;
}danish_verb;

danish_verb list[] =
{
/*	
	{ "He wakes up 1 o'clock." , "Han vågner klokken et." , REPEAT_CNT} ,
	{ "He stands in the kitchen."	,"Han står i køkkenet." , REPEAT_CNT} ,
	{ "She dries her hair."	,"Hun tørrer sit hår." , REPEAT_CNT} ,
	{ "She meets her farther in a bus."	,"Hun møder sin far i bussen." , REPEAT_CNT} ,
	{ "He calls to her mother."	,"Han ringer til sin mor." , REPEAT_CNT} ,
	{ "Mother sits at a table."	,"Mor sætter sig ved bordet." , REPEAT_CNT} ,
	{ "Mother helps a girl."	,"Mor hjælper en pige." , REPEAT_CNT} ,
	{ "She is called Lise."	,"Hun hedder Lise." , REPEAT_CNT} ,
	{ "A woman come in a bus."	,"En dame kommer ind i bussen." , REPEAT_CNT} ,
	{ "She buys milk and bread."	,"Hun køber mælk og brød." , REPEAT_CNT} ,
*/	
	{ "She writes with a pencil." , "Hun skriver med en blyant." , REPEAT_CNT} ,
	{ "He plays a ball in school."	,"Han spiller bold i skolen." , REPEAT_CNT} ,
	{ "The girl laughs at her father."	,"Pigen griner af sin far." , REPEAT_CNT} ,
	{ "Mom kisses dad."	,"Mor kysser far." , REPEAT_CNT} ,
	{ "Father talk to a woman."	,"Far snakker med en dame." , REPEAT_CNT} ,
	{ "He runs into the class."	,"Han løber ind i klassen." , REPEAT_CNT} ,
	{ "2 boys plays jumping rope."	,"2 drenge sjipper." , REPEAT_CNT} ,
	{ "He must buy a pencil."	,"Han skal Købe en blyant." , REPEAT_CNT} ,
	{ "She is waiting for father."	,"Hun venter på far." , REPEAT_CNT} ,
	{ "The boy is sleeping in his bed."	,"Drengen sover i sin seng." , REPEAT_CNT} ,	
};


void main()
{
	int i,j,k,shit_count=0,len;
	
	char ans[100];
	
	srand(time(NULL));
	
	i=rand() % VERB_NUM;
	
	while(1)
	{
		memset(ans,0,sizeof(ans));
		
		printf("%s\n",list[i].question);
		
		
retry1:
		//scanf("%s",ans);
		fgets(ans, sizeof(ans), stdin);
	
//		printf("%s\n",ans);
		
		if (memcmp(list[i].answer,ans,strlen(list[i].answer)))
		{
			printf("SHIT!!!!!! %d\n",strlen(list[i].answer));
			shit_count++;
			
			goto retry1;
		}
/*
		len=strlen(ans);

retry2:
		scanf("%s",ans);
		
		if (memcmp(list[i].answer + len +1 ,ans , strlen(ans)))
		{
			printf("SHIT!!!!!!\n");
			shit_count++;
			
			goto retry2;
		}
*/	
		
		
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

