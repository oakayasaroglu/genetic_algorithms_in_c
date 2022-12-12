//Osman Alperen KAYASAROÐLU
//16050511011

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#define NUMBER_OF_CITY 5
#define NUMBER_OF_POPULATION 15
#define COORDINATE_RANGE_END 20
#define MUTATION_RATE 0.2
int finish_him=0;
//NUMBER_OF_CITY cities and distances between two cities
void cityCoord(int cities[NUMBER_OF_CITY][2], float cityDistance[NUMBER_OF_CITY][NUMBER_OF_CITY])
{
	//NUMBER_OF_CITY cities and random coordinates
	for(int a = 0; a < NUMBER_OF_CITY; a++){
	
		cities[a][0] = rand() %COORDINATE_RANGE_END;
	}
	
	for (int b = 0; b < NUMBER_OF_CITY; b++){
	
		cities[b][1] = rand() %COORDINATE_RANGE_END;
	}
	
	printf("x\ty\n");
	printf("--\t--\n");

	for(int i = 0; i < NUMBER_OF_CITY; i++){
		
		for(int k = 0; k < 2; k++){
			
			printf("%d\t", cities[i][k]);
		}
		
		printf("\n");
	}
	//distances between cities
	printf("\n\n");
	
	for(int i = 0; i < NUMBER_OF_CITY; i++){
		
		for(int j = 0; j < NUMBER_OF_CITY; j++){
			
			cityDistance[i][j] = sqrt( pow( (float) ( cities[i][0] - cities[j][0] ) , 2 ) + pow( (float) ( cities[i][1] - cities[j][1] ) , 2 ));
		}
	}
	
	printf("\n The Distance Between Cities: \n");
	printf("\t");
	
	for(int j = 0; j < NUMBER_OF_CITY; j++){
			
			printf("%d\t",j+1);
	}
	
	printf("\n");
	
	for(int i = 0; i < NUMBER_OF_CITY; i++){
		
		printf("%d\t",i+1);
		
		for(int j = 0; j < NUMBER_OF_CITY; j++){
		
			printf("%3.2f\t", cityDistance[i][j]);
		}
		
		printf("\n");
	}
	printf("\n\n");
}
//defining routes with non-repeat random
void change(int populationCities[][NUMBER_OF_CITY])
{
	srand(time(NULL));
	int p;
	p = 1+rand()%NUMBER_OF_CITY;
		    

	int count = 0;
			
	for (int x = 0; x < NUMBER_OF_POPULATION; x++) {
			
	   	for (int y = 0; y < NUMBER_OF_CITY; y++) {
	
	   		p = 1+rand()%NUMBER_OF_CITY;
		    		
	  		for (int z = 0; z < NUMBER_OF_CITY; z++) {
		    			
	   			if (populationCities[x][z] != p) {
	   				count++;
				}
				else {
					y--;
					count = 0;
					break;
				}
			}
					
			if (count == NUMBER_OF_CITY) {
				populationCities[x][y] = p;
				count = 0;
			}
		}
	}
}
//choose random NUMBER_OF_POPULATION/2 routes
void randomTen(int arr[NUMBER_OF_POPULATION/2],int r)
{

	

	int count = 0;
			
	for (int b = 0; b < NUMBER_OF_POPULATION/2; b++) {
			
		r = 1+rand()%NUMBER_OF_POPULATION;
		    		
	  	for (int c = 0; c < NUMBER_OF_POPULATION/2; c++) {
		    			
	   		if (arr[c] != r) {
	   			count++;
			}
			else {
				b--;
				count = 0;
				break;
			}
		}
					
		if (count == NUMBER_OF_POPULATION/2) {
			arr[b] = r;
			count = 0;
		}
	}
}
//total distances of each route
void populationTotalDistance(float populationDistance[NUMBER_OF_POPULATION], int populationCities[NUMBER_OF_POPULATION][NUMBER_OF_CITY], float cityDistance[NUMBER_OF_CITY][NUMBER_OF_CITY])
{
	int city1;
	int city2;
	
	float totalDistance = 0;
	
	for(int i = 0; i < NUMBER_OF_POPULATION; i++){
		
		for(int j = 1; j < NUMBER_OF_CITY; j++){
			
			city1 = populationCities[i][j]-1;
			city2 = populationCities[i][j-1]-1;
			
			totalDistance += cityDistance[city1][city2];
			
	    }	
	
	populationDistance[i] = totalDistance;
	totalDistance = 0;
	
	}

}

int stroute; 
int ndroute;
void crossover(int a[NUMBER_OF_POPULATION][NUMBER_OF_CITY])
{
	int temp;
	int b;
	
	b = 1+rand()%NUMBER_OF_CITY;
	
	printf("Crossover Point: %d\n", b);
    
	for(int s = b; s < NUMBER_OF_CITY; s++){
    	
    	temp = a[ndroute][s];
    	a[ndroute][s] = a[stroute][s];
    	a[stroute][s] = temp;
    	
	}
}
void mutation(int t[NUMBER_OF_POPULATION][NUMBER_OF_CITY])
{
	int temp;
	int b;
	int c;
	
	again: 	b = rand()%NUMBER_OF_CITY;
    		c = rand()%NUMBER_OF_CITY;
    
    if(b == c){
    	
		goto again;
	}
	
    temp = t[stroute][b];
	t[stroute][b] = t[stroute][c];
	t[stroute][c] = temp;
	
	temp = t[ndroute][b];
	t[ndroute][b] = t[ndroute][c];
	t[ndroute][c] = temp;
	
	printf("%d. Cities and %d. Cities Swapped:\n", b+1, c+1);

}

float finish_her = 999999999;
int shortestRoute[NUMBER_OF_CITY];
int main() 
{
	int cities[NUMBER_OF_CITY][2];
	float cityDistance[NUMBER_OF_CITY][NUMBER_OF_CITY];
	int arr[NUMBER_OF_POPULATION];
	float populationDistance[NUMBER_OF_POPULATION];
    int newRoute[NUMBER_OF_POPULATION][NUMBER_OF_CITY];                                                                                   
	int donguSayaci=0;


	srand(time(0));
    
	//NUMBER_OF_CITY cities and random coordinates
    cityCoord(cities,cityDistance);
    
	printf("\n");
    
	//defining routes with non-repeat random
    int populationCities[NUMBER_OF_POPULATION][NUMBER_OF_CITY];
	
	change(populationCities);
	//printin'
	for (int x = 0; x < NUMBER_OF_POPULATION; x++) {
		
		if(x < 9){
			
			printf(" ");
		}
		printf("%d. Route--> ", x+1);
		
		for (int y = 0; y < NUMBER_OF_CITY; y++) {
			
	  		printf("%d  ", populationCities[x][y]);
	  	}
	  	printf("\n");
	}
	printf("\n\n\n");
	while(1){	
	
	int abc;
	//choose random NUMBER_OF_POPULATION/2 routes
	srand(time(NULL));
	abc = 1+rand()%NUMBER_OF_POPULATION;
	randomTen(arr,abc);
	
	for(int f = 0; f < NUMBER_OF_POPULATION/2; f++){
		
		if(arr[f] <= 9){
			
			printf(" ");
		}
		
		printf("%d. Route--> ", arr[f]);
		
		for(int c = 0; c < NUMBER_OF_CITY; c++ ){
			
			printf("%d  ", populationCities[arr[f]-1][c]);
		}
		printf("\n");
	}
	printf("\n\n\n");
	
	//distances of chosen NUMBER_OF_POPULATION/2 routes
	populationTotalDistance(populationDistance,populationCities,cityDistance);
	
	for(int i = 0; i < NUMBER_OF_POPULATION/2; i++){
	
		printf("Total distance of %d. route : %3.3f \n", arr[i], populationDistance[arr[i]-1]);
	
	}
	printf("\n\n\n");
	
	//choosing shortest 2 routes from random NUMBER_OF_POPULATION/2 routes
	float shortest = populationDistance[arr[0]-1];
	for(int h = 0; h < NUMBER_OF_POPULATION/2; h++){
		
		if(populationDistance[arr[h]-1] <= shortest){
			
			shortest = populationDistance[arr[h]-1];
		}
	}
	
	for(int y = 0; y < NUMBER_OF_POPULATION/2; y++){
		
		if(shortest == populationDistance[arr[y]-1]){
			
			stroute = arr[y]-1;                                                                            //en kýsa kaçýncý rotaysa kalýcý olarak kaydettim
		}
	}
	
	printf("The shortest route is %d. route:%3.3f\n", stroute+1, populationDistance[stroute]);
	
	float shorter = 999999999;
	
	for(int h = 0; h < NUMBER_OF_POPULATION/2; h++){
		
		if(shortest < populationDistance[arr[h]-1]){
		 
		    if(populationDistance[arr[h]-1] < shorter){
			
			    shorter = populationDistance[arr[h]-1];
		    }
	    }
	}
	
	for(int h = 0; h < NUMBER_OF_POPULATION/2; h++){
		
		if(shorter == populationDistance[arr[h]-1]){
	
			ndroute = arr[h]-1;                                                                            //2.en kýsa kaçýncý rotaysa kalýcý olarak kaydettim
		}
	}
	
	printf("The 2nd shortest route is %d. route:%3.3f\n", ndroute+1, populationDistance[ndroute]);
    printf("\n\n\n");
    
    printf("Before Crossing-Over:\n");
    
	for(int i = 0; i < NUMBER_OF_CITY; i++){
    	
    	printf("%d  ", populationCities[stroute][i]);	
	}
	
	printf("\n");
		
	for(int i = 0; i < NUMBER_OF_CITY; i++){
    	
    	printf("%d  ", populationCities[ndroute][i]);	
	}
    
    printf("\n\n");
    
	//cross-over between shortest 2 routes from NUMBER_OF_POPULATION/2 routes
	int temp = 0;
    
	for(int i = 0; i < NUMBER_OF_CITY; i++){
    	
		newRoute[stroute][i] = populationCities[stroute][i];
    	newRoute[ndroute][i] = populationCities[ndroute][i];
    }

	crossover(newRoute);
	
	printf("Crossing-Over Applied:\n");
		
	for(int z = 0; z < NUMBER_OF_CITY; z++){
		
		printf("%d  ", newRoute[stroute][z]);
	}
	
	printf("\n");
	
	for(int r = 0; r < NUMBER_OF_CITY; r++){
	
		printf("%d  ", newRoute[ndroute][r]);
	}
	
	printf("\n\n");
	
	//treating has applied cross-over routes
	for(int i = 0; i < NUMBER_OF_CITY; i++){
		
		for(int j = 0; j < NUMBER_OF_CITY; j++){
			
			if(i != j){
				
				if(newRoute[stroute][i] == newRoute[stroute][j]){
					
					line:newRoute[stroute][i] = 1+rand()%NUMBER_OF_CITY;
					
					for(int k = 0; k < NUMBER_OF_CITY; k++){
						
						if(i != k){
							
							if(newRoute[stroute][i] == newRoute[stroute][k]){
								
								goto line;
							}
						}
					}
				}
			}
		}
	}
	for(int z = 0; z < NUMBER_OF_CITY; z++){
		
		printf("%d  ", newRoute[stroute][z]);
	}
	
	printf("\n");
	
	for(int i = 0; i < NUMBER_OF_CITY; i++){
		
		for(int j = 0; j < NUMBER_OF_CITY; j++){
		
			if(i != j){
		
				if(newRoute[ndroute][i] == newRoute[ndroute][j]){
		
					chopper:newRoute[ndroute][i] = 1+rand()%NUMBER_OF_CITY;
		
					for(int k = 0; k < NUMBER_OF_CITY; k++){
		
						if(i != k){
		
							if(newRoute[ndroute][i] == newRoute[ndroute][k]){
		
								goto chopper;
							}
						}
					}
				}
			}
		}
	}
	for(int z = 0; z < NUMBER_OF_CITY; z++){
		
		printf("%d  ", newRoute[ndroute][z]);
	}
	printf("\n\n\n\n");
	
	//mutation
	int q;
	int r = 1/MUTATION_RATE;
	
	q = 1+rand()%r;
	
	printf("Random Number For Mutation: %d \n", q);
	
	if(q == 3){
		
		mutation(newRoute);
		
		printf("Mutation Applied:\n\n");
		
		for(int e = 0; e < NUMBER_OF_CITY; e++){
			
			printf("%d  ", newRoute[stroute][e]);
			
			populationCities[stroute][e]=newRoute[stroute][e];
		}
		
		populationTotalDistance(populationDistance,populationCities,cityDistance);		
		
		printf("--> %3.3f\n", populationDistance[stroute]);
		for(int f = 0; f < NUMBER_OF_CITY; f++){
			
			printf("%d  ", newRoute[ndroute][f]);
			
			populationCities[ndroute][f]=newRoute[ndroute][f];
		}
		printf("--> %3.3f\n", populationDistance[ndroute]);
		printf("\n");
		
	}
	else{
		
		printf("No Mutation:\n");
		
		for(int a = 0; a < NUMBER_OF_CITY; a++){
		
			printf("%d  ", newRoute[stroute][a]);
			
			populationCities[stroute][a] = newRoute[stroute][a];
		}

		printf("--> %3.3f\n", populationDistance[stroute]);
		
		for(int b = 0; b < NUMBER_OF_CITY; b++){
		
			printf("%d  ", newRoute[ndroute][b]);
			
			populationCities[ndroute][b] = newRoute[ndroute][b];
		}
		populationTotalDistance(populationDistance,populationCities,cityDistance);

		printf("--> %3.3f\n", populationDistance[ndroute]);
		
		printf("\n\n");
	}	
	
	//adding has applied crossing_over and mutated(if) routes to population again
	for(int f = 0; f < NUMBER_OF_CITY; f++){
	
		populationCities[stroute][f] = newRoute[stroute][f];
	}
	
	for(int f = 0; f < NUMBER_OF_CITY; f++){
	
		populationCities[ndroute][f] = newRoute[ndroute][f];
	}
	
	populationTotalDistance(populationDistance,populationCities,cityDistance);
	
	if(finish_her >= populationDistance[stroute]){
	
		for(int i = 0; i < NUMBER_OF_CITY; i++){
		
			shortestRoute[i]=populationCities[stroute][i];
		}
	
		finish_her = populationDistance[stroute];
		finish_him++;
	}
	if(finish_her >= populationDistance[ndroute]){
	
		for(int i = 0; i < NUMBER_OF_CITY; i++){
			
			shortestRoute[i]=populationCities[ndroute][i];
		}
	
		finish_her = populationDistance[ndroute];
		finish_him++;
	}
		
	if(finish_him ==100){
	//***********************************************//	
		printf("x\ty\n");
		printf("--\t--\n");
	
		for(int i = 0; i < NUMBER_OF_CITY; i++){
		
			for(int k = 0; k < 2; k++){
			
				printf("%d\t", cities[i][k]);
			}
		
		printf("\n");
	}
	
	//****************************************************//
	
	printf("\n The Distance Between Cities: \n");
	printf("\t");
	
	for(int j = 0; j < NUMBER_OF_CITY; j++){
			
			printf("%d\t",j+1);
	}
	
	printf("\n");
	
	for(int i = 0; i < NUMBER_OF_CITY; i++){
		
		printf("%d\t",i+1);
		
		for(int j = 0; j < NUMBER_OF_CITY; j++){
		
			printf("%3.2f\t", cityDistance[i][j]);
		}
		
		printf("\n");
	}
	printf("\n\n");	
	
//*********************************************************//	
	
		
		printf("\n***The shortest route is:  ");
	
		for(int i = 0; i < NUMBER_OF_CITY; i++){
	
			printf("%d  ", shortestRoute[i]);
		}
	
		printf("--->%3.3f***", finish_her);
		
		break;
	}
	donguSayaci++;
	printf("%d. DONGU BITTI.\n", donguSayaci);
}
	

    return 0;
}
