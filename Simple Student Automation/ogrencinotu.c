#include <stdio.h>
#include <math.h>
#include <locale.h>

void DosyaOkuma(char dosyaadresi[]);

struct Ogrenci{
	int no;
	char ad[20];
	char soyad[20];
	int vize;
	int final;
	int odev1;
	int odev2;
	float ortalama;
}ogrenci[100];
	
int i=0;

int main(int argc, char *argv[]){
	setlocale(LC_ALL,"Turkish");
	
	char M;
	if(argv[1] != NULL){
		DosyaOkuma(argv[1]);
	}
	int a;
	int islem;
	while(1){
		
	    M=0;
		printf("\n\t\t MENÜ\n __________________________________ \n"
		" 1) ÖÐRENCÝ EKLEME \n 2) ÖÐRENCÝ ARAMA (NUMARA ÝLE) \n 3) RAPOR YAZDIR \n\n Lütfen Yapýlacak Ýþlemi Seçiniz=");
		scanf("%d",&islem);
		
		
		
		if(islem==1){
			int hata=0;
			int numara;
			while(1){
				printf(" __________________________________\n\n Öðrencinin Numarasý=");
				scanf("%d",&numara);
				
				
				for(a=0 ; a<100 ; a++){
					
					if(numara == ogrenci[a].no){
						printf("\n Girdiðiniz numaraya ait öðrenci bulunmaktadýr.\n\n");
						hata=1;
					}
					if(hata==1){
						break;
					}
				}
				if(hata==1){
					
					printf("\n\n Tekrar denemek için 't' tuþuna basýnýz.\n Menüye dönmek için 'm' tuþuna basýnýz.\n\n ");
					
					while(1){
						M=getch();	
						if(M==84 || M==116 || M==77 || M==109){
							break;
						}
					}
					if(M==84 || M==116){
						hata=0;
						continue;
					}
					if(M==77 || M==109){
						break;
					}
					
				}
				break;
			}
			if(hata==1){
				continue;
			}
			ogrenci[i].no=numara;
			printf(" Adý= ");
			scanf("%s",&ogrenci[i].ad);
			printf(" Soyadý= ");
			scanf("%s",&ogrenci[i].soyad);
			printf(" Vize Notu= ");
			scanf("%d",&ogrenci[i].vize);
			printf(" Final Notu= ");
			scanf("%d",&ogrenci[i].final);
			printf(" 1.Ödev Notu= ");
			scanf("%d",&ogrenci[i].odev1);
			printf(" 2.Ödev Notu= ");
			scanf("%d",&ogrenci[i].odev2);
		    ogrenci[i].ortalama = ogrenci[i].vize*0.25+ogrenci[i].final*0.4+ogrenci[i].odev1*0.15+ogrenci[i].odev2*0.20;
			printf(" Öðrencinin Dönem Sonu Notu= %.2f \n",ogrenci[i].ortalama);
			printf("\n __________________________________\n\n");
		i++;}
		
		
		
		if(islem==2){
			int girilen_numara;
			
			printf(" __________________________________\n\n Öðrenci numarasý=");
			scanf("%d",&girilen_numara);
			
			int hata=1;
			for(a=0 ; a<100 ; a++){
			
				if(girilen_numara == ogrenci[a].no){
					printf("\n Adý= %s\n",ogrenci[a].ad);
					printf(" Soyadý= %s\n",ogrenci[a].soyad);
					printf(" Vize Notu= %d\n",ogrenci[a].vize);
					printf(" Final Notu= %d\n",ogrenci[a].final);
					printf(" Odev1 Notu= %d\n",ogrenci[a].odev1);
					printf(" Odev2 Notu= %d\n",ogrenci[a].odev2);
					printf(" Öðrencinin Dönem Sonu Notu= %f \n",ogrenci[a].ortalama);
				hata =0;
				}
				if(hata==0)break;
			}
			if(hata==0){
				printf("\n\n Menüye dönmek için 'm' tuþuna basýnýz.\n\n ");
				while(1){
					M = getch();
					if(M==109 || M==77){
					break;
					}
				}		
				printf("\n __________________________________\n\n");
				continue;
			}
			
			printf("\n Kayýt bulunamadý. \n");
			printf("\n\n Menüye dönmek için 'm' tuþuna basýnýz.\n\n ");
			while(1){
				M = getch();
				if(M==109 || M==77){
					break;
				}
			}
			printf("\n __________________________________\n\n");
		}
		
		
		
		if(islem==3){
			float vize_ortalamasi = 0;
			float final_ortalamasi = 0;
			float odev1_ortalamasi = 0;
			float odev2_ortalamasi = 0;
			float donem_sonu_not_ortalamasi = 0;
			FILE *rapor;
			
			int kontrol = 0;
			do{
				vize_ortalamasi += ogrenci[kontrol].vize;
				final_ortalamasi += ogrenci[kontrol].final;
				odev1_ortalamasi += ogrenci[kontrol].odev1;
				odev2_ortalamasi += ogrenci[kontrol].odev2;
				donem_sonu_not_ortalamasi += ogrenci[kontrol].ortalama;
				kontrol++;	
			}while(kontrol<=i);
			
			vize_ortalamasi = vize_ortalamasi/i;
			final_ortalamasi = final_ortalamasi/i;
			odev1_ortalamasi = odev1_ortalamasi/i;
			odev2_ortalamasi = odev2_ortalamasi/i;
			donem_sonu_not_ortalamasi = donem_sonu_not_ortalamasi/i;
			
			
			
			
			rapor = fopen("DersRaporu.txt","w");
			
			fprintf(rapor,"Toplam Öðrenci Sayýsý=%.2d \n\nVize Ortalamasý=%.2f \nFinal Ortalamasý=%.2f"
			                 "\nÖdev1 Ortalamasý=%.2f \nÖdev2 Ortalamasý=%.2f \nDönem Sonu Not Ortalamasý=%.2f",
							 i,vize_ortalamasi,final_ortalamasi,odev1_ortalamasi,odev2_ortalamasi,donem_sonu_not_ortalamasi);
							 
			fclose(rapor);
			
			
			
			
		}
	}
}

void DosyaOkuma(char dosyaadresi[]){
	
	FILE *ogrencilistesi;
	ogrencilistesi=fopen(dosyaadresi,"a+");
	if(ogrencilistesi!=NULL){
		
		do{
			fscanf(ogrencilistesi,"%d %s %s %d %d %d %d",&ogrenci[i].no,&ogrenci[i].ad,&ogrenci[i].soyad,&ogrenci[i].vize,&ogrenci[i].final,&ogrenci[i].odev1,&ogrenci[i].odev2);
			ogrenci[i].ortalama = ogrenci[i].vize*0.25+ogrenci[i].final*0.4+ogrenci[i].odev1*0.15+ogrenci[i].odev2*0.20;
			i++;
		}while(!feof(ogrencilistesi));
		
		fclose(ogrencilistesi);
	}
}
