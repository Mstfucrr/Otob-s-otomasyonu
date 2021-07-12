#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
int FirmaGirisi();
int otobusekle();
int seferbilgiekle();
int Sefer_Koltuk_Bilgisi();
int MusteriGirisi();
int SeferListele();
int SeferRezervasyonYap();
int RezervasyonGoster();
int istenilen_oto_num;
int istenen_sefer_num;
int Kl_istenilen_sefer_num;
int otobuscesidi;
int ogrenci_no_son_2_hane = 20;
int kisi[50];
int seferbaslangicsaati[50][50];
int seferbitissaati[50][50];
int seferbitisssaati[50][50];
int varissuresi[50][50];
int OTO = 0;
int MUSTERI = 0;
int istenen_Rezervasyon_num;
int istenen_Rezerve;
int otonum[50];
int KL_otonum[50];
int Koltuk_No[50][50];
int personelsayisi;
float istenen_hasilat[50];
char Rezervasyon_num[50][50][30];
char Girilen_Rezervasyon_num[50][50];
char sefernumarasi[50][50];
char SiraliSefer[50][50];
char GirilenSeferNo[50][50];
char model[50][50];
char baslangic_sehiri[50][30];
char varis_sehiri[50][30];
char Ad[50][50][50];
char Soyad[50][50][50];
int b = 0;
int c = 0;

int main()
{

    char cik;
    int giris;

    printf("\n\n\n\n\n\n");
m:
    printf("\n\n1-FIRMA GIRISI\n");
    printf("2-MUSTERI GIRISI\n");
    printf("3-CIKIS\n\n");
    printf("lutfen isleminizin numarasini giriniz:==>\n");
    scanf("%d", &giris);
    if (giris == 1)
    {
        if (FirmaGirisi() == 1)
        {
            goto m;
        }
        FirmaGirisi();
    }
    else if (giris == 2)
    {
        if (MusteriGirisi() == 1)
        {
            goto m;
        }

        MusteriGirisi();
    }
    else if (giris != 1 && giris != 2 && giris != 3)
    {
        printf("\nHATALI GIRIS YAPTINIZ.!!!\n");
        goto m;
    }

    else if (giris == 3)
    {
        system("\nPAUSE");
        return 0;
    }
}

/*------------FIRMA GIRISI-----------*/
int FirmaGirisi()
{
    while (b == 0)
    {

        int firmagirisnumarasi;

    f:

        printf("\n*****************************************");
        printf("\n1-OTOBUS EKLE\n");
        printf("2-SEFER BILGISI EKLE\n");
        printf("3-SEFER/KOLTUK BILGIISI\n");
        printf("4-BIR UST MENUYE DON\n");
        printf("\nlutfen isleminizin numarasini giriniz:==>\n");
        scanf("%d", &firmagirisnumarasi);
        if (firmagirisnumarasi == 1)
        {
            otobusekle();
            goto f;
        }
        else if (firmagirisnumarasi == 2)
        {
            seferbilgiekle();
            goto f;
        }
        else if (firmagirisnumarasi == 3)
        {
            Sefer_Koltuk_Bilgisi();
            goto f;
        }
        else if (firmagirisnumarasi != 1 && firmagirisnumarasi != 2 && firmagirisnumarasi != 3 && firmagirisnumarasi != 4)
        {
            printf("HATALI GIRIS YAPTINIZ.!!!\n\n");
            goto f;
        }
        else
        {
            break;
        }
    }
    return 1;
}

int otobusekle()
{

    model[OTO][50];
    otonum[OTO] = OTO + 1;
    printf("Otobus kac kisilik: \n");
    scanf("%d", &kisi[OTO]);
    /*OTOBUS CESIDI*/
    if (kisi[OTO] >= 30)
    {
        otobuscesidi = 2;
    }
    else
    {
        otobuscesidi = 1;
    }

    if (otobuscesidi == 2)
    {
        personelsayisi = 3;
    }
    else
    {
        personelsayisi = 2;
    }

    printf("Otobusun  modelini giriniz: \n");
    scanf("%s", &model[OTO]);

    printf("personel sayisi: %d\n", personelsayisi);
    printf("otobus numarasi: %d", OTO + 1);

    OTO++;
}

int seferbilgiekle()
{

    char HEX[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
l:
    /*OTOBUS NUMARASI SECME*/
    printf("\nlutfen kullanmak istediginiz otobus numarasini giriniz: \n");
    scanf("%d", &istenilen_oto_num);
    if (istenilen_oto_num < 1)
    {
        printf("gecersiz otobus numarasi !! tekrar deneyin.\n");
        goto l;
    }

    if (istenilen_oto_num > OTO)
    {
        printf("otobus numarasi bulunamadi !! tekrar deneyin. \n");
        goto l;
    }

    /*OTOBUS SEFER NUMARASI*/
    printf("istenilen otobus numarasinin Sefer numarasi:  ");

    for (int i = 0; i < OTO; i++)
    {
        sefernumarasi[i][0] = '2';
        sefernumarasi[i][1] = '0';
    }

    srand(time(NULL));
    for (int i = 2; i <= 5; i++)
    {

        sefernumarasi[istenilen_oto_num - 1][i] = HEX[rand() % 16];
    }
    printf("%s", sefernumarasi[istenilen_oto_num - 1]);

    printf("\n*******************************************************\n");
s:
    /*SEFER BASLANGİC SAATİ*/
    printf("\nLutfen seferin sefer baslangic saatini saat ve dakika arasinda bosluk birakarak giriniz: \n");

    scanf("%d %d", &seferbaslangicsaati[istenilen_oto_num - 1][0], &seferbaslangicsaati[istenilen_oto_num - 1][1]);
    if (seferbaslangicsaati[istenilen_oto_num - 1][0] >= 24)
    {
        printf("Hatali saat girisi..\n Tekrar deneyin\n");
        goto s;
    }

    if (seferbaslangicsaati[istenilen_oto_num - 1][1] != ogrenci_no_son_2_hane)
    {
        seferbaslangicsaati[istenilen_oto_num - 1][1] = ogrenci_no_son_2_hane;
        printf("Sefer Bu Saat Gerceklesmez! Saat otomatik olarak su saata ayarlanmistir:=> %d:%d\n", seferbaslangicsaati[istenilen_oto_num - 1][0], seferbaslangicsaati[istenilen_oto_num - 1][1]);
    }
    else
    {
        printf("Sefer baslangic saati '%d:%d' saatine ayarlanmistir.\n", seferbaslangicsaati[istenilen_oto_num - 1][0], seferbaslangicsaati[istenilen_oto_num - 1][1]);
    }
g:
    /*SEFER BİTİS SAATİ*/
    printf("\nLutfen seferin tahmimi bitis saatini saat ve dakika arasinda bosluk birakarak giriniz: \n");

    scanf("%d %d", &seferbitissaati[istenilen_oto_num - 1][0], &seferbitissaati[istenilen_oto_num - 1][1]);
    seferbitisssaati[istenilen_oto_num - 1][0] = seferbitissaati[istenilen_oto_num - 1][0];
    seferbitisssaati[istenilen_oto_num - 1][1] = seferbitissaati[istenilen_oto_num - 1][1];
    if (seferbitissaati[istenilen_oto_num - 1][0] >= 24)
    {
        printf("Hatali saat girisi..\n Tekrar deneyin\n");
        goto g;
    }
    if (seferbitissaati[istenilen_oto_num - 1][1] > 59)
    {
        printf("Hatali saat girisi..\nTekrar deneyin\n");
        goto g;
    }
    printf("seferin tahmimi bitis saati '%d:%d' saatine ayarlanmistir.\n", seferbitissaati[istenilen_oto_num - 1][0], seferbitissaati[istenilen_oto_num - 1][1]);

    /*SEFER VARIS SURESI*/

    if (seferbitissaati[istenilen_oto_num - 1][1] < seferbaslangicsaati[istenilen_oto_num - 1][1])
    {
        --seferbitissaati[istenilen_oto_num - 1][0];
        seferbitissaati[istenilen_oto_num - 1][1] += 60;
    }

    varissuresi[istenilen_oto_num - 1][0] = seferbitissaati[istenilen_oto_num - 1][0] - seferbaslangicsaati[istenilen_oto_num - 1][0];
    varissuresi[istenilen_oto_num - 1][1] = seferbitissaati[istenilen_oto_num - 1][1] - seferbaslangicsaati[istenilen_oto_num - 1][1];

    printf("\nVaris suresi:  %d saat, %d dakika\n", varissuresi[istenilen_oto_num - 1][0], varissuresi[istenilen_oto_num - 1][1]);
    if (varissuresi[istenilen_oto_num - 1][0] >= 4 && otobuscesidi == 1)
    {
        printf("%d numarali otobus 4 saatten fazla yolculuklar icin elverisli degil lufen saatleri tekrar giriniz.\n%d numarali otobus icin varis suresinin 4 saatten fazla olmamasi gerektigine dikkat ediniz.\n", istenilen_oto_num, istenilen_oto_num);
        goto s;
    }
    printf("\n*******************************************\n");

    printf("Lutfen Sefer baslangic sehrini giriniz: \n");
    scanf("%s", &baslangic_sehiri[istenilen_oto_num - 1]);
    printf("\nLutfen Sefer varis sehrini giriniz: \n");
    scanf("%s", &varis_sehiri[istenilen_oto_num - 1]);
    printf("\n*******************************************\n");
    printf("Lutfen istenen Hasilati giriniz: ");
    scanf("%f", &istenen_hasilat[istenilen_oto_num - 1]);
    printf("istenen Hasilata gore Musteri basi ucret: %.3f TL", istenen_hasilat[istenilen_oto_num - 1] / kisi[istenilen_oto_num - 1]);
}

int Sefer_Koltuk_Bilgisi()
{
    printf("\n**************************************\n");
    printf("SEFER NUMARALARI:\n\n");
    for (int i = 0; i < OTO; i++)
    {
        printf("%d -) ", i + 1);
        printf("%s", sefernumarasi[i]);
        printf("\t\t");
    }

    printf("\nKacinci seferin bilgilerini gormek istiyorsunuz:  \n");
    scanf("%d", &istenen_sefer_num);

    /* OTOBUS KOLTUK DIZILISI */
    printf("\n**************************************\n");
    printf("  |----------------------------|\n");
    printf("  |      _                     |\n");
    printf("  |     |_|                []{  \n");
    printf("  |                            |\n");
    printf("  |      1    2        3    4  |\n");
    for (int i = 0; i < kisi[istenen_sefer_num - 1] / 4; i++)
    {
        if (i < 9)
        {
            printf("  | %d ", i + 1);
        }

        if (i >= 9)
        {
            printf("  | %d", i + 1);
        }

        for (int j = 0; j < 2; j++)
        {
            printf("  [ ]");
        }
        printf("    ");

        for (int j = 0; j < 2; j++)
        {
            printf("  [ ]");
        }

        if (i < 9)
        {
            printf(" |", i + 1);
        }

        if (i >= 9)
        {
            printf(" | ", i + 1);
        }

        printf("\n");
    }

    printf("  | _ _ _ _ _ _ _ _ _ _ _ _ _  | \n");

    /*--BILGILENDIRME--*/
    printf("\n*****************************************");
    printf("\n--------------BILGILENDIRME--------------\n");
    printf("*****************************************\n");
    printf(" %d nolu Otobusun:\n", istenen_sefer_num);
    printf("\tSEFER NUMARASI: ");
    printf("%s", sefernumarasi[istenen_sefer_num - 1]);

    int dolu_koltuk = 0;
    for (int s = 0; s <= MUSTERI; s++)
    {
        if (strlen(Ad[istenen_sefer_num - 1][0]) == 0)
        {
            dolu_koltuk = 0;
            break;
        }

        if (strlen(Ad[istenen_sefer_num - 1][s + 1]) == 0)
        {
            dolu_koltuk = s + 1;
            break;
        }
    }
    printf("\n\tTOPLANAN TOPLAM HASILATI: ");
    printf("%f", istenen_hasilat[istenen_sefer_num - 1] / kisi[istenen_sefer_num - 1] * dolu_koltuk);
    printf("\n\tBOS KOLTUK SAYISI: %d", kisi[istenen_sefer_num - 1] - dolu_koltuk); /*3 boyutlu ad soyad dene !!*/
    printf("\n\tSEFER GUZERGAHI: %s ---> %s", baslangic_sehiri[istenen_sefer_num - 1], varis_sehiri[istenen_sefer_num - 1]);
    printf("\n\tHAREKET SAATI: '%d:%d'", seferbaslangicsaati[istenen_sefer_num - 1][0], seferbaslangicsaati[istenen_sefer_num - 1][1]);
    printf("\n\tTAHMINI VARIS SAATI: '%d:%d'", seferbitisssaati[istenen_sefer_num - 1][0], seferbitisssaati[istenen_sefer_num - 1][1]);
}

/*-----------MUSTERI GIRISI----------*/
int MusteriGirisi()
{

    int k = 0;
q:

    while (c <= 3)
    {

        int musterigirisnumarasi;

    f:

        printf("\n**************************************\n");
        printf("\n1-SEFERLERI LISTELE\n");
        printf("2-SEFER REZERVASYON YAP\n");
        printf("3-BIR UST MENUYE DON\n");
        printf("4-REZERVASYON GOSTER\n");
        printf("\nlutfen isleminizin numarasini giriniz:==>\n");
        scanf("%d", &musterigirisnumarasi);
        if (musterigirisnumarasi == 1)
        {
            SeferListele();
            goto f;
        }
        else if (musterigirisnumarasi == 2)
        {
            SeferRezervasyonYap();
            goto f;
        }
        else if (musterigirisnumarasi == 4)
        {
            RezervasyonGoster();
            goto f;
        }
        else if (musterigirisnumarasi != 1 && musterigirisnumarasi != 2 && musterigirisnumarasi != 3 && musterigirisnumarasi != 4)
        {
            printf("HATALI GIRIS YAPTINIZ.!!!\n\n");
            printf("%d", musterigirisnumarasi);
            k++;

            goto q;
        }
        else
        {
            break;
        }
    }
    return 1;
}

int SeferListele()
{
    /*SEFERLERI KLONLAMA */
    for (int i = 0; i < OTO; i++)
    {
        strcpy(SiraliSefer[i], sefernumarasi[i]);
    }

    char a[50];

    printf("\n\n");
    for (int x = 1; x < OTO; x++)
    {
        for (int y = 1; y < OTO; y++)
        {
            if (strcmp(SiraliSefer[y - 1], SiraliSefer[y]) < 0)
            {
                strcpy(a, SiraliSefer[y - 1]);
                strcpy(SiraliSefer[y - 1], SiraliSefer[y]);
                strcpy(SiraliSefer[y], a);
            }
        }
    }

    for (int i = 0; i < OTO; i++)
    {
        for (int k = 0; k < OTO; k++)
        {
            if (strcmp(SiraliSefer[i], sefernumarasi[k]) == 0)
            {
                KL_otonum[i] = otonum[k];
            }
        }
    }
    int k;
    for (int i = 0; i < OTO; i++)
    {
        k = KL_otonum[i];

        printf("\n\n\t%s\n\t", SiraliSefer[i]);
        printf("\n\tOTOBUS NO: %d", k);
        printf("\n\tKISI BASI UCRET: %f", istenen_hasilat[k - 1] / kisi[k - 1]);
        printf("\n\tSEFER GUZERGAHI: %s ---> %s", baslangic_sehiri[k - 1], varis_sehiri[k - 1]);
        printf("\n\tHAREKET SAATI: '%d:%d'", seferbaslangicsaati[k - 1][0], seferbaslangicsaati[k - 1][1]);
        printf("\n\tTAHMINI VARIS SAATI: '%d:%d'\n", seferbitisssaati[k - 1][0], seferbitisssaati[k - 1][1]);
    }
    system("PAUSE");
}

int SeferRezervasyonYap()
{

g:
    printf("\n**************************************\n");

    printf("Lutfen Sefer Numaranizi giriniz.\n");
    scanf("%s", &GirilenSeferNo);

    for (int k = 0; k < OTO; k++)
    {
        if (strcmp(GirilenSeferNo[0], sefernumarasi[k]) == 0)
        {
            Kl_istenilen_sefer_num = k;
            goto i;
        }
        if (k == OTO - 1 && strcmp(GirilenSeferNo[0], sefernumarasi[k]) != 0)
        {
            printf("\nHatali sefer girisi Tekrar deneyin!!\n");
            goto g;
        }
    }

i:
    printf("\n**************************************\n");

    printf("  |----------------------------|\n");
    printf("  |      _                     |\n");
    printf("  |     |_|                []{  \n");
    printf("  |                            |\n");
    printf("  |      1    2        3    4  |\n");
    for (int i = 0; i < kisi[Kl_istenilen_sefer_num] / 4; i++)
    {
        if (i < 9)
        {
            printf("  | %d ", i + 1);
        }

        if (i >= 9)
        {
            printf("  | %d", i + 1);
        }

        for (int j = 0; j < 2; j++)
        {
            printf("  [ ]");
        }
        printf("    ");

        for (int j = 0; j < 2; j++)
        {
            printf("  [ ]");
        }

        if (i < 9)
        {
            printf(" |", i + 1);
        }

        if (i >= 9)
        {
            printf(" | ", i + 1);
        }

        printf("\n");
    }
    printf("  | _ _ _ _ _ _ _ _ _ _ _ _ _  | \n");
    printf("\n**************************************\n");

    /* MUSTERİ GIRISI */
    int m;
    printf("LUTFEN ADINIZI GIRINIZ:  \n");
    for (m = 0; m <= MUSTERI; m++)
    {

        if (strlen(Ad[Kl_istenilen_sefer_num][m]) == 0)
        {
            scanf("%s", &Ad[Kl_istenilen_sefer_num][m]);
            break;
        }
    }
    printf("LUTFEN SOYADINIZI GIRINIZ: \n");
    for (m = 0; m <= MUSTERI; m++)
    {
        if (strlen(Soyad[Kl_istenilen_sefer_num][m]) == 0)
        {
            scanf("%s", &Soyad[Kl_istenilen_sefer_num][m]);
            break;
        }
    }

    for (m = 0; m <= MUSTERI; m++)
    {

        if (Koltuk_No[Kl_istenilen_sefer_num][m] == 0)
        {
        c:
            printf("LUTFEN KOLTUK NUMARANIZI GIRINIZ: \n");
            scanf("%d", &Koltuk_No[Kl_istenilen_sefer_num][m]);
            if (m > 0)
            {
                for (int x = 0; x < m; x++)
                {
                    if (Koltuk_No[Kl_istenilen_sefer_num][m] == Koltuk_No[Kl_istenilen_sefer_num][x])
                    {
                        printf("\nBu Koltuk numarasi dolu !!! \n  Lutfen Tekrar deneyin.\n");
                        goto c;
                    }
                }
            }

            if (Koltuk_No[Kl_istenilen_sefer_num][m] > 0 && Koltuk_No[Kl_istenilen_sefer_num][m] <= kisi[Kl_istenilen_sefer_num])
            {

                printf("  |----------------------------|\n");
                printf("  |      _                     |\n");
                printf("  |     |_|                []{  \n");
                printf("  |                            |\n");
                printf("  |      1    2       3    4   |\n  | 1   ");
                for (int k = 1; k <= kisi[Kl_istenilen_sefer_num]; k++)
                {

                    printf("[");
                    if (Koltuk_No[Kl_istenilen_sefer_num][m] == k)
                    {
                        printf("X]  ");
                        goto x;
                    }

                    printf(" ]  ");
                x:
                    if (k % 2 == 0 && k % 4 != 0)
                    {
                        printf("   ");
                    }

                    if (k % 4 == 0 && k / 4 + 1 <= 9)
                    {
                        if (k == kisi[Kl_istenilen_sefer_num])
                        {
                            printf("| ");
                            goto Z;
                        }
                        printf("| \n  | %d   ", k / 4 + 1);
                    }

                    else if (k % 4 == 0 && k / 4 + 1 > 9)
                    {

                        if (k == kisi[Kl_istenilen_sefer_num])
                        {
                            printf("| ");
                            goto Z;
                        }

                        printf("| \n  | %d  ", k / 4 + 1);
                    }
                }
            Z:
                printf("\n  | _ _ _ _ _ _ _ _ _ _ _ _ _  | \n");

                break;
            }
            else
            {
                printf("\nGecersiz Koltuk Numarasi!!!\n  Lutfen tekar deneyin.\n");
                goto c;
            }
        }
    }
    printf("\nGirdiginiz bilgileri onayliyor musunuz? e/h\n");
    char onay;
    scanf("%s", &onay);
    int ad_boyut = strlen(Ad[Kl_istenilen_sefer_num][m]);
    int soy_boyut = strlen(Soyad[Kl_istenilen_sefer_num][m]);
    char Random_Rezervasyon_num[19] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i'};
    if (onay == 'h' || onay == 'H')
    {
        MUSTERI--;
        for (int i = 0; i < ad_boyut; i++)
        {
            Ad[Kl_istenilen_sefer_num][m][i] = Ad[Kl_istenilen_sefer_num][m + 1][i];
        }
        for (int j = 0; j < soy_boyut; j++)
        {
            Soyad[Kl_istenilen_sefer_num][m][j] = Soyad[Kl_istenilen_sefer_num][m + 1][j];
        }

        Koltuk_No[Kl_istenilen_sefer_num][m] = Koltuk_No[Kl_istenilen_sefer_num][m + 1];

        printf("\n--Bilgileriniz Silinmistir--\n");
    }

    else if (onay == 'e' || onay == 'E')
    {

        printf("\n----Girisiniz ONAYLANMISTIR----\n");
        srand(time(NULL));
        for (int i = 0; i < 8; i++)
        {

            Rezervasyon_num[Kl_istenilen_sefer_num][m][i] = Random_Rezervasyon_num[rand() % 19];
        }

        printf("Musteri Numaraniz:  %s", Rezervasyon_num[Kl_istenilen_sefer_num][m]);
    }

    MUSTERI++;
}

int RezervasyonGoster()
{
    int Denetim = 0;
g:
    if (Denetim == 3)
    {
        printf("\n**************************************\n");
        printf("\n3 Kez Hatali giris yaptiginiz icin Musteri giris Menusune Donduruluyorsunuz..");

        return 0;
    }

    printf("\n**************************************\n");
    printf("\nLutfen Rezervasyon numaranizi giriniz.\n");
    scanf("%s", Girilen_Rezervasyon_num);

    for (int T = 0; T <= MUSTERI; T++)
    {
        for (int C = 0; C <= MUSTERI; C++)
        {
            if (strcmp(Girilen_Rezervasyon_num[0], Rezervasyon_num[T][C]) == 0)
            {
                istenen_Rezerve = T;
                istenen_Rezervasyon_num = C;

                goto i;
            }
            else if (T == MUSTERI && C == MUSTERI && strcmp(Girilen_Rezervasyon_num[0], Rezervasyon_num[T][C]) != 0)
            {

                printf("\nBoyle bir Rezervasyon Numarasi yok!!\nTekrar deneyin.\n");
                Denetim++;
                goto g;
            }
        }
    }
i:
    printf("\nAD: %s", Ad[istenen_Rezerve][istenen_Rezervasyon_num]);
    printf("\nSOYAD: %s", Soyad[istenen_Rezerve][istenen_Rezervasyon_num]);
    printf("\nKOLTUK NO: %d", Koltuk_No[istenen_Rezerve][istenen_Rezervasyon_num]);
    printf("\nSEFER NUMARASI: %s", sefernumarasi[istenen_Rezerve]);
    printf("\nGUZERGAH:  %s ---> %s", baslangic_sehiri[istenen_Rezerve], varis_sehiri[istenen_Rezerve]);
    printf("\nHARAKET SAATI: '%d:%d'", seferbaslangicsaati[istenen_Rezerve][0], seferbaslangicsaati[istenen_Rezerve][1]);
    printf("\nVARIS SAATI:   '%d:%d'", seferbitisssaati[istenen_Rezerve][0], seferbitisssaati[istenen_Rezerve][1]);
}
