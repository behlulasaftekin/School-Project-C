#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "veri_seti.h"
#define MAX_KAPASITE 1000

int guncel_abone_sayisi = 0;
int islem_secim;
void abone_ekle();
void abone_sil();
void abone_guncelle();
void abone_arama();
void abone_sayimi();
void rapor_operator_degisimi();
void rapor_sadakat();
void analiz_kampanya();

void menu()
{
	while (1)
	{
		abone_sayimi();
		printf("\n----ABONE SISTEMINE HOSGELDINIZ----\n");
		printf("1.Abone ekleme.\n2.Abone silme.\n3.Abone bilgilerini guncelleme.\n4.Abone arama.\n");
		printf("5.RAPOR: Yillik operator degisimleri.\n6.RAPOR: Musteri sadakati.\n7.ANALIZ: Kampanya popularitesi.\n0.Cikis.\n");
		printf("Lutfen yapmak istediginiz islemi seciniz: ");
		scanf("%d", &islem_secim);
		if (islem_secim == 0) break;
		else
		{
			switch (islem_secim)
			{
			case 1: abone_ekle(); break;
			case 2: abone_sil(); break;
			case 3: abone_guncelle(); break;
			case 4: abone_arama(); break;
			case 5: rapor_operator_degisimi(); break;
			case 6: rapor_sadakat(); break;
			case 7: analiz_kampanya(); break;
			default: printf("Gecersiz secim!\n");
			}
		}
	}
}

int main()
{
	menu();
	return 0;
}

void abone_sayimi()
{
	int i = 0;
	while (i < MAX_KAPASITE && strlen(kisiler[i].tc_no) > 0) i++;

	guncel_abone_sayisi = i;
	printf("Sisteme kayitli abone sayisi: %d\n", guncel_abone_sayisi);
	return;
}

void abone_ekle()
{
	if (guncel_abone_sayisi >= MAX_KAPASITE)
	{
		printf("Sistem dolu, kayit gerceklestirilemez!\n");
		return;
	}

	abone* ptr;
	ptr = &kisiler[guncel_abone_sayisi];
	printf("\n----Yeni abone ekleme ekranina hos geldiniz----\n");

	printf("TC kimlik numarasi: ");
	scanf("%s", ptr->tc_no);

	printf("Isim: ");
	scanf(" %[^\n]s", ptr->isim);

	printf("Soyisim: ");
	scanf(" %[^\n]s", ptr->soyisim);

	printf("Yas: ");
	scanf("%s", ptr->yas);

	printf("Adres: ");
	scanf(" %[^\n]s", ptr->adres);

	printf("Tel No: ");
	scanf("%s", ptr->tel_no);

	printf("Tel No alinma tarihi (Gun Ay Yil): ");
	scanf("%d %d %d", &ptr->ilk_tarih.gun, &ptr->ilk_tarih.ay, &ptr->ilk_tarih.yil);

	printf("Mevcut operator: ");
	scanf(" %[^\n]s", ptr->op_ad);

	printf("Mevcut kampanya: ");
	scanf(" %[^\n]s", ptr->kampanya);

	printf("Tarife baslama zamani (Gun Ay Yil): ");
	scanf("%d %d %d", &ptr->tarife_bas.gun, &ptr->tarife_bas.ay, &ptr->tarife_bas.yil);

	printf("Tarife bitis zamani (Gun Ay Yil): ");
	scanf("%d %d %d", &ptr->tarife_son.gun, &ptr->tarife_son.ay, &ptr->tarife_son.yil);

	guncel_abone_sayisi++;
	strcpy(ptr->eski_op1, "Yok"); //bu iki satırı da yapay zekadan aldım.
	strcpy(ptr->eski_op2, "Yok");

	printf("Abone basariyla eklendi.\n");
	return;
}

void abone_sil()
{
	int aranan_indis = -1;
	char aranan_tc[12];

	printf("\n----Abone silme ekranina hosgeldiniz.----\n");
	printf("Silmek istediginiz abonenin TC kimlik no'sunu giriniz: ");
	scanf("%s", aranan_tc);

	for (int i = 0; i < guncel_abone_sayisi; i++)
	{
		if (strcmp(kisiler[i].tc_no, aranan_tc) == 0)
		{
			aranan_indis = i;
			break;
		}
	}

	if (aranan_indis != -1)
	{
		for (int j = aranan_indis; j < guncel_abone_sayisi - 1; j++)
		{
			kisiler[j] = kisiler[j + 1];
		}
		guncel_abone_sayisi--;

		strcpy(kisiler[guncel_abone_sayisi].tc_no, "");
		printf("Kisi basariyla silindi.\n");
	}
	else
	{
		printf("Hata! Bu TC kimlik no'suna sahip bir abone bulunamadi.\n");
	}

	return;
}

void abone_guncelle()
{
	char yeni_adres[100];
	char yeni_operator[15];
	date yeni_op_baslangic;
	date yeni_op_bitis;
	char silinecek_tel[15];
	int bulunan_indis = -1;

	printf("\n----Abone guncelleme ekranina hosgeldiniz.----\n");
	printf("Silmek istediginiz abonenin Tel no'sunu yaziniz: ");
	scanf("%s", silinecek_tel);

	for (int i = 0; i < guncel_abone_sayisi; i++)
	{
		if (strcmp(silinecek_tel, kisiler[i].tel_no) == 0)
		{
			bulunan_indis = i;
			break;
		}
	}
	if (bulunan_indis != -1)
	{
		abone* ptr;
		ptr = &kisiler[bulunan_indis];

		printf("\nBulunan kisi: %s %s\n", ptr->isim, ptr->soyisim);
		printf("Mevcut operator: %s", ptr->op_ad);
		printf("\n----GUNCELLENEBILIRLER----\n");
		printf("1. Adres.\n2. Operator.\n3. Kampanya.\n");

		int secim;
		printf("Hangisini degistirmek istersiniz?: ");
		scanf("%d", &secim);

		if (secim == 1)
		{
			printf("Yeni adresi giriniz: ");
			scanf(" %[^\n]s", ptr->adres);
			printf("Adres basariyla guncellendi.\n");
		}

		else if (secim == 2)
		{
			printf("Lutfen yeni operatoru giriniz: ");
			scanf(" %[^\n]s", yeni_operator);

			if (strcmp(ptr->op_ad, yeni_operator) != 0)
			{
				printf("Yeni operator tarife baslangic zamani (Gun Ay Yil): ");
				scanf("%d %d %d", &yeni_op_baslangic.gun, &yeni_op_baslangic.ay, &yeni_op_baslangic.yil);

				printf("Yeni operator tarife bitis zamani (Gun Ay Yil): ");
				scanf("%d %d %d", &yeni_op_bitis.gun, &yeni_op_bitis.ay, &yeni_op_bitis.yil);

				strcpy(ptr->eski_op2, ptr->eski_op1);
				ptr->op2_baslangic = ptr->op1_baslangic;
				ptr->op2_bitis = ptr->op1_bitis;

				strcpy(ptr->eski_op1, ptr->op_ad);
				ptr->op1_baslangic = ptr->tarife_bas;
				ptr->op1_bitis = ptr->tarife_son;

				strcpy(ptr->op_ad, yeni_operator);
				ptr->tarife_bas = yeni_op_baslangic;
				ptr->tarife_son = yeni_op_bitis;

				printf("Operator basariyla guncellendi.\n");
			}
			else printf("Zaten bu operatore kayitlisiniz.\n");
		}
		else if (secim == 3)
		{
			printf("Lutfen yeni kampanyayi giriniz: ");
			scanf(" %[^\n]s", ptr->kampanya);
			printf("Kampanya basariyla guncellendi.\n");
		}
	}
	else printf("Hata! Bu numaraya sahip abone bulunamadi.\n");
	return;
}

void abone_arama()
{
	printf("\n----Abone arama ekranina hosgeldiniz.----\n");
	char aranacak[30];
	int toplam_kisi = 0;
	printf("Aramak istediginiz ad, soyad veya tc no yaziniz: ");
	scanf(" %[^\n]s", aranacak);
	printf("\n%-15s %-15s %-15s %-15s %-15s\n", "TC NO", "ISIM", "SOYISIM", "TELEFON", "OPERATOR"); //bu satirlari direkt yapay zekadan aldım
	printf("-------------------------------------------------------------------------------\n"); // bu da aynı şekilde 

	for (int i = 0; i < guncel_abone_sayisi; i++)
	{
		if ((strcmp(aranacak, kisiler[i].isim) == 0 || strcmp(aranacak, kisiler[i].soyisim) == 0) || strcmp(aranacak, kisiler[i].tc_no) == 0)
		{
			printf("%-15s %-15s %-15s %-15s %-15s\n", kisiler[i].tc_no, kisiler[i].isim, kisiler[i].soyisim, kisiler[i].tel_no, kisiler[i].op_ad);
			toplam_kisi++;
		}
	}
	if (toplam_kisi == 0) printf("\nAradiginiz kriterde bir abone bulunamadi.\n");

	else printf("\nToplam %d adet abone bulundu.\n", toplam_kisi);
	return;
}

void rapor_operator_degisimi()
{
	int yil;
	int sayac = 0;
	printf("\n----Yillik operator degisim raporuna hosgeldiniz.----\n");
	printf("Hangi yilin degisimlerini gormek istersiniz?: ");
	scanf("%d", &yil);

	printf("\n%d yilinda operator degistirenler:\n", yil);

	for (int i = 0; i < guncel_abone_sayisi; i++)
	{
		if (strcmp(kisiler[i].eski_op1, "Yok") != 0 && kisiler[i].op1_bitis.yil == yil)
		{
			printf("%s %s: %s -> %s\n", kisiler[i].isim, kisiler[i].soyisim, kisiler[i].eski_op1, kisiler[i].op_ad);
			sayac++;
		}
	}
	if (sayac == 0) printf("Bu yilda kimse operator degistirmemis.\n");
	return;
}

void rapor_sadakat()
{
	char bulunan_operatorler[10][15];
	int operator_cesidi_sayisi = 0;
	printf("\n----Operatorlerin sadik musteri raporu.----\n");

	for (int i = 0; i < guncel_abone_sayisi; i++)
	{
		int listede_var = 0;

		for (int j = 0; j < operator_cesidi_sayisi; j++)
		{
			if (strcmp(bulunan_operatorler[j], kisiler[i].op_ad) == 0)
			{
				listede_var = 1;
				break;
			}
		}
		if (listede_var == 0)
		{
			strcpy(bulunan_operatorler[operator_cesidi_sayisi], kisiler[i].op_ad);
			operator_cesidi_sayisi++;
		}
	}

	for (int i = 0; i < operator_cesidi_sayisi; i++)
	{
		int sadik_musteri_sayisi = 0;

		for (int j = 0; j < guncel_abone_sayisi; j++)
		{
			if (strcmp(kisiler[j].op_ad, bulunan_operatorler[i]) == 0 && strcmp(kisiler[j].eski_op1, "Yok") == 0)
			{
				sadik_musteri_sayisi++;
			}
		}
		printf("%s = %d sadik musteri.\n", bulunan_operatorler[i], sadik_musteri_sayisi);
	}
	return;
}

void analiz_kampanya()
{
	struct Kampanyalar
	{
		char isim[30];
		int sayi;
	};

	struct Kampanyalar tablo[30];
	int cesit_sayisi = 0;

	printf("\n----Kampanya popularite analizi.----\n");

	for (int i = 0; i < guncel_abone_sayisi; i++)
	{
		int listede_var = 0;

		for (int j = 0; j < cesit_sayisi; j++)
		{
			if (strcmp(tablo[j].isim, kisiler[i].kampanya) == 0)
			{
				listede_var = 1;
				break;
			}
		}

		if (listede_var == 0)
		{
			strcpy(tablo[cesit_sayisi].isim, kisiler[i].kampanya);
			tablo[cesit_sayisi].sayi = 0;
			cesit_sayisi++;
		}
	}

	for (int i = 0; i < cesit_sayisi; i++)
	{
		for (int j = 0; j < guncel_abone_sayisi; j++)
		{
			if (strcmp(tablo[i].isim, kisiler[j].kampanya) == 0) tablo[i].sayi++;
		}
	}

	for (int i = 0; i < cesit_sayisi - 1; i++)
	{
		for (int j = 0; j < cesit_sayisi - i - 1; j++)
		{
			if (tablo[j + 1].sayi > tablo[j].sayi)
			{
				struct Kampanyalar gecici = tablo[j];
				tablo[j] = tablo[j + 1];
				tablo[j + 1] = gecici;
			}
		}
	}

	for (int i = 0; i < cesit_sayisi; i++)
	{
		if (strcmp(tablo[i].isim, "Yok") != 0) printf("%s kampanyasi: %d abone.\n", tablo[i].isim, tablo[i].sayi);
	}

	return;
}