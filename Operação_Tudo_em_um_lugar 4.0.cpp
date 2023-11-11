#include<stdlib.h> 
#include<stdio.h>
#include <time.h>
#include <conio.h>

//////////////////////////////// Quick Sort /////////////////////////////////////////
void swap(int* a, int* b) 
{ 
    int t = *a; 
    *a = *b; 
    *b = t; 
}
int partition (int arr[], int low, int high) 
{ 
    int pivot = arr[high];     
    int i = (low - 1);  
  
    for (int j = low; j <= high- 1; j++) 
    { 
        if (arr[j] <= pivot) 
        { 
            i++;    
            swap(&arr[i], &arr[j]); 
        } 
    } 
    swap(&arr[i + 1], &arr[high]); 
    return (i + 1); 
}
void quickSort(int arr[], int low, int high) 
{ 
    if (low < high) 
    {
        int pi = partition(arr, low, high); 
  
        quickSort(arr, low, pi - 1); 
        quickSort(arr, pi + 1, high); 
    } 
} 
  

void printArray(int arr[], int size) 
{ 
    int i; 
    for (i=0; i < size; i++) 
        printf("%d ", arr[i]); 
    printf("n"); 
} 

//////////////////////////////////////////// MergeSort ////////////////////////////////////////////////////
void merge(int arr[], int l, int m, int r) 
{ 
    int i, j, k; 
    int n1 = m - l + 1; 
    int n2 =  r - m; 
  
    
    int L[n1], R[n2]; 
  
    for (i = 0; i < n1; i++) 
        L[i] = arr[l + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = arr[m + 1+ j];
    i = 0; 
    j = 0; 
    k = l; 
    while (i < n1 && j < n2) 
    { 
        if (L[i] <= R[j]) 
        { 
            arr[k] = L[i]; 
            i++; 
        } 
        else
        { 
            arr[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
  
    
    while (i < n1) 
    { 
        arr[k] = L[i]; 
        i++; 
        k++; 
    } 
  
    while (j < n2) 
    { 
        arr[k] = R[j]; 
        j++; 
        k++; 
    } 
} 
  
void mergeSort(int arr[], int l, int r) 
{ 
    if (l < r) 
    {  
        int m = l+(r-l)/2; 
  
        
        mergeSort(arr, l, m); 
        mergeSort(arr, m+1, r); 
  
        merge(arr, l, m, r); 
    } 
}

/////////////////////////////////////////////////// SelectionSort ///////////////////////////////////////////////////////
int indiceMenor(int vet[], int tam, int ini){
int min = ini, j;
for(j=ini+1; j<tam; j++){
if(vet[min] > vet[j])
min = j;
}
return min;
}
void troca(int *a, int *b){
int aux;
aux = *a;
*a = *b;
*b = aux;
}
void selectionSort(int vet[], int tam){
int i, j, min;
for(i=0; i<tam; i++){
min = i;
for(j = i+1; j<tam; j++){//Acha posicao do menor elemento a partir de i
if(vet[min] > vet[j])
min = j;
}
troca(&vet[i], &vet[min]);
}
}




















int main() 
{  
   FILE *file;
    int num;
    int i,op, qtd, tipo, arq, final;
	char c;
	int tamanho;
	qtd = -1;
	do{
        printf("Tipo de Dado\n");
        printf("1. Aleatorio\n");
        printf("2. Concavo(DecresceCresce)\n");
        printf("3. Convexo(CresceDecresce)\n");
        printf("4. Sair do menu\n");
        scanf("%d",&tipo);
        system("cls");    

        switch(tipo){    
        case 1:
        {
          printf("Lembre-se que voce tem que baixar a opcao na qual escolheu!!!\n");	
          printf("Escolha um arquivo do tipo aleatorio\n");
          printf("1.Lista de 5 mil numeros\n");
          printf("2.Lista de 50 mil numeros\n");
          printf("3.Lista de 100 mil numeros\n");
          scanf("%d",&arq);
          if(arq == 1){
          	file = fopen("Aleatorio5k.txt", "r");
          	printf("Lista de 5k numeros foi aberta.");
          	
		  }
		  if(arq == 2){
		  	file = fopen("Aleatorio50k.txt", "r");
		  	printf("lista de 50 mil numeros foi aberta.");
		  }
		  if(arq == 3){
		  	file = fopen("Alatorio100k.txt", "r");
		  	printf("lista de 100 mil numeros foi aberta.");
		  }
		  	final = 1;
            break;
	    }
		case 2:
		{
		  printf("Lembre-se que voce tem que baixar a opcao na qual escolheu!!!\n");	
          printf("Escolha um arquivo do tipo Concavo\n");
          printf("1.Lista de 5 mil numeros\n");
          printf("2.Lista de 50 mil numeros\n");
          printf("3.Lista de 100 mil numeros\n");
          scanf("%d",&arq);
          if(arq == 1){
          	file = fopen("Concavo5k.txt", "r");
          	printf("lista de 5 mil numeros foi aberta.");
		  }
		  
		  if(arq == 2){
		  	file = fopen("Concavo50k.txt", "r");
		  	printf("lista de 50 mil numeros foi aberta.");
		  }
		  if(arq == 3){
		  	file = fopen("Concavo100k.txt", "r");
		  	printf("lista de 100 mil numeros foi aberta.");
		  }
		  final = 1;
            break;
        
		}	
        case 3:
		{
		  printf("Lembre-se que voce tem que baixar a opcao na qual escolheu!!!\n");	
          printf("Escolha um arquivo do tipo Convexo\n");
          printf("1.Lista de 5 mil numeros\n");
          printf("2.Lista de 50 mil numeros\n");
          printf("3.Lista de 100 mil numeros\n");
          scanf("%d",&arq);
          if(arq == 1){
          	file = fopen("Convexo5k.txt", "r");
          	printf("lista de 5 mil numeros foi aberta.");
		  }
		  if(arq == 2){
		  	file = fopen("Convexo50k.txt", "r");
		  	printf("lista de 50 mil numeros foi aberta.");
		  }
		  if(arq == 3){
		  	file = fopen("Convexo100k.txt", "r");
		  	printf("lista de 100 mil numeros foi aberta.");
		  }
		  final = 1;
		  	  break;
		}
		case 4:
			{
			printf("Escolheu sair do menu\n");
			final = 1;
            break;	
			}
		default:
            printf("Entrada \n");   
        }
      }while(final != 1 );
       
                
    for (c = getc(file); c != EOF; c = getc(file)){
        if (c == '\n'){
            qtd = qtd + 1;
        }
    }
    
    int arr[qtd];
    rewind(file);
    while(file != NULL && !feof(file)){ //o for interno estava errado
          fscanf(file,"%d",&arr[i]); //desta forma, ele irá ler todos
          i++;
    }
    
    
    do{
        printf("Menu\n");
        printf("1. SelectionSort\n");
        printf("2. Mergesort\n");
        printf("3. Quicksort\n");
        scanf("%d",&op);
        system("cls");    

        switch(op){    
        case 1:
            {
            clock_t inicio = clock();
				
			printf("\nVetor Antes: (");
            for(i=0;i<qtd;i++)
            printf("%d, ", arr[i]);
            printf(")");
            selectionSort(arr,qtd);
            printf("\n\nVetor Depois: (");
            for(i=0;i<qtd;i++)
            printf("%d, ", arr[i]);
            printf(")\n");
            
            clock_t fim = clock();
            
            double gasto = difftime(fim,inicio)/CLOCKS_PER_SEC;
            printf("\nTempo gasto no Select: %f segundos\n", gasto);
            
            FILE *f;
            if(tipo == 1){
				if(arq == 1){
				f = fopen("Lista_Ordanada_Select_5k_Aleatoria.txt","w");	
				}
				if(arq == 2){
				f = fopen("Lista_Ordanada_Select_50k_Aleatoria.txt","w");	
				}
				if(arq == 3){
				f = fopen("Lista_Ordanada_Select_100k_Aleatoria.txt","w");	
				}
	   		}
	   		if(tipo == 2){
				if(arq == 1){
				f = fopen("Lista_Ordanada_Select_5k_Concava.txt","w");	
				}
				if(arq == 2){
				f = fopen("Lista_Ordanada_Select_50k_Concava.txt","w");	
				}
				if(arq == 3){
				f = fopen("Lista_Ordanada_Select_100k_Concava.txt","w");	
				}
	   		}
	   		if(tipo == 3){
				if(arq == 1){
				f = fopen("Lista_Ordanada_Select_5k_Convexa.txt","w");	
				}
				if(arq == 2){
				f = fopen("Lista_Ordanada_Select_50k_Convexa.txt","w");	
				}
				if(arq == 3){
				f = fopen("Lista_Ordanada_Select_100k_Convexa.txt","w");	
				}
	   		}
	   		
		            for (int j =0; j < qtd; j++ ){
		            	fprintf(f,"\n %d ",arr[j]);
					}
			
			fclose(f);
            
            
            return 0;  
            break;
        }
        case 2:
           {
           	clock_t inicio = clock();
           	
			int arr_size = sizeof(arr)/sizeof(arr[0]); 
            printf("Given array is \n"); 
            printArray(arr, arr_size); 
            mergeSort(arr, 0, arr_size - 1); 
            printf("\nSorted array is \n"); 
            printArray(arr, arr_size);
            
            clock_t fim = clock();
			double gasto = difftime(fim,inicio)/CLOCKS_PER_SEC;
            printf("\nTempo gasto no Merge: %f segundos\n", gasto);
            
            FILE *f;
            if(tipo == 1){
				if(arq == 1){
				f = fopen("Lista_Ordanada_Merge_5k_Aleatoria.txt","w");	
				}
				if(arq == 2){
				f = fopen("Lista_Ordanada_Merge_50k_Aleatoria.txt","w");	
				}
				if(arq == 3){
				f = fopen("Lista_Ordanada_Merge_100k_Aleatoria.txt","w");	
				}
	   		}
	   		if(tipo == 2){
				if(arq == 1){
				f = fopen("Lista_Ordanada_Mege_5k_Concava.txt","w");	
				}
				if(arq == 2){
				f = fopen("Lista_Ordanada_Merge_50k_Concava.txt","w");	
				}
				if(arq == 3){
				f = fopen("Lista_Ordanada_Merge_100k_Concava.txt","w");	
				}
	   		}
	   		if(tipo == 3){
				if(arq == 1){
				f = fopen("Lista_Ordanada_Merge_5k_Convexa.txt","w");	
				}
				if(arq == 2){
				f = fopen("Lista_Ordanada_Merge_50k_Convexa.txt","w");	
				}
				if(arq == 3){
				f = fopen("Lista_Ordanada_Merge_100k_Convexa.txt","w");	
				}
	   		}
	   		
            
            for (int j =0; j < qtd; j++ ){
            	fprintf(f,"\n %d ",arr[j]);
			}
			fclose(f);
			
            return 0; 
            break;
        }
        case 3:
        {
        	clock_t inicio = clock();
        	
	     	int n = sizeof(arr)/sizeof(arr[0]); 
            quickSort(arr, 0, n-1); 
            printf("Sorted array: n"); 
            printArray(arr, n);
            
            clock_t fim = clock();
	        double gasto = difftime(fim,inicio)/CLOCKS_PER_SEC;
            printf("\nTempo gasto no Quick: %f segundos\n", gasto);
            FILE *f;
            if(tipo == 1){
				if(arq == 1){
				f = fopen("Lista_Ordanada_Quick_5k_Aleatoria.txt","w");	
				}
				if(arq == 2){
				f = fopen("Lista_Ordanada_Quick_50k_Aleatoria.txt","w");	
				}
				if(arq == 3){
				f = fopen("Lista_Ordanada_Quick_100k_Aleatoria.txt","w");	
				}
	   		}
	   		if(tipo == 2){
				if(arq == 1){
				f = fopen("Lista_Ordanada_Quick_5k_Concava.txt","w");	
				}
				if(arq == 2){
				f = fopen("Lista_Ordanada_Quick_50k_Concava.txt","w");	
				}
				if(arq == 3){
				f = fopen("Lista_Ordanada_Quick_100k_Concava.txt","w");	
				}
	   		}
	   		if(tipo == 3){
				if(arq == 1){
				f = fopen("Lista_Ordanada_Quick_5k_Convexa.txt","w");	
				}
				if(arq == 2){
				f = fopen("Lista_Ordanada_Quick_50k_Convexa.txt","w");	
				}
				if(arq == 3){
				f = fopen("Lista_Ordanada_Quick_100k_Convexa.txt","w");	
				}
	   		}
            
            for (int j =0; j < qtd; j++ ){
            	fprintf(f,"\n %d ",arr[j]);
			}
			fclose(f);
			
            return 0; 
            break;
        }
        default:
            printf("Entrada invalida!\n");                
        } 
        system("pause"); 
        system("cls");
    }while(op != 4);
    return 0;
}


