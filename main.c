#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <windows.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
	
	

int main(int argc, char *argv[]) {
	
	char Secim;
    char AranacakIsim[41];
    int NumaraAra=-1,a;
    char SilinecekIsim[40];
    char aranan;
    
    menu();
    
    do
    {
        printf("\n\t\t Seciminiz:\t ");
        Secim = putch(getch());// scanf ile yapıcagım işi kabul etmediği için kullandım
		//getch Klavyeden bir karakteri kabul eder ve hemen görüntüler.
		//putch () monitör gibi standart çıktı aygıtını kullanan tüm alfasayısalkarakterleri
		// görüntülemek için kullanılır. Bu fonksiyon bir seferde tek karakter gösterir.
 
        switch (Secim)
        {
            case '1':
                if (KisiEkle()==0)
                { 
                    printf("\n\t\t Telefon Numarasi Basariyla Eklendi.");
                }else{
                    printf("\n\t\t HATA: Telefon Numarasi Eklenemedi!");
                }
                break;
            case '2':
                if (RehberiGoruntule()==0)
                {
                    printf("\n\t\t Telefonlar Basariyla Listelendi.");
                }else{
                    printf("\n\t\t HATA : Telefon Numaralari Listelenemedi!");
                }
                break;
            case '3':
                printf("\n\t\t Aranacak Ismi Giriniz(max 40 karakter):");
                scanf("\t\t%s",AranacakIsim);
 
                NumaraAra = KisiAra(AranacakIsim);
                if (NumaraAra == 0)
                { 
                    printf("\n\t\t Aranan Isim Kayitlarda Bulunamadi.");
                }else {
                    if(NumaraAra > 0)
                    printf("\n\t\t Toplam %d Kayit Bulundu.",NumaraAra);
                else
                    printf("\n\t\t HATA : Numara Aranamadi!");
                }
                break;
            case '4':
                printf("\n\t\t Programi Kullandiginiz İcin Tesekkurler.");
                return 0;
                break;
            default:
                printf("\n\t\t Lutfen 1-4 Arasinda Bir Secim Yapiniz.");
        }
    }while(Secim!=4);

	return 0;
}
