#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <windows.h>
#include "library.h"


struct Kisi
	{
    char isim[41];
    char soyisim[41];
    int tel[11];
	};
	
	void menu()
	{
	system("color B");
    printf("\t\t\t\t\t--------------------------------------\n");
    printf("\t\t\t\t\t**************************************\n");
    printf("\t\t\t\t\t*   TELEFON REHBERINE HOSGELDINIZ!   *\n");
    printf("\t\t\t\t\t*                                    *\n");
	printf("\t\t\t\t\t*      Lutfen Yapmak Istediginiz     *\n");
    printf("\t\t\t\t\t*      Islem Numarasini Giriniz.     *\n");
    printf("\t\t\t\t\t*                                    *\n");
    printf("\t\t\t\t\t*     1. Yeni Kisi Ekle              *\n");
    printf("\t\t\t\t\t*     2. Kayitli Kisileri Listele    *\n");
    printf("\t\t\t\t\t*     3. Kisi Aramasi Yap            *\n");
    printf("\t\t\t\t\t*     4. Cikis                       *\n");
	printf("\t\t\t\t\t**************************************\n");
    printf("\t\t\t\t\t--------------------------------------\n");
	}

int KisiEkle()
	{
		struct Kisi YeniKayit;
		FILE *rehber;
		
		//Rehber dosyasının açılıp açılmadıgını kontrol ediyor veya mantıksal eleme yaptım											
		if((rehber = fopen("D:\\rehber.txt","a+"))==NULL){
        return 0;//a da hem okur hem yazar			
    }
    	printf("\n\t\tYeni Kisi Kaydi Acmak Uzeresiniz..\n\n");
    
		printf("\n\t\tKaydedilecek Kisi Ismi Giriniz(max 40 karakter): ");
    	scanf("\t\t%s",YeniKayit.isim);
 
    	printf("\n\t\tKaydedilecek Kisi Soyismi Giriniz(max 40 karakter): ");
    	scanf("\t\t%s",YeniKayit.soyisim);
 
    	printf("\n\t\tKaydedilecek Kisi Numarasini Giriniz(max 10 karakter): ");
    	scanf("\t\t%s",YeniKayit.tel);
 
    	fprintf(rehber, "\n\t\t%s\t%s\t%s",YeniKayit.isim, YeniKayit.soyisim, YeniKayit.tel);
 
    	fclose(rehber);
    return 0;
}
int RehberiGoruntule()
{
    
   
    FILE *rehber;
    struct Kisi Rehber;	 
    if((rehber = fopen("D:\\rehber.txt","r"))==NULL){
        return 0;//r de sadece dosyayı okur
    }
 
    printf("\n\n\t\tisim\t\t\t\t\tsoyisim\t\t\t\t\ttel\n");
    printf("\t\t----\t\t\t\t\t-----\t\t\t\t\t---\n\n"); //tablo oluşturmak için üsttekine göre bosluk bıraktık
    

 	
    while(!feof(rehber)) //feof ile dosya sonuna kadar okuma islemi gerceklestirdim
    {
        fscanf(rehber,"%s%s%s",&Rehber.isim, &Rehber.soyisim, &Rehber.tel);
        printf("\t\t%s\t\t\t",Rehber.isim);//ekrana 1 tab arayla isim soyisim tel yaz
        printf("\t\t%s\t\t\t",Rehber.soyisim);
        printf("\t\t%s\n",Rehber.tel);
    }
 
    fclose(rehber);//veri tabanını kapat
    return 0;
}
int KisiAra (char *aranan)
{
    
    // dosyaya ac:
    FILE *rehber;
    struct Kisi Rehber;
    int bulunan=0;
 
    if((rehber=fopen("D:\\rehber.txt","r"))==NULL){
        return 0;
    }
 
    
    while(!feof(rehber))
    {
        fscanf(rehber, "%s%s%s", &Rehber.isim, &Rehber.soyisim, &Rehber.tel);
 
        if(!strcmp(aranan, Rehber.isim))//Fonksiyon s1 ve s2 adreslerindeki yazıları karşılaştırır.
		//Eğer s1 adresindeki yazı s2 adresindeki yazıdan daha büyükse fonksiyon 0'dan büyük bir 
		//değere, s1 adresindeki yazı s2 adresindeki yazıdan daha küçükse 0’dan küçük bir değere, 
		//yazılar eşit ise fonksiyon 0 değerine geri döner. 
        {
            printf("\t\t%s\t\t\t", Rehber.isim);
            printf("\t\t%s\t\t\t", Rehber.soyisim);
            printf("\t\t%s\n",Rehber.tel);
        bulunan++;
        }
    }
 
    fclose(rehber);
    return bulunan;//return integer dondurdugu için bulunan=0 dır bu nedenle döndürür.
}
