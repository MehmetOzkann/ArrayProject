#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main() {
	int k;//dizinin araligini belirledigimiz buyuk sayi
	int l;//dizinin araligini belirledigimiz kucuk sayi
	int b;//rand fonksiyonundan gelen sayiyi esitledigimiz deger
	int m;//eleman degisimi icin kullanicidan aldigimiz deger
	int z, y;//dizinin degerlerini degistirmek icin kullanicidan aldigimiz aralik sayilari
	float ortalama;//ortalama degeri
	printf("dizinin araligini belirleyiniz(ilk buyuk sayiyi giriniz)");
	scanf_s("%d", &k);
	scanf_s("%d", &l);
	int n;//dizinin eleman sayisi icin kullanicidan aldigimiz deger
	printf("dizinin eleman sayisini giriniz");
	scanf_s("%d", &n);
	int* ptr;
	ptr = (int*)malloc(n * sizeof(int));//kullanicidan aldigimiz degerle bellekte yer acmak icin
	if (ptr == NULL) {//kullandigimiz kod satiri
		printf("hafiza bolunmedi");
	}
	else {
		srand(time(NULL));
		for (int i = 0; i < n; i++) {//rand fonskiyonundan gelen sayilari dizinin indislerine koyan dongu
			b = (rand() % (k-l))+l;
			ptr[i] = b;
		}
		for (int i = 0; i < n; i++) {//dizinin degerlerini ekrana bastiran dongu
			printf("array[%d]=%d\n", i, ptr[i]);
		}
		printf("dizinin elemanlarini degistirmek ister misiniz?\n 2=evet 3=hayir");
		scanf_s("%d", &m);
		if (m == 2) {//eger ki kullanici degerleri degistirirse ortalama hesaplamaz
			printf("araliklari belirleyiniz");
			scanf_s("%d %d", &z, &y);
			for (int i = z; i < y; i++) {//dizinin yeni degerlerini aldigimiz for dongusu
				printf("yeni degerleri giriniz");
				scanf_s("%d", &ptr[i]);
			}
			for (int i = 0; i < n; i++) {//dizinin yeni degerlerini bastiran for dongusu
				printf("yeni degerler=%d\n", ptr[i]);
			}
		}
		else if (m == 3) {//eger ki kullanici degerleri degistirmezse ortalamayi hesaplar
			float toplam = 0;
			for (int i = 0; i < n; i++) {
				toplam += ptr[i];
			}
			ortalama = toplam / n;
			printf("ortalama= %f", ortalama);
		}

	}
	return 0;
}