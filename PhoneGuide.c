/*
	Description: Telefon Rehberi / Phone Guide
	Copyright: Muhammet Fatih KESK�N
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

struct Kisi //bircok seyin tek bir kay?ta atanmas?n? sagl?yor.
{
    char isim[41];
    char soyisim[41];
    int tel[11];
};

void menuHazirla() //bos d?ng?d?r Altta yazanlar? ekrana yazd?r?yor sadece.
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
    printf("\t\t\t\t\t*     4. Kisi Sil                    *\n");
    printf("\t\t\t\t\t*     5. Cikis                       *\n");
    printf("\t\t\t\t\t**************************************\n");
    printf("\t\t\t\t\t--------------------------------------\n");
}

int KisiEkle()
{
    struct Kisi YeniKayit; //yeni kay?t yaparken yap?lacaklar tek de?i?kene atand?
    FILE *rehber;
    // dosyaya ac:
    //girilen deger veritaban?da esle?miyorsa(null) return 0 ile bir ?nceki int e d?ner.
    if ((rehber = fopen("D:\\rehber.txt", "a")) == NULL)
    {             //veri taban?ndakiler fopen();fprinf();
        return 0; //a da hem okur hem yazar				 //fgets();fclose();	fscanf();
    }
    printf("\n\t\tYeni Kisi Kaydi Acmak Uzeresiniz..\n\n");

    printf("\n\t\tKaydedilecek Kisi Ismi Giriniz(max 40 karakter): ");
    scanf("\t\t%s", YeniKayit.isim); //pointer tan?ml? olan de?i?knleri %s ile tan?mlad?k.int %d gibi

    printf("\n\t\tKaydedilecek Kisi Soyismi Giriniz(max 40 karakter): ");
    scanf("\t\t%s", YeniKayit.soyisim); //pointer tan?ml? olan de?i?knleri %s ile tan?mlad?k.int %d

    printf("\n\t\tKaydedilecek Kisi Numarasini Giriniz(max 10 karakter): ");
    scanf("\t\t%s", YeniKayit.tel); //pointer tan?ml? olan de?i?knleri %s ile tan?mlad?k.int %d

    fprintf(rehber, "\n\t\t%s\t%s\t%s", YeniKayit.isim, YeniKayit.soyisim, YeniKayit.tel);

    fclose(rehber);
    return 0;
}
int RehberiGoruntule()
{
    // dosyadaki tum telefonlari listele
    // dosyaya ac:
    FILE *rehber;
    struct Kisi Rehber; //return ?nteger d?d?r?r. yani girilen deger veritaban?da esle?miyorsa
    if ((rehber = fopen("D:\\rehber.txt", "r")) == NULL)
    {             //donguyu bir onceki integer a tekrar d?nd?r?r
        return 0; //r de sadece soyay? okur
    }

    printf("\n\n\t\tisim\t\t\tsoyisim\t\t\ttel\n"); //\t 4 kez bo?luk basar.=1tab.
    printf("\t\t----\t\t\t-----\t\t\t---\n\n");     //tablo olu?turmak i?in ?sttekine g?re bosluk b?rakt?k

    // dosya sonuna kadar tum verileri oku
    while (!feof(rehber)) //feof ile dosya sonuna kadar okuma islemi gerceklestirilebilir
    {
        fscanf(rehber, "%s%s%s", &Rehber.isim, &Rehber.soyisim, &Rehber.tel);
        printf("\t\t%s\t\t\t", Rehber.isim); //ekrana 1 tab arayla isim soyisim tel yaz
        printf("\t\t%s\t\t\t", Rehber.soyisim);
        printf("\t\t%s\n", Rehber.tel);
    }

    fclose(rehber); //veri taban?n? kapat
    return 0;
}
int KisiAra(char *aranan)
{
    // dosyadaki tum telefonlarini ara
    // dosyaya ac:
    FILE *rehber;
    struct Kisi Rehber;
    int bulunan = 0;

    if ((rehber = fopen("D:\\rehber.txt", "r")) == NULL)
    {
        return 0;
    }

    // dosya sonuna kadar tum verileri oku:
    while (!feof(rehber))
    {
        fscanf(rehber, "%s%s%s", &Rehber.isim, &Rehber.soyisim, &Rehber.tel);

        if (!strcmp(aranan, Rehber.isim))
        { // bbulundu!
            printf("\t\t%s\t\t\t", Rehber.isim);
            printf("\t\t%s\t\t\t", Rehber.soyisim);
            printf("\t\t%s\n", Rehber.tel);
            bulunan++;
        }
    }

    fclose(rehber);
    return bulunan; //return integer dondurdugu i?in bulunan=0 d?r bu nedenle d?nd?r?r.
}

int main(int argc, char *argv[])
{

    char Secim = '0';
    char AranacakIsim[41];
    int NumaraAra = -1;
    char SilinecekIsim[40];

    menuHazirla(); //?stteki telefon rehberine hosgeldiniz olan fonksiyonu ?ag?rd?k

    do
    {
        printf("\n\t\t Seciminiz:\t ");
        Secim = putch(getch()); // scanf ile yap?cag?m i?i kabul etmedi?i i?in kulland?m
                                //getch Klavyeden bir karakteri kabul eder ve hemen g?r?nt?ler.
                                //putch () monit?r gibi standart ??kt? ayg?t?n? kullanan t?m alfasay?salkarakterleri
                                // g?r?nt?lemek i?in kullan?l?r. Bu fonksiyon bir seferde tek karakter g?sterir.

        switch (Secim)
        {
        case '1':
            if (KisiEkle() == 0) // geri bildirim:
            {
                printf("\n\t\t Telefon Numarasi Basariyla Eklendi.");
            }
            else
            {
                printf("\n\t\t HATA: Telefon Numarasi Eklenemedi!");
            }
            break;
        case '2':
            if (RehberiGoruntule() == 0) // geri bildirim:
            {
                printf("\n\t\t Telefonlar Basariyla Listelendi.");
            }
            else
            {
                printf("\n\t\t HATA : Telefon Numaralari Listelenemedi!");
            }
            break;
        case '3':
            printf("\n\t\t Aranacak Ismi Giriniz(max 40 karakter):");
            scanf("\t\t%s", AranacakIsim);

            NumaraAra = KisiAra(AranacakIsim); // geri bildirim:
            if (NumaraAra == 0)
            {
                printf("\n\t\t Aranan Isim Kayitlarda Bulunamadi.");
            }
            else
            {
                if (NumaraAra > 0)
                    printf("\n\t\t Toplam %d Kayit Bulundu.", NumaraAra);
                else
                    printf("\n\t\t HATA : Numara Aranamadi!");
            }
            break;
        case '4':
            printf("\n\t\t Silinecek Kisi Adini Giriniz:\t");
            scanf("\t\t%s", &SilinecekIsim);
            if (SilinecekIsim != 0)
            {
                printf("\n\t\t Toplam %d Adet Kayit Bulundu.", SilinecekIsim);
                printf("\n\t\t Kisi Basariyla Silinmistir.");
            }
            else
                printf("\n\t\t HATA : Kisi Bulunamadi!");
            break;
        case '5':
            printf("\n\t\t Programi Kullandiginiz ?cin Tesekkurler.");
            return 0;
            break;
        default:
            printf("\n\t\t Lutfen 1-4 Arasinda Bir Secim Yapiniz.");
        }
    } while (Secim != 5);

    return 0;
}

