/******************************************************************************

                            Online C Debugger.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Debug" button to debug program.

*******************************************************************************/
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include<conio.h>
#define MAX_YR  9999
#define MIN_YR  1900
#define MAX_SIZE_USER_NAME 30
#define MAX_SIZE_PASSWORD  20
#define FILE_NAME  "Abed Rayen"
// Macro related to the books info
#define MAX_BOOK_NAME   50
#define MAX_AUTHOR_NAME 50
#define MAX_STUDENT_NAME 50
#define MAX_STUDENT_ADDRESS 300
#define FILE_HEADER_SIZE  sizeof(sFileHeader)
int k=-1, l=-1,f=-1;
typedef struct {
	int jj,mm,aa;
}date;
date toujours;
typedef struct {
char titre[30],nom_aut[50],nom_ed[50];
int localisation,code,nbre,type,freq;
date d_pub,d_ed;
} document;
document t[50];
typedef struct {
char nom[30],prenom[30],adresse[100];
int code_adh,type,nbr_emp;
} adher;
adher ta[50];
typedef struct{
	int code_livre,code_aherente,encours;
	date d_emp,d_limite;
} fiche;
fiche tf[50];
void remplir_adh(adher ta[],int i){
	char ch[50]; int x;
	ta[i].code_adh=ta[i-1].code_adh+1;
printf("donner le  nom de l'adherente\t"); gets(ch); fgets( ta[i].nom, 100, stdin);
printf("donner le  prenom de l'adherente\t");  fgets( ta[i].prenom , 100 , stdin);    
printf("donner le  adresse de l'adherente\t");  fgets( ta[i].adresse ,  100, stdin);
printf("choisi le type:\n1)etudiant\n2)enseignant\n3)visiteur\t"); scanf("%d",  &ta[i].type);
printf("\nAjout fait Avec sucess!%d \n",i);

}
void modification_adh(){
	int y,z; char ch[50];
printf("\ndonner le code de adherente qui vous souhaitez modifier\n");
scanf("%d", &y);
printf("vous souhaitez modifier:\n1) le nom?\n2) le prenom?\n3) le adresse?\n4) le type?");
scanf("%d", &z);
  switch(z){
  	          case 1:printf("donner le nouveaux nom de adherente\t"); gets(ch); fgets( ta[y-1].nom, 100, stdin); break;
  	          case 2:printf("donner le nouveaux prenom de adherente\t"); gets(ch); fgets( ta[y-1].prenom, 100, stdin); break;
  	          case 3:printf("donner le nouveaux adresse de adherente\t"); gets(ch); fgets( ta[y-1].adresse, 100, stdin); break;
  	          case 4:printf("choisir un nouveau type :\n1)etudiant\n2)enseignant\n3)visiteur\n"); scanf("%d", &z); ta[y-1].type=z;
              }
        printf("\nmodification fait avec sucess!\n");
}
void   afficher_adh(  adher ta[],int n){
int i,x; char ch[50]; 

for(i=0;i<=n;i++){
x=ta[i].type;
if(x==1){strcpy(ch,"etudiant");}else if(x==2) {strcpy(ch,"enseignat");} else{strcpy(ch,"visiteur");}


printf("code_adh:%d\n\nnom:%s\nprenom:%s\nadresse:%s\ntype:%s\nnombre de document emprumente:%d\n*************************\n",ta[i].code_adh,ta[i].nom,ta[i].prenom,ta[i].adresse,ch,ta[i].nbr_emp); }
 }
  void supprimer_adh(adher ta[],int s){
int i;
for (i=s;i<l;i++){
ta[i].code_adh=ta[i+1].code_adh;
strcpy(ta[i].nom,ta[i+1].nom);
strcpy(ta[i].prenom,ta[i+1].prenom);
strcpy(ta[i].adresse,ta[i+1].adresse);
ta[i].type=ta[i+1].type;
}
l--;
}
void suppression_adh(){int y; int p=-1;
printf("\ndonner le code de adherente qui vous souhaitez supprimer\n");
scanf("%d", &y);
do{
	p++;
	printf("\n***%d***%d\n",ta[p].code_adh,y);
}while((p<l)&&(ta[p].code_adh!=y));
supprimer_adh(ta,p);
printf(" suppression effectue avec sucess ! %d \n",p); main();
}
void chercher_adh(){
		int c,code,i,x,test=0;char ch[50],ch1[50];
	printf("vous souhaitez chercher selon le : \n1)identifieur?\n2)nom?\n3)prenom?\n4)adresse\n5)type?\n");
	scanf("%d", &c);
	switch(c){case 1:printf("donner le code de l'adherent qui vous souhaitez chercher:\n");scanf("%d", &code);
	          	for(i=0;i<=l;i++){if(ta[i].code_adh==code){x=ta[i].type;
                if(x==1){strcpy(ch1,"etudiant");}else if(x==2) {strcpy(ch1,"enseignat");} else{strcpy(ch1,"visiteur");}
                 printf("code_adh:%d\n\nnom:%s\nprenom:%s\nadresse:%s\ntype:%s\n*************************\n",ta[i].code_adh,ta[i].nom,ta[i].prenom,ta[i].adresse,ch1);
                        break;	}
                           }if(i==l+1) { printf("il n'y pas des resultats correspondants a votre recherche \n"); } break;
             case 2:printf("donner le nom de l'adherent qui vous souhaitez chercher:\n");gets(ch);fgets(ch, 100, stdin);
		             for(i=0;i<=l;i++){if(strcmp(ta[i].nom,ch)==0){  test=1;x=ta[i].type;
                       if(x==1){strcpy(ch1,"etudiant");}else if(x==2) {strcpy(ch1,"enseignant");} else{strcpy(ch1,"visiteur");}
                        printf("code_adh:%d\n\nnom:%s\nprenom:%s\nadresse:%s\ntype:%s\n*************************\n",ta[i].code_adh,ta[i].nom,ta[i].prenom,ta[i].adresse,ch1);}
                        	}if(test==0) {printf("il n'y pas des resultats correspondants a votre recherche \n"); 
                                         } break;
             case 3:printf("donner le prenom de l'adherent qui vous souhaitez chercher:\n");gets(ch);fgets(ch, 100, stdin);
		             for(i=0;i<=l;i++){if(strcmp(ta[i].prenom,ch)==0){ test=1;x=ta[i].type;
                       if(x==1){strcpy(ch1,"etudiant");}else if(x==2) {strcpy(ch1,"enseignant");} else{strcpy(ch1,"visiteur");}
                        printf("code_adh:%d\n\nnom:%s\nprenom:%s\nadresse:%s\ntype:%s\n*************************\n",ta[i].code_adh,ta[i].nom,ta[i].prenom,ta[i].adresse,ch1);}
                        	}if(test==0) {printf("il n'y pas des resultats correspondants a votre recherche \n"); 
                                         }break;
             case 4:printf("donner l'adresse de l'adherent qui vous souhaitez chercher:\n");gets(ch);fgets(ch, 100, stdin);
		             for(i=0;i<=l;i++){if(strcmp(ta[i].adresse,ch)==0){ test=1;x=ta[i].type;
                       if(x==1){strcpy(ch1,"etudiant");}else if(x==2) {strcpy(ch1,"enseignant");} else{strcpy(ch1,"visiteur");}
                        printf("code_adh:%d\n\nnom:%s\nprenom:%s\nadresse:%s\ntype:%s\n*************************\n",ta[i].code_adh,ta[i].nom,ta[i].prenom,ta[i].adresse,ch1);}
                        	}if(test==0) {printf("il n'y pas des resultats correspondants a votre recherche \n"); 
                                         }break;
             case 5:printf("chercher tous les:\n1)etudiants?\n2)enseignant?\n3)visiteur?"); scanf("%d", &code);
                        for(i=0;i<=l;i++){
                        	if(ta[i].type!=code){ continue ;}
                        	test=1;x=ta[i].type;
                        	if(x==1){strcpy(ch1,"etudiant");}else if(x==2) {strcpy(ch1,"enseignant");} else{strcpy(ch1,"visiteur");}
                        printf("code_adh:%d\n\nnom:%s\nprenom:%s\nadresse:%s\ntype:%s\n*************************\n",ta[i].code_adh,ta[i].nom,ta[i].prenom,ta[i].adresse,ch1);}
                        	if(test==0) {printf("il n'y pas des resultats correspondants a votre recherche \n"); 
                                         }break;}
				                         }
             
                                         
                                              
 void gerer_adh(){
	int x;
	printf("1) afficher tous les adherentes\n2) supprimer un adherente\n3) chercher un adherente\n4) modifier les proprietes d'un adherente\n5) retour au menu precedent\n ");
	scanf("%d", &x);
	switch(x){
	case 1:afficher_adh(ta,l); break;
	case 2:suppression_adh(); break; 
	case 3:chercher_adh(); break;
	case 4:modification_adh(); break;
	case 5:menu();break;
} }
/*******************gestion emprunt**************************/
void  datedate(int d,int m,int y,int days)
{
  int flag=0,temp=0;
  // variable days must have positive integer value
 
  while(flag <days)
  {
     (d) ++;
     if( (m) == 4 || (m) == 6 || (m) == 9 || (m) == 11)
      {
           temp=30;
      }
     else if( (m) == 2)
      {
           if( (y) % 400 == 0 || ( (y) % 100 != 0 && (y) % 4 == 0 ))

               temp = 29;
           else
               temp = 28;
      }
     else
          temp=31;

     if( (d) > temp)
      {
          (m) ++;
          (d) = 1;
      }
     if( (m) == 13)
      {
          (y) ++;
          (m) = 1;
      }
     flag++;
 }  // end of while
tf[f].d_limite.jj=d; tf[f].d_limite.mm=m; tf[f].d_limite.aa=y;
} 
void dev(){  tf[f].d_emp.aa=toujours.aa; tf[f].d_emp.mm=toujours.mm; tf[f].d_emp.jj=toujours.jj; }
	
	

void test_emp(int a,int b,fiche tf[]){
	int i,s,emp,tp,j;
	for(i=0;i<=k;i++){
		if(t[i].code==a){s=t[i].nbre; break;} 
	}
	if(s==0){printf("\nil ne reste pas de copie pour ce document\n "); 
	} else{
	
	for(j=0;j<=l;j++){
		if(ta[j].code_adh==b){ emp=ta[j].nbr_emp; tp=ta[j].type; break;} 
		
	}switch(tp){ 
		            case 1:if(emp<2){ f++; tf[f].code_aherente=b ; tf[f].code_livre=a; dev(); datedate(tf[f].d_emp.jj,tf[f].d_emp.mm,tf[f].d_emp.aa,7);  ta[j].nbr_emp++; t[i].nbre--;} else printf("\nnombre maximale d'emprunt est atteint pour ce adherente\n"); break;
					case 2:if(emp<4){ f++; tf[f].code_aherente=b ; tf[f].code_livre=a; dev(); datedate(tf[f].d_emp.jj,tf[f].d_emp.mm,tf[f].d_emp.aa,21);  ta[j].nbr_emp++; t[i].nbre--;} else printf("\nnombre maximale d'emprunt est atteint pour ce adherente\n"); break;             
				    case 3:if(emp<1){ f++; tf[f].code_aherente=b ; tf[f].code_livre=a; dev(); datedate(tf[f].d_emp.jj,tf[f].d_emp.mm,tf[f].d_emp.aa,7);  ta[j].nbr_emp++; t[i].nbre--;}  else printf("\nnombre maximale d'emprunt est atteint pour ce adherente\n"); break;                                 	                         
		
		                         }
		                         printf("vous avez emprunter le document de code:%d a l'utilisateur de code:%d\n",a,b);
	
}
}
void emprunter(){
    headMessage("Emprunter");
	int a,b;
	printf("donner le code de document qui vous voulez emprunter\n"); scanf("%d", &a);
	printf("donner le code de l'adherente qui souhaite emprunter un document\n"); scanf("%d", &b);
    test_emp(a,b,tf);    
	printf("Emprunt effectuè avec succès....\n");
	
}
void afficher_emp(){
	int i;
	if(f==-1){ printf("il n'y pas des emprunte fait jusqu'a maintenant\n");}
	else 
	{
		for(i=0;i<=f;i++){
			printf("code_adherente:%d\ncode_livre:%d\ndate d'emprunt:%d/%d/%d\ndate limite:%d/%d/%d\n*******************************\n",tf[i].code_aherente,tf[i].code_livre,tf[i].d_emp.jj,tf[i].d_emp.mm,tf[i].d_emp.aa,tf[i].d_limite.jj,tf[i].d_limite.mm,tf[i].d_limite.aa);
	                                 	}
	}
}
void retourner(){
	int a,b,j;
	printf("donner le code de document a retourner\n"); scanf("%d", &a);
	printf("donner le code de l'adherente qui souhaite retourner un document\n"); scanf("%d", &b);
	for(j=0;j<=l;j++){
		if(ta[j].code_adh==b){ ta[j].nbr_emp--; break;} 
         }
    	for(j=0;j<=l;j++){
		if(t[j].code==a){ t[j].nbre++; break;} 
         }
         for(j=0;j<=f;j++){
		if((tf[j].code_livre==a)&&(tf[j].code_aherente==b)&&(tf[j].encours!=1)){ tf[j].encours=1; break;} 
         }
		 }
int compare_dates(int j1, int m1, int a1, int j2, int m2, int a2){
if(a2>a1)	    { return 1;} else if(a2<a1) return 0;
if(m2>m1)       {  return 1;} else if(a2<a1) return 0;
if(j2>j1)       { return 1;}  else if(a2<a1) return 0;
                 return 0;
}
void retard(){
	int i,j;
	for(i=0;i<=f;i++){
		if(tf[i].encours==0&&compare_dates(toujours.jj,toujours.mm,toujours.aa,tf[i].d_limite.jj,tf[i].d_limite.mm,tf[i].d_limite.aa)==0){ j++;
		printf("code_adherente:%d\ncode_livre:%d\ndate d'emprunt:%d/%d/%d\ndate limite:%d/%d/%d\n*******************************\n",tf[i].code_aherente,tf[i].code_livre,tf[i].d_emp.jj,tf[i].d_emp.mm,tf[i].d_emp.aa,tf[i].d_limite.jj,tf[i].d_limite.mm,tf[i].d_limite.aa);
		}}
		if(j==0) printf("il n'y pas des retardataires");
	}
	void gerer_empr(){
	int x;
	printf("1) Emprunter\n2) Afficher les emprints\n3) Retourner l'emprint\n4) Afficher les retards\n5) retour au menu precedent\n ");
	scanf("%d", &x);
	switch(x){
	case 1:emprunter();main();
	case 2:afficher_emp(); main();
	case 3:retourner(); main();
	case 4:retard(); main();
	case 5:menu();break;
} }
		
//structure to store date
typedef struct
{
    int yyyy;
    int mm;
    int dd;
} Date;
typedef struct
{
    char username[MAX_SIZE_USER_NAME];
    char password[MAX_SIZE_PASSWORD];
    char CIN[50];
} sFileHeader;
typedef struct// to call in program
{
    unsigned int books_id; // declare the integer data type
    char bookName[MAX_BOOK_NAME];// declare the character data type
    char authorName[MAX_AUTHOR_NAME];// declare the charecter data type
    char studentName[MAX_STUDENT_NAME];// declare the character data type
    char studentAddr[MAX_STUDENT_ADDRESS];// declare the character data type
    Date bookIssueDate;// declare the integer data type
} s_BooksInfo;
void printMessageCenter(const char* message)
{
    int len =0;
    int pos = 0;
    //calculate how many space need to print
    len = (78 - strlen(message))/2;
    printf("\t\t\t");
    for(pos =0 ; pos < len ; pos++)
    {
        //print space
        printf(" ");
    }
    //print message
    printf("%s",message);
}
void headMessage(const char *message)
{
    //system("clear");
    printf("\t\t\t###########################################################################");
    printf("\n\t\t\t############                                                   ############");
    printf("\n\t\t\t############      Mini-Projet Gestion de bibliotheque en C     ############");
    printf("\n\t\t\t############                                                   ############");
    printf("\n\t\t\t###########################################################################");
    printf("\n\t\t\t---------------------------------------------------------------------------\n");
    printMessageCenter(message);
    printf("\n\t\t\t----------------------------------------------------------------------------");
}
void welcomeMessage()
{
    headMessage("Abed Rayen");
    printf("\n\n\n\n\n");
    printf("\n\t\t\t  **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**\n");
    printf("\n\t\t\t  **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**\n");
    printf("\n\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
    printf("\n\t\t\t        =                BIENVENUE                   =");
    printf("\n\t\t\t        =                   DANS                     =");
     printf("\n\t\t\t       =                   EPI                      =");
    printf("\n\t\t\t        =                 LIBRARY                   =");
    printf("\n\t\t\t        =               MANAGEMENT                  =");
    printf("\n\t\t\t        =                 SYSTEM                    =");
    printf("\n\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
    printf("\n\t\t\t  **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**\n");
    printf("\n\t\t\t  **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**\n");
    printf("\n\n\n\t\t\tPress any key to go to main menu.....");
    getchar();
}
int isNameValid(const char *name)
{
    int validName = 1;
    int len = 0;
    int index = 0;
    len = strlen(name);
    for(index =0; index <len ; ++index)
    {
        if(!(isalpha(name[index])) && (name[index] != '\n') && (name[index] != ' '))
        {
            validName = 0;
            break;
        }
    }
    return validName;
}
// Function to check leap year.
//Function returns 1 if leap year
int  IsLeapYear(int year)
{
    return (((year % 4 == 0) &&
             (year % 100 != 0)) ||
            (year % 400 == 0));
}
// returns 1 if given date is valid.
int isValidDate(Date *validDate)
{
    //check range of year,month and day
    if (validDate->yyyy > MAX_YR ||
            validDate->yyyy < MIN_YR)
        return 0;
    if (validDate->mm < 1 || validDate->mm > 12)
        return 0;
    if (validDate->dd < 1 || validDate->dd > 31)
        return 0;
    //Handle feb days in leap year
    if (validDate->mm == 2)
    {
        if (IsLeapYear(validDate->yyyy))
            return (validDate->dd <= 29);
        else
            return (validDate->dd <= 28);
    }
    //handle months which has only 30 days
    if (validDate->mm == 4 || validDate->mm == 6 ||
            validDate->mm == 9 || validDate->mm == 11)
        return (validDate->dd <= 30);
    return 1;
}
// Add books in list
void addBookInDataBase()
{
    int days;
    s_BooksInfo addBookInfoInDataBase = {0};
    FILE *fp = NULL;
    int status = 0;
    fp = fopen(FILE_NAME,"ab+");
    if(fp == NULL)
    {
        printf("File is not opened\n");
        exit(1);
    }
    headMessage("AJOUTER UN LIVRE");
    printf("\n\n\t\t\tENTER YOUR DETAILS BELOW:");
    printf("\n\t\t\t---------------------------------------------------------------------------\n");
    printf("\n\t\t\tLIVRE ID NO  = ");
    fflush(stdin);
    scanf("%u",&addBookInfoInDataBase.books_id);
    do
    {
        printf("\n\t\t\tLIVRE NOM  = ");
        fflush(stdin);
        fgets(addBookInfoInDataBase.bookName,MAX_BOOK_NAME,stdin);
        status = isNameValid(addBookInfoInDataBase.bookName);
        if (!status)
        {
            printf("\n\t\t\tName contain invalid character. Please enter again.");
        }
    }
    while(!status);
    do
    {
        printf("\n\t\t\tNOM D'ECRIVAIN  = ");
        fflush(stdin);
        fgets(addBookInfoInDataBase.authorName,MAX_AUTHOR_NAME,stdin);
        status = isNameValid(addBookInfoInDataBase.authorName);
        if (!status)
        {
            printf("\n\t\t\tName contain invalid character. Please enter again.");
        }
    }
    while(!status);
    do
    {
        printf("\n\t\t\tNOM D'ETUDIANT  = ");
        fflush(stdin);
        fgets(addBookInfoInDataBase.studentName,MAX_STUDENT_NAME,stdin);
        status = isNameValid(addBookInfoInDataBase.studentName);
        if (!status)
        {
            printf("\n\t\t\tName contain invalid character. Please enter again.");
        }
    }
    while(!status);
    do
    {
        //get date year,month and day from user
        printf("\n\t\t\tEnter date in format (day/month/year): ");
        scanf("%d/%d/%d",&addBookInfoInDataBase.bookIssueDate.dd,&addBookInfoInDataBase.bookIssueDate.mm,&addBookInfoInDataBase.bookIssueDate.yyyy);
        //check date validity
        status = isValidDate(&addBookInfoInDataBase.bookIssueDate);
        if (!status)
        {
            printf("\n\t\t\tPlease enter a valid date.\n");
        }
    }
    while(!status);
    fwrite(&addBookInfoInDataBase,sizeof(addBookInfoInDataBase), 1, fp);
    fclose(fp);
}
// search books
void searchBooks()
{
    int found = 0;
    char bookName[MAX_BOOK_NAME] = {0};
    s_BooksInfo addBookInfoInDataBase = {0};
    FILE *fp = NULL;
    int status = 0;
    fp = fopen(FILE_NAME,"rb");
    if(fp == NULL)
    {
        printf("\n\t\t\tFile is not opened\n");
        exit(1);
    }
    headMessage("RECHERCHE D'UN LIVRE");
    //put the control on books detail
    if (fseek(fp,FILE_HEADER_SIZE,SEEK_SET) != 0)
    {
        fclose(fp);
        printf("\n\t\t\tFacing issue while reading file\n");
        exit(1);
    }
    printf("\n\n\t\t\tEntrer le nom du livre a chercher:");
    fflush(stdin);
    fgets(bookName,MAX_BOOK_NAME,stdin);
    while (fread (&addBookInfoInDataBase, sizeof(addBookInfoInDataBase), 1, fp))
    {
        if(!strcmp(addBookInfoInDataBase.bookName, bookName))
        {
            found = 1;
            break;
        }
    }
    if(found)
    {
        printf("\n\t\t\tBook id = %u\n",addBookInfoInDataBase.books_id);
        printf("\t\t\tBook name = %s",addBookInfoInDataBase.bookName);
        printf("\t\t\tBook authorName = %s",addBookInfoInDataBase.authorName);
        printf("\t\t\tBook issue date(day/month/year) =  (%d/%d/%d)",addBookInfoInDataBase.bookIssueDate.dd,
               addBookInfoInDataBase.bookIssueDate.mm, addBookInfoInDataBase.bookIssueDate.yyyy);
    }
    else
    {
        printf("\n\t\t\tNo Record");
    }
    fclose(fp);
    printf("\n\n\n\t\t\tPress any key to go to main menu.....");
    getchar();
}
// v books function
void viewBooks()
{
    int found = 0;
    char bookName[MAX_BOOK_NAME] = {0};
    s_BooksInfo addBookInfoInDataBase = {0};
    FILE *fp = NULL;
    int status = 0;
    unsigned int countBook = 1;
   
    fp = fopen(FILE_NAME,"rb");
    if(fp == NULL)
    {
        printf("File is not opened\n");
        exit(1);
    }
    if (fseek(fp,FILE_HEADER_SIZE,SEEK_SET) != 0)
    {
        fclose(fp);
        printf("Facing issue while reading file\n");
        exit(1);
    }
    while (fread (&addBookInfoInDataBase, sizeof(addBookInfoInDataBase), 1, fp))
    {
        printf("\n\t\t\tBook Count = %d\n\n",countBook);
        printf("\t\t\tBook id = %u",addBookInfoInDataBase.books_id);
        printf("\n\t\t\tBook name = %s",addBookInfoInDataBase.bookName);
        printf("\t\t\tBook authorName = %s",addBookInfoInDataBase.authorName);
        printf("\t\t\tBook issue date(day/month/year) =  (%d/%d/%d)\n\n",addBookInfoInDataBase.bookIssueDate.dd,
               addBookInfoInDataBase.bookIssueDate.mm, addBookInfoInDataBase.bookIssueDate.yyyy);
        found = 1;
        ++countBook;
    }
    fclose(fp);
    if(!found)
    {
        printf("\n\t\t\tNo Record");
    }
    printf("\n\n\t\t\tPress any key to go to main menu.....");
    fflush(stdin);
    getchar();
}
// delete function
void deleteBooks()
{
    int found = 0;
    int bookDelete = 0;
    sFileHeader fileHeaderInfo = {0};
    char bookName[MAX_BOOK_NAME] = {0};
    s_BooksInfo addBookInfoInDataBase = {0};
    FILE *fp = NULL;
    FILE *tmpFp = NULL;
    int status = 0;
    headMessage("Delete Books Details");
    fp = fopen(FILE_NAME,"rb");
    if(fp == NULL)
    {
        printf("File is not opened\n");
        exit(1);
    }
    tmpFp = fopen("tmp.bin","wb");
    if(tmpFp == NULL)
    {
        fclose(fp);
        printf("File is not opened\n");
        exit(1);
    }
    fread (&fileHeaderInfo,FILE_HEADER_SIZE, 1, fp);
    fwrite(&fileHeaderInfo,FILE_HEADER_SIZE, 1, tmpFp);
    printf("\n\t\t\tEnter Book ID NO. for delete:");
    scanf("%d",&bookDelete);
    while (fread (&addBookInfoInDataBase, sizeof(addBookInfoInDataBase), 1, fp))
    {
        if(addBookInfoInDataBase.books_id != bookDelete)
        {
            fwrite(&addBookInfoInDataBase,sizeof(addBookInfoInDataBase), 1, tmpFp);
        }
        else
        {
            found = 1;
        }
    }
    (found)? printf("\n\t\t\tRecord deleted successfully....."):printf("\n\t\t\tRecord not found");
    fclose(fp);
    fclose(tmpFp);
    remove(FILE_NAME);
    rename("tmp.bin",FILE_NAME);
}
void updateCredential(void)
{
    sFileHeader fileHeaderInfo = {0};
    FILE *fp = NULL;
    unsigned char userName[MAX_SIZE_USER_NAME] = {0};
    unsigned char password[MAX_SIZE_PASSWORD] = {0};
    headMessage("Update Credential");
    fp = fopen(FILE_NAME,"rb+");
    if(fp == NULL)
    {
        printf("File is not opened\n");
        exit(1);
    }
    fread (&fileHeaderInfo,FILE_HEADER_SIZE, 1, fp);
    if (fseek(fp,0,SEEK_SET) != 0)
    {
        fclose(fp);
        printf("\n\t\t\tFacing issue while updating password\n");
        exit(1);
    }
    printf("\n\n\t\t\tNew Username:");
    fflush(stdin);
    fgets(userName,MAX_SIZE_USER_NAME,stdin);
    printf("\n\n\t\t\tNew Password:");
    fflush(stdin);
    fgets(password,MAX_SIZE_PASSWORD,stdin);
    strncpy(fileHeaderInfo.username,userName,sizeof(userName));
    strncpy(fileHeaderInfo.password,password,sizeof(password));
    fwrite(&fileHeaderInfo,FILE_HEADER_SIZE, 1, fp);
    fclose(fp);
    printf("\n\t\t\tYour Password has been changed successfully");
    printf("\n\t\t\ttLogin Again:");
    fflush(stdin);
    getchar();
    exit(1);
}
void menu()
{
    int choice = 0;
    do
    {
        headMessage("MAIN MENU");
        printf("\n\n\n\t\t\t1.Add Books");
        printf("\n\t\t\t2.Search Books");
        printf("\n\t\t\t3.View Books");
        printf("\n\t\t\t4.Delete Book");
        printf("\n\t\t\t5.Update Password");
        printf("\n\t\t\t6.Update Adherant");
        printf("\n\t\t\t7.Add Adherant");
        printf("\n\t\t\t8.Emprunt management");
        printf("\n\t\t\t0.Exit");
        printf("\n\n\n\t\t\tEnter choice => ");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            addBookInDataBase();
            break;
        case 2:
            searchBooks();
            break ;
        case 3:
            viewBooks();
            break;
        case 4:
            deleteBooks();
            break;
        case 5:
            updateCredential();
            break;
        case 6:    
            gerer_adh();
            break;
        case 7:    
            remplir_adh(ta,l);
            break;
        case 8:    
            gerer_empr();
            menu();
        case 0:
            printf("\n\n\n\t\t\t\tThank you!!!\n\n\n\n\n");
            exit(1);
            break;
        default:
            printf("\n\n\n\t\t\tINVALID INPUT!!! Try again...");
        }                                            //Switch Ended
    }
    while(choice!=0);                                        //Loop Ended
}
//login password
void login()
{
    unsigned char userName[MAX_SIZE_USER_NAME] = {0};
    unsigned char password[MAX_SIZE_PASSWORD] = {0};
    unsigned char CIN[50] = {0};
    int L=0;
    sFileHeader fileHeaderInfo = {0};
    FILE *fp = NULL;
    headMessage("Login");
    fp = fopen(FILE_NAME,"rb");
    if(fp == NULL)
    {
        printf("File is not opened\n");
        exit(1);
    }
    fread (&fileHeaderInfo,FILE_HEADER_SIZE, 1, fp);
    fclose(fp);
    do
    {  printf("\n\n\n\t\t\t\tCarte CIN:");
        fgets(CIN,MAX_SIZE_USER_NAME,stdin);
        printf("\n\n\n\t\t\t\tUtilisateur:");
        fgets(userName,MAX_SIZE_USER_NAME,stdin);
        printf("\n\t\t\t\tMot de passe:");
        fgets(password,MAX_SIZE_PASSWORD,stdin);
        if((!strcmp(userName,fileHeaderInfo.username)) && (!strcmp(password,fileHeaderInfo.password)))
        {
            menu();
        }
        else
        {
            printf("\t\t\t\tLogin Failed Enter Again Username & Password\n\n");
            L++;
        }
    }
    while(L<=3);
    if(L>3)
    {
        headMessage("Login Failed");
        printf("\t\t\t\tSorry,Unknown User.");
        getch();
        system("clear");
    }
}
int isFileExists(const char *path)
{
    // Try to open file
    FILE *fp = fopen(path, "rb");
    int status = 0;
    // If file does not exists
    if (fp != NULL)
    {
        status = 1;
        // File exists hence close file
        fclose(fp);
    }
    return status;
}
void init()
{
    FILE *fp = NULL;
    int status = 0;
    const char defaultUsername[] ="rayen\n";
    const char defaultPassword[] ="rayen123\n";
    sFileHeader fileHeaderInfo = {0};
    status = isFileExists(FILE_NAME);
    if(!status)
    {
        //create the binary file
        fp = fopen(FILE_NAME,"wb");
        if(fp != NULL)
        {
            //Copy default password
            strncpy(fileHeaderInfo.password,defaultPassword,sizeof(defaultPassword));
            strncpy(fileHeaderInfo.username,defaultUsername,sizeof(defaultUsername));
            fwrite(&fileHeaderInfo,FILE_HEADER_SIZE, 1, fp);
            fclose(fp);
        }
    }
}
int main()
{
    //init();
    welcomeMessage();
    login();
    return 0;
}
